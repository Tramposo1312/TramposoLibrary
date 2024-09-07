#ifndef TRAMPOSO_AUDIO_MANAGER_H
#define TRAMPOSO_AUDIO_MANAGER_H

#include <SDL_mixer.h>
#include <string>
#include <vector>

namespace TramposoLibrary {

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

} 

#endif // TRAMPOSO_AUDIO_MANAGER_H