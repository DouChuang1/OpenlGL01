#pragma once
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
	Shader(const char* vertextPath, const char* fragmentPath);
	std::string vertexString;
	std::string fragmentStrimg;
	const char* vertexSource;
	const char* fragmentSource;

	unsigned int ID; //shader program id

	void SetUniform3f(const char* paramNameString, glm::vec3 param);

	void SetUniform1f(const char* paramNameString, float param);
	void Use();
private:
	void checkComplieErrors(unsigned int ID, std::string type);
};