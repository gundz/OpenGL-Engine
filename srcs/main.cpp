#include <iostream>
#include <Engine.class.hpp>
#include <constant.h>

float		x = 0;
float		y = 0;
float		z = 1;
float		lx = 0;
float		ly = 0;

void
drawLandMark(void)
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
drawCube(void)
{

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
	glVertex3d(-1, 1, -	1);
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
}

#include <cmath>

void
mainGame(Engine &engine)
{
		std::cout << z << std::endl;
		if (engine.getKInput(SDL_SCANCODE_A))
			x -= 0.1;
		if (engine.getKInput(SDL_SCANCODE_D))
			x += 0.1;
		if (engine.getKInput(SDL_SCANCODE_W))
			y += 0.1;
		if (engine.getKInput(SDL_SCANCODE_S))
			y -= 0.1;

		if (engine.getKInput(SDL_SCANCODE_UP))
			z -= 0.1;
		if (engine.getKInput(SDL_SCANCODE_DOWN))
			z += 0.1;
		if (z <= 0.0)
			z = 0;

		if (engine.getMInput(SDL_BUTTON_LEFT))
		{
			lx += fmod(engine.in.m_r_x, 0.05);
			ly += fmod(engine.in.m_r_y, 0.05);
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(x, y, z, 0, 0, 0, 0, 1, 0);
		std::cout << "x : " << x << " - y : " << y << " - z : " << z << std::endl;

		drawCube();
		drawLandMark();

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
	gluPerspective(70, (double)engine._RX / engine._RY, 1, 1000);

	while (!engine.getKInput(SDL_SCANCODE_ESCAPE) && engine.run == 1)
	{
		engine.poolInputs();
		mainGame(engine);
	}
	return (0);
}