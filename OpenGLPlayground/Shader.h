#pragma once


#include <GL/glew.h>


class Shader
{
private:

	GLuint Program;


public:

	bool Initialize(const GLchar* vertexPath, const GLchar* fragmentPath);

	void Use();

	const GLuint GetProgram() const
	{
		return Program;
	}
};

