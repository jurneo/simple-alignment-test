#include <iostream>
#include "alignmentmodel.h"
#include "alignment.h"
#include <core/point2d.h>

using namespace std;

int main(int argc, char *argv[])
{
    using namespace processing;

    // test with linear model y = 2x + 10; for X-mapping
    // test with quadratic model y = x^2 + 3x + 5 for Y-mapping
    ImagePoint p1(1,1);
    ImagePoint p2(2,2);
    ImagePoint p3(3,3);
    LaserPoint s1(12, 9);
    LaserPoint s2(14, 15);
    LaserPoint s3(16, 23);

    ImagePoints pts;
    pts.push_back(p1);
    pts.push_back(p2);
    pts.push_back(p3);

    LaserPoints lts;
    lts.push_back(s1);
    lts.push_back(s2);
    lts.push_back(s3);

    PairAlignmentResults results = Alignment::computeModel(pts, lts, kLinear, kQuadratic);
    AlignmentResult r1 = results.first;
    AlignmentResult r2 = results.second;
    std::cout << r1.m_coeffs[0] << ", " << r1.m_coeffs[1] << "\n";
    std::cout << r2.m_coeffs[0] << ", " << r2.m_coeffs[1] << ", " << r2.m_coeffs[2] << "\n";

    return 0;
}
