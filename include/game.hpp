#ifndef GAME_HPP
#define GAME_HPP

#include "sdl3_game/states/app_state.hpp"

void game_init(App_State *context);
void game_loop(App_State *context);
void handle_event(App_State *context);
void game_close(App_State *context);

#endif
