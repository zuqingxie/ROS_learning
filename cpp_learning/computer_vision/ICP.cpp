/*
    http://www.open3d.org/docs/0.7.0/tutorial/Basic/icp_registration.html
    set of 3D point problem registration
    
*/
#include <iostream>
#include <Eigen/Dense>

int main() {
    Eigen::MatrixXf A(3, 3);
    A << 1, 2, 3,
         4, 5, 6,
         7, 8, 9;

    // Perform SVD
    Eigen::JacobiSVD<Eigen::MatrixXf> svd(A, Eigen::ComputeThinU | Eigen::ComputeThinV);

    // Retrieve the matrices
    Eigen::MatrixXf U = svd.matrixU();
    Eigen::MatrixXf V = svd.matrixV();
    Eigen::VectorXf singularValues = svd.singularValues();

    std::cout << "Original Matrix A:\n" << A << "\n\n";
    std::cout << "Matrix U:\n" << U << "\n\n";
    std::cout << "Matrix V:\n" << V << "\n\n";
    std::cout << "Singular Values:\n" << singularValues << "\n";

    // Reconstruct A from SVD components
    Eigen::MatrixXf reconstructedA = U * singularValues.asDiagonal() * V.transpose();
    std::cout << "\nReconstructed Matrix A:\n" << reconstructedA << "\n";

    return 0;
}