#ifndef		OBJECT_CLASS_HPP
# define	OBJECT_CLASS_HPP

# include <iostream>
# include <map>
# include <TVec3.class.hpp>

class Object
{
	public:

		Object(void);
		Object(Object const &src);
		~Object(void);

		Object				&operator = (Object const &rhs);

		void				loadObj(std::string path);
		void				insertVertex(const TVec3<float> v);

	protected:

		typedef TVec3 <float>	Vec3f;
		std::map<int, Vec3f>	_vertex;
		unsigned int			_nbVertex;
};

std::ostream				&operator << (std::ostream &o, Object const &i);

#endif