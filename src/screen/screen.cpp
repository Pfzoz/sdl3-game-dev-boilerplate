#include "sdl3_game/screen/screen.hpp"
#include "sdl3_game/states/game.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_log.h>

Screen::Screen() {}
Screen::~Screen() {}
void Screen::handle_event(Game_State *app_state) {}
void Screen::on_close(Game_State *app_state) {}
void Screen::on_load(Game_State *app_state) {}
void Screen::render(Game_State *app_state) {}
