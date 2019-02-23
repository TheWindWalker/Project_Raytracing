#ifndef OBJ
#define OBJ
#include "vec3.h"
#include <iostream>
#include <string>

using namespace std;
class Object
{
public:
	/*Variables publiques*/
	vec3 position, rotation;
	int materials=0;

	/*Constructeurs*/
	Object();
	Object(vec3 pos, vec3 rot);
	Object(vec3 pos, vec3 rot, int material);
	/*Polymorphisme*/

	/*Destructeur*/
	virtual ~Object();
	/*Affiche le type*/
	virtual void affiche() const;
	virtual vec3 intersect(vec3 ray, vec3 position);
	virtual void print_value_xyz();
};

#endif