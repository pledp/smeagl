#ifndef TEXTURE_TWOD_
#define TEXTURE_TWOD_

class Texture2D {
public:
    Texture2D(const char *path);
    void Bind(const uint32_t slot);
    int Width, Height;

private:
    uint32_t mTextureID;
};

#endif