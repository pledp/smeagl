#ifndef APP_H_
#define APP_H_

#include "Game.h"
#include "Graphics/RendererBase.h"

class Game;
class RendererBase;

class App {
    public:
        virtual void Init() = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
};

#endif