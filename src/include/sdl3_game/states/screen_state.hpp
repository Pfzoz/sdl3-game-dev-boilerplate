#ifndef SCENE_STATE_HPP
#define SCENE_STATE_HPP

#include "sdl3_game/screen/screen.hpp"
#include "sdl3_game/states/app_state.hpp"
#include <memory>

class Screen_State {
private:
    bool initialized = false;
    void init();
    std::unique_ptr<Screen> screen;
protected:
    static std::unique_ptr<Screen_State> state;

    Screen_State(){};
public:
    static Screen_State *init_state();
    Screen_State(Screen_State &other) = delete;
    void operator=(const Screen_State &) = delete;

    void load_screen(App_State *app_state, Screen *screen);
    void close_screen(App_State *app_state);
    void render(App_State *app_state);
    void handle_event(App_State *app_state);
};

#endif
