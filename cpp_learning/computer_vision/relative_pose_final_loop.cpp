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
    Matrix2d U,V;
    Matrix2d H = Matrix2d::Zero();
    //{y_n} Template
    std::vector<std::pair<Vector2d, Vector2d>> point_pair;
    Vector2d center_point(1.79020,1.86217);
    //{x_n} measurements
    // Vector2d a(5.0,12.0);
    // Vector2d b(5.0,9.0);
    // Vector2d c(9.0,9.0);

    // Vector2d A(10.0,-3.0);
    // Vector2d B(7.0,-3.0);
    // Vector2d C(7.0,-7.0);
    
    Vector2d a(0.234058, 0.798684);
    Vector2d b(0.142777, 1.162806);
    Vector2d c(-0.772560, 0.915287);
    Vector2d d(-0.664753, 0.554510);
    
    //{Y_n}
    Vector2d A(1.242767, 2.109341);
    Vector2d B(1.346743, 1.799540);
    Vector2d C(2.221643, 2.069928);
    Vector2d D(2.130244, 2.387423);



    point_pair.push_back(std::make_pair(a,A));
    point_pair.push_back(std::make_pair(b,B));
    point_pair.push_back(std::make_pair(c,C));
    point_pair.push_back(std::make_pair(d,D));
    
    // y_o 
    // Vector2d y_o = (A+B+C)/3;
    Vector2d sum_T(0,0);
    Vector2d sum_m(0,0);
    for(int i = 0; i< point_pair.size();i++){
        sum_m +=point_pair[i].first;
        sum_T += point_pair[i].second;

    }
    Vector2d y_o = sum_T/point_pair.size();
    cout<<"y_o = \n"<<y_o<<endl;

    //x_o
    Vector2d x_o = sum_m/point_pair.size(); 
    cout<<"x_o = \n"<<x_o<<endl;


    for(int i = 0; i< point_pair.size();i++){
        H = H + (point_pair[i].first-x_o)*(point_pair[i].second- y_o).transpose();
    }
    H = H/point_pair.size();
    cout<<"H = "<<H<<endl;

    // Perform SVD
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(H, Eigen::ComputeThinU | Eigen::ComputeThinV);

    // Retrieve the matrices
    U = svd.matrixU();
    V = svd.matrixV();

    auto R = V* U.transpose();
    std::cout << "\nRotation Matrix R:\n" << R << "\n";
    double theta = atan2(R(1,0), R(0,0));
    std::cout << "\nRotation angle is :\n" << theta *180/M_PI << "\n";
    auto translation = y_o - R*x_o;
    std::cout << "\ntranslation is :\n" << translation << "\n";

    Vector2d t_center_point;
    t_center_point = R.transpose()*(center_point - translation);
    cout << "transformed center point:\n" << t_center_point << "\n\n";
    cout << "center point pose is :\n" << -atan2(R(1,0), R(0,0)) << "\n\n";

}