#ifndef		VECTOR3D_CLASS_HPP
# define	VECTOR3D_CLASS_HPP

# include <iostream>
# include <cmath>


class Vector3D
{
	public:

    double			x;
    double			y;
    double			z;

    Vector3D(void);
    Vector3D(double x,double y,double z);
    Vector3D(const Vector3D &v);
    Vector3D(const Vector3D &from, const Vector3D &to);

    Vector3D &operator = (const Vector3D &v);

    Vector3D &operator += (const Vector3D &v);
    Vector3D operator + (const Vector3D &v) const;

    Vector3D &operator -= (const Vector3D &v);
    Vector3D operator - (const Vector3D &v) const;

    Vector3D &operator *= (const double a);
    Vector3D operator * (const double a)const;
    friend Vector3D operator * (const double a, const Vector3D &v);

    Vector3D & operator /= (const double a);
    Vector3D operator / (const double a)const;

    Vector3D crossProduct(const Vector3D &v)const;
    double length(void)const;
    Vector3D & normalize(void);
};

#endif