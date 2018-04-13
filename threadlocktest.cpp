#include "threadlocktest.h"
#include <stdio.h>
#include <thread>
#include <mutex>
 int sum=0;

std::mutex g_mutex;
void *threadDo1()
{
    for(int i=0;i<1000;i++) {
        //std::lock_guard<std::mutex> lock(g_mutex); 此处的锁
        if(sum>=1000)
            break;
        sum++;
        printf("%d:%d_\n" ,std::this_thread::get_id(),sum);

    }
}

void ThreadLockTest(){

    std::thread t1(threadDo1);
    std::thread t2(threadDo1);
    t1.join();
    t2.join();

}

