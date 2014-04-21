#include "fieldview3dprojection.h"
#include <iostream>
#include <QPainter>
#include <QColor>
#include <QKeyEvent>

FieldView3DProjection::FieldView3DProjection(Field3D& field, QWidget *parent) :
    _field(field),
    QWidget(parent)
{
    _colors[0] = QColor(Qt::black);
    _colors[1] = QColor(Qt::cyan);
    _colors[2] = QColor(Qt::red);
    _colors[3] = QColor(Qt::green);
    _colors[4] = QColor(Qt::blue);
    _colors[5] = QColor(Qt::gray);
    _colors[6] = QColor(Qt::yellow);
    _colors[7] = QColor(Qt::magenta);
    setFocusPolicy(Qt::StrongFocus);
}

void FieldView3DProjection::timer_handler()
{
    _field.move_piece();
    update();
}

void FieldView3DProjection::paintEvent(QPaintEvent *paintevent)
{
    QPainter painter(this);
    painter.fillRect(0, 0, 300, 600, _colors[0]);
    unsigned int colors[20][10][10];
    _field.get_colors(colors);
    unsigned int origin[2] = {0,0};
    unsigned int width[2] = {30,30};
    for(int i = 0; i < 20; i++){
        origin[0] = 0;
        for(int j = 0; j < 10; j++){
            painter.fillRect(origin[0]+1, origin[1]+1, width[0]-2, width[1]-2, _colors[colors[i][j][0]]);
            origin[0] += width[0];
        }
        origin[1] += width[1];
    }
}

void FieldView3DProjection::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Up:
        _field.turn_piece_x();
        break;
    case Qt::Key_Down:
        _field.drop_piece();
        break;
    case Qt::Key_Left:
        _field.move_piece_left();
        break;
    case Qt::Key_Right:
        _field.move_piece_right();
        break;
    default:
        break;
    }

    QWidget::keyPressEvent(event);
    update();
}
