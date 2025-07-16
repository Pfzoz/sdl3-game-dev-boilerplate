#pragma once

#include <SDL3/SDL_events.h>
struct SDL_Renderer;
struct SDL_Window;

struct App_State {
    SDL_Event event;
    int screen_height = 800, screen_width = 600;
    SDL_Renderer *renderer = nullptr;
    SDL_Window *window = nullptr;
};

namespace SDL3_Game {

    namespace Core {
        bool init();
    }

    App_State &get_state();
    double get_delta();
    void quit();
}
