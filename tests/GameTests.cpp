#include <gtest/gtest.h>
#include "TramposoLibrary/Game.h"
#include "TramposoLibrary/Sprite.h"

namespace TramposoLibrary {

    class GameTests : public ::testing::Test {
    protected:
        void SetUp() override {
            game = std::make_unique<Game>("Test Game", 800, 600);
        }

        std::unique_ptr<Game> game;
    };

    TEST_F(GameTests, Initialization) {
        EXPECT_NE(game, nullptr);
        EXPECT_FALSE(game->isRunning());
    }

    TEST_F(GameTests, AddSprite) {
        auto sprite = std::make_shared<Sprite>(game->getRenderer(), "test.png", 0, 0);
        EXPECT_NO_THROW(game->addSprite(sprite));
        // Add more specific checks here, e.g., sprite count
    }

    TEST_F(GameTests, RunAndQuit) {
        EXPECT_FALSE(game->isRunning());
        game->run();
        EXPECT_TRUE(game->isRunning());
        game->quit();
        EXPECT_FALSE(game->isRunning());
    }


} // TramposoLibrary