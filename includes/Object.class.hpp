#ifndef		OBJECT_CLASS_HPP
# define	OBJECT_CLASS_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <cstdlib>
# include <TVec3.class.hpp>
# include <constant.hpp>

class Object
{
	public:

		typedef TVec3 <float>			Vec3f;
		typedef std::map<int, Vec3f>	mapVec3f;
		typedef TVec3 <int>				Vec3i;
		typedef std::map<int, Vec3i>	mapVec3i;

		Object(void);
		Object(Object const &src);
		~Object(void);

		Object 					&operator = (Object const &rhs);

		void					loadObj(std::string path);
		
		void					insertVertex(const TVec3<float> v);
		mapVec3f const	 		&getVertex(void) const;
		unsigned int			getNbVertex(void) const;
		
		void					insertFace(const TVec3<int> f);
		mapVec3i const			&getFaces(void) const;
		unsigned int			getNbFaces(void) const;

		void					showDirect(void);

	protected:

		unsigned int			_nbVertex;
		std::map<int, Vec3f>	_vertex;
		unsigned int			_nbFaces;
		std::map<int, Vec3i>	_faces;
};

std::ostream				&operator << (std::ostream &o, Object const &i);

#endif