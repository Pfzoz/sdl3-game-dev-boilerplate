#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_scancode.h>
#include "sdl3_game/screen/screen.hpp"
#include "sdl3_game/states/app_state.hpp"
#include "sdl3_game/states/screen_state.hpp"
#include "game.hpp"

Screen_State *screen_state = Screen_State::init_state();

void game_init(App_State *context) {
    screen_state->load_screen(context, new Screen);
}

void game_loop(App_State *context) {
    screen_state->render(context);
}

void handle_event(App_State *context) {
    if (context->event.type == SDL_EVENT_WINDOW_RESIZED) {
        context->screen_height = context->event.window.data2;
        context->screen_width = context->event.window.data1;
    }
    if (context->event.type == SDL_EVENT_QUIT) {
        SDL_Log("Quitting...");
        context->set_quit(true);
    }
    screen_state->handle_event(context);
}

void game_close(App_State *context) {
    screen_state->close_screen(context);
}
