#include "Graphics/Window/GraphicsAPI.h"
#include "Graphics/Window/SDLGraphics.h"

pledGL::GraphicsBase* pledGL::GraphicsAPI::SetRenderer(API api) {
    switch(api) {
        case API::SDL: return new pledGL::SDLGraphics();
    }
}