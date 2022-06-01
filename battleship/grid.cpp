#include "grid.h"

Grid::Grid()
{

}

bool Grid::isOccupied(int row, int col) {
    return occupied[row][col];
}

bool Grid::isHit(int row, int col) {
    return hit[row][col];
}

bool Grid::allSunk() {
    for (int i = 0 ; i < 10 ; i++) {
        for ( int j = 0 ; j < 10 ; j++) {
            if ( occupied[i][j] == true && hit[i][j] == false ) {
                return false;
            }
        }
    }
    return true;
}

bool Grid::addShip(Ship::ShipType ship_type, int stern_pos_row, int stern_pos_col, Ship::Orientation orientation) {
    //int ship_length = int(ship_type);
    int ship_length;
    switch (ship_type) {
        case Ship::ShipType::CV : ship_length = 5 ; break;
        case Ship::ShipType::BB : ship_length = 4 ; break;
        case Ship::ShipType::CA : ship_length = 3 ; break;
        case Ship::ShipType::SS : ship_length = 3 ; break;
        case Ship::ShipType::DD : ship_length = 2 ; break;
    }
    //int rotation = 90*int(orientation);
    int row_delta = 0;
    int col_delta = 0;
    switch (int(orientation)) {
        case 0 : row_delta = -1 ; break;
        case 1 : col_delta = 1  ; break;
        case 2 : row_delta = 1  ; break;
        case 3 : col_delta = -1 ; break;
    }
    for ( int i = 0 ; i < ship_length ; i++ ) {
        if ( ( stern_pos_col + col_delta * i ) < 0 || ( stern_pos_row + row_delta * i) < 0 || ( stern_pos_col + col_delta * i ) > 9 || ( stern_pos_row + row_delta * i) > 9 ) {
            return false;
        }
        if ( occupied[( stern_pos_row + row_delta * i)][( stern_pos_col + col_delta * i )] == true ) {
            return false;
        }
    }

    for ( int i = 0 ; i < ship_length ; i++ ) {
        occupied[( stern_pos_row + row_delta * i)][( stern_pos_col + col_delta * i )] = true;
    }
    return true;
}

void Grid::reset() {
    for ( int i = 0 ; i < 10 ; i++ ) {
        for ( int j = 0 ; j < 10 ; j++ ) {
            occupied[i][j] = false;
            hit[i][j] = false;
        }
    }
}

void Grid::hitCell(int row, int col) {
    hit[row][col] = true;
}
