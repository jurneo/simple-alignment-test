#ifndef ALIGNMENTMODEL_H
#define ALIGNMENTMODEL_H

#include <core/point2d.h>
#include <vector>

namespace processing {

// in terms of pixel values
typedef sis::Point2d<float> ImagePoint;

// in terms of motor values
typedef sis::Point2d<float> LaserPoint;

// in terms of
typedef std::vector<ImagePoint> ImagePoints;

// in terms of
typedef std::vector<LaserPoint> LaserPoints;

enum AlignmentModel { kLinear, kQuadratic, kCubic };
enum AlignmentStatus { kNotYetComputed, kOk, kNotOk };

struct AlignmentResult
{
    AlignmentModel m_model;
    AlignmentStatus m_status;
    std::vector<double> m_coeffs;

    // initializations
    explicit AlignmentResult(const AlignmentModel& model) :
        m_model(model), m_status(kNotYetComputed), m_coeffs()
    {
    }
};

// for the result of x and y models
typedef std::pair<AlignmentResult, AlignmentResult> PairAlignmentResults;

}

#endif // ALIGNMENTMODEL_H
