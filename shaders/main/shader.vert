/**
 * @file main/shader.vert
 * @brief Implements a vertex shader for all major calculations of a vertex' color
 * @author D3PSI
 */
#version 330 core
layout(location = 0) in vec3 _pos;


void main() {
    gl_Position = vec4(_pos, 1.0);
}

