#include <iostream>
#include <Engine.class.hpp>
#include <constant.h>

int		angX = 0;
int		angY = 0;
int		angZ = 0;

void
drawLandMark(void)
{
	glBegin(GL_LINES);

	glColor3ub(255, 0, 0);
	glVertex2d(0, 0);
	glVertex2d(0.5, 0);

	glColor3ub(0, 255, 0);
	glVertex2d(0, 0);
	glVertex2d(0, 0.5);

	glEnd();
}

void
drawCube(void)
{
	//glPushMatrix();

	glRotated(angX, 1, 0, 1);
	glRotated(angY, 0, 1, 0);
	glRotated(angZ, 0, 0, 1);

	glBegin(GL_QUADS);
	glColor3ub(255, 0, 0);
	glVertex3d(1, 1, 1);
	glVertex3d(1, 1, -1);
	glVertex3d(-1, 1, -1);
	glVertex3d(-1, 1, 1);

	glBegin(GL_QUADS);
	glColor3ub(0, 255, 0);
	glVertex3d(1, -1, 1);
	glVertex3d(1, -1, -1);
	glVertex3d(1, 1, -1);
	glVertex3d(1, 1, 1);

	glBegin(GL_QUADS);
	glColor3ub(0, 0, 255);
	glVertex3d(1, -1, 1);
	glVertex3d(1, -1, -1);
	glVertex3d(-1, -1, -1);
	glVertex3d(-1, -1, 1);

	glBegin(GL_QUADS);
	glColor3ub(255, 255, 0);
	glVertex3d(-1, -1, 1);
	glVertex3d(-1, -1, -1);
	glVertex3d(-1, 1, -1);
	glVertex3d(-1, 1, 1);

	glBegin(GL_QUADS);
	glColor3ub(0, 255, 255);
	glVertex3d(1, -1, 1);
	glVertex3d(1, 1, 1);
	glVertex3d(-1, 1, 1);
	glVertex3d(-1, -1, 1);

	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3d(1, -1, -1);
	glVertex3d(1, 1, -1);
	glVertex3d(-1, 1, -1);
	glVertex3d(-1, -1, -1);
	glEnd();

	//glPopMatrix();
}

void
mainGame(Engine &engine)
{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		if (engine.getKInput(SDL_SCANCODE_A))
			angZ -= 1;
		if (engine.getKInput(SDL_SCANCODE_D))
			angZ += 1;

		if (engine.getKInput(SDL_SCANCODE_W))
			angY -= 1;
		if (engine.getKInput(SDL_SCANCODE_S))
			angY += 1;

		if (engine.getMInput(SDL_BUTTON_LEFT))
		{
			angY += engine.in.m_r_y;
			angZ += engine.in.m_r_x;
		}

		if (engine.getKInput(SDL_SCANCODE_Q))
			angX -= 1;
		if (engine.getKInput(SDL_SCANCODE_E))
			angX += 1;

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt(3, 4, 2, 0, 0, 0, 0, 0, 1);

		drawCube();

		glFlush();
		SDL_GL_SwapWindow(engine._window);
}

int
main(void)
{
	Engine          engine;

	engine.init("Test de ouf", 800, 600);

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (double)800 / 600, 1, 1000);

	while (!engine.getKInput(SDL_SCANCODE_ESCAPE) && engine.run == 1)
	{
		engine.poolInputs();
		mainGame(engine);
	}
	return (0);
}