#pragma once
#include <string>

class Shader
{
public:
	Shader(const char* vertextPath, const char* fragmentPath);
	std::string vertexString;
	std::string fragmentStrimg;
	const char* vertexSource;
	const char* fragmentSource;

	unsigned int ID; //shader program id

	void Use();
private:
	void checkComplieErrors(unsigned int ID, std::string type);
};