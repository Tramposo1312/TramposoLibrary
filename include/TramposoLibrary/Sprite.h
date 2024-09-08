#ifndef TRAMPOSO_SPRITE_H
#define TRAMPOSO_SPRITE_H

#include <SDL.h>
#include <string>
#include <memory>
#include <vector>
#include "TramposoLibrary/Component.h"

namespace TramposoLibrary {

    /**
 * @class Sprite
 * @brief Represents a game object that can be rendered to the screen.
 *
 * The Sprite class manages the texture, position, and components of a game object.
 */
    class Sprite {
    public:

        /**
     * @brief Construct a new Sprite object.
     *
     * @param renderer The SDL renderer to use for drawing.
     * @param imagePath The file path to the sprite's image.
     * @param x The initial x-coordinate of the sprite.
     * @param y The initial y-coordinate of the sprite.
     */
        Sprite(SDL_Renderer* renderer, const std::string& imagePath, int x, int y);

        /**
    * @brief Destroy the Sprite object and clean up resources.
    */
        virtual ~Sprite();

        /**
    * @brief Update the sprite and its components.
    *
    * @param deltaTime The time elapsed since the last update.
    */
        virtual void update(float deltaTime);

        /**
     * @brief Render the sprite to the screen.
     */
        virtual void render();

        /**
    * @brief Set the position of the sprite.
    *
    * @param x The new x-coordinate.
    * @param y The new y-coordinate.
    */
        void setPosition(int x, int y);

        /**
     * @brief Get the current bounding rectangle of the sprite.
     *
     * @return SDL_Rect The bounding rectangle.
     */
        SDL_Rect getRect() const {
            return m_rect;
        }

        /**
   * @brief Add a component to the sprite.
   *
   * @tparam T The type of component to add.
   * @tparam Args The types of arguments to pass to the component constructor.
   * @param args The arguments to pass to the component constructor.
   * @return T* A pointer to the newly added component.
   */
        template<typename T, typename... Args>
        T* addComponent(Args&&... args) {
            auto component = std::make_unique<T>(this, std::forward<Args>(args)...);
            T* componentPtr = component.get();
            m_components.push_back(std::move(component));
            return componentPtr;
        }

        /**
    * @brief Get a component of a specific type.
    *
    * @tparam T The type of component to get.
    * @return T* A pointer to the component, or nullptr if not found.
    */
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