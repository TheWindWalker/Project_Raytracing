#include "Sphere.h"
#include "vec3.h"
#include "Object.h"

Sphere::Sphere()
{
	vec3 pos = vec3(0.0f,0.0f,0.0,f);
}
Sphere::Sphere(Object(vec3 pos, vec3 rot), float diam)
{
	diameter = diam;
}
Sphere::Sphere(Object(vec3 pos, vec3 rot, int material), float diam)
{
	diameter = diam;
}


Sphere::~Sphere()
{
}
