#include "object.h"
#include "vec3.h"

Object::Object()
{
}

Object::Object(vec3 pos, vec3 rot)
{
	position = pos;
	rotation = rot;
}
Object::Object(vec3 pos, vec3 rot, int material)
{
	position = pos;
	rotation = rot;
	materials=material
}

Object::~Object()
{
}
