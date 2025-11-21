#include "Board.h"
#include <iostream>
using namespace std;

Board::Board() : filledCells(0) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] = ' ';
        }
    }
}

void Board::drawBoard() const {
    cout << "\n   |   |   \n";
    for (int i = 0; i < 3; i++) {
        cout << " " << grid[i][0] << " | " << grid[i][1] << " | " << grid[i][2] << " \n";
        if (i < 2) {
            cout << "___|___|___\n";
        } else {
            cout << "   |   |   \n";
        }
    }
}

bool Board::isValidMove(int row, int col) const {
    return row >= 1 && row <= 3 && col >= 1 && col <= 3 && grid[row-1][col-1] == ' ';
}

bool Board::makeMove(int row, int col, char symbol) {
    if (isValidMove(row, col)) {
        grid[row-1][col-1] = symbol;
        filledCells++;
        return true;
    }
    return false;
}

bool Board::checkWin(char symbol) const {
    for (int i = 0; i < 3; i++) {
        if ((grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) ||
            (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol)) {
            return true;
        }
    }
    
    if ((grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) ||
        (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol)) {
        return true;
    }
    
    return false;
}

bool Board::isFull() const {
    return filledCells == 9;
}