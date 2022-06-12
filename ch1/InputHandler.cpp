#include <SDL2/SDL.h>

#include "Game.h"
#include "InputHandler.h"

void InputHandler::update()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            TheGame::Instance()->quit();
            break;
        case SDL_MOUSEMOTION:
            onMouseMove(event);
            break;
        case SDL_MOUSEBUTTONDOWN:
            onMouseButtonDown(event);
            break;
        case SDL_MOUSEBUTTONUP:
            onMouseButtonUp(event);
            break;
        case SDL_KEYDOWN:
            onKeyDown();
            break;
        case SDL_KEYUP:
            onKeyUp();
            break;
        default:
            break;
        }



        //m_keystate = SDL_GetKeyboardState(0);       
    }       
}

InputHandler::InputHandler()
{
    for(int i=0; i<3; i++)
    {
        m_mouseButtonStates.push_back(false);
    }
}

bool InputHandler::getMouseButtonState(int buttonNumber)
{
    return m_mouseButtonStates[buttonNumber];
}

bool InputHandler::isKeyDown(SDL_Scancode key)
{
    if(m_keystate != 0)
    {
        if(m_keystate[key] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;
}

void InputHandler::onMouseButtonDown(SDL_Event &event)
{
    if(event.button.button == SDL_BUTTON_LEFT)
    {
        m_mouseButtonStates[LEFT] = true;
    }
    if(event.button.button == SDL_BUTTON_MIDDLE)
    {
        m_mouseButtonStates[MIDDLE] = true;
    }
    if(event.button.button == SDL_BUTTON_RIGHT)
    {
        m_mouseButtonStates[RIGHT] = true;
    }
}