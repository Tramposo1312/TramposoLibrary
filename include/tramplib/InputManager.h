#ifndef TRAMPOSO_INPUT_MANAGER_H
#define TRAMPOSO_INPUT_MANAGER_H

#include <SDL.h>
#include <vector>

namespace tramplib {

    class InputManager {
    public:
        InputManager();
        void update();
        void handleEvent(const SDL_Event& event);

        bool isKeyPressed(SDL_Scancode key) const;
        bool isKeyReleased(SDL_Scancode key) const;
        bool isKeyHeld(SDL_Scancode key) const;

        bool isMouseButtonPressed(int button) const;
        bool isMouseButtonReleased(int button) const;
        bool isMouseButtonHeld(int button) const;
        void getMousePosition(int& x, int& y) const;

    private:
        const Uint8* m_keyboardState;
        std::vector<Uint8> m_previousKeyboardState;
        Uint32 m_currentMouseState;
        Uint32 m_previousMouseState;
        int m_mouseX, m_mouseY;
    };

} 

#endif 