#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;

void func(const char *name, int id)
{
    
    int cnt = 5;
    while (cnt--)
    {
        mtx.lock();
        cout << "Thread " << name << "id# " << id << " is running" << endl;
        mtx.unlock();
    }

}

int main()
{
    auto n = thread::hardware_concurrency();
    cout << n << endl;

    thread t1(func, "SPU", 0);
    thread t2(func, "QTU", 1);

    t1.join();
    t2.join();

    return 0;
}