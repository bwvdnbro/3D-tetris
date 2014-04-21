#ifndef FIELDVIEW3DPROJECTION_H
#define FIELDVIEW3DPROJECTION_H

#include <QWidget>
#include "../field3d.h"

class FieldView3DProjection : public QWidget
{
    Q_OBJECT

private:
    Field3D& _field;
    QColor _colors[8];

protected:
    void keyPressEvent(QKeyEvent *event);

public:
    explicit FieldView3DProjection(Field3D& field, QWidget *parent = 0);

    void paintEvent(QPaintEvent *paintevent);
    
signals:
    
public slots:
    void timer_handler();
    
};

#endif // FIELDVIEW3DPROJECTION_H
