#version 330 core

in vec3 ourColor;
in vec2 ourTexCoord;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;

out vec4 color;

void main() {
   color = mix(texture(ourTexture1, ourTexCoord), texture(ourTexture2, vec2(1.0f - ourTexCoord.x, ourTexCoord.y)), 0.2);
}