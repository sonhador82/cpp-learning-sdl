#include <iostream>
#include "Game.h"
#include "InputHandler.h"
#include "MenuState.hpp"
#include "PlayState.hpp"

Game* Game::s_pInstance = 0;

bool Game::init(const char *title, int xpos, int ypos, int width, int height, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success\n";
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if (m_pWindow != 0) // window init success
        {
            std::cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
            if (m_pRenderer != 0) // renderer init success
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
            }
            else
            {
                std::cout << "renderer init fail\n";
                return false; // renderer init fail
            }
        }
        else
        {
            std::cout << "window init fail\n";
            return false; // window init fail
        }
    }
    else
    {
        std::cout << "SDL init fail\n";
        return false; // SDL init fail
    }
    std::cout << "init success\n";
    m_bRunning = true; // everything inited successfully,    start the main loop return true;

    m_go.load(100, 100, 128, 82, "animate");
    m_player.load(300, 300, 128, 82, "animate");

    m_pGameStateMachine = new GameStateMachine();
    m_pGameStateMachine->changeState(new MenuState());
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);   // clear the renderer to    the draw color

    m_pGameStateMachine->render();

    SDL_RenderPresent(m_pRenderer); // draw to the screen
}

void Game::update()
{
    m_pGameStateMachine->update();
}


void Game::clean()
{
    TheInputHandler::Instance()->clean();
}
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

void Game::handleEvents()
{
    TheInputHandler::Instance()->update();

    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
    {
        m_pGameStateMachine->changeState(new PlayState());
    }
}

