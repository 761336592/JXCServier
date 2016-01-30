//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit39.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm39 *Form39;
//---------------------------------------------------------------------------
__fastcall TForm39::TForm39(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm39::Label1Click(TObject *Sender)
{
      ShellExecute(Handle,NULL,Label1->Caption.c_str(),NULL,NULL,SW_SHOWNORMAL);

}
//---------------------------------------------------------------------------

void __fastcall TForm39::Label1MouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
     Label1->Font->Color=clRed;
     Label1->Font->Style=TFontStyles()<<fsBold<<fsUnderline;
}
//---------------------------------------------------------------------------
void __fastcall TForm39::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    Label1->Font->Color=clBlue;
     Label1->Font->Style=TFontStyles();
}
//---------------------------------------------------------------------------
