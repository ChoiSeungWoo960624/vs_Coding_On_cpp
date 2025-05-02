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

/*
#include <iostream>
#include <mysql/jdbc.h>
#include <string>
#include <memory>
//#include <Windows.h> // 한글 안깨지기 위한 해더파일 그래도 깨지면 2) 넣기

using namespace std;

int main() 
{
	//SetConsoleOutputCP(CP_UTF8); // 한글 안깨지기 위한 설정 그래도 깨지면 2) 넣기

    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_driver_instance();
        const string server = "tcp://127.0.0.1:3306";
        const string name = "root";
        const string password = "@134680745Aa";

        unique_ptr<sql::Connection> con(driver->connect(server, name, password));
        con->setSchema("codin");
        std::unique_ptr<sql::Statement> stmt(con->createStatement()); // 2) 이거 넣어야 한글이 안깨짐
        stmt->execute("set names euckr"); // 2) 이거 넣어야 한글이 안깨짐

        unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("SELECT customer_id, name, email FROM customers"));
        unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        while (res->next()) {
            cout << '[' << res->getInt("customer_id") << "] ";
            cout << res->getString("name") << " | ";
            cout << res->getString("email") << endl;
        }

       // 고객 추가하기
        string user_name, email, phone;
         cout << "고객 이름: ";
         getline(cin, user_name);
         cout << "이메일 : ";
         getline(cin, email);
         cout << "전화 번호 : ";
         getline(cin, phone);

         unique_ptr<sql::PreparedStatement> pstmt1(con->prepareStatement("INSERT INTO customers (name, email, phone) VALUES (?, ?, ?)"));

         pstmt1->setString(1, user_name);
         pstmt1->setString(2, email);
         pstmt1->setString(3, phone);

         int result = pstmt1->executeUpdate();

         con->commit();
         cout << result << "명의 고객이 등록 되었습니다." << endl;

         cout << "DB 연결 성공" << endl;

    }
    catch (sql::SQLException& e) {
        cerr << "SQL 오류: " << e.what() << endl;
        cerr << "MySQL 오류 코드: " << e.getErrorCode() << endl;
        cerr << "SQLState: " << e.getSQLState() << endl;
    }

    return 0;
}



// update
#include <iostream>
#include <mysql/jdbc.h>
#include <string>
#include <memory>
//#include <Windows.h> // 한글 안깨지기 위한 해더파일 그래도 깨지면 2) 넣기

using namespace std;

int main()
{
    //SetConsoleOutputCP(CP_UTF8); // 한글 안깨지기 위한 설정 그래도 깨지면 2) 넣기

    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_driver_instance();
        const string server = "tcp://127.0.0.1:3306";
        const string name = "root";
        const string password = "@134680745Aa";

        unique_ptr<sql::Connection> con(driver->connect(server, name, password));
        con->setSchema("codin");
        std::unique_ptr<sql::Statement> stmt(con->createStatement()); // 2) 이거 넣어야 한글이 안깨짐
        stmt->execute("SET NAMES utf8"); // 2) 이거 넣어야 한글이 안깨짐

        unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("SELECT customer_id, name, email FROM customers"));
        unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        while (res->next()) {
            cout << '[' << res->getInt("customer_id") << "] ";
            cout << res->getString("name") << " | ";
            cout << res->getString("email") << endl;
        }

        // (수정) 업데이트 하기
        int customer_id;
        std::string name, email, phone;
        std::cout << "수정할 고객 ID (customer_id): ";
        std::cin >> customer_id;
        std::cin.ignore(); // 버퍼 정리
        std::cout << "수정할 고객 이름: ";
        std::getline(std::cin, name);
        std::cout << "수정할 고객 이메일: ";
        std::getline(std::cin, email);
        std::cout << "수정할 고객 전화번호: ";
        std::getline(std::cin, phone);

        // UPDATE 실행
        std::unique_ptr<sql::PreparedStatement> pstmt1(con->prepareStatement("UPDATE customers SET name = ?, email = ?, phone = ? WHERE customer_id = ?"));
        pstmt1->setString(1, name);
        pstmt1->setString(2, email);
        pstmt1->setString(3, phone);
        pstmt1->setInt(4, customer_id);
        int result = pstmt1->executeUpdate();
        std::cout << result << "명의 고객이 수정 되었습니다." << std::endl;

        cout << "DB 연결 성공" << endl;

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

using namespace std;

int main()
{
    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_driver_instance();
        const string server = "tcp://127.0.0.1:3306";
        const string name = "root";
        const string password = "@134680745Aa";

        unique_ptr<sql::Connection> con(driver->connect(server, name, password));
        con->setSchema("codin");

        // 한글 깨짐 방지
        unique_ptr<sql::Statement> stmt(con->createStatement());
        stmt->execute("set names utf8mb4");

        // 고객 정보 조회
        unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("SELECT customer_id, name, email FROM customers"));
        unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        while (res->next()) {
            cout << '[' << res->getInt("customer_id") << "] ";
            cout << res->getString("name") << " | ";
            cout << res->getString("email") << endl;
        }

        // 고객 삭제하기
        int customer_id;
        cout << "삭제할 고객 ID (customer_id): ";
        cin >> customer_id;

        unique_ptr<sql::PreparedStatement> pstmt1(con->prepareStatement("DELETE FROM customers WHERE customer_id = ?"));
        pstmt1->setInt(1, customer_id);
        int result = pstmt1->executeUpdate();

        cout << result << "명의 고객이 삭제되었습니다." << endl;
        cout << "DB 연결 성공" << endl;

    }
    catch (sql::SQLException& e) {
        cerr << "SQL 오류: " << e.what() << endl;
        cerr << "MySQL 오류 코드: " << e.getErrorCode() << endl;
        cerr << "SQLState: " << e.getSQLState() << endl;
    }

    return 0;
}


//join
#include <iostream>
#include <mysql/jdbc.h>
#include <string>
#include <memory>
//#include <Windows.h> // 한글 안깨지기 위한 해더파일 그래도 깨지면 2) 넣기

using namespace std;

int main()
{
    //SetConsoleOutputCP(CP_UTF8); // 한글 안깨지기 위한 설정 그래도 깨지면 2) 넣기

    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_driver_instance();
        const string server = "tcp://127.0.0.1:3306";
        const string name = "root";
        const string password = "@134680745Aa";

        unique_ptr<sql::Connection> con(driver->connect(server, name, password));
        con->setSchema("codin");
        std::unique_ptr<sql::Statement> stmt(con->createStatement()); // 2) 이거 넣어야 한글이 안깨짐
        stmt->execute("set names euckr"); // 2) 이거 넣어야 한글이 안깨짐

        unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("SELECT customer_id, name, email FROM customers"));
        unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        while (res->next()) {
            cout << '[' << res->getInt("customer_id") << "] ";
            cout << res->getString("name") << " | ";
            cout << res->getString("email") << endl;
        }

		unique_ptr<sql::PreparedStatement> pstmt_join(con->prepareStatement("SELECT c.name, o.order_id, o.order_date, o.order_status" "FROM orders o" "JOIN customers c ON o.customer_id = c.customer_id" "ORDER BY o.order date DESC"));
        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        std::cout << "[고객 주문 내역 조회]\n";
        while (res->next())
        {
			std::cout << "고객: " << res->getString("name") << " ㅣ 주문번호: " << res->getInt("order_id")
				<< " ㅣ 주문일자: " << res->getString("order_date") << " ㅣ 주문상태: " << res->getString("order_status") 
                << "\n";
        }
        cout << "DB 연결 성공" << endl;

    }
    catch (sql::SQLException& e) {
        cerr << "SQL 오류: " << e.what() << endl;
        cerr << "MySQL 오류 코드: " << e.getErrorCode() << endl;
        cerr << "SQLState: " << e.getSQLState() << endl;
    }

    return 0;
}