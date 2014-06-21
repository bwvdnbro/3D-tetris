#include "fieldview3d.h"
#include <iostream>
#include "QMouseEvent"
#include "../field3d.h"
using namespace std;

GLfloat redcube[3][3] = {{1.,0.,0.},
                       {0.5,0.,0.},
                       {0.75,0.,0.}};

GLfloat greencube[3][3] = {{0.,1.,0.},
                           {0.,0.5,0.},
                           {0.,0.75,0.}};

GLfloat bluecube[3][3] = {{0.,0.,1.},
                          {0.,0.,0.5},
                          {0.,0.,0.75}};

GLfloat whitecube[3][3] = {{1.,1.,1.},
                           {0.5,0.5,0.5},
                           {0.75,0.75,0.75}};

GLfloat purplecube[3][3] = {{1.,0.,1.},
                            {0.5,0.,0.5},
                            {0.75,0.,0.75}};

GLfloat yellowcube[3][3] = {{1.,1.,0.},
                            {0.5,0.5,0.},
                            {0.75,0.75,0.}};

GLfloat cyancube[3][3] = {{0.,1.,1.},
                          {0.,0.5,0.5},
                          {0.,0.75,0.75}};

FieldView3D::FieldView3D(Field3D& field, QWidget* parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent),
      _field(field)
{
    xRot = 208;
    yRot = 752;
    zRot = 0;

    qtGreen = QColor::fromCmykF(0.40, 0.0, 1.0, 0.0);
    qtPurple = QColor::fromCmykF(0.39, 0.39, 0.0, 0.0);
    for(int j = 0; j < 3; j++){
        for(int k = 0; k < 3; k++){
            _colors[2][j][k] = redcube[j][k];
            _colors[3][j][k] = greencube[j][k];
            _colors[4][j][k] = bluecube[j][k];
            _colors[5][j][k] = whitecube[j][k];
            _colors[7][j][k] = purplecube[j][k];
            _colors[6][j][k] = yellowcube[j][k];
            _colors[1][j][k] = cyancube[j][k];
        }
    }
    setFocusPolicy(Qt::StrongFocus);
}

FieldView3D::~FieldView3D()
{
    // do nothing
}

void FieldView3D::timer_handler()
{
    _field.move_piece();
    update();
}

void FieldView3D::keyPressEvent(QKeyEvent *event)
{
    switch(event->key()){
    case Qt::Key_Up:
        _field.move_piece_back();
        break;
    case Qt::Key_Down:
        _field.move_piece_front();
        break;
    case Qt::Key_Left:
        _field.move_piece_left();
        break;
    case Qt::Key_Right:
        _field.move_piece_right();
        break;
    case Qt::Key_Space:
        _field.drop_piece();
        break;
    case Qt::Key_A:
        _field.turn_piece_x();
        break;
    case Qt::Key_Q:
        _field.turn_piece_x();
        break;
    case Qt::Key_D:
        _field.turn_piece_y();
        break;
    case Qt::Key_S:
        _field.turn_piece_z();
        break;
    default:
        break;
    }

    QWidget::keyPressEvent(event);
    update();
}

QSize FieldView3D::minimumSizeHint() const
{
    return QSize(400, 400);
}

QSize FieldView3D::sizeHint() const
{
    return QSize(400, 400);
}

void FieldView3D::setXRotation(int angle)
{
    //qNormalizeAngle(angle);
    if(angle != xRot){
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void FieldView3D::setYRotation(int angle)
{
    //qNormalizeAngle(angle);
    if(angle != yRot){
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void FieldView3D::setZRotation(int angle)
{
    //qNormalizeAngle(angle);
    if(angle != zRot){
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void FieldView3D::initializeGL()
{
    //qglClearColor(qtPurple.dark());

    //logo = new QtLogo(this, 64);
    //logo->setColor(qtGreen.dark());

    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    //glShadeModel(GL_SMOOTH);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    //glEnable(GL_MULTISAMPLE);
    //static GLfloat lightPosition[4] = {0.5, 5.0, 7.0, 1.0};
    //glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void FieldView3D::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width-side)/2, (height-side)/2, side, side);
    //glViewport(0, 0, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-0.5, +0.5, -0.5, +0.5, 4.0, 15.0);
    glFrustum( -1.0, 1.0, -1.0, 1.0, 5.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
}

void FieldView3D::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(xRot/16., 1., 0., 0.);
    glRotatef(yRot/16., 0., 1., 0.);
    glRotatef(zRot/16., 0., 0., 1.);

    GLfloat origin[3] = {1.,-2.5,-3.};
    GLfloat cubeside = 0.2;
    GLfloat cubeborder = 0.01;

    /* create grid */
    glBegin(GL_LINES);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(origin[0],origin[1],origin[2]);
    glVertex3f(origin[0],origin[1]+20*cubeside,origin[2]);
    glVertex3f(origin[0]+10*cubeside,origin[1],origin[2]);
    glVertex3f(origin[0]+10*cubeside,origin[1]+20*cubeside,origin[2]);

    glVertex3f(origin[0],origin[1],origin[2]+10*cubeside);
    glVertex3f(origin[0],origin[1]+20*cubeside,origin[2]+10*cubeside);
    glVertex3f(origin[0]+10*cubeside,origin[1],origin[2]+10*cubeside);
    glVertex3f(origin[0]+10*cubeside,origin[1]+20*cubeside,origin[2]+10*cubeside);

    glVertex3f(origin[0],origin[1],origin[2]+10*cubeside);
    glVertex3f(origin[0]+10*cubeside,origin[1],origin[2]+10*cubeside);
    glVertex3f(origin[0],origin[1]+20*cubeside,origin[2]+10*cubeside);
    glVertex3f(origin[0]+10*cubeside,origin[1]+20*cubeside,origin[2]+10*cubeside);

    glVertex3f(origin[0],origin[1],origin[2]);
    glVertex3f(origin[0]+10*cubeside,origin[1],origin[2]);
    glVertex3f(origin[0],origin[1]+20*cubeside,origin[2]);
    glVertex3f(origin[0]+10*cubeside,origin[1]+20*cubeside,origin[2]);

    glVertex3f(origin[0],origin[1],origin[2]+10*cubeside);
    glVertex3f(origin[0],origin[1],origin[2]);
    glVertex3f(origin[0]+10*cubeside,origin[1],origin[2]+10*cubeside);
    glVertex3f(origin[0]+10*cubeside,origin[1],origin[2]);

    glVertex3f(origin[0],origin[1]+20*cubeside,origin[2]+10*cubeside);
    glVertex3f(origin[0],origin[1]+20*cubeside,origin[2]);
    glVertex3f(origin[0]+10*cubeside,origin[1]+20*cubeside,origin[2]+10*cubeside);
    glVertex3f(origin[0]+10*cubeside,origin[1]+20*cubeside,origin[2]);
    glEnd();

    /* create 3D-Cubes */
    glBegin(GL_QUADS);

    unsigned int colors[20][10][10];
//    for(int i = 0; i < 20; i++){
//        for(int j = 0; j < 10; j++){
//            colors[i][j] = 1;
//        }
//    }
    _field.get_colors(colors);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 20; j++){
            for(int k = 0; k < 10; k++){
                if(colors[19-j][i][k]){
                    //front
                    glColor3fv(_colors[colors[19-j][i][k]][0]);

                    glVertex3f(origin[0]+(i+1)*cubeside-cubeborder,origin[1]+(j+1)*cubeside-cubeborder,origin[2]+(k+1)*cubeside-cubeborder); //A
                    glVertex3f(origin[0]+i*cubeside+cubeborder,origin[1]+(j+1)*cubeside-cubeborder,origin[2]+(k+1)*cubeside-cubeborder); //B
                    glVertex3f(origin[0]+i*cubeside+cubeborder,origin[1]+j*cubeside+cubeborder,origin[2]+(k+1)*cubeside-cubeborder); //C
                    glVertex3f(origin[0]+(i+1)*cubeside-cubeborder,origin[1]+j*cubeside+cubeborder,origin[2]+(k+1)*cubeside-cubeborder); //D

                    //top
                    glColor3fv(_colors[colors[19-j][i][k]][1]);

                    glVertex3f(origin[0]+i*cubeside+cubeborder,origin[1]+(j+1)*cubeside-cubeborder,origin[2]+(k+1)*cubeside-cubeborder); //B
                    glVertex3f(origin[0]+(i+1)*cubeside-cubeborder,origin[1]+(j+1)*cubeside-cubeborder,origin[2]+(k+1)*cubeside-cubeborder); //A
                    glVertex3f(origin[0]+(i+1)*cubeside-cubeborder,origin[1]+(j+1)*cubeside-cubeborder,origin[2]+k*cubeside+cubeborder); //E
                    glVertex3f(origin[0]+i*cubeside+cubeborder,origin[1]+(j+1)*cubeside-cubeborder,origin[2]+k*cubeside+cubeborder); //F

                    //left
                    glColor3fv(_colors[colors[19-j][i][k]][2]);

                    glVertex3f(origin[0]+i*cubeside+cubeborder,origin[1]+(j+1)*cubeside-cubeborder,origin[2]+(k+1)*cubeside-cubeborder); //B
                    glVertex3f(origin[0]+i*cubeside+cubeborder,origin[1]+j*cubeside+cubeborder,origin[2]+(k+1)*cubeside-cubeborder); //C
                    glVertex3f(origin[0]+i*cubeside+cubeborder,origin[1]+j*cubeside+cubeborder,origin[2]+k*cubeside+cubeborder); //G
                    glVertex3f(origin[0]+i*cubeside+cubeborder,origin[1]+(j+1)*cubeside-cubeborder,origin[2]+k*cubeside+cubeborder); //F
                }
            }
        }
    }

    glEnd();
}

void FieldView3D::mousePressEvent(QMouseEvent *event)
{
//    lastPos = event->pos();
}

void FieldView3D::mouseMoveEvent(QMouseEvent *event)
{
//    int dx = event->x() - lastPos.x();
//    int dy = event->y() - lastPos.y();

//    if(event->buttons() & Qt::LeftButton){
//        setXRotation(xRot + 8*dy);
//        setYRotation(yRot + 8*dx);
//    } else if(event->buttons() & Qt::RightButton){
//        setXRotation(xRot + 8*dy);
//        setZRotation(zRot + 8*dx);
//    }
//    lastPos = event->pos();
//    cout << xRot << "\t" << yRot << "\t" << zRot << endl;
}
