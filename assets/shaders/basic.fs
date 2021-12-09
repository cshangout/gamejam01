precision highp float;

// structs
struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
    float reflectivity;
};

struct Light {
    vec3 position;
    vec3 ambientColor;
    vec3 diffuseColor;
    vec3 specularColor;
};

out vec4 FragColor;

in vec4 v_Color;
in vec2 TexCoord;
in vec3 FragPos;
in vec3 Normal;

uniform sampler2D baseTexture;
uniform samplerCube skyboxTexture;

uniform Light light;
uniform Material material;

uniform vec3 cameraPosition;

void main() {
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);

    vec3 viewDir = normalize(FragPos - cameraPosition);
    vec3 reflectDir = reflect(lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);

    vec3 specular = (material.specular * spec) * light.specularColor;
    vec3 diffuse = (diff * material.diffuse) * light.diffuseColor;
    vec3 ambience = material.ambient * light.ambientColor;

    vec3 R = reflect(viewDir, normalize(Normal));
    vec4 albedo = (texture(baseTexture, TexCoord)) + (texture(skyboxTexture, R) * material.reflectivity);
//* (1 - material.reflectivity)
//    vec4 albedo = texture(baseTexture, TexCoord);

    FragColor = albedo * vec4(ambience + diffuse + specular, 1.f);


}