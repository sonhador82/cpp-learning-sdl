#ifndef __SDLGameObject__
#define __SDL_GameObject__

#include "LoadParams.h"

class SDLGameObject
{
private:

protected:
    int m_x, m_y;
    int m_height, m_width;
    int m_currentRaw;
    int m_currentFrame;

    std::string m_textureID;

public:
    SDLGameObject(const LoadParams* pParams);
    ~SDLGameObject();
    virtual void draw();
    virtual void update();
    virtual void clean();
};

SDLGameObject::~SDLGameObject(){}

#endif // !__SDLGameObject__
