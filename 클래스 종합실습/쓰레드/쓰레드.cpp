#include <iostream>
#include <thread>
#include <atomic>
#include <mutex>

using namespace std;

atomic<int> counter = 0;  // ������ ������ ���� atomic ���� ���

mutex mtx;  // ���ؽ� ��ü

void increment() {
    for (int i = 0; i < 100000000; ++i) {
		mtx.lock();  // ���ؽ� ���
        lock_guard<mutex> lock(mtx);
        ++counter;  // ���������� ����
		mtx.unlock();  // ���ؽ� ����
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