#include "Camera.h"
#include "vec3.h"
Camera::Camera()
{

}
Camera::Camera(vec3 pos, vec3 dir, vec3 axeverti = vec3(0, 0, 1))
{
	position = pos;
	direction = normalize(dir);
	horiz = normalize(prodVect(dir, axeverti));
	verti = normalize(axeverti);

}
Camera::~Camera()
{
}
