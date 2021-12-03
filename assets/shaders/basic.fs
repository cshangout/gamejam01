precision highp float;
out vec4 FragColor;

in vec4 v_Color;
in vec2 TexCoord;
in vec3 FragPos;
in vec3 Normal;

uniform sampler2D baseTexture;
uniform vec3 ambientColor;
uniform float ambientIntensity;
uniform vec3 lightPosition;
uniform vec3 cameraPosition;

void main() {
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPosition - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);

    float specularStrength = 1.f;

    vec3 viewDir = normalize(cameraPosition - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 256.f);

    vec3 specular = specularStrength * spec * ambientColor;
    vec3 diffuse = diff * ambientColor;
    vec3 ambience = ambientColor * ambientIntensity;

    FragColor = texture(baseTexture, TexCoord) * vec4(ambience + diffuse + specular, 1.f);
}