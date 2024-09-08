#ifndef TRAMPOSO_COLLISION_MANAGER_H
#define TRAMPOSO_COLLISION_MANAGER_H

#include <SDL.h>
#include <string>
#include <unordered_map>

namespace tramplib {

    class CollisionManager {
    public:
        void addCollider(const std::string& name, const SDL_Rect& rect);
        void removeCollider(const std::string& name);
        void updateCollider(const std::string& name, const SDL_Rect& rect);
        bool checkCollision(const std::string& name1, const std::string& name2);
        void checkCollisions();

    private:
        std::unordered_map<std::string, SDL_Rect> m_colliders;
    };

} 

#endif 