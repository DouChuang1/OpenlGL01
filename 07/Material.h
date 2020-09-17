#pragma once

#include "Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Material
{
public:
	glm::vec3 ambient;
	unsigned int diffuse;
	unsigned int specular;
	float shininess;
	Shader *shader;

	Material(Shader* _shader, glm::vec3 _ambient, unsigned int _diffuse, unsigned int _specualr,float _shininess);
	~Material();
};

