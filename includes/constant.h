#ifndef		CONSTANT_H
# define	CONSTANT_H

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