#include "TramposoLibrary/PhysicsComponent.h"
<<<<<<< HEAD
#include "TramposoLibrary/Sprite.h"
=======
>>>>>>> ff39892716f02024ee20b509f89751aa88d65f92

namespace TramposoLibrary {

    PhysicsComponent::PhysicsComponent(Sprite* owner) : Component(owner) {}

    void PhysicsComponent::update(float deltaTime) {
<<<<<<< HEAD
        m_velocityX += m_accelerationX * deltaTime;
        m_velocityY += m_accelerationY * deltaTime;

        SDL_Rect rect = m_owner->getRect();
        rect.x += static_cast<int>(m_velocityX * deltaTime);
        rect.y += static_cast<int>(m_velocityY * deltaTime);
        m_owner->setPosition(rect.x, rect.y);
    }

} 
=======
        // Implementation to be added
    }

} // TramposoLibrary
>>>>>>> ff39892716f02024ee20b509f89751aa88d65f92
