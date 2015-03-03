#include <iostream>
#include <constant.hpp>
#include <Core.class.hpp>
#include <TVec3.class.hpp>
#include <Object.class.hpp>

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
drawCube(int size, TVec3<float> pos)
{
	glPushMatrix();
	glTranslated(pos.x, pos.y, pos.z);

	glBegin(GL_QUADS);
	glColor3ub(255, 0, 0);
	glVertex3d(size, size, size);
	glVertex3d(size, size, -size);
	glVertex3d(-size, size, -size);
	glVertex3d(-size, size, size);

	glBegin(GL_QUADS);
	glColor3ub(0, 255, 0);
	glVertex3d(size, -size, size);
	glVertex3d(size, -size, -size);
	glVertex3d(size, size, -size);
	glVertex3d(size, size, size);

	glBegin(GL_QUADS);
	glColor3ub(0, 0, 255);
	glVertex3d(size, -size, size);
	glVertex3d(size, -size, -size);
	glVertex3d(-size, -size, -size);
	glVertex3d(-size, -size, size);

	glBegin(GL_QUADS);
	glColor3ub(255, 255, 0);
	glVertex3d(-size, -size, size);
	glVertex3d(-size, -size, -size);
	glVertex3d(-size, size, -	size);
	glVertex3d(-size, size, size);

	glBegin(GL_QUADS);
	glColor3ub(0, 255, 255);
	glVertex3d(size, -size, size);
	glVertex3d(size, size, size);
	glVertex3d(-size, size, size);
	glVertex3d(-size, -size, size);

	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3d(size, -size, -size);
	glVertex3d(size, size, -size);
	glVertex3d(-size, size, -size);
	glVertex3d(-size, -size, -size);
	glEnd();

	glPopMatrix();
}

#include <cmath>
#include <Camera.class.hpp>

void
mainEngine(const Core &core, Camera &camera)
{
	//std::cout << camera << std::endl;

	camera.animate();
	camera.look();
	drawCube(1, TVec3<float>(0, 0, 0));
	drawLandMark();
}
/*
int
main(void)
{
	Core			core("Test de ouf", 800, 600);
	Camera			camera(core);

	while (!core.getKInput(SDL_SCANCODE_ESCAPE) && core.run == true)
	{
		core.preMain();
		core.poolInputs();

		mainEngine(core, camera);

		core.postMain();
	}
	return (0);
}
*/
int
main(void)
{
	Object			object;

	object.loadObj("ressources/test.obj");
	return (0);
}