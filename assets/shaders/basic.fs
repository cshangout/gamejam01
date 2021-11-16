precision highp float;
out vec4 FragColor;

in vec4 v_Color;
in vec2 TexCoord;

uniform sampler2D baseTexture;
uniform sampler2D smileTexture;

void main() {
    FragColor = mix(texture(baseTexture, TexCoord), texture(smileTexture, TexCoord), 0.25) * v_Color;
}