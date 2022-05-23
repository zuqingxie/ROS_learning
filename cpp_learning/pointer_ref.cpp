#include <iostream>
using namespace std;

/*
    基础操作
*/ 
#if 0
using namespace std;
int main()
{

    int a = 5;
    int *p; // 定一个指针变量
    p =  &a; // &a get the address of the a
    cout<<"address of a is"<<p<<endl;

}
#endif

/*

*/
#if 1
int main()
{

    int a = 5;
    int b = 5;
    int* q = &a; // 获取a的地址
    int& p = a; // 引用变量=真的变量。就是取别名！！！！！ p 和 a 已经没有区别了。使用这个可以达到一些优化效果
    // int &p = b; // 只能赋值一次。外号总不能是指两个人吧
    cout<<"address of a is"<<q<<endl;
    cout<<"address of a is"<<&p<<endl; 
    cout<<"value of a is"<<*q<<endl; // 解指针 
    cout<<"value of a is"<<p<<endl;
    cout<<"address of the pointer"<<&q<<endl; //不一样哦，这个是指针变量的地址
    // cout<<"address of the pointer"<<*p<<endl; //没有这种表达。p 和a一样都不是指针，所以不能解指针


}
#endif

#if 0
int main()
{

    int a = 5;
    int *p; // 定一个指针变量
    p =  &a; // &a get the address of the a
    cout<<"address of a is"不一样哦，这个是指针变量的地址
<<p<<endl;

}
#endif

#if 0
int main()
{

    int a = 5;
    int *p; // 定一个指针变量
    p =  &a; // &a get the address of the a
    cout<<"address of a is"<<p<<endl;

}
#endif

#if 0
int main()
{

    int a = 5;
    int *p; // 定一个指针变量
    p =  &a; // &a get the address of the a
    cout<<"address of a is"<<p<<endl;

}
#endif

#if 0
int main()
{

    int a = 5;
    int *p; // 定一个指针变量
    p =  &a; // &a get the address of the a
    cout<<"address of a is"<<p<<endl;

}
#endif

#if 0
int main()
{

    int a = 5;
    int *p; // 定一个指针变量
    p =  &a; // &a get the address of the a
    cout<<"address of a is"<<p<<endl;

}
#endif

#if 0
#endif

#if 0
#endif

#if 0
#endif

#if 0
#endif

#if 0
#endif
