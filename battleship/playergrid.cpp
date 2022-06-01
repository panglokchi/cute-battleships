#include "playergrid.h"
#include <QMouseEvent>
#include <QDebug>
#include <QHoverEvent>

PlayerGrid::PlayerGrid(QWidget *parent):QGraphicsView(parent)
{

}

void PlayerGrid::mousePressEvent(QMouseEvent *event) {
    // TODO: take the x, y position, convert to grid index and send the signal mouseClicked to GameWindow
    // NOTE the coordinate system:
    // +----------> x
    // |
    // |
    // |
    // v
    // y
    // Size of the image is 16x16
    // useful docs: https://doc.qt.io/qt-5/qmouseevent.html
    // convert window coordinate to scene coordinate: https://doc.qt.io/qt-5/qgraphicsview.html#mapToScene
    // send signal: emit mouseClicked(int, int);
    //int col = event->x()/16;
    //int row = event->y()/16;
    //qDebug() << event->x() << " " << event->y();
    if ( event->button() == Qt::RightButton ) {
        emit mouseRightClicked();
        return;
    }
    QPointF point = mapToScene(event->x(), event->y());
    //qDebug() << point;
    emit mouseClicked(int(point.y()/16), int(point.x()/16));
}

void PlayerGrid::mouseMoveEvent(QMouseEvent *event) {
    //qDebug() << event->x() << " " << event->y();
    QPointF point = mapToScene(event->x(), event->y());
    //qDebug() << point;
    emit mouseHover(int(point.y()/16), int(point.x()/16));
}
