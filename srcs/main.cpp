#include <iostream>
#include <Core.class.hpp>
#include <constant.hpp>
#include <Vector3d.class.hpp>

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
#include <Camera.class.hpp>

void
mainGame(Core &Core, Camera &camera)
{
		if (Core.getKInput(SDL_SCANCODE_A))
			x -= 0.1;
		if (Core.getKInput(SDL_SCANCODE_D))
			x += 0.1;
		if (Core.getKInput(SDL_SCANCODE_W))
			y += 0.1;
		if (Core.getKInput(SDL_SCANCODE_S))
			y -= 0.1;

		if (Core.getKInput(SDL_SCANCODE_UP))
			z -= 0.1;
		if (Core.getKInput(SDL_SCANCODE_DOWN))
			z += 0.1;
		if (z <= 0.0)
			z = 0;

		if (Core.getMInput(SDL_BUTTON_LEFT))
		{
			lx += fmod(Core.in.m_r_x, 0.05);
			ly += fmod(Core.in.m_r_y, 0.05);
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		camera.animate();
		camera.look();

		drawCube();
		drawLandMark();

		glFlush();
		SDL_GL_SwapWindow(Core._window);
}

int
main(void)
{
	Core			core;
	Camera			camera(core, Vector3D(0, 0, 0));

	core.init("Test de ouf", 800, 600);
	while (!core.getKInput(SDL_SCANCODE_ESCAPE) && core.run == true)
	{
		core.poolInputs();
		mainGame(core, camera);
	}
	return (0);
}