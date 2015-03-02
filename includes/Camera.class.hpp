#ifndef		CAMERA_CLASS_HPP
# define	CAMERA_CLASS_HPP

# include <constant.hpp>
# include <TVec3.class.hpp>
# include <Core.class.hpp>
# include <iostream>

class Camera
{
	public:

		Camera(Core &core);
		Camera(Camera const &src);
		~Camera(void);

		Camera			&operator = (Camera const &rhs);

		TVec3<float>	getPosition(void) const;
		void			setPosition(TVec3<float> const &vec);

		void			animate(void);
		void			vectorFromAngles(void);
		void			look(void);

	//protected:

		Core			*_core;
		TVec3<float>	_pos;
		TVec3<float>	_target;
		TVec3<float>	_forward;
		TVec3<float>	_left;
		double			_theta;
		double			_phi;
		double			_sensivity;
		double			_speed;
};

std::ostream			&operator << (std::ostream &o, Camera const &i);

#endif