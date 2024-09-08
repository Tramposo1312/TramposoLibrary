#ifndef TRAMPOSO_PHYSICS_COMPONENT_H
#define TRAMPOSO_PHYSICS_COMPONENT_H

<<<<<<< HEAD
#include "Component.h"

namespace TramposoLibrary {

    class Sprite;

    class PhysicsComponent : public Component {
    public:
        PhysicsComponent(Sprite* owner);
        void update(float deltaTime) override;
        void render() override {}  // Physics component doesn't render anything
=======
#include "TramposoLibrary/Component.h"

namespace TramposoLibrary {

    class PhysicsComponent : public Component {
    public:
        PhysicsComponent(Sprite* owner);

        void update(float deltaTime) override;
        void render() override {} // Physics component doesn't render anything
>>>>>>> ff39892716f02024ee20b509f89751aa88d65f92

        void setVelocity(float x, float y) {
            m_velocityX = x; m_velocityY = y;
        }
        void setAcceleration(float x, float y) {
            m_accelerationX = x; m_accelerationY = y;
        }

    private:
        float m_velocityX = 0.0f, m_velocityY = 0.0f;
        float m_accelerationX = 0.0f, m_accelerationY = 0.0f;
    };

<<<<<<< HEAD
} 

#endif
=======
} // TramposoLibrary

#endif // TRAMPOSO_PHYSICS_COMPONENT_H
>>>>>>> ff39892716f02024ee20b509f89751aa88d65f92
