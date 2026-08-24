#include "edge.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

Edge::Edge() {
    
};

Edge::~Edge() {

};

void Edge::_ready() {
    timer = get_node<godot::Timer>("timer");
    connect("body_entered", godot::Callable(this, "_on_enter_body"));
    timer->connect("timeout", godot::Callable(this, "_on_timeout"));
};

void Edge::_on_enter_body(godot::Node2D* body) {
    godot::UtilityFunctions::print("enter");
    timer->start();
};

void Edge::_on_timeout() {
    godot::UtilityFunctions::print("timeout");
    kill_player();
};

void Edge::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("_on_enter_body", "body"), &_on_enter_body);
    godot::ClassDB::bind_method(godot::D_METHOD("_on_timeout"), &_on_timeout);
};