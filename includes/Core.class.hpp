
#ifndef		CORE_CLASS_HPP
# define	CORE_CLASS_HPP

# include <iostream>
# include <constant.hpp>
# include <cstring>
# include <sstream>

class Core
{
	public:

		typedef struct		s_input
		{
			bool			key[SDL_NUM_SCANCODES];
			bool			button[8];
			int				m_x;
			int				m_y;
			int				m_r_x;
			int				m_r_y;
		}					t_input;

		typedef struct		s_timer
		{
			Uint32			fps;
			Uint32			current;
			Uint32			update;
			std::string		text;
		}					t_timer;

		bool				run;
		t_input				in;


		Core(std::string name, const int RX, const int RY);
		Core(Core const &src);
		~Core(void);

		Core				&operator = (Core const &rhs);

		void				preMain(void);
		void				postMain(void);
		void				poolInputs(void);
		bool				getKInput(const int scancode);
		bool				getMInput(const int scancode);

		SDL_Window			*getWindow(void) const;
 
	private:
		SDL_Window			*_window;
		std::string			_name;
		int					_RX;
		int					_RY;
		SDL_GLContext		_GLContext;
		t_timer				_fps;
};

std::ostream				&operator << (std::ostream &o, Core const &i);

#endif
