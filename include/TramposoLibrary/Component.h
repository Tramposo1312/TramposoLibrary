#ifndef TRAMPOSO_COMPONENT_H
#define TRAMPOSO_COMPONENT_H

namespace TramposoLibrary {

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

} // TramposoLibrary

#endif // TRAMPOSO_COMPONENT_H