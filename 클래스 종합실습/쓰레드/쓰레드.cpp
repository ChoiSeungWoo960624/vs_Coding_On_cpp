#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>

using namespace std;

atomic<int> counter = 0;  // 원자적 연산을 위한 atomic 변수 사용

mutex mtx;  // 뮤텍스 객체

void increment() {
    for (int i = 0; i < 100000000; ++i) {
		mtx.lock();  // 뮤텍스 잠금
        lock_guard<mutex> lock(mtx);
        ++counter;  // 원자적으로 증가
		mtx.unlock();  // 뮤텍스 해제
    }
}

int main()
{
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();

    cout << "Counter: " << counter << endl;
}