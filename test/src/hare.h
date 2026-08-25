#pragma once

#include "enemy.hpp"

#define FSM_T Fsm<Hare>

class Hare: public Enemy {
    GDCLASS(Hare, Enemy)

public:
    Hare();
    ~Hare();

    void set_hp(int64_t value);
    int64_t get_hp() const;

    void _ready() override;
    void _physics_process(double p_delta) override;

    FSM_T::status_t handle_idle(FSM_T::event_t event);
    FSM_T::status_t handle_wander(FSM_T::event_t event);
protected:
    static void _bind_methods();
private:
    int64_t hp;
    FSM_T* fsm;
};