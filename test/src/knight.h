#pragma once

#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/animated_sprite2d.hpp>

class Knight: public godot::CharacterBody2D {
    GDCLASS(Knight, godot::CharacterBody2D);
public:
    Knight();
    ~Knight();
    
    godot::Input* input;

    void _ready() override;
    void _physics_process(double p_delta) override;

    void set_b_velocity(double velocity);
    double get_b_velocity() const;
    void set_p_gravity(double p_gravity);
    double get_p_gravity() const;
    void set_jump_velocity(double velocity);
    double get_jump_velocity();

    void handle_move(double delta);
    void resetting_gravity();
protected:
    static void _bind_methods();

private:
    double b_velocity;
    double p_gravity;
    double jump_velocity;
    godot::AnimatedSprite2D* animator;
};