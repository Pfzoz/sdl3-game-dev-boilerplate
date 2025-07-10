#include "sdl3_game/screen/screen.hpp"
#include "sdl3_game/states/app_state.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_log.h>

Screen::Screen() {}
Screen::~Screen() {}
void Screen::handle_event(App_State *app_state) {}
void Screen::on_close(App_State *app_state) {}
void Screen::on_load(App_State *app_state) {}
void Screen::render(App_State *app_state) {}
