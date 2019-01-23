#pragma once
#include "glm/glm.hpp"
class Camera
{
	public:

	Camera();
	Camera(glm::vec3 pos, glm::vec3 rot);
	glm::vec3 get_position();
	glm::vec3 get_rotation();
	glm::vec3 set_position(glm::vec3 pos);
	glm::vec3 set_rotation(glm::vec3 rot);
	~Camera();

	private:

	glm::vec3 position;
	glm::vec3 rotation;
};

