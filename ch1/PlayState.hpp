#ifndef __PlayState__
#define __PlayState__

#include "GameState.hpp"

class PlayState : public GameState
{
public:
    PlayState(/* args */);
    ~PlayState();
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const { return s_playID;}

private:
    static const std::string s_playID;
};

PlayState::PlayState(/* args */){}

PlayState::~PlayState(){}


#endif // !__PlayState__
