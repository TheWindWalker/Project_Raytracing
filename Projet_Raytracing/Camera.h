#pragma once
#include "vec3.h"
class Camera
{
	public:
	vec3 position, rotation;
	float focale = 1;
	int sizex = 600, sizey = 400;
	Camera();
	Camera(vec3 pos, vec3 rot);
	~Camera();

	private:

};

