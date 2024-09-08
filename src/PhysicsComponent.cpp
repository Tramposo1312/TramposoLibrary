#include "tramplib/PhysicsComponent.h"
#include "tramplib/Sprite.h"

namespace tramplib {

    PhysicsComponent::PhysicsComponent(Sprite* owner) : Component(owner) {}

    void PhysicsComponent::update(float deltaTime) {
        m_velocityX += m_accelerationX * deltaTime;
        m_velocityY += m_accelerationY * deltaTime;

        SDL_Rect rect = m_owner->getRect();
        rect.x += static_cast<int>(m_velocityX * deltaTime);
        rect.y += static_cast<int>(m_velocityY * deltaTime);
        m_owner->setPosition(rect.x, rect.y);
    }

} // namespace tramplib