#include "Dooz.h"
#include <iostream>
using namespace std;

Dooz::Dooz(const std::string& p1Name, const std::string& p2Name)
    : player1(p1Name, 'X'), player2(p2Name, 'O'), currentPlayer(&player1) {}

void Dooz::play() {
    cout << "=== dooz ===\n";
    cout << "Player 1 (X): " << player1.getName() << endl;
    cout << "Player 2 (O): " << player2.getName() << endl;
    
    while (true) {
        board.drawBoard();
        
        cout << "\nTurn: " << currentPlayer->getName() << " (" << currentPlayer->getSymbol() << ")\n";
        
        int row, col;
        cout << "Enter row and column (1-3): ";
        cin >> row >> col;
        
        if (board.makeMove(row, col, currentPlayer->getSymbol())) {
            if (board.checkWin(currentPlayer->getSymbol())) {
                board.drawBoard();
                cout << "\n" << currentPlayer->getName() << " wins!\n";
                break;
            }
            
            if (board.isFull()) {
                board.drawBoard();
                cout << "\nIt's a draw!\n";
                break;
            }
            
            switchPlayer();
        } else {
            cout << "Invalid move! Try again.\n";
        }
    }
}

void Dooz::switchPlayer() {
    currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
}