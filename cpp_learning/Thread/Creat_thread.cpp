/*
    how to creat the thread!
    for Linux the command is:
        g++ -pthread Creat_thread.cpp -o runable_name;  

*/
#include <iostream>
#include <thread>
// #include <chrono>

using namespace std;

#if 1

/*
    creat a thread to run a funciton
    the problem is Race condition
*/
void func(int a ){
    // while(true){
        cout<<"Hello World"<<endl;
        std::this_thread::sleep_for(std::chrono::microseconds(50));
    // }
    // std::this_thread::get_id()
    // this_thread is the operation for the thread inside
}

int main()
{
    int a =10;
    std::thread thread1(func, a);  // creat and run the thread 
    // thread1.join(); // run this thread , and going on until it returns
    thread1.detach(); // seperate the two threads
    // thread1.get_id(); // get the thread ID eg. 19336

    cout<<"thread id is :"<<thread1.get_id()<<endl;
    cout<<"thread maximun allowed thread :"<<thread1.hardware_concurrency()<<endl; // for my onenote the hardware support 4 thread. this number is for reference only


    // while(true){
        cout<<"main is running "<<""<<endl;
        std::this_thread::sleep_for(std::chrono::microseconds(50));
    // }

}
#endif

