#ifndef PLAYERGRID_H
#define PLAYERGRID_H

#include <QGraphicsView>

class PlayerGrid : public QGraphicsView
{
    Q_OBJECT
public:
    PlayerGrid(QWidget *parent);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

signals:
    void mouseClicked(int row, int col);
    void mouseRightClicked();
    void mouseHover(int row, int col);
};

#endif // PLAYERGRID_H
