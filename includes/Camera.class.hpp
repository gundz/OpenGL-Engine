#ifndef		CAMERA_CLASS_HPP
# define	CAMERA_CLASS_HPP

# include <constant.hpp>
# include <Vector3d.class.hpp>
# include <Core.class.hpp>
# include <iostream>

class Camera
{
	public:

		Camera(Core &core, const Vector3D &pos);
		Camera(Camera const &src);
		~Camera(void);

		Camera			&operator = (Camera const &rhs);

		void			animate(void);
		void			vectorFromAngles(void);
		void			look(void);

	protected:

		Core			*_core;
		Vector3D		_pos;
		Vector3D		_target;
		Vector3D		_forward;
		Vector3D		_left;
		double			_theta;
		double			_phi;
		double			_sensivity;
		double			_speed;
};

std::ostream			&operator << (std::ostream &o, Camera const &i);

#endif