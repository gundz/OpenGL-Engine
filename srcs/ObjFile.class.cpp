#include <ObjFile.class.hpp>


void
ObjFile::loadObj(std::string path)
{
	std::ifstream			file(path.c_str(), std::ios::in);
	std::string				line;

	std::string				s;
	float					x, y, z;
	std::string				s1, s2, s3;
	if (file)
	{
		while (std::getline(file, line))
		{
			std::stringstream		issV(line);
			
			if (issV >> s >> x >> y >> z)
			{
				if (s == "v")
				{
					insertVertex(Vec3f(x, y, z));
				}
			}

			std::stringstream		issF(line);
			if (issF >> s >> s1 >> s2 >> s3)
			{
				if (s == "f")
				{
					insertFace(Vec3i(
							atoi(s1.c_str()), 
							atoi(s2.c_str()), 
							atoi(s3.c_str())
							));
				}
			}
		}

		file.close();
	}
	else
		std::cerr << "Unable to open : " << path << std::endl;
}