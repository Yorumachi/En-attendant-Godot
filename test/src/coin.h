#pragma once

#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node2d.hpp>

class Coin :public godot::Area2D {
    GDCLASS(Coin, godot::Area2D);

public:
    Coin();
    ~Coin();

    void _on_body_entered(godot::Node2D* body);
    void _ready() override;
protected:
    static void _bind_methods();
};