/*
#include <iostream>
using namespace std;

class Car 
{
    // �����
    // �ش� Ŭ���� �������� ���� �����ϴ�.
    //private:
  // ��𼭳� ���� �����ϴ�.
public:
    string brand;
    int speed;

    void display() 
    {
        cout << "������ �귣��� " << brand << "�̰� �ӵ��� " << speed << "km/h �Դϴ�." << endl;
    }
};

class Point
{
    //Ŭ���� ���ο����� ������ �����ϴ�.
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
        cout << "�̸�: " << Name << endl;
        cout << "����: " << Age << endl;
    }
};

int main() 
{
    Person p;

    string InName;
    int InAge;

    cout << "�̸��� �Է����ּ��� : ";
    getline(cin, InName);

    cout << "���̸� �Է����ּ��� : ";
    cin >> InAge;

    p.setName(InName);
    p.setAge(InAge);

    p.showInfo();

    return 0;
}


// �ǽ� 2 Ŭ���� ����غ��� (2) - �簢��
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

    cout << "���� �� : ";
    cin >> w;

    cout << "���� �� : ";
    cin >> h;

    Rectangle rect(w, h);

    cout << "���� : " << rect.area() << endl;

    return 0;
}


// �ǽ� 2-1 Ŭ���� ����غ���
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
        width = w; //����
        height = h; //����
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

    cout << "���� �� : ";
    cin >> w;

    cout << "���� �� : ";
    cin >> h;

    Rectangle rect(w, h);
    cout << "���� : " << rect.area() << endl;

    Rectangle copy1(rect);
    cout << "������ ���� : " << copy1.area() << endl;

    Rectangle copy2;  // �⺻ ������
    copy2 = rect;     // ���� ����
    cout << "������ ���� : " << copy2.area() << endl;

    return 0;
}


// �ǽ� 3. Ŭ���� ����غ���(3) - ����
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
        cout << "���� ������ : " << AccountNumber << endl;
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
        cout << "���¹�ȣ " << AccountNumber << "�� �ܾ��� " << Balance << "�� �Դϴ�." << endl;
    }
};

int main() 
{
    int AccNum, inBalance;

    cout << "���¹�ȣ �Է�: ";
    cin >> AccNum;

    cout << "�ʱ� �ܾ� �Է�: ";
    cin >> inBalance;

    BankAccount account(AccNum, inBalance);

    account.deposit(12000); //�Ա�
    account.withdraw(4000); //���
    account.print();

    return 0;
}
*/

//�ǽ� 4. ���� ĳ���� �����ϱ� 
#include <iostream>
using namespace std;

//ĳ���� Ŭ����
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
        cout << "ĳ���� ���� �Ϸ�! ĳ���͸� : " << name << endl;
    }

    void showInfo() 
    {
        cout << "ĳ���͸� : " << name << endl;
        cout << "���� : " << level << endl;
        cout << "������ ���� : " << item_num << endl;
    }
    void levelUp() 
    {
        level++;
        cout << "������! ���� ���� : " << level << endl;
    }
    void addItem() 
    {
        item_num += 1;
        cout << "������ �߰�! ���� ������ ���� : " << item_num << endl;
    }
    void removeItem(int num) 
    {
        if (item_num >= num) 
        {
            item_num -= num;
            cout << "������ ���! ���� ������ ���� : " << item_num << endl;
        }
        else {
            cout << "�������� �����մϴ�!" << endl;
        }
    }
    void changeName(string newName) 
    {
        name = newName;
        cout << "�̸� ���� �Ϸ�! ���� ĳ���͸� : " << name << endl;
    }
};

int main()
{
    string name;
    cout << "ĳ���͸� �����մϴ�." << endl;
    cout << "ĳ���� �̸���? : ";
    cin >> name;
    Character me(name, 0, 0);
    int act = 0;
    while (act != 6) 
    {
        cout << "������ �Ͻðڽ��ϱ�? \n1. �̸� ���� \n2. ������ \n 3.������ �ݱ� \n4. �����ۻ�� \n5. ĳ���� ���� ���� \n6. ����" << endl;
        cin >> act;
        if (act == 1) 
        {
            cout << "������ �̸���? : ";
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
            cout << "����� ������ ������? : ";
            cin >> item_num;
            me.removeItem(item_num);
        }
        else if (act == 5) 
        {
            me.showInfo();
        }
        else if (act == 6) 
        {
            cout << "�����մϴ�." << endl;
        }
        cout << "------------------------" << endl;
        cout << endl;
        cout << "------------------------" << endl;
    }
    return 0;
}