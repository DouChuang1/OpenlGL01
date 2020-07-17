#include <iostream>
using namespace std;
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void processInput(GLFWwindow *window);

int main()
{
	glfwInit();  //≥ı ºªØglfwø‚
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL Window", NULL, NULL);

	if (window == NULL)
	{
		cout << "init window error" << endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);  


	//init glew
	//glewExperimental = GL_TRUE; // π”√”–Œ Ã‚ ◊¢ ÕµÙ
	if (glewInit() != GLEW_OK)
	{
		cout << "glewInit error" << endl;
		glfwTerminate();
		return -1;
	}
	
	glViewport(0, 0, 800, 600);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window); //À´ª∫¥Ê∑¿÷π…¡À∏
		
		processInput(window);
	}
	return 0;
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}