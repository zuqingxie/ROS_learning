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
    Matrix2d H, U,V,V_t;
    //{y_n}
    Vector2d A(0.0,0.0);
    Vector2d B(3.0,0.0);
    Vector2d C(0.0,4.0);
    
    //{x_n}
    Vector2d a(9.0,4.0);
    Vector2d b(9.0,1.0);
    Vector2d c(13.0,4.0);
    Vector2d y_o,x_o;
    // y_o 
    y_o =(A+B+C)/3; 
    cout<<"y_o = \n"<<y_o<<endl;

    //x_o
    x_o =(a+b+c)/3; 
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
    Eigen::VectorXd singularValues = svd.singularValues();

    std::cout << "Original Matrix A:\n" << H << "\n\n";
    std::cout << "Matrix U:\n" << U << "\n\n";
    std::cout << "Matrix V:\n" << V << "\n\n";
    std::cout << "Singular Values:\n" << singularValues << "\n";

    // // Reconstruct A from SVD components
    // Eigen::MatrixXd reconstructedA = U * singularValues.asDiagonal() * V.transpose();
    // std::cout << "\nReconstructed Matrix A:\n" << reconstructedA << "\n";

    // auto R = U* V.transpose();
    auto R = V* U.transpose();
    std::cout << "\nRotation Matrix R:\n" << R << "\n";
    auto translation = y_o - R*x_o;
    std::cout << "\ntranslation is :\n" << translation << "\n";



    //solve master thesis problem

    



}