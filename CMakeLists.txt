cmake_minimum_required(VERSION 3.12)
project(TramposoLibrary VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(SDL2_ttf CONFIG REQUIRED)
find_package(SDL2_mixer CONFIG REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(TramposoLibrary
    src/Game.cpp
    src/Sprite.cpp
    src/InputManager.cpp
    src/AudioManager.cpp
    src/CollisionManager.cpp
)

target_link_libraries(TramposoLibrary
    PRIVATE
    SDL2::SDL2 SDL2::SDL2main
    SDL2_image::SDL2_image
    SDL2_ttf::SDL2_ttf
    SDL2_mixer::SDL2_mixer
)

install(TARGETS TramposoLibrary
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)
install(DIRECTORY include/ DESTINATION include)

# Add examples subdirectory
# Uncomment the following line when you're ready to add examples
# add_subdirectory(examples)

enable_testing()
# Uncomment the following line when you're ready to add tests
# add_subdirectory(tests)

# Add an executable for testing SDL2 setup
add_executable(sdl_test src/sdl_test.cpp)
target_link_libraries(sdl_test PRIVATE
    SDL2::SDL2 SDL2::SDL2main
    SDL2_image::SDL2_image
    SDL2_ttf::SDL2_ttf
    SDL2_mixer::SDL2_mixer
)