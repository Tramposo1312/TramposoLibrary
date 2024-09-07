#ifndef TRAMPOSO_SPRITE_H
#define TRAMPOSO_SPRITE_H

#include <SDL.h>
#include <string>

namespace TramposoLibrary {

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

} 

#endif // TRAMPOSO_SPRITE_H