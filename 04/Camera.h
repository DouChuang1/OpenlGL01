#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
	Camera(glm::vec3 position,glm::vec3 target,glm::vec3 worldUp);
	Camera(glm::vec3 position, float pitch, float yaw, glm::vec3 worldUp);
	~Camera();

	glm::vec3 Position;
	glm::vec3 Forward;
	glm::vec3 Right;
	glm::vec3 Up;
	glm::vec3 WorldUp;

	float Yaw;
	float Pitch;

	float senseX=0.01f;
	float senseY = 0.01f;
	float speedZ = 0.0f;
	glm::mat4 GetViewMat();
	void ProcessMoiseMovement(float deltaX, float deltaY);
	void UpdateCameraPos();
private:
	void UpdateCameraVectors();
};