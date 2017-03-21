#define GLEW_STATIC

#include <stdio.h>
#include <math.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Shader.h"


GLFWwindow* window = nullptr;
const GLuint WIDTH = 800;
const GLuint HEIGHT = 600;


void keyCallback(GLFWwindow*, int key, int scancode, int action, int mode);


int main(int argc, char* args[])
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr)
	{
		printf("Failed to create GLFW window\n");
		glfwTerminate();
		return -1;
	}

	glfwSetKeyCallback(window, keyCallback);
	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		printf("Failed to initialize GLEW");
		glfwTerminate();
		return -1;
	}
	
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	// Setup the vertex data, buffers and attribute pointers
	GLfloat vertices[] = {
		// Positions			// Colors
		 0.5f, -0.5f, 0.0f,		1.0f, 0.0f, 0.0f,   // Bottom Right
		-0.5f, -0.5f, 0.0f,		0.0f, 1.0f, 0.0f,   // Bottom Left
		 0.0f,  0.5f, 0.0f,		0.0f, 0.0f, 1.0f    // Top 
	};
	GLuint indices[] = {
		0, 1, 2
	};
	GLfloat texCoords[] = {
		0.0f, 0.0f, // Lower left
		1.0f, 0.0f, // Lower right
		0.5f, 1.0f  // Top center
	};
	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Bind the Vertex Array Object first, then bind and set vertex buffers and attribute pointers
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0); // Unbind VAO

	Shader shader;
	if (!shader.Initialize("./vertex.vs", "./fragment.frag"))
	{
		printf("Out shader failed\n");
		return -1;
	}

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		// Clear the colorbuffer
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.Use();

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		glfwSwapBuffers(window);
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	glfwTerminate();

	return 0;
}


void keyCallback(GLFWwindow*, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}


