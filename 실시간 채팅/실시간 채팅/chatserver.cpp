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

//������ �õ��� ���� ��ȣ 15410 ~ 33333������ ��Ʈ��ȣ
#define PORT_START 15410
#define PORT_END   33333

#define MAX_CLIENTS 8 // ������ ����� �ִ� �ο� ��

std::vector<SOCKET> client_sockets;
std::mutex clients_mutex;
volatile bool server_running = true; // ���� ���� ���¸� ��Ÿ���� �÷���
SOCKET server_socket = INVALID_SOCKET;

void broadcast_message(const std::string& message, SOCKET sender_socket = INVALID_SOCKET) {
    std::lock_guard<std::mutex> lock(clients_mutex);
    for (SOCKET client : client_sockets) {
        if (client != sender_socket) {
            int result = send(client, message.c_str(), static_cast<int>(message.length()), 0);
            if (result == SOCKET_ERROR) {
                std::cerr << "send ����: " << WSAGetLastError() << std::endl;
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
            std::cerr << "recv ����: " << WSAGetLastError() << std::endl;
            break;
        }
        if (bytes == 0) {
            std::cout << "Ŭ���̾�Ʈ ���� ����" << std::endl;
            break;
        }

        buffer[bytes] = '\0';
        std::string msg(buffer);
        std::cout << "[" << std::time(nullptr) << "] ���� �޽���: " << msg << std::endl;

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
// ���� ����
void signal_handler(int signal) {
    if (signal == SIGINT) {
        std::cout << "\n���� ���� ��û ���� (Ctrl+C). Ŭ���̾�Ʈ�鿡�� ���� ��..." << std::endl;
        server_running = false;

        broadcast_message("������ ����˴ϴ�. ������ �������ϴ�.\n");

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
            std::cerr << "���� ���� ����: " << WSAGetLastError() << std::endl;
            continue;
        }

        //���� �ּ� ����
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(port);

        if (bind(sock, (SOCKADDR*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
            closesocket(sock);
            continue;
        }

        if (listen(sock, SOMAXCONN) == SOCKET_ERROR) {
            std::cerr << "������ ����: " << WSAGetLastError() << std::endl;
            closesocket(sock);
            continue;
        }

        used_port = port;  // ������ ��Ʈ ��ȣ ����
        return sock; //������ ���� ��ȯ
    }

    return INVALID_SOCKET;  // ��� ������ ��Ʈ�� ã�� ���� ���
}

int main() {
    signal(SIGINT, signal_handler);

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup ����: " << WSAGetLastError() << std::endl;
        return 1;
    }

    int selected_port = 0;
    server_socket = create_server_socket(selected_port);
    if (server_socket == INVALID_SOCKET) {
        std::cerr << "��� ������ ��Ʈ�� ã�� �� �����ϴ� (" << PORT_START << "~" << PORT_END << ")" << std::endl;
        WSACleanup();
        return 1;
    }

    // ���� ���� �޽��� ��� 
    std::cout << "ä�� ������ ��Ʈ " << selected_port << "���� ��� ���Դϴ� (�ִ� " << MAX_CLIENTS << "��)." << std::endl;
    std::cout << "���� ����: Ctrl+C�� ��������." << std::endl;

    while (server_running) { // ������ ���� ���� �� �ݺ�
        sockaddr_in client_addr; // Ŭ���̾�Ʈ �ּ� ������ ������ ����ü
        int addr_len = sizeof(client_addr); // �ּ� ����ü ũ��
        SOCKET client_socket = accept(server_socket, (SOCKADDR*)&client_addr, &addr_len);

        if (client_socket == INVALID_SOCKET) {
            if (!server_running) break;
            std::cerr << "Ŭ���̾�Ʈ ���� ����: " << WSAGetLastError() << std::endl;
            continue;
        }

        {
            std::lock_guard<std::mutex> lock(clients_mutex);
            if (client_sockets.size() >= MAX_CLIENTS) {
                std::string msg = "������ ������ �� �����ϴ�. (�ִ� ���� �ο� �ʰ�)\n";
                send(client_socket, msg.c_str(), static_cast<int>(msg.length()), 0);
                closesocket(client_socket);
                continue;
            }

            client_sockets.push_back(client_socket);
        }

        std::cout << "�� Ŭ���̾�Ʈ ����" << std::endl;
        std::thread t(handle_client, client_socket);
        t.detach();
    }

    // ���� ���� �� ���ҽ� ����
    if (server_socket != INVALID_SOCKET) {
        closesocket(server_socket);
    }
    WSACleanup();
    std::cout << "������ ���������� ����Ǿ����ϴ�." << std::endl;
    return 0;
}
