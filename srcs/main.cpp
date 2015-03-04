#include <iostream>
#include <constant.hpp>
#include <Core.class.hpp>
#include <TVec3.class.hpp>
#include <Object.class.hpp>
#include <Camera.class.hpp>

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

void
drawSquare(const int x, const int y, const int size)
{
	int z;
		z = 0;
	glBegin(GL_QUADS);
	glVertex3d(x, y, z);
	glVertex3d(x + size, y, z);
	glVertex3d(x + size, y + size, z);
	glVertex3d(x, y + size, z);
	glEnd();
}

void
mainEngine(Core &core, Camera &camera)
{

	camera.animate();
	camera.look();

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	for (int y = 0; y < 100; y++)
	{
		for (int x = 0; x < 100; x++)
			drawSquare(x, y, 1);
	}
	core.drawLandMark();
}

int
main(void)
{
	Core			core("Test de ouf", 800, 600);
	Camera			camera(core);

	while (!core.getKInput(SDL_SCANCODE_ESCAPE) && core.run == true)
	{
		core.preMain();-
		core.poolInputs();

		mainEngine(core, camera);

		core.postMain();
	}
	return (0);
}