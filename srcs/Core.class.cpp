
#include <Core.class.hpp>

Core::Core(std::string name, const int RX, const int RY) : _name(name), _RX(RX), _RY(RY)
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
		SDL_Quit();
		return ;
	}
	// Version d'OpenGL
	// SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	// SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	
	// Double Buffer
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	_window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, RX, RY, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	if (this->_window == 0)
	{
		std::cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << std::endl;
		SDL_Quit();

		return ;
	}

	this->_GLContext = SDL_GL_CreateContext(this->_window);
	if (this->_GLContext == 0)
	{
		std::cout << SDL_GetError() << std::endl;
		SDL_DestroyWindow(this->_window);
		SDL_Quit();
		return ;
	}

	run = true;
	for (int i = 0; i < SDL_NUM_SCANCODES; i++)
		in.key[i] = false;
	for (int i = 0; i < 8; i++)
		in.button[i] = false;
	_fps.fps = 0;
	_fps.current = 0;
	_fps.update = 0;

	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	
	//glEnable(GL_POLYGON_FLAT);
	glLoadIdentity();
	gluPerspective(70, (double)RX / RY, 0.01, 20000);	
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

Core &
Core::operator = (Core const &rhs)
{
	if (this != &rhs)
	{
			//// PUT VALUE HERE
			//// this-> val = rhs.getVal();
	}
	return (*this);
}

void
Core::preMain(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void
Core::postMain(void)
{
	glFlush();
	SDL_GL_SwapWindow(_window);

	std::ostringstream			oss;

	if ((_fps.update = SDL_GetTicks()) - _fps.current >= 1000)
	{
		_fps.current = _fps.update;
		oss << _name << " - " << _fps.fps << " FPS";
		_fps.text = oss.str();
		SDL_SetWindowTitle(_window, _fps.text.c_str());
		_fps.fps = 0;
	}
	_fps.fps++;
}

void
Core::drawLandMark(void)
{
	glPushMatrix();
	glTranslated(0, 0, 0);

	glBegin(GL_LINES);

	glColor3ub(255, 0, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(10, 0, 0);

	glColor3ub(0, 255, 0);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 10, 0);

	glColor3ub(0, 0, 255);
	glVertex3d(0, 0, 0);
	glVertex3d(0, 0, 10);

	glEnd();

	glPopMatrix();
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

SDL_Window *
Core::getWindow(void) const
{
	return (this->_window);
}

std::ostream &
operator << (std::ostream &o, Core const &i)
{
	o	<< "Class : Core" << std::endl;
	(void)i;
	return (o);
}