#include <iostream>
using namespace std;

struct Tire
{
	string brand;
	int size;

	void display() 
    {
		cout << "타이어 브랜드는 " << brand << " 사이즈는 " << size << "이다" << endl;
	}
};

struct Car
{
	// 멤버 변수
	string brand;
	int speed;
	Tire tire;

	void accelerate() 
    {
		speed += 10;
	}

	void display() 
    {
		cout << "자동차 브랜드는 " << brand << "이고 속도는 " << speed << "km/h 이다." << endl;
		tire.display();
	}
};

struct Rectangle
{
	int width;
	int height;
};


struct Point
{
	// 멤버 변수
	int x;
	int y;

	// 멤버 함수
	void add(const Point p)
    {
		x += p.x;
		y += p.y;
	}
};

int main()
{
	Car myCar = { "tesla", 100, {"금호", 17}};

	cout << myCar.brand << endl;
	cout << myCar.tire.size << endl;

	myCar.display();
	myCar.accelerate();
	myCar.display();

	Car* ptr = &myCar;
	cout << "차량의 브랜드는 " << ptr->brand << endl;
	cout << "타이어의 브랜드는 " << ptr->tire.brand << endl;

#include <iostream>
#include <string>
using namespace std;

struct Rectangle
{
    int width;
    int height;

    int area()
    {
        return width * height;
    }
};

int main() 
{
    Rectangle rect;

    cout << "가로 길이 : ";
    cin >> rect.width;

    cout << "세로 길이 : ";
    cin >> rect.height;

    cout << "사각형의 넓이: " << rect.area() << endl;

    return 0;
}

// main안에서 직접 계산
#include <iostream>
using namespace std;

struct Rectangle
{
    int width;
    int height;
};

int main()
{
    Rectangle rect;

    cout << "가로 길이 : ";
    cin >> rect.width;

    cout << "세로 길이 : ";
    cin >> rect.height;

    int area = rect.width * rect.height;

    cout << "사각형의 넓이(width * height) : " << area << endl;

    return 0;
}




#include <iostream>
#include <string>
using namespace std;

struct Point 
{
    int x;
    int y;

    Point add(const Point& other) 
    {
        Point Result;
        Result.x = x + other.x;
        Result.y = y + other.y;
        return Result;
    }
};

int main() 
{
    Point p1, p2;

    cout << "첫 번째 x 좌표: ";
    cin >> p1.x;
    cout << "첫 번째 y 좌표: ";
    cin >> p1.y;

    cout << "두 번째 x 좌표: ";
    cin >> p2.x;
    cout << "두 번째 y 좌표: ";
    cin >> p2.y;

    Point sum = p1.add(p2);

    cout << "좌표 합 : (" << sum.x << ", " << sum.y << ")" << endl;

    return 0;
}
