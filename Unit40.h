//---------------------------------------------------------------------------

#ifndef Unit40H
#define Unit40H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm40 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TGroupBox *GroupBox2;
        TEdit *Edit1;
        TEdit *Edit2;
        TComboBox *CB1;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm40(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm40 *Form40;
//---------------------------------------------------------------------------
#endif
