#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoadParams* pParams) : GameObject(pParams),
    m_position(pParams->getX(), pParams->getY()), m_velociy(0,0)
{
    m_width = pParams->getWidth();
    m_height = pParams->getHeight();
    m_textureID = pParams->getTextureId();
    m_currentRaw = 1;
    m_currentFrame = 1;
}

void SDLGameObject::draw()
{
    TextureManager::Instance()->drawFrame(
        m_textureID, 
        (int)m_position.getX(), (int)m_position.getY(), 
        m_width, m_height, 
        m_currentRaw, m_currentFrame,
    TheGame::Instance()->getRenderer());
}

void SDLGameObject::update()
{
    m_velocity += m_acceleration;
    m_position += m_velociy;
}