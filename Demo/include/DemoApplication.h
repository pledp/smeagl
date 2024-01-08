#ifndef D_APPLICATION_H_
#define D_APPLICATION_H_

#include "Application\Game.h"

class DemoApplication : public pledGL::Game {
    public:
        DemoApplication(); 
        ~DemoApplication();

        void Init() override;
        void Update(const pledGL::GameTime& game_time) override;
        void Render(const pledGL::GameTime& game_time, pledGL::Renderer& renderer) override;

    private: 
        pledGL::GraphicsBase* graphics = nullptr;
};

#endif