#include <iostream>
// #include <ros/ros.h>
#include <cmath>
#include <list>
using namespace std;

// 了解数据类型
#if 1
int main(int argc, char **argv){
    
    cout<<"数据类型是:  "<<typeid(coneTypes).name()<<endl;
    cout<<"数据类型是:  "<<typeid(cone).name()<<endl;
    return 0;
}
#endif



// list
#if 0
int main(int argc, char **argv){
    list<int> l1{5,1,3,4,5,6};
    std::list<int>::iterator iter;
    int sum = 0;
    for(iter = l1.begin();iter != l1.end();iter++) 
    { 
    sum = sum + *iter;
    
    } 
    cout<<sum;
    return 0;
}
#endif