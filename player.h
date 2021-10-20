#ifndef PLAYER_H
#define PLAYER_H
#include "warrior.h"

class player : public warrior
{
public:
    player(int _hp, int _dmg, int _speed) : warrior(_hp, _dmg, _speed) {};
    void set_speed(int new_speed) override;
    void set_dmg(int new_dmg) override;
    bool take_dmg(int damage) override;
    void move(vector2i new_pos) override;
    vector2i get_pos() override;
    void attack(std::shared_ptr<warrior> target) override;
    void special_action() override;
    int get_dmg() override;
};

#endif // PLAYER_H
