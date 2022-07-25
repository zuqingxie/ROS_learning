/*
    thread learning
    for Linux the command is:
        g++ -pthread Creat_thread.cpp -o runable_name;  

*/
#include <iostream>
#include <thread>
#include <mutex> // 互斥量

using namespace std;

#if 1

/*
    Race condition
    solution: Mutex lock and unlock
    problem:
        1: dead lock
            程序在锁上之后就return或者崩溃了，没有执行到unlock
        solution：
            lock_guard （RAII resource Acquisition is initialization）
        2：上所顺序的不同也会导致死锁的可能
        solution:
            1.多个🔓的时候一定要保证🔓的顺序
            2. std::lock(mtx1,mtx2);

*/

std::mutex mtx1;
std::mutex mtx2;
int globalnumber =0;
void func(){
    for(int i = 0; i<1000000; i++){
        // std::lock_guard<std::mutex> lock(mtx1); // 相当于 mtx.lock()和mtx.unlock()， mtx.unlock() 在兮沟函数被调用，解决了死锁的问题
        // std::lock_guard<std::mutex> lock(mtx2);
        // std::lock(mtx1,mtx2);
        // mtx.lock();
        std::unique_lock<std::mutex> lock(mtx1); // 这个比lock_guard更加灵活     

        globalnumber++;
        globalnumber--;
        // mtx.unlock();

}
}

int main()
{
    int a = 0;
    std::thread thread1(func);  
    std::thread thread2(func); // 在这边的时候已经运行线程了，不是到之后detach或者join的时候才运行的。。。  
    thread1.detach(); // 这个会缓解一些race condition 但是还是会存在问题，最好的就是用线程🔓
    thread2.detach(); 

    cout<<"finally global number is :"<<globalnumber<<endl;


    // // while(true){
    //     cout<<"main is running "<<""<<endl;
    // // }

}
#endif

