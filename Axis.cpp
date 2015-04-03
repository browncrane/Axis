#include "Axis.h"
#include <glm/glm.hpp>

Axis::Axis()
{

    //setup shader
    shader.LoadFromFile(GL_VERTEX_SHADER, "shaders/TransformVertexShader.vertexshader");
    shader.LoadFromFile(GL_FRAGMENT_SHADER, "shaders/ColorFragmentShader.fragmentshader");
    shader.CreateAndLinkProgram();
    shader.Use();
        shader.AddAttribute("vertexPosition_modelspace");
        shader.AddUniform("MVP");
    shader.UnUse();

    Init();
}


Axis::~Axis(void)
{

}
