/*
#include <iostream>
using namespace std;


class Math
{
public:
	int add(int a, int b)
	{
		cout << "1�� add ȣ��" << endl;
		return a + b;
	}
	int add(int a, int b, int c)
	{
		cout << "2�� add ȣ��" << endl;
		return a + b + c;
	}
		double add(double a, double b)
	{
		cout << "3�� add ȣ��" << endl;
		return a + b;
	}
};

int main()
{
	Math m;
	cout << m.add(1, 2) << endl; // 1�� add ȣ��
	cout << m.add(1, 2, 3) << endl; // 2�� add ȣ��
	cout << m.add(1.5, 2.5) << endl; // 3�� add ȣ��
	return 0;
}


// �ǽ�1. �Լ� �����ε� - ���� ����ϱ�
#include <iostream>
using namespace std;


class Shape
{
public:
	int area(int side)
	{
		cout << "���簢���� ���� ȣ��" << endl;
		return side * side;
	}
	int area(int width, int height)
	{
		cout << "���簢���� ���� ȣ��" << endl;
		return width * height;
	}
	double area(double radius)
	{
		cout << "���� ���� ȣ��" << endl;
		return radius * radius * 3.14;
	}
};
int main()
{
	Shape s;
	cout << s.area(5) << endl;
	cout << s.area(5, 10) << endl;
	cout << s.area(3.5) << endl;
	return 0;
}


// ������ �����ε�
#include <iostream>
using namespace std;

class Weight
{
public:
	int kg;

	Weight(int w) : kg(w) {} // ������
	~Weight() {} // �Ҹ���

	// "+" ������ �����ε�
	Weight operator+(const Weight& other)
	{
		return Weight(kg + other.kg);
	}

	// ���� ��� �Լ�
	void show()
	{
		cout << "Weight: " << kg << "kg" << endl;
	}
};

int main()
{
	Weight w1(50), w2(30);
	Weight w3 = w1 + w2; // ������ �����ε��� ����Ͽ� �� ���� Weight ��ü�� ����
	w3.show(); // ���� �̸� ����
	return 0;
}


// �ǽ�2. ������ �����ε� - ��ǥ ����
#include <iostream>
using namespace std;

class point
{
public:
	int x, y;
	point(int x, int y) : x(x), y(y) {} // ������
	~point() {}

	point operator+(const point& other)
	{
		return point(x + other.x, y + other.y);
	}
		void show()
		{
			cout << "��ǥ: (" << x << ", " << y << ")" << endl;
	}
};

	int main()
	{
		point p1(1, 2), p2(3, 4);
		point p3 = p1 + p2;
		p3.show();
		return 0;
	}

// �����ε� vs �������̵�

	// ======================== �����ε� vs �������̵� ==============================================================
	// | ����       | �����ε�(Overloading)                         | �������̵�(Overriding)                        |
	// |------------|-----------------------------------------------|-----------------------------------------------|
	// | ����       | ���� �Լ� �̸��� ���� �� ����                 | �θ� Ŭ������ �Լ��� �ڽ� Ŭ�������� ������   |
	// | ��� ����  | ���� Ŭ���� ������ ����                       | ��� ���迡���� ����                          |
	// | �Լ� �̸�  | ����                                          | ����                                          |
	// | �Ű�����   | �ٸ� (���� or Ÿ��)                           | ����                                          |
	// | ��ȯ Ÿ��  | �������                                      | ���ų� covariant ����                         |
	// | Ű����     | ����                                          | virtual ���                                  |
	// ==============================================================================================================

// ���� ���ε��� ���� ���ε�
// ======================== ���� ���ε� vs ���� ���ε� ==========================================================
// | Ư¡                | ���� ���ε�                           | ���� ���ε�                                   |
// |---------------------|---------------------------------------|-----------------------------------------------|
// | �Լ� ȣ�� ���� ���� | ������ Ÿ��                           | ���� �ð� (��Ÿ��)                            |
// | ��� Ű����         | �Ϲ� �Լ�                             | virtual Ű���� ���                           |
// | �������̵� ���� ����| �������̵� �� ��                      | �������̵� �����                             |
// | ����                | ���� (������ �� ����)                 | ��������� ���� (��Ÿ�� ����)                 |
// | ����                | �Ϲ� ��� �Լ�, �Լ� �����ε�         | ���� �Լ�(virtual), ������                    |
// ==============================================================================================================


// �������̵��� �⺻ ����
#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void speak() // ���� �Լ�
	{
		cout << "������ �Ҹ��� ���ϴ�." << endl;
	}
};

class Dog : public Animal
{
public:
	void speak() override // �������̵��� �Լ�
	{
		cout << "�۸�!" << endl; // �������̵�
	}
};

int main()
{
	Animal* animal = new Dog(); // Animal �����Ͱ� Dog ��ü�� ����Ŵ
	animal->speak(); // ���� ���ε�: Dog Ŭ������ speak() ȣ��
	delete animal; // �޸� ����
	return 0;
}

Animal* aPtr;
int choice;

cout << "1. Dog \n2. Cat";
cin >> choice;

if (choice == 1)
{
	aPtr = new Dog();
}
else if (choice == 2)
{
	aPtr = new Cat();
}
else
{
	cout << "�߸��� �����Դϴ�." << endl;
	myPet->speak(); // ���� ���ε�: Dog Ŭ������ speak() ȣ��
	delete aPtr;
	return 0;
}


// �ǽ�3. �������̵� - �ڵ��� ���� ��� ����
#include <iostream>
using namespace std;

class Vehicle 
{
public:
	virtual void accelerate() 
	{
		cout << "�ڵ��� ������ �����ϼ���: " << endl;
	}
};

class Car : public Vehicle 
{
public:
	void accelerate() override 
	{
		cout << "Car - �Ϲ�" << endl;
	}
};

class SportsCar : public Vehicle 
{
public:
	void accelerate() override 
	{
		cout << "SportsCar ������ī" << endl;
	}
};

class Truck : public Vehicle 
{
public:
	void accelerate() override
	{
		cout << "Truck Ʈ��" << endl;
	}
};

void main() 
{
	Vehicle* vehicles[] = { new Car(), new SportsCar(), new Truck() };

	for (Vehicle* vehicle : vehicles) 
	{
		vehicle->accelerate();
	}

	for (Vehicle* vehicle : vehicles) 
	{
		delete vehicle;
	}
}
*/


// �߻� Ŭ����

#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void speak() = 0; // ���� ���� �Լ�
};

class Dog : public Animal
{ 
public:
	void sonud() override
	{
		cout << "�۸�!" << endl;
	}
};

class Cat : public Animal
{
public:
	void sound() override
	{
		cout << "�߿�!" << endl;
	}
};

int main()
{
	Animal* animals[] = { new Dog(), new Cat() };

	for (Animal* a : animals)
	{
		a->sound(); // ���� ���ε�
	}

	return 0;
}
