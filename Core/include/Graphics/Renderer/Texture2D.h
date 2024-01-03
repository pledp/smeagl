#ifndef TEXTURE_TWOD_
#define TEXTURE_TWOD_

#include <cstdint>

namespace pledGL {
    class Texture2D {
    public:
        Texture2D(const char *path);
        ~Texture2D();

        void Bind(const uint32_t slot);
        int Width, Height;

    private:
        uint32_t mTextureID;
    };
};

#endif