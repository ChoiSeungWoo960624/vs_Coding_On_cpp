/*
#include <iostream>
using namespace std;

class Animal
{
public:
	void MakeSound()
	{
		cout << "동물 소리를 냅니다." << endl;
	}
};

class Dog : public Animal
{
	public:
	void brak()
	{
		cout << "멍멍" << endl;
	}
};

int main()
{
	Dog MyDog;
	MyDog.MakeSound(); // Animal 클래스의 메서드 호출
	MyDog.brak(); // Dog 클래스의 메서드 호출
	return 0;
}

#include <iostream>
using namespace std;

class Parent
{
public:
	Parent() { cout << "부모 클래스 생성자 호출" << endl; }
	~Parent() { cout << "부모 클래스 소멸자 호출" << endl; }
};

class Child : public Parent
{
public:
	Child() { cout << "자식 클래스 생성자 호출" << endl; }
	~Child() { cout << "자식 클래스 소멸자 호출" << endl; }
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
	{ //매개 변수가 있는 생성자
		num = n;
		cout << "부모 클래스 생성자 호출" << num << endl;
	}
};

class Child : public Parent
{
public:
	// 부모 클래스의 생성자를 명시적으로 호출
	Child(int n) : Parent(n)
	{
		cout << "자식 클래스 생성자 호출" << endl;
	}
};

int main()
{
	Child c(10); // Child 객체 생성
	return 0;
}


// 멤버 이니셜라이저 리스트
#include <iostream>
using namespace std;

class Parent
{
public:
	int num;
	Parent(int n)
	{
		num = n;
		cout << "부모 클래스 생성자 호출 " << num << endl;
	}
};

class Child : public Parent
{
public:
	Child(int n) : Parent(n)
	{
		cout << "자식 클래스 생성자 호출" << endl;
	}
};

class Ex
{
public:
	Ex(int value) : x(value) {}

private:
	const int x; // 상수 멤버 변수
};

int main()
{
	Child c(10); // Child 객체 생성
	return 0;
}


// 실습 1 상속 연습 - shape
#include <iostream>
using namespace std;

class Shape // Shape 클래스
{
public:
	Shape(int sides, double baselength)
		: NumSides(sides), Base(baselength){}

	void printInfo() const 
	{
		cout << "변의 개수: " << NumSides << ", 밑변 길이: " << Base << endl;
	}

protected:
	int NumSides;
	double Base;
};

//상속 1 Rectangle - 세로 갖고있기
class Rectangle : public Shape 
{
public:
	Rectangle(int sides, double baselength, double verticallength)
		: Shape(sides, baselength), height(verticallength) {}

	void area() const 
	{
		double result = Base * height;
		printInfo();
		cout << "사각형의 세로 길이: " << height << endl;
		cout << "사각형의 넓이: " << result << endl;
	}

private:
	double height; // 멤버 변수
};

//상속 2 Triangle - 높이 갖고있기
class Triangle : public Shape 
{
public:
	Triangle(int sides, double baselength, double triangleheight)
		: Shape(sides, baselength), height(triangleheight) {}

	void area() const 
	{
		double result = 0.5 * Base * height;
		printInfo();
		cout << "삼각형의 높이: " << height << endl;
		cout << "삼각형의 넓이: " << result << endl;
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



// 접근 지정자(Access Specifiers)
#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
	string brand;

	void ShowBrand()
	{
		cout << "브랜드: " << brand << endl;
	}
};

int main()
{
	Car MyCar;
	MyCar.brand = "KIA";      // public 멤버에 직접 접근 가능
	MyCar.ShowBrand();        // public 멤버 함수 호출 가능
	return 0;
}

//private (비공개 멤버)
#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
	int balance; // private 멤버 변수 (직접 접근 불가)

public:
	void deposit(int amount)
	{
		balance += amount;
		cout << "입금 완료 ! 현재 잔액 : " << balance << "원" << endl;
	}
};

int main()
{
	BankAccount MyAccount;
	MyAccount.deposit(1000); // public 멤버 함수 호출 가능
	// myAccount.balance = 1000; // 오류: private 멤버에 직접 접근 불가 (컴파일 오류)
	return 0;
}
*/


// protected (보호된 멤버)

#include <iostream>
#include <string>
using namespace std;

class Parent
{
protected: //보호된 멤버 변수 (상속된 클래스에서 접근 가능)
	int protectedVar;
};

class Child : public Parent
{
public:
	void modifvValue(int newValue)
	{
		protectedVar = newValue; // 부모 클래스의 protected 멤버에 접근 가능
		cout << "protectedVar의 값: " << protectedVar << endl;
	}
};

int main()
{
	Parent MyParent;
	MyParent.protectedVar;  // 오류 : protected 멤버에 직접 접근 불가 (컴파일 오류)
	// 외부에서 접근 불가능
	return 0;
}


// 상속과 접근 지정자

// ┌────────────────────────────────────────────┐
// │ 상속 방식     │ 부모의 public 멤버  │ 부모의 protected 멤버 │ 부모의 private 멤버   │
// ├────────────────────────────────────────────┤
// │ public 상속   │ public 유지         │ protected 유지        │ 접근 불가             │
// │ protected 상속│ protected로 변경    │ protected 유지        │ 접근 불가             │
// │ private 상속  │ private로 변경      │ private로 변경        │ 접근 불가             │
// └────────────────────────────────────────────┘

// 접근 지정자 

// ┌────────────────────────────────────────────┐
// │ 접근 지정자    │ 클래스 내부 접근     │ 상속받은 클래스 접근     │ 외부 접근        │
// ├────────────────────────────────────────────┤
// │ public        │ 가능                  │가능                      │ 가능             │
// │ protected     │ 가능                  │ 가능                     │ 불가능           │
// │ private       │ 가능                  │ 불가능                   │ 불가능           │
// └────────────────────────────────────────────┘

// 예제 코드 

class Parent
{
public :
	int publicVar = 10; // public 멤버

protected:
	int protectedVar = 20; // protected 멤버

private:
	int privateVar = 30; // private 멤버
};

class Chlid : public Parent
{
public:
	void ShowValues()
	{
		cout << "publicVar : " << publicVar << endl; //  접근 가능 - public
		cout << "protectedVar: " << protectedVar << endl; // 접근 가능 - protected
		// cout << "privateVar: " << privateVar << endl; // 접근 불가 (오류) - private
	}
};

int main()
{
	Child obj;
	obj.modifvValue();
	cout << obj.publicVar << endl; // 접근 가능 - public
	// cout << obj.protectedVar << endl; // 접근 불가 (오류) - protected
	return 0;
}


// 실습 2. 상속과 접근 지저장
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
		cout << "브랜드: " << brand << ", 속도: " << speed << "km/h" << endl;
	}
};

class Car : public Vehicle 
{
private:
	int passengerCount;

public:
	Car(string b, int s, int p) : Vehicle(b, s), passengerCount(p) {}

	void printPassengerCount() const {
		cout << "승객 수: " << passengerCount << "명" << endl;
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
		cout << "적재 용량: " << loadCapacity << "톤" << endl;
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
상속의 유형 (1)

단일 상속(Single lnheritance) : 하나의 부모 클래스부터 상속을 받는 것

class a {};
class b : public A {};


상속의 유형 (2)

다중 상속(Multiple Inheritance) : 여러 개의 부모 클래스를 동시에 상속 받을 수 있다.

class a {};
class b {};
class c : public a, public b {}; // 다중 상속 

상속의 유형 (3)

다중 레벨 상속(Multilebel Inheritance) : 상속을 연속적으로 진행하는 방식

class a {};
class b : public a {}; // b는 a를 상속
class c : public b {}; // c는 b를 상속

상속의 유형 (4)

다이아몬드 상속 문제 (Diamond Problem)
:다중 상속에서 같은 부모 클래스를 두 번 상속받을 때 발생하는 문제

class a {};
class b : public a {};
class c : public a {};
class d : public b, public c {}; // a가 두번 상속됨 (문제발생)
-> 해결방법 : virtual 키워드를 사용하여 가상 상속을 수행해야한다.