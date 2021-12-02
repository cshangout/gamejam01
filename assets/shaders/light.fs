precision highp float;
out vec4 FragColor;

in vec4 v_Color;
in vec2 TexCoord;

uniform sampler2D baseTexture;

void main() {
    FragColor = texture(baseTexture, TexCoord) * v_Color;
}