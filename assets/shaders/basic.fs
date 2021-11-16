precision highp float;
out vec4 FragColor;

in vec4 v_Color;
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
    FragColor = texture(ourTexture, TexCoord) * v_Color;
}