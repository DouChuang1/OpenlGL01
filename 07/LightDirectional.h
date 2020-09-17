#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>

class LightDirectional
{
public:
	LightDirectional(glm::vec3 _position, glm::vec3 _angles, glm::vec3 _color);
	~LightDirectional();

	glm::vec3 postion; //平行光位置不重要
	glm::vec3 direction = glm::vec3(0, 0, 1.0f);
	glm::vec3 angles; //光旋转角
	glm::vec3 color=glm::vec3(1.0f,1.0f, 1.0f);;

	void UpdateDirection()
	{
		//glm旋转方法根据 angles算出direction
		direction = glm::vec3(0, 0, 1.0f);
		direction = glm::rotateZ(direction, angles.z);
		direction = glm::rotateX(direction, angles.x);
		direction = glm::rotateY(direction, angles.y);
		direction = -1.0f*direction;
	}
};

