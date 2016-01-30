//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit35.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPDprint *PDprint;
//---------------------------------------------------------------------------
__fastcall TPDprint::TPDprint(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
