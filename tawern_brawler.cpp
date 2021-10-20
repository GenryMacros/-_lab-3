#include "tawern_brawler.h"

void tawern_brawler::set_speed(int new_speed)
{
    speed = new_speed;
};
void tawern_brawler::set_dmg(int new_dmg)
{
    dmg = new_dmg;
};
bool tawern_brawler::take_dmg(int damage)
{
    hp -= damage;
    return hp <= 0;
};
void tawern_brawler::move(vector2i new_pos)
{
    pos.x -= speed;
    if(pos.x < 0)
        pos.x = 1;
    pos.y -= speed;
    if(pos.y < 0)
        pos.y = 1;
};
vector2i tawern_brawler::get_pos()
{
    return pos;
};
void tawern_brawler::attack(std::shared_ptr<warrior> target)
{
    vector2i target_pos = target->get_pos();
    int x_difference = std::abs(target_pos.x - pos.x);
    int y_difference = std::abs(target_pos.y - pos.y);
    target->take_dmg(
                x_difference == 1 &&
                y_difference == 1 ?
                    dmg : 0);
};

int tawern_brawler::get_dmg()
{
    return dmg;
}

void tawern_brawler::special_action()
{
    if (speed != 1)
    {
        speed -= 1;
        dmg += 1;
    }
};
