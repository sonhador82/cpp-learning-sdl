#ifndef __Game__
#define __Game__

#include <SDL2/SDL.h>

class Game
{
public:
    Game(/* args */);
    ~Game();

    bool init(const char *title, int xpos, int ypos, int width, int height, int flags);

    void render();
    void update();
    void handleEvents();
    void clean();
    bool running() { return m_bRunning; }

private:
    SDL_Window *m_pWindow = 0;
    SDL_Renderer *m_pRenderer = 0;

    bool m_bRunning;
};

Game::Game(/* args */) {}

Game::~Game() {}

#endif
