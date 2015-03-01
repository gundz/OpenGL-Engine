
#ifndef		CORE_CLASS_HPP
# define	CORE_CLASS_HPP

# include <iostream>
# include <constant.hpp>

class Core
{
	public:

		typedef struct s_input
		{
			int				key[SDL_NUM_SCANCODES];
			int				button[8];
			int				m_x;
			int				m_y;
			int				m_r_x;
			int				m_r_y;
		}					t_input;

		bool				run;
		t_input				in;


		Core(void);
		Core(Core const &src);
		~Core(void);

		Core				&operator = (Core const &rhs);

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

std::ostream				&operator << (std::ostream &o, Core const &i);

#endif
