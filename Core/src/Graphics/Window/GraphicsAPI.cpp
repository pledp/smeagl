#include <memory>

#include "Graphics/Window/GraphicsAPI.h"
#include "Graphics/Window/SDLGraphics.h"

namespace pledGL {
    std::unique_ptr<GraphicsBase> GraphicsAPI::SetRenderer(API api) {
        switch(api) {
            case API::SDL: return std::make_unique<SDLGraphics>();
        }
    }
}