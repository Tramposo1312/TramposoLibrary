#ifndef TRAMPOSO_INPUT_MANAGER_H
#define TRAMPOSO_INPUT_MANAGER_H

#include <SDL.h>
<<<<<<< HEAD
#include <vector>
=======
#include <array>
>>>>>>> ff39892716f02024ee20b509f89751aa88d65f92

namespace TramposoLibrary {

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
<<<<<<< HEAD
        std::vector<Uint8> m_previousKeyboardState;
=======
        std::array<Uint8, SDL_NUM_SCANCODES> m_previousKeyboardState;
>>>>>>> ff39892716f02024ee20b509f89751aa88d65f92
        Uint32 m_currentMouseState;
        Uint32 m_previousMouseState;
        int m_mouseX, m_mouseY;
    };

<<<<<<< HEAD
} // namespace TramposoLibrary
=======
} // TramposoLibrary
>>>>>>> ff39892716f02024ee20b509f89751aa88d65f92

#endif // TRAMPOSO_INPUT_MANAGER_H