#pragma once
#include "GLSLShader.h"

class RenderAxis
{
public:
    RenderAxis(void);
    virtual ~RenderAxis(void);
    void Render(const float* MVP);

    void Init();
    void Destroy();

protected:
    GLuint VertexArrayID[10];
    GLuint vertexbuffer[20];
    float fLineOneColor[6];
    float fLineTwoColor[6];
    float fLineThreeColor[6];

    GLSLShader shader;

};

