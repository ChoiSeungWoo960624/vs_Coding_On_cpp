/*
#include <iostream>
using namespace std;


class Math
{
public:
	int add(int a, int b)
	{
		cout << "1번 add 호출" << endl;
		return a + b;
	}
	int add(int a, int b, int c)
	{
		cout << "2번 add 호출" << endl;
		return a + b + c;
	}
		double add(double a, double b)
	{
		cout << "3번 add 호출" << endl;
		return a + b;
	}
};

int main()
{
	Math m;
	cout << m.add(1, 2) << endl; // 1번 add 호출
	cout << m.add(1, 2, 3) << endl; // 2번 add 호출
	cout << m.add(1.5, 2.5) << endl; // 3번 add 호출
	return 0;
}


// 실습1. 함수 오버로딩 - 면적 계산하기
#include <iostream>
using namespace std;


class Shape
{
public:
	int area(int side)
	{
		cout << "정사각형의 면적 호출" << endl;
		return side * side;
	}
	int area(int width, int height)
	{
		cout << "직사각형의 면적 호출" << endl;
		return width * height;
	}
	double area(double radius)
	{
		cout << "원의 면적 호출" << endl;
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


// 연산자 오버로딩
#include <iostream>
using namespace std;

class Weight
{
public:
	int kg;

	Weight(int w) : kg(w) {} // 생성자
	~Weight() {} // 소멸자

	// "+" 연산자 오버로딩
	Weight operator+(const Weight& other)
	{
		return Weight(kg + other.kg);
	}

	// 무게 출력 함수
	void show()
	{
		cout << "Weight: " << kg << "kg" << endl;
	}
};

int main()
{
	Weight w1(50), w2(30);
	Weight w3 = w1 + w2; // 연산자 오버로딩을 사용하여 두 개의 Weight 객체를 더함
	w3.show(); // 변수 이름 수정
	return 0;
}


// 실습2. 연산자 오버로딩 - 좌표 연산
#include <iostream>
using namespace std;

class point
{
public:
	int x, y;
	point(int x, int y) : x(x), y(y) {} // 생성자
	~point() {}

	point operator+(const point& other)
	{
		return point(x + other.x, y + other.y);
	}
		void show()
		{
			cout << "좌표: (" << x << ", " << y << ")" << endl;
	}
};

	int main()
	{
		point p1(1, 2), p2(3, 4);
		point p3 = p1 + p2;
		p3.show();
		return 0;
	}

// 오버로딩 vs 오버라이딩

	// ======================== 오버로딩 vs 오버라이딩 ==============================================================
	// | 개념       | 오버로딩(Overloading)                         | 오버라이딩(Overriding)                        |
	// |------------|-----------------------------------------------|-----------------------------------------------|
	// | 목적       | 같은 함수 이름을 여러 개 정의                 | 부모 클래스의 함수를 자식 클래스에서 재정의   |
	// | 사용 조건  | 같은 클래스 내에서 가능                       | 상속 관계에서만 가능                          |
	// | 함수 이름  | 같음                                          | 같음                                          |
	// | 매개변수   | 다름 (개수 or 타입)                           | 동일                                          |
	// | 반환 타입  | 상관없음                                      | 같거나 covariant 가능                         |
	// | 키워드     | 없음                                          | virtual 사용                                  |
	// ==============================================================================================================

// 정적 바인딩과 동적 바인딩
// ======================== 정적 바인딩 vs 동적 바인딩 ==========================================================
// | 특징                | 정적 바인딩                           | 동적 바인딩                                   |
// |---------------------|---------------------------------------|-----------------------------------------------|
// | 함수 호출 결정 시점 | 컴파일 타임                           | 실행 시간 (런타임)                            |
// | 사용 키워드         | 일반 함수                             | virtual 키워드 사용                           |
// | 오버라이딩 적용 여부| 오버라이딩 안 됨                      | 오버라이딩 적용됨                             |
// | 성능                | 빠름 (컴파일 시 결정)                 | 상대적으로 느림 (런타임 결정)                 |
// | 예제                | 일반 멤버 함수, 함수 오버로딩         | 가상 함수(virtual), 다형성                    |
// ==============================================================================================================


// 오버라이딩의 기본 문법
#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void speak() // 가상 함수
	{
		cout << "동물이 소리를 냅니다." << endl;
	}
};

class Dog : public Animal
{
public:
	void speak() override // 오버라이딩된 함수
	{
		cout << "멍멍!" << endl; // 오버라이딩
	}
};

int main()
{
	Animal* animal = new Dog(); // Animal 포인터가 Dog 객체를 가리킴
	animal->speak(); // 동적 바인딩: Dog 클래스의 speak() 호출
	delete animal; // 메모리 해제
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
	cout << "잘못된 선택입니다." << endl;
	myPet->speak(); // 동적 바인딩: Dog 클래스의 speak() 호출
	delete aPtr;
	return 0;
}


// 실습3. 오버라이딩 - 자동차 가속 기능 구현
#include <iostream>

using namespace std;

class Vehicle 
{
public :
	void accelerate()
	{
		cout << "자동차 시속 30km 증가!" << endl;
	}
};

class Car : public Vehicle 
{
public:
	void accelerate() 
	{
		cout << "자동차 시속 30km 증가!" << endl;
	}
};

class Truck : public Vehicle 
{
public:
	void accelerate() 
	{
		cout << "트럭 시속 20km 증가!" << endl;
	}
};
class SportsCar : public Vehicle 
{
public:
	void accelerate() 
	{
		cout << "스포츠카 시속 50km 증가!" << endl;
	}
};

int main()
{
	cout << "자동차 유형을 선택하세요 :\n1. Car (일반 자동차)\n2. Truck (트럭)\n3. SportsCar (스포츠카)\n입력 : " << endl;
	int choice;
	cin >> choice;
	if (choice == 1) 
	{
		Car car;
		car.accelerate();
	}
	else if (choice == 2) 
	{
		Truck truck;
		truck.accelerate();
	}
	else if (choice == 3) 
	{
		SportsCar sportsCar;
		sportsCar.accelerate();
	}
	else 
	{
		cout << "잘못된 선택입니다." << endl;
	}
}
*/

#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void speak() = 0; // 순수 가상 함수
};

class Dog : public Animal
{
public:
	void speak() override
	{
		cout << "멍멍!" << endl;
	}
};

class Cat : public Animal
{
public:
	void speak() override
	{
		cout << "야옹!" << endl;
	}
};

int main()
{
	Animal* animals[] = { new Dog(), new Cat() };

	for (Animal* a : animals)
	{
		a->speak(); // 동적 바인딩
	}

	// 메모리 해제
	for (Animal* a : animals)
	{
		delete a;
	}

	return 0;
}

//실습 4. 과자, 사탕, 초콜릿

#include <iostream>
#include <string>
using namespace std;

// 추상 클래스 Snack
class Snack 
{
protected:
	string productName;
	string company;
	int price;

public:
	Snack(string name, string comp, int pr)
		: productName(name), company(comp), price(pr) {}

	virtual void printInfo() const = 0; // 순수 가상 함수
	virtual ~Snack() {} // 소멸자도 가상으로
};

// Candy 클래스
class Candy : public Snack 
{
private:
	string taste;

public:
	Candy(string name, string comp, int pr, string t)
		: Snack(name, comp, pr), taste(t) {}

	void printInfo() const override 
	{
		cout << "[Candy] " << productName << ", " << company << ", "
			<< price << "원, Taste: " << taste << endl;
	}
};

// Chocolate 클래스
class Chocolate : public Snack 
{
private:
	string shape;

public:
	Chocolate(string name, string comp, int pr, string sh)
		: Snack(name, comp, pr), shape(sh) {}

	void printInfo() const override 
	{
		cout << "[Chocolate] " << productName << ", " << company << ", "
			<< price << "원, Shape: " << shape << endl;
	}
};

int main() 
{
	// Snack 포인터 배열
	Snack* snackBasket[4];

	// Candy 객체 2개
	snackBasket[0] = new Candy("SweetBerry", "CandyCo", 500, "Strawberry");
	snackBasket[1] = new Candy("MintyFresh", "FreshCandy", 600, "Mint");

	// Chocolate 객체 2개
	snackBasket[2] = new Chocolate("ChocoStar", "ChocoWorld", 1000, "Star");
	snackBasket[3] = new Chocolate("BlockChoco", "SweetBar", 1200, "Block");

	// 모든 간식 정보 출력
	for (int i = 0; i < 4; ++i) {
		snackBasket[i]->printInfo();
	}

	// 메모리 해제
	for (int i = 0; i < 4; ++i) {
		delete snackBasket[i];
	}

	return 0;
}

//실습 5. AI 챗봇 시스템 설계

#include <iostream>
#include <string>
using namespace std;

// 추상 클래스 Chatbot
class Chatbot {
public:
	virtual void respond(const string& message) = 0; // 순수 가상 함수
	virtual ~Chatbot() {} // 가상 소멸자
};

// 고객 지원 봇
class CustomerSupportBot : public Chatbot {
public:
	void respond(const string& message) override {
		cout << "고객 지원 문의를 처리합니다: " << message << endl;
	}
};

// 날씨 봇
class WeatherBot : public Chatbot {
public:
	void respond(const string& message) override {
		cout << "현재 날씨 정보를 제공합니다: " << message << endl;
	}
};

// 메인 함수
int main() {
	Chatbot* bot = nullptr;
	string userInput;
	int choice;

	cout << "챗봇을 선택하세요:\n1. 고객 지원 봇\n2. 날씨 봇\n선택: ";
	cin >> choice;
	cin.ignore(); // 입력 버퍼 비우기

	cout << "메시지를 입력하세요: ";
	getline(cin, userInput);

	if (choice == 1) {
		bot = new CustomerSupportBot();
	}
	else if (choice == 2) {
		bot = new WeatherBot();
	}
	else {
		cout << "잘못된 선택입니다." << endl;
		return 1;
	}

	bot->respond(userInput);

	delete bot;
	return 0;
}
