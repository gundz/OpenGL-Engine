#include <Vector3d.class.hpp>

Vector3D::Vector3D(void)
{
    x = 0;
    y = 0;
    z = 0;
}

Vector3D::Vector3D(double x, double y, double z)
{
    x = x;
    y = y;
    z = z;
}

Vector3D::Vector3D(const Vector3D &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
}

Vector3D::Vector3D(const Vector3D & from, const Vector3D &to)
{
    x = to.x - from.x;
    y = to.y - from.y;
    z = to.z - from.z;
}

Vector3D &
Vector3D::operator = (const Vector3D &v)
{
    x = v.x;
    y = v.y;
    z = v.z;
    return (*this);
}

Vector3D &
Vector3D::operator += (const Vector3D &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return (*this);
}

Vector3D
Vector3D::operator + (const Vector3D &v) const
{
    Vector3D t = *this;
    t += v;
    return (t);
}

Vector3D &
Vector3D::operator -= (const Vector3D &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return (*this);
}

Vector3D
Vector3D::operator - (const Vector3D &v) const
{
    Vector3D t = *this;
    t -= v;
    return (t);
}

Vector3D &
Vector3D::operator *= (const double a)
{
    x *= a;
    y *= a;
    z *= a;
    return (*this);
}

Vector3D
Vector3D::operator * (const double a) const
{
    Vector3D t = *this;
    t *= a;
    return (t);
}

Vector3D operator * (const double a,const Vector3D &v)
{
    return Vector3D(v.x*a,v.y*a,v.z*a);
}

Vector3D &
Vector3D::operator /= (const double a)
{
    x /= a;
    y /= a;
    z /= a;
    return (*this);
}

Vector3D
Vector3D::operator / (const double a) const
{
    Vector3D t = *this;
    t /= a;
    return (t);
}

Vector3D
Vector3D::crossProduct(const Vector3D & v) const
{
    Vector3D t;
    t.x = y*v.z - z*v.y;
    t.y = z*v.x - x*v.z;
    t.z = x*v.y - y*v.x;
    return t;
}

double
Vector3D::length(void)const
{
    return sqrt( x*x + y*y + z*z);
}

Vector3D &
Vector3D::normalize(void)
{
    (*this) /= length();
    return (*this);
}