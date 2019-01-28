#include "Camera.h"
#include "vec3.h"
Camera::Camera()
{

}
Camera::Camera(vec3 pos, vec3 rot)
{
	position = pos;
	rotation = rot;
}
Camera::~Camera()
{
}
