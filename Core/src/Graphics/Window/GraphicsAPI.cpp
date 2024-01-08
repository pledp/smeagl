#include <memory>

#include "Graphics/Window/GraphicsAPI.h"
#include "Graphics/Window/SDLGraphics.h"

std::unique_ptr<pledGL::GraphicsBase> pledGL::GraphicsAPI::SetRenderer(API api) {
    switch(api) {
        case API::SDL: return std::make_unique<pledGL::SDLGraphics>();
    }
}