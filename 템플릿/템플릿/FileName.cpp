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
*/

#include <iostream>
#include <memory>
using namespace std;

int main()
{
    unique_ptr<int> ptr = make_unique<int>(10); // ���� �޸𸮷� ����
        cout << *ptr << endl; // 10���
    return 0; // �ڵ����� �޸� ������
}

// unique_ptr : ��ü ����
class Test
{
public:
    Test() { cout << "Test ����\n"; }
    ~Test() { cout << "Test �Ҹ�\n"; }
};

int main()
{
    unique_ptr<Test> ptr1 = make_unique<Test>();
    // ��ü ���� �� ������ ȹ��
    unique_ptr<Test> ptr2 = move(ptr1); // ������ ����

    if (!ptr1)
    {
        cout << "ptr1�� �� �̻� ��ü�� �������� �ʽ��ϴ�. \n";
    }

    return 0; // ptr2�� �Ҹ��ϸ鼭 ��ü�� �ڵ� ������
}

// unique_ptr: �Լ� ��ȯ��
class Test
{
public:
    Test() { cout << "Test ����\n"; }
    ~Test() { cout << "Test �Ҹ�\n"; }
};
// �Լ����� 'unique_ptr'�� ��ȯ (������ �̵�)
unique_ptr<Test> createTest()
{
    return make_unique<Test>();
}

int main()
{
    unique_ptr<Test> ptr = createTest(); 
    //��ȯ�� 'unique_ptr'�� �������� ����
    
    return 0; // ptr�� �������� ����鼭 �ڵ� �Ҹ��
}

//�Ϲ����� ��ĳ����

class Base
{
public:
    virtual void show() { cout << "Base Ŭ����\n "; }
};

class Derived : public Base {
public:
    void show() override { cout << "Derived Ŭ����\n"; }
    };

int main()
{
    Derived d;
    Base* basePtr = &d; //��ĳ���� (�ڵ� ��ȯ)
    basePtr->show(); // "Derivd Ŭ����" ��� (������ ����)
    return 0;
}


//�Ϲ����� �ٿ�ĳ����(c��Ÿ��)

int main()
{
    Base* basePtr = new Derived(); // ��ĳ����
    Derived* derivePtr = (Derived*)basePtr; // �ٿ� ĳ����

    derivedPtr->show(); //"Derived Ŭ����" ��� (���� ����)

    delete basePtr; //�޸� ����
    return 0;
}

//�Ϲ����� �ٿ�ĳ����(C++��Ÿ��)

int main()
{
    Base* basePtr = new Derived(); // ��ĳ����
    Derived* derivePtr = dynamic_cast(Derived*)(basePtr); // �ٿ� ĳ����

    if (derivedPtr)
    {
        derivedPtr->show(); //"Derived Ŭ����" ���
    }
    else
    {
        cout << "�ٿ� ĳ���� ����\n";
    }

    delete basePtr; //�޸� ����
    return 0;
}

//����Ʈ �����ͷ� ��ĳ����

int main()
{
    shared_ptr<Derived> derived = make_shared<Derived>(); //����Ʈ ������ ����
    shared_ptr<Base> base = derived; // ��ĳ���� (�ڵ� ��ȯ)

    base->show(); // "Derived Ŭ����" ���

    return 0; // �޸� �ڵ� ������
}

// ����Ʈ �����ͷ� �ٿ�ĳ����
int main()
{
    shared_ptr<Base> base = make_shared<Derived>(); // ��ĳ����
    shared_ptr<Derived> derived = dynamic_pointr_cast<Derived>(base); //�ٿ� ĳ����
  
    if (derived)
    {
        base->show(); // "Derived Ŭ����" ���
    }
    else {
        cout << "�ٿ�ĳ���� ����\n";
    }
    return 0; // ����Ʈ �����Ͱ� �ڵ�����  �޸� ������
}