# TramposoLibrary

TramposoLibrary is a C++ 2D game development library built on top of SDL2. It provides a set of classes and utilities to simplify game development.

## Features

- Game loop management
- Scene-based game structure
- Sprite rendering
- Input handling
- Audio management
- Collision detection
- Basic physics components

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

Here's a basic example of how to use TramposoLibrary:

```cpp
#include <TramposoLibrary/Game.h>
#include <TramposoLibrary/Scene.h>

class MyScene : public TramposoLibrary::Scene {
public:
    MyScene(TramposoLibrary::Game* game) : Scene(game) {}
    
    void load() override {
        // Load resources, create sprites, etc.
    }
    
    void update(float deltaTime) override {
        // Update game logic
    }
    
    void render() override {
        // Render sprites
    }
};

int main() {
    TramposoLibrary::Game game("My Game", 800, 600);
    game.addScene("myScene", std::make_unique<MyScene>(&game));
    game.setCurrentScene("myScene");
    game.run();
    return 0;
}
```

## Documentation

For detailed API documentation, please refer to the `docs` folder.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
