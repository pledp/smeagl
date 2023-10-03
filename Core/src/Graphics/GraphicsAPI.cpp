#include "Graphics/GraphicsAPI.h"
#include "Graphics/Renderer/SDLRenderer.h"

Renderer* GraphicsAPI::SetRenderer(API api) {
    switch(api) {
        case API::SDL: return new SDLRenderer();
    }
}