#include "sdl3_game/screen/screen.hpp"
#include "sdl3_game/states/game.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_log.h>

Screen::Screen() {}
Screen::~Screen() {}
void Screen::handle_event(SDL_Event *event) {}
void Screen::on_close() {}
void Screen::on_load() {}
void Screen::render() {}
