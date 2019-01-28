#include "vec3.h"
#include <math.h>



vec3::vec3()
{
}

vec3::vec3(float coordx, float coordy, float coordz) {
	x = coordx;
	y = coordy;
	z = coordz;
}

vec3::~vec3()
{
}

float vec3::getx() {
	return x;
}

float vec3::gety() {
	return y;
}

float vec3::getz() {
	return z;
}

vec3 add3(vec3 a, vec3 b) {
	vec3 c = vec3(a.getx() + b.getx(), a.gety() + b.gety(), a.getz() + b.getz());
	return c;
}

vec3 dif3(vec3 a, vec3 b) {
	vec3 c = vec3(a.getx() - b.getx(), a.gety() - b.gety(), a.getz() - b.getz());
	return c;
}

vec3 prod(vec3 vec, float a) {
	vec3 c = vec3(a*vec.getx(), a*vec.gety(), a*vec.getz());
	return c;
}

float prodScal(vec3 a, vec3 b) {
	float c = a.getx() * b.getx() + a.gety() * b.gety() + a.getz() * b.getz();
	return c;
}

vec3 prodVect(vec3 a, vec3 b) {
	vec3 c = vec3(a.gety()*b.getz() - b.gety()*a.getz(), a.getz()*b.getx() - b.getz()*a.getx(), a.getx()*b.gety() - b.getx()*a.gety());
	return c;
}

float norm(vec3 vec) {
	float c = sqrt(pow(vec.getx(), 2) + pow(vec.gety(), 2) + pow(vec.getz(), 2));
	return c;
}

vec3 reflexion(vec3 norm, vec3 vec) {
	vec3 c = dif3(vec, prod(norm, 2 * prodScal(vec, norm)));
	return c;
}

vec3 normalize(vec3 vec) {
	float n = norm(vec);
	vec3 c = vec3(vec.getx() / n, vec.gety() / n, vec.getz() / n);
	return c;
}
