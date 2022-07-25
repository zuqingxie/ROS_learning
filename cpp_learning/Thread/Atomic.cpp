/*
    thread learning
    for Linux the command is:
        g++ -pthread Creat_thread.cpp -o runable_name;  

*/
#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

#if 1

/*
    Race condition
    solution: Mutex lock and unlock
    another solution: atomic


*/


// int globalnumber =0;
std::atomic_int globalnumber(0);

void func(){
    
    for(int i = 0; i<1000000; i++){
        globalnumber++;
        globalnumber--;
    }

}

int main()
{
    int a = 0;
    std::thread thread1(func);  
    std::thread thread2(func); // 在这边的时候已经运行线程了，不是到之后detach或者join的时候才运行的。。。  
    thread1.detach(); // 这个会缓解一些race condition 但是还是会存在问题，最好的就是用线程🔓
    thread2.detach(); 

    std::this_thread::sleep_for(std::chrono::microseconds(5000));

    cout<<"finally global number is :"<<globalnumber<<endl;

}
#endif

