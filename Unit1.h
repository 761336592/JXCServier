//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Buttons.hpp>
#include <ADODB.hpp>
#include <ComCtrls.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *Image1;
        TBevel *Bevel1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TEdit *name;
        TEdit *password;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TADOConnection *ADOConnection1;
        TADOCommand *ADOCommand1;
        TADOQuery *Search_ADOQuery;
        TADOQuery *RK_ADOQuery;
        TADOTable *RK_ADOTable;
        TADOQuery *KC_ADOQuery;
        TADOTable *KC_ADOTable;
        TADOQuery *CK_ADOQuery;
        TADOTable *CK_ADOTable;
        TADOTable *PD_ADOTable;
        TADOQuery *PD_ADOQuery;
        TADOTable *YG_ADOTable;
        TADOQuery *YG_ADOQuery;
        TADOTable *YK_ADOTable;
        TADOQuery *YK_ADOQuery;
        TADOTable *YD_ADOTable;
        TADOQuery *YD_ADOQuery;
        TADOTable *ADOTable1;
        TADOQuery *ADOQuery1;
        TADOConnection *con1;
        TADOQuery *qry1;
        TADOQuery *Print_ADOQuery;
        TStatusBar *StatusBar1;
        TADOTable *XSTJ_ADOTable;
        TADOQuery *XSTJ_ADOQuery;
        TPanel *Panel1;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TLabel *Label9;
        TLabel *Label10;
        TButton *Button1;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label4;
        TEdit *Edit1;
        TADOTable *ZC_ADOTable;
        TPanel *Panel2;
        TLabel *Label15;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TButton *Button2;
        TADOQuery *XSXQ_ADOQuery;
        TADOTable *PDTJ_ADOTable;
        TADOQuery *PDTJ_ADOQuery;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall nameKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall passwordKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        String LoginName;
        String infshow1;
        String infshow2;
        String infshow3;
        String infshow4;
        String infshow5;
        String infshow6;
        String infshow7;
        String infshow8;
        String infshow9;
        String infshow10;
        String infshow11;

        String rksendback1;
        String rksendback2;
        String rksendback3;
        String rksendback4;
        String rksendback5;

        String cksendback1;
        String cksendback2;
        String cksendback3;
        String cksendback4;
        String cksendback5;

        String pdsendback1;
        String pdsendback2;
        String pdsendback3;
        String pdsendback4;
        String pdsendback5;

        String ydsendback1;
        String ydsendback2;
        String ydsendback3;
        String ydsendback4;
        String ydsendback5;

        String yksendback1;
        String yksendback2;
        String yksendback3;
        String yksendback4;
        String yksendback5;

        String rksendstring1;
        String rksendstring2;
        String rksendstring3;
        String rksendstring4;
        String rksendstring5;

        String pdsendstring1;
        String pdsendstring2;
        String pdsendstring3;
        String pdsendstring4;
        String pdsendstring5;

        String yksendstring1;
        String yksendstring2;
        String yksendstring3;
        String yksendstring4;
        String yksendstring5;

        String ydsendstring1;
        String ydsendstring2;
        String ydsendstring3;
        String ydsendstring4;
        String ydsendstring5;

        String cksendstring1;
        String cksendstring2;
        String cksendstring3;
        String cksendstring4;
        String cksendstring5;



        String Pshow;
        String KCshow;
        
        void __fastcall SaveExcel(TStringList * sList, String szFile);
        int CrnListSplitString(String str, TStrings * pList, TCHAR cSplit);
       // int __stdcall CrnListSplitString(String str, TStrings *pList, TCHAR cSplit);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
