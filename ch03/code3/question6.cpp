#include <iostream>
using namespace std;
#include <ctime>
#include <Eigen/Core>
#include <Eigen/Dense>

#define MATRIX_SIZE 4

/**
    这里分别用几种直接法与jocabi迭代法求解线性方程组Ax=b；
    例题摘自于寅版《高等工程数学》第四版，185页
 */

int N_max(20);//最大迭代次数
float eps(1e-3);//收敛误差
bool converge(false);

bool JacobiSolve(const  Eigen::Matrix4d& A, const Eigen::Vector4d b,Eigen::Vector4d& x) {
    int iter_num(0);
    Eigen::Vector4d last_x = x;
    Eigen::Vector4d error = Eigen::Vector4d::Zero();
    Eigen::Matrix4d D =   Eigen::Matrix4d::Zero();
    D(0,0) = A(0,0);
    D(1,1) = A(1,1);
    D(2,2) = A(2,2);
    D(3,3) = A(3,3);
    Eigen::Matrix4d B =  Eigen::Matrix4d::Identity() - D.inverse()*A;

    while(!converge) {
        std::cout<<"第"<<iter_num<<"次迭代"<<std::endl;
        std::cout<<"x:"<<x<<std::endl;
        x = B * x + D.inverse() * b;
        error = x - last_x;
        last_x = x;
        float e_normal = error.norm();
        if (e_normal < eps)
            converge = true;
        iter_num++;
        if (iter_num >= N_max)
                break;
    }

    return converge;
}

int main( int argc, char** argv )
{

    // 如果不确定矩阵大小，可以使用动态大小的矩阵
    Eigen::Matrix4d A;
    A<< 5, -1, -1, -1,
       -1, 10, -1, -1,
       -1, -1,  5, -1,
       -1, -1, -1,  10;
    Eigen::Vector4d b;
    b<<-4,12,8,34;
    //QR分解求解
    Eigen::Matrix<double,MATRIX_SIZE,1> x = A.colPivHouseholderQr().solve(b);
    std::cout<<"x:"<<x<<std::endl;
    //Cholesky分解求解，要求被分解的矩阵必须为正定矩阵
    Eigen::Matrix<double,MATRIX_SIZE,1> x2 = A.llt().solve(b);
    std::cout<<"x2:"<<x2<<std::endl;
    //LDL^T分解
    Eigen::Matrix<double,MATRIX_SIZE,1> x3 = A.ldlt().solve(b);
    std::cout<<"x3:"<<x3<<std::endl;

    //Jacobi迭代法
    Eigen::Matrix<double,MATRIX_SIZE,1> x4 = Eigen::Matrix<double,MATRIX_SIZE,1>::Zero();
    JacobiSolve(A,b,x4);
    return 0;
}
