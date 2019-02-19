#pragma once
#include "Object.h"
#include "vec3.h"
#include <vector>

using namespace std;

class Sphere: public Object
{
public:
	float diameter=1;
	Sphere();
	Sphere(Object(vec3 pos, vec3 rot),float diam);
	Sphere(Object(vec3 pos, vec3 rot, int material), float diam);
	~Sphere();
};

