//---------------------------------------------------------------------------

#ifndef Unit28H
#define Unit28H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TYKprint : public TForm
{
__published:	// IDE-managed Components
        TQuickRep *QuickRep1;
        TQRBand *QRBand1;
        TQRLabel *QRLabel2;
        TQRDBText *QRDBText2;
        TQRLabel *QRLabel4;
        TQRLabel *QRLabel5;
        TQRLabel *QRLabel3;
        TQRLabel *QRLabel14;
        TQRLabel *QRLabel15;
        TQRBand *QRBand2;
        TQRShape *QRShape5;
        TQRShape *QRShape6;
        TQRShape *QRShape8;
        TQRDBText *QRDBText5;
        TQRDBText *QRDBText6;
        TQRShape *QRShape10;
        TQRDBText *QRDBText9;
        TQRShape *QRShape12;
        TQRDBText *QRDBText10;
        TQRShape *QRShape14;
        TQRBand *QRBand3;
        TQRShape *QRShape1;
        TQRShape *QRShape2;
        TQRShape *QRShape4;
        TQRLabel *QRLabel6;
        TQRLabel *QRLabel7;
        TQRShape *QRShape9;
        TQRLabel *QRLabel10;
        TQRShape *QRShape11;
        TQRLabel *QRLabel11;
        TQRShape *QRShape13;
        TQRBand *QRBand4;
        TQRLabel *QRLabel9;
        TQRDBText *QRDBText8;
        TQRLabel *QRLabel17;
        TQRDBText *QRDBText3;
        TQRLabel *QRLabel1;
        TQRDBText *QRDBText1;
        TQRLabel *QRLabel16;
        TQRLabel *QRLabel12;
        TQRLabel *QRLabel13;
private:	// User declarations
public:		// User declarations
        __fastcall TYKprint(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TYKprint *YKprint;
//---------------------------------------------------------------------------
#endif
