//---------------------------------------------------------------------------

#ifndef Unit32H
#define Unit32H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm32 : public TForm
{
__published:	// IDE-managed Components
        TDataSource *DataSource1;
        TDBGrid *DBGrid1;
        TComboBox *ComboBox1;
        TEdit *Edit1;
        TBitBtn *BitBtn1;
        TLabel *Label1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall DBGrid1DblClick(TObject *Sender);
        void __fastcall DBGrid1CellClick(TColumn *Column);
private:	// User declarations
public:		// User declarations
        __fastcall TForm32(TComponent* Owner);

        String typeindex;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm32 *Form32;
//---------------------------------------------------------------------------
#endif
