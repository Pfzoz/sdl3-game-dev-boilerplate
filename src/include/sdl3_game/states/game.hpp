#pragma once

#include <SDL3/SDL_events.h>
struct SDL_Renderer;
struct SDL_Window;

struct Game_State {
    SDL_Event event;
    int screen_height = 800, screen_width = 600;
};

namespace Game {

    namespace Core {
        bool init();
        void handle_event(SDL_Event &event);
        void update();
    }

    Game_State &get_state();
    double get_delta();
    void quit();

    SDL_Window *get_window();
    SDL_Renderer *get_renderer();
}
