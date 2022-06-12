#ifndef __GameObject__
#define __GameObject__

#include <iostream>
#include <SDL2/SDL.h>

class GameObject
{
public:
    GameObject(/* args */);
    void load(int x, int y, int width, int height, std::string textureID);
    void draw(SDL_Renderer* pRenderer);
    void update();
    void clean();

protected:
    std::string m_textureID;
    int m_x, m_y;
    int m_width, m_height;
    int m_currentFrame;
    int m_currentRow;

    //GameObject(const LoaderParams* pParams){}
    virtual ~GameObject();

};

GameObject::GameObject(/* args */){}

GameObject::~GameObject(){}

#endif // !__GameObject__
