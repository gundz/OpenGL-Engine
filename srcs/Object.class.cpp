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
	std::string				s1, s2, s3;
	if (file)
	{
		while (std::getline(file, line))
		{
			std::stringstream		issV(line);
			
			if (issV >> s >> x >> y >> z)
			{
				if (s == "v")
				{
					insertVertex(Vec3f(x, y, z));
				}
			}

			std::stringstream		issF(line);
			if (issF >> s >> s1 >> s2 >> s3)
			{
				if (s == "f")
				{
					insertFace(Vec3i(
							atoi(s1.c_str()), 
							atoi(s2.c_str()), 
							atoi(s3.c_str())
							));
				}
			}
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
Object::insertFace(const Vec3i f)
{
	_faces.insert(std::pair<int, Vec3i>(_nbFaces++, f));
}

void
Object::showVertex(void)
{
	for (unsigned int i = 0; i < _vertex.size(); i++)
		std::cout << i << " -  x : " << _vertex[i].x << " y : " << _vertex[i].y << " z : " << _vertex[i].z << std::endl;
	std::cout << std::endl;
}

void
Object::showFaces(void)
{
	for (unsigned int i = 0; i < _faces.size(); i++)
		std::cout << i << " - " << _faces[i].x << " " << _faces[i].y << " " << _faces[i].z << std::endl;
	std::cout << std::endl;
}

void
Object::show(void)
{
	TVec3<float>		tmp;

	for (unsigned int i = 0; i < _faces.size(); i++)
	{
		glBegin(GL_TRIANGLES);
		tmp = _vertex[_faces[i].x - 1];
		
		glVertex3d(tmp.x, tmp.y, tmp.z);
		tmp = _vertex[_faces[i].y - 1];
		glVertex3d(tmp.x, tmp.y, tmp.z);
		tmp = _vertex[_faces[i].z - 1];
		glVertex3d(tmp.x, tmp.y, tmp.z);
		glEnd();
	}
}

std::ostream &
operator << (std::ostream &o, Object const &i)
{
	o	<< "Object: " << &i;
	return (o);
}