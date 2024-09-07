#include "TramposoLibrary/AudioManager.h"
#include <stdexcept>

namespace TramposoLibrary {

    AudioManager::AudioManager() : m_music(nullptr) {
        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
            throw std::runtime_error("SDL_mixer could not initialize! SDL_mixer Error: " + std::string(Mix_GetError()));
        }
    }

    AudioManager::~AudioManager() {
        for (auto& chunk : m_soundEffects) {
            Mix_FreeChunk(chunk.second);
        }
        if (m_music) {
            Mix_FreeMusic(m_music);
        }
        Mix_CloseAudio();
    }

    void AudioManager::loadSound(const std::string& name, const std::string& filename) {
        Mix_Chunk* chunk = Mix_LoadWAV(filename.c_str());
        if (!chunk) {
            throw std::runtime_error("Failed to load sound effect! SDL_mixer Error: " + std::string(Mix_GetError()));
        }
        m_soundEffects[name] = chunk;
    }

    void AudioManager::playSound(const std::string& name) {
        auto it = m_soundEffects.find(name);
        if (it != m_soundEffects.end()) {
            Mix_PlayChannel(-1, it->second, 0);
        }
    }

    void AudioManager::loadMusic(const std::string& filename) {
        if (m_music) {
            Mix_FreeMusic(m_music);
        }
        m_music = Mix_LoadMUS(filename.c_str());
        if (!m_music) {
            throw std::runtime_error("Failed to load music! SDL_mixer Error: " + std::string(Mix_GetError()));
        }
    }

    void AudioManager::playMusic() {
        if (m_music) {
            Mix_PlayMusic(m_music, -1);
        }
    }

    void AudioManager::pauseMusic() {
        Mix_PauseMusic();
    }

    void AudioManager::resumeMusic() {
        Mix_ResumeMusic();
    }

    void AudioManager::stopMusic() {
        Mix_HaltMusic();
    }

} // TramposoLibrary