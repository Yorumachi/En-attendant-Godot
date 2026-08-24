#include "knight.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/project_settings.hpp>
#include <godot_cpp/classes/input_map.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/signal.hpp>

#define PRINT(a, ...) godot::UtilityFunctions::print(a, __VA_ARGS__)

Knight::Knight(){
    b_velocity = 100.0;
    input = godot::Input::get_singleton();
    p_gravity = godot::ProjectSettings::get_singleton()->get_setting("physics/2d/default_gravity");
    jump_velocity = -340;
    const char* lala = "lily";
};
Knight::~Knight(){

};

void Knight::_ready() {
    if(!godot::Engine::get_singleton()->is_editor_hint()){
        godot::InputMap::get_singleton()->load_from_project_settings();
        animator = get_node<godot::AnimatedSprite2D>("KnightAnimator");
    }
    
}

void Knight::_physics_process(double p_delta) {
    if(!godot::Engine::get_singleton()->is_editor_hint()){
        handle_move(p_delta);
    }
}

void Knight::set_b_velocity(double velocity){
    Knight::b_velocity = velocity; 
};

double Knight::get_b_velocity() const {
    return b_velocity;
};

void Knight::set_p_gravity(double p_gravity) {
    Knight::p_gravity = p_gravity;
};

double Knight::get_p_gravity() const {
    return p_gravity;
};

void Knight::set_jump_velocity(double velocity) {
    Knight::jump_velocity = velocity;
};

double Knight::get_jump_velocity() {
    return jump_velocity;
};

void Knight::handle_move(double delta){
    godot::Vector2 velocity = Knight::get_velocity();
    if(!Knight::is_on_floor()){
        velocity += Knight::get_gravity() * delta;
        animator->play("jump");
    }; 
    if(Knight::is_on_floor() && input->is_action_just_pressed("up")){
        velocity.y = get_jump_velocity();
    };
    double direction = input->get_axis("left", "right");
    if(direction) {
        godot::Vector2 scale = Knight::get_scale();
        if(direction < 0) {
            animator->set_flip_h(true);
        }else if(direction > 0) {
            animator->set_flip_h(false);
        }
        animator->play("run");
        velocity.x = direction * b_velocity;
        Knight::set_scale(scale);
    }else {
        animator->play("idle");
        velocity.x = godot::UtilityFunctions::move_toward(velocity.x, 0, b_velocity);
    }
    Knight::set_velocity(velocity);
    move_and_slide();
};

void Knight::resetting_gravity() {
   set_p_gravity(godot::ProjectSettings::get_singleton()->get_setting("physics/2d/default_gravity"));
};

void Knight::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("set_b_velocity", "value"), &set_b_velocity);
    godot::ClassDB::bind_method(godot::D_METHOD("get_b_velocity"), &get_b_velocity);
    godot::ClassDB::bind_method(godot::D_METHOD("set_p_gravity", "p_gravity"),&set_p_gravity);
    godot::ClassDB::bind_method(godot::D_METHOD("get_p_gravity"), &get_p_gravity);
    godot::ClassDB::bind_method(godot::D_METHOD("handle_move"), &handle_move);

    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::FLOAT, "b_velocity"), "set_b_velocity", "get_b_velocity");
    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::FLOAT, "p_gravity"), "set_p_gravity", "get_p_gravity");
};
