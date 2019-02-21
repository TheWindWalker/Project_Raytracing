#ifndef OBJ
#define OBJ

#include "vec3.h"
class Object
{
public:
	vec3 position, rotation;
	int materials=0;
	Object();
	Object(vec3 pos, vec3 rot);
	Object(vec3 pos, vec3 rot, int material);

	~Object();

	vec3 intersect(vec3 ray, vec3 position);
};

#endif