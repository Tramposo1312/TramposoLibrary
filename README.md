# TramposoLibrary (tramplib)

TramposoLibrary ~`tramplib`~, is a C++ game development library built on top of SDL2. It provides a set of classes and utilities to simplify 2D game development.

## Features

- Game loop management
- Scene-based game structure
- Sprite rendering
- Input handling
- Audio management (sound effects and music)
- Collision detection
- Text rendering
- Resource management

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

Here's a basic example of how to use TramposoLibrary with the new `tramplib` namespace:

```cpp
#include <tramplib/Game.h>
#include <tramplib/Scene.h>

class MyScene : public tramplib::Scene {
public:
    MyScene(tramplib::Game* game) : Scene(game) {}
    
    void load() override {
        // Load resources, create sprites, etc.
    }
    
    void update(float deltaTime) override {
        // Update game logic
    }
    
    void render() override {
        // Render sprites and UI
    }
};

int main() {
    tramplib::Game game("My Game", 800, 600);
    game.addScene("myScene", std::make_unique<MyScene>(&game));
    game.setCurrentScene("myScene");
    game.run();
    return 0;
}
```

## Demo Game

The library includes a simple "Catch the Falling Objects" demo game (CatchGame). To run it:

```
cd build
./Debug/CatchGame  # or ./Release/CatchGame depending on your build configuration
```

## Current State

The library currently provides basic functionality for 2D game development, including:

- Game loop and scene management
- Sprite rendering
- Input handling
- Audio playback
- Collision detection
- Text rendering

The CatchGame demo showcases these features in a simple gameplay scenario.

## Future Plans

- Implement a particle system for visual effects
- Add support for sprite sheets and animations
- Implement a UI system (buttons, menus, etc.)
- Add support for tile maps
- Implement a simple physics system
- Add more advanced audio features (e.g., sound positioning, fading)
- Improve documentation and add more code examples

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.