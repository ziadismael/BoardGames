//------------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Original.h"
#include <random>
#include <iomanip>
#include <string>
#include <algorithm>
//------------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//------------------------------------------------------------------------------
int num_moves = 0;
int buttonX = 0;
char current_symbol = 'X';
String player1 = "Ziad";
String player2 = "Hossam the Computer";
//------------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Label2->Caption = player1;
}
//------------------------------------------------------------------------------
void __fastcall TForm1::ButtonClick(TObject *Sender)
{
	if(is_game_over()){
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

		if(clickedButton->Caption == ""){

			clickedButton->Caption = current_symbol;
			playMove();
			randMove(buttonX);
		}
	}
}
//------------------------------------------------------------------------------
bool TForm1::is_winner()
{
	//First Diagonal Win
	if(Button1->Caption !=""){
		if(Button1->Caption == Button5->Caption && Button5->Caption == Button9->Caption){
			return true;
		}
	}

	// Second Diagonal Win
	if(Button3->Caption !=""){
		if(Button3->Caption == Button5->Caption && Button5->Caption == Button7->Caption){
			return true;
		}
	}

	// Rows win : First Row
	if(Button1->Caption !=""){
		if(Button1->Caption == Button2->Caption && Button2->Caption == Button3->Caption){
			return true;
		}
	}

	// Mid Row
	if(Button4->Caption !=""){
		if(Button4->Caption == Button5->Caption && Button5->Caption == Button6->Caption){
			return true;
		}
	}

	// Last Row
	if(Button7->Caption !=""){
		if(Button7->Caption == Button8->Caption && Button8->Caption == Button9->Caption){
			return true;
		}
	}

	// Column Wins : First Column
	if(Button1->Caption !=""){
		if(Button1->Caption == Button4->Caption && Button4->Caption == Button7->Caption){
			return true;
		}
	}

	// Mid Row
	if(Button2->Caption !=""){
		if(Button2->Caption == Button5->Caption && Button5->Caption == Button8->Caption){
			return true;
		}
	}

	// Last Row
	if(Button3->Caption !=""){
		if(Button3->Caption == Button6->Caption && Button6->Caption == Button9->Caption){
			return true;
		}
	}

	return false;
}
//------------------------------------------------------------------------------
bool TForm1::is_draw()
{
	if(num_moves >= 9 && !is_winner())
	{
		return true;
	}
	return false;
}
//------------------------------------------------------------------------------
bool TForm1::is_game_over()
{
	if(num_moves == 9)
	{
		return true;
	}
	return false;
}
//------------------------------------------------------------------------------
void TForm1::randMove(int& buttonX)
{
	if(is_game_over())
	{
	   return;
	}
	else if(is_winner())
	{
		return;
	}

	int num_buttons = 9;
	buttonX = rand() % (num_buttons);
	srand(static_cast<unsigned int>(time(0)));
	while (true)
	{
		buttonX = rand() % (num_buttons);   // 9->number of buttons
		switch(buttonX)
		{
		case 1:
			if(Button1->Caption == ""){
				Button1->Caption = current_symbol;
				playMove();
				return;
			}
			break;

		case 2:
			if(Button2->Caption == ""){
				Button2->Caption = current_symbol;
				playMove();
				return;
			}
			break;

		case 3:
			if(Button3->Caption == ""){
				Button3->Caption = current_symbol;
				playMove();
				return;
			}
			break;

		case 4:
			if(Button4->Caption == ""){
				Button4->Caption = current_symbol;
				playMove();
				return;
			}
			break;

		case 5:
			if(Button5->Caption == ""){
				Button5->Caption = current_symbol;
				playMove();
				return;
			}
			break;

		case 6:
			if(Button6->Caption == ""){
				Button6->Caption = current_symbol;
				playMove();
				return;
			}
			break;

		case 7:
			if(Button7->Caption == ""){
				Button7->Caption = current_symbol;
				playMove();
				return;
			}
			break;

		case 8:
			if(Button4->Caption == ""){
				Button4->Caption = current_symbol;
				playMove();
				return;
			}
			break;

		case 9:
			if(Button4->Caption == ""){
				Button4->Caption = current_symbol;
				playMove();
				return;
			}
			break;
		}
	}
}
//------------------------------------------------------------------------------
void TForm1::playMove()
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
void TForm1::reset_game()
{
	num_moves = 0;
	if(current_symbol == 'O')
		current_symbol = 'X';
	Button1->Caption = "";
	Button2->Caption = "";
	Button3->Caption = "";
	Button4->Caption = "";
	Button5->Caption = "";
	Button6->Caption = "";
	Button7->Caption = "";
	Button8->Caption = "";
	Button9->Caption = "";
	Label2->Caption = player1;
}