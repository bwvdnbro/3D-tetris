#ifndef FIELDVIEW3DPROJECTION_H
#define FIELDVIEW3DPROJECTION_H

#include <QWidget>
#include "../field3d.h"

enum Projection3D{
    PROJECTION_X_LEFT,
    PROJECTION_X_RIGHT,
    PROJECTION_Y_FRONT,
    PROJECTION_Y_BACK,
    PROJECTION_Z_TOP,
    PROJECTION_Z_BOTTOM
};

class FieldView3DProjection : public QWidget
{
    Q_OBJECT

private:
    Field3D& _field;
    QColor _colors[8];
    Projection3D _projection;

protected:
    void keyPressEvent(QKeyEvent *event);

public:
    explicit FieldView3DProjection(Field3D& field, Projection3D projection, QWidget *parent = 0);

    void paintEvent(QPaintEvent *paintevent);
    
signals:
    
public slots:
    void timer_handler();
    
};

#endif // FIELDVIEW3DPROJECTION_H
