#ifndef __Game__
#define __Game__

#include <SDL2/SDL.h>
#include "GameObject.h"
#include "Player.h"

class Game
{
public:
    Game();
    ~Game();

    bool init(const char *title, int xpos, int ypos, int width, int height, int flags);

    void render();
    void update();
    void handleEvents();
    void clean();
    bool running() { return m_bRunning; }

    SDL_Renderer* getRenderer() const {return m_pRenderer;}

    static Game* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new Game();
            return s_pInstance;
        }
        return s_pInstance;
    }

private:
    Game();

    static Game* s_pInstance;

    SDL_Window *m_pWindow = 0;
    SDL_Renderer *m_pRenderer = 0;

    GameObject m_go;
    Player m_player;

    bool m_bRunning;
};

typedef Game TheGame;

#endif
