#ifndef DOOZ_H
#define DOOZ_H

#include "Player.h"
#include "Board.h"

class Dooz {
private:
    Player player1;
    Player player2;
    Board board;
    Player* currentPlayer;

public:
    Dooz(const std::string& p1Name, const std::string& p2Name);
    void play();
    void switchPlayer();
};

#endif