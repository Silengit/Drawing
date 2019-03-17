#include "paintedwindow.h"
#include "constants.h"

LinePaintedWindow::LinePaintedWindow(QWidget *parent) :
    QWidget(parent)
{
    resize(WINDOW_WIDTH, WINDOW_HEIGHT+150);
    setWindowTitle(tr("Paint Line"));

    palette = new LinePaintedPalatte(this);
    QSpinBox *x1spinBox = new QSpinBox(this);
    QSlider *x1slider = new QSlider(Qt::Horizontal, this);
    QLabel *x1label = new QLabel(this);
    x1label->setText("x1:");
    QSpinBox *y1spinBox = new QSpinBox(this);
    QSlider *y1slider = new QSlider(Qt::Horizontal, this);
    QLabel *y1label = new QLabel(this);
    y1label->setText("y1:");
    QSpinBox *x2spinBox = new QSpinBox(this);
    QSlider *x2slider = new QSlider(Qt::Horizontal, this);
    QLabel *x2label = new QLabel(this);
    x2label->setText("x2:");
    QSpinBox *y2spinBox = new QSpinBox(this);
    QSlider *y2slider = new QSlider(Qt::Horizontal, this);
    QLabel *y2label = new QLabel(this);
    y2label->setText("y2:");
    x1spinBox->setRange(0, WINDOW_WIDTH);
    x1slider->setRange(0, WINDOW_WIDTH);
    y1spinBox->setRange(0, WINDOW_HEIGHT);
    y1slider->setRange(0, WINDOW_HEIGHT);
    x2spinBox->setRange(0, WINDOW_WIDTH);
    x2slider->setRange(0, WINDOW_WIDTH);
    y2spinBox->setRange(0, WINDOW_HEIGHT);
    y2slider->setRange(0, WINDOW_HEIGHT);

    QObject::connect(x1slider, &QSlider::valueChanged, x1spinBox, &QSpinBox::setValue);
    void (QSpinBox:: *spinBoxSignal1)(int) = &QSpinBox::valueChanged;
    QObject::connect(x1spinBox, spinBoxSignal1, x1slider, &QSlider::setValue);
    x1spinBox->setValue(0);

    QObject::connect(y1slider, &QSlider::valueChanged, y1spinBox, &QSpinBox::setValue);
    void (QSpinBox:: *spinBoxSignal2)(int) = &QSpinBox::valueChanged;
    QObject::connect(y1spinBox, spinBoxSignal2, y1slider, &QSlider::setValue);
    y1spinBox->setValue(0);

    QObject::connect(x2slider, &QSlider::valueChanged, x2spinBox, &QSpinBox::setValue);
    void (QSpinBox:: *spinBoxSignal3)(int) = &QSpinBox::valueChanged;
    QObject::connect(x2spinBox, spinBoxSignal3, x2slider, &QSlider::setValue);
    x2spinBox->setValue(WINDOW_WIDTH);

    QObject::connect(y2slider, &QSlider::valueChanged, y2spinBox, &QSpinBox::setValue);
    void (QSpinBox:: *spinBoxSignal4)(int) = &QSpinBox::valueChanged;
    QObject::connect(y2spinBox, spinBoxSignal4, y2slider, &QSlider::setValue);
    y2spinBox->setValue(WINDOW_HEIGHT);


    QObject::connect(x1slider, &QSlider::valueChanged, palette, &LinePaintedPalatte::x1Change);
    QObject::connect(y1slider, &QSlider::valueChanged, palette, &LinePaintedPalatte::y1Change);
    QObject::connect(x2slider, &QSlider::valueChanged, palette, &LinePaintedPalatte::x2Change);
    QObject::connect(y2slider, &QSlider::valueChanged, palette, &LinePaintedPalatte::y2Change);

    QHBoxLayout *h1layout = new QHBoxLayout;
    h1layout->addWidget(x1label);
    h1layout->addWidget(x1spinBox);
    h1layout->addWidget(x1slider);

    QHBoxLayout *h2layout = new QHBoxLayout;
    h2layout->addWidget(y1label);
    h2layout->addWidget(y1spinBox);
    h2layout->addWidget(y1slider);

    QHBoxLayout *h3layout = new QHBoxLayout;
    h3layout->addWidget(x2label);
    h3layout->addWidget(x2spinBox);
    h3layout->addWidget(x2slider);

    QHBoxLayout *h4layout = new QHBoxLayout;
    h4layout->addWidget(y2label);
    h4layout->addWidget(y2spinBox);
    h4layout->addWidget(y2slider);

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addLayout(h1layout);
    vlayout->addLayout(h2layout);
    vlayout->addLayout(h3layout);
    vlayout->addLayout(h4layout);
    vlayout->addWidget(palette);
    this->setLayout(vlayout);
}

EllipsePaintedWindow::EllipsePaintedWindow(QWidget *parent) :
    QWidget(parent)
{
    resize(WINDOW_WIDTH, WINDOW_HEIGHT+150);
    setWindowTitle(tr("Paint Ellipse"));

    palette = new EllipsePaintedPalatte(this);
    QSpinBox *xspinBox = new QSpinBox(this);
    QSlider *xslider = new QSlider(Qt::Horizontal, this);
    QLabel *xlabel = new QLabel(this);
    xlabel->setText("x:");
    QSpinBox *yspinBox = new QSpinBox(this);
    QSlider *yslider = new QSlider(Qt::Horizontal, this);
    QLabel *ylabel = new QLabel(this);
    ylabel->setText("y:");
    QSpinBox *widthspinBox = new QSpinBox(this);
    QSlider *widthslider = new QSlider(Qt::Horizontal, this);
    QLabel *widthlabel = new QLabel(this);
    widthlabel->setText("w:");
    QSpinBox *heightspinBox = new QSpinBox(this);
    QSlider *heightslider = new QSlider(Qt::Horizontal, this);
    QLabel *heightlabel = new QLabel(this);
    heightlabel->setText("h:");
    xspinBox->setRange(0, WINDOW_WIDTH);
    xslider->setRange(0, WINDOW_WIDTH);
    yspinBox->setRange(0, WINDOW_HEIGHT);
    yslider->setRange(0, WINDOW_HEIGHT);
    widthspinBox->setRange(0, WINDOW_WIDTH);
    widthslider->setRange(0, WINDOW_WIDTH);
    heightspinBox->setRange(0, WINDOW_HEIGHT);
    heightslider->setRange(0, WINDOW_HEIGHT);

    QObject::connect(xslider, &QSlider::valueChanged, xspinBox, &QSpinBox::setValue);
    void (QSpinBox:: *spinBoxSignal1)(int) = &QSpinBox::valueChanged;
    QObject::connect(xspinBox, spinBoxSignal1, xslider, &QSlider::setValue);
    xspinBox->setValue(0);

    QObject::connect(yslider, &QSlider::valueChanged, yspinBox, &QSpinBox::setValue);
    void (QSpinBox:: *spinBoxSignal2)(int) = &QSpinBox::valueChanged;
    QObject::connect(yspinBox, spinBoxSignal2, yslider, &QSlider::setValue);
    yspinBox->setValue(0);

    QObject::connect(widthslider, &QSlider::valueChanged, widthspinBox, &QSpinBox::setValue);
    void (QSpinBox:: *spinBoxSignal3)(int) = &QSpinBox::valueChanged;
    QObject::connect(widthspinBox, spinBoxSignal3, widthslider, &QSlider::setValue);
    widthspinBox->setValue(WINDOW_WIDTH/2);

    QObject::connect(heightslider, &QSlider::valueChanged, heightspinBox, &QSpinBox::setValue);
    void (QSpinBox:: *spinBoxSignal4)(int) = &QSpinBox::valueChanged;
    QObject::connect(heightspinBox, spinBoxSignal4, heightslider, &QSlider::setValue);
    heightspinBox->setValue(WINDOW_HEIGHT);


    QObject::connect(xslider, &QSlider::valueChanged, palette, &EllipsePaintedPalatte::xChange);
    QObject::connect(yslider, &QSlider::valueChanged, palette, &EllipsePaintedPalatte::yChange);
    QObject::connect(widthslider, &QSlider::valueChanged, palette, &EllipsePaintedPalatte::widthChange);
    QObject::connect(heightslider, &QSlider::valueChanged, palette, &EllipsePaintedPalatte::heightChange);

    QHBoxLayout *h1layout = new QHBoxLayout;
    h1layout->addWidget(xlabel);
    h1layout->addWidget(xspinBox);
    h1layout->addWidget(xslider);

    QHBoxLayout *h2layout = new QHBoxLayout;
    h2layout->addWidget(ylabel);
    h2layout->addWidget(yspinBox);
    h2layout->addWidget(yslider);

    QHBoxLayout *h3layout = new QHBoxLayout;
    h3layout->addWidget(widthlabel);
    h3layout->addWidget(widthspinBox);
    h3layout->addWidget(widthslider);

    QHBoxLayout *h4layout = new QHBoxLayout;
    h4layout->addWidget(heightlabel);
    h4layout->addWidget(heightspinBox);
    h4layout->addWidget(heightslider);

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addLayout(h1layout);
    vlayout->addLayout(h2layout);
    vlayout->addLayout(h3layout);
    vlayout->addLayout(h4layout);
    vlayout->addWidget(palette);
    this->setLayout(vlayout);
}


RectPaintedWindow::RectPaintedWindow(QWidget *parent) :
    QWidget(parent)
{
    resize(WINDOW_WIDTH, WINDOW_HEIGHT+150);
    setWindowTitle(tr("Paint Rectangle"));

    palette = new RectPaintedPalatte(this);
    QSpinBox *xspinBox = new QSpinBox(this);
    QSlider *xslider = new QSlider(Qt::Horizontal, this);
    QLabel *xlabel = new QLabel(this);
    xlabel->setText("x:");
    QSpinBox *yspinBox = new QSpinBox(this);
    QSlider *yslider = new QSlider(Qt::Horizontal, this);
    QLabel *ylabel = new QLabel(this);
    ylabel->setText("y:");
    QSpinBox *widthspinBox = new QSpinBox(this);
    QSlider *widthslider = new QSlider(Qt::Horizontal, this);
    QLabel *widthlabel = new QLabel(this);
    widthlabel->setText("w:");
    QSpinBox *heightspinBox = new QSpinBox(this);
    QSlider *heightslider = new QSlider(Qt::Horizontal, this);
    QLabel *heightlabel = new QLabel(this);
    heightlabel->setText("h:");
    xspinBox->setRange(0, WINDOW_WIDTH);
    xslider->setRange(0, WINDOW_WIDTH);
    yspinBox->setRange(0, WINDOW_HEIGHT);
    yslider->setRange(0, WINDOW_HEIGHT);
    widthspinBox->setRange(0, WINDOW_WIDTH);
    widthslider->setRange(0, WINDOW_WIDTH);
    heightspinBox->setRange(0, WINDOW_HEIGHT);
    heightslider->setRange(0, WINDOW_HEIGHT);

    QObject::connect(xslider, &QSlider::valueChanged, xspinBox, &QSpinBox::setValue);
    void (QSpinBox:: *spinBoxSignal1)(int) = &QSpinBox::valueChanged;
    QObject::connect(xspinBox, spinBoxSignal1, xslider, &QSlider::setValue);
    xspinBox->setValue(0);

    QObject::connect(yslider, &QSlider::valueChanged, yspinBox, &QSpinBox::setValue);
    void (QSpinBox:: *spinBoxSignal2)(int) = &QSpinBox::valueChanged;
    QObject::connect(yspinBox, spinBoxSignal2, yslider, &QSlider::setValue);
    yspinBox->setValue(0);

    QObject::connect(widthslider, &QSlider::valueChanged, widthspinBox, &QSpinBox::setValue);
    void (QSpinBox:: *spinBoxSignal3)(int) = &QSpinBox::valueChanged;
    QObject::connect(widthspinBox, spinBoxSignal3, widthslider, &QSlider::setValue);
    widthspinBox->setValue(WINDOW_WIDTH/2);

    QObject::connect(heightslider, &QSlider::valueChanged, heightspinBox, &QSpinBox::setValue);
    void (QSpinBox:: *spinBoxSignal4)(int) = &QSpinBox::valueChanged;
    QObject::connect(heightspinBox, spinBoxSignal4, heightslider, &QSlider::setValue);
    heightspinBox->setValue(WINDOW_HEIGHT);


    QObject::connect(xslider, &QSlider::valueChanged, palette, &RectPaintedPalatte::xChange);
    QObject::connect(yslider, &QSlider::valueChanged, palette, &RectPaintedPalatte::yChange);
    QObject::connect(widthslider, &QSlider::valueChanged, palette, &RectPaintedPalatte::widthChange);
    QObject::connect(heightslider, &QSlider::valueChanged, palette, &RectPaintedPalatte::heightChange);

    QHBoxLayout *h1layout = new QHBoxLayout;
    h1layout->addWidget(xlabel);
    h1layout->addWidget(xspinBox);
    h1layout->addWidget(xslider);

    QHBoxLayout *h2layout = new QHBoxLayout;
    h2layout->addWidget(ylabel);
    h2layout->addWidget(yspinBox);
    h2layout->addWidget(yslider);

    QHBoxLayout *h3layout = new QHBoxLayout;
    h3layout->addWidget(widthlabel);
    h3layout->addWidget(widthspinBox);
    h3layout->addWidget(widthslider);

    QHBoxLayout *h4layout = new QHBoxLayout;
    h4layout->addWidget(heightlabel);
    h4layout->addWidget(heightspinBox);
    h4layout->addWidget(heightslider);

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addLayout(h1layout);
    vlayout->addLayout(h2layout);
    vlayout->addLayout(h3layout);
    vlayout->addLayout(h4layout);
    vlayout->addWidget(palette);
    this->setLayout(vlayout);
}
