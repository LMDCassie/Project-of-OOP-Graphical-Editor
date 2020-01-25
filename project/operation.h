#ifndef OPERATION_H
#define OPERATION_H
#include <QColor>

class Operation
{
public:
    Operation();
    Operation(int t, int w, QColor cc, int xx1, int yy1, int xx2, int yy2, unsigned int num, bool b, QColor fc);
    bool isInside(int x, int y);
    int Type;
    int W;
    QColor C;
    QColor FC;
    int x1;
    int y1;
    int x2;
    int y2;
    unsigned int Layer_No;
    bool isFill;
};

#endif // OPERATION_H
