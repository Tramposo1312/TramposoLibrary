#include "TramposoLibrary/InputManager.h"

namespace TramposoLibrary {

    InputManager::InputManager() : m_keyboardState(SDL_GetKeyboardState(nullptr)) {
        std::fill_n(m_previousKeyboardState, SDL_NUM_SCANCODES, 0);
    }

    void InputManager::update() {
        std::copy_n(m_keyboardState, SDL_NUM_SCANCODES, m_previousKeyboardState);

        m_previousMouseState = m_currentMouseState;
        m_currentMouseState = SDL_GetMouseState(&m_mouseX, &m_mouseY);
    }

    void InputManager::handleEvent(const SDL_Event& event) {
        // Handle specific events if needed
    }

    bool InputManager::isKeyPressed(SDL_Scancode key) const {
        return m_keyboardState[key] && !m_previousKeyboardState[key];
    }

    bool InputManager::isKeyReleased(SDL_Scancode key) const {
        return !m_keyboardState[key] && m_previousKeyboardState[key];
    }

    bool InputManager::isKeyHeld(SDL_Scancode key) const {
        return m_keyboardState[key];
    }

    bool InputManager::isMouseButtonPressed(int button) const {
        return (m_currentMouseState & SDL_BUTTON(button)) && !(m_previousMouseState & SDL_BUTTON(button));
    }

    bool InputManager::isMouseButtonReleased(int button) const {
        return !(m_currentMouseState & SDL_BUTTON(button)) && (m_previousMouseState & SDL_BUTTON(button));
    }

    bool InputManager::isMouseButtonHeld(int button) const {
        return m_currentMouseState & SDL_BUTTON(button);
    }

    void InputManager::getMousePosition(int& x, int& y) const {
        x = m_mouseX;
        y = m_mouseY;
    }

} // TramposoLibrary