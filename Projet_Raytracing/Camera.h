#pragma once
#include "vec3.h"
class Camera
{
	public:
	vec3 position, rotation;
	Camera();
	Camera(vec3 pos, vec3 rot);
	~Camera();

	private:

};

