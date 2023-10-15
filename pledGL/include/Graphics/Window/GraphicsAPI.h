#ifndef GRAPHICS_API_H_
#define GRAPHICS_API_H_

#include "Graphics/Window/GraphicsBase.h"

class GraphicsAPI  {
public:
    enum class API
    {
        None = 0, SDL = 1, OpenGL = 2
    };

    static GraphicsBase* SetRenderer(API api);

};

#endif