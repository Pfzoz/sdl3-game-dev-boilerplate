cmake_minimum_required(VERSION 3.15...3.30.8)
project(SDL3Game VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

set(LIB_SOURCES
    src/actors/actor.cpp
    src/states/game.cpp
    src/states/screens.cpp
    src/texture_management/texture_management.cpp
    src/scene/scene.cpp
    src/screen/screen.cpp
)

add_library(SDL3Game ${LIB_SOURCES} ${LIB_HEADERS})

target_include_directories(SDL3Game PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include
)

target_link_libraries(SDL3Game PUBLIC
    SDL3::SDL3
    SDL3_image::SDL3_image
)
