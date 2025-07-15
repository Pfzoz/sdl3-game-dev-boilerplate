#include <SDL3/SDL_init.h>
#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>
#include "sdl3_game/states/app_state.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_timer.h>
#include "game.hpp"

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) {
    App_State global_app_state = SDL3_Game::get_state();
    if (!global_app_state.initialized) {
        return SDL_APP_FAILURE;
    }
    game_init(&global_app_state);
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    App_State *global_app_state = (App_State*) appstate;
    SDL_RenderClear(global_app_state->renderer);
    game_loop(global_app_state);
    if (SDL3_Game::Core::is_quit()) {
        game_close(global_app_state);
        return SDL_APP_SUCCESS;
    }
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    App_State *global_app_state = (App_State*) appstate;
    global_app_state->event = *event;
    handle_event(global_app_state);
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
    App_State *global_app_state = (App_State*) appstate;
    SDL_Quit();
}
