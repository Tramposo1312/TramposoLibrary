#ifndef TRAMPOSO_COMPONENT_H
#define TRAMPOSO_COMPONENT_H

namespace tramplib {

    class Sprite;

    class Component {
    public:
        Component(Sprite* owner) : m_owner(owner) {}
        virtual ~Component() = default;

        virtual void update(float deltaTime) = 0;
        virtual void render() = 0;

    protected:
        Sprite* m_owner;
    };

} // tramplib

#endif // TRAMPOSO_COMPONENT_H