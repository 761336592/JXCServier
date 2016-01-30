//---------------------------------------------------------------------------

#ifndef Unit19H
#define Unit19H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
//---------------------------------------------------------------------------
class TRKprint : public TForm
{
__published:	// IDE-managed Components
        TQuickRep *QuickRep1;
        TQRBand *QRBand1;
        TQRLabel *QRLabel2;
        TQRDBText *QRDBText2;
        TQRLabel *QRLabel4;
        TQRLabel *QRLabel5;
        TQRBand *QRBand2;
        TQRBand *QRBand3;
        TQRShape *QRShape1;
        TQRShape *QRShape2;
        TQRShape *QRShape3;
        TQRShape *QRShape4;
        TQRShape *QRShape5;
        TQRShape *QRShape6;
        TQRShape *QRShape7;
        TQRShape *QRShape8;
        TQRLabel *QRLabel6;
        TQRLabel *QRLabel7;
        TQRLabel *QRLabel8;
        TQRLabel *QRLabel9;
        TQRDBText *QRDBText5;
        TQRDBText *QRDBText6;
        TQRDBText *QRDBText7;
        TQRDBText *QRDBText8;
        TQRBand *QRBand4;
        TQRShape *QRShape9;
        TQRShape *QRShape10;
        TQRLabel *QRLabel10;
        TQRDBText *QRDBText9;
        TQRShape *QRShape11;
        TQRShape *QRShape12;
        TQRLabel *QRLabel11;
        TQRDBText *QRDBText10;
        TQRLabel *QRLabel3;
        TQRLabel *QRLabel14;
        TQRLabel *QRLabel15;
        TQRShape *QRShape13;
        TQRLabel *QRLabel17;
        TQRShape *QRShape14;
        TQRExpr *QRExpr1;
        TQRLabel *QRLabel12;
        TQRLabel *QRLabel13;
        TQRLabel *QRLabel1;
        TQRDBText *QRDBText1;
        TQRLabel *QRLabel16;
private:	// User declarations
public:		// User declarations
        __fastcall TRKprint(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRKprint *RKprint;
//---------------------------------------------------------------------------
#endif
