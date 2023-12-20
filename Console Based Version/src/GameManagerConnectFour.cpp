// Class Implementaion for GameMangerConnectFour
// Author:  Ibrahem Medhat Mahmoud
// ID:		20221003
// Date:    16/12/2023

#include "../include/BoardGame_Classes.hpp"
#include <iostream>
using namespace std;

GameManagerConnectFour::GameManagerConnectFour(Board* bPtr, Player* playerPtr[2]) : GameManager(bPtr, playerPtr) {}


void GameManagerConnectFour::runConnect4() {
    int y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i : {0, 1}) {
            players[i]->get_move(y);
            while (!boardPtr->update_board(5, y, players[i]->get_symbol())) {
                players[i]->get_move(y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()) {
                cout << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()) {
                cout << "Draw!\n";
                return;
            }
        }
    }
}
