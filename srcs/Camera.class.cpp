#include <Camera.class.hpp>

Camera::Camera(Core &core, const Vector3D &pos) : _core(&core), _pos(pos)
{
	_phi = 0;
	_theta = 0;
	_speed = 0.01;
	_sensivity = 0.2;
	vectorFromAngles();
	return ;
}

Camera::Camera(Camera const &src)
{
	*this = src;
	return ;
}

Camera::~Camera(void)
{
	return ;
}

Camera &
Camera::operator = (Camera const &rhs)
{
	if (this != &rhs)
	{
		// copy members here
	}
	return (*this);
}

std::ostream &
operator << (std::ostream &o, Camera const &i)
{
	o	<< "Camera: " << &i;
	return (o);
}

void
Camera::animate(void)
{
	if (_core->getKInput(SDL_SCANCODE_UP))
		_pos += _forward;
	if (_core->getKInput(SDL_SCANCODE_DOWN))
		_pos -= _forward;
	if (_core->getKInput(SDL_SCANCODE_LEFT))
		_pos += _left;
	if (_core->getKInput(SDL_SCANCODE_RIGHT))
		_pos -= _left;

	_target = _pos + _forward;
}

void
Camera::vectorFromAngles(void)
{
	double					r_temp;
	static const Vector3D	up(0, 0, 1);
	
	if (_phi > 89)
		_phi = 89;
	else if (_phi < -89)
		_phi = -89;
	
	r_temp = cos(_phi * M_PI / 180);
	_forward.x = r_temp * cos(_theta * M_PI / 180);
	_forward.y = r_temp * sin(_theta * M_PI / 180);
	_forward.z = sin(_phi * M_PI / 180);

	_left = up.crossProduct(_forward);
	_left.normalize();

	_target = _pos + _forward;
}

void
Camera::look(void)
{
	std::cout <<
		_pos.x << " " <<
		_pos.y << " " <<
		_pos.z << " " <<
		_target.x << " " <<
		_target.y << " " <<
		_target.z << " " <<
		std::endl;
	gluLookAt(
		_pos.x, _pos.y, _pos.z,
		_target.x, _target.y, _target.z,
		0, 0, 1);
}