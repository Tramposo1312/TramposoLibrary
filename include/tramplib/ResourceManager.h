#ifndef TRAMPOSO_RESOURCE_MANAGER_H
#define TRAMPOSO_RESOURCE_MANAGER_H

#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <string>
#include <unordered_map>

namespace tramplib {

    class ResourceManager {
    public:
        ResourceManager();
        ~ResourceManager();

        // Audio methods
        void loadSound(const std::string& name, const std::string& filename);
        void playSound(const std::string& name);
        void loadMusic(const std::string& filename);
        void playMusic();
        void pauseMusic();
        void resumeMusic();
        void stopMusic();

        // Text rendering methods
        void loadFont(const std::string& name, const std::string& filename, int fontSize);
        SDL_Texture* renderText(SDL_Renderer* renderer, const std::string& text, const std::string& fontName, SDL_Color color);

    private:
        std::unordered_map<std::string, Mix_Chunk*> m_soundEffects;
        Mix_Music* m_music;
        std::unordered_map<std::string, TTF_Font*> m_fonts;
    };

} 

#endif 