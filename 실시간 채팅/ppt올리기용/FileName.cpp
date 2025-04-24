/*
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


#define MAX_CLIENTS 8 // 최대 접속자 수 설정

// 클라이언트 수락 루프 내부
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


// 서버가 시도할 포트 번호 범위 설정
#define PORT_START 15410 // 시작 포트 번호
#define PORT_END   33333 // 종료 포트 번호

// 사용 가능한 포트를 찾아 서버 소켓 생성하는 함수
SOCKET create_server_socket(int& used_port) {
    SOCKET sock;
    sockaddr_in server_addr;

    for (int port = PORT_START; port <= PORT_END; ++port) { /// TCP 소켓 생성
        ...
            // 바인딩 시도
            if (bind(sock, (SOCKADDR*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
                closesocket(sock);
                continue;
            }
        // 리스닝 상태로 전환
        if (listen(sock, SOMAXCONN) == SOCKET_ERROR) {
            ...
        }

        used_port = port; // 사용된 포트 저장
        return sock;  // 생성된 소켓 반환
    }
    return INVALID_SOCKET;  // 실패 시 INVALID_SOCKET 반환
}


// accept 이후
std::thread t(handle_client, client_socket);
t.detach(); // 각 클라이언트를 독립적으로 처리

// 각 클라이언트를 처리하는 쓰레드 함수
void handle_client(SOCKET client_socket) {
    ...
        // 클라이언트 통신 루프
        recv(...);
    broadcast_message(...); // 다른 클라이언트들에게 메시지 전달
    ...
}

// 모든 클라이언트에게 메시지를 전송하는 함수
void broadcast_message(const std::string& message, SOCKET sender_socket = INVALID_SOCKET) {
    std::lock_guard<std::mutex> lock(clients_mutex);
    for (SOCKET client : client_sockets) {
        if (client != sender_socket) {
            send(client, message.c_str(), static_cast<int>(message.length()), 0);
        }
    }
}

// 메인 함수 시작 부분
signal(SIGINT, signal_handler); // Ctrl + C 신호 처리 함수 등록

...

// Ctrl+C 등 종료 신호를 처리하는 함수
void signal_handler(int signal) {
    if (signal == SIGINT) {
        std::cout << "\n서버 종료 요청 수신 (Ctrl+C). 클라이언트들에게 공지 중..." << std::endl;
        server_running = false;

        // 종료 전 클라이언트에게 메시지
        broadcast_message("서버가 종료됩니다. 연결이 끊어집니다.\n");

        // 소켓 정리
        for (SOCKET client : client_sockets) {
            closesocket(client);
        }
        ...
    }
}



// handle_client 내부
int bytes = recv(client_socket, buffer, sizeof(buffer) - 1, 0); // 클라이언트로부터 데이터 수신

if (bytes == SOCKET_ERROR) {
    int errCode = WSAGetLastError();
    if (errCode == WSAECONNRESET) {
        std::cout << "유저와의 연결을 종료했습니다." << std::endl; // 네트워크 오류 등 비정상 종료
    }
    else {
        std::cerr << "recv 오류: " << errCode << std::endl;
    }
    break;
}
*/