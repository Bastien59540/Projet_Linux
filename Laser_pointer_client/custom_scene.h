/// \author Quentin Berdal
#ifndef CUSTOM_SCENE_H
#define CUSTOM_SCENE_H

#include <QGraphicsScene>
#include "mainwindow.h"
#include "protocol.h"

/*/////////////////////////////////////////////////*/

/** Class QGraphicsScene with mouse tracking.
 */
class custom_scene : public QGraphicsScene
{
    Q_OBJECT
private slots:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);///< Mouse tracking event

public slots:
    void gotNewPosition(int x, int y);/// Deprecated
};

#endif
