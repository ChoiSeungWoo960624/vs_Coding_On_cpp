#include <iostream>
#include <vector>
#include <list>
using namespace std;


int main()
{
	list<int> mylist = { 10, 20, 30, 40, 50 };

	for (int num : mylist)
	{
		cout << num << endl;
	}

	// ¹İº¹ÀÚ (iterator)
	for (list<int>::iterator it = mylist.begin(); it != mylist.end(); ++it)
		cout << *it << " ";









}
