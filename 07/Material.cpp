#include "Material.h"



Material::Material(Shader * _shader, glm::vec3 _ambient, unsigned int _diffuse, unsigned int _specualr, float _shininess)
{
	shader = _shader;
	ambient = _ambient;
	diffuse = _diffuse;
	specular = _specualr;
	shininess = _shininess;
}

Material::~Material()
{
}
