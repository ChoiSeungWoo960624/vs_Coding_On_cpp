/*
#include <iostream>
using namespace std;

class Car 
{
    // 비공개
    // 해당 클래스 내에서만 접근 가능하다.
    //private:
  // 어디서나 접근 가능하다.
public:
    string brand;
    int speed;

    void display() 
    {
        cout << "차량의 브랜드는 " << brand << "이고 속도는 " << speed << "km/h 입니다." << endl;
    }
};

class Point
{
    //클래스 내부에서만 접근이 가능하다.
private:
    int x;
    int y;

public:
    void setX(int x1) 
    {
        x = x1;
    }
    void setY(int y1) 
    {
        y = y1;
    }
    void print() 
    {
        cout << x << ", " << y << endl;
    }
};


#include <iostream>
#include <string>
using namespace std;

class Person 
{
private:
    string Name;
    int Age;

public:
    void setName(const string& NewName) 
    {
        Name = NewName;
    }

    void setAge(int NewAge) 
    {
        Age = NewAge;
    }

    void showInfo() 
    {
        cout << "이름: " << Name << endl;
        cout << "나이: " << Age << endl;
    }
};

int main() 
{
    Person p;

    string InName;
    int InAge;

    cout << "이름을 입력해주세요 : ";
    getline(cin, InName);

    cout << "나이를 입력해주세요 : ";
    cin >> InAge;

    p.setName(InName);
    p.setAge(InAge);

    p.showInfo();

    return 0;
}


// 실습 2 클래스 사용해보기 (2) - 사각형
#include <iostream>
using namespace std;

class Rectangle 
{
private:
    int width;
    int height;

public:
    Rectangle(int w, int h) {
        width = w;
        height = h;
    }

    int area() 
    {
        return width * height;
    }
};

int main() 
{
    int w, h;

    cout << "가로 값 : ";
    cin >> w;

    cout << "세로 값 : ";
    cin >> h;

    Rectangle rect(w, h);

    cout << "넓이 : " << rect.area() << endl;

    return 0;
}


// 실습 2-1 클래스 사용해보기
#include <iostream>
using namespace std;

class Rectangle
{
private:
    int width;
    int height;

public:
    Rectangle(int w, int h) 
    {
        width = w; //가로
        height = h; //세로
    }

    Rectangle() 
    {
        width = 0;
        height = 0;
    }

    Rectangle(const Rectangle& other) 
    {
        width = other.width;
        height = other.height;
    }

    int area() 
    {
        return width * height;
    }
};

int main()
{
    int w, h;

    cout << "가로 값 : ";
    cin >> w;

    cout << "세로 값 : ";
    cin >> h;

    Rectangle rect(w, h);
    cout << "넓이 : " << rect.area() << endl;

    Rectangle copy1(rect);
    cout << "복사한 넓이 : " << copy1.area() << endl;

    Rectangle copy2;  // 기본 생성자
    copy2 = rect;     // 복사 연산
    cout << "연산자 넓이 : " << copy2.area() << endl;

    return 0;
}


// 실습 3. 클래스 사용해보기(3) - 계좌
#include <iostream>
using namespace std;

class BankAccount 
{
private:
    int AccountNumber;
    int Balance;

public:
    BankAccount(int acc, int bal) 
    {
        AccountNumber = acc;
        Balance = bal;
    }

    ~BankAccount() 
    {
        cout << "계좌 삭제됨 : " << AccountNumber << endl;
    }

    void deposit(int money) 
    {
        Balance += money;
    }

    void withdraw(int money) 
    {
        Balance -= money;
    }

    void print() 
    {
        cout << "계좌번호 " << AccountNumber << "의 잔액은 " << Balance << "원 입니다." << endl;
    }
};

int main() 
{
    int AccNum, inBalance;

    cout << "계좌번호 입력: ";
    cin >> AccNum;

    cout << "초기 잔액 입력: ";
    cin >> inBalance;

    BankAccount account(AccNum, inBalance);

    account.deposit(12000); //입금
    account.withdraw(4000); //출금
    account.print();

    return 0;
}
*/

//실습 4. 게임 캐릭터 생성하기 
#include <iostream>
using namespace std;

//캐릭터 클래스
class Character 
{
private:
    string name;
    int level;
    int item_num;
public:
    Character(string a, int b, int c) 
    {
        name = a;
        level = b;
        item_num = c;
        cout << "캐릭터 생성 완료! 캐릭터명 : " << name << endl;
    }

    void showInfo() 
    {
        cout << "캐릭터명 : " << name << endl;
        cout << "레벨 : " << level << endl;
        cout << "아이템 개수 : " << item_num << endl;
    }
    void levelUp() 
    {
        level++;
        cout << "레벨업! 현재 레벨 : " << level << endl;
    }
    void addItem() 
    {
        item_num += 1;
        cout << "아이템 추가! 현재 아이템 개수 : " << item_num << endl;
    }
    void removeItem(int num) 
    {
        if (item_num >= num) 
        {
            item_num -= num;
            cout << "아이템 사용! 현재 아이템 개수 : " << item_num << endl;
        }
        else {
            cout << "아이템이 부족합니다!" << endl;
        }
    }
    void changeName(string newName) 
    {
        name = newName;
        cout << "이름 변경 완료! 현재 캐릭터명 : " << name << endl;
    }
};

int main()
{
    string name;
    cout << "캐릭터를 생성합니다." << endl;
    cout << "캐릭터 이름은? : ";
    cin >> name;
    Character me(name, 0, 0);
    int act = 0;
    while (act != 6) 
    {
        cout << "무엇을 하시겠습니까? \n1. 이름 변경 \n2. 레벨업 \n 3.아이템 줍기 \n4. 아이템사용 \n5. 캐릭터 정보 보기 \n6. 종료" << endl;
        cin >> act;
        if (act == 1) 
        {
            cout << "변경할 이름은? : ";
            cin >> name;
            me.changeName(name);
        }
        else if (act == 2) 
        {
            me.levelUp();
        }
        else if (act == 3)
        {
            me.addItem();
        }
        else if (act == 4)
        {
            int item_num;
            cout << "사용할 아이템 개수는? : ";
            cin >> item_num;
            me.removeItem(item_num);
        }
        else if (act == 5) 
        {
            me.showInfo();
        }
        else if (act == 6) 
        {
            cout << "종료합니다." << endl;
        }
        cout << "------------------------" << endl;
        cout << endl;
        cout << "------------------------" << endl;
    }
    return 0;
}