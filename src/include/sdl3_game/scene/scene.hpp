#pragma once

#include "sdl3_game/actors/actor.hpp"
#include <SDL3/SDL_events.h>
#include <string>
#include <vector>

struct Game_State;

class Scene {
private:
    std::vector<Actor*> actors;

    int get_actor_index(Actor *actor);
    void sort_actors();

    // events
    void (*click_event)(Actor *first_touched) = nullptr;

public:
    Scene() = default;
    ~Scene();

    void update(float delta);
    void draw();
    Actor *get_actor(std::string name);
    void add_actor(Actor* actor);
    void remove_actor(Actor* actor);
    void remove_actor(std::string name);
    void clear_actors();
    void handle_event(SDL_Event *event);
    void set_z_index(Actor* actor, int z_index);

    // events setters
    void set_on_click_event(void (*event)(Actor *actor));
};
