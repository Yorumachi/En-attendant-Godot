#pragma once

#include "enemy.h"

class Hare: public Enemy {
    GDCLASS(Hare, Enemy)

public:
    Hare();
    ~Hare();

    void set_hp();
    int64_t get_hp() const;

    
protected:
    static void _bind_methods();
private:
    int64_t hp;
};