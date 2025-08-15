#include <SDL3/SDL_events.h>
#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_scancode.h>
#include "sdl3_game/screen/screen.hpp"
#include "sdl3_game/states/app.hpp"
#include "sdl3_game/states/screens.hpp"
#include "game.hpp"

void game_init(App_State *context) {
    Game::Screens::load_screen(context, new Screen);
}

void game_loop(App_State *context) {
    Game::Screens::render(context);
}

void handle_event(App_State *context) {
    if (context->event.type == SDL_EVENT_WINDOW_RESIZED) {
        context->screen_height = context->event.window.data2;
        context->screen_width = context->event.window.data1;
    }
    if (context->event.type == SDL_EVENT_QUIT) {
        SDL_Log("Quitting...");
        Game::quit();
    }
    Game::Screens::handle_event(context);
}

void game_close(App_State *context) {
    Game::Screens::close_screen(context);
}
