#include "tramplib.h"
#include <stdexcept>

namespace tramplib {

    Sprite::Sprite(SDL_Renderer* renderer, const std::string& imagePath, int x, int y)
        : m_renderer(renderer), m_texture(nullptr) {
        SDL_Surface* surface = IMG_Load(imagePath.c_str());
        if (!surface) {
            throw std::runtime_error("Failed to load image: " + std::string(IMG_GetError()));
        }

        m_texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        if (!m_texture) {
            throw std::runtime_error("Failed to create texture: " + std::string(SDL_GetError()));
        }

        SDL_QueryTexture(m_texture, nullptr, nullptr, &m_rect.w, &m_rect.h);
        setPosition(x, y);
    }

    Sprite::~Sprite() {
        if (m_texture) {
            SDL_DestroyTexture(m_texture);
        }
    }

    void Sprite::update() {
        // Default update behavior (can be overridden in derived classes) //
    }

    void Sprite::render() {
        SDL_RenderCopy(m_renderer, m_texture, nullptr, &m_rect);
    }

    void Sprite::setPosition(int x, int y) {
        m_rect.x = x;
        m_rect.y = y;
    }

} 