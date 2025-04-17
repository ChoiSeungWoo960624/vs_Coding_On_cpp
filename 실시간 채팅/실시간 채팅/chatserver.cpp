#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <algorithm>
#include <csignal>
#include <ctime>

#pragma comment(lib, "ws2_32.lib")

//서버가 시도할 시작 번호 15410 ~ 33333까지의 포트번호
#define PORT_START 15410
#define PORT_END   33333

#define MAX_CLIENTS 8 // 서버가 허용할 최대 인원 수

std::vector<SOCKET> client_sockets;
std::mutex clients_mutex;
volatile bool server_running = true; // 서버 실행 상태를 나타내는 플래그
SOCKET server_socket = INVALID_SOCKET;

void broadcast_message(const std::string& message, SOCKET sender_socket = INVALID_SOCKET) {
    std::lock_guard<std::mutex> lock(clients_mutex);
    for (SOCKET client : client_sockets) {
        if (client != sender_socket) {
            int result = send(client, message.c_str(), static_cast<int>(message.length()), 0);
            if (result == SOCKET_ERROR) {
                std::cerr << "send 오류: " << WSAGetLastError() << std::endl;
            }
        }
    }
}

void handle_client(SOCKET client_socket) {
    char buffer[1024];
    while (server_running) {
        ZeroMemory(buffer, sizeof(buffer));
        int bytes = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
        if (bytes == SOCKET_ERROR) {
            std::cerr << "recv 오류: " << WSAGetLastError() << std::endl;
            break;
        }
        if (bytes == 0) {
            std::cout << "클라이언트 연결 종료" << std::endl;
            break;
        }

        buffer[bytes] = '\0';
        std::string msg(buffer);
        std::cout << "[" << std::time(nullptr) << "] 받은 메시지: " << msg << std::endl;

        broadcast_message(msg, client_socket);
    }

    {
        std::lock_guard<std::mutex> lock(clients_mutex);
        client_sockets.erase(
            std::remove(client_sockets.begin(), client_sockets.end(), client_socket),
            client_sockets.end()
        );
    }

    closesocket(client_socket);
}
// 서버 종료
void signal_handler(int signal) {
    if (signal == SIGINT) {
        std::cout << "\n서버 종료 요청 수신 (Ctrl+C). 클라이언트들에게 공지 중..." << std::endl;
        server_running = false;

        broadcast_message("서버가 종료됩니다. 연결이 끊어집니다.\n");

        {
            std::lock_guard<std::mutex> lock(clients_mutex);
            for (SOCKET client : client_sockets) {
                closesocket(client);
            }
            client_sockets.clear();
        }

        if (server_socket != INVALID_SOCKET) {
            closesocket(server_socket);
        }

        WSACleanup();
        std::exit(0);
    }
}

SOCKET create_server_socket(int& used_port) {
    SOCKET sock;
    sockaddr_in server_addr;

    for (int port = PORT_START; port <= PORT_END; ++port) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == INVALID_SOCKET) {
            std::cerr << "소켓 생성 실패: " << WSAGetLastError() << std::endl;
            continue;
        }

        //서버 주소 설정
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(port);

        if (bind(sock, (SOCKADDR*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
            closesocket(sock);
            continue;
        }

        if (listen(sock, SOMAXCONN) == SOCKET_ERROR) {
            std::cerr << "리스닝 실패: " << WSAGetLastError() << std::endl;
            closesocket(sock);
            continue;
        }

        used_port = port;  // 성공한 포트 번호 저장
        return sock; //성공한 소켓 반환
    }

    return INVALID_SOCKET;  // 사용 가능한 포트를 찾지 못한 경우
}

int main() {
    signal(SIGINT, signal_handler);

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup 실패: " << WSAGetLastError() << std::endl;
        return 1;
    }

    int selected_port = 0;
    server_socket = create_server_socket(selected_port);
    if (server_socket == INVALID_SOCKET) {
        std::cerr << "사용 가능한 포트를 찾을 수 없습니다 (" << PORT_START << "~" << PORT_END << ")" << std::endl;
        WSACleanup();
        return 1;
    }

    // 서버 시작 메시지 출력 
    std::cout << "채팅 서버가 포트 " << selected_port << "에서 대기 중입니다 (최대 " << MAX_CLIENTS << "명)." << std::endl;
    std::cout << "서버 종료: Ctrl+C를 누르세요." << std::endl;

    while (server_running) { // 서버가 실행 중일 때 반복
        sockaddr_in client_addr; // 클라이언트 주소 정보를 저장할 구조체
        int addr_len = sizeof(client_addr); // 주소 구조체 크기
        SOCKET client_socket = accept(server_socket, (SOCKADDR*)&client_addr, &addr_len);

        if (client_socket == INVALID_SOCKET) {
            if (!server_running) break;
            std::cerr << "클라이언트 연결 실패: " << WSAGetLastError() << std::endl;
            continue;
        }

        {
            std::lock_guard<std::mutex> lock(clients_mutex);
            if (client_sockets.size() >= MAX_CLIENTS) {
                std::string msg = "서버에 접속할 수 없습니다. (최대 접속 인원 초과)\n";
                send(client_socket, msg.c_str(), static_cast<int>(msg.length()), 0);
                closesocket(client_socket);
                continue;
            }

            client_sockets.push_back(client_socket);
        }

        std::cout << "새 클라이언트 접속" << std::endl;
        std::thread t(handle_client, client_socket);
        t.detach();
    }

    // 서버 종료 시 리소스 정리
    if (server_socket != INVALID_SOCKET) {
        closesocket(server_socket);
    }
    WSACleanup();
    std::cout << "서버가 정상적으로 종료되었습니다." << std::endl;
    return 0;
}
