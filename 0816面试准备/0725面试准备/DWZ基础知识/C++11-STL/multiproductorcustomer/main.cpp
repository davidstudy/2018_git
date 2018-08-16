/*
#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;

mutex mux;
static int x = 0;
condition_variable con_var;

void producer()
{
    lock_guard<mutex> locker(mux);
    if(x < 10)
    {
        x++;
    }
    else
    {
        con_var.notify_all();
    }
}

void comsumer()
{
    lock_guard<mutex> locker(mux);
    if(x < 10)
        con_var.wait(mux);
    else
        x--;
}

void f1()
{
    producer();
    cout <<"x=" << x <<endl;
    comsumer();
}

int main()
{
    thread t1(f1);
    t1.join();
    return 0;
}
*/


/*

#include<iostream>
#include<condition_variable>
#include<vector>
#include<thread>

std::vector<std::thread> tv;         //保存线程的情况
std::condition_variable_any m_t;     //条件变量
std::mutex lock;                     //互斥锁
int i = 1;                           //打印机资源 初始为1 表示可用

void subi() {
    std::lock_guard<std::mutex> locker(lock);  //使用之前先加锁
    while(i == 0){             //如果不可用
        m_t.wait(lock);        //将当前线程阻塞，注意：此时会释放锁
    }

    i--;                       //使用打印机过程
}

void addi() {
    std::lock_guard<std::mutex> locker(lock); //同理，放弃使用的时候先加锁

    i++;                       //是资源变为可用
    m_t.notify_all();          //通知其余阻塞的使用者可以使用了
}

void func(int j) {
    subi();
    std::cout << "I am thread "<< j << " , i = " << i << std::endl;
    addi();
}


int main(int argc,char *argv[])
{
    for(int j = 0; j < 10 ; ++j) {
        std::thread t(func,j);
        tv.push_back(std::move(t));
    }

    for(auto &thread : tv) {
        thread.join();
    }
    return 0;
}
*/

#include <unistd.h>

#include <cstdlib>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

static const int kItemRepositorySize  = 4; // Item buffer size.
static const int kItemsToProduce  = 10;   // How many items we plan to produce.

struct ItemRepository {
    int item_buffer[kItemRepositorySize];
    size_t read_position;
    size_t write_position;
    size_t produced_item_counter;
    size_t consumed_item_counter;
    std::mutex mtx;
    std::mutex produced_item_counter_mtx;
    std::mutex consumed_item_counter_mtx;
    std::condition_variable repo_not_full;
    std::condition_variable repo_not_empty;
} gItemRepository;

typedef struct ItemRepository ItemRepository;


void ProduceItem(ItemRepository *ir, int item)
{
    std::unique_lock<std::mutex> lock(ir->mtx);
    while(((ir->write_position + 1) % kItemRepositorySize)
        == ir->read_position) { // item buffer is full, just wait here.
        std::cout << "Producer is waiting for an empty slot...\n";
        (ir->repo_not_full).wait(lock);
    }

    (ir->item_buffer)[ir->write_position] = item;
    (ir->write_position)++;

    if (ir->write_position == kItemRepositorySize)
        ir->write_position = 0;

    (ir->repo_not_empty).notify_all();
    lock.unlock();
}

int ConsumeItem(ItemRepository *ir)
{
    int data;
    std::unique_lock<std::mutex> lock(ir->mtx);
    // item buffer is empty, just wait here.
    while(ir->write_position == ir->read_position) {
        std::cout << "Consumer is waiting for items...\n";
        (ir->repo_not_empty).wait(lock);
    }

    data = (ir->item_buffer)[ir->read_position];
    (ir->read_position)++;

    if (ir->read_position >= kItemRepositorySize)
        ir->read_position = 0;

    (ir->repo_not_full).notify_all();
    lock.unlock();

    return data;
}

void ProducerTask()
{
    bool ready_to_exit = false;
    while(1) {
      //  sleep(1);
        std::unique_lock<std::mutex> lock(gItemRepository.produced_item_counter_mtx);
        if (gItemRepository.produced_item_counter < kItemsToProduce) {
            ++(gItemRepository.produced_item_counter);
            ProduceItem(&gItemRepository, gItemRepository.produced_item_counter);
            std::cout << "Producer thread " << std::this_thread::get_id()
                << " is producing the " << gItemRepository.produced_item_counter
                << "^th item" << std::endl;
        } else ready_to_exit = true;
        lock.unlock();
        if (ready_to_exit == true) break;
    }
    std::cout << "Producer thread " << std::this_thread::get_id()
                << " is exiting..." << std::endl;
}

void ConsumerTask()
{
    bool ready_to_exit = false;
    while(1) {
      //  sleep(1);
        std::unique_lock<std::mutex> lock(gItemRepository.consumed_item_counter_mtx);
        if (gItemRepository.consumed_item_counter < kItemsToProduce) {
            int item = ConsumeItem(&gItemRepository);
            ++(gItemRepository.consumed_item_counter);
            std::cout << "Consumer thread " << std::this_thread::get_id()
                << " is consuming the " << item << "^th item" << std::endl;
        } else ready_to_exit = true;
        lock.unlock();
        if (ready_to_exit == true) break;
    }
    std::cout << "Consumer thread " << std::this_thread::get_id()
                << " is exiting..." << std::endl;
}

void InitItemRepository(ItemRepository *ir)
{
    ir->write_position = 0;
    ir->read_position = 0;
    ir->produced_item_counter = 0;
    ir->consumed_item_counter = 0;
}

int main()
{
    InitItemRepository(&gItemRepository);
    std::thread producer1(ProducerTask);
    std::thread producer2(ProducerTask);
    std::thread producer3(ProducerTask);
    std::thread producer4(ProducerTask);

    std::thread consumer1(ConsumerTask);
    std::thread consumer2(ConsumerTask);
    std::thread consumer3(ConsumerTask);
    std::thread consumer4(ConsumerTask);

    producer1.join();
    producer2.join();
    producer3.join();
    producer4.join();

    consumer1.join();
    consumer2.join();
    consumer3.join();
    consumer4.join();
}
