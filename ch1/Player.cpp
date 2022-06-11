#include <iostream>
#include <SDL2/SDL.h>
#include "SDLGameObject.h"
#include "Player.h"


Player::Player(const LoadParams* pParams) : SDLGameObject(pParams)
{

}

void Player::load(int x, int y, int width, int height, std::string textureID)
{
    GameObject::load(x, y, width, height, textureID);
}

void Player::draw(SDL_Renderer* pRenderer)
{
    GameObject::draw(pRenderer);
}

void Player::update()
{
    m_x -= 1;
}

void Player::clean()
{

}