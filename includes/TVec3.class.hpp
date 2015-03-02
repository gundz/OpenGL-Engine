
#ifndef		TTVec3_CLASS_HPP
# define	TTVec3_CLASS_HPP

# include <iostream>
# include <cmath>

template<typename TYPE>
class TVec3
{
	public:
		TYPE				x;
		TYPE				y;
		TYPE				z;

		TVec3(void) : x(0.0f), y(0.0f), z(0.0f)
		{
			return ;
		}

		TVec3(TYPE const &x, TYPE const &y, TYPE const &z) : x(x), y(y), z(z)
		{
			return ;
		}

		TVec3(TVec3<TYPE> const &src) : x(src.x), y(src.y), z(src.z)
		{
			return ;
		}

		~TVec3(void)
		{
			return ;
		}

		TVec3<TYPE>
		crossProduct(TVec3<TYPE> const &v) const
		{
			TVec3<TYPE>	r;

			r.x = this->y * v.z - this->z * v.y;
			r.y = this->z * v.x - this->x * v.z;
			r.z = this->x * v.y - this->y * v.x;
			return (r);
		}

		TYPE
		dotProduct(TVec3<TYPE> const &v) const
		{
			return (this->x * v.x + this->y * v.y + this->z * v.z);
		}

		void
		normalize(void)
		{
			TYPE const	h = sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
			this->x = this->x / h;
			this->y = this->y / h;
			this->z = this->z / h;
		}

		void
		set(TYPE const &x, TYPE const &y, TYPE const &z)
		{
			this->x = x;
			this->y = y;
			this->z = z;
		}

		TVec3<TYPE> &
		operator=(TVec3<TYPE> const &rhs)
		{
			if (this != &rhs)
			{
				this->x = rhs.x;
				this->y = rhs.y;
				this->z = rhs.z;
			}
			return (*this);
		}

		TVec3<TYPE>
		operator + (TVec3<TYPE> const &rhs)
		{
			return (TVec3<TYPE>(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z));
		}

		TVec3<TYPE>
		operator * (TVec3<TYPE> const &rhs)
		{
			return (TVec3<TYPE>(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z));
		}

		TVec3<TYPE>
		operator * (TYPE const &rhs)
		{
			return (TVec3<TYPE>(this->x * rhs, this->y * rhs, this->z * rhs));
		}

		TVec3<TYPE> &
		operator += (TVec3<TYPE> const &rhs)
		{
			this->x += rhs.x;
			this->y += rhs.y;
			this->z += rhs.z;
			return (*this);
		}

		TVec3<TYPE> &
		operator -= (TVec3<TYPE> const &rhs)
		{
			this->x -= rhs.x;
			this->y -= rhs.y;
			this->z -= rhs.z;
			return (*this);
		}
};

template<typename TYPE> std::ostream &
operator << (std::ostream &o, TVec3<TYPE> const &i)
{
	o	<< "x: " << i.x << ", y: " << i.y << ", z: " << i.z;
	return (o);
}

#endif
