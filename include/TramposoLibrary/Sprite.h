#ifndef TRAMPOSO_SPRITE_H
#define TRAMPOSO_SPRITE_H

#include <SDL.h>
#include <string>
#include <memory>
#include <vector>
#include "TramposoLibrary/Component.h"

namespace TramposoLibrary {

    class Sprite {
    public:
        Sprite(SDL_Renderer* renderer, const std::string& imagePath, int x, int y);
        virtual ~Sprite();

        virtual void update(float deltaTime);
        virtual void render();

        void setPosition(int x, int y);
        SDL_Rect getRect() const {
            return m_rect;
        }

        template<typename T, typename... Args>
        T* addComponent(Args&&... args) {
            auto component = std::make_unique<T>(this, std::forward<Args>(args)...);
            T* componentPtr = component.get();
            m_components.push_back(std::move(component));
            return componentPtr;
        }

        template<typename T>
        T* getComponent() {
            for (auto& component : m_components) {
                if (auto casted = dynamic_cast<T*>(component.get())) {
                    return casted;
                }
            }
            return nullptr;
        }

    protected:
        SDL_Texture* m_texture;
        SDL_Rect m_rect;
        SDL_Renderer* m_renderer;
        std::vector<std::unique_ptr<Component>> m_components;
    };

} // namespace TramposoLibrary

#endif // TRAMPOSO_SPRITE_H