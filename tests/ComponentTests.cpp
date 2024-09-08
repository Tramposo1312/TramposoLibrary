#include <gtest/gtest.h>
#include "TramposoLibrary/Sprite.h"
#include "TramposoLibrary/Component.h"

namespace TramposoLibrary {

    class TestComponent : public Component {
    public:
        TestComponent(Sprite* owner) : Component(owner), updated(false), rendered(false) {}

        void update(float deltaTime) override {
            updated = true;
        }

        void render() override {
            rendered = true;
        }

        bool updated;
        bool rendered;
    };

    TEST(ComponentTests, AddComponent) {
        SDL_Renderer* renderer = SDL_CreateRenderer(SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0), -1, 0);
        Sprite sprite(renderer, "test.png", 0, 0);

        auto* component = sprite.addComponent<TestComponent>();
        EXPECT_NE(component, nullptr);

        auto* retrievedComponent = sprite.getComponent<TestComponent>();
        EXPECT_EQ(component, retrievedComponent);

        SDL_DestroyRenderer(renderer);
    }

    TEST(ComponentTests, ComponentLifecycle) {
        SDL_Renderer* renderer = SDL_CreateRenderer(SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0), -1, 0);
        Sprite sprite(renderer, "test.png", 0, 0);

        auto* component = sprite.addComponent<TestComponent>();

        EXPECT_FALSE(component->updated);
        sprite.update(0.016f);
        EXPECT_TRUE(component->updated);

        EXPECT_FALSE(component->rendered);
        sprite.render();
        EXPECT_TRUE(component->rendered);

        SDL_DestroyRenderer(renderer);
    }

} 