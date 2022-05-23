#include <iostream>
using namespace std;
/*
    传统的指针的问题在于：
    我们一直在创建本地指针，但是我们忘记了deallocate p
    这样的话内存会被不断占用    memory leak
     Languages Java, C# has Garbage Collection Mechanisms to smartly deallocate unused memory to be used again.
     C++11 之后也引入了Smarter Pointer的机制来解决这个问题。 它会自动帮我们销毁占用的内存
*/

#if 0

/*
    传统的指针的问题演示：
  */
class Rectangle {
private:
    int length;
    int breadth;
};
 
void fun()
{
    // By taking a pointer p and
    // dynamically creating object
    // of class rectangle
    Rectangle* p = new Rectangle();
}
 
int main()
{
    // Infinite Loop
    while (1) {
        fun();
    }
}
#endif

#if 1

/*
    xxx
*/
class SmartPtr {
    int* ptr; // Actual pointer
public:
    // Constructor: Refer https:// www.geeksforgeeks.org/g-fact-93/
    // for use of explicit keyword
    explicit SmartPtr(int* p = NULL) { ptr = p; } // 明确的构造类型，而不是隐含的。说明我们必须按照规定来定义实例
 
    // Destructor
    ~SmartPtr() { delete (ptr); }
 
    // Overloading dereferencing operator
    int& operator*() { return *ptr; }
};
 
int main()
{
    SmartPtr ptr(new int());
    *ptr = 20;
    cout << *ptr;
 
    // We don't need to call delete ptr: when the object
    // ptr goes out of scope, the destructor for it is automatically
    // called and destructor does delete ptr.
 
    return 0;
}
#endif
#if 0

/*
    xxx
*/
int main()
{



    cout<<"velue is"<<""<<endl;
}
#endif

#if 0

/*
    xxx
*/
int main()
{



    cout<<"velue is"<<""<<endl;
}
#endif

#if 0

/*
    xxx
*/
int main()
{



    cout<<"velue is"<<""<<endl;
}
#endif

#if 0

/*
    xxx
*/
int main()
{



    cout<<"velue is"<<""<<endl;
}
#endif

#if 0

/*
    xxx
*/
int main()
{



    cout<<"velue is"<<""<<endl;
}
#endif
