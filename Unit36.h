//---------------------------------------------------------------------------

#ifndef Unit36H
#define Unit36H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm36 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *Edit1;
        TEdit *Edit2;
        TLabel *Label3;
        TButton *Button1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Edit1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Edit2KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TForm36(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm36 *Form36;
//---------------------------------------------------------------------------
#endif
