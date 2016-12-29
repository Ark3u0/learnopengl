#version 330 core

in vec3 ourColor;
in vec2 ourTexCoord;

uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;

uniform float mixValue;

out vec4 color;

void main() {
   color = mix(texture(ourTexture1, ourTexCoord), texture(ourTexture2, ourTexCoord), mixValue);
}