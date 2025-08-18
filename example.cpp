#include "sdl3_game/screen/screen.hpp"
#include "sdl3_game/states/screens.hpp"
#include <SDL3/SDL_init.h>
#include <memory>
#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>
#include "sdl3_game/states/app.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_surface.h>
#include <SDL3/SDL_video.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_timer.h>

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) {
    if (!Game::Core::init()) {
        return SDL_APP_FAILURE;
    }
    *appstate = &Game::get_state();
    Game::Screens::load_screen((App_State*) *appstate, std::make_unique<Screen>());
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    App_State *app_state = (App_State*) appstate;
    SDL_RenderClear(app_state->renderer);
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    App_State *app_state = (App_State*) appstate;
    app_state->event = *event;
    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
    Game::quit();
}
