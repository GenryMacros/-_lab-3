#ifndef STORY_STATE_H
#define STORY_STATE_H

#include <vector>
#include <string>
#include <memory>
#include "factory.h"
class MainWindow;

struct responce
{
    std::vector<std::string> answers;
    std::string text;
};

class state
{
protected:
    MainWindow* holder = nullptr;
public:
    virtual responce process_answer(int choosed_ind) = 0;
    virtual std::unique_ptr<state> memento() = 0;
    virtual void set_holder(MainWindow* holder) = 0;
    virtual const std::unique_ptr<factory>& get_factory() = 0;
    virtual ~state() {}
};
#include "mainwindow.h"
#endif // STORY_STATE_H
