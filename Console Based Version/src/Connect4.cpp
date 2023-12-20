#include <iostream>
#include "../include/BoardGame_Classes.hpp"
using namespace std;
Connect4_Board::Connect4_Board()
{
    n_rows = 6;
    n_cols = 7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++) {
            board[i][j] = ' ';
        }
    }
}

bool Connect4_Board::update_board(int x ,int y, char mark)
{
  if( y >= 0 && y <= 6 ){
    while(board[x][y] != ' ' && x >= 0){
        x--;
        if(x==0){
            break;
        }
    }
    if(board[x][y] == ' '){
        board[x][y]= mark;
    return true;
    }
    else{
        return false;
    }
    
  }
  return false;
}
void Connect4_Board::display_board()
{
    for (int i=0;i<n_rows;i++){
        cout<<"| ";
        for (int j=0;j<n_cols;j++){
            cout <<board[i][j]<<" | ";
        }
         cout << "\n-----------------------------\n";
    }
     cout << "  0   1   2   3   4   5   6\n";
}

bool Connect4_Board::is_winner()
{
     for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < n_cols; ++j) {
            if (board[i][j] != ' ') {
                char symbol = board[i][j];

                // Check horizontally
                if (j + 3 < n_cols &&
                    board[i][j + 1] == symbol &&
                    board[i][j + 2] == symbol &&
                    board[i][j + 3] == symbol) {
                    return true;
                }

                // Check vertically
                if (i + 3 < n_rows &&
                    board[i + 1][j] == symbol &&
                    board[i + 2][j] == symbol &&
                    board[i + 3][j] == symbol) {
                    return true;
                }
                // Check diagonally (bottom-left to top-right)
                if (i - 3 >= 0 && j + 3 < n_cols &&
                    board[i - 1][j + 1] == symbol &&
                    board[i - 2][j + 2] == symbol &&
                    board[i - 3][j + 3] == symbol) {
                    return true;
                }

                // Check diagonally (top-left to bottom-right)
                if (i + 3 < n_rows && j + 3 < n_cols &&
                    board[i + 1][j + 1] == symbol &&
                    board[i + 2][j + 2] == symbol &&
                    board[i + 3][j + 3] == symbol) {
                    return true;
                }
            }
        }
    }
    
    return false;
}

bool Connect4_Board::is_draw()
{
    if (n_moves == 42 && is_winner() == false){
        return true;
    }
    return false;
}

bool Connect4_Board::game_is_over()
{
    
    return n_moves >= 42;
}
