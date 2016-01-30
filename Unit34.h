//---------------------------------------------------------------------------

#ifndef Unit34H
#define Unit34H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm34 : public TForm
{
__published:	// IDE-managed Components
        TDataSource *DataSource1;
        TDBGrid *DBGrid1;
        TCheckBox *CheckPDbar;
        TEdit *Check_PD_bar;
        TCheckBox *CheckPDck;
        TEdit *Check_PD_ck;
        TCheckBox *CheckPDdj;
        TEdit *Check_PD_dj;
        TCheckBox *CheckPDbh;
        TEdit *Check_PD_bh;
        TCheckBox *CheckPDnm;
        TEdit *Check_PD_nm;
        TCheckBox *CheckPDdate;
        TDateTimePicker *Check_PD_date1;
        TLabel *Label1;
        TDateTimePicker *Check_PD_date2;
        TButton *Button1;
        TComboBox *ComboBox1;
        TStatusBar *StatusBar1;
        TButton *Button2;
        TButton *Button3;
        TBitBtn *BitBtn1;
        TButton *Button4;
        TButton *Button5;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall DBGrid1CellClick(TColumn *Column);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall DBGrid1TitleClick(TColumn *Column);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm34(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm34 *Form34;
//---------------------------------------------------------------------------
#endif
