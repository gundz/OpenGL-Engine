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
Object::insertVertex(const Vec3f v)
{
	_vertex.insert(std::pair<int, Vec3f>(_nbVertex++, v));
}

Object::mapVec3f const &
Object::getVertex(void) const
{
	return (_vertex);
}

unsigned int
Object::getNbVertex(void) const
{
	return (_nbVertex);
}

void
Object::insertFace(const Vec3i f)
{
	_faces.insert(std::pair<int, Vec3i>(_nbFaces++, f));
}

Object::mapVec3i const &
Object::getFaces(void) const
{
	return (_faces);
}

unsigned int
Object::getNbFaces(void) const
{
	return (_nbFaces);
}

void
Object::showDirect(void)
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
operator << (std::ostream &o, Object const &src)
{
	o	<< "Object: " << std::endl;

	//Show Vertex
	Object::mapVec3f	vertex = src.getVertex();
	unsigned int		nbVertex = src.getNbVertex();

	for (unsigned int i = 0; i < nbVertex; i++)
		o << i << " -  x : " << vertex[i].x << " y : " << vertex[i].y << " z : " << vertex[i].z << std::endl;
	o << std::endl;

	// //Show Faces
	Object::mapVec3i	faces = src.getFaces();
	unsigned int		nbFaces = src.getNbFaces();

	for (unsigned int i = 0; i < nbFaces; i++)
		o << i << " - " << faces[i].x << " " << faces[i].y << " " << faces[i].z << std::endl;
	o << std::endl;
	return (o);
}