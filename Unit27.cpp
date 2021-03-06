//---------------------------------------------------------------------------

#include <vcl.h>
#include   <inifiles.hpp>
#pragma hdrstop

#include "Unit27.h"
#include "Unit1.h"
#include "Unit19.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm27 *Form27;
//---------------------------------------------------------------------------
__fastcall TForm27::TForm27(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm27::Button1Click(TObject *Sender)
{
     RKprint->QRLabel15->Caption=Edit1->Text.Trim();
     if(Edit2->Text.Trim().Length()==0)RKprint->QRLabel16->Caption="";    
     else RKprint->QRLabel16->Caption="备    注："+Edit2->Text.Trim();
     RKprint->QRLabel7->Caption=Form1->infshow2.Trim();



     Double all=0;
       //计算总金额
       for(int i=0;i<Form1->RK_ADOQuery->RecordCount;i++)
       {
            all=all+Form1->RK_ADOQuery->FieldByName("入库数量")->AsFloat*Form1->RK_ADOQuery->FieldByName("进价")->AsFloat;
            Form1->RK_ADOQuery->Next();
       }
       RKprint->QRLabel13->Caption=String(all);

       TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
       RKprint->QRLabel5->Caption=ini->ReadString("Sys","RK3","广州润山信息科技有限公司");
       delete  ini;
       RKprint->QRLabel3->Caption=Now().FormatString("yyyy-mm-dd hh:nn:ss");
       this->Close();
       RKprint->QuickRep1->Preview();
}
//---------------------------------------------------------------------------

void __fastcall TForm27::Edit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key==13)
    {
       Edit2->SetFocus();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm27::Edit2KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key==13)
    {
       Button1Click(Sender);
    }
}
//---------------------------------------------------------------------------
