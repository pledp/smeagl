#include "Graphics/Renderer/ShaderProgram.h"
#include <string>
#include <fstream>
#include <sstream>
#include <memory>
#include <iostream>

// Creates a program (Application that runs on the GPU, in this case with our shaders)
void ShaderProgram::CreateProgram(const std::string& vertPath, const std::string& fragPath) {
    uint32_t program = glCreateProgram();
    std::string vertSource = getShaderFromPath(vertPath);
    std::string fragSource = getShaderFromPath(fragPath);

    uint32_t vertShader = createShader(vertSource, GL_VERTEX_SHADER);
    uint32_t fragShader = createShader(fragSource, GL_FRAGMENT_SHADER);

    glAttachShader(program, vertShader);
    glAttachShader(program, fragShader);

    glLinkProgram(program);

    // Delete now unnecessary shaders
    glDeleteShader(vertShader);
    glDeleteShader(fragShader);

    m_ProgramID = program;


    std::cout << getShaderFromPath(std::string("assets/shaders/frag.shader"));
}

// Creates a shader
uint32_t ShaderProgram::createShader(const std::string& source, GLenum shaderType) {
    uint32_t id = glCreateShader(shaderType);
    const char* src = source.c_str();

    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);

    return id;
}

std::string ShaderProgram::getShaderFromPath(const std::string& path) {
    std::ifstream stream(path);
    std::string line;
    std::stringstream ss;

    while(getline(stream, line)) {
        ss << line << "\n";
    }

    return ss.str();
}

void ShaderProgram::BindProgram() {
    glUseProgram(m_ProgramID);
}

// Upload a uniform to the shader
void ShaderProgram::UploadUniformMat4(const std::string& name, const glm::mat4 matrix) {
    GLint location = glGetUniformLocation(m_ProgramID, name.c_str());
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void ShaderProgram::UploadUniform1i(const std::string& name, const int value) {
    GLint location = glGetUniformLocation(m_ProgramID, name.c_str());
    glUniform1i(location, value);
}
