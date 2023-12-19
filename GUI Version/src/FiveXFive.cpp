//------------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FiveXFive.h"
//------------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//------------------------------------------------------------------------------
int num_moves = 0;
int button_row = 0;
int button_col = 0;
char current_symbol = 'X';
int player1_points = 0;
int player2_points = 0;
bool isPlayer1 = true;
String player1 = "Khamis";
String player2 = "Hassan the Computer";
//------------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{

	Label2->Caption = player1;
}
//------------------------------------------------------------------------------
bool TForm4::is_draw()
{
	if(player1_points == player2_points)
	{
		return true;
	}

	return false;
}
//------------------------------------------------------------------------------
bool TForm4::is_game_over()
{
	if(num_moves >= 24)
	{
		return true;
	}

	return false;
}
//------------------------------------------------------------------------------
bool TForm4::is_winner()
{
	TButton* iterButton;
	player1_points = 0, player2_points = 0;

	for (int i = 0; i < 5; i++) {

		int x_count = 0, o_count = 0;

		for (int j = 0; j < 5; j++) {
			iterButton = TForm4::buttons[i][j];

			if(iterButton->Caption == 'X')
			{
				x_count++;
				o_count = 0;
			}
			else if(iterButton->Caption == 'O')
			{
				x_count = 0;
				o_count++;
			}
			else{
				x_count = 0;
				o_count = 0;
			}

			if (x_count >= 3) player1_points++;// counting symbols more than once
			if (o_count >= 3) player2_points++;// counting symbols more than once


		}
		x_count = 0;
		o_count = 0;

		for (int j = 0; j < 5; j++) {
			iterButton = TForm4::buttons[j][i];

			if(iterButton->Caption == 'X')
			{
				x_count++;
				o_count = 0;
			}
			else if(iterButton->Caption == 'O')
			{
				x_count = 0;
				o_count++;
			}
			else{
				x_count = 0;
				o_count = 0;
			}

			if (x_count >= 3) player1_points++;// counting symbols more than once
			if (o_count >= 3) player2_points++;// counting symbols more than once

		}
	}

	// Checking diagonals
	int x_count = 0;
	int o_count = 0;
    int i{}, j{};

    for (int k = 0; k < 5; k++)
    {
        i = k;
        j = 0;
		while (i >= 0) {
			iterButton = TForm4::buttons[i][j];

			if(iterButton->Caption == 'X')
			{
				x_count++;
				o_count = 0;
			}
			else if(iterButton->Caption == 'O')
			{
				x_count = 0;
				o_count++;
			}
			else{
				x_count = 0;
				o_count = 0;
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
           iterButton = TForm4::buttons[i][j];

			if(iterButton->Caption == 'X')
			{
				x_count++;
				o_count = 0;
			}
			else if(iterButton->Caption == 'O')
			{
				x_count = 0;
				o_count++;
			}
			else{
				x_count = 0;
				o_count = 0;
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
            iterButton = TForm4::buttons[i][j];

			if(iterButton->Caption == 'X')
			{
				x_count++;
				o_count = 0;
			}
			else if(iterButton->Caption == 'O')
			{
				x_count = 0;
				o_count++;
			}
			else{
				x_count = 0;
				o_count = 0;
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
            iterButton = TForm4::buttons[i][j];

			if(iterButton->Caption == 'X')
			{
				x_count++;
				o_count = 0;
			}
			else if(iterButton->Caption == 'O')
			{
				x_count = 0;
				o_count++;
			}
			else{
				x_count = 0;
				o_count = 0;
			}

            if (x_count >= 3) player1_points++;
            if (o_count >= 3) player2_points++;
            i--;
            j--;
        }
        x_count = 0;
        o_count = 0;
	}

	if(player1_points > player2_points)
		return true;

	//No Conditions Met
	return false;
}
//------------------------------------------------------------------------------
void __fastcall TForm4::ButtonClick(TObject *Sender)
{
	if(is_game_over()){
		Label3->Caption = "Game Over...";
	}

	else{
		TButton* clickedButton = dynamic_cast<TButton*> (Sender);

		if(clickedButton->Caption == ""){

			clickedButton->Caption = current_symbol;
			playMove();
			randMove(button_row, button_col);
		}
	}
}
//------------------------------------------------------------------------------
void TForm4::randMove(int& button_row, int& button_col)
{
	if(is_game_over())
	{
	   return;
	}

	int num_rows = 5;
	int num_cols = 5;
	button_row = rand() % (num_rows);
	button_col = rand() % (num_cols);

	while (true)
	{
		button_row = rand() % (num_rows);
		button_col = rand() % (num_cols);

		TButton* buttonIndex = TForm4::buttons[button_row][button_col];

		if(buttonIndex->Caption == "")
		{
			buttonIndex->Caption = current_symbol;
			playMove();
			return;
		}
	}
}
//------------------------------------------------------------------------------
void TForm4::playMove()
{
	if(current_symbol == 'X')
		current_symbol = 'O';
	else
		current_symbol = 'X';

	num_moves++;
	if(is_game_over())
	{
		if(is_winner())
		{
			Label5->Caption = player1 + " won!";
		}
		else if(is_draw())
		{
			Label5->Caption = "Draw...";
		}
		else
		{
			Label5->Caption = player2 + " won!";
		}
			Label4->Caption = player1;
			Label6->Caption = player1_points;
			Label7->Caption = player2;
			Label8->Caption = player2_points;
	 }
	 else
	 {
		if(Label2->Caption == player2)
			Label2->Caption = player1;
		else
			Label2->Caption = player2;
	 }
}
//------------------------------------------------------------------------------
void TForm4::reset_game()
{
	num_moves = 0;
	if(current_symbol == 'O')
	{
		current_symbol = 'X';
	}
	TButton* iterButton;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			iterButton = buttons[i][j];
			iterButton->Caption = "";
		}
	}
}
