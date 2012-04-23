#include "alignment.h"
#include <eigen/dense>

namespace processing {

size_t numberOfCoefficients(const AlignmentModel& model)
{
    switch(model)
    {
    case kLinear:
        return 2;
    case kCubic:
        return 4;
    case kQuadratic:
    default:
        return 3;
    }
}

void extrapolate(size_t row, Eigen::MatrixXd& matrix, double v, const AlignmentModel& model)
{
    switch(model)
    {
    case kLinear:
        matrix(row, 0) = v;
        matrix(row, 1) = 1;
        break;
    case kCubic:
        matrix(row, 0) = v*v*v;
        matrix(row, 1) = v*v;
        matrix(row, 2) = v;
        matrix(row, 3) = 1;
        break;
    case kQuadratic:
    default:
        matrix(row, 0) = v*v;
        matrix(row, 1) = v;
        matrix(row, 2) = 1;
        break;
    }
}

void updateResult(const Eigen::VectorXd& r, AlignmentResult& o)
{
    o.m_status = kOk;

    switch(o.m_model)
    {
    case kLinear:
        o.m_coeffs.resize(2);
        o.m_coeffs[0] = r(0);
        o.m_coeffs[1] = r(1);
        break;

    case kCubic: // X^3
        o.m_coeffs.resize(4);
        o.m_coeffs[0] = r(0);
        o.m_coeffs[1] = r(1);
        o.m_coeffs[2] = r(2);
        o.m_coeffs[3] = r(3);
        break;

    case kQuadratic: // X^2
    default:
        o.m_coeffs.resize(3);
        o.m_coeffs[0] = r(0);
        o.m_coeffs[1] = r(1);
        o.m_coeffs[2] = r(2);
        break;
    }
}

PairAlignmentResults Alignment::computeModel(const ImagePoints& imgPts,
        const LaserPoints& laserPts, AlignmentModel modelX, AlignmentModel modelY)
{
    AlignmentResult resultX(modelX);
    AlignmentResult resultY(modelY);

/*
   // Solving Ax = b

   MatrixXf A = MatrixXf::Random(3, 2);
   cout << "Here is the matrix A:\n" << A << endl;
   VectorXf b = VectorXf::Random(3);
   cout << "Here is the right hand side b:\n" << b << endl;
   cout << "The least-squares solution is:\n"
        << A.jacobiSvd(ComputeThinU | ComputeThinV).solve(b) << endl;
*/
    // fill up the matrix A
    if (imgPts.size() != laserPts.size() || imgPts.empty())
    {
        return PairAlignmentResults(resultX, resultY);
    }

    size_t size = imgPts.size();

    using namespace Eigen;
    MatrixXd mat_aX;
    VectorXd mat_bX;
    MatrixXd mat_aY;
    VectorXd mat_bY;

    size_t xsize = numberOfCoefficients(modelX);
    size_t ysize = numberOfCoefficients(modelY);

    mat_aX.resize(size, xsize);
    mat_bX.resize(size, 1);
    mat_aY.resize(size, ysize);
    mat_bY.resize(size, 1);

    for(size_t row = 0; row<size; ++row)
    {
        extrapolate(row, mat_aX, imgPts[row].getX(), modelX);
        extrapolate(row, mat_aY, imgPts[row].getY(), modelY);
        mat_bX(row) = laserPts[row].getX();
        mat_bY(row) = laserPts[row].getY();
    }

    // solve using least square method
    VectorXd r1 = mat_aX.jacobiSvd(ComputeThinU | ComputeThinV).solve(mat_bX);
    updateResult(r1, resultX);

    VectorXd r2 = mat_aY.jacobiSvd(ComputeThinU | ComputeThinV).solve(mat_bY);
    updateResult(r2, resultY);

    return PairAlignmentResults(resultX, resultY);
}

}
