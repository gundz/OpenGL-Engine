#ifndef		CONSTANT_HPP
# define	CONSTANT_HPP

# ifdef linux
# include <GL/glu.h>
# include <GL/gl.h>
# include <GL/glut.h>
# include <SDL2/SDL.h>
# endif
# ifdef __APPLE__
# include <openGL/glu.h>
# include <openGL/gl.h>
# include <GLUT/glut.h>
# include <SDL.h>
# endif

#endif