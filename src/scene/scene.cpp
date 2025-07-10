#include "sdl3_game/scene/scene.hpp"
#include "sdl3_game/actors/actor.hpp"
#include "sdl3_game/states/app_state.hpp"
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_render.h>
#include <algorithm>
#include <memory>
#include <string>

Scene::~Scene() {
    this->actors.clear();
}

void Scene::add_actor(std::shared_ptr<Actor> actor) {
    actors.push_back(actor);
    actor->scene = this;
    set_z_index(actors.back().get(), actor->get_z_index());
}

void Scene::remove_actor(Actor* actor) {
    for (int i = actors.size() - 1; i >= 0; --i) {
        if (actors[i].get() == actor) {
            actors.erase(actors.begin() + i);
            break;
        }
    }
}

void Scene::remove_actor(std::string name) {
    for (int i = actors.size() - 1; i >= 0; --i) {
        if (actors[i].get()->name == name) {
            actors.erase(actors.begin() + i);
            break;
        }
    }
}

void Scene::clear_actors() {
    this->actors.clear();
}

void Scene::update(float delta) {
    for (auto& actor : actors) {
        actor->act(delta);
    }
}

void Scene::draw(App_State *context) {
    for (auto& actor : actors) {
        if (!actor->visible) continue;
        actor->draw(context);
    }
    SDL_RenderPresent(context->renderer);
}

Actor *Scene::get_actor(Actor *actor) {
    for (std::shared_ptr<Actor>& actor : actors) {
        if (actor == actor) {
            return actor.get();
        }
    }
    return nullptr;
}

Actor *Scene::get_actor(std::string name) {
    for (std::shared_ptr<Actor>& actor : actors) {
        if (actor->name == name) {
            return actor.get();
        }
    }
    return nullptr;
}

void Scene::handle_event(App_State *app_state) {
    if (app_state->event.type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
        bool first_hit = true;
        Actor *first_touched = nullptr;
        for (int i = actors.size() - 1; i > -1; i--) {
            std::shared_ptr<Actor> actor = actors[i];
            float x = app_state->event.button.x;
            float y = app_state->event.button.y;
            bool touched = actor->touches(app_state, {x, y});
            actor->on_click(app_state, touched, touched && first_hit);
            if (touched && first_hit) {
                first_touched = actor.get();
            }
            if (touched) first_hit = false;
        }
        if (click_event != nullptr) click_event(app_state, first_touched);
    }
}

int Scene::get_actor_index(Actor *actor) {
    for (int i = 0; i < actors.size(); i++) {
        if (actors[i].get() == actor) {
            return i;
        }
    }
    return -1;
}

void Scene::sort_actors() {
    std::sort(actors.begin(), actors.end(), [](const std::shared_ptr<Actor>& a, const std::shared_ptr<Actor>& b) {
        return a->_z_index < b->_z_index;
    });
    int z_counter = 0;
    for (std::shared_ptr<Actor> actor : actors) {
        if (actor->_z_index > z_counter) {
            actor->_z_index = z_counter;
        } else {
            z_counter = actor->_z_index;
            z_counter++;
        }
    }
}

void Scene::set_z_index(Actor *actor, int z_index) {
    actor->_z_index = z_index;
    sort_actors();
}

void Scene::set_on_click_event(void (*event)(App_State *app_state, Actor *actor)) {
    this->click_event = event;
}
