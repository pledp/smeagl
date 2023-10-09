#include "Graphics/Renderer/Renderer.h"
#include "glad/glad.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <string>
#include "Graphics/Renderer/ShaderProgram.h"

const std::string vertexShaderSource =
"#version 330 core\n"
"\n"
"layout(location = 0) in vec3 aPos;"
"\n"
"uniform mat4 model;"
"\n"
"void main() {"
"\n"
"   gl_Position = model * vec4(aPos, 1.0);"
"\n"
"}\n";

const std::string fragmentShaderSource = 
"#version 330 core\n"
"\n"
"layout(location = 0) out vec4 FragColor;"
"\n"
"void main() {"
"\n"
"   FragColor = vec4(1.0, 0.0, 0.0, 1.0);"
"\n"
"}\n";

struct RendererData {
    unsigned int TriVertexArray; 
    unsigned int TriVertexBuffer; 
    unsigned int TriIndicesArray;
    unsigned int TriIndicesBuffer; 

    ShaderProgram Program;

    glm::vec3 TriVertexPosistions[3];
    unsigned int TriIndicesPosistions[3];
};

static RendererData s_Data;

void Renderer::Init() {
    s_Data.Program.CreateProgram(vertexShaderSource, fragmentShaderSource);
    s_Data.Program.BindProgram();

    glGenVertexArrays(1, &s_Data.TriVertexArray);
    glBindVertexArray(s_Data.TriVertexArray);

    s_Data.TriVertexPosistions[0] = { -0.5f, -0.5f, 0.0f }; 
    s_Data.TriVertexPosistions[1] = { 0.5f, -0.5f, 0.0f }; 
    s_Data.TriVertexPosistions[2] = { 0.0f, 0.5f, 0.0f }; 
    s_Data.TriIndicesPosistions[0] = 0;
    s_Data.TriIndicesPosistions[1] = 1;
    s_Data.TriIndicesPosistions[2] = 2;

    glGenBuffers(1, &s_Data.TriVertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, s_Data.TriVertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, 3*sizeof(glm::vec3), s_Data.TriVertexPosistions, GL_STATIC_DRAW);

    glGenBuffers(1, &s_Data.TriIndicesBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, s_Data.TriIndicesBuffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 3*sizeof(glm::vec3), s_Data.TriIndicesPosistions, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Renderer::DrawTri(pledGL::Vector3 pos) {
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(pos.x, pos.y, pos.z));

    s_Data.Program.UploadUniformMat4("model", model);
    
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
}

void Renderer::ClearScreen() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::flush() {
    
}