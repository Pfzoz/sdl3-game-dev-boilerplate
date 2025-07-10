#include "sdl3_game/states/app_state.hpp"
#include <SDL3/SDL_init.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <cstdio>
#include <memory>

void App_State::destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

void App_State::init() {
    initialized = true;
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        initialized = false;
    }
    window = SDL_CreateWindow("App", screen_width, screen_height, SDL_WINDOW_RESIZABLE);
    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        initialized = false;
    }
    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        initialized = false;
    }
}

App_State *App_State::init_state() {
    if (state.get()->initialized == false) {
        state.get()->init();
    }
    return state.get();
}

std::unique_ptr<App_State> App_State::state(new App_State());

bool App_State::get_quit() {
    return this->quit;
}

bool App_State::is_initialized() {
    return initialized;
}

void App_State::set_quit(bool quit) {
    this->quit = quit;
}

void App_State::update() {
    last_timestamp = current_timestamp;
    current_timestamp = SDL_GetPerformanceCounter();

    delta_time = ((current_timestamp - last_timestamp) / (double)SDL_GetPerformanceFrequency());
}

double App_State::get_delta() { return delta_time; }
