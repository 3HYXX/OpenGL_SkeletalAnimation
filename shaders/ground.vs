#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoord;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

out vec2 TexCoord;

void main()
{
    vec4 pos = projection * view * model * vec4(aPos, 1.0);
    gl_Position = pos;
    TexCoord = aTexCoord;
}  