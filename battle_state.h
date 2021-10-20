#ifndef BATTLE_STATE_H
#define BATTLE_STATE_H
#include "state.h"
#include "factory.h"
#include "warrior.h"

class battle_state: public state
{
private:
    std::unique_ptr<state> remembered_state;
    std::vector<std::unique_ptr<warrior>> enemies;
public:
    battle_state(std::unique_ptr<state> rem_state);
    responce process_answer(int choosed_ind) override;
    std::unique_ptr<state> memento() override;
    void set_holder(MainWindow* holder) override;
    const std::unique_ptr<factory>&  get_factory() override {return nullptr;}
private:
    void make_move();
    bool is_victorious();
};

#endif // BATTLE_STATE_H
