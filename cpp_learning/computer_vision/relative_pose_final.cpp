/*
    https://www.youtube.com/watch?v=K5WG40gMlz8
    set of 3D point problem registration
*/
#include <iostream>
#include<Eigen/Dense>
#include<vector>
using namespace std;
using namespace Eigen;

int main(){
    Matrix2d H,U,V;
    //{x_n}
    Vector2d a(5.0,12.0);
    Vector2d b(5.0,9.0);
    Vector2d c(9.0,9.0);
    //{y_n}
    Vector2d A(10.0,-3.0);
    Vector2d B(7.0,-3.0);
    Vector2d C(7.0,-7.0);
    Vector2d center_point(8.5,-5.0);
    
    
    // y_o 
    Vector2d y_o = (A+B+C)/3;
    cout<<"y_o = \n"<<y_o<<endl;

    //x_o
    Vector2d x_o = (a+b+c)/3; 
    cout<<"x_o = \n"<<x_o<<endl;

    auto t_a= (A-y_o).transpose();
    auto t_b= (B-y_o).transpose();
    auto t_c= (C-y_o).transpose();
    H = ((a-x_o)*t_a + (b-x_o)*t_b + (c -x_o)*t_c)/3;
    cout<<"H = "<<H<<endl;

    // Perform SVD
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(H, Eigen::ComputeThinU | Eigen::ComputeThinV);

    // Retrieve the matrices
    U = svd.matrixU();
    V = svd.matrixV();

    auto R = V* U.transpose();
    std::cout << "\nRotation Matrix R:\n" << R << "\n";
    auto translation = y_o - R*x_o;
    std::cout << "\ntranslation is :\n" << translation << "\n";

    Vector2d t_center_point;
    t_center_point = R.transpose()*(center_point - translation);
    cout << "transform center point:\n" << t_center_point << "\n\n";
    cout << "center point pose is :\n" << -atan2(R(1,0), R(0,0)) << "\n\n";

}