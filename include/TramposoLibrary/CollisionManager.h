#ifndef TRAMPOSO_COLLISION_MANAGER_H
#define TRAMPOSO_COLLISION_MANAGER_H

#include <SDL.h>

namespace TramposoLibrary {

    class CollisionManager {
    public:
        bool checkCollision(const SDL_Rect& rectA, const SDL_Rect& rectB);
    };

} // namespace TramposoLibrary

#endif // TRAMPOSO_COLLISION_MANAGER_H