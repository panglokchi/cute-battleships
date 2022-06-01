#include "aiplayer.h"
#include <QRandomGenerator>
#include <QDateTime>
#include <cmath>
#include <qDebug>

AIPlayer::AIPlayer(HumanPlayer* human_player): Player( false ) , human_player(human_player)
{

}

void AIPlayer::aiHit(QGraphicsScene& scene) {
    QRandomGenerator generator(QDateTime::currentMSecsSinceEpoch());
    int row = 0 ;
    int col = 0 ;
    if ( squares_of_interest.empty() ) {
        do {
            row = generator.bounded(10);
            col = generator.bounded(10);
        } while ( human_player->getGrid().isHit( row , col ) );
    } else {
        QPoint to_hit = squares_of_interest.front();
        squares_of_interest.pop_front();
        row = to_hit.x();
        col = to_hit.y();
    }
    int result = human_player->hit( row , col , scene );
    if ( result == 0 ) {
        aiHit(scene);
    }
    if ( result == 2 ) {
        for ( int i = -1 ; i <= 1 ; i++ ) {
            for ( int j = -1 ; j <= 1 ; j++ ) {
                if ( (row+i) < 0 || (row+i) > 9 || (col+j) < 0 || (col+j) > 9 || abs(i)+abs(j) > 1 ) {
                    continue;
                }
                if ( !squares_of_interest.contains(QPoint(row+i,col+j)) && !human_player->getGrid().isHit( row+i, col+j) ) {
                    squares_of_interest.append(QPoint(row+i,col+j));
                    qDebug() << squares_of_interest;
                }
            }
        }
    }
    if ( result >= 100 ) {
        result -= 100;
        qDebug() << "sunk" << result;
        QList<QPoint> not_interested = human_player->getShip(Ship::ShipType(result))->getOccupiedCells();
        for ( QList<QPoint>::iterator it = not_interested.begin() ; it != not_interested.end() ; it++ ) {
            row = it->x();
            col = it->y();
            for ( int i = -1 ; i <= 1 ; i++ ) {
                for ( int j = -1 ; j <= 1 ; j++ ) {
                    if ( (row+i) < 0 || (row+i) > 9 || (col+j) < 0 || (col+j) > 9 || abs(i)+abs(j) > 1 ) {
                        continue;
                    }
                    if ( !squares_of_interest.contains(QPoint(row+i,col+j)) ) {
                        squares_of_interest.removeOne(QPoint(row+i,col+j));
                        qDebug() << squares_of_interest;
                    }
                }
            }
        }
        /*
        for ( int i = -1 ; i <= 1 ; i++ ) {
            for ( int j = -1 ; j <= 1 ; j++ ) {
                if ( (row+i) < 0 || (row+i) > 9 || (col+j) < 0 || (col+j) > 9 || abs(i)+abs(j) > 1 ) {
                    continue;
                }
                if ( !squares_of_interest.contains(QPoint(row+i,col+j)) && !human_player->getGrid().isHit( row+i, col+j) ) {
                    squares_of_interest.removeOne(QPoint(row+i,col+j));
                    qDebug() << squares_of_interest;
                }
            }
        }*/
    }
}
