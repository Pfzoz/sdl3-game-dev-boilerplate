#include "sdl3_game/states/game.hpp"
#include "sdl3_game/texture_management/texture_management.hpp"
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_log.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <memory>

Uint64 current_timestamp = 0, last_timestamp = 0;
double delta;

struct SDLWindowDeleter {
    void operator()(SDL_Window* window) const noexcept {
        if (window) SDL_DestroyWindow(window);
    }
};

struct SDLRendererDeleter {
    void operator()(SDL_Renderer* renderer) const noexcept {
        if (renderer) SDL_DestroyRenderer(renderer);
    }
};

std::unique_ptr<SDL_Window, SDLWindowDeleter> window;
std::unique_ptr<SDL_Renderer, SDLRendererDeleter> renderer;

Game_State state;

double update_delta() {
    last_timestamp = current_timestamp;
    current_timestamp = SDL_GetPerformanceCounter();
    return ((current_timestamp - last_timestamp) / (double)SDL_GetPerformanceFrequency());
}

bool Game::Core::init() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    window = std::unique_ptr<SDL_Window, SDLWindowDeleter>(SDL_CreateWindow("App", state.screen_width, state.screen_height, SDL_WINDOW_RESIZABLE));
    SDL_SetWindowPosition(window.get(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    if (window == NULL) {
        SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    renderer = std::unique_ptr<SDL_Renderer, SDLRendererDeleter>(SDL_CreateRenderer(window.get(), nullptr));
    if (renderer == NULL) {
        SDL_Log("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }
    return true;
}

Game_State& Game::get_state() {
    return state;
}

double Game::get_delta() {
    return delta;
}

void Game::quit() {
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
    Game::Textures::clear_textures();
    SDL_Quit();
}

SDL_Window *Game::get_window() {
    return window.get();
}

SDL_Renderer *Game::get_renderer() {
    return renderer.get();
}

void Game::Core::handle_event(SDL_Event &event) {
    state.event = event;
    switch (event.type) {
        case SDL_EVENT_WINDOW_RESIZED:
            state.screen_width = event.window.data1;
            state.screen_height = event.window.data2;
            break;
        default:
            break;
    }
}

void Game::Core::update() {
    delta = update_delta();
}
