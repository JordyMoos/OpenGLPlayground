#version 330 core

in vec3 ourColor;
in vec2 textureCoord;

out vec4 color;

uniform sampler2D ourTexture;

void main()
{
	color = texture(ourTexture, textureCoord) * vec4(ourColor, 1.0f);
}
