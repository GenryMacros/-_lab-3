#include "mainwindow.h"
#include <QPushButton>

#include "mainwindow.h"
#include <QPushButton>

using namespace std;

MainWindow::MainWindow(unique_ptr<state> st, QWidget *parent)
    : QMainWindow(parent), pl(40, 5, 5)
{
    pl.move({0,0});
    cur_state.swap(st);
    cur_state->set_holder(this);
    setWindowTitle("Best text game");
    setGeometry(500, 500, 600, 640);
    setMinimumSize(200, 200);
    auto resp = cur_state->process_answer(-1);
    view = new QGraphicsView(this);
    view->setGeometry(10,10,580,330);

    outputField = new QTextEdit(QString::fromLocal8Bit(resp.text), this);
    outputField->setGeometry(10, 350, 580, 120);
    outputField->setReadOnly(true);
    answers.push_back(new QRadioButton(QString::fromLocal8Bit(resp.answers[0]), this));
    answers.push_back(new QRadioButton(QString::fromLocal8Bit(resp.answers[1]), this));
    answers.push_back(new QRadioButton(QString::fromLocal8Bit(resp.answers[2]), this));
    answers[0]->setGeometry(210, 460, 200, 50);
    answers[1]->setGeometry(210, 510, 200, 50);
    answers[2]->setGeometry(210, 560, 200, 50);

    im = new QImage(QString("C:/Users/Light/Documents/text_game/images/tavern.jpg"));
    *im = im->scaled(570, 320);
    QGraphicsScene *graphics = new QGraphicsScene(this);
    graphics->addPixmap(QPixmap::fromImage(*im));

    view->setScene(graphics);
    QPushButton *okButton = new QPushButton("OK", this);
    okButton->setGeometry(250, 610, 50, 30);
    connect(okButton, SIGNAL (released()), this, SLOT (handleButton()));
}

void MainWindow::handleButton()
{
    if(pl.is_dead())
    {
        change_text({{"","",""},"You are dead"});
        return;
    }
    int counter = 0;
    for (auto radio : answers)
    {
        if(radio->isChecked())
        {
            change_text(cur_state->process_answer(counter));
        }
        counter++;
    }
}

void MainWindow::change_text(responce&& resp)
{
    answers[0]->setText(QString::fromLocal8Bit(resp.answers[0]));
    answers[1]->setText(QString::fromLocal8Bit(resp.answers[1]));
    answers[2]->setText(QString::fromLocal8Bit(resp.answers[2]));
    outputField->setText(QString::fromLocal8Bit(resp.text));
}

void MainWindow::change_state(std::unique_ptr<state> new_state)
{
    cur_state.swap(new_state);
    cur_state->set_holder(this);
}

player& MainWindow::get_player()
{
    return pl;
}

MainWindow::~MainWindow()
{
}

