/*
// Codinon_ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
// 확인용



#include <iostream>
using namespace std;


int main()
{
	/*
	cout << "Hello world" << endl;
	// 선언만 하기
	int numver;

	// 선언 후 초기화
	int count;
	count = 20;
	cout << "count : " << count << endl;

	// 선언과 동시에 초기화
	int value = 30; // 할당 초기화
	int score(49); // 직접 초기화

	
	cout << "value" << value << endl;
}


float number;

// 선언 후 초기화
float count;
count = 20.25323524323425234234245;

float value = 30.2; // 할당 초기화
float score(49.3); // 직접 초기화	

cout << "count : " << count << endl;

	// 불리언 자료형
	bool isTrue = true;
	bool isFalse = false;
	
	cout << "isTrue : " << isTrue << "\nisFalse : " << isFalse << endl;

	char a = 'a';
	char b = 'c';
	cout << "a b : " << a << b;

	string str1 = "문자열 입니다.";
		cout << str1 << endl;

		string str1 = "문자열 입니다.";
		string str2 = "오류가 날까요?";

		int a;
		string b;

		cin >> a;
		cin >> b;
		
		
		string name;
		cout << " 이름을 입력하세요." << endl;
		cin >> name;
		string age;
		cout << "나이를 입력하세요." << endl;
		cin >> age;
	 
		cout << "안녕하세요 ! " << name << "님" << "(" << age << "세)" << endl;
		

		int a = 10, b = 3;
		int sum = a + b;
		int differnce = a - b;
		int product = a * b;
		int quotient = a / b;
		int remainder = a % b;

		double result = static_cast<double>(a) / b;

		

	// 증감 연산자 
		x++;
		x--;
		++x;
		--x;
		*/
		/*
		int a = 5, b = 5;
		int resultA = ++a; // 전위
		cout << "resultA : " << resultA << endl;
		int resultB = b++; // 후위
		cout << "resultA : " << resultB << endl;

		int x = 10, y = 20;
		bool isEqual = (x == y);	
		bool isNotEqual = (x != y);
		bool isGreater = (x > y);
		bool isLess = (x < y);	
		bool isGreaterOrEqual = (x >= y);
		bool isLessOrEqual = (x <= y);

		// 논리 연산자
		bool condition1 = true, condition2 = false;
		bool andresult1 = condition1 && condition2; // AND
		bool orresult = condition1 || condition2; // OR
		bool notresult = !condition1; // NOT

		bool complexLogic = (x > 5 && y < 30) || (x == y);
}
*/


#include <iostream>
#include <bitset>
using namespace std;

/*
// 실습 1번
int main() {

	unsigned char num = 0b00010010;
	//      00010010 
	// or   00100000
	//      00110010
	// 다섯번째 비트를 1 로 
	num = num | (1 << 5);
	cout << "결과 : " << (int)num;
	cout << "\n결과 : " << bitset<8>((int)num) << endl;
	return 0;
}

//실습 2번
int main() 
{
	unsigned int num = 0b10101111;
	num = num & ~(1 << 2);
	cout << "결과 : " << (int)num;
	cout << "\n결과 : " << bitset<8>((int)num) << endl;
	return 0;
}

// 실습 3 번
int main()
{
	unsigned int num = 0b11011010;
	num = num ^(1 << 4);
	cout << "결과 : " << (int)num;
	cout << "\n결과 : " << bitset<8>((int)num) << endl;
	return 0;
}
*/

