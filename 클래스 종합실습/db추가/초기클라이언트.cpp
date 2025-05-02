#include <iostream>
#include <Winsock2.h>
#include <WS2tcpip.h>
#include <string>
#include <vector>
#pragma comment(lib, "ws2.32.lib")

using namespace std;

int main()
{ 
// ������ ���� �ʱ�ȭ
WSADATA wsaData;
// Ŭ���̳�Ʈ ����
SOCKET clientSocket;
// ���� �ּ� ����
SOCKADDR_IN serverAddr;

WSAStartup(MAKEWORD(2, 2), &wsaData);

clientSocket = socket(AF_INET, SOCK_STREAM, 0);

serverAddr.sin_family = AF_INET;
serverAddr.sin_port = htons(12345);
inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);


if (connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
	std::cerr << "������ ������ �� �����ϴ�.\n";
	closesocket(clientSocket);
	WSACleanup();
	return 1;
}


// ����� �Է�
string username, password;
cout << "���̵�: ";
getline(cin, username);
	cout << "��� ��ȣ: ";
getline(cin, password);

// �޽��� ���� : LOGIN : USERANAME : password
string mesgage = "LOGIN: " + username + " " + password + " : ";

// ���� ���� ����
std::vector<char> buffer(1024);
int bytesReceived = recv(clientSocket, buffer.data(), static_cast<int>(buffer.size()), 0);

if (bytesReceived > 0)
{
	std::string response(buffer.data(), bytesReceived);
	std::cout << "[���� ����] " << response << std::endl;
}
else
{
	std::cerr << "���� ���� ���� ����\n";
}

while (true)
{
	cout << "�޽���: ";
	//����� �Է�
	cin.getline(buffer.data(), sizeof(buffer));

	if (strcmp(buffer.data(), "exit") == 0) {
		break;
	}

	send(clientSocket, buffer.data(), strlen(buffer.data()), 0);
	<< "\n";
}

//������ 
closesocket(clientSocket);
WSACleanup();

