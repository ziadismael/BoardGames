// GameManager5x5 Class Implementation
// Author:  Mohamed Mahmoud Khamis Rezk
// ID:		20221129
// Date:    15/12/2023
#include <iostream>
#include <string>
#include "BoardGame_Classes.hpp"
using namespace std;


GameManager5x5::GameManager5x5(Board* bPtr, Player* playerPtr[2]) : GameManager(bPtr, playerPtr) {}


void GameManager5x5::runThirdGame() // Mohamed Khamis
{
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i : {0, 1}) {
            players[i]->get_move(x, y);
            while (!boardPtr->update_board(x, y, players[i]->get_symbol())) {
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
        }
    }
    if (boardPtr->is_winner()) {
        cout << players[0]->to_string() << " wins\n";
    }
    else if (boardPtr->is_draw())
    {
        cout << "No Winner Draw" << endl;
    }
    else
        cout << players[1]->to_string() << " wins\n";
}

