#include "Dooz.h"
#include <iostream>
using namespace std;

int main() {
    string p1Name, p2Name;
    
    cout << "Enter Player 1 name (X): ";
    cin >> p1Name;
    cout << "Enter Player 2 name (O): ";
    cin >> p2Name;
    
    Dooz game(p1Name, p2Name);
    game.play();
    
    return 0;
}