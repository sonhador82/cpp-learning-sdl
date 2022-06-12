#ifndef __Player__
#define __Player__

#include <iostream>
#include "SDLGameObject.h"
#include "LoadParams.h"

class Player : SDLGameObject
{
private:
    /* data */
public:
    Player(const LoadParams* pParams);
    ~Player();

    void load(int x, int y, int width, int height, std::string textureID);
    void draw(SDL_Renderer* pRenderer);
    void update();
    void clean();

};

Player::~Player(){}

#endif // !__Player__
