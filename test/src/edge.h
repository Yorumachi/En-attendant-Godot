#pragma once

#include "killzone.h"
#include <godot_cpp/classes/timer.hpp>
#include <godot_cpp/variant/callable.hpp>

class Edge: public Killzone {
    GDCLASS(Edge, Killzone);

public:
    Edge();
    ~Edge();

    void _ready() override;
    void _on_enter_body(godot::Node2D* body);
    void _on_timeout();

    godot::Timer* timer;
protected:
    static void _bind_methods();

private:
    
};