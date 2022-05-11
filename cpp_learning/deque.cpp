// CPP Program to implement Deque in STL



#if 0
// deque的优点，可以很轻松的在array前面添加数据。比Vector快很多。
//  原因是deque double end queue 它是由很多一样长度的array首位链接在一块
#include <deque>
#include <iostream>
 
using namespace std;
 
void showdq(deque<int> g)
{
    // deque<int>::iterator it; 
    for (auto it = g.begin(); it != g.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}
 
int main()
{
    deque<int> gquiz = { 7, 7, 7};

    cout<<"大小是： "<<gquiz.size()<<endl;
    gquiz.push_back(10);  //放前，放后
    gquiz.push_front(20);   
    gquiz.push_back(30);
    gquiz.push_front(15);
    cout << "The deque gquiz is : ";
    showdq(gquiz);
 
    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.max_size() : " << gquiz.max_size();
 
    cout << "\ngquiz.at(2) : " << gquiz.at(2); // 取出第三个数据
    cout << "\ngquiz.front() : " << gquiz.front(); // 取出最前面或者最后面对数据
    cout << "\ngquiz.back() : " << gquiz.back();
 
    cout << "\ngquiz.pop_front() : ";
    gquiz.pop_front();  //把最前面的删除
    showdq(gquiz);
 
    cout << "\ngquiz.pop_back() : ";
    gquiz.pop_back();   //把最后面的删除
    showdq(gquiz);

    cout << "\ngquiz.clear() : ";
    gquiz.clear(); //   清空了这个gquiz
    showdq(gquiz);


 
    return 0;
}
#endif

#if 1

// deque 的删除和打印
#include <iostream>
#include <deque>

int main ()
{
  std::deque<int> mydeque;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) mydeque.push_back(i);

  // erase the 6th element
  mydeque.erase (mydeque.begin()+5);

  // erase the first 3 elements:
  mydeque.erase (mydeque.begin(),mydeque.begin()+3);

  std::cout << "mydeque contains:";
  for (std::deque<int>::iterator it = mydeque.begin(); it!=mydeque.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}

#endif