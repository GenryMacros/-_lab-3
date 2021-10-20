#include "player.h"

void player::set_speed(int new_speed)
{
    speed = new_speed;
};
void player::set_dmg(int new_dmg)
{
    dmg = new_dmg;
};
bool player::take_dmg(int damage)
{
    hp -= damage;
    return hp <= 0;
};
void player::move(vector2i new_pos)
{
    pos = new_pos;
};
vector2i player::get_pos()
{
    return pos;
};
void player::attack(std::shared_ptr<warrior> target)
{
    vector2i target_pos = target->get_pos();
    int x_difference = std::abs(target_pos.x - pos.x);
    int y_difference = std::abs(target_pos.y - pos.y);
    target->take_dmg(
                x_difference == 1 &&
                y_difference == 1 ?
                    dmg : 0);
};
void player::special_action()
{};

int player::get_dmg()
{
    return dmg;
}

