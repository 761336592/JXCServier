//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include   <inifiles.hpp>

#include "Unit29.h"
#include "Unit28.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm29 *Form29;
//---------------------------------------------------------------------------
__fastcall TForm29::TForm29(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm29::Button1Click(TObject *Sender)
{
     YKprint->QRLabel15->Caption=Edit1->Text.Trim();
     if(Edit2->Text.Trim().Length()==0)YKprint->QRLabel16->Caption="";
     else YKprint->QRLabel16->Caption="备    注："+Edit2->Text.Trim();
     YKprint->QRLabel7->Caption=Form1->infshow2.Trim();


     Double all=0;
       //计算总金额
       for(int i=0;i<Form1->YK_ADOQuery->RecordCount;i++)
       {
            all=all+Form1->YK_ADOQuery->FieldByName("数量")->AsFloat;
            Form1->YK_ADOQuery->Next();
       }
       YKprint->QRLabel13->Caption=String(all);

       TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
       YKprint->QRLabel5->Caption=ini->ReadString("Sys","YK3","广州润山信息科技有限公司");
       delete  ini;
       YKprint->QRLabel3->Caption=Now().FormatString("yyyy-mm-dd hh:nn:ss");
       this->Close();
       YKprint->QuickRep1->Preview();
}
//---------------------------------------------------------------------------

void __fastcall TForm29::Edit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key==13)
    {
       Edit2->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm29::Edit2KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key==13)
    {
       Button1Click(Sender);
    }        
}
//---------------------------------------------------------------------------
