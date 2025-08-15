#pragma once

class Screen;
struct App_State;

namespace Game::Screens {
    void load_screen(App_State *app_state, Screen *screen);
    void close_screen(App_State *app_state);
    void render(App_State *app_state);
    void handle_event(App_State *app_state);
}
