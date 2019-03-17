#ifndef PAINTEDWIDGET_H
#define PAINTEDWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QSpinBox>
#include <QSlider>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "paintedpalatte.h"

class LinePaintedWindow : public QWidget
{
    Q_OBJECT
public:
    LinePaintedWindow(QWidget *parent = 0);
private:
    LinePaintedPalatte *palette;
};

class EllipsePaintedWindow : public QWidget
{
    Q_OBJECT
public:
    EllipsePaintedWindow(QWidget *parent = 0);
private:
    EllipsePaintedPalatte *palette;
};

class RectPaintedWindow : public QWidget
{
    Q_OBJECT
public:
    RectPaintedWindow(QWidget *parent = 0);
private:
    RectPaintedPalatte *palette;
};

#endif // PAINTEDWIDGET_H
