#include "LightSource.h"
#include "vec3.h"


LightSource::LightSource()
{
}
LightSource::LightSource(int redlight, int greenlight, int bluelight)
{
	red = redlight;
	green = greenlight;
	blue = bluelight;
}

LightSource::~LightSource()
{
}
