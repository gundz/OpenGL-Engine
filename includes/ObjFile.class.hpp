#ifndef		OBJFILE_CLASS_HPP
# define	OBJFILE_CLASS_HPP

# include <iostream>
# include <Object.class.hpp>

class ObjFile : public Object
{
	public:
		void			loadObj(std::string path);
};

#endif