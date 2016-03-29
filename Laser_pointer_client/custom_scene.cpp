#include "custom_scene.h"

void custom_scene::gotNewPosition(int x, int y)// Deprecated
{
    //printf("%d %d - ",x,y);
}

void custom_scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    MainWindow *parent=(MainWindow*)this->parent();
    QPoint p = QCursor::pos(), pa = parent->pos();  // get MainWindow and GraphicsView positions
    int x = (p.rx()-pa.rx()-39)/2;                  // get x position inside GraphicsView
    int y = (p.ry()-pa.ry()-208)/2;                 // get y position inside GraphicsView
    if( x <= Protocol::POSITION_UPPER_LIMIT && x >= Protocol::POSITION_LOWER_LIMIT &&
            y <= Protocol::POSITION_UPPER_LIMIT && y >= Protocol::POSITION_LOWER_LIMIT)   // if correct position
    {
        Message data;
        unsigned char m[2]={(unsigned char)x,(unsigned char)y};
        data.mode=Protocol::MODE_TRACKING;
        data.data=m;
        parent->putData(&data);                      // send position
    }
}
