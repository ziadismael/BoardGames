//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Menu.h"
#include "Original.h"
#include "Pyramic.h"
#include "FourinRow.h"
#include "FiveXFive.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMenuForm *MenuForm;
//---------------------------------------------------------------------------
__fastcall TMenuForm::TMenuForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMenuForm::Button1Click(TObject *Sender)
{
	TForm1* Form1 = new TForm1(this);
	Form1->ShowModal();
	Form1->reset_game();
	delete Form1;
}
//---------------------------------------------------------------------------
void __fastcall TMenuForm::Button2Click(TObject *Sender)
{
	TForm2* Form2 = new TForm2(this);
	Form2->ShowModal();
	Form2->reset_game();
	delete Form2;
}
//---------------------------------------------------------------------------

void __fastcall TMenuForm::Button3Click(TObject *Sender)
{
	TForm3* Form3 = new TForm3(this);
	Form3->ShowModal();
    Form3->reset_game();
	delete Form3;
}
//---------------------------------------------------------------------------

void __fastcall TMenuForm::Button4Click(TObject *Sender)
{
	TForm4* Form4 = new TForm4(this);
	Form4->ShowModal();
	Form4->reset_game();
	delete Form4;
}
//---------------------------------------------------------------------------

