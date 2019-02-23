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
	materials = material;
}

void Object::print_value_xyz()
{
	std::cout << "X: " << position.x << " Y: " << position.y << " Z: " << position.z;
}



void Object::affiche() const
{
	std::cout<<"Object_pur" << "\n";
}

Object::~Object()
{
}

vec3 Object::intersect(vec3 ray, vec3 position) {
	return vec3(-1, -1, -1);
}