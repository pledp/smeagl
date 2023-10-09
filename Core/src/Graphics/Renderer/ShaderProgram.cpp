#include "Graphics/Renderer/ShaderProgram.h"
#include <string>
#include <memory>
#include <iostream>

// Creates a program for openGL
void ShaderProgram::CreateProgram(const std::string& vertSource, const std::string& fragSource) {
    uint32_t program = glCreateProgram();
    uint32_t vertShader = createShader(vertSource, GL_VERTEX_SHADER);
    uint32_t fragShader = createShader(fragSource, GL_FRAGMENT_SHADER);

    glAttachShader(program, vertShader);
    glAttachShader(program, fragShader);

    glLinkProgram(program);

    mProgramID = program;
}

// Creates a shader
uint32_t ShaderProgram::createShader(const std::string& source, GLenum shaderType) {
    uint32_t id = glCreateShader(shaderType);
    const char* src = source.c_str();

    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    return id;
}

void ShaderProgram::BindProgram() {
    glUseProgram(mProgramID);
}

void ShaderProgram::UploadUniformMat4(const std::string& name, const glm::mat4 matrix) {
    GLint location = glGetUniformLocation(mProgramID, name.c_str());
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}
