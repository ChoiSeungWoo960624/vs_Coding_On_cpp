#include <iostream>
#include <Winsock2.h>
#include <WS2tcpip.h>
#include <string>
#include <vector>
#pragma comment(lib, "ws2.32.lib")

using namespace std;

int main()
{ 
// 윈도우 소켓 초기화
WSADATA wsaData;
// 클라이너트 소켓
SOCKET clientSocket;
// 서버 주소 정보
SOCKADDR_IN serverAddr;

WSAStartup(MAKEWORD(2, 2), &wsaData);

clientSocket = socket(AF_INET, SOCK_STREAM, 0);

serverAddr.sin_family = AF_INET;
serverAddr.sin_port = htons(12345);
inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);


if (connect(clientSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
	std::cerr << "서버에 연결할 수 없습니다.\n";
	closesocket(clientSocket);
	WSACleanup();
	return 1;
}


// 사용자 입력
string username, password;
cout << "아이디: ";
getline(cin, username);
	cout << "비밀 번호: ";
getline(cin, password);

// 메시지 구성 : LOGIN : USERANAME : password
string mesgage = "LOGIN: " + username + " " + password + " : ";

// 서버 응답 수신
std::vector<char> buffer(1024);
int bytesReceived = recv(clientSocket, buffer.data(), static_cast<int>(buffer.size()), 0);

if (bytesReceived > 0)
{
	std::string response(buffer.data(), bytesReceived);
	std::cout << "[서버 응답] " << response << std::endl;
}
else
{
	std::cerr << "서버 응답 수신 실패\n";
}

while (true)
{
	cout << "메시지: ";
	//사용자 입력
	cin.getline(buffer.data(), sizeof(buffer));

	if (strcmp(buffer.data(), "exit") == 0) {
		break;
	}

	send(clientSocket, buffer.data(), strlen(buffer.data()), 0);
	<< "\n";
}

//종료전 
closesocket(clientSocket);
WSACleanup();

