#include <iostream>
#include "field.h"
#include "gui/fieldview.h"
#include <QApplication>
#include <QMainWindow>
#include <QTimer>

using namespace std;

int main(int argc, char **argv)
{
    Field field;
    QTimer timer;
    QApplication a(argc, argv);
    QMainWindow mw;
    FieldView fview(field);
    fview.connect(&timer, SIGNAL(timeout()), &fview, SLOT(timer_handler()));
    mw.setCentralWidget(&fview);
    mw.setFixedSize(300,600);

    mw.show();
    timer.start(1000);
    return a.exec();
}
