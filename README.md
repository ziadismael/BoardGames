# Tic Tac Toe Board Games

This project is an implementation of Tic Tac Toe with multiple game modes, Original, Pyramic, 5x5 and Connect Four! 
It includes player vs player, player vs random computer player. Programmed with C++ from bottom to top!
there's a console-based program and a GUI version both built on C++.

## How to Build and Run
### Prerequisites

Make sure you have a C++ compiler installed on your system.

### Build

```bash
g++ -o BoardGames main.cpp BoardGame_Classes.hpp RandPlayerPyramic.cpp ... (all files) ...
```

### Run

```bash
./BoardGames
```

## Game Modes
### 3x3 X-O Game Mode
The standard Tic Tac Toe game mode where two players take turns making moves on a 3x3 grid.

### Pyramic X-O Game Mode
An extended version of Tic Tac Toe with a pyramic board. Players make moves on the pyramic grid, 
and the first player to form a winning pattern wins.

### 5x5 X-O Game Mode
A larger 5x5 grid version of Tic Tac Toe where two players compete to get a larger score,
players keep playing forming winning patterns untill the 24 cells are filled and the game is over.

### Connect 4
A classic Connect 4 game where two players take turns dropping their pieces in a vertical grid, and the first player to connect four pieces wins.

## Players
### Human Player
A player controlled by user input.

### Random Player
A computer player that makes random moves on the board.

## How to Play
1. Choose a game mode and the players (human, random, or AI). <br>
2. Follow the on-screen instructions to make moves. <br>
3. The game will declare a winner, a draw, or continue until the players decide to exit. <br>

Have fun playing Tic Tac Toe in various game modes!
