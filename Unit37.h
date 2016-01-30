//---------------------------------------------------------------------------

#ifndef Unit37H
#define Unit37H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm37 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *Edit1;
        TButton *Button1;
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm37(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm37 *Form37;
//---------------------------------------------------------------------------
#endif
