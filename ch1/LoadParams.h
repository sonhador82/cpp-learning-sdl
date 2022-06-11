#include <iostream>

class LoadParams
{
public:
    LoadParams(/* args */);
    ~LoadParams();
    LoadParams(int x, int y, int width, int height, std::string textureID) 
        : m_x(x), m_y(y), m_width(width), m_height(height), m_textureId(textureID) 
        {

        }
    int getX() const { return m_x; }
    int getY() const { return m_y; }
    int getWidth() const {return m_width;}
    int getHeight() const { return m_height;}
    std::string getTextureId() const { return m_textureId;}
private:
    int m_x, m_y;
    int m_width, m_height;

    std::string  m_textureId;

};

LoadParams::LoadParams(/* args */)
{
}

LoadParams::~LoadParams()
{
}
