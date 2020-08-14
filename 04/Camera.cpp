#include "Camera.h"


Camera::Camera(glm::vec3 position, glm::vec3 target, glm::vec3 worldUp)
{
	Position = position;
	Forward = glm::normalize(target - position);
	WorldUp = worldUp;
	Right = glm::normalize(glm::cross(Forward, worldUp));
	Up = glm::normalize(glm::cross(Forward, Right));

}

Camera::Camera(glm::vec3 position, float pitch, float yaw, glm::vec3 worldUp)
{
	Position = position;
	WorldUp = worldUp;
	Yaw = yaw;
	Pitch = pitch;
	Forward.x = glm::cos(pitch)*glm::sin(yaw);
	Forward.y = glm::sin(pitch);
	Forward.z = glm::cos(pitch)*glm::cos(yaw);
	Right = glm::normalize(glm::cross(Forward, worldUp));
	Up = glm::normalize(glm::cross(Forward, Right));
}

glm::mat4 Camera::GetViewMat()
{
	return glm::lookAt(Position, Position + Forward, WorldUp);
}

Camera::~Camera()
{
	
}

void Camera::UpdateCameraVectors()
{
	Forward.x = glm::cos(Yaw)*glm::sin(Yaw);
	Forward.y = glm::sin(Pitch);
	Forward.z = glm::cos(Pitch)*glm::cos(Yaw);
	Right = glm::normalize(glm::cross(Forward, WorldUp));
	Up = glm::normalize(glm::cross(Forward, Right));
}

void Camera::ProcessMoiseMovement(float deltaX, float deltaY)
{
	Pitch -= deltaY* senseX;
	Yaw -= deltaX* senseY;

	UpdateCameraVectors();
}

void Camera::UpdateCameraPos()
{
	Position += Forward*speedZ*0.1f;
}