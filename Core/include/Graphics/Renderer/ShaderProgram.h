#ifndef SHADERPROGRAM_H_
#define SHADERPROGRAM_H_

#include <cstdint>
#include <string>

#include "glad/glad.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

namespace pledGL {
    class ShaderProgram {
    public: 
        ~ShaderProgram();

        void BindProgram();
        void CreateProgram(const std::string& vertShader, const std::string& fragShader);
        void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
        void UploadUniform1i(const std::string& name, const int value);

        uint32_t GetID() { return mProgramID; };

    private:
        uint32_t createShader(const std::string& shader, GLenum shaderType);
        std::string getShaderFromPath(const std::string& path);
        uint32_t mProgramID;
    };
};

#endif