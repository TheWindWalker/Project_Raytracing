#ifndef TRI
#define TRI

#include "vec3.h"
#include <vector>

using namespace std;
class Triangle
{
public:
	vec3 position, rotation; //Position du centre du triangle et du centre de rotation du triangle
	vector<vec3> vertices;
	int materials;
	Triangle();
	~Triangle();
};

#endif