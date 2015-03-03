#ifndef		OBJECT_CLASS_HPP
# define	OBJECT_CLASS_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <TVec3.class.hpp>

class Object
{
	public:
		typedef struct			s_face
		{
			int					a;
			int					a1;
			int					b;
			int					b1;
			int					c;
			int					c1;
		}						t_face;


		Object(void);
		Object(Object const &src);
		~Object(void);

		Object				&operator = (Object const &rhs);

		void				loadObj(std::string path);
		void				insertVertex(const TVec3<float> v);
		void				insertFace(const t_face f);

	protected:

		typedef TVec3 <float>	Vec3f;
		unsigned int			_nbVertex;
		std::map<int, Vec3f>	_vertex;
		unsigned int			_nbFaces;
		std::map<int, t_face>	_faces;
};

std::ostream				&operator << (std::ostream &o, Object const &i);

#endif