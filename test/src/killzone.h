#pragma once

#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/timer.hpp>

class Killzone: public godot::Area2D {
    GDCLASS(Killzone, godot::Area2D);
public:
    void kill_player();
    void harm_player(double harm_value);

protected:
    static void _bind_methods();

private:
};