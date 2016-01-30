//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit24.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm24 *Form24;
//---------------------------------------------------------------------------
__fastcall TForm24::TForm24(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm24::FormCreate(TObject *Sender)
{
      for(int i=0;i<DBGrid1->Columns->Count;i++)
      DBGrid1->Columns->Items[i]->Width=(DBGrid1->Width-50)/DBGrid1->Columns->Count;
}
//---------------------------------------------------------------------------

