#pragma once

#include "sdl3_game/actors/actor.hpp"
#include "sdl3_game/states/app_state.hpp"
#include <string>
#include <vector>

class Scene {
private:
    std::vector<Actor*> actors;

    int get_actor_index(Actor *actor);
    void sort_actors();

    // events
    void (*click_event)(App_State *app_state, Actor *first_touched) = nullptr;

public:
    Scene() = default;
    ~Scene();

    void update(float delta);
    void draw(App_State* context);
    Actor *get_actor(std::string name);
    void add_actor(Actor* actor);
    void remove_actor(Actor* actor);
    void remove_actor(std::string name);
    void clear_actors();
    void handle_event(App_State *app_state);
    void set_z_index(Actor* actor, int z_index);

    // events setters
    void set_on_click_event(void (*event)(App_State *app_state, Actor *actor));
};
