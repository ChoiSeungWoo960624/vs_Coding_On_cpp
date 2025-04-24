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


#define MAX_CLIENTS 8 // �ִ� ������ �� ����

// Ŭ���̾�Ʈ ���� ���� ����
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


// ������ �õ��� ��Ʈ ��ȣ ���� ����
#define PORT_START 15410 // ���� ��Ʈ ��ȣ
#define PORT_END   33333 // ���� ��Ʈ ��ȣ

// ��� ������ ��Ʈ�� ã�� ���� ���� �����ϴ� �Լ�
SOCKET create_server_socket(int& used_port) {
    SOCKET sock;
    sockaddr_in server_addr;

    for (int port = PORT_START; port <= PORT_END; ++port) { /// TCP ���� ����
        ...
            // ���ε� �õ�
            if (bind(sock, (SOCKADDR*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
                closesocket(sock);
                continue;
            }
        // ������ ���·� ��ȯ
        if (listen(sock, SOMAXCONN) == SOCKET_ERROR) {
            ...
        }

        used_port = port; // ���� ��Ʈ ����
        return sock;  // ������ ���� ��ȯ
    }
    return INVALID_SOCKET;  // ���� �� INVALID_SOCKET ��ȯ
}


// accept ����
std::thread t(handle_client, client_socket);
t.detach(); // �� Ŭ���̾�Ʈ�� ���������� ó��

// �� Ŭ���̾�Ʈ�� ó���ϴ� ������ �Լ�
void handle_client(SOCKET client_socket) {
    ...
        // Ŭ���̾�Ʈ ��� ����
        recv(...);
    broadcast_message(...); // �ٸ� Ŭ���̾�Ʈ�鿡�� �޽��� ����
    ...
}

// ��� Ŭ���̾�Ʈ���� �޽����� �����ϴ� �Լ�
void broadcast_message(const std::string& message, SOCKET sender_socket = INVALID_SOCKET) {
    std::lock_guard<std::mutex> lock(clients_mutex);
    for (SOCKET client : client_sockets) {
        if (client != sender_socket) {
            send(client, message.c_str(), static_cast<int>(message.length()), 0);
        }
    }
}

// ���� �Լ� ���� �κ�
signal(SIGINT, signal_handler); // Ctrl + C ��ȣ ó�� �Լ� ���

...

// Ctrl+C �� ���� ��ȣ�� ó���ϴ� �Լ�
void signal_handler(int signal) {
    if (signal == SIGINT) {
        std::cout << "\n���� ���� ��û ���� (Ctrl+C). Ŭ���̾�Ʈ�鿡�� ���� ��..." << std::endl;
        server_running = false;

        // ���� �� Ŭ���̾�Ʈ���� �޽���
        broadcast_message("������ ����˴ϴ�. ������ �������ϴ�.\n");

        // ���� ����
        for (SOCKET client : client_sockets) {
            closesocket(client);
        }
        ...
    }
}



// handle_client ����
int bytes = recv(client_socket, buffer, sizeof(buffer) - 1, 0); // Ŭ���̾�Ʈ�κ��� ������ ����

if (bytes == SOCKET_ERROR) {
    int errCode = WSAGetLastError();
    if (errCode == WSAECONNRESET) {
        std::cout << "�������� ������ �����߽��ϴ�." << std::endl; // ��Ʈ��ũ ���� �� ������ ����
    }
    else {
        std::cerr << "recv ����: " << errCode << std::endl;
    }
    break;
}
*/