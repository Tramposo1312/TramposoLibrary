#include <gtest/gtest.h>
#include "TramposoLibrary/Scene.h"
#include "TramposoLibrary/Game.h"
#include "TramposoLibrary/Sprite.h"

namespace TramposoLibrary {

    class TestScene : public Scene {
    public:
        TestScene(Game* game) : Scene(game) {}
        void load() override {
            loaded = true;
        }
        void unload() override {
            loaded = false;
        }
        void update(float deltaTime) override {
            updated = true;
        }
        void render() override {
            rendered = true;
        }

        bool loaded = false;
        bool updated = false;
        bool rendered = false;
    };

    TEST(SceneTests, SceneLifecycle) {
        Game game("Test Game", 800, 600);
        TestScene scene(&game);

        EXPECT_FALSE(scene.loaded);
        scene.load();
        EXPECT_TRUE(scene.loaded);

        EXPECT_FALSE(scene.updated);
        scene.update(0.016f);
        EXPECT_TRUE(scene.updated);

        EXPECT_FALSE(scene.rendered);
        scene.render();
        EXPECT_TRUE(scene.rendered);

        scene.unload();
        EXPECT_FALSE(scene.loaded);
    }

    TEST(SceneTests, AddSprite) {
        Game game("Test Game", 800, 600);
        TestScene scene(&game);
        auto sprite = std::make_shared<Sprite>(game.getRenderer(), "test.png", 0, 0);

        scene.addSprite(sprite);

        // TODO: Add a method to Scene to get the number of sprites
        // EXPECT_EQ(scene.getSpriteCount(), 1);
    }

} 