#include "Material.h"



Material::Material(Shader * _shader, glm::vec3 _ambient, glm::vec3 _diffuse, glm::vec3 _specualr, float _shininess)
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
