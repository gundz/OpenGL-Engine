#include <Object.class.hpp>

Object::Object(void)
{
	_nbVertex = 0;
	_nbFaces = 0;
	return ;
}

Object::Object(Object const &src)
{
	*this = src;
	return ;
}

Object::~Object(void)
{
	return ;
}

Object &
Object::operator = (Object const &rhs)
{
	if (this != &rhs)
	{
		// copy members here
	}
	return (*this);
}

void
Object::loadObj(std::string path)
{
	std::ifstream			file(path.c_str(), std::ios::in);
	std::string				line;

	std::string				s;
	float					x, y, z;
	int						a, a1, b, b1, c, c1;
	char					w;
	if (file)
	{
		// while (file >> s >> x >> y >> z)
		// {
		// 	if (s == "v")
		// 		std::cout << "v : " << x << " " << " y : " << y << " z : " << z << std::endl;
		// }
		// file.seekg(0);
		while (file >> s >> a >> a1 >> b >> b1 >> c >> c1)
		{
			if (s == "f")
				std::cout << "f : " << 
				a << "/" << a1 << " " << 
				b << "/" << b1 << " " << 
				c << "/" << c1 << std::endl;
		}


		file.close();
	}
	else
		std::cerr << "Unable to open : " << path << std::endl;
}

void
Object::insertVertex(const Vec3f v)
{
	_vertex.insert(std::pair<int, Vec3f>(_nbVertex++, v));
}

void
Object::insertFace(const t_face f)
{
	_faces.insert(std::pair<int, t_face>(_nbFaces++, f));
}

std::ostream &
operator << (std::ostream &o, Object const &i)
{
	o	<< "Object: " << &i;
	return (o);
}