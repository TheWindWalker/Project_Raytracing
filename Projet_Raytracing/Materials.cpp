#include "Materials.h"



Materials::Materials()
{
}

Materials::Materials(int material_red, int material_green, int material_blue, int material_reflection)
{
	red = material_red;
	green = material_green;
	blue = material_blue;
	reflection = material_reflection;
}
Materials::~Materials()
{
}
