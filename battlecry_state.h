#ifndef BATTLECRY_STATE_H
#define BATTLECRY_STATE_H
#include "state.h"
#include "battle_state.h"

class battlecry_state : public state
{
private:
    std::unique_ptr<state> remembered_state;
public:
    battlecry_state(std::unique_ptr<state> rem_state);
    responce process_answer(int choosed_ind) override;
    void set_holder(MainWindow* holder) override;
    std::unique_ptr<state> memento() override;
    const std::unique_ptr<factory>&  get_factory() override {return nullptr;}
};

#endif // BATTLECRY_STATE_H
