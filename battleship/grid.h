#ifndef GRID_H
#define GRID_H

#include "ship.h"
#include <QGraphicsPixmapItem>

class Grid
{
private:
    bool occupied[10][10] = {{0}};
    bool hit[10][10] = {{0}};

public:
    Grid();
    void reset();
    //accessors
    bool isOccupied( int row, int col);
    bool isHit( int row, int col);
    bool allSunk();

    //mutators
    bool addShip( Ship::ShipType ship_type , int stern_pos_row , int stern_pos_col , Ship::Orientation orientation );
    void hitCell( int row , int col);

    QList<QGraphicsPixmapItem*> crosses;
    QList<QGraphicsPixmapItem*> circles;

};

#endif // GRID_H
