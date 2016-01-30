//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit13.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm13 *Form13;
//---------------------------------------------------------------------------
__fastcall TForm13::TForm13(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm13::FormClose(TObject *Sender, TCloseAction &Action)
{
   // if(DBGrid1->DataSource->DataSet->State==dsEdit)
    if(DBGrid1->DataSource->DataSet->State==2||DBGrid1->DataSource->DataSet->State==3)
    {
       DBGrid1->DataSource->DataSet->Post();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm13::BitBtn2Click(TObject *Sender)
{
    String str="";

    if(Edit1->Text.Trim().Length()==0)
    {
            str="";
            str="SELECT * FROM YG";
    }
    else
    {
            str="";
            str="SELECT * FROM YG WHERE 员工编号 like \""+Edit1->Text.Trim()+"\"";
    }

    Form1->YG_ADOQuery->Close();
    Form1->YG_ADOQuery->SQL->Clear();
    Form1->YG_ADOQuery->SQL->Add(str);
    Form1->YG_ADOQuery->Active= true;

    StatusBar1->Panels->Items[0]->Text="查询结果    条数： "+String(Form1->YG_ADOQuery->RecordCount);
}
//---------------------------------------------------------------------------
void __fastcall TForm13::Button1Click(TObject *Sender)
{
ShowMessage(DBGrid1->DataSource->DataSet->State);
       DBGrid1->DataSource->DataSet->Post();
}
//---------------------------------------------------------------------------


void __fastcall TForm13::DBGrid1TitleClick(TColumn *Column)
{
  String s;
  if(Form1->YG_ADOQuery->Active)
  {
      if (DBGrid1->Tag==0) //顺序排列
      {
         Form1->YG_ADOQuery->Sort=Column->FieldName+" ASC";
         DBGrid1->Tag=1;
      }
      else   //反序排列,改变字体颜色
      {
         Form1->YG_ADOQuery->Sort=Column->FieldName+" DESC";
         DBGrid1->Tag=0;
      }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm13::FormShow(TObject *Sender)
{
    if(Form1->LoginName!="01")
     {
        //  BitBtn3->Enabled=false;
          DBGrid1->Options=TDBGridOptions(DBGrid1->Options)<<dgRowSelect;

     }
    StatusBar1->Panels->Items[0]->Text="查询结果    条数： "+String(Form1->YG_ADOQuery->RecordCount);
}
//---------------------------------------------------------------------------

void __fastcall TForm13::DBGrid1CellClick(TColumn *Column)
{
   if(DBGrid1->Columns->Grid->Fields[0]->IsNull==false)Edit1->Text=DBGrid1->Columns->Grid->Fields[0]->Value;                
}
//---------------------------------------------------------------------------

