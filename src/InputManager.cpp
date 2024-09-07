#include "TramposoLibrary/InputManager.h"
#include <cstring>

namespace TramposoLibrary {

    InputManager::InputManager() : m_keyboardState(SDL_GetKeyboardState(nullptr)) {
        memset(m_previousKeyboardState, 0, sizeof(m_previousKeyboardState));
    }

    void InputManager::update() {
        memcpy(m_previousKeyboardState, m_keyboardState, SDL_NUM_SCANCODES);
        SDL_PumpEvents();
    }

    bool InputManager::isKeyPressed(SDL_Scancode key) {
        return m_keyboardState[key] && !m_previousKeyboardState[key];
    }

    bool InputManager::isKeyReleased(SDL_Scancode key) {
        return !m_keyboardState[key] && m_previousKeyboardState[key];
    }

} // TramposoLibrary