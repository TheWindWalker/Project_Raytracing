#ifndef SPHERE
#define SPHERE

#include "Object.h"
#include "vec3.h"
#include <vector>
using namespace std;
class Sphere: public Object
{
public:
	float r;
	vec3 pos;
	Sphere();
	Sphere(float posx, float posy, float posz, float rayon);
	~Sphere();

	vec3 intersect(vec3 ray);
};

#endif