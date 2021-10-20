#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QRadioButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPixmap>
#include <iostream>
#include <QImage>
#include <memory>
#include <vector>
#include "state.h"
#include "player.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
   QLineEdit *inputField;
   QTextEdit *outputField;
   QGraphicsView *view;
   std::vector<QRadioButton*> answers;
   QImage* im;
   std::unique_ptr<state> cur_state = nullptr;
   player pl;
public:
    MainWindow(std::unique_ptr<state> st, QWidget *parent = nullptr);
    void change_state(std::unique_ptr<state> new_state);
    player& get_player();
    ~MainWindow();
private:
    void change_text(responce&& resp);
private slots:
    void handleButton();
};
#endif // MAINWINDOW_H
