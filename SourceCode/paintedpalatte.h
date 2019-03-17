#ifndef PAINTEDPALATTE_H
#define PAINTEDPALATTE_H

#include <QWidget>
#include <Qlabel>
#include <QPainter>
#include <QMouseEvent>
#include <QKeyEvent>
#include "constants.h"
#include <QList>
#include <QVector>
#include <QDebug>
#include <QtAlgorithms>
#include <QImage>
#include <QColorDialog>

struct PointPair{
    int x1,y1;
    int x2,y2;
};

struct Figure{
    PointPair pp;
    Shape s;
    QColor c;
    PointPair bound;
};

class PaintedPalatte : public QWidget
{
    Q_OBJECT
public:
    PaintedPalatte(QWidget *parent = 0);
    void x1Change(int value);
    void y1Change(int value);
    void x2Change(int value);
    void y2Change(int value);
    void initial_coor();
    void setLineEditting();
    void setEllipseEditting();
    void setRectEditting();
    void setPolyEditting();
    void setCurseEditting();
    void setTailoring();
    void BresenhamLine(int x1,int y1,int x2,int y2);
    void CenterEllipse(int rx,int ry,int xc,int yc);
    void TrivialRect(int x1,int y1,int x2,int y2);
    void LinePadding(int x1,int y1,int x2,int y2);
    void EllipsePadding(int rx,int ry,int xc,int yc);
    void RectPadding(int x1,int y1,int x2,int y2);
    bool EditLine(int x, int y);
    bool EditEllipse(int x, int y);
    bool EditRect(int x, int y);
    void rotate(int degree);
    void zoom(double times);
    void padding(QColor color);
    void proc_padding(int x, int y, QColor c, PointPair bound);
    void disproc_padding();
    void proc_curse(QVector<QPoint> points);
    PointPair tailLine(PointPair pp, int x1, int y1, int x2, int y2);
    void savePicture(const QString fileName, const char *format);
    void clear();
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
private:
    int x1;
    int y1;
    int x2;
    int y2;
    QList<Figure> f;
    Figure lastf;
    bool isLeftPressed;
    bool isParalell;
    bool isEditx1;
    bool isEdity1;
    bool isEditx2;
    bool isEdity2;
    Shape shape;
    bool isTailor;
    bool isPolyFirst;
    bool isCurseFirst;
    bool isPadding;
    QColor padding_color;
    QImage saveimage;
    int polystartx1;
    int polystarty1;
    int cursestartx1;
    int cursestarty1;
    int curse_counter;
    QColor pixel[MAX_WIDTH][MAX_HEIGHT];
    //QPainter painter;
};

#endif // PAINTEDPALATTE_H
