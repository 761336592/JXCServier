//---------------------------------------------------------------------------

#include <vcl.h>
#include   <inifiles.hpp>
#pragma hdrstop

#include "Unit36.h"
#include "Unit1.h"
#include "Unit35.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm36 *Form36;
//---------------------------------------------------------------------------
__fastcall TForm36::TForm36(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm36::Button1Click(TObject *Sender)
{
     PDprint->QRLabel15->Caption=Edit1->Text.Trim();
     if(Edit2->Text.Trim().Length()==0)PDprint->QRLabel16->Caption="";
     else PDprint->QRLabel16->Caption="备    注："+Edit2->Text.Trim();
     PDprint->QRLabel7->Caption=Form1->infshow2.Trim();
     PDprint->QRLabel8->Caption=Form1->infshow3.Trim();


     Double all=0;
       //计算总金额
       for(int i=0;i<Form1->PD_ADOQuery->RecordCount;i++)
       {
            all=all+Form1->PD_ADOQuery->FieldByName("盘点库存")->AsFloat;
            Form1->PD_ADOQuery->Next();
       }
       PDprint->QRLabel13->Caption=String(all);

       TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
       PDprint->QRLabel5->Caption=ini->ReadString("Sys","PD3","广州润山信息科技有限公司");
       delete  ini;
       PDprint->QRLabel3->Caption=Now().FormatString("yyyy-mm-dd hh:nn:ss");
       this->Close();
       PDprint->QuickRep1->Preview();
}
//---------------------------------------------------------------------------
void __fastcall TForm36::Edit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key==13)
    {
       Edit2->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm36::Edit2KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key==13)
    {
       Button1Click(Sender);
    }
}
//---------------------------------------------------------------------------
