#include "paintedpalatte.h"
#include "constants.h"

void PaintedPalatte::initial_coor(){
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
}

void PaintedPalatte::setLineEditting(){
    initial_coor();
    isTailor = 0;
    isPadding = 0;
    shape = LINE;
}

void PaintedPalatte::setEllipseEditting()
{
    initial_coor();
    isTailor = 0;
    isPadding = 0;
    shape = ELLIPSE;
}

void PaintedPalatte::setRectEditting()
{
    initial_coor();
    isTailor = 0;
    isPadding = 0;
    shape = RECTANGLE;;
}

void PaintedPalatte::setPolyEditting()
{
    initial_coor();
    isTailor = 0;
    isPadding = 0;
    shape = POLYGON;
    isPolyFirst = 1;
}

void PaintedPalatte::setCurseEditting()
{
    initial_coor();
    isTailor = 0;
    isPadding = 0;
    shape = CURSE;
    isCurseFirst = 1;
}

void PaintedPalatte::setTailoring()
{
    initial_coor();
    isPadding = 0;
    isTailor = 1;
    this->setFocusPolicy(Qt::ClickFocus);
}

void PaintedPalatte::BresenhamLine(int x1,int y1,int x2,int y2)
{
    //qDebug()<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    QPainter painter(this);
    int x,y,dx,dy,p;
    x=x1;
    y=y1;
    dx=x2-x1;
    dy=y2-y1;
    p=2*dy-dx;

    //qDebug()<<dx<<" "<<dy<<endl;

    if(dy == 0){
        if(dx>0)
            for(;x<=x2;x++){
                painter.drawPoint(x,y);
            }
        else
            for(;x>=x2;x--){
                painter.drawPoint(x,y);
            }
    }
    else if(dx == 0){
        if(dy>0)
            for(;y<=y2;y++){
                painter.drawPoint(x,y);
            }
        else
            for(;y>=y2;y--){
                painter.drawPoint(x,y);
            }
    }
    else if(dy == dx){
        if(dx>0){
            for(;x<=x2;x++){
                painter.drawPoint(x,y+x-x1);
            }
        }
        else{
            for(;x>=x2;x--){
                painter.drawPoint(x,y+x-x1);
            }
        }
    }
    else if(dy == -dx){
        if(dx>0){
            for(;x<=x2;x++){
                painter.drawPoint(x,y+x1-x);
            }
        }
        else{
            for(;x>=x2;x--){
                painter.drawPoint(x,y+x1-x);
            }
        }
    }
    else if(qAbs(dy) < qAbs(dx)){
        if(dx > 0 && dy > 0){
            for(;x<=x2;x++){
                painter.drawPoint(x,y);
                if(p>=0)
                {
                    y++;
                    p+=2*(dy-dx);
                }
                else
                {
                    p+=2*dy;
                }
            }
        }
        else if(dx > 0 && dy < 0){
            p= -2*dy-dx;
            for(;x<=x2;x++){
                painter.drawPoint(x,y);
                if(p>=0)
                {
                    y--;
                    p+=2*(-dy-dx);
                }
                else
                {
                    p+=2*(-dy);
                }
            }
        }
        else if(dx < 0 && dy > 0){
            p= 2*dy+dx;
            for(;x>=x2;x--){
                painter.drawPoint(x,y);
                if(p>=0)
                {
                    y++;
                    p+=2*(dy+dx);
                }
                else
                {
                    p+=2*dy;
                }
            }
        }
        else{
            p= -2*dy+dx;
            for(;x>=x2;x--){
                painter.drawPoint(x,y);
                if(p>=0)
                {
                    y--;
                    p+=2*(-dy+dx);
                }
                else
                {
                    p+=2*(-dy);
                }
            }
        }
    }
    else{
        if(dy > 0 && dx > 0){
            p=2*dx-dy;
            for(;y<=y2;y++){
                painter.drawPoint(x,y);
                if(p>=0)
                {
                    x++;
                    p+=2*(dx-dy);
                }
                else
                {
                    p+=2*dx;
                }
            }
        }
        else if(dy > 0 && dx < 0){
            p= -2*dx-dy;
            for(;y<=y2;y++){
                painter.drawPoint(x,y);
                if(p>=0)
                {
                    x--;
                    p+=2*(-dx-dy);
                }
                else
                {
                    p+=2*(-dx);
                }
            }
        }
        else if(dy < 0 && dx > 0){
            p= 2*dx+dy;
            for(;y>=y2;y--){
                painter.drawPoint(x,y);
                if(p>=0)
                {
                    x++;
                    p+=2*(dx+dy);
                }
                else
                {
                    p+=2*dx;
                }
            }
        }
        else{
            p= -2*dx+dy;
            for(;y>=y2;y--){
                painter.drawPoint(x,y);
                if(p>=0)
                {
                    x--;
                    p+=2*(-dx+dy);
                }
                else
                {
                    p+=2*(-dx);
                }
            }
        }
    }
}

void PaintedPalatte::CenterEllipse(int rx,int ry,int xc,int yc)
{
    QPainter painter(this);
    double x = 0, y = ry;
    double p1 = pow(ry,2)-pow(rx,2)*ry+pow(rx,2)/4;
    while(pow(ry,2)*x<pow(rx,2)*y){
        painter.drawPoint(x+xc,y+yc);
        painter.drawPoint(x+xc,-y+yc);
        painter.drawPoint(-x+xc,y+yc);
        painter.drawPoint(-x+xc,-y+yc);
        x++;
        if(p1<0){
            p1 = p1 + 2*pow(ry,2)*x + pow(ry,2);
        }
        else{
            y--;
            p1 = p1 + 2*pow(ry,2)*x - 2*pow(rx,2)*y + pow(ry,2);
        }
    }
    double p2 = pow(ry,2)*pow((x+0.5),2)+pow(rx,2)*pow((y-1),2)-pow(rx,2)*pow(ry,2);
    while(y>=0){
        painter.drawPoint(x+xc,y+yc);
        painter.drawPoint(x+xc,-y+yc);
        painter.drawPoint(-x+xc,y+yc);
        painter.drawPoint(-x+xc,-y+yc);
        y--;
        if(p2>0){
            p2 = p2 - 2*pow(rx,2)*y + pow(rx,2);
        }
        else{
            x++;
            p2 = p2 + 2*pow(ry,2)*x - 2*pow(rx,2)*y + pow(rx,2);
        }
    }
}

void PaintedPalatte::TrivialRect(int x1,int y1,int x2,int y2)
{
    BresenhamLine(x1,y1,x1,y2);
    BresenhamLine(x1,y1,x2,y1);
    BresenhamLine(x2,y1,x2,y2);
    BresenhamLine(x1,y2,x2,y2);
}

void PaintedPalatte::LinePadding(int x1,int y1,int x2,int y2)
{
    int x,y,dx,dy,p;
    x=x1;
    y=y1;
    dx=x2-x1;
    dy=y2-y1;
    p=2*dy-dx;

    if(dy == 0){
        if(dx>0)
            for(;x<=x2;x++){
                pixel[x][y] = Qt::black;
            }
        else
            for(;x>=x2;x--){
                pixel[x][y] = Qt::black;
            }
    }
    else if(dx == 0){
        if(dy>0)
            for(;y<=y2;y++){
                pixel[x][y] = Qt::black;
            }
        else
            for(;y>=y2;y--){
                pixel[x][y] = Qt::black;
            }
    }
    else if(dy == dx){
        if(dx>0){
            for(;x<=x2;x++){
                pixel[x][y+x-x1] = Qt::black;
            }
        }
        else{
            for(;x>=x2;x--){
                pixel[x][y+x-x1] = Qt::black;
            }
        }
    }
    else if(dy == -dx){
        if(dx>0){
            for(;x<=x2;x++){
                pixel[x][y+x1-x] = Qt::black;
            }
        }
        else{
            for(;x>=x2;x--){
                pixel[x][y+x1-x] = Qt::black;
            }
        }
    }
    else if(qAbs(dy) < qAbs(dx)){
        if(dx > 0 && dy > 0){
            for(;x<=x2;x++){
                pixel[x][y] = Qt::black;
                if(p>=0)
                {
                    y++;
                    p+=2*(dy-dx);
                }
                else
                {
                    p+=2*dy;
                }
            }
        }
        else if(dx > 0 && dy < 0){
            p= -2*dy-dx;
            for(;x<=x2;x++){
                pixel[x][y] = Qt::black;
                if(p>=0)
                {
                    y--;
                    p+=2*(-dy-dx);
                }
                else
                {
                    p+=2*(-dy);
                }
            }
        }
        else if(dx < 0 && dy > 0){
            p= 2*dy+dx;
            for(;x>=x2;x--){
                pixel[x][y] = Qt::black;
                if(p>=0)
                {
                    y++;
                    p+=2*(dy+dx);
                }
                else
                {
                    p+=2*dy;
                }
            }
        }
        else{
            p= -2*dy+dx;
            for(;x>=x2;x--){
                pixel[x][y] = Qt::black;
                if(p>=0)
                {
                    y--;
                    p+=2*(-dy+dx);
                }
                else
                {
                    p+=2*(-dy);
                }
            }
        }
    }
    else{
        if(dy > 0 && dx > 0){
            p=2*dx-dy;
            for(;y<=y2;y++){
                pixel[x][y] = Qt::black;
                if(p>=0)
                {
                    x++;
                    p+=2*(dx-dy);
                }
                else
                {
                    p+=2*dx;
                }
            }
        }
        else if(dy > 0 && dx < 0){
            p= -2*dx-dy;
            for(;y<=y2;y++){
                pixel[x][y] = Qt::black;
                if(p>=0)
                {
                    x--;
                    p+=2*(-dx-dy);
                }
                else
                {
                    p+=2*(-dx);
                }
            }
        }
        else if(dy < 0 && dx > 0){
            p= 2*dx+dy;
            for(;y>=y2;y--){
                pixel[x][y] = Qt::black;
                if(p>=0)
                {
                    x++;
                    p+=2*(dx+dy);
                }
                else
                {
                    p+=2*dx;
                }
            }
        }
        else{
            p= -2*dx+dy;
            for(;y>=y2;y--){
                pixel[x][y] = Qt::black;
                if(p>=0)
                {
                    x--;
                    p+=2*(-dx+dy);
                }
                else
                {
                    p+=2*(-dx);
                }
            }
        }
    }
}

void PaintedPalatte::EllipsePadding(int rx,int ry,int xc,int yc)
{
    double x = 0, y = ry;
    double p1 = pow(ry,2)-pow(rx,2)*ry+pow(rx,2)/4;
    while(pow(ry,2)*x<pow(rx,2)*y){
        pixel[(int)x+xc][(int)y+yc] = Qt::black;
        pixel[(int)x+xc][-(int)y+yc] = Qt::black;
        pixel[-(int)x+xc][(int)y+yc] = Qt::black;
        pixel[-(int)x+xc][-(int)y+yc] = Qt::black;
        x++;
        if(p1<0){
            p1 = p1 + 2*pow(ry,2)*x + pow(ry,2);
        }
        else{
            y--;
            p1 = p1 + 2*pow(ry,2)*x - 2*pow(rx,2)*y + pow(ry,2);
        }
    }
    double p2 = pow(ry,2)*pow((x+0.5),2)+pow(rx,2)*pow((y-1),2)-pow(rx,2)*pow(ry,2);
    while(y>=0){
        pixel[(int)x+xc][(int)y+yc] = Qt::black;
        pixel[(int)x+xc][-(int)y+yc] = Qt::black;
        pixel[-(int)x+xc][(int)y+yc] = Qt::black;
        pixel[-(int)x+xc][-(int)y+yc] = Qt::black;
        y--;
        if(p2>0){
            p2 = p2 - 2*pow(rx,2)*y + pow(rx,2);
        }
        else{
            x++;
            p2 = p2 + 2*pow(ry,2)*x - 2*pow(rx,2)*y + pow(rx,2);
        }
    }
}

void PaintedPalatte::RectPadding(int x1,int y1,int x2,int y2)
{
    LinePadding(x1,y1,x1,y2);
    LinePadding(x1,y1,x2,y1);
    LinePadding(x2,y1,x2,y2);
    LinePadding(x1,y2,x2,y2);
}

bool PaintedPalatte::EditLine(int x,int y)
{
    Figure l = f.last();
    if(l.s == LINE &&
       x >= l.pp.x1 - POINT_SIZE &&
       x <= l.pp.x1 + POINT_SIZE &&
       y >= l.pp.y1 - POINT_SIZE &&
       y <= l.pp.y1 + POINT_SIZE)
    {
        //qDebug()<<"you have come here!"<<endl;
        lastf = f.last();
        x1 = l.pp.x2;
        y1 = l.pp.y2;
        x2 = x;
        y2 = y;
        isLeftPressed = true;
        f.pop_back();
        return true;
    }
    else if(l.s == LINE &&
            x >= l.pp.x2 - POINT_SIZE &&
            x <= l.pp.x2 + POINT_SIZE &&
            y >= l.pp.y2 - POINT_SIZE &&
            y <= l.pp.y2 + POINT_SIZE)
    {
        //qDebug()<<"you have come here!"<<endl;
        lastf = f.last();
        x1 = l.pp.x1;
        y1 = l.pp.y1;
        x2 = x;
        y2 = y;
        isLeftPressed = true;
        f.pop_back();
        return true;
    }
    else if(l.s == LINE &&
            x >= (l.pp.x1 + l.pp.x2)/2 - POINT_SIZE &&
            x <= (l.pp.x1 + l.pp.x2)/2 + POINT_SIZE &&
            y >= (l.pp.y1 + l.pp.y2)/2 - POINT_SIZE &&
            y <= (l.pp.y1 + l.pp.y2)/2 + POINT_SIZE)
    {
        //qDebug()<<"you have come here!"<<endl;
        lastf = f.last();
        x1 = l.pp.x1;
        y1 = l.pp.y1;
        x2 = l.pp.x2;
        y2 = l.pp.y2;
        isLeftPressed = true;
        isParalell = true;
        f.pop_back();
        return true;
    }
    else{
        return false;
    }
}

bool PaintedPalatte::EditEllipse(int x, int y)
{
    Figure l = f.last();
    if(l.s == ELLIPSE &&
       x >= (l.pp.x1+l.pp.x2)/2 - POINT_SIZE &&
       x <= (l.pp.x1+l.pp.x2)/2 + POINT_SIZE &&
       y >= l.pp.y1 - POINT_SIZE &&
       y <= l.pp.y1 + POINT_SIZE)
    {
        //qDebug()<<"you have come here!"<<endl;
        lastf = f.last();
        x1 = l.pp.x1;
        y1 = l.pp.y1;
        x2 = l.pp.x2;
        y2 = l.pp.y2;
        isLeftPressed = true;
        isEdity1 = true;
        f.pop_back();
        return true;
    }
    else if(l.s == ELLIPSE &&
       x >= (l.pp.x1+l.pp.x2)/2 - POINT_SIZE &&
       x <= (l.pp.x1+l.pp.x2)/2 + POINT_SIZE &&
       y >= l.pp.y2 - POINT_SIZE &&
       y <= l.pp.y2 + POINT_SIZE)
    {
        //qDebug()<<"you have come here!"<<endl;
        lastf = f.last();
        x1 = l.pp.x1;
        y1 = l.pp.y1;
        x2 = l.pp.x2;
        y2 = l.pp.y2;
        isLeftPressed = true;
        isEdity2 = true;
        f.pop_back();
        return true;
    }
    else if(l.s == ELLIPSE &&
       x >= l.pp.x1 - POINT_SIZE &&
       x <= l.pp.x1 + POINT_SIZE &&
       y >= (l.pp.y1+l.pp.y2)/2 - POINT_SIZE &&
       y <= (l.pp.y1+l.pp.y2)/2 + POINT_SIZE)
    {
        //qDebug()<<"you have come here!"<<endl;
        lastf = f.last();
        x1 = l.pp.x1;
        y1 = l.pp.y1;
        x2 = l.pp.x2;
        y2 = l.pp.y2;
        isLeftPressed = true;
        isEditx1 = true;
        f.pop_back();
        return true;
    }
    else if(l.s == ELLIPSE &&
       x >= l.pp.x2 - POINT_SIZE &&
       x <= l.pp.x2 + POINT_SIZE &&
       y >= (l.pp.y1+l.pp.y2)/2 - POINT_SIZE &&
       y <= (l.pp.y1+l.pp.y2)/2 + POINT_SIZE)
    {
        //qDebug()<<"you have come here!"<<endl;
        lastf = f.last();
        x1 = l.pp.x1;
        y1 = l.pp.y1;
        x2 = l.pp.x2;
        y2 = l.pp.y2;
        isLeftPressed = true;
        isEditx2 = true;
        f.pop_back();
        return true;
    }
    else if(l.s == ELLIPSE &&
       x >= (l.pp.x1+l.pp.x2)/2 - POINT_SIZE &&
       x <= (l.pp.x1+l.pp.x2)/2 + POINT_SIZE &&
       y >= (l.pp.y1+l.pp.y2)/2 - POINT_SIZE &&
       y <= (l.pp.y1+l.pp.y2)/2 + POINT_SIZE)
    {
        //qDebug()<<"you have come here!"<<endl;
        lastf = f.last();
        x1 = l.pp.x1;
        y1 = l.pp.y1;
        x2 = l.pp.x2;
        y2 = l.pp.y2;
        isLeftPressed = true;
        isParalell = true;
        f.pop_back();
        return true;
    }
    else{
        return false;
    }
}

bool PaintedPalatte::EditRect(int x, int y)
{
    Figure l = f.last();
    if(l.s == RECTANGLE &&
       x >= (l.pp.x1+l.pp.x2)/2 - POINT_SIZE &&
       x <= (l.pp.x1+l.pp.x2)/2 + POINT_SIZE &&
       y >= l.pp.y1 - POINT_SIZE &&
       y <= l.pp.y1 + POINT_SIZE)
    {
        //qDebug()<<"you have come here!"<<endl;
        lastf = f.last();
        x1 = l.pp.x1;
        y1 = l.pp.y1;
        x2 = l.pp.x2;
        y2 = l.pp.y2;
        isLeftPressed = true;
        isEdity1 = true;
        f.pop_back();
        return true;
    }
    else if(l.s == RECTANGLE &&
       x >= (l.pp.x1+l.pp.x2)/2 - POINT_SIZE &&
       x <= (l.pp.x1+l.pp.x2)/2 + POINT_SIZE &&
       y >= l.pp.y2 - POINT_SIZE &&
       y <= l.pp.y2 + POINT_SIZE)
    {
        //qDebug()<<"you have come here!"<<endl;
        lastf = f.last();
        x1 = l.pp.x1;
        y1 = l.pp.y1;
        x2 = l.pp.x2;
        y2 = l.pp.y2;
        isLeftPressed = true;
        isEdity2 = true;
        f.pop_back();
        return true;
    }
    else if(l.s == RECTANGLE &&
       x >= l.pp.x1 - POINT_SIZE &&
       x <= l.pp.x1 + POINT_SIZE &&
       y >= (l.pp.y1+l.pp.y2)/2 - POINT_SIZE &&
       y <= (l.pp.y1+l.pp.y2)/2 + POINT_SIZE)
    {
        //qDebug()<<"you have come here!"<<endl;
        lastf = f.last();
        x1 = l.pp.x1;
        y1 = l.pp.y1;
        x2 = l.pp.x2;
        y2 = l.pp.y2;
        isLeftPressed = true;
        isEditx1 = true;
        f.pop_back();
        return true;
    }
    else if(l.s == RECTANGLE &&
       x >= l.pp.x2 - POINT_SIZE &&
       x <= l.pp.x2 + POINT_SIZE &&
       y >= (l.pp.y1+l.pp.y2)/2 - POINT_SIZE &&
       y <= (l.pp.y1+l.pp.y2)/2 + POINT_SIZE)
    {
        //qDebug()<<"you have come here!"<<endl;
        lastf = f.last();
        x1 = l.pp.x1;
        y1 = l.pp.y1;
        x2 = l.pp.x2;
        y2 = l.pp.y2;
        isLeftPressed = true;
        isEditx2 = true;
        f.pop_back();
        return true;
    }
    else if(l.s == RECTANGLE &&
       x >= l.pp.x1 - POINT_SIZE &&
       x <= l.pp.x1 + POINT_SIZE &&
       y >= l.pp.y1 - POINT_SIZE &&
       y <= l.pp.y1 + POINT_SIZE)
    {
        //qDebug()<<"you have come here!"<<endl;
        lastf = f.last();
        x1 = l.pp.x1;
        y1 = l.pp.y1;
        x2 = l.pp.x2;
        y2 = l.pp.y2;
        isLeftPressed = true;
        isEditx1 = true;
        isEdity1 = true;
        f.pop_back();
        return true;
    }
    else if(l.s == RECTANGLE &&
       x >= l.pp.x1 - POINT_SIZE &&
       x <= l.pp.x1 + POINT_SIZE &&
       y >= l.pp.y2 - POINT_SIZE &&
       y <= l.pp.y2 + POINT_SIZE)
    {
        //qDebug()<<"you have come here!"<<endl;
        lastf = f.last();
        x1 = l.pp.x1;
        y1 = l.pp.y1;
        x2 = l.pp.x2;
        y2 = l.pp.y2;
        isLeftPressed = true;
        isEditx1 = true;
        isEdity2 = true;
        f.pop_back();
        return true;
    }
    else if(l.s == RECTANGLE &&
       x >= l.pp.x2 - POINT_SIZE &&
       x <= l.pp.x2 + POINT_SIZE &&
       y >= l.pp.y1 - POINT_SIZE &&
       y <= l.pp.y1 + POINT_SIZE)
    {
        //qDebug()<<"you have come here!"<<endl;
        lastf = f.last();
        x1 = l.pp.x1;
        y1 = l.pp.y1;
        x2 = l.pp.x2;
        y2 = l.pp.y2;
        isLeftPressed = true;
        isEditx2 = true;
        isEdity1 = true;
        f.pop_back();
        return true;
    }
    else if(l.s == RECTANGLE &&
       x >= l.pp.x2 - POINT_SIZE &&
       x <= l.pp.x2 + POINT_SIZE &&
       y >= l.pp.y2 - POINT_SIZE &&
       y <= l.pp.y2 + POINT_SIZE)
    {
        //qDebug()<<"you have come here!"<<endl;
        lastf = f.last();
        x1 = l.pp.x1;
        y1 = l.pp.y1;
        x2 = l.pp.x2;
        y2 = l.pp.y2;
        isLeftPressed = true;
        isEditx2 = true;
        isEdity2 = true;
        f.pop_back();
        return true;
    }
    else if(l.s == RECTANGLE &&
       x >= (l.pp.x1+l.pp.x2)/2 - POINT_SIZE &&
       x <= (l.pp.x1+l.pp.x2)/2 + POINT_SIZE &&
       y >= (l.pp.y1+l.pp.y2)/2 - POINT_SIZE &&
       y <= (l.pp.y1+l.pp.y2)/2 + POINT_SIZE)
    {
        //qDebug()<<"you have come here!"<<endl;
        lastf = f.last();
        x1 = l.pp.x1;
        y1 = l.pp.y1;
        x2 = l.pp.x2;
        y2 = l.pp.y2;
        isLeftPressed = true;
        isParalell = true;
        f.pop_back();
        return true;
    }
    else{
        return false;
    }
}

PaintedPalatte::PaintedPalatte(QWidget *parent):
    QWidget(parent), x1(0), y1(0), x2(0), y2(0),
    padding_color(Qt:: red)
{
    resize(WINDOW_WIDTH, WINDOW_HEIGHT);
    isTailor = false;
    isLeftPressed = false;
    isParalell = false;
    isEditx1 = false;
    isEdity1 = false;
    isEditx2 = false;
    isEdity2 = false;
    isPadding = false;
    f.clear();
    for(int i = 0; i < MAX_WIDTH; i++)
        for(int j = 0; j < MAX_HEIGHT; j++){
            pixel[i][j] = Qt::white;
        }
}

void PaintedPalatte::x1Change(int value){
    x1 = value;
    update();
}

void PaintedPalatte::y1Change(int value){
    y1 = value;
    update();
}

void PaintedPalatte::x2Change(int value){
    x2 = value;
    update();
}

void PaintedPalatte::y2Change(int value){
    y2 = value;
    update();
}

void PaintedPalatte::paintEvent(QPaintEvent *)
{
    QVector<QPoint> curse_points;
    curse_points.clear();

    auto it = f.begin();
    while (it != f.end()) {
        if(it != f.begin() && it->s == DEFAULT)
            it = f.erase(it);
        else
            it++;
    }

    disproc_padding();
    for(auto lt = f.begin();lt!=f.end();lt++){
        switch(lt->s){
        case LINE:
            BresenhamLine(lt->pp.x1,lt->pp.y1, lt->pp.x2,lt->pp.y2);
            LinePadding(lt->pp.x1,lt->pp.y1, lt->pp.x2,lt->pp.y2);
            break;
        case ELLIPSE:
            CenterEllipse(qAbs((lt->pp.x2-lt->pp.x1)/2),qAbs((lt->pp.y2-lt->pp.y1)/2),
                          (lt->pp.x1+lt->pp.x2)/2,(lt->pp.y1+lt->pp.y2)/2);
            EllipsePadding(qAbs((lt->pp.x2-lt->pp.x1)/2),qAbs((lt->pp.y2-lt->pp.y1)/2),
                           (lt->pp.x1+lt->pp.x2)/2,(lt->pp.y1+lt->pp.y2)/2);
            break;
        case RECTANGLE:
            TrivialRect(lt->pp.x1,lt->pp.y1, lt->pp.x2,lt->pp.y2);
            RectPadding(lt->pp.x1,lt->pp.y1, lt->pp.x2,lt->pp.y2);
            break;
        case POLYGON:
            BresenhamLine(lt->pp.x1,lt->pp.y1, lt->pp.x2,lt->pp.y2);
            LinePadding(lt->pp.x1,lt->pp.y1, lt->pp.x2,lt->pp.y2);
            break;
        case CURSE:
            if(curse_points.size() == 0){
                QPoint tmp1(lt->pp.x1,lt->pp.y1);
                curse_points.append(tmp1);
                QPoint tmp2(lt->pp.x2,lt->pp.y2);
                curse_points.append(tmp2);
            }
            else{
                QPoint tmp(lt->pp.x2,lt->pp.y2);
                curse_points.append(tmp);
            }
            proc_curse(curse_points);
            if(curse_points.size() == 4){
                curse_points.clear();
            }
            break;
        case PADPOINT:
            proc_padding(lt->pp.x1,lt->pp.y1,lt->c,lt->bound);
            break;
        default: break;
        }
    }

    if(isTailor){
        QPainter painter(this);
        QPen pen;
        QVector<qreal> dashes;
        qreal space = 3;
        dashes << 5 << space << 5 <<space;
        pen.setDashPattern(dashes);
        //pen.setWidth(2);
        painter.setPen(pen);
        painter.drawRect(x1,y1,x2-x1,y2-y1);
    }
    else if(isPadding && isLeftPressed){
        PointPair bound = {0, 0, MAX_WIDTH-50, MAX_HEIGHT};
        proc_padding(x1, y1, padding_color, bound);
    }
    else if(shape == LINE){
        BresenhamLine(x1,y1,x2,y2);
        QPainter painter(this);
        QPen pen;
        pen.setBrush(Qt::red);
        pen.setWidth(POINT_SIZE);
        painter.setPen(pen);
        painter.drawPoint(x1,y1);
        painter.drawPoint(x2,y2);
        painter.drawPoint((x1+x2)/2,(y1+y2)/2);
    }
    else if(shape == ELLIPSE){
        CenterEllipse(qAbs((x2-x1)/2),qAbs((y2-y1)/2),(x1+x2)/2,(y1+y2)/2);
        QPainter painter(this);
        QPen pen;
        pen.setBrush(Qt::red);
        pen.setWidth(POINT_SIZE);
        painter.setPen(pen);
        painter.drawPoint((x1+x2)/2,y1);
        painter.drawPoint((x1+x2)/2,y2);
        painter.drawPoint(x1,(y1+y2)/2);
        painter.drawPoint(x2,(y1+y2)/2);
        painter.drawPoint((x1+x2)/2,(y1+y2)/2);
    }
    else if(shape == RECTANGLE){
        TrivialRect(x1,y1,x2,y2);
        QPainter painter(this);
        QPen pen;
        pen.setBrush(Qt::red);
        pen.setWidth(POINT_SIZE);
        painter.setPen(pen);
        painter.drawPoint((x1+x2)/2,y1);
        painter.drawPoint((x1+x2)/2,y2);
        painter.drawPoint(x1,(y1+y2)/2);
        painter.drawPoint(x2,(y1+y2)/2);
        painter.drawPoint(x1,y1);
        painter.drawPoint(x1,y2);
        painter.drawPoint(x2,y1);
        painter.drawPoint(x2,y2);
        painter.drawPoint((x1+x2)/2,(y1+y2)/2);
    }
    else if(shape == POLYGON){
        BresenhamLine(x1,y1,x2,y2);
        QPainter painter(this);
        QPen pen;
        pen.setBrush(Qt::red);
        pen.setWidth(POINT_SIZE);
        painter.setPen(pen);
        painter.drawPoint(x1,y1);
        painter.drawPoint(x2,y2);
    }
    else if(shape == CURSE && isLeftPressed){
        BresenhamLine(x1,y1,x2,y2);
        QPainter painter(this);
        QPen pen;
        pen.setBrush(Qt::red);
        pen.setWidth(POINT_SIZE);
        painter.setPen(pen);
        painter.drawPoint(x1,y1);
        painter.drawPoint(x2,y2);
    }
    else{
        ;//donothing
    }
}

void PaintedPalatte::mousePressEvent(QMouseEvent *e)
{
    //qDebug()<<e->x()<<" "<<e->y()<<endl;
    if(isPadding)
    {
        if(e->buttons() & Qt::LeftButton)
        {
            x1 = e->x();
            y1 = e->y();
            isLeftPressed = true;
        }
        else {
            isPadding = false;
            shape = LINE;
        }
        return;
    }

    isParalell = false;
    isEditx1 = false;
    isEdity1 = false;
    isEditx2 = false;
    isEdity2 = false;
    if(e->buttons() & Qt::LeftButton){
        if(f.size()!=0){
            if(EditLine(e->x(),e->y()) == true)
                return;
            if(EditEllipse(e->x(),e->y()) == true)
                return;
            if(EditRect(e->x(),e->y()) == true)
                return;
        }
        if(shape == DEFAULT)
            shape = lastf.s;
        x1 = e->x();
        y1 = e->y();
        x2 = e->x();
        y2 = e->y();
        if(shape == POLYGON && isPolyFirst == 0){
            if(f.size()!=0){
               x1 = f.last().pp.x2;
               y1 = f.last().pp.y2;
            }
            else {
               isPolyFirst = 1; //撤销到第一条。
            }
        }
        else if(shape == CURSE && isCurseFirst == 0){
            if(f.size()!=0){
               x1 = f.last().pp.x2;
               y1 = f.last().pp.y2;
            }
            else {
               isCurseFirst = 1; //撤销到第一条。
            }
        }
        isLeftPressed = true;
    }
    else if(e->buttons() & Qt::RightButton){
        if(shape == POLYGON && isPolyFirst == 0 && isCurseFirst == 0)
            return;
        if(f.size()!=0){
            if(shape == POLYGON)
            {
                if(f.last().s != POLYGON)
                    return;
                do{
                     f.pop_back();
                }
                while(f.size()!=0 && (f.last().pp.x1 != polystartx1
                   || f.last().pp.y1 != polystarty1));
                if(f.size()!=0)
                    f.pop_back();
                isPolyFirst = 1;
                shape = DEFAULT;
                update();
            }
            else if(shape == CURSE)
            {
                if(f.last().s != CURSE)
                    return;
                do{
                     f.pop_back();
                }
                while(f.size()!=0 && (f.last().pp.x1 != cursestartx1
                   || f.last().pp.y1 != cursestarty1));
                if(f.size()!=0)
                    f.pop_back();
                isCurseFirst = 1;
                shape = DEFAULT;
                update();
            }
            else
            {
                lastf = f.last();
                f.pop_back();
                shape = DEFAULT;
                //qDebug()<<"f.size() = "<<f.size()<<endl;
                update();
            }
        }
    }
}

void PaintedPalatte::mouseMoveEvent(QMouseEvent *e)
{
    if(isPadding){
        return;
    }

    if(isLeftPressed)
    {
        if(!isParalell && !isEditx1 && !isEdity1 && !isEditx2 && !isEdity2){
            x2 = e->x();
            y2 = e->y();
            update();
        }
        if(isParalell){
            x1 = lastf.pp.x1 + e->x() -(lastf.pp.x1 + lastf.pp.x2)/2;
            y1 = lastf.pp.y1 + e->y() -(lastf.pp.y1 + lastf.pp.y2)/2;
            x2 = lastf.pp.x2 + e->x() -(lastf.pp.x1 + lastf.pp.x2)/2;
            y2 = lastf.pp.y2 + e->y() -(lastf.pp.y1 + lastf.pp.y2)/2;
            update();
        }
        if(isEditx1){
            x1 = e->x();
            update();
        }
        if(isEdity1){
            y1 = e->y();
            update();
        }
        if(isEditx2){
            x2 = e->x();
            update();
        }
        if(isEdity2){
            y2 = e->y();
            update();
        }
    }
}

void PaintedPalatte::mouseReleaseEvent(QMouseEvent *)
{
    if(isTailor){
        isLeftPressed=false;
        update();
        return;
    }

    if(isPadding && isLeftPressed){
        //qDebug()<<"you should come here"<<endl;
        //qDebug()<<isPadding<<" "<<isLeftPressed<<endl;
        repaint();
        isLeftPressed = false;
        Figure tmp;
        tmp.pp = {x1,y1,x1,y1};
        tmp.c = padding_color;
        tmp.bound = {0, 0, MAX_WIDTH-50, MAX_HEIGHT};
        tmp.s = PADPOINT;
        f.append(tmp);
        update();
        return;
    }

    if(isLeftPressed){
        if(shape == POLYGON){
            if(isPolyFirst == 1){
                polystartx1 = x1;
                polystarty1 = y1;
                isPolyFirst = 0;
            }
            else if(x2 >= polystartx1 - POINT_SIZE &&
                    x2 <= polystartx1 + POINT_SIZE &&
                    y2 >= polystarty1 - POINT_SIZE &&
                    y2 <= polystarty1 + POINT_SIZE){
                x2 = polystartx1;
                y2 = polystarty1;
                isPolyFirst = 1;
            }
        }
        else if(shape == CURSE){
            if(isCurseFirst == 1){
                cursestartx1 = x1;
                cursestarty1 = y1;
                isCurseFirst = 0;
                curse_counter = 1;
            }
            else if(curse_counter == 2)
            {
                isCurseFirst = 1;
                curse_counter = 0;
            }
            else
            {
                curse_counter ++;
            }
        }
        Figure tmp;
        switch(shape){
        case LINE:  tmp.s = LINE; break;
        case ELLIPSE: tmp.s = ELLIPSE; break;
        case RECTANGLE: tmp.s = RECTANGLE; break;
        case POLYGON: tmp.s = POLYGON; break;
        case CURSE: tmp.s = CURSE; break;
        default: break;
        }
        tmp.pp = {x1,y1,x2,y2};
        tmp.c = Qt::black;
        if(shape!=DEFAULT)
            f.append(tmp);
    }
    //qDebug()<<"size = "<<f.size()<<endl;
    isLeftPressed=false;
    update();
}

void PaintedPalatte::keyPressEvent(QKeyEvent *e)
{
    if(isTailor && (e->key() == Qt::Key_Enter
                    || e->key() == Qt::Key_Return) )
    {
        int winxmin = x1<x2?x1:x2;
        int winxmax = x1>x2?x1:x2;
        int winymin = y1<y2?y1:y2;
        int winymax = y1>y2?y1:y2;

        for (auto lt = f.begin(); lt != f.end(); lt++) {
            switch(lt->s){
            case LINE: {
                PointPair tmpp = tailLine(lt->pp, x1, y1, x2, y2);
                if(tmpp.x1 == 0 && tmpp.y1 == 0 && tmpp.x2 == 0 && tmpp.y2 == 0)
                    lt->s = DEFAULT;
                else
                {
                    lt->pp = tmpp;
                }
                break;
            }
            case RECTANGLE: {
                PointPair tmp[4] = {
                    {lt->pp.x1, lt->pp.y1, lt->pp.x1, lt->pp.y2},
                    {lt->pp.x1, lt->pp.y1, lt->pp.x2, lt->pp.y1},
                    {lt->pp.x2, lt->pp.y1, lt->pp.x2, lt->pp.y2},
                    {lt->pp.x1, lt->pp.y2, lt->pp.x2, lt->pp.y2}
                };
                PointPair tmpp;
                int flag = 0;
                int xmin = lt->pp.x1 < lt->pp.x2 ? lt->pp.x1 : lt->pp.x2;
                int xmax = lt->pp.x1 > lt->pp.x2 ? lt->pp.x1 : lt->pp.x2;
                int ymin = lt->pp.y1 < lt->pp.y2 ? lt->pp.y1 : lt->pp.y2;
                int ymax = lt->pp.y1 > lt->pp.y2 ? lt->pp.y1 : lt->pp.y2;
                if(xmin > winxmin && xmax < winxmax && ymin > winymin && ymax < winymax)
                    continue;
                else for(int i = 0; i < 4; i++){
                    lt->s = DEFAULT;
                    Figure tmpf;
                    tmpf.c = Qt::black;
                    tmpp = tailLine(tmp[i], x1, y1, x2, y2);
                    //qDebug()<<i<<": "<<tmpp.x1<<" "<<tmpp.y1<<" "<<tmpp.x2<<" "<<tmpp.y2<<endl;
                    tmpf.pp = tmpp;
                    if(tmpp.x1 == 0 && tmpp.y1 == 0 && tmpp.x2 == 0 && tmpp.y2 == 0)
                        tmpf.s = DEFAULT;
                    else
                    {
                        flag++;
                        tmpf.s = LINE;
                        lt = f.insert(lt, tmpf);
                        lt ++;
                    }
                }
                break;
            }
            case POLYGON: {
                PointPair tmp = tailLine(lt->pp, x1, y1, x2, y2);
                if(tmp.x1 == 0 && tmp.y1 == 0 && tmp.x2 == 0 && tmp.y2 == 0)
                    lt->s = DEFAULT;
                else
                {
                    lt->pp = tmp;
                }
                break;
            }
            case PADPOINT: {
                if(lt->pp.x1>=winxmin && lt->pp.x1<=winxmax && lt->pp.y1>=winymin && lt->pp.y1<=winymax)
                    lt->bound = {winxmin,winymin,winxmax,winymax};
                else
                    lt->s = DEFAULT;
                break;
            }
            default: break;
            }
        }
    }
}

void PaintedPalatte::keyReleaseEvent(QKeyEvent *e)
{
    if(isTailor && (e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return) )
    {
        isTailor = 0;
        this->setFocusPolicy(Qt::NoFocus);
        shape = DEFAULT;
        update();
    }
}

void PaintedPalatte::rotate(int degree)
{
    if(f.size()==0)//当画图板中没有图形时，什么也不做。
        return;

    double COS = cos(double(degree) / 180 * PI);
    double SIN = sin(double(degree) / 180 * PI);

    int xr = round((x1+x2)/2);
    int yr = round((y1+y2)/2);
    double xx1 = x1;
    double yy1 = y1;
    double xx2 = x2;
    double yy2 = y2;
    x1 = round(xr + (xx1-xr) * COS - (yy1-yr) * SIN);
    y1 = round(yr + (xx1-xr) * SIN + (yy1-yr) * COS);
    x2 = round(xr + (xx2-xr) * COS - (yy2-yr) * SIN);
    y2 = round(yr + (xx2-xr) * SIN + (yy2-yr) * COS);

    Figure tmp;
    switch(shape){
      case LINE:  tmp.s = LINE; break;
      case ELLIPSE: tmp.s = ELLIPSE; break;
      case RECTANGLE: tmp.s = RECTANGLE; break;
      default: return;
    }
    f.pop_back();
    tmp.pp = {x1,y1,x2,y2};
    tmp.c = Qt::black;
    f.append(tmp);

    update();
}

void PaintedPalatte::zoom(double times)
{
    if(f.size()==0)//当画图板中没有图形时，什么也不做。
        return;

    double x_mid = (x1+x2)/2;
    double y_mid = (y1+y2)/2;
    int x1_new = round(times * (x1 - x_mid) + x_mid);
    int y1_new = round(times * (y1 - y_mid) + y_mid);
    int x2_new = round(times * (x2 - x_mid) + x_mid);
    int y2_new = round(times * (y2 - y_mid) + y_mid);

    if(x1_new < 0 || x1_new > MAX_WIDTH || x2_new < 0 || x2_new > MAX_WIDTH
       || y1_new < 0 || y1_new > MAX_HEIGHT || y2_new < 0 || y2_new > MAX_HEIGHT)
        return;
    else{
        x1 = x1_new;
        y1 = y1_new;
        x2 = x2_new;
        y2 = y2_new;
    }


    Figure tmp;
    switch(shape){
      case LINE:  tmp.s = LINE;break;
      case ELLIPSE: tmp.s = ELLIPSE; break;
      case RECTANGLE: tmp.s = RECTANGLE; break;
      default: return;
    }
    f.pop_back();
    tmp.pp = {x1,y1,x2,y2};
    tmp.c = Qt::black;
    f.append(tmp);

    update();
}

void PaintedPalatte::padding(QColor color)
{
    shape = PADPOINT;
    isPadding = true;
    padding_color = color;
}

void PaintedPalatte::proc_padding(int x, int y, QColor c, PointPair bound)
{
     QPainter painter(this);
     painter.setPen(c);
     painter.drawPoint(x,y);
     pixel[x][y] = c;
     QVector<QPoint> stack;
     QPoint start(x,y);
     pixel[start.x()][start.y()] = c;
     stack.push_back(start);
     while(stack.size()!=0)
     {
        QPoint tmp = stack.last();
        painter.drawPoint(tmp.x(),tmp.y());
        stack.pop_back();
        if(tmp.x()>bound.x1 && (pixel[tmp.x() - 1][tmp.y()] != Qt::black &&
                                pixel[tmp.x() - 1][tmp.y()] != c))
        {
            QPoint tmp2(tmp.x() - 1,tmp.y());
            pixel[tmp2.x()][tmp2.y()] = c;
            stack.push_back(tmp2);
        }
        if(tmp.x()<bound.x2 && (pixel[tmp.x() + 1][tmp.y()] != Qt::black &&
                                pixel[tmp.x() + 1][tmp.y()] != c))
        {
            QPoint tmp2(tmp.x() + 1,tmp.y());
            pixel[tmp2.x()][tmp2.y()] = c;
            stack.push_back(tmp2);
        }
        if(tmp.y()>bound.y1 && (pixel[tmp.x()][tmp.y()-1] != Qt::black &&
                                pixel[tmp.x()][tmp.y()-1] != c))
        {
            QPoint tmp2(tmp.x(),tmp.y() - 1);
            pixel[tmp2.x()][tmp2.y()] = c;
            stack.push_back(tmp2);
        }
        if(tmp.y()<bound.y2 && (pixel[tmp.x()][tmp.y()+1] != Qt::black &&
                                pixel[tmp.x()][tmp.y()+1] != c))
        {
            QPoint tmp2(tmp.x(),tmp.y() + 1);
            pixel[tmp2.x()][tmp2.y()] = c;
            stack.push_back(tmp2);
        }
     }
}

void PaintedPalatte::disproc_padding()
{
    for(int i = 0; i < MAX_WIDTH; i++)
        for(int j = 0; j < MAX_HEIGHT; j++){
            pixel[i][j] = Qt::white;
        }
}

void PaintedPalatte::proc_curse(QVector<QPoint> points)
{
    if(points.size() != 4)
        return;
    QPainter painter(this);
    painter.setPen(Qt::black);
    for(double t = 0;t < 1; t += 0.0005)
    {
        int x = pow((1-t),3) * points[0].x() +
                3 * pow((1-t),2) * t * points[1].x() +
                3 * (1-t) * pow(t,2) * points[2].x() +
                pow(t,3) * points[3].x();
        int y = pow((1-t),3) * points[0].y() +
                3 * pow((1-t),2) * t * points[1].y() +
                3 * (1-t) * pow(t,2) * points[2].y() +
                pow(t,3) * points[3].y();
        pixel[x][y] = Qt::black;
        painter.drawPoint(x,y);
    }
}

float maxi(float arr[],int n) {
  float m = 0;
  for (int i = 0; i < n; ++i)
    if (m < arr[i])
      m = arr[i];
  return m;
}

float mini(float arr[], int n) {
  float m = 1;
  for (int i = 0; i < n; ++i)
    if (m > arr[i])
      m = arr[i];
  return m;
}

PointPair PaintedPalatte::tailLine(PointPair pp, int x1, int y1, int x2, int y2)
{
    PointPair tmp{0,0,0,0};
    //float u1 = 0, u2 = 1;
    float xmin = x1<x2?x1:x2;
    float xmax = x1>x2?x1:x2;
    float ymin = y1<y2?y1:y2;
    float ymax = y1>y2?y1:y2;
    float deltax = pp.x2 - pp.x1;
    float deltay = pp.y2 - pp.y1;
    float p1 = -deltax, p2 = deltax, p3 = -deltay, p4 = deltay;
    float q1 = pp.x1 - xmin, q2 = xmax - pp.x1, q3 = pp.y1 - ymin, q4 = ymax - pp.y1;
    float posarr[5], negarr[5];
    int posind = 1, negind = 1;
    posarr[0] = 1;
    negarr[0] = 0;
    if((p1 == 0 && q1 < 0) || (p2 == 0 && q2 < 0) || (p3 == 0 && q3 < 0) || (p4 == 0 && q4 < 0))
        return tmp;
    if (p1 != 0) {
        float r1 = q1 / p1;
        float r2 = q2 / p2;
        if (p1 < 0) {
          negarr[negind++] = r1; // for negative p1, add it to negative array
          posarr[posind++] = r2; // and add p2 to positive array
        } else {
          negarr[negind++] = r2;
          posarr[posind++] = r1;
        }
    }
    if (p3 != 0) {
       float r3 = q3 / p3;
       float r4 = q4 / p4;
       if (p3 < 0) {
          negarr[negind++] = r3;
          posarr[posind++] = r4;
       } else {
          negarr[negind++] = r4;
          posarr[posind++] = r3;
       }
    }
    float xn1, yn1, xn2, yn2;
    float rn1, rn2;
    rn1 = maxi(negarr, negind); // maximum of negative array
    rn2 = mini(posarr, posind); // minimum of positive array
    if (rn1 > rn2)
        return tmp;
    xn1 = pp.x1 + p2 * rn1;
    yn1 = pp.y1 + p4 * rn1; // computing new points

    xn2 = pp.x1 + p2 * rn2;
    yn2 = pp.y1 + p4 * rn2;
    tmp.x1 = xn1;
    tmp.y1 = yn1;
    tmp.x2 = xn2;
    tmp.y2 = yn2;
    return tmp;
}

void PaintedPalatte::savePicture(const QString fileName, const char *format)
{
    QImage image(QSize(this->width(),this->height()),QImage::Format_ARGB32);
    image.fill("white");
    QPainter *painter = new QPainter(&image);
    painter->save();

    for(int i = 0; i < MAX_WIDTH; i++)
        for(int j = 0; j < MAX_HEIGHT; j++){
            painter->setPen(pixel[i][j]);
            painter->drawPoint(i,j);
        }
    painter->restore();
    painter->end();
    saveimage = image;

    qDebug()<<image.save(fileName, format)<<endl;

}

void PaintedPalatte::clear()
{
    while(f.size()!=0)
    {
        f.pop_back();
    }
    shape = DEFAULT;
    update();
}
