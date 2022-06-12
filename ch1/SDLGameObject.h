#ifndef __SDLGameObject__
#define __SDL_GameObject__

#include "GameObject.h"
#include "LoadParams.h"
#include "Vector2D.h"

class SDLGameObject : GameObject
{
private:

protected:
    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_acceleration;

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
