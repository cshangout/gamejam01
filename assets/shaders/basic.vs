layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTexCoord;
layout (location = 3) in vec3 aNormal;

uniform mat4 u_projection;
uniform mat4 u_view;
uniform mat4 u_model;
uniform mat4 u_inverseNormal;

out vec4 v_Color;
out vec2 TexCoord;
out vec3 Normal;
out vec3 FragPos;

void main()
{
   gl_Position = u_projection * u_view * u_model * vec4(aPos, 1.0);
   v_Color = aColor;
   TexCoord = aTexCoord;
   Normal = mat3(transpose(u_inverseNormal)) * aNormal;
   FragPos = vec3(u_model * vec4(aPos, 1.0));
}