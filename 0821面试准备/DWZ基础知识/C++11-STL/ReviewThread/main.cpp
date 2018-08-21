#include <iostream>
#include <deque>
#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;

mutex mux;
deque<int> deq;
condition_variable conv;

void producer()
{
    int cnt = 10;
    while(cnt>0)
    {
        unique_lock<mutex> loc(mux);
        deq.push_front(cnt);
        loc.unlock();
        conv.notify_one();
        cnt--;
    }
}

void comsumer()
{
    int k ;
    while( k!= 1)
    {
        unique_lock<mutex> loc(mux);
        conv.wait(loc,[]()
        {
            return !deq.empty();
        });
        k = deq.back();
        deq.pop_back();
        loc.unlock();
        cout << k <<endl;
    }
}

int main()
{
    thread t1(producer);
    thread t2(comsumer);
    t1.join();
    t2.join();
    return 0;
}
