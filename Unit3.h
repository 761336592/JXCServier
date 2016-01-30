//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <DBGrids.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TEdit *RK_dj;
        TEdit *RK_ck;
        TStringGrid *sgPurDetail;
        TCheckBox *CheckBox1;
        TLabel *Label4;
        TButton *Button1;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TRadioButton *RadioButton3;
        TRadioButton *RadioButton4;
        TButton *Button2;
        void __fastcall sgPurDetailKeyPress(TObject *Sender, char &Key);
        void __fastcall sgPurDetailSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall sgPurDetailClick(TObject *Sender);
        void __fastcall sgPurDetailDrawCell(TObject *Sender, int ACol,
          int ARow, TRect &Rect, TGridDrawState State);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall RK_djKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall RK_ckKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
