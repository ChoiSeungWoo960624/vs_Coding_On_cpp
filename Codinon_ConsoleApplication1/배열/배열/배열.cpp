/*/#include <iostream>
using namespace std;

//���ϱ� �Լ�
int add(int a, int b)
{
	int sum = a + b;
	return sum;
}

 // ���ϱ�
int multiply(int a, int y)
{
	return x * y;
}
//����
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


//�ǽ� 1. ��Ģ���� �Լ� �����
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

	cout << "���� ���: " << (double)add(x, y) << endl;
	cout << "���� ���: " << (double)sub(x, y) << endl;
	cout << "���� ���: " << (double)mul(x, y) << endl;
	cout << "������ ���: " << (double)divide(x, y) << endl;

	return 0;
}


// �ǽ�2 Ȧ¦ �Ǻ���
#include <iostream>
using namespace std;

void holjak(int num)
{
	if (num % 2 == 0)
	{
		cout << num << "��(��) ¦���Դϴ�." << endl;
	}
	else
	{
		cout << num << "��(��) Ȧ���Դϴ�." << endl;
	}
}

int main()
{
	int n;
	cout << "������ �Է��ϼ���: ";
	cin >> n;
	if (n % 2 == 0)
	{
		cout << n << "��(��) ¦���Դϴ�." << endl;
	}
	else
	{
		cout << n << "��(��) Ȧ���Դϴ�." << endl;
	}

	return 0;
}

// �ǽ� 3. �ִ� ã��
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
	cout << "�� ���� ������ �Է��ϼ���: ";
	cin >> num1 >> num2 >> num3;

	int maxNum = FindMax(num1, num2, num3);
	cout << "���� ū ����: " << maxNum << endl;

	return 0;
}




void recursivefunctuon(int n)
{
	if (n == 0) //�⺻ ���� (base, case)
	{
		return;
	}
	else
	{
		cout << n << " ";
		recursivefunctuon(n - 1);
	}
}


// �ǽ� 4. ���丮�� ����
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
	cout << "���� �Է�: ";
	cin >> num;

	cout << num << "! = " << fac(num) << endl;
	return 0;
}

// �ǽ� 5. �Ǻ���ġ ����
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
	cout << "�Ǻ���ġ ������ ���� �Է��ϼ���: ";
	cin >> n;
	cout << "�Ǻ���ġ ������ " << n << "��° ����: " << fibonacci(n) << endl;
	return 0;
}*/

// �ǽ� 6. �ŵ� ����	
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
	cout << "��(base)�� ����(exp)�� �Է��ϼ���: ";
	cin >> base >> exp;
	cout << base << "^" << exp << " = " << home(base, exp) << endl;
	return 0;
}


