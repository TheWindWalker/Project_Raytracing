#ifndef SPHERE
#define SPHERE

#include "Object.h"
#include "vec3.h"
#include <vector>

using namespace std;
class Sphere: public Object
{
public:
	/*Variables*/
	float r;
	vec3 pos;
	/*Constructeurs*/
	Sphere();
	Sphere(float posx, float posy, float posz, float rayon);
	/*Polymorphisme*/
	/*Destucteur*/
	virtual ~Sphere();
	virtual void affiche() const;

	/*Fonctions de la classe*/
	vec3 intersect(vec3 ray, vec3 position);
};

#endif