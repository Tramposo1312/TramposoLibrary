#include "TramposoLibrary/ResourceManager.h"
#include <stdexcept>

namespace TramposoLibrary {

    ResourceManager::ResourceManager() : m_music(nullptr) {
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
            throw std::runtime_error("SDL_mixer could not initialize! SDL_mixer Error: " + std::string(Mix_GetError()));
        }
        if (TTF_Init() == -1) {
            throw std::runtime_error("SDL_ttf could not initialize! SDL_ttf Error: " + std::string(TTF_GetError()));
        }
    }

    ResourceManager::~ResourceManager() {
        for (auto& chunk : m_soundEffects) {
            Mix_FreeChunk(chunk.second);
        }
        if (m_music) {
            Mix_FreeMusic(m_music);
        }
        for (auto& font : m_fonts) {
            TTF_CloseFont(font.second);
        }
        TTF_Quit();
        Mix_CloseAudio();
    }
    void ResourceManager::loadSound(const std::string& name, const std::string& filename) {
        Mix_Chunk* chunk = Mix_LoadWAV(filename.c_str());
        if (!chunk) {
            throw std::runtime_error("Failed to load sound effect! SDL_mixer Error: " + std::string(Mix_GetError()));
        }
        m_soundEffects[name] = chunk;
    }

    void ResourceManager::playSound(const std::string& name) {
        auto it = m_soundEffects.find(name);
        if (it != m_soundEffects.end()) {
            Mix_PlayChannel(-1, it->second, 0);
        }
    }

    void ResourceManager::loadMusic(const std::string& filename) {
        if (m_music) {
            Mix_FreeMusic(m_music);
        }
        m_music = Mix_LoadMUS(filename.c_str());
        if (!m_music) {
            throw std::runtime_error("Failed to load music! SDL_mixer Error: " + std::string(Mix_GetError()));
        }
    }

    void ResourceManager::playMusic() {
        if (m_music) {
            Mix_PlayMusic(m_music, -1);
        }
    }

    void ResourceManager::pauseMusic() {
        Mix_PauseMusic();
    }

    void ResourceManager::resumeMusic() {
        Mix_ResumeMusic();
    }

    void ResourceManager::stopMusic() {
        Mix_HaltMusic();
    }


    void ResourceManager::loadFont(const std::string& name, const std::string& filename, int fontSize) {
        TTF_Font* font = TTF_OpenFont(filename.c_str(), fontSize);
        if (!font) {
            throw std::runtime_error("Failed to load font! SDL_ttf Error: " + std::string(TTF_GetError()));
        }
        m_fonts[name] = font;
    }

    SDL_Texture* ResourceManager::renderText(SDL_Renderer* renderer, const std::string& text, const std::string& fontName, SDL_Color color) {
        auto it = m_fonts.find(fontName);
        if (it == m_fonts.end()) {
            throw std::runtime_error("Font not found: " + fontName);
        }

        SDL_Surface* surfaceMessage = TTF_RenderText_Solid(it->second, text.c_str(), color);
        if (!surfaceMessage) {
            throw std::runtime_error("Failed to render text! SDL_ttf Error: " + std::string(TTF_GetError()));
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surfaceMessage);
        SDL_FreeSurface(surfaceMessage);

        if (!texture) {
            throw std::runtime_error("Failed to create texture from rendered text! SDL Error: " + std::string(SDL_GetError()));
        }

        return texture;
    }
} 