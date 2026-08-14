#include <player.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/animated_sprite2d.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/timer.hpp>
#include <godot_cpp/variant/signal.hpp>
#include <godot_cpp/classes/area2d.hpp>

void Player::set_base_velocity(double value) {
    base_velocity = value;
    
};

double Player::get_base_velocity() const {
    return base_velocity;
}

void Player::run(godot::AnimatedSprite2D* animator){
    godot::Vector2 velocity = godot::Input::get_singleton()->get_vector("left", "right", "up", "down") * base_velocity;
    set_velocity(velocity);
    
    godot::Vector2 speed = get_velocity();
    if(speed.is_zero_approx()) {
        animator->play("idle");
    }else {
        animator->play("walk");
        move_and_slide();
    };
}

godot::AnimatedSprite2D* Player::getAni() const {
    return godot::Node::get_node<godot::AnimatedSprite2D>("AnimatedSprite2D");
};

void Player::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("set_base_velocity", "value"), &Player::set_base_velocity);
    godot::ClassDB::bind_method(godot::D_METHOD("get_base_velocity"), &Player::get_base_velocity);

    godot::ClassDB::bind_method(godot::D_METHOD("run", "animator"), &Player::run);
    godot::ClassDB::bind_method(godot::D_METHOD("getAni"), &Player::getAni);

    ADD_PROPERTY(godot::PropertyInfo(godot::Variant::FLOAT, "base_velocity"), "set_base_velocity", "get_base_velocity");
};