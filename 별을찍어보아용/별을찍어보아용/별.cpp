/*
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
// 5을 설정하고 cout 했을 때
5
*
**
***
****
*****
*/

/*
// 오른쪽 별찍기
#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = n ; j > i ; j --) cout<<" ";
		for(int k =0 ; k < i ; k ++) cout<<"*";
		cout<<"\n";
	}
}

// 5을 설정하고 cout 했을 때
5
*
**
***
****
*****
*/


/*
 // 마른모
#include <iostream>
using namespace std;

int main() 
{
	int N;
	cin >> N;
	N = N * 2 - 1;
	int o = N / 2;

	for (int i = -o; i <= o; i++) 
	{
		int k = 0;
		for (int j = 0; j < N - abs(i); j++) 
		{
			cout << (k < abs(i) ? " " : "*");
			k++;
		}
		cout << "\n";
	}

	return 0;
}
	8
       *
      ***
     *****
    *******
   *********
  ***********
 *************
***************
 *************
  ***********
   *********
    *******
     *****
      ***
       *
*/