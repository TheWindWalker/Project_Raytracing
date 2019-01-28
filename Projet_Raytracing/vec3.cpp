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


vec3 add3(vec3 a, vec3 b) {
	vec3 c = vec3(a.x + b.x, a.y + b.y, a.z + b.z);
	return c;
}

vec3 dif3(vec3 a, vec3 b) {
	vec3 c = vec3(a.x - b.x, a.y - b.y, a.z - b.z);
	return c;
}

vec3 prod(vec3 vec, float a) {
	vec3 c = vec3(a*vec.x, a*vec.y, a*vec.z);
	return c;
}

float prodScal(vec3 a, vec3 b) {
	float c = a.x * b.x + a.y * b.y + a.z * b.z;
	return c;
}

vec3 prodVect(vec3 a, vec3 b) {
	vec3 c = vec3(a.y*b.z - b.y*a.z, a.z*b.x - b.z*a.x, a.x*b.y - b.x*a.y);
	return c;
}

float norm(vec3 vec) {
	float c = sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
	return c;
}

vec3 reflexion(vec3 norm, vec3 vec) {
	vec3 c = dif3(vec, prod(norm, 2 * prodScal(vec, norm)));
	return c;
}

vec3 normalize(vec3 vec) {
	float n = norm(vec);
	vec3 c = vec3(vec.x / n, vec.y / n, vec.z / n);
	return c;
}
