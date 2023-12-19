//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FourinRow.h"
//------------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//------------------------------------------------------------------------------
int num_moves = 0;
int button_row = 0;
int button_col = 0;
int num_cols = 7;
int num_rows = 6;
char current_symbol = 'X';
String player1 = "Ibrahim";
String player2 = "Bassyoni the Computer";
//------------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	Label2->Caption = player1;
}
//------------------------------------------------------------------------------
void __fastcall TForm3::ButtonClick(TObject *Sender)
{
	if(is_game_over())
	{
		Label3->Caption = "Game Over...";
		return;
	}

	else if(is_winner()){
		Label3->Caption = Label2->Caption + " won!";
		return;
	}

	else if(is_draw()){
		Label3->Caption = "Draw...";
		return;
	}

	
	else{
		TButton* clickedButton = dynamic_cast<TButton*> (Sender);
		TButton* iterButton = TForm3::buttons[0][0];
		for (int i = 0; i < 6; i++) {
			int l = 0;
			for (int j = 0; j < 7; j++) {
				iterButton = TForm3::buttons[i][j];
				if(iterButton == clickedButton)
				{
					button_col = l;
					break;
				}
				l++;
			}
		}

		button_row = 5;
		while(button_row>=0)
		{
			iterButton = TForm3::buttons[button_row][button_col];
			if(iterButton->Caption == "")
			{
				iterButton->Caption = current_symbol;
				playMove();
				randMove(button_col);
				return;
			}
			button_row--;
		}

	}
}
//------------------------------------------------------------------------------
bool TForm3::is_game_over()
{
	if (num_moves == 42) {
		return true;
	}
	return false;
}
//------------------------------------------------------------------------------
bool TForm3::is_draw()
{
	if (num_moves == 42	 && !is_winner()) {
		return true;
	}
	return false;
}
//------------------------------------------------------------------------------
bool TForm3::is_winner()
{
	TButton* iterButton;
	for (int i = 0; i < num_rows; i++) {
		for (int j = 0; j < num_cols; j++) {
			iterButton = buttons[i][j];
			if(iterButton->Caption != "")
			{
				String symbol = iterButton->Caption;

				// Checking Horizontally
				if (j + 3 < num_cols)
				{
					iterButton = buttons[i][j+1];
					if(iterButton->Caption == symbol)
					{
						iterButton = buttons[i][j+2];
						if(iterButton->Caption == symbol)
						{
							iterButton = buttons[i][j+3];
							if(iterButton->Caption == symbol)
							{
								return true;
							}
						}
					}
				}

				iterButton = buttons[i][j];

				// Checking Vertically
				if (i + 3 < num_rows)
				{
					iterButton = buttons[i+1][j];
					if(iterButton->Caption == symbol)
					{
						iterButton = buttons[i+2][j];
						if(iterButton->Caption == symbol)
						{
							iterButton = buttons[i+3][j];
							if(iterButton->Caption == symbol)
							{
								return true;
							}
						}
					}
				}

				iterButton = buttons[i][j];

				// Checking Diagonally (bottom left to top right)
				if (i - 3 >= num_rows && j + 3 < num_cols)
				{
					iterButton = buttons[i-1][j+1];
					if(iterButton->Caption == symbol)
					{
						iterButton = buttons[i-2][j+2];
						if(iterButton->Caption == symbol)
						{
							iterButton = buttons[i-3][j+3];
							if(iterButton->Caption == symbol)
							{
								return true;
							}
						}
					}
				}

				iterButton = buttons[i][j];

				// Checking Diagonally (bottom right to top left)
				if (i + 3 < num_rows && j + 3 < num_cols)
				{
					iterButton = buttons[i+1][j+1];
					if(iterButton->Caption == symbol)
					{
						iterButton = buttons[i+2][j+2];
						if(iterButton->Caption == symbol)
						{
							iterButton = buttons[i+3][j+3];
							if(iterButton->Caption == symbol)
							{
								return true;
							}
						}
					}
				}

				iterButton = buttons[i][j];


			}
		}
	}

	// No winning conditions met
	return false;
}
//------------------------------------------------------------------------------
void TForm3::playMove()
{
	if(current_symbol == 'X')
		current_symbol = 'O';
	else
		current_symbol = 'X';

	num_moves++;

	if(is_winner())
	{
		Label3->Caption = Label2->Caption + " won!";
		return;
	}
	else if(is_draw())
	{
		Label3->Caption = "Draw...";
		return;
	}
	else{
		if(Label2->Caption == player2)
			Label2->Caption = player1;
		else
			Label2->Caption = player2;

	}
}
//------------------------------------------------------------------------------
void TForm3::randMove(int& button_col)
{
	if(is_game_over())
	{
		return;
    }

	button_row = 5;
	button_col = rand() % (num_cols);

	while (true)
	{
		button_col = rand() % (num_cols);

		TButton* buttonIndex = TForm3::buttons[button_row][button_col];

		while (button_row >= 0)
		{
			buttonIndex = TForm3::buttons[button_row][button_col];
			button_row--;
			
			if(buttonIndex->Caption == "")
			{
				buttonIndex->Caption = current_symbol;
				playMove();
				return;
			}
			
		}
		buttonIndex = TForm3::buttons[button_row][button_col];

	}
}
//------------------------------------------------------------------------------
void TForm3::reset_game()
{
	num_moves = 0;
	if(current_symbol == 'O')
	{
		current_symbol = 'X';
	}
	TButton* iterButton;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			iterButton = buttons[i][j];
			iterButton->Caption = "";
		}
	}
}
