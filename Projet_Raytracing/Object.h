#pragma once
#include "vec3.h"
class Object
{
public:
	vec3 position, rotation;
	Object();
	Object(vec3 pos, vec3 rot);

	~Object();
};