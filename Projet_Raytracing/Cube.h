#pragma once
#include "Object.h"
#include "vec3.h"
class Cube : public Object
{
public:
	
	Cube();
	Cube(Object(vec3 pos, vec3 rot), float diam);
	Cube(Object(vec3 pos, vec3 rot, int material), float diam);
	Cube();
	~Cube();
};

