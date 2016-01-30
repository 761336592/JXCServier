//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit33.h"
#include "Unit1.h"
#include "Unit25.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm33 *Form33;
//---------------------------------------------------------------------------
__fastcall TForm33::TForm33(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm33::FormCreate(TObject *Sender)
{
      for(int i=0;i<DBGrid1->Columns->Count;i++)
      DBGrid1->Columns->Items[i]->Width=(DBGrid1->Width-50)/DBGrid1->Columns->Count;
}
//---------------------------------------------------------------------------
void __fastcall TForm33::FormShow(TObject *Sender)
{
    DBGrid1->Columns->Items[0]->Title->Caption=Form1->infshow1;
    DBGrid1->Columns->Items[1]->Title->Caption=Form1->infshow2;
    DBGrid1->Columns->Items[2]->Title->Caption=Form1->infshow3;
    DBGrid1->Columns->Items[3]->Title->Caption=Form1->infshow4;
    DBGrid1->Columns->Items[4]->Title->Caption=Form1->infshow4;

    ComboBox1->Clear();
    ComboBox1->Items->Add("条码");
    ComboBox1->Items->Add(Form1->infshow2);
    ComboBox1->Items->Add(Form1->infshow3);
    ComboBox1->Items->Add(Form1->infshow4);
    ComboBox1->Items->Add(Form1->infshow5);
    ComboBox1->ItemIndex=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm33::Button1Click(TObject *Sender)
{
    String str="";
    String SelectINF[]={"条码","名称","货号","规格","型号"};
    str="SELECT * FROM 验单 WHERE "+SelectINF[ComboBox1->ItemIndex]+" like \"%"+Edit1->Text.Trim()+"%\"";
    Form1->YD_ADOQuery->Close();
    Form1->YD_ADOQuery->SQL->Clear();
    Form1->YD_ADOQuery->SQL->Add(str);
    Form1->YD_ADOQuery->Active= true;

}
//---------------------------------------------------------------------------
void __fastcall TForm33::DBGrid1CellClick(TColumn *Column)
{
     if(DBGrid1->Columns->Grid->Fields[ComboBox1->ItemIndex]->IsNull==false)Edit1->Text=DBGrid1->Columns->Grid->Fields[ComboBox1->ItemIndex]->Value;
}
//---------------------------------------------------------------------------
void __fastcall TForm33::DBGrid1DblClick(TObject *Sender)
{
        if(DBGrid1->Columns->Grid->Fields[0]->IsNull==false)Form25->sgPurDetail->Cells[1][Form25->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[0]->Value;
        if(DBGrid1->Columns->Grid->Fields[1]->IsNull==false)Form25->sgPurDetail->Cells[2][Form25->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[1]->Value;
        if(DBGrid1->Columns->Grid->Fields[5]->IsNull==false)Form25->sgPurDetail->Cells[3][Form25->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[5]->Value;
        if(DBGrid1->Columns->Grid->Fields[6]->IsNull==false)Form25->sgPurDetail->Cells[4][Form25->sgPurDetail->Row]=DBGrid1->Columns->Grid->Fields[6]->Value;

        this->Close();
}
//---------------------------------------------------------------------------
