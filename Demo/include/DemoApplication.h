#ifndef D_APPLICATION_H_
#define D_APPLICATION_H_

#include "Game.h"
#include "Graphics/Renderer/SDLRenderer.h"

class DemoApplication : public Game {
    public:
        DemoApplication(); 
        ~DemoApplication();

        void Init() override;
        void Update() override;
        void Render() override;

    private: 
        Renderer* graphics = nullptr;
};

#endif