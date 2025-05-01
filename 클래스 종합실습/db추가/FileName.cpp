/*
#include <iostream>
#include <mysql/jdbc.h>
#include <string>
#include <memory>

using namespace std;

int main() {
    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_driver_instance();
        const string server = "tcp://127.0.0.1:3306";
        const string name = "root";
        const string password = "@134680745Aa";

        std::unique_ptr<sql::Connection> con(driver->connect(server, name, password));

        // 사용할 데이터베이스 설정
        con->setSchema("codin");

        cout << "DB 연결 성공!" << endl;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL 오류: " << e.what() << endl;
        cerr << "MySQL 오류 코드: " << e.getErrorCode() << endl;
        cerr << "SQLState: " << e.getSQLState() << endl;
    }

    return 0;
}

*/

#include <iostream>
#include <mysql/jdbc.h>
#include <string>
#include <memory>
#include <Windows.h> // 한글 안깨지기 위한 해더파일

using namespace std;

int main() 
{
	SetConsoleOutputCP(CP_UTF8); // 한글 안깨지기 위한 설정

    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_driver_instance();
        const string server = "tcp://127.0.0.1:3306";
        const string name = "root";
        const string password = "@134680745Aa";

        unique_ptr<sql::Connection> con(driver->connect(server, name, password));
        con->setSchema("codin");

        unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("SELECT customer_id, name, email FROM customers"));
        unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        while (res->next()) {
            cout << '[' << res->getInt("customer_id") << "] ";
            cout << res->getString("name") << " | ";
            cout << res->getString("email") << endl;
        }
    }
    catch (sql::SQLException& e) {
        cerr << "SQL 오류: " << e.what() << endl;
        cerr << "MySQL 오류 코드: " << e.getErrorCode() << endl;
        cerr << "SQLState: " << e.getSQLState() << endl;
    }

    return 0;
}
