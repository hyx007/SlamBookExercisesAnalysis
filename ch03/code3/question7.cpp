#include <iostream>
#include <cmath>
using namespace std;

#include <Eigen/Core>
#include <Eigen/Dense>
// Eigen 几何模块
#include <Eigen/Geometry>

int main ( int argc, char** argv )
{
    Eigen::Quaterniond q1(0.35,0.2,0.3,0.1);
    q1 = q1.normalized();
    Eigen::Vector3d t1(0.3,0.1,0.1);
    Eigen::Quaterniond q2(-0.5,0.4,-0.1,0.2);
    q2 = q2.normalized();
    Eigen::Vector3d t2(-0.1,0.5,0.3);
    Eigen::Vector3d pc1(0.5,0.,0.2);

    Eigen::Isometry3d Tc1w=Eigen::Isometry3d::Identity();
    Eigen::Isometry3d Tc2w=Eigen::Isometry3d::Identity();
    Tc1w.rotate(q1);
    Tc1w.pretranslate(t1);
    Tc2w.rotate(q2);
    Tc2w.pretranslate(t2);
    Eigen::Isometry3d Tc2c1 = Tc2w*(Tc1w.inverse());
    Eigen::Vector3d result = Tc2c1*pc1;
    std::cout<<"result:"<<result<<std::endl;
    return 0;
}
