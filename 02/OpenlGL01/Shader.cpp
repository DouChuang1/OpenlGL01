#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
using namespace std;

Shader::Shader(const char* vertextPath,const char* fragmentPath )
{
	ifstream vertexFile;
	ifstream fragmentFile;

	vertexFile.open(vertextPath);
	fragmentFile.open(fragmentPath);
	stringstream vertexSStream;
	stringstream fragmentSStream;

	vertexFile.exceptions(ifstream::failbit || ifstream::badbit);
	fragmentFile.exceptions(ifstream::failbit || ifstream::badbit);
	try
	{
		if (!vertexFile.is_open() || !fragmentFile.is_open())
		{
			throw exception("open file error");
		}
		vertexSStream << vertexFile.rdbuf();
		fragmentSStream << fragmentFile.rdbuf();

		vertexString = vertexSStream.str();
		fragmentStrimg = fragmentSStream.str();

		vertexSource = vertexString.c_str();
		fragmentSource = fragmentStrimg.c_str();

		unsigned vertex, frag;
		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vertexSource, NULL);
		glCompileShader(vertex);
		checkComplieErrors(vertex, "VERTEX");

		frag = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(frag, 1, &fragmentSource, NULL);
		glCompileShader(frag);
		checkComplieErrors(frag, "FRAGMENT");

		ID = glCreateProgram();
		glAttachShader(ID, vertex);
		glAttachShader(ID, frag);

		glLinkProgram(ID);
		checkComplieErrors(ID, "PROGRAM");
		glDeleteShader(vertex);
		glDeleteShader(frag);
	}
	catch (const std::exception& ex)
	{
		printf(ex.what());
	}
}

void Shader::Use()
{
	glUseProgram(ID);
}
void Shader::checkComplieErrors(unsigned int ID, std::string type)
{
	int success;
	char infoLog[512];

	if (type != "PROGRAM")
	{
		glGetShaderInfoLog(ID, 512, NULL, infoLog);
		cout << "shader complie error:" << infoLog << endl;
	}
	else
	{
		glGetProgramiv(ID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(ID, 512, NULL, infoLog);
			cout << "shader link error:" << infoLog << endl;
		}
		
	}
}