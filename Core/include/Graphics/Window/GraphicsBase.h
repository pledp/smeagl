#ifndef RENDERER_BASE_H_
#define RENDERER_BASE_H_

class GameBase;

class GraphicsBase {
public:
    virtual ~GraphicsBase() {};

    virtual void Init(bool createWindow) = 0;
    virtual void Exit() = 0;
    virtual void Flush() = 0;
    virtual void ProcessInput(GameBase* context) = 0;
    virtual void StartLoop(int fps) = 0;
    virtual void EndLoop(GameBase* context) = 0;
};

#endif