#include "ship.h"

//Constructor
Ship::Ship( ShipType ship_type , Orientation orientation , int row , int col , QGraphicsScene& scene , bool is_human) : ship_type(ship_type), orientation(orientation) , row(row) , col(col ){
    alive = true;
    switch( ship_type ) {
        case Ship::ShipType::CV : length = 5 ; break;
        case Ship::ShipType::BB : length = 4 ; break;
        case Ship::ShipType::CA : length = 3 ; break;
        case Ship::ShipType::SS : length = 3 ; break;
        case Ship::ShipType::DD : length = 2 ; break;
    }

    int rotation = 90*int(orientation);
    //qDebug() << "rotation" << rotation;
    int row_delta = 0;
    int col_delta = 0;
    switch (int(orientation)) {
        case 0 : row_delta = -1 ; break;
        case 1 : col_delta = 1  ; break;
        case 2 : row_delta = 1  ; break;
        case 3 : col_delta = -1 ; break;
    }
    QString filename_stern = is_human ? ":/images/ship_images/ship_stern_green.png" : ":/images/ship_images/ship_stern_red.png";
    QString filename_mid = is_human ? ":/images/ship_images/ship_mid_green.png" : ":/images/ship_images/ship_mid_red.png";
    QString filename_bow = is_human ? ":/images/ship_images/ship_bow_green.png" : ":/images/ship_images/ship_bow_red.png";

    QGraphicsPixmapItem * ship_stern = scene.addPixmap(QPixmap( filename_stern ));

    ship_stern->setOffset(col*16,row*16);
    ship_stern->setTransformOriginPoint(col*16+8,row*16+8);
    ship_stern->setRotation(rotation);
    graphic_items.append( ship_stern );
    occupied_cells.append( QPoint( row , col) );
    //qDebug() << "stern";


    int i = 1;
    for ( ; i < length - 1 ; i++ ) {
        if ( ( col + col_delta * i ) < 0 || ( row + row_delta * i) < 0 || ( col + col_delta * i ) > 9 || ( row + row_delta * i) > 9 ) {
            return;
        }
        QGraphicsPixmapItem * ship_mid = scene.addPixmap(QPixmap( filename_mid ));

        ship_mid->setOffset( ( col + col_delta * i ) *16, ( row + row_delta * i) *16);
        ship_mid->setTransformOriginPoint( ( col + col_delta * i ) * 16 + 8 , ( row + row_delta * i) * 16 + 8 );
        ship_mid->setRotation(rotation);
        graphic_items.append( ship_mid );
        occupied_cells.append( QPoint( ( row + row_delta * i) , ( col + col_delta * i )) );
        //qDebug() << "mid";
    }

    if ( ( col + col_delta * i ) < 0 || ( row + row_delta * i) < 0 || ( col + col_delta * i ) > 9 || ( row + row_delta * i) > 9 ) {
        return;
    }
    QGraphicsPixmapItem * ship_bow = scene.addPixmap(QPixmap( filename_bow ));

    ship_bow->setOffset( ( col + col_delta * i ) *16, ( row + row_delta * i) *16);
    ship_bow->setTransformOriginPoint( ( col + col_delta * i ) * 16 + 8 , ( row + row_delta * i) * 16 + 8 );
    ship_bow->setRotation(rotation);
    graphic_items.append( ship_bow );
    occupied_cells.append( QPoint( ( row + row_delta * i) , ( col + col_delta * i )) );
   // qDebug() << "bow";

}

//Destructor
Ship::~Ship() {
    for ( QList<QGraphicsPixmapItem*>::iterator it = graphic_items.begin() ; it != graphic_items.end() ; it++ ) {
        delete *it;
    }
    graphic_items.clear();
};

//Accessors
Ship::ShipType Ship::getType() {
    return ship_type;
}
Ship::Orientation Ship::getOrientation() {
    return orientation;
}
int Ship::getRow() {
    return row;
}
int Ship::getCol() {
    return col;
}
bool Ship::is_alive() {
    return alive;
}
void Ship::sink() {
    alive = false;
    setVisible(true);
}
QList<QPoint> Ship::getOccupiedCells() {
    return occupied_cells;
}
QList<QGraphicsPixmapItem*> Ship::getGraphicItems() {
    return graphic_items;
}
void Ship::setVisible(bool visibility) {
    for ( QList<QGraphicsPixmapItem*>::iterator it = graphic_items.begin() ; it != graphic_items.end() ; it++ ) {
        (*it)->setVisible(visibility);
    }
}
