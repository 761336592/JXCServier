//---------------------------------------------------------------------------

#ifndef Unit6H
#define Unit6H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
        TCheckBox *CheckCKbar;
        TEdit *Check_CK_bar;
        TCheckBox *CheckCKck;
        TEdit *Check_CK_ck;
        TCheckBox *CheckCKdj;
        TEdit *Check_CK_dj;
        TCheckBox *CheckCKbh;
        TEdit *Check_CK_bh;
        TDateTimePicker *Check_CK_date2;
        TLabel *Label1;
        TDateTimePicker *Check_CK_date1;
        TCheckBox *CheckCKdate;
        TEdit *Check_CK_nm;
        TCheckBox *CheckCKnm;
        TDBGrid *DBGrid1;
        TDataSource *DataSource1;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn4;
        TBitBtn *BitBtn5;
        TStatusBar *StatusBar1;
        TComboBox *ComboBox1;
        TBitBtn *BitBtn6;
        TButton *Button1;
        TButton *Button2;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall BitBtn4Click(TObject *Sender);
        void __fastcall DBGrid1TitleClick(TColumn *Column);
        void __fastcall BitBtn5Click(TObject *Sender);
        void __fastcall DBGrid1CellClick(TColumn *Column);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall BitBtn6Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm6(TComponent* Owner);

        String CKnote;
        String CKinfm;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
