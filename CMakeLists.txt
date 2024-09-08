cmake_minimum_required(VERSION 3.12)
project(tramplib VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)
find_package(SDL2_mixer CONFIG REQUIRED)

# Specify source files
set(SOURCES
    src/Game.cpp
    src/Sprite.cpp
    src/InputManager.cpp
    src/ResourceManager.cpp
    src/CollisionManager.cpp
    src/Scene.cpp
    src/PhysicsComponent.cpp
)

# Add library
add_library(tramplib ${SOURCES})

# Set include directories for the library
target_include_directories(tramplib PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Link libraries
target_link_libraries(tramplib
    PUBLIC
    SDL2::SDL2 SDL2::SDL2main
    SDL2_image::SDL2_image
    SDL2_ttf::SDL2_ttf
    SDL2_mixer::SDL2_mixer
)

# Add demo game executable
add_executable(CatchGame src/CatchGame.cpp)
target_link_libraries(CatchGame PRIVATE tramplib)

# Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.11.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Add test executable
add_executable(tramposo_tests 
    tests/GameTests.cpp
    tests/SpriteTests.cpp
    tests/SceneTests.cpp
    tests/ComponentTests.cpp
)
target_link_libraries(tramposo_tests
    PRIVATE
    tramplib
    gtest_main
)

# Add the test
add_test(NAME TramposoTests COMMAND tramposo_tests)

# Set CMP0135 to NEW to avoid the warning
cmake_policy(SET CMP0135 NEW)