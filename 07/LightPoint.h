#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>

class LightPoint
{
public:
	LightPoint(glm::vec3 _position, glm::vec3 _angles, glm::vec3 _color);
	~LightPoint();

	glm::vec3 postion; //平行光位置不重要
	glm::vec3 direction = glm::vec3(0, 0, 1.0f);
	glm::vec3 angles; //光旋转角
	glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);;

	//点光源不关心旋转

	//衰减
	float constant;
	float linear;
	float quadratic;
};

