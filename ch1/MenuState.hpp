#ifndef __MenuState__
#define __MenuState__

#include "GameState.hpp"

class MenuState : public GameState
{
public:
    MenuState(/* args */);
    ~MenuState();
    virtual void update();
    virtual void render();

    virtual bool onEnter();
    virtual bool onExit();

    virtual std::string getStateID() const { return s_menuID;}

private:
    static const std::string s_menuID;
};

MenuState::MenuState(/* args */){}

MenuState::~MenuState(){}


#endif // !__MenuState__
