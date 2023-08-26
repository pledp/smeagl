#ifndef GAME_BASE_H_
#define GAME_BASE_H_

class GameBase {
public:
    /**
     * The game context.
    */    
    virtual void Run() = 0;
    virtual void End() = 0;
};

#endif