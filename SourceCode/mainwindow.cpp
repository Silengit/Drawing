#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "constants.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    palatte = new PaintedPalatte(this);
    setWindowIcon(QIcon(":/logo_ico"));
    setCentralWidget(palatte);
    palatte->setLineEditting();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete palatte;
}

void MainWindow::on_actionline_triggered()
{   
    palatte->setLineEditting();
}

void MainWindow::on_actionellipse_triggered()
{
    palatte->setEllipseEditting();
}

void MainWindow::on_actionrectange_triggered()
{
    palatte->setRectEditting();
}

void MainWindow::on_actionpolygon_triggered()
{
    palatte->setPolyEditting();
}

void MainWindow::on_actioncurse_triggered()
{
    palatte->setCurseEditting();
}

void MainWindow::on_actiontailor_triggered()
{
    palatte->setTailoring();
}

void MainWindow::on_actionsave_triggered()
{
    QString directory =
            QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, tr("Save path"), QDir::currentPath()));
    if(!directory.isEmpty())
    {
        qDebug()<<"directory: "<<directory<<endl;
        QString filename = directory +"\\img.png";
        palatte->savePicture(filename,"png");
    }
}

void MainWindow::on_actionright_90_degree_triggered()
{
    palatte->rotate(270);
}

void MainWindow::on_actionleft_90_degree_triggered()
{
    palatte->rotate(90);
}

void MainWindow::on_action180_degree_triggered()
{
    palatte->rotate(180);
}

void MainWindow::on_actionerase_clear_palette_triggered()
{
    palatte->clear();
}

void MainWindow::on_actionpadding_triggered()
{
    QColorDialog dia(this);
    dia.setWindowTitle("Color Editor");
    dia.setCurrentColor(Qt:: red);
    QColor color(Qt:: red);
    if(dia.exec() == QColorDialog::Accepted )
    {
        color = dia.selectedColor();
    }
    palatte->padding(color);
}

void MainWindow::on_actionopen_off_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,
           tr("choose an OFF"),
           "",
           tr("File (*.off)"));
    if (filename.isEmpty())
       {
           return;
       }
    else{
        qDebug()<<filename<<endl;
        //QString command = ".\\release\\benchmark\\util\\offviewer\\offviewer.exe " + filename;
        QString command = ".\\benchmark\\util\\offviewer\\offviewer.exe " + filename;
        QByteArray ba = command.toLocal8Bit();
        const char *data = ba.data();
        system(data);
    }
}

void MainWindow::on_actionzoom_2_times_triggered()
{
    palatte->zoom(2);
}

void MainWindow::on_actionzoom_0_5_times_triggered()
{
    palatte->zoom(0.5);
}
