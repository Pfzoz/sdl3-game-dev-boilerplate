#include "sdl3_game/actors/actor.hpp"
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
void Actor::draw() {}
void Actor::on_click(bool touched, bool first_hit) {
    if (click_event == nullptr) return;
    click_event(this, touched, first_hit);
}

bool Actor::touches(SDL_FPoint point) {
    if (point.x > this->screen_x + this->width || point.y > this->screen_y + this->height)
        return false;
    if (point.x < this->screen_x || point.y < this->screen_y)
        return false;
    return true;
}

int Actor::get_z_index() {
    return _z_index;
}

void Actor::set_click_event(std::function<void(Actor *, bool, bool)> event) {
    click_event = event;
}
