#ifndef FIELDVIEW3D_H
#define FIELDVIEW3D_H

#include <QtOpenGL/QGLWidget>

class Field3D;

class FieldView3D : public QGLWidget
{
    Q_OBJECT
public:
    FieldView3D(Field3D& field, QWidget* parent = 0);
    ~FieldView3D();

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void timer_handler();

signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:
    Field3D& _field;
    GLfloat _colors[8][3][3];
    int xRot;
    int yRot;
    int zRot;
    QPoint lastPos;
    QColor qtGreen;
    QColor qtPurple;
};

#endif // FIELDVIEW3D_H
