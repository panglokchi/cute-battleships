#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "player.h"
#include "humanplayer.h"

class AIPlayer : public Player
{
private:
    HumanPlayer * human_player;
    QList<QPoint> squares_of_interest;
public:
    AIPlayer(HumanPlayer* player);
    void aiHit(QGraphicsScene& scene);
};

#endif // AIPLAYER_H
