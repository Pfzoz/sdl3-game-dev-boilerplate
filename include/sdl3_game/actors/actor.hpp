#ifndef ACTOR_HPP
#define ACTOR_HPP

#include "sdl3_game/states/app_state.hpp"
#include <SDL3/SDL_rect.h>
#include <string>

class Actor {
public:
    int _z_index = 0;
    float screen_x = 0, screen_y = 0, width = 0, height = 0;
    std::string name = "";
    bool visible = true;
    void *scene;

    ~Actor();

    int get_z_index();
    SDL_FRect get_rect();
    virtual void draw(App_State *app_state);
    virtual void act(float delta);
    virtual bool touches(App_State *app_state, SDL_FPoint rect);

    void scale(float s);

    void on_click(App_State *app_state, bool touched, bool first_hit);
    void set_click_event(void (*event)(App_State *app_state, Actor *actor, bool touched, bool first_hit)) {
        click_event = event;
    }
private:
    void (*click_event)(App_State *app_state, Actor *actor, bool touched, bool first_hit) = nullptr;
};

#endif
