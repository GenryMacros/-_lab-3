#include "tavern_state.h"
#include <iostream>
using namespace std;

tavern_state::tavern_state(std::unique_ptr<factory> _fact)
: fact(std::move(_fact))
{
    current_story = make_unique<story>();
    current_story->descr = "From the outside it looks delightful, warm and intimate. Large and small stones and marble pillars make up most of the building's outer structure.\n It's impossible to see through the windows, but the entertained voices from within can be felt outside.\nAs you enter the tavern through the hardwooden door, you're welcomed by amazing, but unknown scents and overall happiness.\nThe bartender is a little preoccupied, but still manages to welcome you with a friendly nod.\nIt's as alluring inside as it is on the outside. Hardwooden beams support the upper floor and the ambient lights attached to them. The walls are decorated with sports memorabilia, it's clear the owner, and probably the customers, are avid fans..\n The tavern itself is packed. Tourists seem to be the primary clientele here, which is probably the best clientele for the owner. Several long tables are occupied by happy, excited groups of people, some are dancing on the table, while others cheer them on with clapping and yelling. The other, smaller tables are also occupied by people who are playing games and, judging by their laughter, are either telling jokes or great, perhaps embarrasing, tales. Even most of the stools at the bar are occupied, though nobody seems to mind more company.\nYou did hear rumors about this tavern, supposedly it's famous for something, but you can't remember what for. Though judging by the laughter, cheering and overall enjoyment of everybody, it's probably the people themselves who make this tavern famous. You manage to find a seat and prepare for what will undoubtedbly be a great evening. Bearded dwarf takes a seat near you -Hello!First time here,huh?\n";
    current_story->answers.push_back("Hello, yes, and it is very nice here...\n Who are you by the way?");
    current_story->answers.push_back("No, coming here every evening");
    current_story->answers.push_back("Attack");
    current_story->next.push_back(make_unique<story>());
    current_story->next.push_back(make_unique<story>());
    current_story->next.push_back(make_unique<story>());
    current_story->next[0]->descr = "- Well it is pleasure too see new faces in out tavern. By the way im Yerevan, and what is your name, brave andventurer?";
    current_story->next[0]->answers.push_back("Nice to meet you.. eh, i cant remember my name");
    current_story->next[0]->answers.push_back("Im Rova. Nice to meet you");
    current_story->next[0]->answers.push_back("Im Vi");
    current_story->next[1]->descr = "- Well, well looks like we've got a thief on out hands! By the way im Yerevan, and what is your name, brave andventurer?";
    current_story->next[1]->answers.push_back("Yes,yes just dont tell the guards");
    current_story->next[1]->answers.push_back("Thief? No!");
    current_story->next[1]->answers.push_back("I think youre wrong here, newbie");
    current_story->next[2]->descr = "- Soldiers!Take him!";
    current_story->next[2]->answers.push_back("Run");
    current_story->next[2]->answers.push_back("Take barmen as prisoner");
    current_story->next[2]->answers.push_back("Fight");
}
const unique_ptr<factory>& tavern_state::get_factory()
{
    return fact;
}
responce tavern_state::process_answer(int choosed_ind)
{
    if(choosed_ind == -1)
    {
        return responce{current_story->answers, current_story->descr};
    }
    if(current_story->answers[choosed_ind] == "Attack")
    {
        current_story = move(current_story->next[choosed_ind]);
        unique_ptr<battlecry_state> new_state = make_unique<battlecry_state>(memento());
        responce ret = new_state->process_answer(-1);
        holder->change_state(move(new_state));
        return ret;
    }
    current_story = move(current_story->next[choosed_ind]);
    return responce{current_story->answers, current_story->descr};
};

unique_ptr<state> tavern_state::memento()
{
    auto copy = std::make_unique<tavern_state>();

    copy->current_story = move(current_story);
    copy->image_path = move(image_path);
    copy->file_path = move(file_path);
    copy->fact = move(fact);
    copy->stage = stage;

    return copy;
};

void tavern_state::set_holder(MainWindow* _holder)
{
    holder = _holder;
};
