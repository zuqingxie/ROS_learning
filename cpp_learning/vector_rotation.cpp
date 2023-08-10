#include <iostream>
#include<Eigen/Dense>
#include<vector>
using namespace std;
using namespace Eigen;

#if 1
// 这是一个计算两个机器人相对位姿的代码:
//https://blog.csdn.net/m0_67976789/article/details/128632697?spm=1001.2101.3001.6650.6&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-6-128632697-blog-95114649.235%5Ev38%5Epc_relevant_default_base3&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-6-128632697-blog-95114649.235%5Ev38%5Epc_relevant_default_base3&utm_relevant_index=11
int main(int argc, char** argv)
{
    std::vector<double> A,B,C,D;
    A = {0.0,0.0};
    B = {3.0,4.0};
    C = {8.0,0.0};
    D = {12.0,1.5};

    std::vector<double>A_B,C_D;
    A_B = {B[0]-A[0],B[1]-A[1]};
    C_D = {D[0]-C[0],D[1]-C[1]};
    double theta_1 = std::atan2(A_B[1],A_B[0]);
    double theta_2 = std::atan2(C_D[1],C_D[0]);
    double x = C[0]-A[0];
    double y = C[1]-A[1];
    double theta = theta_2-theta_1;
    std::cout<<"x = "<<  x << " , y = " << y << " , theta = " << theta*180/M_PI <<std::endl;

    // rotate another point E (0,4)
    std::vector<double> E,E_rotated;
    E = {0,4, M_PI_2};
    double costheta = std::cos(theta);//|cos  -sin| n逆时针转theta角
    double sintheta = std::sin(theta);//|sin  cos |
    std::cout<<"cos = "<< costheta << " , sin = " << sintheta <<std::endl;
    E_rotated = {E[0]*costheta - E[1]*sintheta + x, E[0]*sintheta+ E[1]*costheta+ y};
    std::cout<<"rotated E with x = "<<  E_rotated[0]<< " , y = " << E_rotated[1] << " , orientaiton = " << (E[2] +theta)*180/M_PI<<std::endl;

}
#endif