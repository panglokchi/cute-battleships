#ifndef SHIP_H
#define SHIP_H

#include<QGraphicsPixmapItem>
#include<QGraphicsScene>
class Ship
{

    public:
        enum ShipType { CV , BB , CA , SS , DD }; // Carrier (5*1) , Battleship (4*1) , Cruiser (3*1) , Submarine (3*1) , Destroyer (2*1)
        enum Orientation { N , E , S , W }; // North, East, South, West
        //Constructor
        Ship( ShipType ship_type , Orientation orientation , int row , int col , QGraphicsScene& scene , bool is_human);
        //Destructor
        ~Ship();
        //Accessors
        ShipType getType();
        Orientation getOrientation();
        int getRow();
        int getCol();
        int getLength();
        bool is_alive();
        void sink();
        QList<QPoint> getOccupiedCells();
        QList<QGraphicsPixmapItem*> getGraphicItems();
        void setVisible(bool visibility);
    private:
        ShipType ship_type;
        Orientation orientation;
        int length;
        int row;
        int col;
        bool alive;
        QList<QGraphicsPixmapItem*> graphic_items;
        QList<QPoint> occupied_cells;

};

#endif // SHIP_H
