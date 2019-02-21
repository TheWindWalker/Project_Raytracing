#include "LightSource.h"
#include "vec3.h"


LightSource::LightSource()
{
}
LightSource::LightSource(int redlight, int greenlight, int bluelight, vec3 position)
{
	red = redlight;
	green = greenlight;
	blue = bluelight;
	pos = position;
}

LightSource::~LightSource()
{
}

vec3 LightSource::shadowray(vec3 point) {
	return dif3(pos, point);
}
