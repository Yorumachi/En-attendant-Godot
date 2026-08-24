#include "killzone.h"
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

void Killzone::kill_player() {
    Killzone::get_tree()->reload_current_scene();
};

void Killzone::harm_player(double harm_value) {
    godot::UtilityFunctions::print("- ", harm_value);
};

void Killzone::_bind_methods() {
    godot::ClassDB::bind_method(godot::D_METHOD("kill_player"), &kill_player);
    godot::ClassDB::bind_method(godot::D_METHOD("harm_player"), &harm_player);
};