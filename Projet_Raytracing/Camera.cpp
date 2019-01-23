#include "Camera.h"
#include "glm/glm.hpp"

Camera::Camera()
{

}
Camera::Camera(glm::vec3 pos, glm::vec3 rot)
{
	position = pos;
	rotation = rot;
}

glm::vec3 Camera::get_position()
{
	return position;
}
glm::vec3 Camera::get_rotation()
{
	return rotation;
}

glm::vec3 Camera::set_position(glm::vec3 pos)
{
	position = pos;
}
glm::vec3 Camera::set_rotation(glm::vec3 rot)
{
	rotation = rot;
}

Camera::~Camera()
{
}
