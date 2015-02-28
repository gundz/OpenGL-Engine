
#ifndef		ENGINE_CLASS_HPP
# define	ENGINE_CLASS_HPP

# include <iostream>
# include <constant.h>

class Engine
{
	public:

		typedef struct s_input
		{
			char		key[SDL_NUM_SCANCODES];
			char		button[8];
			int			m_x;
			int			m_y;
			int			m_r_x;
			int			m_r_y;
		}				t_input;

		bool				run;
		t_input				in;


		Engine(void);
		Engine( Engine const &src );
		~Engine(void);

		Engine				&operator=(Engine const &rhs);

		bool				init(std::string name, const int RX, const int RY);
		void				poolInputs(void);
		bool				getKInput(const int scancode);
		bool				getMInput(const int scancode);

//	private:
		SDL_Window			*_window;
		int					_RX;
		int					_RY;
		SDL_GLContext		_GLContext;
};

std::ostream				&operator<<(std::ostream &o, Engine const &i);

#endif
