//Main Cpp file for running all the three games together
// Author:  Ziad Ismael
// ID:		20220143
// Date:    16/12/2023
#include <iostream>
#include "../include/BoardGame_Classes.hpp"
using namespace std;

int main() {
    int player_choice, game_choice;
    string games[4] = { "1- Original 3x3 Tic Tac Toe",
                       "2- Pyramic Tic Tac Toe",
                       "3- 5X5 Tic Tac Toe",
                       "4- Four in a row Tic Tac Toe" };
    Player* players[2];
    players[0] = new Player(1, 'x');
    
    cout << endl << "Welcome to FCAI Tic Tac Toe Game. :)\n";
    cout << endl;

    for (int i = 0;i < 4;i++) {
        cout << games[i] << endl;
    }
    cout << "Chose what game do you want to play among these options: ";
    cin >> game_choice;
    
    
    cout << "Press 1 if you want to play with computer: ";
    cin >> player_choice;
    cout << endl;
    if (player_choice != 1)
        players[1] = new Player(2, 'o');
    else {
        switch (game_choice)
        {
        case 1:
            players[1] = new RandomPlayer('o', 3);
            break;
        case 2:
            players[1] = new RandPlayer('o', 5);
            break;
        case 3:
            players[1] = new RandomPlayer('o', 5);
            break;
        case 4:
            players[1] = new RandomPlayer('o', 7);
            break;
        default:
            cout << "Invalid input..." << endl;
            break;
        }
    }

    GameManager x_o_original(new X_O_Board, players);
    GameManager x_o_game_pyramic(new PyramicBoard(), players);
    GameManager5x5 x_o_game5x5(new X_O_5Board(), players);
    GameManagerConnectFour x_o_game_fourInrow(new Connect4_Board(), players);

    bool flag = true;
    while (flag) {
        switch (game_choice) {
        case 1:
            flag = false;
            x_o_original.run();
            break;
        case 2:
            flag = false;
            x_o_game_pyramic.run();
            break;
        case 3:
            flag = false;
            x_o_game5x5.runThirdGame();
            break;
        case 4:
            flag = false;
            x_o_game_fourInrow.runConnect4();
            break;
        default:
            cout << endl << "Please Enter a valid choice 1-4: ";
            cin >> game_choice;
        }
    }
    system("pause");

}