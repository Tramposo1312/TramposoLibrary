#ifndef TRAMPOSO_GAME_H
#define TRAMPOSO_GAME_H

#include <SDL.h>
#include <string>
#include <memory>
#include <unordered_map>
#include "TramposoLibrary/Scene.h"

namespace TramposoLibrary {

    class InputManager;
    class AudioManager;
    class CollisionManager;

    /**
 * @class Game
 * @brief The main class for managing the game loop and core systems.
 *
 * The Game class is responsible for initializing SDL, managing scenes,
 * and running the main game loop.
 */

    class Game {
    public:

        /**
     * @brief Construct a new Game object.
     *
     * @param title The title of the game window.
     * @param width The width of the game window.
     * @param height The height of the game window.
     */

        Game(const std::string& title, int width, int height);
        /**
     * @brief Destroy the Game object and clean up resources.
     */
        ~Game();

        /**
    * @brief Start the main game loop.
    */
        void run();

        /**
     * @brief Signal the game to quit.
     */

        void quit();

        /**
   * @brief Add a new scene to the game.
   *
   * @param name The name of the scene, used as a key for retrieval.
   * @param scene A unique pointer to the Scene object.
   */
        void addScene(const std::string& name, std::unique_ptr<Scene> scene);

        /**
    * @brief Set the current active scene.
    *
    * @param name The name of the scene to set as active.
    */
        void setCurrentScene(const std::string& name);

        /**
     * @brief Get the SDL renderer.
     *
     * @return SDL_Renderer* A pointer to the SDL renderer.
     */
        SDL_Renderer* getRenderer() const;

        /**
    * @brief Get the input manager.
    *
    * @return InputManager& A reference to the input manager.
    */
        InputManager& getInputManager() {
            return *m_inputManager;
        }

        /**
    * @brief Get the audio manager.
    *
    * @return AudioManager& A reference to the audio manager.
    */
        AudioManager& getAudioManager() {
            return *m_audioManager;
        }

        /**
     * @brief Get the collision manager.
     *
     * @return CollisionManager& A reference to the collision manager.
     */
        CollisionManager& getCollisionManager() {
            return *m_collisionManager;
        }

        /**
    * @brief Check if the game is currently running.
    *
    * @return true If the game is running.
    * @return false If the game is not running.
    */
        bool isRunning() const;

    private:
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        bool m_isRunning;

        std::unique_ptr<InputManager> m_inputManager;
        std::unique_ptr<AudioManager> m_audioManager;
        std::unique_ptr<CollisionManager> m_collisionManager;

        std::unordered_map<std::string, std::unique_ptr<Scene>> m_scenes;
        Scene* m_currentScene;

        Uint32 m_lastFrameTime;

        void handleEvents();
        void update(float deltaTime);
        void render();
    };

} // TramposoLibrary

#endif // TRAMPOSO_GAME_H