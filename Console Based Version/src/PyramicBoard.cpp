// File name: PyramicBoard 
// Author(s): Ziad Ismael
// ID(s): 20220143
// Section: S18

#include"BoardGame_Classes.hpp"
#include <iostream>
#include <string>
#include <random>
#include <iomanip>
#include <algorithm>

PyramicBoard::PyramicBoard()
{
    n_rows = 3;
    board = new char* [n_rows];
    for (int i = 0; i < n_rows; ++i) {
        for (int k = 0; k < 2 * i + 1; ++k) {
            board[i] = new char[k];
        }
    }
    for (int i = 0; i < n_rows; ++i) {
        for (int k = 0; k < 2 * i + 1; ++k) {
            board[i][k] = 0;
        }
    }
}

void PyramicBoard::display_board()
{
    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_rows - i - 1; ++j) {
            cout << "            ";
        }

        for (int k = 0; k < 2 * i + 1; ++k) {
            cout << "|  (" << i << "," << k << ")";
            if (board[i][k] == 0) {
                cout << setw(2) << " " << " |";
            }
            else {
                cout << setw(2) << board[i][k] << " |";
            }
        }

        cout << endl;
    }
    cout << endl;
}

bool PyramicBoard::update_board(int x, int y, char symbol)
{
    if (!(x < 0 || x > 5 || y < 0 || (x * 2) < y) && (board[x][y] == 0)) {
        board[x][y] = toupper(symbol);
        n_moves++;
        return true;
    }
    else
        return false;
}

bool PyramicBoard::is_winner()
{
    // Check first diagonal
    if (board[0][0] != 0) {
        if (board[0][0] == board[1][0] && board[1][0] == board[2][0]) {
            return true;
        }
    }

    // Check second diagonal
    if (board[0][0] != 0) {
        if (board[0][0] == board[1][2] && board[1][2] == board[2][4]) {
            return true;
        }
    }

    // Check mid column
    if (board[0][0] != 0) {
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
            return true;
        }
    }

    // Check mid row
    if ((board[1][0] && board[1][1] && board[1][2]) && (board[1][0] == board[1][1] && board[1][1] == board[1][2])) {
        return true;
    }

    // Check last row
    int ctr = 0;
    char temp = board[2][0];
    for (int j = 0; j < 3; j++) {
        if (board[2][j] != 0 && board[2][j] == temp) {
            ctr++;
        }
    }
    if (ctr == 3)
        return true;

    ctr = 0;
    temp = board[2][1];
    for (int j = 1; j < 4; j++) {
        if (board[2][j] != 0 && board[2][j] == temp) {
            ctr++;
        }
    }
    if (ctr == 3)
        return true;

    ctr = 0;
    temp = board[2][2];
    for (int j = 2; j < 5; j++) {
        if (board[2][j] != 0 && board[2][j] == temp) {
            ctr++;
        }
    }
    if (ctr == 3)
        return true;

    // No winning combination found
    return false;
}

bool PyramicBoard::is_draw() {
    return (n_moves == 9 && !is_winner());
}

bool PyramicBoard::game_is_over() {
    return n_moves >= 9;
}
