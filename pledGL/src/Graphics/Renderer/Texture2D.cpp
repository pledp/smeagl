#include "glad/glad.h"
#include <stb/stb_image.h>
#include "Graphics/Renderer/Texture2D.h"

Texture2D::Texture2D(const char *path) {
    int width, height, nrChannels;
    unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);

    if (data) {
        Width = width;
        Height = height;

        glCreateTextures(GL_TEXTURE_2D, 1, &mTextureID);
        glTextureStorage2D(mTextureID, 1, GL_RGB8, Width, Height);

        // Set texture parameters
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTextureSubImage2D(mTextureID, 0, 0, 0, Width, Height, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    stbi_image_free(data);

} 

void Texture2D::Bind(uint32_t slot) {
    glBindTextureUnit(slot, mTextureID);
}