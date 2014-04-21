#include <iostream>
#include "field3d.h"
#include "gui/fieldview3dprojection.h"
#include <QApplication>
#include <QMainWindow>
#include <QTimer>

using namespace std;

int main(int argc, char **argv)
{
    Field3D field;
    QTimer timer;
    QApplication a(argc, argv);
    QMainWindow mw;
    FieldView3DProjection fview(field);
    fview.connect(&timer, SIGNAL(timeout()), &fview, SLOT(timer_handler()));
    mw.setCentralWidget(&fview);
    mw.setFixedSize(300,600);

    mw.show();
    timer.start(1000);
    return a.exec();
}
