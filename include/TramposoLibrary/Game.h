#ifndef TRAMPOSO_GAME_H
#define TRAMPOSO_GAME_H

#include <SDL.h>
#include <string>
#include <vector>
#include <memory>

namespace TramposoLibrary {

    class Sprite;
    class InputManager;
    class AudioManager;
    class CollisionManager;

    class Game {
    public:
        Game(const std::string& title, int width, int height);
        ~Game();

        void run();
        void quit();

        void addSprite(std::shared_ptr<Sprite> sprite);
        InputManager& getInputManager() {
            return *m_inputManager;
        }
        AudioManager& getAudioManager() {
            return *m_audioManager;
        }
        CollisionManager& getCollisionManager() {
            return *m_collisionManager;
        }

    private:
        SDL_Window* m_window;
        SDL_Renderer* m_renderer;
        bool m_isRunning;

        std::vector<std::shared_ptr<Sprite>> m_sprites;
        std::unique_ptr<InputManager> m_inputManager;
        std::unique_ptr<AudioManager> m_audioManager;
        std::unique_ptr<CollisionManager> m_collisionManager;

        void initialize();
        void handleEvents();
        void update();
        void render();
        void clean();
    };

} 

#endif // TRAMPOSO_GAME_H