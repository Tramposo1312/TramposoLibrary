#include "TramposoLibrary/Scene.h"
#include "TramposoLibrary/Game.h"

namespace TramposoLibrary {

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
