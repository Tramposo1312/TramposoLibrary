#include "TramposoLibrary/Game.h"
#include "TramposoLibrary/Sprite.h"
#include "TramposoLibrary/Scene.h"
#include "TramposoLibrary/InputManager.h"
#include "TramposoLibrary/AudioManager.h"
#include "TramposoLibrary/CollisionManager.h"
#include <random>
#include <memory>
#include <iostream>
#include <fstream>
#include <SDL.h>
class CatchGameScene : public TramposoLibrary::Scene {
public:
    CatchGameScene(TramposoLibrary::Game* game) : Scene(game), m_score(0) {}

    void load() override {
        // Load player sprite
        m_player = std::make_shared<TramposoLibrary::Sprite>(m_game->getRenderer(), "../assets/player.png", 400, 550);
        addSprite(m_player);

        // Load falling object sprite
        m_fallingObject = std::make_shared<TramposoLibrary::Sprite>(m_game->getRenderer(), "../assets/object.png", 400, 0);
        addSprite(m_fallingObject);

        // Load audio
        m_game->getAudioManager().loadSound("catch", "../assets/catch.wav");
        m_game->getAudioManager().loadMusic("../assets/background_music.mp3");
        m_game->getAudioManager().playMusic();

        // Set up collision detection
        m_game->getCollisionManager().addCollider("player", m_player->getRect());
        m_game->getCollisionManager().addCollider("object", m_fallingObject->getRect());
    }

    void update(float deltaTime) override {
        // Handle player movement
        const auto& input = m_game->getInputManager();
        if (input.isKeyHeld(SDL_SCANCODE_LEFT)) {
            m_player->setPosition(static_cast<int>(m_player->getRect().x - 300 * deltaTime), m_player->getRect().y);
        }
        if (input.isKeyHeld(SDL_SCANCODE_RIGHT)) {
            m_player->setPosition(static_cast<int>(m_player->getRect().x + 300 * deltaTime), m_player->getRect().y);
        }

        // Update falling object position
        SDL_Rect objectRect = m_fallingObject->getRect();
        objectRect.y += static_cast<int>(200 * deltaTime);
        m_fallingObject->setPosition(objectRect.x, objectRect.y);

        // Check for collisions
        m_game->getCollisionManager().updateCollider("player", m_player->getRect());
        m_game->getCollisionManager().updateCollider("object", m_fallingObject->getRect());

        if (m_game->getCollisionManager().checkCollision("player", "object")) {
            // Object caught
            m_score++;
            m_game->getAudioManager().playSound("catch");
            resetFallingObject();
        }
        else if (objectRect.y > 600) {
            // Object missed
            resetFallingObject();
        }

        // Handle quit event
        if (input.isKeyPressed(SDL_SCANCODE_ESCAPE)) {
            m_game->quit();
        }
    }

    void render() override {
        Scene::render();
        // Render score (you might want to use SDL_ttf for proper text rendering)
        // For now, we'll just print to console
        std::cout << "Score: " << m_score << "\r" << std::flush;
    }

    void unload() override {
        m_game->getCollisionManager().removeCollider("player");
        m_game->getCollisionManager().removeCollider("object");
    }

private:
    std::shared_ptr<TramposoLibrary::Sprite> m_player;
    std::shared_ptr<TramposoLibrary::Sprite> m_fallingObject;
    int m_score;

    void resetFallingObject() {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        static std::uniform_int_distribution<> dis(0, 800);

        m_fallingObject->setPosition(dis(gen), 0);
    }
};

int main(int argc, char* argv[]) {
    try {
        SDL_Init(SDL_INIT_EVERYTHING);

        std::ofstream logFile("game_log.txt");
        logFile << "Starting game initialization..." << std::endl;

        logFile << "Creating game object..." << std::endl;
        TramposoLibrary::Game game("Catch Game", 800, 600);

        logFile << "Adding catch_game scene..." << std::endl;
        game.addScene("catch_game", std::make_unique<CatchGameScene>(&game));

        logFile << "Setting current scene..." << std::endl;
        game.setCurrentScene("catch_game");

        logFile << "Running game..." << std::endl;
        game.run();

        logFile << "Game finished normally." << std::endl;
        logFile.close();

        SDL_Quit();
    }
    catch (const std::exception& e) {
        std::ofstream logFile("game_log.txt", std::ios_base::app);
        logFile << "Error: " << e.what() << std::endl;
        logFile.close();

        std::cerr << "Error: " << e.what() << std::endl;
        SDL_Quit();
        return 1;
    }
    return 0;
}