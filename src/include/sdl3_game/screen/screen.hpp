#pragma once

#include "sdl3_game/scene/scene.hpp"
struct Game_State;

class Screen {
public:
    std::string name = "Screen Title";
    Scene scene;
    Screen();
    ~Screen();
    virtual void on_load(Game_State *app_state); // Every time it is opened on the app state
    virtual void on_close(Game_State *app_state); // Every time it is closed on the app state
    virtual void render(Game_State *app_state);
    virtual void handle_event(Game_State *app_state);
};
