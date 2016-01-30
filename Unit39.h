//---------------------------------------------------------------------------

#ifndef Unit39H
#define Unit39H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm39 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        void __fastcall Label1Click(TObject *Sender);
        void __fastcall Label1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
private:	// User declarations
public:		// User declarations
        __fastcall TForm39(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm39 *Form39;
//---------------------------------------------------------------------------
#endif
