#ifndef CUBE
#define CUBE

#include <iostream>
#include <string>
#include "Object.h"
#include "vec3.h"

class Cube : public Object
{
public:
	/*Variables*/
	
	/*Constructeurs*/
	Cube();
	Cube(Object(vec3 pos, vec3 rot), float diam);
	Cube(Object(vec3 pos, vec3 rot, int material), float diam);
	/*Polymorphisme*/
	/*Destructeur*/
	virtual ~Cube();
	virtual void affiche() const;
	/*Fonctions de la classe*/
};

#endif