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
        cout << "����Դϴ�." << endl;
    }
    // -10�� �ְԵǸ� �ƹ��͵� ������ ����.

    else if (num < 0)
    {
        cout << "�����Դϴ�." << endl;
    }
    else
    {
        cout << "0�Դϴ�." << endl;
    }

    return 0;
}


    // ���� ������
    int a = 10;
    int b = 20;

    int MaxValue = (a > b) ? a : b;
    cout << "MaxValue : " << MaxValue << endl;


    // switch��
    int day = 1;
    switch (day)
    {
        ease 1:
        cout << "������" << endl;
        break;
        ease 2:
        cout << "ȭ����" << endl;
        break;
        ease 3:
        cout << "������" << endl;
        break;
        ease 4:
        cout << "�����" << endl;
        break;
    default:
        cout << "�˼� �����ϴ�." nedl;
        break;
    }
    

    // �ǽ� 3�� ���׿�����
    int numbe = 0;
    cout << "���ڸ� �Է����ּ��� : " << endl;
    cin >> numbe;

    int fivex = (numbe % 5 == 0) ? 1 : 0;
	if (fivex == 1)
    cout << numbe << "�� 5�� ����Դϴ�." << fivex << endl;

    else if (fivex == 0)
        cout << numbe << "�� 5�� ����� �ƴմϴ�." << endl;

    return 0;
    }

    // �ǽ� 4�� switch��
       
    int x, y;
    cout << "������ ���� �� ���� �Է����ּ���. : " << endl;
    cin >> x >> y;

    char cal;
    cout << "�����ڸ� �Է����ּ���. : " << endl;
    cin >> cal;

    cout << " *** ������ ---> ";

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
        cout << "0���� ���� �� �����ϴ�." << endl;

    else
        cout << x / y << endl;
    break;

    default:
    cout << "�����ڸ� �߸� �Է��ϼ̽��ϴ�." << endl;
    break;
}

return 0;  // ���α׷� ����
}
*/

// �ݺ���
//  for (�ʱ�ȭ; ���ǽ�; ������){
//  // �ݺ��� �ڵ�
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

// whil (���ǽ�) {
// ������ ���� ���� �ݺ� ����
// }

int count = 1;
while (count < 5)
{
    cout << "count : " << count << endl;
    count++;
}
cout << "���� count: " << count << endl;
do
{
    cout << "���ư�����? " << endl; // do while�� ������ ���̵� �����̵� ������ �ѹ��� �����.
} while (count < 5);
}

//�ǽ� 1 �Է��� ���ڸ�ŭ �� ���
// *��� ��������
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

// �߰� �ǽ�
// *��� ��������
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

// ������ ���

for (int i = 1; i <= 9; i++)
{
    cout << "====" << i << "��====" << endl;
    for (int j = 1; j < 10; j++))
    {
        cout << i << " x " << j << " = " << i * j << endl;
    }

    // �ǽ� 3 1���� n������ �� ���ϱ�
    int m
        int sum = 0;
    cout << "1���� n������ �� ���ϱ�" << endl;
    cout << "1���� n������ ���� ���� n�� �Է��ϼ��� : ";
    cin >> m;

    int k = 1
        while (k <= m)
        {
            sum += k;
            k++;
        }

    cout << "1����" << m << "������ ���� : " << sum << endl;

    /*
    * for ������ §�ٸ�
    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }
    */

    // �ǽ� 4. ����ڰ� �Է��� ���� ���ϱ�
    int input_num;

    cout << "����ڰ� �Է��� ���� ���ϱ�" << endl;
    cout << endl;

    int totl = 0;
    while (true) {
        cout << "���ڸ� �Է��ϼ���( 0�Է½� ��) : ";
        cin >> input_num;

        if (input_num == 0)
        {
            break;
        }
        total += input_num;
    }
    cout << "����ڰ� �Է��� ���� ���� : " << total << endl;
}
  
//�迭
int arr[3] = { 1, 2, 3 };

for (int i = 0; i < 3; i++)
{
	cout << "arr[" << i << "] : " << arr[i] << endl;
}

for (int num : arr) 
{
	cout << "num : " << num << endl;

    // �ڵ� �迭�� ũ��
    int arr1[] = { 10,20,30,40,50 };
	for (int i = 0; i < 6; i++)
	{
		cout << "arr1[" << i << "] : " << arr1[i] << endl;
	}
    for (int num1 : arr1)
    {
		cout << "num1 : " << num1 << endl;
}


    // 2���� �迭
    string matrix[2][2] = { {"apple", "banana"}, {"orange", "strawberry"} };

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << "matrix[" << i << "][" << j << "] : " << matrix[i][j] << endl;
		}
	}