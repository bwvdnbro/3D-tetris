#ifndef FIELDVIEW_H
#define FIELDVIEW_H

#include <QWidget>
#include "../field.h"

class FieldView : public QWidget
{
    Q_OBJECT

private:
    Field& _field;
    QColor _colors[8];

public:
    explicit FieldView(Field& field, QWidget *parent = 0);

    void paintEvent(QPaintEvent *paintevent);
    
signals:
    
public slots:
    void timer_handler();
    
};

#endif // FIELDVIEW_H
