#include <iostream>
#include <SDL2/SDL.h>
#include "SDLGameObject.h"
#include "Player.h"
#include "InputHandler.h"

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
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
    m_acceleration.setX(1);
    SDLGameObject::update();
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
    {
        m_velocity.setX(2);
    }
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
    {
        m_velocity.setX(-2);
    }
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
    {
        m_velocity.setY(-2);
    }
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
    {
        m_velocity.setY(2);
    }
}

void Player::clean()
{

}