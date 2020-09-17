#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexcoord;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projectionMat;
out vec3 FragPos;
out vec3 Normal;
out vec2 texcoord;
void main()
{
	gl_Position =projectionMat *viewMat*modelMat* vec4(aPos.xyz, 1.0);
	FragPos = (modelMat*vec4(aPos.xyz,1.0)).xyz;
	Normal = mat3(transpose(inverse(modelMat))) * aNormal;
	texcoord = aTexcoord;
}