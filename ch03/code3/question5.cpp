#include <iostream>
#include <cmath>
using namespace std;

#include <Eigen/Core>
#include <Eigen/Dense>
// Eigen 几何模块
#include <Eigen/Geometry>

int main ( int argc, char** argv )
{
    Eigen::MatrixXd m1 = Eigen::MatrixXd::Random(10,10);
    std::cout<<"m1:"<<m1<<std::endl;
    m1.block(0,0,3,3) = Eigen::Matrix3d::Identity();
    std::cout<<"m1:"<<m1<<std::endl;
    return 0;
}
