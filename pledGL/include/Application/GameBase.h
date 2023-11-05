#ifndef GAME_BASE_H_
#define GAME_BASE_H_

#include <cstdint>

class GameBase {
public:
    /**
     * The game context.
    */    
    virtual void Run() = 0;
    virtual void End() = 0;

    virtual void SetFps(int newFps) = 0;

    uint64_t TimeElapsedInMilliseconds = 0;
    float TotalTimeElapsedSeconds = 0;
    float DeltaTime = 0;
};

#endif