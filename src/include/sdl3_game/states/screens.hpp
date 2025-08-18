#pragma once

#include <memory>
class Screen;
struct Game_State;

namespace Game::Screens {
    void load_screen(Game_State *app_state, std::unique_ptr<Screen> screen);
    void close_screen(Game_State *app_state);
    void render(Game_State *app_state);
    void handle_event(Game_State *app_state);
}
