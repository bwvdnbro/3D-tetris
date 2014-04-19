#include "fieldview.h"
#include <iostream>
#include <QPainter>
#include <QColor>

FieldView::FieldView(Field& field, QWidget *parent) :
    _field(field),
    QWidget(parent)
{
    _colors[0] = QColor("black");
    _colors[1] = QColor("cyan");
    _colors[2] = QColor("red");
    _colors[3] = QColor("green");
    _colors[4] = QColor("blue");
    _colors[5] = QColor("gray");
    _colors[6] = QColor("yellow");
    _colors[7] = QColor("magenta");
}

void FieldView::timer_handler()
{
    _field.move_piece();
    update();
}

void FieldView::paintEvent(QPaintEvent *paintevent)
{
    QPainter painter(this);
    unsigned int colors[20][10];
    _field.get_colors(colors);
    unsigned int origin[2] = {0,0};
    unsigned int width[2] = {30,30};
    for(int i = 0; i < 20; i++){
        origin[0] = 0;
        for(int j = 0; j < 10; j++){
            painter.fillRect(origin[0], origin[1], width[0], width[1], _colors[colors[i][j]]);
            origin[0] += width[0];
        }
        origin[1] += width[1];
    }
}
