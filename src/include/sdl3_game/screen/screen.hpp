#pragma once

#include "sdl3_game/scene/scene.hpp"
struct App_State;

class Screen {
public:
    std::string name = "Screen Title";
    Scene scene;
    Screen();
    ~Screen();
    virtual void on_load(App_State *app_state); // Every time it is opened on the app state
    virtual void on_close(App_State *app_state); // Every time it is closed on the app state
    virtual void render(App_State *app_state);
    virtual void handle_event(App_State *app_state);
};
