//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include   <inifiles.hpp>
#include "Unit40.h"
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm40 *Form40;
//---------------------------------------------------------------------------
__fastcall TForm40::TForm40(TComponent* Owner)
        : TForm(Owner)
{
	
}
//---------------------------------------------------------------------------

void __fastcall TForm40::FormShow(TObject *Sender)
{
    Edit1->Text="条码";
    Edit2->Text="名称" ;
    TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
    CB1->Items->Add("条码");
    CB1->Items->Add("名称");
    CB1->Items->Add(Form1->infshow3);
    CB1->Items->Add(Form1->infshow4);
    CB1->Items->Add(Form1->infshow5);
    CB1->Items->Add(Form1->infshow6);
    CB1->Items->Add(Form1->infshow7);
    CB1->Items->Add(Form1->infshow8);
    CB1->Items->Add(Form1->infshow9);
    CB1->Items->Add(Form1->infshow10);
    CB1->Items->Add(Form1->infshow11);


    String code=ini->ReadString("Sys","code","0,1,2,3");
    TStringList *pList=new TStringList();
    pList->Text="";
    Form1->CrnListSplitString(code,pList,',');
    CB1->ItemIndex=pList->Strings[2].ToInt();



    delete ini;
   delete pList;
}
//---------------------------------------------------------------------------

void __fastcall TForm40::Button1Click(TObject *Sender)
{
     TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
        String RK="0,1,"+String(CB1->ItemIndex);

     String  RKxls="条码,名称,"+CB1->Text.Trim();

      ini-> WriteString( "Sys", "codexls",RKxls);
        ini-> WriteString( "Sys", "code",RK);

        delete ini;

        ShowMessage("保存成功");
}
//---------------------------------------------------------------------------

