// X_O_5Board Class  Implementation
// Author:  Mohamed Mahmoud Khamis Rezk
// ID:		20221129
// Date:    11/12/2023
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "BoardGame_Classes.hpp"
using namespace std;

//set the board 5*5
X_O_5Board::X_O_5Board() {
    n_rows = n_cols = 5;
    board = new char* [n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool X_O_5Board::update_board(int x, int y, char mark) {
    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}


// Display the board and the pieces on it
void X_O_5Board::display_board() {
    for (int i : {0, 1, 2, 3, 4}) {
        cout << "\n| ";
        for (int j : {0, 1, 2, 3, 4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n--------------------------------------------";
    }
    cout << endl;
}

//Return true if the first player win
// false if the second player wind
//checking for draw by draw function

bool X_O_5Board::is_winner() {
    player1_points = 0, player2_points = 0;

    // Check rows, columns, and diagonals
    for (size_t i = 0; i < 5; ++i) {
        // Track consecutive symbols for each player
        int x_count = 0, o_count = 0;

        // Check row
        for (size_t j = 0; j < 5; ++j) {
            switch (board[i][j]) {
            case 'X': ++x_count; o_count = 0; break;
            case 'O': ++o_count; x_count = 0; break;
            default: x_count = 0; o_count = 0; break;
            }
            if (x_count >= 3) player1_points++;// counting symbols more than once
            if (o_count >= 3) player2_points++;// counting symbols more than once
        }

        // Reset counters for next check
        x_count = 0;
        o_count = 0;

        // Check column
        for (size_t j = 0; j < 5; ++j) {
            switch (board[j][i]) {
            case 'X': ++x_count; o_count = 0; break;
            case 'O': ++o_count; x_count = 0; break;
            default: x_count = 0; o_count = 0; break;
            }
            if (x_count >= 3) player1_points++;
            if (o_count >= 3) player2_points++;
        }
    }

    // Check diagonals
    int x_count = 0;
    int o_count = 0;
    int i{}, j{};

    for (int k = 0; k < 5; k++)
    {
        i = k;
        j = 0;
        while (i >= 0) {
            switch (board[i][j]) {
            case 'X': ++x_count; o_count = 0; break;
            case 'O': ++o_count; x_count = 0; break;
            default: x_count = 0; o_count = 0; break;
            }
            if (x_count >= 3) player1_points++;
            if (o_count >= 3) player2_points++;
            i--;
            j++;
        }
        x_count = 0;
        o_count = 0;

    }

    for (int k = 1; k < 5; k++)
    {
        i = 5 - 1;
        j = k;
        while (j <= 5 - 1) {
            switch (board[i][j]) {
            case 'X': ++x_count; o_count = 0; break;
            case 'O': ++o_count; x_count = 0; break;
            default: x_count = 0; o_count = 0; break;
            }
            if (x_count >= 3) player1_points++;
            if (o_count >= 3) player2_points++;
            i--;
            j++;
        }
        x_count = 0;
        o_count = 0;
    }


    for (int k = 0; k < 5 - 1; k++)
    {
        i = k;
        j = 4;
        while (i >= 0) {
            switch (board[i][j]) {
            case 'X': ++x_count; o_count = 0; break;
            case 'O': ++o_count; x_count = 0; break;
            default: x_count = 0; o_count = 0; break;
            }
            if (x_count >= 3) player1_points++;
            if (o_count >= 3) player2_points++;

            i--;
            j--;
        }
        x_count = 0;
        o_count = 0;
    }

    for (int k = 1; k < 5; k++)
    {
        i = 5 - 1;
        j = 5 - k;
        while (j >= 0) {
            switch (board[i][j]) {
            case 'X': ++x_count; o_count = 0; break;
            case 'O': ++o_count; x_count = 0; break;
            default: x_count = 0; o_count = 0; break;
            }
            if (x_count >= 3) player1_points++;
            if (o_count >= 3) player2_points++;
            i--;
            j--;
        }
        x_count = 0;
        o_count = 0;
    }



    cout << "player1 points " << player1_points << endl;
    cout << "player2 points " << player2_points << endl;

    if (player1_points > player2_points) {
        return true;
    }
    else if (player1_points < player2_points) {
        return false;
    }

    return false;
}


bool X_O_5Board::is_draw()
{
    if (player1_points == player2_points)
    {
        return true;
    }
    else
        return false;
}

bool X_O_5Board::game_is_over()
{
    return n_moves >= 24;
}

