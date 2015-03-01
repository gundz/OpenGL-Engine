#ifndef		TVECTOR3_HPP
# define	TVECTOR3_HPP

template <typename T>
class TVector3
{
	public:

		TVector3(void)
		{

		}

		TVector3(T x, T y, T z) : _x(x), _y(y), _z(z)
		{

		}

		TVector3(TVector3 const &src)
		{
			*this = src;
		}

		~TVector3(void)
		{

		}

		TVector3 &
		operator = (const TVector3 &s)
		{
			if (this != &s)
			{
				this->_x = s.getX();
				this->_y = s.getY();
				this->_z = s.getZ();
			}
			return (*this);
		}

		TVector3 &
		operator += (const TVector3 &s)
		{
			if (this != &s)
			{
				this->_x += s.getX();
				this->_y += s.getY();
				this->_z += s.getZ();
			}
			return (*this);
		}

		TVector3
		operator + (const TVector3 &s) const
		{
			TVector3		ret = *this;
			ret += s;
			return (ret);
		}

		TVector3 &
		operator -= (const TVector3 &s)
		{
			if (this != &s)
			{
				this->_x -= s.getX();
				this->_y -= s.getY();
				this->_z -= s.getZ();
			}
			return (*this);
		}

		TVector3
		operator - (const TVector3 &s) const
		{
			TVector3		ret = *this;
			ret -= s;
			return (ret);
		}

		TVector3 &
		operator *= (const TVector3 &s)
		{
			if (this != &s)
			{
				this->_x *= s.getX();
				this->_y *= s.getY();
				this->_z *= s.getZ();
			}
			return (*this);
		}

		TVector3
		operator * (const TVector3 &s) const
		{
			TVector3		ret = *this;
			ret *= s;
			return (ret);
		}

		TVector3 &
		operator /= (const TVector3 &s)
		{
			if (this != &s)
			{
				this->_x /= s.getX();
				this->_y /= s.getY();
				this->_z /= s.getZ();
			}
			return (*this);
		}

		TVector3
		operator / (const TVector3 &s) const
		{
			TVector3		ret = *this;
			ret /= s;
			return (ret);
		}

		TVector3
		crossProduct(const TVector3 &v) const
		{
			TVector3		ret;

			ret.setX(this->_y * v.getZ() - this->_z * v.getY());
			ret.setY(this->_z * v.getX() - this->_x * v.getZ());
			ret.setZ(this->_x * v.getY() - this->_y * v.getX());
			return (ret);
		}

		T
		getLength(void) const
		{
			return (sqrt(
				this->_x * this->_x +
				this->_y * this->_y + 
				this->_z * this->_z));
		}

		T
		getX(void) const
		{
			return (this->_x);
		}

		void
		setX(const T x)
		{
			this->_x = x;
		}

		T
		getY(void) const
		{
			return (this->_y);
		}

		void
		setY(const T y)
		{
			this->_y = y;
		}

		T
		getZ(void) const
		{
			return (this->_z);
		}

		void
		setZ(const T z)
		{
			this->_z = z;
		}

	private:

		T				_x;
		T				_y;
		T				_z;
};

template <typename T>
std::ostream &
operator << (std::ostream &o, const TVector3<T> &i)
{
	o << "x : " << i.getX() <<
		" - y : " << i.getY() <<
		" - z : " << i.getZ();
	return (o);
}

#endif