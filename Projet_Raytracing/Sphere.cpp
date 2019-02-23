#include "Sphere.h"
#include "vec3.h"
#include "Object.h"

/*Constructeurs*/
Sphere::Sphere()
{
	pos = vec3(0.0f,0.0f,0.0f);
}

Sphere::Sphere(float posx, float posy, float posz, float rayon) {
	pos = vec3(posx, posy, posz);
	r = rayon;
}

/*Destructeur*/
Sphere::~Sphere()
{
}

void Sphere::affiche() const
{
	std::cout << "Sphere" << "\n";
}

void Sphere::print_value_xyz()
{
	std::cout << "X: "<< pos.x << " Y: "<<pos.y << " Z: " << pos.z << " R: "<< r;
}

/*Fonctions de la classe*/

vec3 Sphere::intersect(vec3 ray, vec3 position) {
	float i = -30.0;
	vec3 point = vec3(-1, -1, -1);
	while (i < 30) {
		if (norm(dif3(add3(position, prod(ray, i)), pos)) <= r) {
			point = add3(position, prod(ray, i));
			break;
		}
		i += 0.1;
	}
	return point;
}
