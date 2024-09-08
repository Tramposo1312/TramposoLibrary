#include "tramplib/Game.h"
#include "tramplib/Sprite.h"
#include "tramplib/Scene.h"
#include "tramplib/InputManager.h"
#include "tramplib/ResourceManager.h"
#include "tramplib/CollisionManager.h"
#include <random>
#include <memory>
#include <string>
#include <fstream>
#include <iostream>

class CatchGameScene : public tramplib::Scene {
public:
    CatchGameScene(tramplib::Game* game) : Scene(game), m_score(0), m_scoreTexture(nullptr) {}

    ~CatchGameScene() {
        if (m_scoreTexture) {
            SDL_DestroyTexture(m_scoreTexture);
        }
    }

    void load() override {
        m_player = std::make_shared<tramplib::Sprite>(m_game->getRenderer(), "../assets/player.png", 400, 550);
        m_fallingObject = std::make_shared<tramplib::Sprite>(m_game->getRenderer(), "../assets/object.png", 400, 0);
        addSprite(m_player);
        addSprite(m_fallingObject);

        m_game->getResourceManager().loadSound("catch", "../assets/catch.wav");
        //m_game->getResourceManager().loadMusic("../assets/background_music.mp3");
        m_game->getResourceManager().loadFont("score", "../assets/arial.ttf", 24);

        //m_game->getResourceManager().playMusic();

        m_game->getCollisionManager().addCollider("player", m_player->getRect());
        m_game->getCollisionManager().addCollider("object", m_fallingObject->getRect());

        updateScoreTexture();
    }

    void update(float deltaTime) override {
        handleInput(deltaTime);
        updateFallingObject(deltaTime);
        checkCollisions();
    }

    void render() override {
        Scene::render();
        renderScore();
    }

    void unload() override {
        m_game->getCollisionManager().removeCollider("player");
        m_game->getCollisionManager().removeCollider("object");
        if (m_scoreTexture) {
            SDL_DestroyTexture(m_scoreTexture);
            m_scoreTexture = nullptr;
        }
    }

private:
    std::shared_ptr<tramplib::Sprite> m_player;
    std::shared_ptr<tramplib::Sprite> m_fallingObject;
    int m_score;
    SDL_Texture* m_scoreTexture;

    void handleInput(float deltaTime) {
        const auto& input = m_game->getInputManager();
        int playerSpeed = 300;
        if (input.isKeyHeld(SDL_SCANCODE_LEFT)) {
            m_player->setPosition(std::max(0, static_cast<int>(m_player->getRect().x - playerSpeed * deltaTime)), m_player->getRect().y);
        }
        if (input.isKeyHeld(SDL_SCANCODE_RIGHT)) {
            m_player->setPosition(std::min(800 - m_player->getRect().w, static_cast<int>(m_player->getRect().x + playerSpeed * deltaTime)), m_player->getRect().y);
        }
        if (input.isKeyPressed(SDL_SCANCODE_ESCAPE)) {
            m_game->quit();
        }
    }

    void updateFallingObject(float deltaTime) {
        SDL_Rect objectRect = m_fallingObject->getRect();
        objectRect.y += static_cast<int>(200 * deltaTime);
        m_fallingObject->setPosition(objectRect.x, objectRect.y);

        if (objectRect.y > 600) {
            resetFallingObject();
        }
    }

    void checkCollisions() {
        m_game->getCollisionManager().updateCollider("player", m_player->getRect());
        m_game->getCollisionManager().updateCollider("object", m_fallingObject->getRect());

        if (m_game->getCollisionManager().checkCollision("player", "object")) {
            m_score++;
            m_game->getResourceManager().playSound("catch");
            resetFallingObject();
            updateScoreTexture();
        }
    }

    void resetFallingObject() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(0, 800 - m_fallingObject->getRect().w);

        m_fallingObject->setPosition(dis(gen), 0);
    }

    void updateScoreTexture() {
        if (m_scoreTexture) {
            SDL_DestroyTexture(m_scoreTexture);
        }
        std::string scoreText = "Score: " + std::to_string(m_score);
        SDL_Color textColor = { 96, 168, 255, 255 };
        m_scoreTexture = m_game->getResourceManager().renderText(m_game->getRenderer(), scoreText, "score", textColor);
    }

    void renderScore() {
        if (m_scoreTexture) {
            SDL_Rect destRect = { 10, 10, 0, 0 };
            SDL_QueryTexture(m_scoreTexture, nullptr, nullptr, &destRect.w, &destRect.h);
            SDL_RenderCopy(m_game->getRenderer(), m_scoreTexture, nullptr, &destRect);
        }
    }
};

int main(int argc, char* argv[]) {
    try {
        tramplib::Game game("Catch Game", 800, 600);
        game.addScene("catch_game", std::make_unique<CatchGameScene>(&game));
        game.setCurrentScene("catch_game");
        game.run();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}