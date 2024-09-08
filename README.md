# TramposoLibrary (tramplib)

TramposoLibrary, using the namespace `tramplib`, is a C++ game development library built on top of SDL2. It provides a set of classes and utilities to simplify 2D game development.

## Features

- Game loop management
- Scene-based game structure
- Sprite rendering
- Input handling
- Audio management (sound effects and music)
- Collision detection
- Text rendering
- Resource management
- State Management System
- Configuration File Support

## Prerequisites

- C++17 compatible compiler
- CMake 3.12 or higher
- vcpkg package manager
- SDL2, SDL2_image, SDL2_ttf, SDL2_mixer

## Installation

1. Clone the repository:
   ```
   git clone https://github.com/Tramposo1312/TramposoLibrary.git
   cd TramposoLibrary
   ```

2. Install dependencies using vcpkg:
   ```
   vcpkg install sdl2:x64-windows sdl2-image:x64-windows sdl2-ttf:x64-windows sdl2-mixer:x64-windows
   ```

3. Configure and build the project:
   ```
   mkdir build && cd build
   cmake .. -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake
   cmake --build . --config Release
   ```

## Usage

Here's a basic example of how to use `tramplib` namespace and the State Management System:

```cpp
#include <tramplib/Game.h>
#include <tramplib/GameState.h>

class MenuState : public tramplib::GameState {
public:
    MenuState(tramplib::Game* game) : GameState(game) {}
    
    void enter() override {
        // Initialize menu
    }
    
    void update(float deltaTime) override {
        // Update menu logic
    }
    
    void render() override {
        // Render menu
    }

    void exit() override {
        // Clean up menu resources
    }
};

class PlayState : public tramplib::GameState {
    // Similar implementation to MenuState
};

int main() {
    tramplib::Game game("My Game", 800, 600);
    
    // Load configuration
    game.getConfigManager().loadConfig("game_config.ini");
    
    // Push initial state
    game.pushState(std::make_unique<MenuState>(&game));
    
    game.run();
    return 0;
}
```

## Configuration File

You can create a configuration file (e.g., `game_config.ini`) with key-value pairs:

```ini
window_width=800
window_height=600
fullscreen=false
```

Access configuration values in your code:

```cpp
int width = std::stoi(game.getConfigManager().getValue("window_width", "800"));
```

## State Management

The State Management System allows you to organize your game into different states (e.g., Menu, Playing, Paused) and easily switch between them:

- `pushState`: Add a new state on top of the current one
- `popState`: Remove the current state and return to the previous one
- `changeState`: Replace the current state with a new one

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.
