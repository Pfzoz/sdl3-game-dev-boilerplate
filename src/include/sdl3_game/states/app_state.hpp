#ifndef SDL_CONTEXT_HPP
#define SDL_CONTEXT_HPP

#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <memory>

class App_State {
private:
    bool quit = false, initialized = false;
    Uint64 current_timestamp, last_timestamp;
    double delta_time = 0;
    void init();

protected:
    static std::unique_ptr<App_State> state;

    App_State(){};
public:
    int screen_width = 800;
    int screen_height = 600;
    SDL_Event event;

    bool is_initialized();
    bool get_quit();
    void set_quit(bool quit);

    App_State(App_State &other) = delete;
    void operator=(const App_State &) = delete;

    SDL_Window *window;
    SDL_Renderer *renderer;

    static App_State *init_state();
    double get_delta();

    void update();
    void destroy();

};

#endif
