#version 330 core

in vec3 color;
in vec2 TexCoord;
in float TexIndex;

uniform sampler2D u_Textures[2];

layout(location = 0) out vec4 FragColor;

void main() {

   int index = int(TexIndex);
   vec2 st = gl_FragCoord.xy / vec2(800, 600);
   FragColor = texture(u_Textures[index], TexCoord) * vec4(color, 1.0);
}