#include "tramplib/CollisionManager.h"

namespace tramplib {

    void CollisionManager::addCollider(const std::string& name, const SDL_Rect& rect) {
        m_colliders[name] = rect;
    }

    void CollisionManager::removeCollider(const std::string& name) {
        m_colliders.erase(name);
    }

    void CollisionManager::updateCollider(const std::string& name, const SDL_Rect& rect) {
        m_colliders[name] = rect;
    }

    bool CollisionManager::checkCollision(const std::string& name1, const std::string& name2) {
        auto it1 = m_colliders.find(name1);
        auto it2 = m_colliders.find(name2);

        if (it1 == m_colliders.end() || it2 == m_colliders.end()) {
            return false;
        }

        const SDL_Rect& rect1 = it1->second;
        const SDL_Rect& rect2 = it2->second;

        return (rect1.x < rect2.x + rect2.w &&
            rect1.x + rect1.w > rect2.x &&
            rect1.y < rect2.y + rect2.h &&
            rect1.y + rect1.h > rect2.y);
    }

    void CollisionManager::checkCollisions() {
        for (auto it1 = m_colliders.begin(); it1 != m_colliders.end(); ++it1) {
            auto it2 = it1;
            ++it2;
            for (; it2 != m_colliders.end(); ++it2) {
                if (checkCollision(it1->first, it2->first)) {
                    // Collision detected so Trigger an event or callback here
                }
            }
        }
    }

} // tramplib