#include <iostream>
#include <WinSock2.h>
#include <vector>
#include <mysql/jdbc.h>
#include <string>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

const string DB_HOST = "tcp://127.0.0.1:3306";
const string DB_USER = "root";
const string DB_PASS = "@13468Aa";
const string DB_NAME = "socket";

void handleClient(SOCKET clientSocket)
{
    vector<char> buffer(1024);

    // 데이터 수신
    int bytesRead = recv(clientSocket, buffer.data(), buffer.size(), 0); // **변수명 수정 (byresRead -> bytesRead)**

    if (bytesRead <= 0)
    {
        closesocket(clientSocket);
        return;
    }
    string msg(buffer.data(), bytesRead);
    cout << "[RECV] " << msg << endl;

    // ===== [4] 메시지 형식 파싱 =====
    if (msg.rfind("LOGIN:", 0) == 0) {  // "LOGIN:"으로 시작하는지 확인
        size_t pos1 = msg.find(":", 6);
        size_t pos2 = msg.find(":", pos1 + 1);

        if (pos1 == string::npos || pos2 == string::npos) {
            string error = "Invalid Format";
            send(clientSocket, error.c_str(), error.length(), 0);
            closesocket(clientSocket);
            return;
        }

        string username = msg.substr(6, pos1 - 6);
        string password = msg.substr(pos1 + 1, pos2 - pos1 - 1);


        // ===== [5] MySQL 로그인 검증 =====
        try {
            sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();
            unique_ptr<sql::Connection> con(driver->connect(DB_HOST, DB_USER, DB_PASS));
            con->setSchema(DB_NAME);

            // 아이디와 비밀번호로 DB조회
            unique_ptr<sql::PreparedStatement> pstmt(
                con->prepareStatement("SELECT * FROM users WHERE username = ? AND password = ?")
            );
            pstmt->setString(1, username);
            pstmt->setString(2, password);

            unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

            string result = res->next() ? "Login Success" : "Login Failed";
            send(clientSocket, result.c_str(), result.length(), 0);
        }
        catch (sql::SQLException& e) {
            cerr << "MySQL 오류: " << e.what() << endl;
            string err = "DB Error";
            send(clientSocket, err.c_str(), err.length(), 0);
        }

        // 추가 로직 구현
    }
    // 예외처리
    else {
        string error = "Unknown Command";
        send(clientSocket, error.c_str(), error.length(), 0);
    }
    // 클라이언트 소켓 닫기
    closesocket(clientSocket);
}


int main()
{

    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    SOCKADDR_IN serverAddr, clientAddr;

    int clientSize = sizeof(clientAddr);
    vector<char> buffer(1024);

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSAStartup 실패.\n";
        return 1;
    }

    serverSocket = socket(AF_INET, SOCK_STREAM, 0); // **중복된 변수 선언 제거**
    if (serverSocket == INVALID_SOCKET) {
        cerr << "소켓 생성 실패.\n";
        WSACleanup();
        return 1;
    }

    // 서버 주소 설정
    serverAddr.sin_family = AF_INET;  // IPV4 주소
    serverAddr.sin_port = htons(12345);  // 포트 번호
    serverAddr.sin_addr.s_addr = INADDR_ANY;  // 모든 인터페이스에서 연결 허용

    bind(serverSocket, (SOCKADDR*)&serverAddr, sizeof(serverAddr));

        listen(serverSocket, SOMAXCONN);

    cout << "서버가 실행 중입니다...\n";

    // 클라이언트 연결
    clientSocket = accept(serverSocket, (SOCKADDR*)&clientAddr, &clientSize);
    if (clientSocket == INVALID_SOCKET) {
        cerr << "클라이언트 연결 실패.\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    int recvLen;
    while ((recvLen = recv(clientSocket, buffer.data(), buffer.size(), 0)) > 0) {
        cout << "클라이언트로부터 받은 데이터: " << string(buffer.data(), recvLen) << "\n";
        send(clientSocket, buffer.data(), recvLen, 0);
    }
    cout << "[서버 시작] 9000 포트 대기 중...\n";

    while (true) {
        SOCKET clientSocket = accept(serverSocket, NULL, NULL);
        if (clientSocket != INVALID_SOCKET) {
            handleClient(clientSocket);
        }
    }

    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
