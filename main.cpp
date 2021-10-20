#include "mainwindow.h"
#include "human_factory.h"
#include "tavern_state.h"
#include <QApplication>
#include <memory>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    unique_ptr<factory> factory = make_unique<human_factory>();
    unique_ptr<state> tavern = make_unique<tavern_state>(move(factory));
    MainWindow w(move(tavern));
    w.show();
    return a.exec();
}
