#include <iostream>
#include <bitset>
#include <string>

using namespace std;

/*
int main()
{
    
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

    return 0;
}


    // 삼항 연산자
    int a = 10;
    int b = 20;

    int MaxValue = (a > b) ? a : b;
    cout << "MaxValue : " << MaxValue << endl;


    // switch문
    int day = 1;
    switch (day)
    {
        ease 1:
        cout << "월요일" << endl;
        break;
        ease 2:
        cout << "화요일" << endl;
        break;
        ease 3:
        cout << "수요일" << endl;
        break;
        ease 4:
        cout << "목요일" << endl;
        break;
    default:
        cout << "알수 없습니다." nedl;
        break;
    }
    

    // 실습 3번 삼항연산자
    int numbe = 0;
    cout << "숫자를 입력해주세요 : " << endl;
    cin >> numbe;

    int fivex = (numbe % 5 == 0) ? 1 : 0;
	if (fivex == 1)
    cout << numbe << "은 5의 배수입니다." << fivex << endl;

    else if (fivex == 0)
        cout << numbe << "은 5의 배수가 아닙니다." << endl;

    return 0;
    }

    // 실습 4번 switch문
       
    int x, y;
    cout << "연산할 정수 두 개를 입력해주세요. : " << endl;
    cin >> x >> y;

    char cal;
    cout << "연산자를 입력해주세요. : " << endl;
    cin >> cal;

    cout << " *** 연산결과 ---> ";

    switch (cal)
    {
    case '+':
        cout << x + y << endl;
    break;

    case '-':
        cout << x - y << endl;
    break;

    case '*':
    cout << x * y << endl;
    break;

    case '/':
        if (y == 0)
        cout << "0으로 나눌 수 없습니다." << endl;

    else
        cout << x / y << endl;
    break;

    default:
    cout << "연산자를 잘못 입력하셨습니다." << endl;
    break;
}

return 0;  // 프로그램 종료
}
*/

// 반복문
//  for (초기화; 조건식; 증감식){
//  // 반복할 코드
//  }

int main()
{
    for (int i = 0; i < 5; i++)
    {
        cout << i << endl;
    }

    int j = 0;
    for (; j < 10; j++)
    {
        cout << j << endl;
        j++;
    }
}

// whil (조건식) {
// 조건이 참인 동안 반복 실행
// }

int count = 1;
while (count < 5)
{
    cout << "count : " << count << endl;
    count++;
}
cout << "현재 count: " << count << endl;
do
{
    cout << "돌아가나유? " << endl; // do while은 조건이 참이든 거짓이든 무조건 한번은 실행됨.
} while (count < 5);
}

//실습 1 입력한 숫자만큼 별 찍기
// *찍기 왼쪽정렬
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++) cout << "*";
        cout << "\n";
    }
}

// 추가 실습
// *찍기 오른정렬
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j > i; j--) cout << " ";
        for (int k = 0; k < i; k++) cout << "*";
        cout << "\n";
    }
}

// 구구단 출력

for (int i = 1; i <= 9; i++)
{
    cout << "====" << i << "단====" << endl;
    for (int j = 1; j < 10; j++))
    {
        cout << i << " x " << j << " = " << i * j << endl;
    }

    // 실습 3 1부터 n까지의 합 구하기
    int m
        int sum = 0;
    cout << "1부터 n까지의 합 구하기" << endl;
    cout << "1부터 n까지의 합을 구할 n을 입력하세요 : ";
    cin >> m;

    int k = 1
        while (k <= m)
        {
            sum += k;
            k++;
        }

    cout << "1부터" << m << "까지의 합은 : " << sum << endl;

    /*
    * for 문으로 짠다면
    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }
    */

    // 실습 4. 사용자가 입력한 숫자 더하기
    int input_num;

    cout << "사용자가 입력한 숫자 더하기" << endl;
    cout << endl;

    int totl = 0;
    while (true) {
        cout << "숫자를 입력하세요( 0입력시 끝) : ";
        cin >> input_num;

        if (input_num == 0)
        {
            break;
        }
        total += input_num;
    }
    cout << "사용자가 입력한 수의 합은 : " << total << endl;
}
  
//배열
int arr[3] = { 1, 2, 3 };

for (int i = 0; i < 3; i++)
{
	cout << "arr[" << i << "] : " << arr[i] << endl;
}

for (int num : arr) 
{
	cout << "num : " << num << endl;

    // 자동 배열의 크기
    int arr1[] = { 10,20,30,40,50 };
	for (int i = 0; i < 6; i++)
	{
		cout << "arr1[" << i << "] : " << arr1[i] << endl;
	}
    for (int num1 : arr1)
    {
		cout << "num1 : " << num1 << endl;
}


    // 2차원 배열
    string matrix[2][2] = { {"apple", "banana"}, {"orange", "strawberry"} };

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << "matrix[" << i << "][" << j << "] : " << matrix[i][j] << endl;
		}
	}