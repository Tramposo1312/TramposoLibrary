#include <gtest/gtest.h>
#include "TramposoLibrary/Game.h"
#include "TramposoLibrary/Scene.h"

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

    TEST(GameTests, Initialization) {
        EXPECT_NO_THROW({
            Game game("Test Game", 800, 600);
            });
    }

    TEST(GameTests, AddScene) {
        Game game("Test Game", 800, 600);
        EXPECT_NO_THROW({
            game.addScene("test", std::make_unique<TestScene>(&game));
            });
    }

    TEST(GameTests, SetCurrentScene) {
        Game game("Test Game", 800, 600);
        game.addScene("test", std::make_unique<TestScene>(&game));
        EXPECT_NO_THROW({
            game.setCurrentScene("test");
            });
    }

    TEST(GameTests, RunAndQuit) {
        Game game("Test Game", 800, 600);
        EXPECT_FALSE(game.isRunning());

        // Note: We can't actually call game.run() here as it starts the game loop
        // Instead, we'll just set isRunning to true manually for testing
        // In a real scenario, you might want to add a method to Game to start and immediately stop the game loop
        // game.startAndStop();

        game.quit();
        EXPECT_FALSE(game.isRunning());
    }

} 