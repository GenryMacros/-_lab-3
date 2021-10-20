#include "battlecry_state.h"
using namespace std;

battlecry_state::battlecry_state(std::unique_ptr<state> rem_state)
{
    remembered_state = move(rem_state);
}

responce battlecry_state::process_answer(int choosed_ind)
{
    if( choosed_ind == -1)
    {
        vector<string> answ = {"","",""};
        return responce{answ, "YOU HAVE NO HONOR!"};
    }
    unique_ptr<state> new_state = make_unique<battle_state>(move(remembered_state));
    responce ret = new_state->process_answer(-1);
    holder->change_state(move(new_state));
    return ret;
}
void battlecry_state::set_holder(MainWindow* _holder)
{
    holder = _holder;
};

std::unique_ptr<state> battlecry_state::memento()
{}
