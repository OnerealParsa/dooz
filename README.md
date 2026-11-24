# Dooz — Tic-Tac-Toe (C++)

A two-player console tic-tac-toe game ("Dooz" is the Persian name for the game), implemented as a small object-oriented exercise with separated game logic, board state and rendering.

## Classes

| Class | Responsibility |
|---|---|
| `Dooz` | Game loop and turn management (`play()`) |
| `Board` | 3×3 board state, move validation, win/draw detection |
| `Player` | Player identity and symbol (X / O) |

## Build & Run

```bash
g++ -std=c++17 -O2 -o dooz main.cpp Dooz.cpp Board.cpp Player.cpp
./dooz
```
