#include <Camera.class.hpp>

Camera::Camera(Core &core) : _core(&core)
{
	_pos.set(0, 0, 0);
	_target.set(0, 0, 0);
	_forward.set(0, 0, 0);
	_left.set(0, 0, 0);

	_phi = 0;
	_theta = 0;
	// _speed = 0.01;
	_speed = 1;
	_sensivity = 0.2;
	vectorFromAngles();

	SDL_ShowCursor(SDL_DISABLE);
	SDL_SetRelativeMouseMode(SDL_TRUE);
	SDL_SetWindowGrab(_core->getWindow(), SDL_TRUE);
	return ;
}

Camera::Camera(Camera const &src)
{
	*this = src;
	return ;
}

Camera::~Camera(void)
{
	SDL_SetWindowGrab(_core->getWindow(), SDL_FALSE);
	SDL_SetRelativeMouseMode(SDL_FALSE);
	SDL_ShowCursor(SDL_ENABLE);
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

TVec3<float>
Camera::getPosition(void) const
{
	return (_pos);
}

void
Camera::setPosition(TVec3<float> const &pos)
{
	_pos = pos;
	_target = _pos + _forward;
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

	_theta -= _core->in.m_r_x * _sensivity;
	_phi -= _core->in.m_r_y * _sensivity;
	vectorFromAngles();

	_target = _pos + _forward;
}

void
Camera::vectorFromAngles(void)
{
	double						r_temp;
	static const TVec3<float>	up(0, 0, 1);
	
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
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(
		_pos.x, _pos.y, _pos.z,
		_target.x, _target.y, _target.z,
		0, 0, 1);
}

std::ostream &
operator << (std::ostream &o, Camera const &i)
{
	o	<< "Camera: " << std::endl
		<< "pos: " << i._pos;
	return (o);
}