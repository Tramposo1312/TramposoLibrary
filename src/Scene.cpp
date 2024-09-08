#include "tramplib/Scene.h"
#include "tramplib/Game.h"

namespace tramplib {

    Scene::Scene(Game* game) : m_game(game) {}

    void Scene::addSprite(std::shared_ptr<Sprite> sprite) {
        m_sprites.push_back(sprite);
    }

    void Scene::render() {
        for (const auto& sprite : m_sprites) {
            sprite->render();
        }
    }

} 
