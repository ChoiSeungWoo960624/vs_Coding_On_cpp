#include <iostream>
#include <vector>
#include <list>
using namespace std;

void listShow(list<int> list1) {

    // 반복자 (iterator)
    for (list<int>::iterator it = list1.begin(); it != list1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
	list<int> mylist = { 10, 20, 30, 40, 50 };

	// for - each 문법
	for (int num : mylist) 
	{
		cout << num << endl;
	}

//실습 list사용해보기
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main() 
{
    list<int> List = { 5, 4, 3, 4, 2, 1, 1 };

    int count4 = count(List.begin(), List.end(), 4);
    cout << "4의 개수: " << count4 << endl;

    List.sort();
    cout << "정렬 후 리스트: ";
    for (int n : List) cout << n << " ";
    cout << endl;

    List.unique();
    cout << "중복 제거 후 리스트: ";
    for (int n : List) cout << n << " ";
    cout << endl;

    List.push_back(6);
    List.push_back(7);
    cout << "6, 7 추가 후 리스트: ";
    for (int n : List) cout << n << " ";
    cout << endl;

    List.push_front(0);
    cout << "0 추가 후 리스트: ";
    for (int n : List) cout << n << " ";
    cout << endl;

    return 0;
}