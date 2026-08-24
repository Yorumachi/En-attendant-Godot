#include "enemy.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <algorithm>
#include <random>

Fsm::Fsm(Fsm::Handlers handlers) {
    state = &Fsm::handle_state_init;
    handle_idle = handlers.idle_handler;
    handle_wander = handlers.wander_handler;
}

Fsm::~Fsm() {

}

template<typename T>
T Fsm::random(T min, T max){
    std::random_device rd;
    std::mt19937 mt(rd());

    std::uniform_real_distribution<T> rand(min, max);
    return rand(mt);
}

Fsm::status_t Fsm::handle_state_init(event_t event) {
    state = handle_idle;
    return Fsm::status_t::STATUS_TURN;
}

void Fsm::fsm_init(event_t event) {
    (this->*state)(Fsm::event_t::EVENT_STATE_INIT);
    //初始化?
    (this->*state)(Fsm::event_t::EVENT_STATE_ENTER);
}

void Fsm::fsm_dipatch(Fsm* fsm, event_t event){
    Fsm::status_t status = (fsm->*(fsm->state))(event);
    if(status == Fsm::status_t::STATUS_TURN){
        Fsm::state_hander_t pre_state = fsm->state; 
        (fsm->*pre_state)(Fsm::event_t::EVENT_STATE_EXIT);
        (fsm->*(fsm->state))(Fsm::event_t::EVENT_STATE_ENTER);
    }
}

// enemy

Enemy::Enemy(){
    velocity = godot::Vector2(16.0, 0);
}

Enemy::~Enemy(){

}

void Enemy::move(){
	godot::Vector2 position = get_position();
    set_position(position + velocity);
}

void Enemy::_ready() {

}

void Enemy::_physics_process(double p_delta) {
    if(!godot::Engine::get_singleton()->is_editor_hint()){
        move();
    }
}

void Enemy::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("move"), &move);
    godot::ClassDB::bind_method(godot::D_METHOD("get_velocity"), &get_velocity);
    godot::ClassDB::bind_method(godot::D_METHOD("set_velocity", "vec"), &set_velocity);

    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::VECTOR2, "velocity"), "set_velocity", "get_velocity" );
}

godot::Vector2 Enemy::get_velocity() const {
    return velocity;
}; 

void Enemy::set_velocity(godot::Vector2 vec){
    velocity = vec;
}