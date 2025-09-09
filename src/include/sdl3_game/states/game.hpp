#pragma once

#include <SDL3/SDL_events.h>
#include <memory>
struct SDL_Renderer;
struct SDL_Window;

struct Screen;

namespace Game {

    namespace Core {
        bool init();
        void handle_event(SDL_Event &event);
        void update();
        void render();
    }

    double get_delta();
    void quit();

    SDL_Window *get_window();
    SDL_Renderer *get_renderer();

    void load_screen(std::unique_ptr<Screen> screen);
    void close_screen();
}
