/*#include <iostream>
using namespace std;

template <typename T1, typename T2>

T add(T1 a, T2 b)
{
	cout << "���ø� �Լ�" << endl;
	return a + b;
}

double add(int am double b)
{
	cout << "�Ϲ��Լ�" << endl;
	return a + b;
}
int main()
{
	cout << add(2, 3.1) << endl;
}

template <typename T>

class Box
{
private:
	T data;
	
};
*/

//�ǽ� 1. �ΰ��� ���� �����ϴ� Ŭ���� ����
#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
class Pair 
{
private:
    T1 first;
    T2 second;

public:
    Pair(T1 f, T2 s) : first(f), second(s) {}

    void show() const 
    {
        cout << "First: " << first << ", Second: " << second << endl;
    }

    T1 getFirst() const 
    {
        return first;
    }

    T2 getSecond() const 
    {
        return second;
    }

    void setFirst(const T1& f) 
    {
        first = f;
    }

    void setSecond(const T2& s) 
    {
        second = s;
    }
};

int main() 
{
    Pair<int, string> p(250415, "coding");
    p.show();

    cout << "First: " << p.getFirst() << endl;
    cout << "Second: " << p.getSecond() << endl;

    p.setFirst(1514);
    p.setSecond("on");
    p.show();

    return 0;
}

