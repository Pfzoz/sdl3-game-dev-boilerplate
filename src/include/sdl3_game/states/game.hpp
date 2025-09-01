#pragma once

#include <SDL3/SDL_events.h>
#include <memory>
struct SDL_Renderer;
struct SDL_Window;

struct Game_State {
    SDL_Event event;
    int screen_height = 800, screen_width = 600;
};

struct Screen;

namespace Game {

    namespace Core {
        bool init();
        void handle_event(SDL_Event &event);
        void update();
        void render(Game_State *app_state);
        void handle_event(Game_State *app_state);
    }

    Game_State &get_state();
    double get_delta();
    void quit();

    SDL_Window *get_window();
    SDL_Renderer *get_renderer();

    void load_screen(Game_State *app_state, std::unique_ptr<Screen> screen);
    void close_screen(Game_State *app_state);
}
