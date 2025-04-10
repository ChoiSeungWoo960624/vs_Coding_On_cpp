#include <iostream>
using namespace std;

struct Tire
{
	string brand;
	int size;

	void display() 
    {
		cout << "Ÿ�̾� �귣��� " << brand << " ������� " << size << "�̴�" << endl;
	}
};

struct Car
{
	// ��� ����
	string brand;
	int speed;
	Tire tire;

	void accelerate() 
    {
		speed += 10;
	}

	void display() 
    {
		cout << "�ڵ��� �귣��� " << brand << "�̰� �ӵ��� " << speed << "km/h �̴�." << endl;
		tire.display();
	}
};

struct Rectangle
{
	int width;
	int height;
};


struct Point
{
	// ��� ����
	int x;
	int y;

	// ��� �Լ�
	void add(const Point p)
    {
		x += p.x;
		y += p.y;
	}
};

int main()
{
	Car myCar = { "tesla", 100, {"��ȣ", 17}};

	cout << myCar.brand << endl;
	cout << myCar.tire.size << endl;

	myCar.display();
	myCar.accelerate();
	myCar.display();

	Car* ptr = &myCar;
	cout << "������ �귣��� " << ptr->brand << endl;
	cout << "Ÿ�̾��� �귣��� " << ptr->tire.brand << endl;

#include <iostream>
#include <string>
using namespace std;

struct Rectangle
{
    int width;
    int height;

    int area()
    {
        return width * height;
    }
};

int main() 
{
    Rectangle rect;

    cout << "���� ���� : ";
    cin >> rect.width;

    cout << "���� ���� : ";
    cin >> rect.height;

    cout << "�簢���� ����: " << rect.area() << endl;

    return 0;
}

// main�ȿ��� ���� ���
#include <iostream>
using namespace std;

struct Rectangle
{
    int width;
    int height;
};

int main()
{
    Rectangle rect;

    cout << "���� ���� : ";
    cin >> rect.width;

    cout << "���� ���� : ";
    cin >> rect.height;

    int area = rect.width * rect.height;

    cout << "�簢���� ����(width * height) : " << area << endl;

    return 0;
}




#include <iostream>
#include <string>
using namespace std;

struct Point 
{
    int x;
    int y;

    Point add(const Point& other) 
    {
        Point Result;
        Result.x = x + other.x;
        Result.y = y + other.y;
        return Result;
    }
};

int main() 
{
    Point p1, p2;

    cout << "ù ��° x ��ǥ: ";
    cin >> p1.x;
    cout << "ù ��° y ��ǥ: ";
    cin >> p1.y;

    cout << "�� ��° x ��ǥ: ";
    cin >> p2.x;
    cout << "�� ��° y ��ǥ: ";
    cin >> p2.y;

    Point sum = p1.add(p2);

    cout << "��ǥ �� : (" << sum.x << ", " << sum.y << ")" << endl;

    return 0;
}
