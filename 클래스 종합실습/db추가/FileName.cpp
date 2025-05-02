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

        // ����� �����ͺ��̽� ����
        con->setSchema("codin");

        cout << "DB ���� ����!" << endl;
    }
    catch (sql::SQLException& e) {
        cerr << "SQL ����: " << e.what() << endl;
        cerr << "MySQL ���� �ڵ�: " << e.getErrorCode() << endl;
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
//#include <Windows.h> // �ѱ� �ȱ����� ���� �ش����� �׷��� ������ 2) �ֱ�

using namespace std;

int main() 
{
	//SetConsoleOutputCP(CP_UTF8); // �ѱ� �ȱ����� ���� ���� �׷��� ������ 2) �ֱ�

    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_driver_instance();
        const string server = "tcp://127.0.0.1:3306";
        const string name = "root";
        const string password = "@134680745Aa";

        unique_ptr<sql::Connection> con(driver->connect(server, name, password));
        con->setSchema("codin");
        std::unique_ptr<sql::Statement> stmt(con->createStatement()); // 2) �̰� �־�� �ѱ��� �ȱ���
        stmt->execute("set names euckr"); // 2) �̰� �־�� �ѱ��� �ȱ���

        unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("SELECT customer_id, name, email FROM customers"));
        unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        while (res->next()) {
            cout << '[' << res->getInt("customer_id") << "] ";
            cout << res->getString("name") << " | ";
            cout << res->getString("email") << endl;
        }

       // �� �߰��ϱ�
        string user_name, email, phone;
         cout << "�� �̸�: ";
         getline(cin, user_name);
         cout << "�̸��� : ";
         getline(cin, email);
         cout << "��ȭ ��ȣ : ";
         getline(cin, phone);

         unique_ptr<sql::PreparedStatement> pstmt1(con->prepareStatement("INSERT INTO customers (name, email, phone) VALUES (?, ?, ?)"));

         pstmt1->setString(1, user_name);
         pstmt1->setString(2, email);
         pstmt1->setString(3, phone);

         int result = pstmt1->executeUpdate();

         con->commit();
         cout << result << "���� ���� ��� �Ǿ����ϴ�." << endl;

         cout << "DB ���� ����" << endl;

    }
    catch (sql::SQLException& e) {
        cerr << "SQL ����: " << e.what() << endl;
        cerr << "MySQL ���� �ڵ�: " << e.getErrorCode() << endl;
        cerr << "SQLState: " << e.getSQLState() << endl;
    }

    return 0;
}



// update
#include <iostream>
#include <mysql/jdbc.h>
#include <string>
#include <memory>
//#include <Windows.h> // �ѱ� �ȱ����� ���� �ش����� �׷��� ������ 2) �ֱ�

using namespace std;

int main()
{
    //SetConsoleOutputCP(CP_UTF8); // �ѱ� �ȱ����� ���� ���� �׷��� ������ 2) �ֱ�

    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_driver_instance();
        const string server = "tcp://127.0.0.1:3306";
        const string name = "root";
        const string password = "@134680745Aa";

        unique_ptr<sql::Connection> con(driver->connect(server, name, password));
        con->setSchema("codin");
        std::unique_ptr<sql::Statement> stmt(con->createStatement()); // 2) �̰� �־�� �ѱ��� �ȱ���
        stmt->execute("SET NAMES utf8"); // 2) �̰� �־�� �ѱ��� �ȱ���

        unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("SELECT customer_id, name, email FROM customers"));
        unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        while (res->next()) {
            cout << '[' << res->getInt("customer_id") << "] ";
            cout << res->getString("name") << " | ";
            cout << res->getString("email") << endl;
        }

        // (����) ������Ʈ �ϱ�
        int customer_id;
        std::string name, email, phone;
        std::cout << "������ �� ID (customer_id): ";
        std::cin >> customer_id;
        std::cin.ignore(); // ���� ����
        std::cout << "������ �� �̸�: ";
        std::getline(std::cin, name);
        std::cout << "������ �� �̸���: ";
        std::getline(std::cin, email);
        std::cout << "������ �� ��ȭ��ȣ: ";
        std::getline(std::cin, phone);

        // UPDATE ����
        std::unique_ptr<sql::PreparedStatement> pstmt1(con->prepareStatement("UPDATE customers SET name = ?, email = ?, phone = ? WHERE customer_id = ?"));
        pstmt1->setString(1, name);
        pstmt1->setString(2, email);
        pstmt1->setString(3, phone);
        pstmt1->setInt(4, customer_id);
        int result = pstmt1->executeUpdate();
        std::cout << result << "���� ���� ���� �Ǿ����ϴ�." << std::endl;

        cout << "DB ���� ����" << endl;

    }
    catch (sql::SQLException& e) {
        cerr << "SQL ����: " << e.what() << endl;
        cerr << "MySQL ���� �ڵ�: " << e.getErrorCode() << endl;
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

        // �ѱ� ���� ����
        unique_ptr<sql::Statement> stmt(con->createStatement());
        stmt->execute("set names utf8mb4");

        // �� ���� ��ȸ
        unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("SELECT customer_id, name, email FROM customers"));
        unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        while (res->next()) {
            cout << '[' << res->getInt("customer_id") << "] ";
            cout << res->getString("name") << " | ";
            cout << res->getString("email") << endl;
        }

        // �� �����ϱ�
        int customer_id;
        cout << "������ �� ID (customer_id): ";
        cin >> customer_id;

        unique_ptr<sql::PreparedStatement> pstmt1(con->prepareStatement("DELETE FROM customers WHERE customer_id = ?"));
        pstmt1->setInt(1, customer_id);
        int result = pstmt1->executeUpdate();

        cout << result << "���� ���� �����Ǿ����ϴ�." << endl;
        cout << "DB ���� ����" << endl;

    }
    catch (sql::SQLException& e) {
        cerr << "SQL ����: " << e.what() << endl;
        cerr << "MySQL ���� �ڵ�: " << e.getErrorCode() << endl;
        cerr << "SQLState: " << e.getSQLState() << endl;
    }

    return 0;
}


//join
#include <iostream>
#include <mysql/jdbc.h>
#include <string>
#include <memory>
//#include <Windows.h> // �ѱ� �ȱ����� ���� �ش����� �׷��� ������ 2) �ֱ�

using namespace std;

int main()
{
    //SetConsoleOutputCP(CP_UTF8); // �ѱ� �ȱ����� ���� ���� �׷��� ������ 2) �ֱ�

    try {
        sql::mysql::MySQL_Driver* driver = sql::mysql::get_driver_instance();
        const string server = "tcp://127.0.0.1:3306";
        const string name = "root";
        const string password = "@134680745Aa";

        unique_ptr<sql::Connection> con(driver->connect(server, name, password));
        con->setSchema("codin");
        std::unique_ptr<sql::Statement> stmt(con->createStatement()); // 2) �̰� �־�� �ѱ��� �ȱ���
        stmt->execute("set names euckr"); // 2) �̰� �־�� �ѱ��� �ȱ���

        unique_ptr<sql::PreparedStatement> pstmt(con->prepareStatement("SELECT customer_id, name, email FROM customers"));
        unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        while (res->next()) {
            cout << '[' << res->getInt("customer_id") << "] ";
            cout << res->getString("name") << " | ";
            cout << res->getString("email") << endl;
        }

		unique_ptr<sql::PreparedStatement> pstmt_join(con->prepareStatement("SELECT c.name, o.order_id, o.order_date, o.order_status" "FROM orders o" "JOIN customers c ON o.customer_id = c.customer_id" "ORDER BY o.order date DESC"));
        std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());

        std::cout << "[�� �ֹ� ���� ��ȸ]\n";
        while (res->next())
        {
			std::cout << "��: " << res->getString("name") << " �� �ֹ���ȣ: " << res->getInt("order_id")
				<< " �� �ֹ�����: " << res->getString("order_date") << " �� �ֹ�����: " << res->getString("order_status") 
                << "\n";
        }
        cout << "DB ���� ����" << endl;

    }
    catch (sql::SQLException& e) {
        cerr << "SQL ����: " << e.what() << endl;
        cerr << "MySQL ���� �ڵ�: " << e.getErrorCode() << endl;
        cerr << "SQLState: " << e.getSQLState() << endl;
    }

    return 0;
}