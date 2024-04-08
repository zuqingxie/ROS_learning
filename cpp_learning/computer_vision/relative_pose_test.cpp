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
    //{X_n}
    Vector2d a(-0.646392, 1.090100);
    Vector2d b(-0.155595, 0.897698);
    // Vector2d C(7.0,-7.0);
    
    //{Y_n}
    Vector2d A(-0.646392, 1.090100);
    Vector2d B(1.736763, 1.784774);
    // Vector2d c(9.0,9.0);
    Vector2d y_o,x_o;
    // y_o 
    y_o =(A+B)/2; 
    cout<<"y_o = \n"<<y_o<<endl;

    //x_o
    x_o =(a+b)/2; 
    cout<<"x_o = \n"<<x_o<<endl;


    auto t_a= (A-y_o).transpose();
    auto t_b= (B-y_o).transpose();
    // auto t_c= (C-y_o).transpose();
    // H = ((a-x_o)*t_a + (b-x_o)*t_b + (c -x_o)*t_c)/3;
    H = ((a-x_o)*t_a + (b-x_o)*t_b)/2;
    cout<<"H = "<<H<<endl;

    // Perform SVD
    Eigen::JacobiSVD<Eigen::MatrixXd> svd(H, Eigen::ComputeThinU | Eigen::ComputeThinV);

    // Retrieve the matrices
    U = svd.matrixU();
    V = svd.matrixV();
    Eigen::VectorXd singularValues = svd.singularValues();

    // std::cout << "Original Matrix A:\n" << H << "\n\n";
    // std::cout << "Matrix U:\n" << U << "\n\n";
    // std::cout << "Matrix V:\n" << V << "\n\n";
    // std::cout << "Singular Values:\n" << singularValues << "\n";

    // // Reconstruct A from SVD components
    // Eigen::MatrixXd reconstructedA = U * singularValues.asDiagonal() * V.transpose();
    // std::cout << "\nReconstructed Matrix A:\n" << reconstructedA << "\n";

    // auto R = U* V.transpose();
    auto R = V* U.transpose();
    std::cout << "\nRotation Matrix R:\n" << R << "\n";
    auto translation = y_o - R*x_o;
    double theta = atan2(R(1,0), R(0,0));
    std::cout << "\ntranslation is :\n" << translation << "\n";
    std::cout << "\nrotation angle :\n" << atan2(R(1,0), R(0,0))*180/M_PI << "\n";

    std::cout << "\nRotation Matrix R new:\n" << -R << "\n";
    auto translation_ = y_o + R*x_o;
    double theta_ = atan2(-R(1,0), -R(0,0));
    std::cout << "\ntranslation new is :\n" << translation_ << "\n";
    std::cout << "\nrotation angle new :\n" << atan2(-R(1,0), -R(0,0))*180/M_PI << "\n";



    Vector2d test_a = R*a + translation;
    Vector2d test_b = R*b + translation;
    std::cout<<"test_a:\n"<<test_a<<std::endl;
    // std::cout<<"test_b"<<test_b<<std::endl;

    //重新写入R的方式
    double costheta = std::cos(theta);//|cos  -sin| n逆时针转theta角
    double sintheta = std::sin(theta);//|sin  cos |

    Matrix2d R_new;
    R_new << costheta, -sintheta,
         sintheta, costheta;

    std::cout<< "\nrotation matrix new :\n"<< R_new<<std::endl;

    std::cout<< R_new*a+translation<<std::endl;


    //测试两个点的多解问题:




    //目前已经算出来了 transformation

    // 中心点的问题有待解决

    //solve master thesis problem, ralative pose
    // Matrix3d Tvt,Ttv,Tov,Tvo,Tot,Tvm,Tmv,Tmt,Ttm;
        
    // //从原点坐标系看vehicle
    // Vector3d P(0,10,0);
    // Tov << cos(P(2)), -sin(P(2)), P(0),
    //        sin(P(2)),  cos(P(2)), P(1),
    //           0,          0,        1;

    // Vector3d m2t_pose(translation(0), translation(1), atan2(R(1,0), R(0,0)));
    // cout << "Original 2x2 Matrix:\n" << m2t_pose << "\n\n";

    // // 从template 看measurement
    // Vector3d P_tm((x_o - y_o)(0),(x_o - y_o)(1),-atan2(R(1,0), R(0,0)));                            // pose of measure from the template

    // Ttm << cos(P_tm(2)), -sin(P_tm(2)), P_tm(0),//从原点坐标系看p点
    //        sin(P_tm(2)),  cos(P_tm(2)), P_tm(1),
    //           0,          0,        1;
    

    // // 原点看template
    // Vector3d P_ot(y_o(0),y_o(1),0);                            
    // Tot << cos(P_ot(2)), -sin(P_ot(2)), P_ot(0),
    //        sin(P_ot(2)),  cos(P_ot(2)), P_ot(1),
    //           0,          0,        1;
    
    // Tvo = Tov.transpose();
    // Tvm = Tvo *Tot*Ttm;

    // cout << Tvm << endl;
    // Vector3d OC;
    // OC << Tvm(0, 2), //可以简化,
    // Tvm(1, 2),
    // atan2(Tvm(1, 0), Tvm(0, 0)); //arctan unique solution
    // cout << "Your answer is BA: " << OC.transpose() << endl;


}