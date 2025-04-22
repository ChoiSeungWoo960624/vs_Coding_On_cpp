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

// ������ �õ��� ��Ʈ ��ȣ ���� ����
#define PORT_START 15410 // ���� ��Ʈ ��ȣ
#define PORT_END   33333 // ���� ��Ʈ ��ȣ

#define MAX_CLIENTS 8 // ������ ����� �ִ� ���� ���� Ŭ���̾�Ʈ ��

// ���� ���� ����
std::vector<SOCKET> client_sockets; // ����� Ŭ���̾�Ʈ ���� ���
std::mutex clients_mutex;           // Ŭ���̾�Ʈ ��� ������ ��ȣ�ϱ� ���� mutex
volatile bool server_running = true; // ���� ���� ���� �÷���
SOCKET server_socket = INVALID_SOCKET; // ���� ����

// ��� Ŭ���̾�Ʈ���� �޽����� �����ϴ� �Լ�
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

// �� Ŭ���̾�Ʈ�� ó���ϴ� ������ �Լ�
void handle_client(SOCKET client_socket) {
    char buffer[1024];
    while (server_running) {
        ZeroMemory(buffer, sizeof(buffer)); // ���� �ʱ�ȭ
        int bytes = recv(client_socket, buffer, sizeof(buffer) - 1, 0); // Ŭ���̾�Ʈ�κ��� ������ ����

        if (bytes == SOCKET_ERROR) {
            int errCode = WSAGetLastError();
            if (errCode == WSAECONNRESET) {
                std::cout << "�������� ������ �����߽��ϴ�." << std::endl;
            }
            else {
                std::cerr << "recv ����: " << errCode << std::endl;
            }
            break;
        }

        buffer[bytes] = '\0'; // ���ڿ� �� ǥ��
        std::string msg(buffer);
        std::cout << "[" << std::time(nullptr) << "] ���� �޽���: " << msg << std::endl;

        broadcast_message(msg, client_socket); // �ٸ� Ŭ���̾�Ʈ�鿡�� �޽��� ����
    }

    // Ŭ���̾�Ʈ ���� ���� ó��
    {
        std::lock_guard<std::mutex> lock(clients_mutex);
        client_sockets.erase(std::remove(client_sockets.begin(), client_sockets.end(), client_socket), client_sockets.end());
    }

    closesocket(client_socket); // Ŭ���̾�Ʈ ���� �ݱ�
}

// Ctrl+C �� ���� ��ȣ�� ó���ϴ� �Լ�
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

        WSACleanup(); // Winsock ���ҽ� ����
        std::exit(0);
    }
}

// ��� ������ ��Ʈ�� ã�� ���� ���� �����ϴ� �Լ�
SOCKET create_server_socket(int& used_port) {
    SOCKET sock;
    sockaddr_in server_addr;

    for (int port = PORT_START; port <= PORT_END; ++port) {
        sock = socket(AF_INET, SOCK_STREAM, 0); // TCP ���� ����
        if (sock == INVALID_SOCKET) {
            std::cerr << "���� ���� ����: " << WSAGetLastError() << std::endl;
            continue;
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(port);

        // ���ε� �õ�
        if (bind(sock, (SOCKADDR*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
            closesocket(sock);
            continue;
        }

        // ������ ���·� ��ȯ
        if (listen(sock, SOMAXCONN) == SOCKET_ERROR) {
            std::cerr << "������ ����: " << WSAGetLastError() << std::endl;
            closesocket(sock);
            continue;
        }

        used_port = port; // ����� ��Ʈ ����
        return sock;      // ������ ���� ��ȯ
    }

    return INVALID_SOCKET; // ���� �� INVALID_SOCKET ��ȯ
}

// ���� �Լ� - ���� �ʱ�ȭ �� Ŭ���̾�Ʈ ���� ����
int main() {
    signal(SIGINT, signal_handler); // Ctrl+C �� ���� ó�� ���

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup ����: " << WSAGetLastError() << std::endl;
        return 1;
    }

    int selected_port = 0;
    server_socket = create_server_socket(selected_port); // ���� ���� ���� �� ��Ʈ ���ε�
    if (server_socket == INVALID_SOCKET) {
        std::cerr << "��� ������ ��Ʈ�� ã�� �� �����ϴ� (" << PORT_START << "~" << PORT_END << ")" << std::endl;
        WSACleanup();
        return 1;
    }

    std::cout << "ä�� ������ ��Ʈ " << selected_port << "���� ��� ���Դϴ� (�ִ� " << MAX_CLIENTS << "��)." << std::endl;
    std::cout << "���� ����: Ctrl+C�� ��������." << std::endl;

    // Ŭ���̾�Ʈ ���� ����
    while (server_running) {
        sockaddr_in client_addr;
        int addr_len = sizeof(client_addr);
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

        std::cout << "���ο� ���� ����" << std::endl;
        std::thread t(handle_client, client_socket);
        t.detach();
    }

    // ���� ���� ó��
    if (server_socket != INVALID_SOCKET) {
        closesocket(server_socket);
    }
    WSACleanup();
    std::cout << "������ ���������� ����Ǿ����ϴ�." << std::endl;
    return 0;
}