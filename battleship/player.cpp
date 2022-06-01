#include "player.h"
#include <QRandomGenerator>
#include <QDateTime>
#include <QDebug>

Player::Player(bool is_human): is_human(is_human)
{

}

void Player::linkShipIcons( QPushButton* ship_icons[5]) {
    for ( int i = 0 ; i < 5 ; i++ ) {
        this->ship_icons[i] = ship_icons[i];
    }
}

Grid Player::getGrid() const {
    return grid;
}

bool Player::hasDeployed(Ship::ShipType ship_type) {
    return deployed[int(ship_type)];
}

bool Player::addShip(Ship::ShipType ship_type, int stern_pos_row, int stern_pos_col, Ship::Orientation orientation , QGraphicsScene& scene) {
    if ( deployed[int(ship_type)] ) {
        return false;
    }
    if ( !grid.addShip( ship_type , stern_pos_row , stern_pos_col , orientation ) ) {
        return false;
    }
    Ship * new_ship = new Ship( ship_type , orientation , stern_pos_row, stern_pos_col , scene , is_human );
    ships[int(ship_type)] = new_ship;
    deployed[int(ship_type)] = true;
    if ( !is_human ) {
        new_ship->setVisible(false);
    }
    return true;
}

Ship* Player::getShip(Ship::ShipType ship_type) {
    return ships[int(ship_type)];
}

bool Player::allDeployed() {
    for ( int i = 0 ; i < 5 ; i++) {
        if ( deployed[i] == false ) {
            return false;
        }
    }
    return true;
}

void Player::randomDeploy(QGraphicsScene& scene) {
    QRandomGenerator generator(QDateTime::currentSecsSinceEpoch());
    while( !allDeployed() ) {
        int row = generator.bounded(10);
        int col = generator.bounded(10);
        Ship::Orientation orientation = Ship::Orientation(generator.bounded(4));
        Ship::ShipType ship_type = Ship::ShipType(generator.bounded(5));
        addShip( ship_type , row , col , orientation , scene );
    }
}

void Player::resetShips() {
    grid.reset();
    for ( int i = 0 ; i < 5 ; i++ ) {
        delete ships[i];
        deployed[i] = false;
    }

}

int Player::hit ( int row , int col, QGraphicsScene& scene ) {
    if ( grid.isHit(row, col) ) {
        return 0;
    }
    grid.hitCell( row , col );
    if ( grid.isOccupied( row , col ) ) {
        QGraphicsPixmapItem * new_circle = scene.addPixmap(QPixmap(":/images/ship_images/red_circle.png"));
        new_circle->setOffset(col*16, row*16);
        grid.circles.append( new_circle );
        Ship * ship_hit = findShipByPos(row, col);
        if ( !checkShipAlive(ship_hit) ) {
            qDebug() << "sunk";
            ship_icons[int(ship_hit->getType())]->setVisible(false);
            ship_hit->sink();
            //return 3;
            sunk++;
            return 100 + int(ship_hit->getType());
        }
        hits++;
        return 2;
    } else {
        QGraphicsPixmapItem * new_cross = scene.addPixmap(QPixmap(":/images/ship_images/red_cross.png"));
        new_cross->setOffset(col*16, row*16);
        grid.crosses.append( new_cross );
        misses++;
        return 1;
    }
} // 0 invalid hit 1 miss 2 hit 3 sunk


Ship* Player::findShipByPos(int row, int col) {
    for ( int i = 0 ; i < 5 ; i++ ) {
        QList<QPoint> occupied_cells = ships[i]->getOccupiedCells();
        for ( QList<QPoint>::iterator it = occupied_cells.begin() ; it != occupied_cells.end() ; it++ ) {
            if ( it->x() == row && it->y() == col ) {
                return ships[i];
            }
        }
    }
    return nullptr;
}

bool Player::checkShipAlive( Ship* ship ) {
    QList<QPoint> occupied_cells = ship->getOccupiedCells();
    for ( QList<QPoint>::iterator it = occupied_cells.begin() ; it != occupied_cells.end() ; it++ ) {
        if ( !grid.isHit(it->x(), it->y())) {
            return true;
        }
    }
    return false;
}

bool Player::hasShipsLeft() {
    for ( int i = 0 ; i < 5 ; i++ ) {
        if ( ships[i]->is_alive()) {
            return true;
        }
    }
    return false;
}

QList<QString> Player::getStats() const {
    QList<QString> stats;
    stats.append(QString(hits));
    stats.append(QString(misses));
    stats.append(QString(sunk));
    return stats;
}
