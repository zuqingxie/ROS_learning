/*
  * 各种的const的
  * 函数定义的时候
  * 变量定义的时候。
  * 变量前后的区别
*/
#include <iostream>
using namespace std;

#if 1

/*
    xxx
*/
class Entity {
private:
	int m_X, m_Y;
	mutable int var; // can be modified inside const menthods
	int* m_x, *m_y;// * use to create pointer in one line
public:
    mutable int m_X_1;
	int GetX() const //不能修改所有的成员变量，无论是在private还是public里面。除非是由mutable（可变的）定义的
	{
		// m_X = 4;//error private member can't be modified inside const method
        m_X_1 = 10;
		var = 5; // was set mutable
		return m_X;
	}
	int Get_X()// will modify class 
	{
		return m_X;
	}
	const int* const getX() const  // returning a pointer that cannot be modified & context of pointer cannot be modified
	{
		//m_x = 4;
		return m_x;
	}
	void PrintEntity(const Entity& e) {
		std::cout << e.GetX() << std::endl;
	}
};
int main() {
	Entity e;
	const int MAX_AGE = 90;
   // MAX_AGE =100; error const var is stored in read only section in memory and we can't write to that memory
	//  int const* a = new int; is same as const int* a = new int ;////but you can't change the context of pointer but can reassign it to a pointer something else
	int * const a = new int; //can change the context of pointer but can't reassign it to a pointer something else
    *a = 2; 
    // a = &MAX_AGE;// error can't change it to ptr something else
   	std::cout << *a << std::endl;
	// a =(int*) &MAX_AGE;
	std::cout << *a << std::endl;
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

#if 0

/*
    xxx
*/
int main()
{



    cout<<"velue is"<<""<<endl;
}
#endif
