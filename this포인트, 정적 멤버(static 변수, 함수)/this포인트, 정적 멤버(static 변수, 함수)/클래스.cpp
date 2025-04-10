





/*
//실습 1 두 객체 비교 및 반환

#include <iostream>
using namespace std;

class Rectangle 
{
private:
    int width;
    int height;

public:
    // 생성자
    Rectangle(int w, int h) 
    {
        width = w;
        height = h;
    }

    // 넓이 반환 함수
    int getArea() const 
    {
        return width * height;
    }

    // 다른 Rectangle 객체와 넓이 비교 후 더 넓은 객체 반환
    Rectangle& compareArea(Rectangle& other) 
    {
        if (this->getArea() >= other.getArea())
            return *this;
        else
            return other;
    }

    // 정보 출력 함수
    void showInfo() const {
        cout << "Width: " << width << ", Height: " << height
            << ", Area: " << getArea() << endl;


//실습 2 유일한 ID 할당

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

    cout << "총 사용자 수: " << User::GetTotalUsers() << endl;

    return 0;
}
*/

