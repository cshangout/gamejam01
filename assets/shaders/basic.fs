precision highp float;

// structs
struct Material {
    sampler2D diffuse;
    sampler2D specular;
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

uniform samplerCube skyboxTexture;

uniform Light light;
uniform Material material;

uniform vec3 cameraPosition;

void main() {
    float clampShininess = clamp(material.shininess, 0, 1.0);

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(light.position - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);

    vec3 viewDir = normalize(FragPos - cameraPosition);
    vec3 reflectDir = reflect(lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), clamp(clampShininess * 128.0, 1.0, 128.0));

    vec3 R = reflect(viewDir, normalize(Normal));
    vec4 albedo = texture(material.diffuse, TexCoord);

    vec3 reflection = vec3(mix(texture(material.diffuse, TexCoord), texture(skyboxTexture, R), clampShininess));
    reflection = reflection * vec3(texture(material.specular, TexCoord));

    vec3 specular = (vec3(texture(material.specular, TexCoord)) * spec) * light.specularColor;
    vec3 diffuse = (diff * vec3(albedo)) * light.diffuseColor;
    vec3 ambience = vec3(albedo) * light.ambientColor;

    FragColor = vec4(ambience + diffuse + specular + reflection, 1.f);
}