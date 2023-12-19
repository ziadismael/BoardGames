//---------------------------------------------------------------------------

#ifndef FourinRowH
#define FourinRowH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TButton *Button10;
	TButton *Button11;
	TButton *Button12;
	TButton *Button13;
	TButton *Button14;
	TButton *Button15;
	TButton *Button16;
	TButton *Button17;
	TButton *Button18;
	TButton *Button19;
	TButton *Button20;
	TButton *Button21;
	TButton *Button22;
	TButton *Button23;
	TButton *Button24;
	TButton *Button25;
	TButton *Button26;
	TButton *Button27;
	TButton *Button28;
	TButton *Button29;
	TButton *Button30;
	TButton *Button31;
	TButton *Button32;
	TButton *Button33;
	TButton *Button34;
	TButton *Button35;
	TButton *Button36;
	TButton *Button37;
	TButton *Button38;
	TButton *Button39;
	TButton *Button40;
	TButton *Button41;
	TButton *Button42;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	void __fastcall ButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
	bool is_winner();
	bool is_draw();
	bool is_game_over();
	void playMove();
	void randMove(int& y);
	void reset_game();
	TButton* buttons[6][7] = { {Button1, Button2, Button3, Button4, Button5, Button6, Button7},
							   {Button8, Button9, Button10, Button11, Button12, Button13, Button14},
							   {Button15, Button16, Button17, Button18, Button19,Button20, Button21},
							   {Button22, Button23, Button24, Button25, Button26, Button27, Button28},
							   {Button29, Button30, Button31, Button32, Button33 ,Button34, Button35},
							   {Button36, Button37, Button38, Button39, Button40, Button41, Button42}
							 };
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
