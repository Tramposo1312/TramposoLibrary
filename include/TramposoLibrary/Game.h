#ifndef TRAMPOSO_GAME_H
#define TRAMPOSO_GAME_H

#include <SDL.h>
#include <string>
#include <memory>
#include <unordered_map>
#include "Scene.h"

namespace TramposoLibrary {

    class InputManager;
    class ResourceManager;
    class CollisionManager;

    class Game {
    public:
        Game(const std::string& title, int width, int height);
        ~Game();

        void run();
        void quit();

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

        std::unordered_map<std::string, std::unique_ptr<Scene>> m_scenes;
        Scene* m_currentScene;

        Uint32 m_lastFrameTime;

        void handleEvents();
        void update(float deltaTime);
        void render();
    };

} // namespace TramposoLibrary

#endif // TRAMPOSO_GAME_H