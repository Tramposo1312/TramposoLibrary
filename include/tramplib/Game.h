#ifndef TRAMPLIB_GAME_H
#define TRAMPLIB_GAME_H

#include <SDL.h>
#include <string>
#include <memory>
#include <stack>
#include "GameState.h"

namespace tramplib {

    class InputManager;
    class ResourceManager;
    class CollisionManager;

    /**
     * @class Game
     * @brief Main game class that manages the game loop and states.
     */
    class Game {
    public:
        /**
         * @brief Constructor for Game.
         * @param title The title of the game window.
         * @param width The width of the game window.
         * @param height The height of the game window.
         */
        Game(const std::string& title, int width, int height);

        /**
         * @brief Destructor for Game.
         */
        ~Game();

        /**
         * @brief Runs the main game loop.
         */
        void run();

        /**
         * @brief Quits the game.
         */
        void quit();

        /**
         * @brief Pushes a new state onto the state stack.
         * @param state Unique pointer to the new state.
         */
        void pushState(std::unique_ptr<GameState> state);

        /**
         * @brief Pops the current state off the state stack.
         */
        void popState();

        /**
         * @brief Changes to a new state, replacing the current one.
         * @param state Unique pointer to the new state.
         */
        void changeState(std::unique_ptr<GameState> state);

        void addScene(const std::string& name, std::unique_ptr<Scene> scene);
        void setCurrentScene(const std::string& name);

        SDL_Renderer* getRenderer() const;
        InputManager& getInputManager() {
            return *m_inputManager;
        }
        ResourceManager& getResourceManager() {
            return *m_resourceManager;
        }
        CollisionManager& getCollisionManager() {
            return *m_collisionManager;
        }

        bool isRunning() const;

    private:
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        bool m_isRunning;

        std::unique_ptr<InputManager> m_inputManager;
        std::unique_ptr<ResourceManager> m_resourceManager;
        std::unique_ptr<CollisionManager> m_collisionManager;
        std::stack<std::unique_ptr<GameState>> m_states; ///< Stack of game states.


        std::unordered_map<std::string, std::unique_ptr<Scene>> m_scenes;
        Scene* m_currentScene;

        Uint32 m_lastFrameTime;

        void handleEvents();
        void update(float deltaTime);
        void render();
    };

} 

#endif 