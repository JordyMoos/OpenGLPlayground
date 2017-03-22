#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 textCoord;

out vec3 ourColor;
out vec2 textureCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	gl_Position = projection * view * model * vec4(position, 1.0f);
	textureCoord = vec2(textCoord.x, 1.0f - textCoord.y);
}
