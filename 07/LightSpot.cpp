#include "LightSpot.h"



LightSpot::LightSpot(glm::vec3 _position, glm::vec3 _angles, glm::vec3 _color) :
	postion(_position),
	angles(_angles),
	color(_color)
{
	UpdateDirection();
}


LightSpot::~LightSpot()
{
}
