#include "operation.h"
#include <algorithm>

using namespace std;

Operation::Operation()
{
    Type = -1;
}

Operation::Operation(int t, int w, QColor cc, int xx1, int yy1, int xx2, int yy2, unsigned int num, bool b, QColor fc)
{
    Type=t;
    W=w;
    C=cc;
    x1=xx1;
    y1=yy1;
    x2=xx2;
    y2=yy2;
    Layer_No=num;
    isFill = b;
    FC = fc;
}

//bool Operation::isInside(int x, int y){
//    if(Type == 4 || Type == 8)  // square || circle
//       {
//           int l=max(abs(x1-x2),abs(y1-y2));
//           if(x >= min(x1, x2) && x <= min(x1, x2)+l && y >= min(y1, y2) && y <= min(y1, y2)+l){
//               return true;
//           }
//           return false;
//       }
//       else if (Type==2) {
//           double length=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//           double l1=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
//           double l2=sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
//           if (length*1.05>l1+l2){
//               return true;
//           }
//           return false;
//       }
//       else{
//           if (x >= min(x1, x2) && x <= max(x1, x2) && y >= min(y1, y2) && y <= max(y1, y2))
//               return true;
//       }
//       return false;
//}

bool Operation::isInside(int x, int y){
    if(Type == 1)  // pen
       {
           return false;
       }
       else if (Type==2) {
           double length=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
           double l1=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
           double l2=sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2));
           if (length*1.05>l1+l2){
               return true;
           }
           return false;
       }
       else{
           if (x >= min(x1, x2) && x <= max(x1, x2) && y >= min(y1, y2) && y <= max(y1, y2))
               return true;
       }
       return false;
}

