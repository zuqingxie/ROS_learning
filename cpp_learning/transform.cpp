#include <iostream>
#include<Eigen/Dense>
using namespace std;
using namespace Eigen;

#if 0
// 这是一个计算两个机器人相对位姿的代码:
//https://blog.csdn.net/m0_67976789/article/details/128632697?spm=1001.2101.3001.6650.6&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-6-128632697-blog-95114649.235%5Ev38%5Epc_relevant_default_base3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-6-128632697-blog-95114649.235%5Ev38%5Epc_relevant_default_base3&utm_relevant_index=11
int main(int argc, char** argv)
{
    // 机器人B在坐标系O中的坐标：
    Vector3d B(3, 4, M_PI);
 
    // 坐标系B到坐标O的转换矩阵：
    Matrix3d TOB;
    TOB << cos(B(2)), -sin(B(2)), B(0),
           sin(B(2)),  cos(B(2)), B(1),
              0,          0,        1;
 
    // 坐标系O到坐标B的转换矩阵:
    Matrix3d TBO = TOB.inverse();
 
    // 机器人A在坐标系O中的坐标：
    Vector3d A(1, 3, -M_PI / 2);
 
    // 求机器人A在机器人B中的坐标：
    Vector3d BA;
    Matrix3d TOA;
    TOA << cos(A(2)), -sin(A(2)), A(0),
           sin(A(2)),  cos(A(2)), A(1),
              0,          0,        1;
    Matrix3d TBA = TBO * TOA;
    cout << TBA << endl;
    BA << TBA(0, 2),
    TBA(1, 2),
    atan2(TBA(1, 0), TBA(0, 0)); //这样不会出现很多解吧.
    cout << "Your answer is BA: " << BA.transpose() << endl;
    return 0;
}
#endif

#if 0
int main(int argc, char** argv){

    Vector3d pose(1,1,-M_PI/4);
    Matrix3d Tcp,Tpc,Tpo,Top,Toc;
    Vector3d P(1, 1, M_PI/4);
    Vector3d C(2, 0, 0);
    Vector3d OC;
    Top << cos(P(2)), -sin(P(2)), P(0),
           sin(P(2)),  cos(P(2)), P(1),
              0,          0,        1;

    Tpc << cos(C(2)), -sin(C(2)), C(0),
           sin(C(2)),  cos(C(2)), C(1),
              0,          0,        1;
 
    // Tcp = Tpc.inverse();
    // Tpo = Top.inverse();
    Toc = Top*Tpc;

    cout << Toc << endl;

    OC << Toc(0, 2),
    Toc(1, 2),
    atan2(Toc(1, 0), Toc(0, 0)); //这样不会出现很多解吧.
    cout << "Your answer is BA: " << OC.transpose() << endl;
    return 0;






}
#endif

#if 1
int main(int argc, char** argv){

    Vector3d pose(2,1,M_PI/6);
    Matrix3d Tcp,Tpc,Tpo,Top,Toc;
    Vector3d P(2, 1, M_PI/6); //=pose
    Vector3d C(2, 0, 0);
    Vector3d OC;
    Top << cos(P(2)), -sin(P(2)), P(0),//从原点坐标系看p点
           sin(P(2)),  cos(P(2)), P(1),
              0,          0,        1;

    Tpc << cos(C(2)), -sin(C(2)), C(0),//从p坐标系看c点
           sin(C(2)),  cos(C(2)), C(1),
              0,          0,        1;
 
    // Tcp = Tpc.inverse();
    // Tpo = Top.inverse();
    Toc = Top*Tpc; //要求从原点坐标系看c点.很简单,只要中间的 字母对的上就能相乘

    cout << Toc << endl;

    OC << Toc(0, 2), //可以简化,
    Toc(1, 2),
    atan2(Toc(1, 0), Toc(0, 0)); //这样不会出现很多解吧.
    cout << "Your answer is BA: " << OC.transpose() << endl;
    return 0;






}
#endif