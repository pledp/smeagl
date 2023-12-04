#ifndef TEXTURE_TWOD_
#define TEXTURE_TWOD_

#include <string>

class Texture2D {
public:
    Texture2D(const char *path);
    void Bind(uint32_t slot);
    int Width, Height;

private:
    uint32_t mTextureID;
};

#endif