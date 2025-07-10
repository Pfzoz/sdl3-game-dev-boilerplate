#include "sdl3_game/states/screen_state.hpp"
#include "sdl3_game/screen/screen.hpp"
#include "sdl3_game/states/app_state.hpp"
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_video.h>

Screen_State *Screen_State::init_state() {
    if (state.get()->initialized == false) {
        state.get()->init();
    }
    return state.get();
}

void Screen_State::init() {
    initialized = true;
}

std::unique_ptr<Screen_State> Screen_State::state(new Screen_State());

void Screen_State::render(App_State *app_state) {
    if (screen == nullptr) return;
    this->screen->render(app_state);
}

void Screen_State::handle_event(App_State *app_state) {
    if (screen == nullptr) return;
    this->screen->handle_event(app_state);
}

void Screen_State::close_screen(App_State *app_state) {
    if (screen == nullptr) return;
    this->screen->on_close(app_state);
    this->screen.reset();
}

void Screen_State::load_screen(App_State *app_state, Screen *screen) {
    if (this->screen != nullptr) {
        this->screen->on_close(app_state);
    }
    this->screen.reset(screen);
    this->screen->on_load(app_state);
    SDL_SetWindowTitle(app_state->window, this->screen->name.c_str());
}
