#include "battle_state.h"
using namespace std;

battle_state::battle_state(unique_ptr<state> rem_state)
{
    remembered_state = move(rem_state);
    const unique_ptr<factory>& fact = remembered_state->get_factory();
    enemies.push_back(fact->create_simple());
    enemies.push_back(fact->create_simple());
    enemies.push_back(fact->create_simple());
    enemies[0]->move({20,20});
    enemies[1]->move({40,40});
    enemies[2]->move({60,60});
}

responce battle_state::process_answer(int choosed_ind)
{
    if(choosed_ind == -1)
    {
        return responce{{"Attack 1", "Attack 2", "Attack 3"}, "Battle started"};
    }
    if(is_victorious())
    {
        responce ret = remembered_state->process_answer(-1);
        holder->change_state(move(remembered_state));
        return ret;
    }
    make_move();
    auto& player = holder->get_player();
    vector<string> answ = {"Attack 1", "Attack 2", "Attack 3"};

    enemies[choosed_ind]->take_dmg(player.get_dmg());
    string en_ndead = "You damaged Enemy" + to_string(choosed_ind) + " for " + to_string(player.get_dmg());
    return responce{answ, enemies[choosed_ind]->is_dead() ? "Enemy" + to_string(choosed_ind) + " is dead " : en_ndead};
}

void battle_state::make_move()
{
    auto& player = holder->get_player();
    for(auto& en : enemies)
    {
        if( en->get_pos().x - 1 == player.get_pos().x || en->get_pos().y - 1 == player.get_pos().y)
        {
            player.take_dmg(en->get_dmg());
        }
        else
        {
            en->move({});
        }
    }
}
bool battle_state::is_victorious()
{
    for(auto& en : enemies)
    {
        if (!en->is_dead())
            return false;
    }
    return true;
}
std::unique_ptr<state> battle_state::memento(){}

void battle_state::set_holder(MainWindow* _holder)
{
    holder = _holder;
}
