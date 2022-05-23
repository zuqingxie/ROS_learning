#if 0
#include <iostream>
#include <cstdint>
#include <cstring>
 
int main()
{
    // simple usage
    char source[] = "once upon a midnight dreary...", dest[4];
    std::memcpy(dest, source, sizeof dest);
    std::cout << "dest[4] = { ";
    for (char c : dest)
        std::cout << "'" << c << "', ";
    std::cout << "};\n";
 
    // reinterpreting
    double d = 0.1;
//  std::int64_t n = *reinterpret_cast<std::int64_t*>(&d); // aliasing violation
    std::int64_t n;
    std::memcpy(&n, &d, sizeof d); // OK
 
    std::cout << std::hexfloat << d << " is " << std::hex << n
              << " as an std::int64_t\n" << std::dec;
 
    // object creation in destination buffer
    struct S {
        int x{42};
        void print() const { std::cout << "{" << x << "}\n"; }
    } s;
    alignas(S) char buf[sizeof(S)];
    S* ps = new (buf) S; // placement new
    std::memcpy(ps, &s, sizeof s);
    ps->print();
}
#endif
#if 0
#include <iostream>
#include <cstdint>
#include <cstring>
#include <deque>

using namespace std;
int main()
{
    // std::deque<float> ap ={1.0, 2.0, 3.0};
    float velocity_send[3]={0,1,2};
    float velocity_copy[3];
    // array 的长度的表达：
    // int len = sizeof(arr) / sizeof(arr[0]);
    int len = sizeof(velocity_send)/sizeof(velocity_send[0]);
    cout<<"size of velocity_send ="<<len<<endl;
    for (auto it = 0; it !=len; ++it){
        velocity_copy[it] = velocity_send[it];
        cout<<"velocity_copy("<<it<<"):"<<velocity_copy[it]<<endl;

    }

    
    // }

}

#endif
#if 0
#include <iostream>
#include <cstdint>
#include <cstring>
#include <deque>

int main(){
    char str1[] = "Geeks"; 
  char str2[] = "Quiz"; 
 
  puts("str1 before memcpy ");
  puts(str1);
 
  /* Copies contents of str2 to str1 */
  memcpy (str1, str2, sizeof(str2));
 
  puts("\nstr1 after memcpy ");
  puts(str1);
 
  return 0;


}
#endif
#if 1
#include <iostream>
#include <deque>
// #include "eigen3/Eigen/Dense"

using namespace std;

struct Traj
{
    /* data */
    int num;
    float arr[3];
};


int main(){
    
    std::deque<Traj> tra;
    Traj a ={ 2, {1.0,2.2,3.0}};
        Traj b ={ 5, {4.0,5.0,6.0}};
        Traj c ={ 5, {4.0,5.0,6.0}};
    tra.push_back(a);
    tra.push_back(b);
    tra.push_back(c);

    // iterater 的使用方式
    for(auto it = tra.begin(); it!=tra.end(); ++it){
        int number = (*it).num;
        cout<<"num = "<<number<<endl;
        // it =it +1;
        number = (*(it+1)).num;
        cout<<"num second= "<<number<<endl;
        // it = it -1;

    }

    // method 1
    float arr_now[3];
    int len =3;

    for (auto i = 0; i !=len; ++i){
        arr_now[i] = tra[0].arr[i];
        cout<<"after copy:"<< arr_now[i]<<endl;
    }
    
    // Eigen::VectorXf array_;
    // array_(0)= 1.6989;
    // cout<<"array is:"<<array_(0)<<endl;
    // write into 
    // float arr_write[3] ={1.0,1.0,1.0};
    // float Traj:: arr_write[3];
    // arr_write = {1.0,2.0,3.0};
    // int len =3;
    // tra[0].arr = arr_write;

    // for (auto i = 0; i !=len; ++i){
    //     arr_now[i] = tra[0].arr[i];
    //     cout<<"after copy:"<< arr_now[i]<<endl;
    // }




}
#endif