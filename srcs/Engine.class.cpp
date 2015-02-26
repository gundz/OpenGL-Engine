
#include "Engine.class.hpp"

Engine::Engine(void)
{
	this->run = 1;
	return ;
}

Engine::Engine(Engine const &src)
{
	*this = src;
	return ;
}

Engine::~Engine(void)
{
	SDL_DestroyWindow(this->_window);
	SDL_Quit();
	return ;
}

Engine
&Engine::operator=(Engine const &rhs)
{
	if (this != &rhs)
	{
			//// PUT VALUE HERE
			//// this-> val = rhs.getVal();
	}
	return (*this);
}

std::ostream
&operator<<(std::ostream &o, Engine const &i)
{
	o	<< "Class : Engine" << std::endl;
	(void)i;
	return (o);
}

bool
Engine::init(std::string name, int RX, int RY)
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
Engine::poolInputs(void)
{
	SDL_Event event;

	SDL_GetMouseState(&this->in.m_x, &this->in.m_y);
	SDL_GetRelativeMouseState(&this->in.m_r_x, &this->in.m_r_y);
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN)
		{
			this->in.key[event.key.keysym.scancode] = 1;
			break ;
		}
		else if (event.type == SDL_KEYUP)
		{
			this->in.key[event.key.keysym.scancode] = 0;
			break ;
		}
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			this->in.button[event.button.button] = 1;
			break ;
		}
		if (event.type == SDL_MOUSEBUTTONUP)
		{
			this->in.button[event.button.button] = 0;
			break ;
		}
		else if (event.type == SDL_QUIT)
			this->run = 0;
	}
}

bool
Engine::getKInput(int scancode)
{
	if (this->in.key[scancode] == 1)
		return (true);
	return (false);
}

bool
Engine::getMInput(int scancode)
{
	if (this->in.button[scancode] == 1)
		return (true);
	return (false);
}