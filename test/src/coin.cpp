#include "coin.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/variant/signal.hpp>
#include <godot_cpp/variant/callable.hpp>
#include "knight.h"

Coin::Coin() {

};

Coin::~Coin() {

};

void Coin::_ready() {
    Coin::connect("body_entered", godot::Callable(this, "_on_body_entered"));
};

void Coin::_on_body_entered(godot::Node2D* body) {
    godot::UtilityFunctions::print("+1");
    queue_free();
};

void Coin::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("_on_body_entered", "body"), &_on_body_entered);
};