#include <iostream>

#include "PlayState.hpp"

const std::string PlayState::s_playID = "PLAY";

void PlayState::update()
{

}

void PlayState::render()
{

}

bool PlayState::onEnter()
{
    std::cout << "Entering PlayState\n";
    return true;
}

bool PlayState::onExit()
{
    std::cout << "exiting playstate\n";
    return true;
}