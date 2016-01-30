//---------------------------------------------------------------------------

#ifndef Unit24H
#define Unit24H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm24 : public TForm
{
__published:	// IDE-managed Components
        TDBGrid *DBGrid1;
        TDataSource *DataSource1;
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm24(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm24 *Form24;
//---------------------------------------------------------------------------
#endif
