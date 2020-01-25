#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QtGui>
#include <QtWidgets>
#include <QMainWindow>
#include "operation.h"
#include "layer.h"


class PaintWidget : public QLabel
{
    Q_OBJECT

public:
    explicit PaintWidget(QWidget *parent = nullptr);
    enum shape {
        Pen = 1,Line,Ellipse,Circle, Triangle, Rhombus,
        Rect, Square, Hexagon, Null
    };
    enum drawMode{
        Choose, Draw
    };

    void paint(QImage &theImage);
    void setImage(QImage img);
    QImage getImage(); // 外部获取图像

    void setShape(PaintWidget::shape );                     // 设置绘制类型
    void setMode(PaintWidget::drawMode);
    void setPenWidth(int w);                                // 设置画笔宽度
    void setPenColor(QColor c);                             // 设置画笔颜色
    void setFillColor(QColor c);
    void setFill(bool b);
    void setCurrentLayer(Layer *l);
    void PaintOp(Operation op, double ratio);
    void setRatio(double value);

signals:
    void sendop(Operation op);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    bool findOp();

private:
    PaintWidget::shape type;
    PaintWidget::drawMode mode;
    int penWidth;
    double ratio;
    QColor penColor;
    QColor fillColor;
    QImage image;
    QImage tempImage;
    QPoint lastPoint;
    QPoint endPoint;
    bool isDrawing;
    bool isChosen;
    bool isFilling;
    Layer *currentLayer;
    Operation op;
    unsigned int OperIndex;
    vector<QPoint> pointList;
};

#endif // PAINTWIDGET_H
