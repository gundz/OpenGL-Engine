#include <iostream>
#include <constant.hpp>
#include <Core.class.hpp>
#include <TVec3.class.hpp>
#include <Object.class.hpp>
#include <Camera.class.hpp>
#include <Noise.class.hpp>

void
mainEngine(Core &core, Camera &camera, Noise &noise)
{

	camera.animate();
	camera.look();

	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glPushMatrix();
	// glScalef(10, 10, 10);
	glTranslatef(0, 0, -255);

	for (int y = 0; y < noise.getSize() - 1; y++)
	{
		for (int x = 0; x < noise.getSize() - 1; x++)
		{
			glBegin(GL_TRIANGLES);
			glColor3ub(0, noise.retNoise.t[y][x] % 256,0);
			glVertex3d(x, y, noise.retNoise.t[y][x]);
			glVertex3d(x, y + 1, noise.retNoise.t[y + 1][x]);
			glVertex3d(x + 1, y + 1, noise.retNoise.t[y + 1][x + 1]);
			glEnd();

			glBegin(GL_TRIANGLES);
			glColor3ub(0, noise.retNoise.t[y][x] % 256, 0);
			glVertex3d(x, y, noise.retNoise.t[y][x]);
			glVertex3d(x + 1, y, noise.retNoise.t[y][x + 1]);
			glVertex3d(x + 1, y + 1, noise.retNoise.t[y + 1][x + 1]);
			glEnd();
		}
	}

	glPopMatrix();

	core.drawLandMark();
}

int
main(void)
{
	Core			core("Test de ouf", 800, 600);
	Camera			camera(core);

	Noise			noise(250, 4, 10, 0.2f, 30);
	noise.genPerlin();

	while (!core.getKInput(SDL_SCANCODE_ESCAPE) && core.run == true)
	{
		core.preMain();
		core.poolInputs();

		mainEngine(core, camera, noise);

		core.postMain();
	}
	return (0);
}