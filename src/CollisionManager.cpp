#include "tramplib.h"

namespace tramplib {

bool CollisionManager::checkCollision(const SDL_Rect& rectA, const SDL_Rect& rectB) {
    return (rectA.x < rectB.x + rectB.w &&
            rectA.x + rectA.w > rectB.x &&
            rectA.y < rectB.y + rectB.h &&
            rectA.y + rectA.h > rectB.y);
}

} 