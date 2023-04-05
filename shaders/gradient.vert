/// <summary>
/// Vertex Shader in GLSL
/// </summary>

#version 460 core

layout(location = 0) in vec3 Position;
layout(location = 1) in vec2 VertTexCoord;

out vec2 TexCoord;
out vec4 Color;

void main()
{
    // transform the texture coordinates
    TexCoord = vec2(VertTexCoord.x, VertTexCoord.y);

    Color = vec4(1.0, 1.0, 1.0, 1.0);
}