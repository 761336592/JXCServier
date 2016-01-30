//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
        TDataSource *DataSource1;
        TDBGrid *DBGrid1;
        TCheckBox *CheckRKbar;
        TEdit *Check_RK_bar;
        TCheckBox *CheckRKck;
        TEdit *Check_RK_ck;
        TCheckBox *CheckRKdj;
        TEdit *Check_RK_dj;
        TCheckBox *CheckRKbh;
        TEdit *Check_RK_bh;
        TCheckBox *CheckRKnm;
        TEdit *Check_RK_nm;
        TCheckBox *CheckRKdate;
        TDateTimePicker *Check_RK_date1;
        TDateTimePicker *Check_RK_date2;
        TLabel *Label1;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn4;
        TStatusBar *StatusBar1;
        TComboBox *ComboBox1;
        TBitBtn *BitBtn5;
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
        void __fastcall DBGrid1CellClick(TColumn *Column);
        void __fastcall BitBtn5Click(TObject *Sender);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall BitBtn6Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
