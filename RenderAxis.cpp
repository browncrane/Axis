
#include "RenderAxis.h"
#include <glm/glm.hpp>

RenderAxis::RenderAxis(void)
{

}


RenderAxis::~RenderAxis(void)
{
    Destroy();
}

void RenderAxis::Init() {
    //setup vao and vbo stuff
    glGenVertexArrays(10, VertexArrayID);
    glGenBuffers(18, vertexbuffer);


    //now allocate buffers
//    glBindVertexArray(VertexArrayID);

//        glBindBuffer (GL_ARRAY_BUFFER, vboVerticesID);
//        glBufferData (GL_ARRAY_BUFFER, totalVertices * sizeof(glm::vec3), 0, GL_STATIC_DRAW);

//        GLfloat* pBuffer = static_cast<GLfloat*>(glMapBuffer(GL_ARRAY_BUFFER, GL_WRITE_ONLY));
//            FillVertexBuffer(pBuffer);
//        glUnmapBuffer(GL_ARRAY_BUFFER);

//        glEnableVertexAttribArray(shader["vVertex"]);
//        glVertexAttribPointer(shader["vVertex"], 3, GL_FLOAT, GL_FALSE,0,0);

//        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vboIndicesID);
//        glBufferData(GL_ELEMENT_ARRAY_BUFFER, totalIndices * sizeof(GLuint), 0, GL_STATIC_DRAW);

//        GLuint* pIBuffer = static_cast<GLuint*>(glMapBuffer(GL_ELEMENT_ARRAY_BUFFER, GL_WRITE_ONLY));
//            FillIndexBuffer(pIBuffer);
//        glUnmapBuffer(GL_ELEMENT_ARRAY_BUFFER);

//    glBindVertexArray(0);
}

void RenderAxis::Destroy() {
    //Destroy shader
    shader.DeleteShaderProgram();

    //Destroy vao and vbo
    glDeleteBuffers(20, vertexbuffer);
    glDeleteVertexArrays(10, VertexArrayID);
}


void RenderAxis::Render(const GLfloat* MVP) {
    fLineOneColor[0] = 0.0f; fLineOneColor[1] = 0.0f; fLineOneColor[2] = 1.0f;
    fLineOneColor[3] = 0.0f; fLineOneColor[4] = 0.0f; fLineOneColor[5] = 1.0f;

    fLineTwoColor[0] = 0.0f; fLineTwoColor[1] = 1.0f; fLineTwoColor[2] = 0.0f;
    fLineTwoColor[3] = 0.0f; fLineTwoColor[4] = 1.0f; fLineTwoColor[5] = 0.0f;

    fLineThreeColor[0] = 1.0f; fLineThreeColor[1] = 0.0f; fLineThreeColor[2] = 0.0f;
    fLineThreeColor[3] = 1.0f; fLineThreeColor[4] = 0.0f; fLineThreeColor[5] = 0.0f;

    shader.Use();
        glUniformMatrix4fv(shader("MVP"), 1, GL_FALSE, MVP);
        glBindVertexArray(VertexArrayID[0]);

        static const GLfloat g_vertex_buffer_data[] = {
            0, 0, 0,
             0, 0, 0.5f,
        };
        glGenBuffers(18, vertexbuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[0]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[0]);
        glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
        );
        glDrawArrays(GL_LINES, 0, 2);

        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[9]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(fLineOneColor), fLineOneColor, GL_STATIC_DRAW);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glBindVertexArray(VertexArrayID[1]);

        static const GLfloat vertex_buffer_data[] = {
             0, 0, 0,
             0,  0.5f, 0,
        };

        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[1]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[1]);
        glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
        );
        glDrawArrays(GL_LINES, 0, 2);

        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[10]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(fLineTwoColor), fLineTwoColor, GL_STATIC_DRAW);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glBindVertexArray(VertexArrayID[2]);

        static const GLfloat vertex_buffer_data3[] = {
             0, 0, 0,
             0.5f, 0, 0,
        };

        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[2]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data3), vertex_buffer_data3, GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
    //    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer3);
        glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
        );
        glDrawArrays(GL_LINES, 0, 2);

        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[11]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(fLineThreeColor), fLineThreeColor, GL_STATIC_DRAW);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glBindVertexArray(VertexArrayID[3]);

        static const GLfloat vertex_buffer_data4[] = {
             0.5f, 0, 0,
             0.4f,  0.1f, 0,
        };

        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[3]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data4), vertex_buffer_data4, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
    //    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer4);
        glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
        );
        glDrawArrays(GL_LINES, 0, 2);

        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[12]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(fLineThreeColor), fLineThreeColor, GL_STATIC_DRAW);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glBindVertexArray(VertexArrayID[4]);

        static const GLfloat vertex_buffer_data5[] = {
            0.5f, 0, 0,
            0.4f, -0.1f, 0,
        };

        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[4]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data5), vertex_buffer_data5, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
    //    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer5);
        glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
        );
        glDrawArrays(GL_LINES, 0, 2);

        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[13]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(fLineThreeColor), fLineThreeColor, GL_STATIC_DRAW);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glBindVertexArray(VertexArrayID[5]);

        static const GLfloat vertex_buffer_data6[] = {
            0, 0.5f, 0,
             0.1f,  0.4f, 0,
        };

        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[5]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data6), vertex_buffer_data6, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
    //    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer6);
        glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
        );
        glDrawArrays(GL_LINES, 0, 2);

        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[14]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(fLineTwoColor), fLineTwoColor, GL_STATIC_DRAW);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glBindVertexArray(VertexArrayID[6]);

        static const GLfloat vertex_buffer_data7[] = {
            0, 0.5f, 0,
             -0.1f,  0.4f, 0,
        };

        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[6]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data7), vertex_buffer_data7, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[6]);
        glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
        );
        glDrawArrays(GL_LINES, 0, 2);

        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[15]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(fLineTwoColor), fLineTwoColor, GL_STATIC_DRAW);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glBindVertexArray(VertexArrayID[7]);

        static const GLfloat vertex_buffer_data8[] = {
            0, 0, 0.5f,
             -0.1f, 0, 0.4f,
        };

        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[7]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data8), vertex_buffer_data8, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
    //    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer8);
        glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
        );
        glDrawArrays(GL_LINES, 0, 2);

        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[16]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(fLineOneColor), fLineOneColor, GL_STATIC_DRAW);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

        glBindVertexArray(VertexArrayID[8]);

        static const GLfloat vertex_buffer_data9[] = {
            0, 0, 0.5f,
             0.1f, 0, 0.4f,
        };

        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[8]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data9), vertex_buffer_data9, GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
    //    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer9);
        glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,           // normalized?
            0,                  // stride
            (void*)0            // array buffer offset
        );
        glDrawArrays(GL_LINES, 0, 2);

        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[17]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(fLineOneColor), fLineOneColor, GL_STATIC_DRAW);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

    shader.UnUse();
}
