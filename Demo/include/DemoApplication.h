#ifndef D_APPLICATION_H_
#define D_APPLICATION_H_

#include "Application\Game.h"

class DemoApplication : public Game {
    public:
        DemoApplication(); 
        ~DemoApplication();

        void Init() override;
        void Update(float deltaTime) override;
        void Render(float deltaTime) override;

    private: 
        GraphicsBase* graphics = nullptr;
};

#endif