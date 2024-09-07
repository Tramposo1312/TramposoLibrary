#ifndef TRAMPOSO_AUDIO_MANAGER_H
#define TRAMPOSO_AUDIO_MANAGER_H

#include <SDL_mixer.h>
#include <string>
#include <unordered_map>

namespace TramposoLibrary {

    class AudioManager {
    public:
        AudioManager();
        ~AudioManager();

        void loadSound(const std::string& name, const std::string& filename);
        void playSound(const std::string& name);

        void loadMusic(const std::string& filename);
        void playMusic();
        void pauseMusic();
        void resumeMusic();
        void stopMusic();

    private:
        std::unordered_map<std::string, Mix_Chunk*> m_soundEffects;
        Mix_Music* m_music;
    };

} // TramposoLibrary

#endif // TRAMPOSO_AUDIO_MANAGER_H