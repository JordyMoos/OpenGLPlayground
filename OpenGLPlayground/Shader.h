#pragma once


#include <GL/glew.h>


class Shader
{
public:
	GLuint Program;


	bool Initialize(const GLchar* vertexPath, const GLchar* fragmentPath);

	void Use();
};

