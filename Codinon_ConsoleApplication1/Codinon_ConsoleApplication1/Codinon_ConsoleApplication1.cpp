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
#include <string>

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

// 실습 4번
int main()
{
	unsigned int num = 0b11011010;
	num = num & (1 << 4);
	cout << "결과 : " << (int)num;
	cout << "\n결과 : " << bitset<8>((int)num) << endl;
	return 0;
}

// 실습 5번
int main()
{
	unsigned int num = 0b11011011;
	num = num % 2;
	cout << "결과 : " << (int)num;
	cout << "\n결과 : " << bitset<8>((int)num) << endl;
	return 0;
}

// 실습 6번
int main()
{
	//unsigned int num = 0b11011011;
	//unsigned int num = 0b11011010;
	unsigned int num = 0b100000000;

	bool TwoCheck = (num != 0) && ((num & (num - 1)) == 0);
	cout << "결과 : " << TwoCheck << endl;
	return 0;
}

*/

int num = 10;

if (num > 0)
{
	cout << "양수입니다." << endl;
}
// -10을 넣게되면 아무것도 나오지 않음.

else if (num < 0)
{
	cout << "음수입니다." << endl;
}
else
{
	cout << "0입니다." << endl;
}



// if 실습 1
int main()
{
	int age;
	cout << "나이를 입력하세요: ";
	cin >> age;

	if (age >= 100)
	{
		cout << "건강하세요" << endl;
	}

	else if (age >= 1 && age <= 7)
	{
		cout << "애송이" << endl;
	}

	else if (age >= 8 && age <= 13)
	{
		cout << "초등학생" << endl;
	}

	else if (age >= 14 && age <= 16)
	{
		cout << "중학생" << endl;
	}

	else if (age >= 17 && age <= 19) {
		cout << "고등학생" << endl;
	}

	else if (age >= 20) {
		cout << "성인" << endl;
	}

	return 0;
}


// if 실습 2
int main()
{
	string Name;
	cout << "이름을 입력해주세요." << endl;
	cin >> Name;

	if (Name == "홍길동")
	{
		cout << "남자입니다." << endl;
	}
	else if (Name == "성춘향")
	{
		cout << "여자입니다." << endl;
	}
	else
	{
		cout << "몰루" << endl;
	}
	return 0;
}









// 실습 1 배열 연습 (1)

/*
#include <iostream>
using namespace std;

int main()
{
	string City[] = { "한국", "북한", "미국", "맥시코", "일본" };

	int size = sizeof(City) / sizeof(City[0]);

	for (int i = 0; i < size; i++)
	{
	   cout << City[i] << endl;
	}

	return 0;
}


// 실습 2 배열 연습 (2)

#include <iostream>
using namespace std;


int main()
{
	string City2[5];

	for (int i = 0; i < 5; i++)
	{
		cin >> City2[i];
	}

	int size = sizeof(City2) / sizeof(City2[0]);

	for (int i = 0; i < size; i++)
	{
		cout << City2[i] << endl;
	}

	return 0;
}
*/
    #include <iostream>
    using namespace std;

    int main()
    {
        // 실습 3 배열 연습 (3)
        int grade[5]; // 학생들의 성적
        int total = 0; // 학생들의 모든 점수

        for (int i = 0; i < 5; i++)
        {
            cout << i << "번 학생의 성적을 입력해주세요 : ";
            cin >> grade[i];
            total += grade[i];
        }

        // 평균 계산
        double average = static_cast<double>(total) / 5;
        cout << "학생들의 평균 성적은 : " << average << endl;
        cout << "학생들의 평균 성적은 : " << total / 5 << endl;

        return 0;
    }
