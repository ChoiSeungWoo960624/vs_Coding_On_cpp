/*#include <iostream>
using namespace std;

template <typename T1, typename T2>

T add(T1 a, T2 b)
{
	cout << "템플릿 함수" << endl;
	return a + b;
}

double add(int am double b)
{
	cout << "일반함수" << endl;
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


//실습 1. 두개의 값을 저장하는 클래스 구현
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
    unique_ptr<int> ptr = make_unique<int>(10); // 동적 메모리로 생성
        cout << *ptr << endl; // 10출력
    return 0; // 자동으로 메모리 해제됨
}

// unique_ptr : 객체 생성
class Test
{
public:
    Test() { cout << "Test 생성\n"; }
    ~Test() { cout << "Test 소멸\n"; }
};

int main()
{
    unique_ptr<Test> ptr1 = make_unique<Test>();
    // 객체 생성 및 소유권 획득
    unique_ptr<Test> ptr2 = move(ptr1); // 소유권 이전

    if (!ptr1)
    {
        cout << "ptr1은 더 이상 객체를 소유하지 않습니다. \n";
    }

    return 0; // ptr2가 소멸하면서 객체도 자동 해제됨
}

// unique_ptr: 함수 반환값
class Test
{
public:
    Test() { cout << "Test 생성\n"; }
    ~Test() { cout << "Test 소멸\n"; }
};
// 함수에서 'unique_ptr'을 반환 (소유권 이동)
unique_ptr<Test> createTest()
{
    return make_unique<Test>();
}

int main()
{
    unique_ptr<Test> ptr = createTest(); 
    //반환된 'unique_ptr'의 소유권을 받음
    
    return 0; // ptr이 스코프를 벗어나면서 자동 소멸됨
}

//일반적인 업캐스팅

class Base
{
public:
    virtual void show() { cout << "Base 클래스\n "; }
};

class Derived : public Base {
public:
    void show() override { cout << "Derived 클래스\n"; }
    };

int main()
{
    Derived d;
    Base* basePtr = &d; //업캐스팅 (자동 변환)
    basePtr->show(); // "Derivd 클래스" 출력 (다형성 적용)
    return 0;
}


//일반적인 다운캐스팅(c스타일)

int main()
{
    Base* basePtr = new Derived(); // 업캐스팅
    Derived* derivePtr = (Derived*)basePtr; // 다운 캐스팅

    derivedPtr->show(); //"Derived 클래스" 출력 (정상 동작)

    delete basePtr; //메모리 해제
    return 0;
}

//일반적인 다운캐스팅(C++스타일)

int main()
{
    Base* basePtr = new Derived(); // 업캐스팅
    Derived* derivePtr = dynamic_cast(Derived*)(basePtr); // 다운 캐스팅

    if (derivedPtr)
    {
        derivedPtr->show(); //"Derived 클래스" 출력
    }
    else
    {
        cout << "다운 캐스팅 실패\n";
    }

    delete basePtr; //메모리 해제
    return 0;
}

//스마트 포인터로 업캐스팅

int main()
{
    shared_ptr<Derived> derived = make_shared<Derived>(); //스마트 포인터 생성
    shared_ptr<Base> base = derived; // 업캐스팅 (자동 변환)

    base->show(); // "Derived 클래스" 출력

    return 0; // 메모리 자동 해제됨
}

// 스마트 포인터로 다운캐스팅
int main()
{
    shared_ptr<Base> base = make_shared<Derived>(); // 업캐스팅
    shared_ptr<Derived> derived = dynamic_pointr_cast<Derived>(base); //다운 캐스팅
  
    if (derived)
    {
        base->show(); // "Derived 클래스" 출력
    }
    else {
        cout << "다운캐스팅 실패\n";
    }
    return 0; // 스마트 포인터가 자동으로  메모리 해제됨
}