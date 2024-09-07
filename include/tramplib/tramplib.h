#ifndef TRAMPLIB_H
#define TRAMPLIB_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include <vector>
#include <memory>

namespace tramplib {

    class Game;
    class Sprite;
    class InputManager;
    class AudioManager;
    class CollisionManager;

    // Game class to manage the main game loop and components //
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

    // Sprite class for game objects //
    class Sprite {
    public:
        Sprite(SDL_Renderer* renderer, const std::string& imagePath, int x, int y);
        virtual ~Sprite();

        virtual void update();
        virtual void render();

        void setPosition(int x, int y);
        SDL_Rect getRect() const {
            return m_rect;
        }

    protected:
        SDL_Texture* m_texture;
        SDL_Rect m_rect;
        SDL_Renderer* m_renderer;
    };

    // Input manager to handle user input //
    class InputManager {
    public:
        InputManager();
        void update();
        bool isKeyPressed(SDL_Scancode key);
        bool isKeyReleased(SDL_Scancode key);

    private:
        const Uint8* m_keyboardState;
        Uint8 m_previousKeyboardState[SDL_NUM_SCANCODES];
    };

    // Audio manager to handle sound effects and music //
    class AudioManager {
    public:
        AudioManager();
        ~AudioManager();

        void playSound(const std::string& soundFile);
        void playMusic(const std::string& musicFile, int loops = -1);
        void stopMusic();

    private:
        std::vector<Mix_Chunk*> m_soundEffects;
        Mix_Music* m_music;
    };

    // Collision manager to handle object collisions //
    class CollisionManager {
    public:
        bool checkCollision(const SDL_Rect& rectA, const SDL_Rect& rectB);
    };

} // namespace tramplib //

#endif // TRAMPLIB_H