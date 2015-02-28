
#include "Core.class.hpp"

Core::Core(void)
{
	this->run = true;
	return ;
}

Core::Core(Core const &src)
{
	*this = src;
	return ;
}

Core::~Core(void)
{
	SDL_DestroyWindow(this->_window);
	SDL_Quit();
	return ;
}

Core
&Core::operator = (Core const &rhs)
{
	if (this != &rhs)
	{
			//// PUT VALUE HERE
			//// this-> val = rhs.getVal();
	}
	return (*this);
}

std::ostream &
operator << (std::ostream &o, Core const &i)
{
	o	<< "Class : Core" << std::endl;
	(void)i;
	return (o);
}

bool
Core::init(std::string name, const int RX, const int RY)
{
	if( SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
		SDL_Quit();
		return (false);
	}
	// Version d'OpenGL
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	
	// Double Buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	this->_window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, RX, RY, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	this->_RX = RX;
	this->_RY = RY;

	if (this->_window == 0)
	{
		std::cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << std::endl;
		SDL_Quit();

		return ( false );
	}

	this->_GLContext = SDL_GL_CreateContext(this->_window);
	if (this->_GLContext == 0)
	{
		std::cout << SDL_GetError() << std::endl;
		SDL_DestroyWindow(this->_window);
		SDL_Quit();
		return (false);
	}
}

void
Core::poolInputs(void)
{
	SDL_Event	event;

	SDL_GetMouseState(&this->in.m_x, &this->in.m_y);
	SDL_GetRelativeMouseState(&this->in.m_r_x, &this->in.m_r_y);
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			this->in.key[event.key.keysym.scancode] = true;
			break ;
		}
		else if (event.type == SDL_KEYUP)
		{
			this->in.key[event.key.keysym.scancode] = false;
			break ;
		}
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			this->in.button[event.button.button] = true;
			break ;
		}
		if (event.type == SDL_MOUSEBUTTONUP)
		{
			this->in.button[event.button.button] = false;
			break ;
		}
		else if (event.type == SDL_QUIT)
			this->run = false;
	}
}

bool
Core::getKInput(const int scancode)
{
	if (this->in.key[scancode] == true)
		return (true);
	return (false);
}

bool
Core::getMInput(const int scancode)
{
	if (this->in.button[scancode] == true)
		return (true);
	return (false);
}