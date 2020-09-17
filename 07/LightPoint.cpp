#include "LightPoint.h"



LightPoint::LightPoint(glm::vec3 _position, glm::vec3 _angles, glm::vec3 _color) :
	postion(_position),
	angles(_angles),
	color(_color)
{
	//不需要旋转
	constant = 1.0f;
	linear = 0.09f;
	quadratic = 0.032f;
}


LightPoint::~LightPoint()
{
}
