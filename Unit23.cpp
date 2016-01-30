//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit23.h"
#include "Unit2.h"

#include   <inifiles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm23 *Form23;
//---------------------------------------------------------------------------
__fastcall TForm23::TForm23(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm23::BitBtn1Click(TObject *Sender)
{
     TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
     ini-> WriteString( "Sys", "port", Edit1->Text.Trim());
     Form2->ServerSocket1->Active=false;
     Form2->ServerSocket1->Port=Edit1->Text.Trim().ToInt();
     Form2->PORT->Text=Edit1->Text.Trim();
     Form2->ServerSocket1->Active=true;
     ShowMessage("设置成功\n盘点机里边的端口必须也设置成同一个\n设置步骤如下：\n盘点机开机\n【系统设置】\n服务器连接设置\n端口设置");
     delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TForm23::FormShow(TObject *Sender)
{
     TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
     Edit1->Text=ini->ReadString("Sys","port","10000");
     delete ini;
}
//---------------------------------------------------------------------------
