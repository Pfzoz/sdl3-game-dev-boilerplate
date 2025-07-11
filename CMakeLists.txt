cmake_minimum_required(VERSION 3.15...3.30.8)
project(PROJECT_NAME VERSION 1.0
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

find_package(SDL3 REQUIRED)
include_directories(SDL3Test ${SDL3_INCLUDE_DIRS})

find_package(SDL3_image REQUIRED)
include_directories(${SDL3_INCLUDE_DIRS} ${SDL3_image_INCLUDE_DIRS})

include_directories(src/include)

set(SOURCES
    src/actors/actor.cpp
    src/states/app_state.cpp
    src/states/screen_state.cpp
    src/texture_manager/texture_manager.cpp
    src/scene/scene.cpp
    src/screen/screen.cpp
    game.cpp
    main.cpp
)

add_executable(app ${SOURCES})
target_link_libraries(app SDL3::SDL3 SDL3_image::SDL3_image)
