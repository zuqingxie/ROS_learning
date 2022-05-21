#include "eigen3/Eigen/Dense"
#include <iostream>
using namespace std;

int main(){
    Eigen::Matrix3f init_covariance;
    init_covariance(0,0) =1.6;
    init_covariance(0,1) =1.2;
    init_covariance(0,2) =1.3;
    init_covariance(1,0) =1.7;
    init_covariance(1,1) =1.9;
    init_covariance(1,2) =1.6;
    init_covariance(2,0) =1.6;
    init_covariance(2,1) =1.6;
    init_covariance(2,2) =2.6;

    cout<<"eigen 打印"<<init_covariance;


}