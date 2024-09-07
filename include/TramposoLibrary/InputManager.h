#ifndef TRAMPOSO_INPUT_MANAGER_H
#define TRAMPOSO_INPUT_MANAGER_H

#include <SDL.h>

namespace TramposoLibrary {

    class InputManager {
    public:
        InputManager();
        void update();
        bool isKeyPressed(SDL_Scancode key);
        bool isKeyReleased(SDL_Scancode key);

    private:
        const Uint8* m_keyboardState;
        Uint8 m_previousKeyboardState[SDL_NUM_SCANCODES];
    };

} 

#endif // TRAMPOSO_INPUT_MANAGER_H