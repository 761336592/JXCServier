//---------------------------------------------------------------------------

#ifndef Unit11H
#define Unit11H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm11 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *Edit1;
        TStringGrid *sgPurDetail;
        TBitBtn *BitBtn2;
        TStatusBar *StatusBar1;
        TCheckBox *CheckBox1;
        TLabel *Label2;
        TButton *Button1;
        TBitBtn *BitBtn1;
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
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TForm11(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm11 *Form11;
//---------------------------------------------------------------------------
#endif
 