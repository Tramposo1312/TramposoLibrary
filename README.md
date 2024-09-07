# TramposoLibrary

TramposoLibrary is a C++ library designed to simplify 2D game development. It provides a set of tools and abstractions to handle common game development tasks, allowing developers to focus on creating engaging gameplay experiences.

## Features

- Easy-to-use game loop management
- Sprite rendering and manipulation
- Input handling
- Audio playback for sound effects and music
- Basic collision detection

## Requirements

- C++17 compatible compiler
- CMake (version 3.12 or higher)
- vcpkg package manager
- SDL2 and its extensions (SDL2_image, SDL2_ttf, SDL2_mixer)

## Building

To build TramposoLibrary, follow these steps:

1. Clone the repository:
   ```
   git clone https://github.com/yourusername/TramposoLibrary.git
   cd TramposoLibrary
   ```

2. Install the required packages using vcpkg:
   ```
   vcpkg install sdl2:x64-windows sdl2-image:x64-windows sdl2-ttf:x64-windows sdl2-mixer:x64-windows
   ```

3. Create a build directory and run CMake:
   ```
   mkdir build
   cd build
   cmake .. -DCMAKE_TOOLCHAIN_FILE=[path to vcpkg]/scripts/buildsystems/vcpkg.cmake
   ```

4. Build the project:
   ```
   cmake --build .
   ```

## Usage

Here's a simple example of how to use TramposoLibrary:

```cpp
#include <TramposoLibrary/Game.h>

int main(int argc, char* argv[]) {
    TramposoLibrary::Game game("My Game", 800, 600);
    
    // Add game objects, load resources, etc.
    
    game.run();
    return 0;
}
```

For more detailed examples, check the `examples` directory.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
