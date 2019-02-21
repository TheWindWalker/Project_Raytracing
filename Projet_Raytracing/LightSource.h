#ifndef LS
#define LS

#include "vec3.h"
class LightSource
{
public:
	int red, green, blue;
	vec3 pos;
	LightSource();
	LightSource(int redlight, int greenlight, int bluelight, vec3 position);
	~LightSource();

	vec3 shadowray(vec3 point);
};

#endif