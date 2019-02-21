#include "Sphere.h"
#include "vec3.h"
#include "Object.h"

/*Constructeurs*/
Sphere::Sphere()
{
	vec3 pos = vec3(0.0f,0.0f,0.0f);
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

/*Fonctions de la classe*/

vec3 Sphere::intersect(vec3 ray, vec3 position) {
	bool inter = false;
	float i = 0.001;
	vec3 point = vec3(-1, -1, -1);
	while (i < 50 && inter == false) {
		if (norm(dif3(add3(position, prod(ray, i)), pos)) <= r) {
			inter = true;
			point = add3(position, prod(ray, i));
		}
		i += 0.001;
	}
	return point;
}
