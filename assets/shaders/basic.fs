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

void main() {
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPosition - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);

    vec3 diffuse = diff * ambientColor;
    vec3 ambience = ambientColor * ambientIntensity;

    FragColor = texture(baseTexture, TexCoord) * vec4(ambience + diffuse, 1.f);
}