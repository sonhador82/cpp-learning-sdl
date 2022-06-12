#ifndef __InputHandler__
#define __InputHandler__

#include <SDL2/SDL.h>
#include <vector>

#include "Vector2D.h"

enum MyEnum
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};


class InputHandler
{
public:
    static InputHandler* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new InputHandler();
        }
        return s_pInstance;
    }
    void update();
    void clean();
    bool getMouseButtonState(int buttonNumber);
    bool InputHandler::isKeyDown(SDL_Scancode key);
    Vector2D* getMousePosition()
    {
        return m_mousePosition;
    }

private:
    static InputHandler* s_pInstance;
    const Uint8* m_keystate;
    InputHandler();
    ~InputHandler(){}

    std::vector<bool> m_mouseButtonStates;
    Vector2D* m_mousePosition;

    // handle keyboard events
    void onKeyDown();
    void onKeyUp();

    // handle mouse events
    void onMouseMove(SDL_Event& event);
    void onMouseButtonDown(SDL_Event& event);
    void onMouseButtonUp(SDL_Event& event);

};
typedef InputHandler TheInputHandler;


#endif // !__InputHandler__
