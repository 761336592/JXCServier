//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <inifiles.hpp>

#include "Unit31.h"
#include "Unit30.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm31 *Form31;
//---------------------------------------------------------------------------
__fastcall TForm31::TForm31(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm31::Button1Click(TObject *Sender)
{
       YDprint->QRLabel15->Caption=Edit1->Text.Trim();
       if(Edit2->Text.Trim().Length()==0)YDprint->QRLabel16->Caption="";
       else YDprint->QRLabel16->Caption="备    注："+Edit2->Text.Trim();
       YDprint->QRLabel7->Caption=Form1->infshow2.Trim();


       Double all1=0;
       Double all2=0;
       //计算总金额
       for(int i=0;i<Form1->YD_ADOQuery->RecordCount;i++)
       {
            all1=all1+Form1->YD_ADOQuery->FieldByName("应扫数量")->AsFloat;
            all2=all2+Form1->YD_ADOQuery->FieldByName("已扫数量")->AsFloat;
            Form1->YD_ADOQuery->Next();
       }
       YDprint->QRLabel13->Caption=String(all1);
       YDprint->QRLabel17->Caption=String(all2);

       TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
       YDprint->QRLabel5->Caption=ini->ReadString("Sys","YD3","广州润山信息科技有限公司");
       delete  ini;
       YDprint->QRLabel3->Caption=Now().FormatString("yyyy-mm-dd hh:nn:ss");
       this->Close();
       YDprint->QuickRep1->Preview();
}
//---------------------------------------------------------------------------
void __fastcall TForm31::Edit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key==13)
    {
       Edit2->SetFocus();
    }        
}
//---------------------------------------------------------------------------

void __fastcall TForm31::Edit2KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key==13)
    {
       Button1Click(Sender);
    }
}
//---------------------------------------------------------------------------

