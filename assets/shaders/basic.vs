layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 u_projection;
uniform mat4 u_view;
uniform mat4 u_model;

out vec4 v_Color;
out vec2 TexCoord;

void main()
{
   gl_Position = u_projection * u_view * u_model * vec4(aPos, 1.0);
   v_Color = aColor;
   TexCoord = aTexCoord;
}