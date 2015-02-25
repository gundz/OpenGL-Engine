#include <SDL.h>
#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <Engine.class.hpp>

void
draw(unsigned int scale = 1)
{
	glPushMatrix();
	glScalef(scale, scale, scale);
	glBegin(GL_LINES);

	glColor3ub(255, 0, 0);
	glVertex2d(0, 0);
	glVertex2d(0.5, 0);

	glColor3ub(0, 255, 0);
	glVertex2d(0, 0);
	glVertex2d(0, 0.5);

	glEnd();
	glPopMatrix();
}

void
mainGame(Engine &engine)
{
		glClear(GL_COLOR_BUFFER_BIT);

		draw(1);
/*
		glBegin(GL_TRIANGLES);
		glColor3ub(255,0,0);    glVertex2d(-0.75,-0.75);
		glColor3ub(0,255,0);    glVertex2d(0,0.75);
		glColor3ub(0,0,255);    glVertex2d(0.75,-0.75);
		glEnd();
*/
		glFlush();
		SDL_GL_SwapWindow(engine._window);
}

int
main(void)
{
	Engine          engine;

	engine.init("Test de ouf", 800, 600);

	while (!engine.getInput(SDL_SCANCODE_ESCAPE) && engine.run == 1)
	{
		engine.poolInputs();
		mainGame(engine);
	}
	return (0);
}