#ifndef TRAMPOSO_SCENE_H
#define TRAMPOSO_SCENE_H

#include <memory>
#include <vector>
#include "tramplib/Sprite.h"

namespace tramplib {

    class Game;

    /**
 * @class Scene
 * @brief Represents a game scene or state.
 *
 * The Scene class manages a collection of sprites and provides
 * methods for updating and rendering the scene.
 */
    class Scene {
    public:

        /**
     * @brief Construct a new Scene object.
     *
     * @param game A pointer to the Game object that owns this scene.
     */
        Scene(Game* game);

        /**
    * @brief Destroy the Scene object.
    */
        virtual ~Scene() = default;

        /**
    * @brief Load resources and initialize the scene.
    *
    * This method is called when the scene becomes active.
    */
        virtual void load() = 0;

        /**
     * @brief Unload resources and clean up the scene.
     *
     * This method is called when the scene is no longer active.
     */
        virtual void unload() = 0;

        /**
    * @brief Update the scene and its sprites.
    *
    * @param deltaTime The time elapsed since the last update.
    */
        virtual void update(float deltaTime) = 0;

        /**
   * @brief Render the scene and its sprites.
   */
        virtual void render(); 

        /**
     * @brief Add a sprite to the scene.
     *
     * @param sprite A shared pointer to the Sprite to add.
     */
        void addSprite(std::shared_ptr<Sprite> sprite);

    protected:
        Game* m_game;
        std::vector<std::shared_ptr<Sprite>> m_sprites;
    };

} // namespace tramplib

#endif // TRAMPOSO_SCENE_H