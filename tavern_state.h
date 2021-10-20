#ifndef TAVERN_STATE_H
#define TAVERN_STATE_H
#include "state.h"
#include "factory.h"
#include "battlecry_state.h"
struct story
{
    std::vector<std::string> answers;
    std::string descr;
    std::vector<std::unique_ptr<story>> next;
};

class tavern_state : public state
{
private:
    std::unique_ptr<story> current_story;
    std::string image_path;
    std::string file_path;
    std::unique_ptr<factory> fact;
    int stage;
public:
    tavern_state() = default;
    const std::unique_ptr<factory>& get_factory() override;
    tavern_state(std::unique_ptr<factory> _fact);
    responce process_answer(int choosed_ind) override;
    void set_holder(MainWindow* holder) override;
    std::unique_ptr<state> memento() override;
};

#endif // TAVERN_STATE_H
