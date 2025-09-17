#ifndef ACTOR_HPP
#define ACTOR_HPP

#include <functional>
#include <string>

struct Game_State;
struct SDL_FRect;
struct SDL_FPoint;

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
    virtual void draw();
    virtual void act(float delta);
    virtual bool touches(SDL_FPoint rect);

    void scale(float s);

    void on_click(bool touched, bool first_hit);
    void set_click_event(std::function<void(Actor *, bool, bool)> event);
private:
    std::function<void(Actor *, bool, bool)> click_event = nullptr;
};

#endif
