#include "sdl3_game/states/app.hpp"
#include "sdl3_game/texture_management/texture_management.hpp"
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

Uint64 current_timestamp = 0, last_timestamp = 0;

App_State state;

bool Game::Core::init() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    state.window = SDL_CreateWindow("App", state.screen_width, state.screen_height, SDL_WINDOW_RESIZABLE);
    SDL_SetWindowPosition(state.window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    if (state.window == NULL) {
        SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    state.renderer = SDL_CreateRenderer(state.window, NULL);
    if (state.renderer == NULL) {
        SDL_Log("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    return true;
}

double Game::get_delta() {
    last_timestamp = current_timestamp;
    current_timestamp = SDL_GetPerformanceCounter();
    return ((current_timestamp - last_timestamp) / (double)SDL_GetPerformanceFrequency());
}

App_State& Game::get_state() {
    return state;
}

void Game::quit() {
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    if (state.window != nullptr) SDL_DestroyWindow(state.window);
    if (state.renderer != nullptr) SDL_DestroyRenderer(state.renderer);
    Game::Textures::clear_textures();
    SDL_Quit();
}
