#ifndef PLAYER_H
#define PLAYER_H

#include "grid.h"
#include "ship.h"
#include <QGraphicsScene>
#include <QPushButton>

class Player
{
    bool deployed[5] = { 0 };
    bool is_human;
    Grid grid;
    Ship* ships[5];
    Ship* findShipByPos( int row , int col );
    bool checkShipAlive( Ship* ship );
    QPushButton* ship_icons[5];
    int hits{0};
    int misses{0};
    int sunk{0};
protected:
    Player( bool is_human );
public:
    void linkShipIcons( QPushButton* ship_icons[5] );
    Grid getGrid() const;
    bool hasDeployed( Ship::ShipType ship_type );
    bool addShip( Ship::ShipType ship_type , int stern_pos_row , int stern_pos_col , Ship::Orientation orientation , QGraphicsScene& scene);
    Ship* getShip( Ship::ShipType ship_type );
    bool allDeployed();
    void randomDeploy(QGraphicsScene& scene);
    void resetShips();

    int hit(int row, int col, QGraphicsScene& scene);
    bool hasShipsLeft();
    QList<QString> getStats() const;

};



#endif // PLAYER_H
