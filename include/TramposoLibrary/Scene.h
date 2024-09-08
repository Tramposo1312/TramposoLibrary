#ifndef TRAMPOSO_SCENE_H
#define TRAMPOSO_SCENE_H

#include <memory>
#include <vector>
#include "TramposoLibrary/Sprite.h"

namespace TramposoLibrary {

    class Game;

    class Scene {
    public:
        Scene(Game* game);
        virtual ~Scene() = default;

        virtual void load() = 0;
        virtual void unload() = 0;
        virtual void update(float deltaTime) = 0;
<<<<<<< HEAD
        virtual void render();  // Changed from pure virtual to virtual with implementation
=======
        virtual void render() = 0;
>>>>>>> ff39892716f02024ee20b509f89751aa88d65f92

        void addSprite(std::shared_ptr<Sprite> sprite);

    protected:
        Game* m_game;
        std::vector<std::shared_ptr<Sprite>> m_sprites;
    };

} // namespace TramposoLibrary

#endif // TRAMPOSO_SCENE_H