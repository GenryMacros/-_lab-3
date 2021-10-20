#ifndef WARRIOR_H
#define WARRIOR_H
#include <memory>
struct vector2i
{
    int x;
    int y;
};

class warrior
{
protected:
    int hp;
    int dmg;
    int speed;
    vector2i pos;
public:
    warrior(int _hp, int _dmg, int _speed) : hp(_hp), dmg(_dmg), speed(_speed), pos({0,0}) {};
    virtual void set_speed(int new_speed) = 0;
    virtual void set_dmg(int new_dmg) = 0;
    virtual bool take_dmg(int damage) = 0;
    virtual void move(vector2i new_pos) = 0;
    virtual vector2i get_pos() = 0;
    virtual void attack(std::shared_ptr<warrior> target) = 0;
    virtual void special_action() = 0;
    virtual int get_dmg() = 0;
    virtual ~warrior() {};
    bool is_dead() {return hp <= 0;};
    int get_hp() {return hp;}
};

#endif // WARRIOR_H
