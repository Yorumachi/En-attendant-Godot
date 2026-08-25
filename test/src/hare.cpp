#include <hare.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/variant.hpp>

Hare::Hare() {
    hp = 0;
    Fsm<Hare>::Handlers* handler= new Fsm<Hare>::Handlers(&handle_idle, &handle_wander);  
}

Hare::~Hare(){
    delete fsm;
    fsm = nullptr;
}

void Hare::set_hp(int64_t value){
    hp = value;
}

int64_t Hare::get_hp() const {
    return hp;
}

FSM_T::status_t handle_idle(FSM_T::event_t event){

}

FSM_T::status_t handle_wander(FSM_T::event_t event){

}

void Hare::_ready() {

}

void Hare::_physics_process(double p_delta) {

}

void Hare::_bind_methods(){
    godot::ClassDB::bind_method(godot::D_METHOD("set_hp", "value"), &set_hp);
    godot::ClassDB::bind_method(godot::D_METHOD("get_hp"), &get_hp);
    godot::ClassDB::bind_method(godot::D_METHOD("handle_idle", "event"), &handle_idle);
    godot::ClassDB::bind_method(godot::D_METHOD("handle_wander", "event"), &handle_wander);

    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::INT, "hp"), "set_hp", "get_hp");
}