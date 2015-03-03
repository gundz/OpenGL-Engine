#include <Object.class.hpp>

Object::Object(void)
{
	_nbVertex = 0;
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

std::ostream &
operator << (std::ostream &o, Object const &i)
{
	o	<< "Object: " << &i;
	return (o);
}