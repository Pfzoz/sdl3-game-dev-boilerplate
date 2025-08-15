#pragma once

struct App_State;

void game_init(App_State *context);
void game_loop(App_State *context);
void handle_event(App_State *context);
void game_close(App_State *context);
