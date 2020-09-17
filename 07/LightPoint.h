#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/rotate_vector.hpp>

class LightPoint
{
public:
	LightPoint(glm::vec3 _position, glm::vec3 _angles, glm::vec3 _color);
	~LightPoint();

	glm::vec3 postion; //ƽ�й�λ�ò���Ҫ
	glm::vec3 direction = glm::vec3(0, 0, 1.0f);
	glm::vec3 angles; //����ת��
	glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);;

	//���Դ��������ת

	//˥��
	float constant;
	float linear;
	float quadratic;
};

