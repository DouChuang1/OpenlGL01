#version 330 core
in vec3 FragPos;
in vec3 Normal;
out vec4 FragColor;

struct Materail
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float shininess;
};

uniform Materail materail;

uniform vec3 objColor;
uniform vec3 ambientColor;
uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 cameraPos;
void main()
{ 
   vec3 lightDir = normalize(lightPos-FragPos);
   float diff = max(dot(lightDir,Normal),0);
   vec3 diffuse = materail.diffuse*diff*lightColor;

   	vec3 reflrctVec = reflect(-lightDir,Normal);
	vec3 cameraVec = normalize(cameraPos-FragPos);
	float specularAmount = pow(max(dot(reflrctVec,cameraVec),0),materail.shininess);
	vec3 specular = materail.specular*specularAmount*lightColor;

	vec3 ambient = materail.ambient*ambientColor;

   //FragColor = vec4(objColor*ambientColor,1.0f);
   FragColor = vec4((diffuse+ambientColor+specular)*objColor,1.0f);
}