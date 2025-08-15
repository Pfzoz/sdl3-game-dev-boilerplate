#include "sdl3_game/states/screens.hpp"
#include "sdl3_game/screen/screen.hpp"
#include "sdl3_game/states/app.hpp"
#include <memory>

std::unique_ptr<Screen> screen;

void Game::Screens::render(App_State *app_state) {
    if (screen == nullptr) return;
    screen->render(app_state);
}

void Game::Screens::handle_event(App_State *app_state) {
    if (screen == nullptr) return;
    screen->handle_event(app_state);
}

void Game::Screens::close_screen(App_State *app_state) {
    if (screen == nullptr) return;
    screen->on_close(app_state);
    screen.reset();
}

void Game::Screens::load_screen(App_State *app_state, Screen *new_screen) {
    if (screen != nullptr) {
        screen->on_close(app_state);
    }
    screen.reset(new_screen);
    screen->on_load(app_state);
    SDL_SetWindowTitle(app_state->window, screen->name.c_str());
}
