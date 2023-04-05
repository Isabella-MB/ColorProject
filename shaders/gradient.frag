//A basic gradient shader in the latest version of GLSL that takes in two colors and outputs a gradient between them based on the x coordinate of the texture.

#version 460 core

uniform vec4 startColor;
uniform vec4 endColor;

in vec4 Color;
in vec2 TexCoord;

out vec4 FragColor;

void main()
{
    // lookup the pixel in the texture
    vec4 pixel = mix(startColor, endColor, TexCoord.x);

    // multiply it by the color
    FragColor = vec4(0.5, 0.4, 1.0, 1.0);
}