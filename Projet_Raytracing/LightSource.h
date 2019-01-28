#pragma once
#include "vec3.h"
class LightSource
{
public:
	int red, green, blue;
	LightSource();
	LightSource(int redlight, int greenlight, int bluelight);
	~LightSource();
};

