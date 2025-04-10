/*
#include <iostream>
using namespace std;

class Animal
{
public:
	void MakeSound()
	{
		cout << "���� �Ҹ��� ���ϴ�." << endl;
	}
};

class Dog : public Animal
{
	public:
	void brak()
	{
		cout << "�۸�" << endl;
	}
};

int main()
{
	Dog MyDog;
	MyDog.MakeSound(); // Animal Ŭ������ �޼��� ȣ��
	MyDog.brak(); // Dog Ŭ������ �޼��� ȣ��
	return 0;
}

#include <iostream>
using namespace std;

class Parent
{
public:
	Parent() { cout << "�θ� Ŭ���� ������ ȣ��" << endl; }
	~Parent() { cout << "�θ� Ŭ���� �Ҹ��� ȣ��" << endl; }
};

class Child : public Parent
{
public:
	Child() { cout << "�ڽ� Ŭ���� ������ ȣ��" << endl; }
	~Child() { cout << "�ڽ� Ŭ���� �Ҹ��� ȣ��" << endl; }
};

int main()
{
	Child obj;
	return 0;
}



#include <iostream>
using namespace std;

class Parent
{
public:
	int num;
	Parent(int n)
	{ //�Ű� ������ �ִ� ������
		num = n;
		cout << "�θ� Ŭ���� ������ ȣ��" << num << endl;
	}
};

class Child : public Parent
{
public:
	// �θ� Ŭ������ �����ڸ� ��������� ȣ��
	Child(int n) : Parent(n)
	{
		cout << "�ڽ� Ŭ���� ������ ȣ��" << endl;
	}
};

int main()
{
	Child c(10); // Child ��ü ����
	return 0;
}


// ��� �̴ϼȶ����� ����Ʈ
#include <iostream>
using namespace std;

class Parent
{
public:
	int num;
	Parent(int n)
	{
		num = n;
		cout << "�θ� Ŭ���� ������ ȣ�� " << num << endl;
	}
};

class Child : public Parent
{
public:
	Child(int n) : Parent(n)
	{
		cout << "�ڽ� Ŭ���� ������ ȣ��" << endl;
	}
};

class Ex
{
public:
	Ex(int value) : x(value) {}

private:
	const int x; // ��� ��� ����
};

int main()
{
	Child c(10); // Child ��ü ����
	return 0;
}


// �ǽ� 1 ��� ���� - shape
#include <iostream>
using namespace std;

class Shape // Shape Ŭ����
{
public:
	Shape(int sides, double baselength)
		: NumSides(sides), Base(baselength){}

	void printInfo() const 
	{
		cout << "���� ����: " << NumSides << ", �غ� ����: " << Base << endl;
	}

protected:
	int NumSides;
	double Base;
};

//��� 1 Rectangle - ���� �����ֱ�
class Rectangle : public Shape 
{
public:
	Rectangle(int sides, double baselength, double verticallength)
		: Shape(sides, baselength), height(verticallength) {}

	void area() const 
	{
		double result = Base * height;
		printInfo();
		cout << "�簢���� ���� ����: " << height << endl;
		cout << "�簢���� ����: " << result << endl;
	}

private:
	double height; // ��� ����
};

//��� 2 Triangle - ���� �����ֱ�
class Triangle : public Shape 
{
public:
	Triangle(int sides, double baselength, double triangleheight)
		: Shape(sides, baselength), height(triangleheight) {}

	void area() const 
	{
		double result = 0.5 * Base * height;
		printInfo();
		cout << "�ﰢ���� ����: " << height << endl;
		cout << "�ﰢ���� ����: " << result << endl;
	}

private:
	double height;
};

int main() 
{
	Rectangle rect(4, 11, 2.0);
	cout << "[Rectangle]" << endl;
	rect.area();

	Triangle tri(3, 15, 6.0);
	cout << "[Triangle]" << endl;
	tri.area();

	cout << endl;

	return 0;
}



// ���� ������(Access Specifiers)
#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
	string brand;

	void ShowBrand()
	{
		cout << "�귣��: " << brand << endl;
	}
};

int main()
{
	Car MyCar;
	MyCar.brand = "KIA";      // public ����� ���� ���� ����
	MyCar.ShowBrand();        // public ��� �Լ� ȣ�� ����
	return 0;
}

//private (����� ���)
#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
	int balance; // private ��� ���� (���� ���� �Ұ�)

public:
	void deposit(int amount)
	{
		balance += amount;
		cout << "�Ա� �Ϸ� ! ���� �ܾ� : " << balance << "��" << endl;
	}
};

int main()
{
	BankAccount MyAccount;
	MyAccount.deposit(1000); // public ��� �Լ� ȣ�� ����
	// myAccount.balance = 1000; // ����: private ����� ���� ���� �Ұ� (������ ����)
	return 0;
}
*/


// protected (��ȣ�� ���)

#include <iostream>
#include <string>
using namespace std;

class Parent
{
protected: //��ȣ�� ��� ���� (��ӵ� Ŭ�������� ���� ����)
	int protectedVar;
};

class Child : public Parent
{
public:
	void modifvValue(int newValue)
	{
		protectedVar = newValue; // �θ� Ŭ������ protected ����� ���� ����
		cout << "protectedVar�� ��: " << protectedVar << endl;
	}
};

int main()
{
	Parent MyParent;
	MyParent.protectedVar;  // ���� : protected ����� ���� ���� �Ұ� (������ ����)
	// �ܺο��� ���� �Ұ���
	return 0;
}


// ��Ӱ� ���� ������

// ��������������������������������������������������������������������������������������������
// �� ��� ���     �� �θ��� public ���  �� �θ��� protected ��� �� �θ��� private ���   ��
// ��������������������������������������������������������������������������������������������
// �� public ���   �� public ����         �� protected ����        �� ���� �Ұ�             ��
// �� protected ��Ӧ� protected�� ����    �� protected ����        �� ���� �Ұ�             ��
// �� private ���  �� private�� ����      �� private�� ����        �� ���� �Ұ�             ��
// ��������������������������������������������������������������������������������������������

// ���� ������ 

// ��������������������������������������������������������������������������������������������
// �� ���� ������    �� Ŭ���� ���� ����     �� ��ӹ��� Ŭ���� ����     �� �ܺ� ����        ��
// ��������������������������������������������������������������������������������������������
// �� public        �� ����                  ������                      �� ����             ��
// �� protected     �� ����                  �� ����                     �� �Ұ���           ��
// �� private       �� ����                  �� �Ұ���                   �� �Ұ���           ��
// ��������������������������������������������������������������������������������������������

// ���� �ڵ� 

class Parent
{
public :
	int publicVar = 10; // public ���

protected:
	int protectedVar = 20; // protected ���

private:
	int privateVar = 30; // private ���
};

class Chlid : public Parent
{
public:
	void ShowValues()
	{
		cout << "publicVar : " << publicVar << endl; //  ���� ���� - public
		cout << "protectedVar: " << protectedVar << endl; // ���� ���� - protected
		// cout << "privateVar: " << privateVar << endl; // ���� �Ұ� (����) - private
	}
};

int main()
{
	Child obj;
	obj.modifvValue();
	cout << obj.publicVar << endl; // ���� ���� - public
	// cout << obj.protectedVar << endl; // ���� �Ұ� (����) - protected
	return 0;
}


// �ǽ� 2. ��Ӱ� ���� ������
#include <iostream>
#include <string>
using namespace std;

class Vehicle 
{
protected:
	int speed;

public:
	string brand;
	Vehicle(string b, int s) : brand(b), speed(s) {}

	void printInfo() const 
	{
		cout << "�귣��: " << brand << ", �ӵ�: " << speed << "km/h" << endl;
	}
};

class Car : public Vehicle 
{
private:
	int passengerCount;

public:
	Car(string b, int s, int p) : Vehicle(b, s), passengerCount(p) {}

	void printPassengerCount() const {
		cout << "�°� ��: " << passengerCount << "��" << endl;
	}
};

class Truck : public Vehicle 
{
private:
	double loadCapacity;

public:
	Truck(string b, int s, double l) : Vehicle(b, s), loadCapacity(l) {}

	void printLoadCapacity() const 
	{
		cout << "���� �뷮: " << loadCapacity << "��" << endl;
	}
};

int main() 
{
	Car myCar("Hyundai", 120, 5);
	Truck myTruck("Volvo", 90, 125);

	myCar.printInfo();
	myCar.printPassengerCount();

	myTruck.printInfo();
	myTruck.printLoadCapacity();

	return 0;
}

/*
����� ���� (1)

���� ���(Single lnheritance) : �ϳ��� �θ� Ŭ�������� ����� �޴� ��

class a {};
class b : public A {};


����� ���� (2)

���� ���(Multiple Inheritance) : ���� ���� �θ� Ŭ������ ���ÿ� ��� ���� �� �ִ�.

class a {};
class b {};
class c : public a, public b {}; // ���� ��� 

����� ���� (3)

���� ���� ���(Multilebel Inheritance) : ����� ���������� �����ϴ� ���

class a {};
class b : public a {}; // b�� a�� ���
class c : public b {}; // c�� b�� ���

����� ���� (4)

���̾Ƹ�� ��� ���� (Diamond Problem)
:���� ��ӿ��� ���� �θ� Ŭ������ �� �� ��ӹ��� �� �߻��ϴ� ����

class a {};
class b : public a {};
class c : public a {};
class d : public b, public c {}; // a�� �ι� ��ӵ� (�����߻�)
-> �ذ��� : virtual Ű���带 ����Ͽ� ���� ����� �����ؾ��Ѵ�.