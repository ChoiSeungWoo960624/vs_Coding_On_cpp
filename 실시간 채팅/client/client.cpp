#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <thread>
#include <string>

#pragma comment(lib, "ws2_32.lib")

class Client {
public:
    void connectToServer(const std::string& ip, int port);
private:
    void receiveMessages(SOCKET clientSocket);
    void sendMessages(SOCKET clientSocket);
};

void Client::receiveMessages(SOCKET clientSocket) {
    char buffer[1024];
    while (true) {
        ZeroMemory(buffer, sizeof(buffer));
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        if (bytesReceived > 0) {
            buffer[bytesReceived] = '\0';
            std::cout << "\n[���� �޽���] " << buffer << "\n> ";
            std::cout.flush(); // ������Ʈ �ٽ� ���
        }
        else if (bytesReceived == 0) {
            std::cout << "�������� ������ ����Ǿ����ϴ�.\n";
            break;
        }
        else {
            std::cerr << "�޽��� ���� ����: " << WSAGetLastError() << std::endl;
            break;
        }
    }
}

void Client::sendMessages(SOCKET clientSocket) {
    std::string message;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, message);
        if (message.empty()) continue;

        int result = send(clientSocket, message.c_str(), static_cast<int>(message.size()), 0);
        if (result == SOCKET_ERROR) {
            std::cerr << "�޽��� ���� ����: " << WSAGetLastError() << std::endl;
            break;
        }
    }
}

void Client::connectToServer(const std::string& ip, int port) {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup ����: " << WSAGetLastError() << std::endl;
        return;
    }

    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "���� ���� ����: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &serverAddr.sin_addr);

    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "���� ���� ����: " << WSAGetLastError() << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return;
    }

    std::cout << "������ ����Ǿ����ϴ�! ä���� �����ϼ���.\n";

    // �޽��� ���� ������
    std::thread recvThread(&Client::receiveMessages, this, clientSocket);
    recvThread.detach();

    // �޽��� ���� ����
    sendMessages(clientSocket);

    closesocket(clientSocket);
    WSACleanup();
}

int main() {
    Client client;
    client.connectToServer("127.0.0.1", 15410);
    return 0;
}
