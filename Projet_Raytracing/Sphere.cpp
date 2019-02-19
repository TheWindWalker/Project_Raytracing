#include "Sphere.h"
#include "vec3.h"


Sphere::Sphere()
{
}

Sphere::Sphere(float posx, float posy, float posz, float rayon) {
	pos = vec3(posx, posy, posz);
	r = rayon;
}

Sphere::~Sphere()
{
}

vec3 Sphere::intersect(vec3 ray) {

}
