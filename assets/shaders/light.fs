precision highp float;

struct Light {
    vec3 position;
    vec3 ambientColor;
    vec3 diffuseColor;
    vec3 specularColor;
};

out vec4 FragColor;

in vec4 v_Color;
in vec2 TexCoord;

uniform sampler2D baseTexture;
uniform Light light;

void main() {
    FragColor = texture(baseTexture, TexCoord) * v_Color * vec4(light.diffuseColor, 1.f);
}