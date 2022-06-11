#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Game.h"

SDLGameObject::SDLGameObject(const LoadParams* pParams)
{
    m_x = pParams->getX();
    m_y = pParams->getY();
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
        m_x, m_y, 
        m_width, m_height, 
        m_currentRaw, m_currentFrame, 
        TheGame::Instance()->getRenderer());
}
