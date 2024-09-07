#include <gtest/gtest.h>
#include "TramposoLibrary/Sprite.h"
#include "TramposoLibrary/PhysicsComponent.h"

namespace TramposoLibrary {

    TEST(SpriteTests, Creation) {
        SDL_Renderer* renderer = SDL_CreateRenderer(SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0), -1, 0);
        EXPECT_NO_THROW({
            Sprite sprite(renderer, "test.png", 0, 0);
            });
        SDL_DestroyRenderer(renderer);
    }

    TEST(SpriteTests, SetPosition) {
        SDL_Renderer* renderer = SDL_CreateRenderer(SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0), -1, 0);
        Sprite sprite(renderer, "test.png", 0, 0);

        sprite.setPosition(100, 200);
        SDL_Rect rect = sprite.getRect();
        EXPECT_EQ(rect.x, 100);
        EXPECT_EQ(rect.y, 200);

        SDL_DestroyRenderer(renderer);
    }

    TEST(SpriteTests, PhysicsComponent) {
        SDL_Renderer* renderer = SDL_CreateRenderer(SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0), -1, 0);
        Sprite sprite(renderer, "test.png", 0, 0);

        auto* physics = sprite.addComponent<PhysicsComponent>();
        EXPECT_NE(physics, nullptr);

        physics->setVelocity(10, 20);
        sprite.update(1.0f);  // Update for 1 second

        SDL_Rect rect = sprite.getRect();
        EXPECT_EQ(rect.x, 10);
        EXPECT_EQ(rect.y, 20);

        SDL_DestroyRenderer(renderer);
    }

} // namespace TramposoLibrary