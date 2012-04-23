#ifndef _POINT2D_INL_
#define _POINT2D_INL_

#include <core/point2d.h>

namespace sis
{

template<> inline Point2d<float> & Point2d<float>::operator=(const Point2d<float>& other)
{
    if (this == &other)
    {
        return *this;
    }
    p_[0] = other.p_[0];
    p_[1] = other.p_[1];

    return *this;
}

template<> inline Point2d<float> Point2d<float>::operator+(const Point2d<float>& other)
{
    Point2d<float> result;
    float* q = result.toArrays();
    q[0] = p_[0] + other.p_[0];
    q[1] = p_[1] + other.p_[1];
    return result;
}

template<> inline Point2d<float> Point2d<float>::operator-(const Point2d<float>& other)
{
    Point2d<float> result;
    float* q = result.toArrays();
    q[0] = p_[0] - other.p_[0];
    q[1] = p_[1] - other.p_[1];
    return result;
}

template<> inline Point2d<float> Point2d<float>::operator/(const float& other)
{
    Point2d<float> result;
    float* q = result.toArrays();
    q[0] = p_[0] / other;
    q[1] = p_[1] / other;
    return result;
}

template<> inline Point2d<double> & Point2d<double>::operator=(const Point2d<double>& other)
{
    if (this == &other)
    {
        return *this;
    }
    p_[0] = other.p_[0];
    p_[1] = other.p_[1];

    return *this;
}

template<> inline Point2d<double> Point2d<double>::operator+(const Point2d<double>& other)
{
    Point2d<double> result;
    double* q = result.toArrays();
    q[0] = p_[0] + other.p_[0];
    q[1] = p_[1] + other.p_[1];
    return result;
}

template<> inline Point2d<double> Point2d<double>::operator-(const Point2d<double>& other)
{
    Point2d<double> result;
    double* q = result.toArrays();
    q[0] = p_[0] - other.p_[0];
    q[1] = p_[1] - other.p_[1];
    return result;
}

template<> inline Point2d<double> Point2d<double>::operator/(const double& other)
{
    Point2d<double> result;
    double* q = result.toArrays();
    q[0] = p_[0] / other;
    q[1] = p_[1] / other;
    return result;
}

template<> inline Point2d<float> Point2d<float>::interpolate (const Point2d<float>& p, float ratio) const
{
   Point2d<float> result;

   result.p_[0] = (p.p_[0]-p_[0])*ratio + p_[0];
   result.p_[1] = (p.p_[1]-p_[1])*ratio + p_[1];

   return result;
}

}

#endif
