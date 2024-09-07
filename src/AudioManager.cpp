#include "TramposoLibrary/AudioManager.h"

namespace TramposoLibrary {

    AudioManager::AudioManager() : m_music(nullptr) {
        // TODO: Initialize audio system
    }

    AudioManager::~AudioManager() {
        stopMusic();
        for (auto& chunk : m_soundEffects) {
            Mix_FreeChunk(chunk);
        }
    }

    void AudioManager::playSound(const std::string& soundFile) {
        // TODO: Implement sound playing
    }

    void AudioManager::playMusic(const std::string& musicFile, int loops) {
        // TODO: Implement music playing
    }

    void AudioManager::stopMusic() {
        if (m_music) {
            Mix_HaltMusic();
            Mix_FreeMusic(m_music);
            m_music = nullptr;
        }
    }

} // TramposoLibrary