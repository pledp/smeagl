#include "Graphics/Window/GraphicsAPI.h"
#include "Graphics/Window/SDLGraphics.h"

GraphicsBase* GraphicsAPI::SetRenderer(API api) {
    switch(api) {
        case API::SDL: return new SDLGraphics();
    }
}