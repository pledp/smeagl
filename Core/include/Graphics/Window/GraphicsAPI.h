#ifndef GRAPHICS_API_H_
#define GRAPHICS_API_H_

#include <memory>

#include "Graphics/Window/GraphicsBase.h"

namespace pledGL {
    class GraphicsAPI  {
    public:
        enum class API
        {
            None = 0, SDL = 1, OpenGL = 2
        };

        static std::unique_ptr<GraphicsBase> SetRenderer(API api);

    };
};

#endif