#include "TramposoLibrary/Game.h"
#include "TramposoLibrary/Sprite.h"
#include "TramposoLibrary/InputManager.h"
#include "TramposoLibrary/AudioManager.h"
#include "TramposoLibrary/CollisionManager.h"
#include <stdexcept>

namespace TramposoLibrary {

    Game::Game(const std::string& title, int width, int height)
        : m_window(nullptr), m_renderer(nullptr), m_isRunning(false) {
        initialize();
        m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
        if (!m_window) {
            throw std::runtime_error("Failed to create window: " + std::string(SDL_GetError()));
        }

        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (!m_renderer) {
            throw std::runtime_error("Failed to create renderer: " + std::string(SDL_GetError()));
        }

        m_inputManager = std::make_unique<InputManager>();
        m_audioManager = std::make_unique<AudioManager>();
        m_collisionManager = std::make_unique<CollisionManager>();
    }

    Game::~Game() {
        clean();
    }

    void Game::initialize() {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            throw std::runtime_error("SDL initialization failed: " + std::string(SDL_GetError()));
        }
    }

    void Game::run() {
        m_isRunning = true;
        while (m_isRunning) {
            handleEvents();
            update();
            render();
        }
    }

    void Game::handleEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                m_isRunning = false;
            }
        }
        m_inputManager->update();
    }

    void Game::update() {
        for (auto& sprite : m_sprites) {
            sprite->update();
        }
    }

    void Game::render() {
        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
        SDL_RenderClear(m_renderer);

        for (auto& sprite : m_sprites) {
            sprite->render();
        }

        SDL_RenderPresent(m_renderer);
    }

    void Game::quit() {
        m_isRunning = false;
    }

    void Game::addSprite(std::shared_ptr<Sprite> sprite) {
        m_sprites.push_back(sprite);
    }

    void Game::clean() {
        m_sprites.clear();
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }

} // TramposoLibrary