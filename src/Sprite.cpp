#include "tramplib/Sprite.h"
#include <SDL_image.h>
#include <stdexcept>

namespace tramplib {

    Sprite::Sprite(SDL_Renderer* renderer, const std::string& imagePath, int x, int y)
        : m_renderer(renderer), m_texture(nullptr) {
        SDL_Surface* surface = IMG_Load(imagePath.c_str());
        if (surface == nullptr) {
            throw std::runtime_error("Unable to load image! SDL_image Error: " + std::string(IMG_GetError()));
        }

        m_texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        if (m_texture == nullptr) {
            throw std::runtime_error("Unable to create texture! SDL Error: " + std::string(SDL_GetError()));
        }

        m_rect.x = x;
        m_rect.y = y;
        SDL_QueryTexture(m_texture, nullptr, nullptr, &m_rect.w, &m_rect.h);
    }

    Sprite::~Sprite() {
        if (m_texture != nullptr) {
            SDL_DestroyTexture(m_texture);
        }
    }

    void Sprite::update(float deltaTime) {
        for (auto& component : m_components) {
            component->update(deltaTime);
        }
    }

    void Sprite::render() {
        SDL_RenderCopy(m_renderer, m_texture, nullptr, &m_rect);
        for (auto& component : m_components) {
            component->render();
        }
    }

    void Sprite::setPosition(int x, int y) {
        m_rect.x = x;
        m_rect.y = y;
    }

} // tramplib