#include "tramplib.h"
#include <stdexcept>

namespace tramplib {

    AudioManager::AudioManager() : m_music(nullptr) {}

    AudioManager::~AudioManager() {
        stopMusic();
        for (auto& chunk : m_soundEffects) {
            Mix_FreeChunk(chunk);
        }
    }

    void AudioManager::playSound(const std::string& soundFile) {
        Mix_Chunk* chunk = Mix_LoadWAV(soundFile.c_str());
        if (!chunk) {
            throw std::runtime_error("Failed to load sound effect: " + std::string(Mix_GetError()));
        }
        m_soundEffects.push_back(chunk);
        Mix_PlayChannel(-1, chunk, 0);
    }

    void AudioManager::playMusic(const std::string& musicFile, int loops) {
        stopMusic();
        m_music = Mix_LoadMUS(musicFile.c_str());
        if (!m_music) {
            throw std::runtime_error("Failed to load music: " + std::string(Mix_GetError()));
        }
        Mix_PlayMusic(m_music, loops);
    }

    void AudioManager::stopMusic() {
        if (m_music) {
            Mix_HaltMusic();
            Mix_FreeMusic(m_music);
            m_music = nullptr;
        }
    }

} 