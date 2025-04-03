/*/#include <iostream>
using namespace std;

//더하기 함수
int add(int a, int b)
{
	int sum = a + b;
	return sum;
}

 // 곱하기
int multiply(int a, int y)
{
	return x * y;
}
//나이
int GetAge()
{
	return 25;
 }
double GetPi()
{
	return 3.1415926;
 }
char GetGrade()
{
	return 'A';
}

bool IsValid()
{
	return true;
}

void PrintMessage()
{
	cout <<
}

int main()
{
	int result = add(10, 20);
	cout << "10 + 20 = " << result << endl;
	int result2 = multiply(10, 20);
	cout << "10 "
}


//실습 1. 사칙연산 함수 만들기
#include <iostream>
using namespace std;

//1)
int add(int a, int b)
{
	return a + b;
}
//2)
int sub(int a, int b)
{
	return max(a, b) - min(a, b);
}

//3)
int mul(int a, int b) {
	return a * b;
}

//4)
double divide(int a, int b) {
	return static_cast<double>(a) / b;
}

// 5)
	int main() {

	int x;
	cin >> x;
	int y;
	cin >> y;

	cout << "덧셈 결과: " << (double)add(x, y) << endl;
	cout << "뺄셈 결과: " << (double)sub(x, y) << endl;
	cout << "곱셈 결과: " << (double)mul(x, y) << endl;
	cout << "나눗셈 결과: " << (double)divide(x, y) << endl;

	return 0;
}


// 실습2 홀짝 판별기
#include <iostream>
using namespace std;

void holjak(int num)
{
	if (num % 2 == 0)
	{
		cout << num << "은(는) 짝수입니다." << endl;
	}
	else
	{
		cout << num << "은(는) 홀수입니다." << endl;
	}
}

int main()
{
	int n;
	cout << "정수를 입력하세요: ";
	cin >> n;
	if (n % 2 == 0)
	{
		cout << n << "은(는) 짝수입니다." << endl;
	}
	else
	{
		cout << n << "은(는) 홀수입니다." << endl;
	}

	return 0;
}

// 실습 3. 최댓값 찾기
#include <iostream>
using namespace std;

int FindMax(int a, int b, int c)
{
	int max;

	if (a >= b && a >= c)
	{
		max = a;
	}
	else if (b >= a && b >= c)
	{
		max = b;
	}
	else
	{
		max = c;
	}

	return max;
}

int main()
{
	int num1, num2, num3;
	cout << "세 개의 정수를 입력하세요: ";
	cin >> num1 >> num2 >> num3;

	int maxNum = FindMax(num1, num2, num3);
	cout << "가장 큰 수는: " << maxNum << endl;

	return 0;
}




void recursivefunctuon(int n)
{
	if (n == 0) //기본 조건 (base, case)
	{
		return;
	}
	else
	{
		cout << n << " ";
		recursivefunctuon(n - 1);
	}
}


// 실습 4. 팩토리얼 계산기
#include <iostream>
using namespace std;

int fac(int n)
{
	int result = 1;
	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}
	return result;
}

int main()
{
	int num;
	cout << "정수 입력: ";
	cin >> num;

	cout << num << "! = " << fac(num) << endl;
	return 0;
}

// 실습 5. 피보나치 수열
#include <iostream>
using namespace std;

int fibonacci(int n)
{
	if (n <= 1)
	{
		return n;
	}
	else if (n == 0)
	{
		return 0;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}
int main()
{
	int n;
	cout << "피보나치 수열의 항을 입력하세요: ";
	cin >> n;
	cout << "피보나치 수열의 " << n << "번째 항은: " << fibonacci(n) << endl;
	return 0;
}*/

// 실습 6. 거듭 제곱	
#include <iostream>
using namespace std;

int home(int base, int exp)
{
	if (exp == 0)
	{
		return 1;
	}
	else
	{
		return base * home(base, exp - 1);
	}
}
int main()
{
	int base, exp;
	cout << "밑(base)과 지수(exp)를 입력하세요: ";
	cin >> base >> exp;
	cout << base << "^" << exp << " = " << home(base, exp) << endl;
	return 0;
}


