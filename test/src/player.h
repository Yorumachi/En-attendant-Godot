#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/animated_sprite2d.hpp>

class Player : public godot::CharacterBody2D {
public:
    GDCLASS(Player, godot::CharacterBody2D);

    double base_velocity;

    void set_base_velocity(double value);
    double get_base_velocity() const;
    
    void run(godot::AnimatedSprite2D* animator);

    godot::AnimatedSprite2D* getAni() const;
protected:
    static void _bind_methods();
};