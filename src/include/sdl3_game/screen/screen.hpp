#pragma once

#include "sdl3_game/scene/scene.hpp"
#include <SDL3/SDL_events.h>
struct Game_State;

class Screen {
public:
    std::string name = "Screen Title";
    Scene scene;
    Screen();
    ~Screen();
    virtual void on_load(); // Every time it is opened on the app state
    virtual void on_close(); // Every time it is closed on the app state
    virtual void render();
    virtual void handle_event(SDL_Event *event);
};
