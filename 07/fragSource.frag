#version 330 core
in vec3 FragPos;
in vec3 Normal;
in vec2 texcoord;
out vec4 FragColor;

struct Materail
{
	vec3 ambient;
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
};

uniform Materail materail;

uniform vec3 objColor;
uniform vec3 ambientColor;
uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 cameraPos;
uniform vec3 lightDirUniform;

struct LigthPoint
{
	float constant;
	float linear;
	float quadratic;
};

uniform LigthPoint lightPoint;

struct LightSpot
{
	float cosInnerPhy;
	float cosOutterPhy;
};
uniform LightSpot lightSpot;

void main()
{ 
	float dist = length(lightPos - FragPos);
	float attenuation = 1.0f / (lightPoint.constant + lightPoint.linear*dist +lightPoint.quadratic*(dist*dist));
    vec3 lightDir = normalize(lightPos-FragPos);
    float diff = max(dot(lightDir,Normal),0);
    vec3 diffuse = texture(materail.diffuse,texcoord).rgb*diff*lightColor;

   	vec3 reflrctVec = reflect(-lightDir,Normal);
	vec3 cameraVec = normalize(cameraPos-FragPos);
	float specularAmount = pow(max(dot(reflrctVec,cameraVec),0),materail.shininess);
	vec3 specular = texture(materail.specular,texcoord).rgb*specularAmount*lightColor;

	vec3 ambient = texture(materail.diffuse,texcoord).rgb*ambientColor;

    //FragColor = vec4(objColor*ambientColor,1.0f);
   // FragColor = vec4((ambientColor+(diffuse+specular)*attenuation),1.0f);

	float cosTheta = dot(normalize(FragPos-lightPos),-lightDirUniform);
	float ratio;
	if(cosTheta>lightSpot.cosInnerPhy)
	{
		ratio = 1.0f;
	}
	else if(cosTheta>lightSpot.cosOutterPhy)
	{
		 ratio = 1-(cosTheta-lightSpot.cosInnerPhy)/(lightSpot.cosOutterPhy-lightSpot.cosInnerPhy);
	}
	else
	{
		ratio = 0.0f;
	}

	FragColor = vec4((ambientColor+(diffuse+specular)*ratio),1.0f);
}