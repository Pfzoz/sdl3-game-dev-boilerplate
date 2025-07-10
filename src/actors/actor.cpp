#include "sdl3_game/actors/actor.hpp"
#include "sdl3_game/states/app_state.hpp"
#include <SDL3/SDL_log.h>
#include <SDL3/SDL_rect.h>

Actor::~Actor() {}

SDL_FRect Actor::get_rect() {
    SDL_FRect rect;
    rect.h = this->height;
    rect.w = this->width;
    rect.x = this->screen_x;
    rect.y = this->screen_y;
    return rect;
}

void Actor::scale(float s) {
    this->width *= s;
    this->height *= s;
}

void Actor::act(float delta) {}
void Actor::draw(App_State *app_state) {}
void Actor::on_click(App_State *app_state, bool touched, bool first_hit) {
    if (click_event == nullptr) return;
    click_event(app_state, this, touched, first_hit);
}

bool Actor::touches(App_State *app_state, SDL_FPoint point) {
    if (point.x > this->screen_x + this->width || point.y > this->screen_y + this->height)
        return false;
    if (point.x < this->screen_x || point.y < this->screen_y)
        return false;
    return true;
}

int Actor::get_z_index() {
    return _z_index;
}
