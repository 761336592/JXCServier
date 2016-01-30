//---------------------------------------------------------------------------

#ifndef Unit8H
#define Unit8H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm8 : public TForm
{
__published:	// IDE-managed Components
        TStringGrid *sgPurDetail;
        TLabel *Label1;
        TEdit *YK_yck;
        TLabel *Label2;
        TEdit *YK_mck;
        TCheckBox *CheckBox1;
        TLabel *Label4;
        TButton *Button1;
        TLabel *Label5;
        TEdit *YK_dh;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TButton *Button2;
        void __fastcall FormShow(TObject *Sender);
        void __fastcall sgPurDetailKeyPress(TObject *Sender, char &Key);
        void __fastcall sgPurDetailSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall sgPurDetailClick(TObject *Sender);
        void __fastcall sgPurDetailDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall YK_dhKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall YK_mckKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall YK_yckKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TForm8(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif
