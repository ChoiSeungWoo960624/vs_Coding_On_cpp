





/*
//�ǽ� 1 �� ��ü �� �� ��ȯ

#include <iostream>
using namespace std;

class Rectangle 
{
private:
    int width;
    int height;

public:
    // ������
    Rectangle(int w, int h) 
    {
        width = w;
        height = h;
    }

    // ���� ��ȯ �Լ�
    int getArea() const 
    {
        return width * height;
    }

    // �ٸ� Rectangle ��ü�� ���� �� �� �� ���� ��ü ��ȯ
    Rectangle& compareArea(Rectangle& other) 
    {
        if (this->getArea() >= other.getArea())
            return *this;
        else
            return other;
    }

    // ���� ��� �Լ�
    void showInfo() const {
        cout << "Width: " << width << ", Height: " << height
            << ", Area: " << getArea() << endl;


//�ǽ� 2 ������ ID �Ҵ�

#include <iostream>
#include <string>
using namespace std;

class User 
{
private:
    static int NextID;
    int id;
    string name;

public:
    User(string username) 
    {
        id = NextID++;
        name = username;
    }

    void showInfo() 
    {
        cout << "ID: " << id << ", Name: " << name << endl;
    }

    static int GetTotalUsers()
    {
        return NextID - 1;
    }
};

int User::NextID = 1;

int main() 
{
    User user1("on");
    User user2("for");
    User user3("all");

    user1.showInfo();
    user2.showInfo();
    user3.showInfo();

    cout << "�� ����� ��: " << User::GetTotalUsers() << endl;

    return 0;
}
*/

