#include "glad/glad.h"
#include <stb/stb_image.h>
#include "Graphics/Renderer/Texture2D.h"

pledGL::Texture2D::Texture2D(const char *path) {
    // Load image
    int width, height, nrChannels;
    unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);

    if (data) {
        // Create OpenGL texture
        glCreateTextures(GL_TEXTURE_2D, 1, &mTextureID);
        // Allocate storage for texture, specify texture format
        glTextureStorage2D(mTextureID, 1, GL_RGB8, width, height);

        // Set texture parameters
        glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        // Set OpenGl texture data
        glTextureSubImage2D(mTextureID, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
        // Generate mipmap (smaller versions of the texture, to be rendered when texture is certain distance away (or size))
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    stbi_image_free(data);

} 

pledGL::Texture2D::~Texture2D() {
    //glDeleteTextures(1, &mTextureID);
}

void pledGL::Texture2D::Bind(const uint32_t slot) {
    // Bind texture to texture unit
    glBindTextureUnit(slot, mTextureID);
}