//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit32.h"
#include "Unit1.h"
#include "Unit3.h"
#include "Unit5.h"
#include "Unit22.h"
#include "Unit8.h"
#include "Unit11.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm32 *Form32;
//---------------------------------------------------------------------------
__fastcall TForm32::TForm32(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm32::FormCreate(TObject *Sender)
{
      for(int i=0;i<DBGrid1->Columns->Count-2;i++)
      DBGrid1->Columns->Items[i]->Width=(DBGrid1->Width-60)/(DBGrid1->Columns->Count-2);
      DBGrid1->Columns->Items[5]->Width=5;
      DBGrid1->Columns->Items[6]->Width=5;
}
//---------------------------------------------------------------------------
void __fastcall TForm32::FormShow(TObject *Sender)
{
    DBGrid1->Columns->Items[0]->Title->Caption=Form1->infshow1;
    DBGrid1->Columns->Items[1]->Title->Caption=Form1->infshow2;
    DBGrid1->Columns->Items[2]->Title->Caption=Form1->infshow3;
    DBGrid1->Columns->Items[3]->Title->Caption=Form1->infshow4;
    DBGrid1->Columns->Items[4]->Title->Caption=Form1->infshow5;

    ComboBox1->Clear();
    ComboBox1->Items->Add("条码");
    ComboBox1->Items->Add(Form1->infshow2);
    ComboBox1->Items->Add(Form1->infshow3);
    ComboBox1->Items->Add(Form1->infshow4);
    ComboBox1->Items->Add(Form1->infshow5);
    ComboBox1->ItemIndex=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm32::BitBtn1Click(TObject *Sender)
{
    String SelectINF[]={"条码","名称","货号","规格","型号"};
    Form1->ADOQuery1->Close();
    Form1->ADOQuery1->SQL->Clear();
    if(Edit1->Text.Trim().Length()!=0)
    Form1->ADOQuery1->SQL->Add("SELECT * FROM JBZL where "+SelectINF[ComboBox1->ItemIndex]+" like \"%"+Edit1->Text.Trim()+"%\"");
    else
    Form1->ADOQuery1->SQL->Add("SELECT * FROM JBZL");
    Form1->ADOQuery1->Active= true;
}
//---------------------------------------------------------------------------
void __fastcall TForm32::DBGrid1DblClick(TObject *Sender)
{
    //确定查询      DBGrid1->Columns->Grid->Fields[0]->Value
    /*Form1->ADOQuery1->Close();
    Form1->ADOQuery1->SQL->Clear();
    Form1->ADOQuery1->SQL->Add("SELECT * FROM JBZL where 条码 like \""+DBGrid1->Columns->Grid->Fields[0]->Value+"\"");
    Form1->ADOQuery1->Active= true; */

    if(Form32->typeindex=="3")
    {
        if(DBGrid1->Columns->Grid->Fields[0]->IsNull==false)Form3->sgPurDetail->Cells[1][Form3->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[0]->Value;
        if(DBGrid1->Columns->Grid->Fields[1]->IsNull==false)Form3->sgPurDetail->Cells[2][Form3->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[1]->Value;
        if(DBGrid1->Columns->Grid->Fields[5]->IsNull==false)Form3->sgPurDetail->Cells[3][Form3->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[5]->Value;

        this->Close();
    }
    else if(Form32->typeindex=="5")
    {
        if(DBGrid1->Columns->Grid->Fields[0]->IsNull==false)Form5->sgPurDetail->Cells[1][Form5->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[0]->Value;
        if(DBGrid1->Columns->Grid->Fields[1]->IsNull==false)Form5->sgPurDetail->Cells[2][Form5->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[1]->Value;
        if(DBGrid1->Columns->Grid->Fields[6]->IsNull==false)Form5->sgPurDetail->Cells[3][Form5->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[6]->Value;
        if(DBGrid1->Columns->Grid->Fields[5]->IsNull==false)Form5->sgPurDetail->Cells[5][Form5->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[5]->Value;

        this->Close();
    }
    else if(Form32->typeindex=="22")
    {
        if(DBGrid1->Columns->Grid->Fields[0]->IsNull==false)Form22->sgPurDetail->Cells[1][Form22->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[0]->Value;
        if(DBGrid1->Columns->Grid->Fields[1]->IsNull==false)Form22->sgPurDetail->Cells[2][Form22->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[1]->Value;
        if(DBGrid1->Columns->Grid->Fields[2]->IsNull==false)Form22->sgPurDetail->Cells[3][Form22->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[2]->Value;

        this->Close();
    }
    else if(Form32->typeindex=="8")
    {
        if(DBGrid1->Columns->Grid->Fields[0]->IsNull==false)Form8->sgPurDetail->Cells[1][Form8->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[0]->Value;
        if(DBGrid1->Columns->Grid->Fields[1]->IsNull==false)Form8->sgPurDetail->Cells[2][Form8->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[1]->Value;
        if(DBGrid1->Columns->Grid->Fields[2]->IsNull==false)Form8->sgPurDetail->Cells[3][Form8->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[2]->Value;
        if(DBGrid1->Columns->Grid->Fields[3]->IsNull==false)Form8->sgPurDetail->Cells[4][Form8->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[3]->Value;
        if(DBGrid1->Columns->Grid->Fields[4]->IsNull==false)Form8->sgPurDetail->Cells[5][Form8->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[4]->Value;

        this->Close();
    }
    else if(Form32->typeindex=="11")
    {
        if(DBGrid1->Columns->Grid->Fields[0]->IsNull==false)Form11->sgPurDetail->Cells[1][Form11->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[0]->Value;
        if(DBGrid1->Columns->Grid->Fields[1]->IsNull==false)Form11->sgPurDetail->Cells[2][Form11->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[1]->Value;
        if(DBGrid1->Columns->Grid->Fields[6]->IsNull==false)Form11->sgPurDetail->Cells[3][Form11->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[6]->Value;

        this->Close();
    }

}
//---------------------------------------------------------------------------
void __fastcall TForm32::DBGrid1CellClick(TColumn *Column)
{
     if(DBGrid1->Columns->Grid->Fields[ComboBox1->ItemIndex]->IsNull==false)Edit1->Text=DBGrid1->Columns->Grid->Fields[ComboBox1->ItemIndex]->Value;
}
//---------------------------------------------------------------------------
