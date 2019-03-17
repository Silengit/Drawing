#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QPainter>
#include <QPen>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVBoxLayout>
#include <QString>
#include <QDir>
#include <QFileDialog>
#include "paintedpalatte.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionline_triggered();

    void on_actionellipse_triggered();

    void on_actionrectange_triggered();

    void on_actiontailor_triggered();

    void on_actionsave_triggered();

    void on_actionright_90_degree_triggered();

    void on_actionleft_90_degree_triggered();

    void on_action180_degree_triggered();

    void on_actionpolygon_triggered();

    void on_actionerase_clear_palette_triggered();

    void on_actionpadding_triggered();

    void on_actioncurse_triggered();

    void on_actionopen_off_triggered();

    void on_actionzoom_2_times_triggered();

    void on_actionzoom_0_5_times_triggered();

private:
    Ui::MainWindow *ui;
    //QGraphicsView *view;
    PaintedPalatte *palatte;
};

#endif // MAINWINDOW_H
