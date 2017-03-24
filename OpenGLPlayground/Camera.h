#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


enum CameraMovement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};


class Camera
{
public:
	static const GLfloat DEFAULT_YAW;
	static const GLfloat DEFAULT_PITCH;
	static const GLfloat DEFAULT_SPEED;
	static const GLfloat DEFAULT_SENSITIVITY;
	static const GLfloat DEFAULT_ZOOM;

public:
	// Camera Attributes
	glm::vec3 Position;
	glm::vec3 Front;
	glm::vec3 Up;
	glm::vec3 Right;
	glm::vec3 WorldUp;

	// Eular Angles
	GLfloat Yaw;
	GLfloat Pitch;
	
	// Camera options
	GLfloat MovementSpeed;
	GLfloat MouseSensitivity;
	GLfloat Zoom;

	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), GLfloat yaw = DEFAULT_YAW, GLfloat pitch = DEFAULT_PITCH);
};

