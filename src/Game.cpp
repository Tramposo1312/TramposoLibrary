#include "tramplib/Game.h"
#include "tramplib/InputManager.h"
#include "tramplib/ResourceManager.h"
#include "tramplib/CollisionManager.h"
#include <stdexcept>
#include <SDL_image.h>
#include <SDL_ttf.h>

namespace tramplib {

    Game::Game(const std::string& title, int width, int height)
        : m_window(nullptr), m_renderer(nullptr), m_isRunning(false), m_currentScene(nullptr), m_lastFrameTime(0) {
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            throw std::runtime_error("SDL could not initialize! SDL_Error: " + std::string(SDL_GetError()));
        }
        if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
            throw std::runtime_error("SDL_image could not initialize! SDL_image Error: " + std::string(IMG_GetError()));
        }
        if (TTF_Init() == -1) {
            throw std::runtime_error("SDL_ttf could not initialize! SDL_ttf Error: " + std::string(TTF_GetError()));
        }

        m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        if (m_window == nullptr) {
            throw std::runtime_error("Window could not be created! SDL_Error: " + std::string(SDL_GetError()));
        }

        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
        if (m_renderer == nullptr) {
            throw std::runtime_error("Renderer could not be created! SDL_Error: " + std::string(SDL_GetError()));
        }

        m_inputManager = std::make_unique<InputManager>();
        m_resourceManager = std::make_unique<ResourceManager>();
        m_collisionManager = std::make_unique<CollisionManager>();
    }

    Game::~Game() {
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
    }

    void Game::run() {
        m_isRunning = true;
        m_lastFrameTime = SDL_GetTicks();
        while (m_isRunning) {
            Uint32 currentTime = SDL_GetTicks();
            float deltaTime = (currentTime - m_lastFrameTime) / 1000.0f;
            m_lastFrameTime = currentTime;

            handleEvents();
            update(deltaTime);
            render();

            // Cap the frame rate
            Uint32 frameTicks = SDL_GetTicks() - currentTime;
            if (frameTicks < 16) {
                SDL_Delay(16 - frameTicks);
            }
        }
    }

    void Game::handleEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                m_isRunning = false;
            }
            m_inputManager->handleEvent(event);
        }
    }
    void Game::pushState(std::unique_ptr<GameState> state) {
        if (!m_states.empty()) {
            m_states.top()->exit();
        }
        m_states.push(std::move(state));
        m_states.top()->enter();
    }

    void Game::popState() {
        if (!m_states.empty()) {
            m_states.top()->exit();
            m_states.pop();
        }
        if (!m_states.empty()) {
            m_states.top()->enter();
        }
    }

    void Game::changeState(std::unique_ptr<GameState> state) {
        while (!m_states.empty()) {
            m_states.top()->exit();
            m_states.pop();
        }
        m_states.push(std::move(state));
        m_states.top()->enter();
    }

    void Game::update(float deltaTime) {
        if (!m_states.empty()) {
            m_states.top()->update(deltaTime);
        }
        m_inputManager->update();
        m_collisionManager->checkCollisions();
    }

    void Game::render() {
        SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(m_renderer);

        if (!m_states.empty()) {
            m_states.top()->render();
        }

        SDL_RenderPresent(m_renderer);
    }
    void Game::quit() {
        m_isRunning = false;
    }

    void Game::addScene(const std::string& name, std::unique_ptr<Scene> scene) {
        m_scenes[name] = std::move(scene);
    }

    void Game::setCurrentScene(const std::string& name) {
        auto it = m_scenes.find(name);
        if (it != m_scenes.end()) {
            if (m_currentScene) {
                m_currentScene->unload();
            }
            m_currentScene = it->second.get();
            m_currentScene->load();
        }
        else {
            throw std::runtime_error("Scene not found: " + name);
        }
    }

    SDL_Renderer* Game::getRenderer() const {
        return m_renderer;
    }

    bool Game::isRunning() const {
        return m_isRunning;
    }

} // namespace tramplib