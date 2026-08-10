#include "knight.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/project_settings.hpp>
#include <godot_cpp/classes/input_map.hpp>

Knight::Knight(){
    b_velocity = 100;
    input = godot::Input::get_singleton();
    p_gravity = godot::ProjectSettings::get_singleton()->get_setting("physics/2d/default_gravity");
};
Knight::~Knight(){

};

void Knight::_ready() {
    godot::InputMap::get_singleton()->load_from_project_settings();
    
}

void Knight::_physics_process(double p_delta) {
    handle_move();
}

void Knight::set_b_velocity(double velocity){
    Knight::b_velocity = velocity; 
};

double Knight::get_b_velocity() const {
    return b_velocity;
};

void Knight::handle_move(){
    const godot::Vector2 &velocity = input->get_vector("left", "right", "up", "down") * Knight::b_velocity;
    Knight::set_velocity(velocity);
    move_and_slide();
};

void Knight::set_p_gravity(double p_gravity) {
    Knight::p_gravity = p_gravity;
};
double Knight::get_p_gravity() const {
    return p_gravity;
};

void Knight::resetting_gravity() {
   set_p_gravity(godot::ProjectSettings::get_singleton()->get_setting("physics/2d/default_gravity"));
};

void Knight::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("set_b_velocity", "value"),&set_b_velocity);
    godot::ClassDB::bind_method(godot::D_METHOD("get_b_velocity"), &get_b_velocity);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_gravity", "p_gravity"),&set_p_gravity);
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_gravity"), &get_p_gravity);
    godot::ClassDB::bind_method(godot::D_METHOD("handle_move"), &handle_move);

    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::FLOAT, "b_velocity"), "set_b_velocity", "get_b_velocity");
    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::FLOAT, "p_gravity"), "set_p_gravity", "get_p_gravity");
};
