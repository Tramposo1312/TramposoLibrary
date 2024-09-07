#include "TramposoLibrary/Sprite.h"

namespace TramposoLibrary {

    Sprite::Sprite(SDL_Renderer* renderer, const std::string& imagePath, int x, int y)
        : m_renderer(renderer), m_texture(nullptr) {
        // TODO: Implement sprite loading
        m_rect = { x, y, 0, 0 };
    }

    Sprite::~Sprite() {
        if (m_texture) {
            SDL_DestroyTexture(m_texture);
        }
    }

    void Sprite::update() {
        // TODO: Implement sprite update logic
    }

    void Sprite::render() {
        // TODO: Implement sprite rendering
    }

    void Sprite::setPosition(int x, int y) {
        m_rect.x = x;
        m_rect.y = y;
    }

} // TramposoLibrary