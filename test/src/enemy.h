#pragma once

#include "killzone.h"
#include <godot_cpp/classes/animated_sprite2d.hpp>

class Fsm {
public:
    enum class event_t{
        EVENT_STATE_INIT,
        EVENT_STATE_ENTER,
        EVENT_STATE_EXIT,
        EVENT_GOTO_IDLE,
        EVENT_GOTO_WANDER,
        EVENT_RUN_CURRENT,
    };

    enum class status_t{
        STATUS_TURN,
        STATUS_HANDLED,
    };

    typedef status_t (Fsm::*state_hander_t)(event_t);

    
    struct Handlers {
        state_hander_t idle_handler;
        state_hander_t wander_handler;
    };

    state_hander_t state;
    state_hander_t handle_idle;
    state_hander_t handle_wander;

    status_t handle_state_init(event_t event);
    Fsm(Handlers handlers);
    ~Fsm();
    void fsm_init(event_t event);
    template<typename T>
    static T random(T min = 0, T max = 1);
    static void fsm_dipatch(Fsm* fsm, event_t event);

};

class Enemy: public Killzone {
    GDCLASS(Enemy, Killzone);
public:
    Enemy();
    ~Enemy();
    void move();
    void _ready() override;
    void _physics_process(double p_delta) override;
    godot::Vector2 get_velocity() const;
    void set_velocity(godot::Vector2 vec);
protected:
    static void _bind_methods();
private:
    godot::Vector2 velocity;
};