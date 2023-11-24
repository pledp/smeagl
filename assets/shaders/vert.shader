#version 330 core

layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 aTexCoord;
layout(location = 3) in float aTexIndex;

out vec3 color;
out vec2 TexCoord;
out float TexIndex;

void main() {

   gl_Position = vec4(aPos, 1.0);
   color = aColor;
   TexCoord = aTexCoord;
   TexIndex = aTexIndex;
}