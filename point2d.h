#ifndef POINT2D_H
#define POINT2D_H

#include <boost/smart_ptr.hpp>

namespace sis {

template <typename T>
class Point2d
{
public:
    Point2d() { p_[0] = 0; p_[1] = 0; }
    Point2d(const T& x, const T& y) { p_[0] = x; p_[1] = y; }
    Point2d(const Point2d& other) { p_[0] = other.p_[0]; p_[1] = other.p_[1]; }
    Point2d& operator=(const Point2d& other);
    virtual ~Point2d() {}

    T getX() const { return p_[0]; }
    T getY() const { return p_[1]; }

    T* toArrays() { return p_; }

    void setX(const T& x) { p_[0] = x; }
    void setY(const T& y) { p_[1] = y; }
    void set(const T& x, const T& y) { p_[0]=x; p_[1]=y; }

    // arithmetic operation
    Point2d operator+(const Point2d& other);
    Point2d operator-(const Point2d& other);

    // scalar
    Point2d operator/(const T& other);

    Point2d interpolate (const Point2d& p, float ratio) const;

private:
    T p_[2];
};

typedef boost::shared_ptr<Point2d<float> > Point2dPtr;
typedef boost::shared_array<Point2d<float> > Point2dArray;

}

#include <core/point2d.inl>

#endif // POINT2D_H
