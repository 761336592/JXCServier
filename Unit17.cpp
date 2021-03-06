//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include   <inifiles.hpp>

#include "Unit17.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm17 *Form17;
//---------------------------------------------------------------------------
__fastcall TForm17::TForm17(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm17::BitBtn1Click(TObject *Sender)
{
        TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");

        String type="";
        String sep="";
        String sepother="";
        String RK="";
        String CK="";
        String PD="";

        String RKxls="";
        String CKxls="";
        String PDxls="";



        if(RadioButton4->Checked==true)
        type="0";
        else if(RadioButton5->Checked==true)
        type="1";
      //  else if(RadioButton6->Checked==true)
      //  type="2";

        sep=String(ComboBox47->ItemIndex);
        sepother=Edit18->Text.Trim();

        RK=String(ComboBox2->ItemIndex)+","+String(ComboBox3->ItemIndex)+","+String(ComboBox4->ItemIndex)+","+String(ComboBox5->ItemIndex)+","+String(ComboBox6->ItemIndex)+","+
        String(ComboBox7->ItemIndex)+","+String(ComboBox8->ItemIndex)+","+String(ComboBox9->ItemIndex)+","+String(ComboBox10->ItemIndex)+","+String(ComboBox11->ItemIndex)+","+
        String(ComboBox12->ItemIndex)+","+String(ComboBox13->ItemIndex)+","+String(ComboBox14->ItemIndex)+","+String(ComboBox15->ItemIndex)+","+String(ComboBox16->ItemIndex)+","+
        String(ComboBox48->ItemIndex)+","+String(ComboBox49->ItemIndex);

        RKxls=ComboBox2->Text.Trim()+","+ComboBox3->Text.Trim()+","+ComboBox4->Text.Trim()+","+ComboBox5->Text.Trim()+","+ComboBox6->Text.Trim()
        +","+ComboBox7->Text.Trim()+","+ComboBox8->Text.Trim()+","+ComboBox9->Text.Trim()+","+ComboBox10->Text.Trim()+","+ComboBox11->Text.Trim()
        +","+ComboBox12->Text.Trim()+","+ComboBox13->Text.Trim()+","+ComboBox14->Text.Trim()+","+ComboBox15->Text.Trim()+","+ComboBox16->Text.Trim()
        +","+ComboBox48->Text.Trim()+","+ComboBox49->Text.Trim();

        CK=String(ComboBox17->ItemIndex)+","+String(ComboBox18->ItemIndex)+","+String(ComboBox19->ItemIndex)+","+String(ComboBox20->ItemIndex)+","+String(ComboBox21->ItemIndex)+","+
        String(ComboBox22->ItemIndex)+","+String(ComboBox23->ItemIndex)+","+String(ComboBox24->ItemIndex)+","+String(ComboBox25->ItemIndex)+","+String(ComboBox26->ItemIndex)+","+
        String(ComboBox27->ItemIndex)+","+String(ComboBox28->ItemIndex)+","+String(ComboBox29->ItemIndex)+","+String(ComboBox30->ItemIndex)+","+String(ComboBox31->ItemIndex)+","+
        String(ComboBox50->ItemIndex)+","+String(ComboBox51->ItemIndex);

        CKxls=ComboBox17->Text.Trim()+","+ComboBox18->Text.Trim()+","+ComboBox19->Text.Trim()+","+ComboBox20->Text.Trim()+","+ComboBox21->Text.Trim()
        +","+ComboBox22->Text.Trim()+","+ComboBox23->Text.Trim()+","+ComboBox24->Text.Trim()+","+ComboBox25->Text.Trim()+","+ComboBox26->Text.Trim()
        +","+ComboBox27->Text.Trim()+","+ComboBox28->Text.Trim()+","+ComboBox29->Text.Trim()+","+ComboBox30->Text.Trim()+","+ComboBox31->Text.Trim()
        +","+ComboBox50->Text.Trim()+","+ComboBox51->Text.Trim();

        PD=String(ComboBox32->ItemIndex)+","+String(ComboBox33->ItemIndex)+","+String(ComboBox34->ItemIndex)+","+String(ComboBox35->ItemIndex)+","+String(ComboBox36->ItemIndex)+","+
        String(ComboBox37->ItemIndex)+","+String(ComboBox38->ItemIndex)+","+String(ComboBox39->ItemIndex)+","+String(ComboBox40->ItemIndex)+","+String(ComboBox41->ItemIndex)+","+
        String(ComboBox42->ItemIndex)+","+String(ComboBox43->ItemIndex)+","+String(ComboBox44->ItemIndex)+","+String(ComboBox45->ItemIndex)+","+String(ComboBox46->ItemIndex)+","+
        String(ComboBox52->ItemIndex)+","+String(ComboBox53->ItemIndex);

        PDxls=ComboBox32->Text.Trim()+","+ComboBox33->Text.Trim()+","+ComboBox34->Text.Trim()+","+ComboBox35->Text.Trim()+","+ComboBox36->Text.Trim()
        +","+ComboBox37->Text.Trim()+","+ComboBox38->Text.Trim()+","+ComboBox39->Text.Trim()+","+ComboBox40->Text.Trim()+","+ComboBox41->Text.Trim()
        +","+ComboBox42->Text.Trim()+","+ComboBox43->Text.Trim()+","+ComboBox44->Text.Trim()+","+ComboBox45->Text.Trim()+","+ComboBox46->Text.Trim()
        +","+ComboBox52->Text.Trim()+","+ComboBox53->Text.Trim();

        ini-> WriteString( "Sys", "type", type);
        ini-> WriteString( "Sys", "sep", sep);
        ini-> WriteString( "Sys", "sepother", sepother);
        ini-> WriteString( "Sys", "RKxls", RKxls);
        ini-> WriteString( "Sys", "CKxls", CKxls);
        ini-> WriteString( "Sys", "PDxls", PDxls);
        ini-> WriteString( "Sys", "RK", RK);
        ini-> WriteString( "Sys", "CK", CK);
        ini-> WriteString( "Sys", "PD", PD);

        delete ini;

        ShowMessage("保存成功");


}
//---------------------------------------------------------------------------

void __fastcall TForm17::ComboBox47Change(TObject *Sender)
{
     if(ComboBox47->ItemIndex==4)Edit18->Visible=true;
     else  Edit18->Visible=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm17::FormShow(TObject *Sender)
{
    TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
    ComboBox2->Clear();
    ComboBox2->Items->Add("条码");
    ComboBox2->Items->Add("入库数量");
    ComboBox2->Items->Add("入库时间");
    ComboBox2->Items->Add("入库仓库");
    ComboBox2->Items->Add("入库单据");
    ComboBox2->Items->Add("员工编号");
    ComboBox2->Items->Add("员工姓名");
    ComboBox2->Items->Add(Form1->infshow2);
    ComboBox2->Items->Add(Form1->infshow3);
    ComboBox2->Items->Add(Form1->infshow4);
    ComboBox2->Items->Add(Form1->infshow5);
    ComboBox2->Items->Add(Form1->infshow6);
    ComboBox2->Items->Add(Form1->infshow7);
    ComboBox2->Items->Add(Form1->infshow8);
    ComboBox2->Items->Add(Form1->infshow9);
    ComboBox2->Items->Add(Form1->infshow10);
    ComboBox2->Items->Add(Form1->infshow11);

    ComboBox3->Items=ComboBox2->Items;
    ComboBox4->Items=ComboBox2->Items;
    ComboBox5->Items=ComboBox2->Items;
    ComboBox6->Items=ComboBox2->Items;
    ComboBox7->Items=ComboBox2->Items;
    ComboBox8->Items=ComboBox2->Items;
    ComboBox9->Items=ComboBox2->Items;
    ComboBox10->Items=ComboBox2->Items;
    ComboBox11->Items=ComboBox2->Items;
    ComboBox12->Items=ComboBox2->Items;
    ComboBox13->Items=ComboBox2->Items;
    ComboBox14->Items=ComboBox2->Items;
    ComboBox15->Items=ComboBox2->Items;
    ComboBox16->Items=ComboBox2->Items;
    ComboBox48->Items=ComboBox2->Items;
    ComboBox49->Items=ComboBox2->Items;


    ComboBox17->Clear();
    ComboBox17->Items->Add("条码");
    ComboBox17->Items->Add("出库数量");
    ComboBox17->Items->Add("出库时间");
    ComboBox17->Items->Add("出库仓库");
    ComboBox17->Items->Add("出库单据");
    ComboBox17->Items->Add("员工编号");
    ComboBox17->Items->Add("员工姓名");
    ComboBox17->Items->Add(Form1->infshow2);
    ComboBox17->Items->Add(Form1->infshow3);
    ComboBox17->Items->Add(Form1->infshow4);
    ComboBox17->Items->Add(Form1->infshow5);
    ComboBox17->Items->Add(Form1->infshow6);
    ComboBox17->Items->Add(Form1->infshow7);
    ComboBox17->Items->Add(Form1->infshow8);
    ComboBox17->Items->Add(Form1->infshow9);
    ComboBox17->Items->Add(Form1->infshow10);
    ComboBox17->Items->Add(Form1->infshow11);

    ComboBox18->Items=ComboBox17->Items;
    ComboBox19->Items=ComboBox17->Items;
    ComboBox20->Items=ComboBox17->Items;
    ComboBox21->Items=ComboBox17->Items;
    ComboBox22->Items=ComboBox17->Items;
    ComboBox23->Items=ComboBox17->Items;
    ComboBox24->Items=ComboBox17->Items;
    ComboBox25->Items=ComboBox17->Items;
    ComboBox26->Items=ComboBox17->Items;
    ComboBox27->Items=ComboBox17->Items;
    ComboBox28->Items=ComboBox17->Items;
    ComboBox29->Items=ComboBox17->Items;
    ComboBox30->Items=ComboBox17->Items;
    ComboBox31->Items=ComboBox17->Items;
    ComboBox50->Items=ComboBox17->Items;
    ComboBox51->Items=ComboBox17->Items;


    ComboBox32->Clear();
    ComboBox32->Items->Add("条码");
    ComboBox32->Items->Add("盘点库存");
    ComboBox32->Items->Add("盘点时间");
    ComboBox32->Items->Add("仓库");
    ComboBox32->Items->Add("单号");
    ComboBox32->Items->Add("员工编号");
    ComboBox32->Items->Add("员工姓名");
    ComboBox32->Items->Add(Form1->infshow2);
    ComboBox32->Items->Add(Form1->infshow3);
    ComboBox32->Items->Add(Form1->infshow4);
    ComboBox32->Items->Add(Form1->infshow5);
    ComboBox32->Items->Add(Form1->infshow6);
    ComboBox32->Items->Add(Form1->infshow7);
    ComboBox32->Items->Add(Form1->infshow8);
    ComboBox32->Items->Add(Form1->infshow9);
    ComboBox32->Items->Add(Form1->infshow10);
    ComboBox32->Items->Add(Form1->infshow11);

    ComboBox33->Items=ComboBox32->Items;
    ComboBox34->Items=ComboBox32->Items;
    ComboBox35->Items=ComboBox32->Items;
    ComboBox36->Items=ComboBox32->Items;
    ComboBox37->Items=ComboBox32->Items;
    ComboBox38->Items=ComboBox32->Items;
    ComboBox39->Items=ComboBox32->Items;
    ComboBox40->Items=ComboBox32->Items;
    ComboBox41->Items=ComboBox32->Items;
    ComboBox42->Items=ComboBox32->Items;
    ComboBox43->Items=ComboBox32->Items;
    ComboBox44->Items=ComboBox32->Items;
    ComboBox45->Items=ComboBox32->Items;
    ComboBox46->Items=ComboBox32->Items;
    ComboBox52->Items=ComboBox32->Items;
    ComboBox53->Items=ComboBox32->Items;



    String type="";
    String sep="";
    String sepother="";
    String RK="";
    String CK="";
    String PD="";

    type=ini->ReadString("Sys","type","0");
    sep=ini->ReadString("Sys","sep","0");
    sepother=ini->ReadString("Sys","sepother","~");
    RK=ini->ReadString("Sys","RK","0,1,2,3,4,5,6,7,8,9,10,11,12,13,14");
    CK=ini->ReadString("Sys","CK","0,1,2,3,4,5,6,7,8,9,10,11,12,13,14");
    PD=ini->ReadString("Sys","PD","0,1,2,3,4,5,6,7,8,9,10,11,12,13,14");

    if(type.Trim()=="0")
    RadioButton4->Checked=true;
    else if(type.Trim()=="1")
    RadioButton5->Checked=true;


    ComboBox47->ItemIndex=sep.ToInt();
    if(sep=="4")
    {
        Edit18->Text=sepother;
       Edit18->Visible=true;
    }

    TStringList *pList=new TStringList();
    pList->Text="";
    Form1->CrnListSplitString(RK,pList,',');
    ComboBox2->ItemIndex=pList->Strings[0].ToInt();
    ComboBox3->ItemIndex=pList->Strings[1].ToInt();
    ComboBox4->ItemIndex=pList->Strings[2].ToInt();
    ComboBox5->ItemIndex=pList->Strings[3].ToInt();
    ComboBox6->ItemIndex=pList->Strings[4].ToInt();
    ComboBox7->ItemIndex=pList->Strings[5].ToInt();
    ComboBox8->ItemIndex=pList->Strings[6].ToInt();
    ComboBox9->ItemIndex=pList->Strings[7].ToInt();
    ComboBox10->ItemIndex=pList->Strings[8].ToInt();
    ComboBox11->ItemIndex=pList->Strings[9].ToInt();
    ComboBox12->ItemIndex=pList->Strings[10].ToInt();
    ComboBox13->ItemIndex=pList->Strings[11].ToInt();
    ComboBox14->ItemIndex=pList->Strings[12].ToInt();
    ComboBox15->ItemIndex=pList->Strings[13].ToInt();
    ComboBox16->ItemIndex=pList->Strings[14].ToInt();

    pList->Text="";
    Form1->CrnListSplitString(CK,pList,',');
    ComboBox17->ItemIndex=pList->Strings[0].ToInt();
    ComboBox18->ItemIndex=pList->Strings[1].ToInt();
    ComboBox19->ItemIndex=pList->Strings[2].ToInt();
    ComboBox20->ItemIndex=pList->Strings[3].ToInt();
    ComboBox21->ItemIndex=pList->Strings[4].ToInt();
    ComboBox22->ItemIndex=pList->Strings[5].ToInt();
    ComboBox23->ItemIndex=pList->Strings[6].ToInt();
    ComboBox24->ItemIndex=pList->Strings[7].ToInt();
    ComboBox25->ItemIndex=pList->Strings[8].ToInt();
    ComboBox26->ItemIndex=pList->Strings[9].ToInt();
    ComboBox27->ItemIndex=pList->Strings[10].ToInt();
    ComboBox28->ItemIndex=pList->Strings[11].ToInt();
    ComboBox29->ItemIndex=pList->Strings[12].ToInt();
    ComboBox30->ItemIndex=pList->Strings[13].ToInt();
    ComboBox31->ItemIndex=pList->Strings[14].ToInt();

    pList->Text="";
    Form1->CrnListSplitString(PD,pList,',');
    ComboBox32->ItemIndex=pList->Strings[0].ToInt();
    ComboBox33->ItemIndex=pList->Strings[1].ToInt();
    ComboBox34->ItemIndex=pList->Strings[2].ToInt();
    ComboBox35->ItemIndex=pList->Strings[3].ToInt();
    ComboBox36->ItemIndex=pList->Strings[4].ToInt();
    ComboBox37->ItemIndex=pList->Strings[5].ToInt();
    ComboBox38->ItemIndex=pList->Strings[6].ToInt();
    ComboBox39->ItemIndex=pList->Strings[7].ToInt();
    ComboBox40->ItemIndex=pList->Strings[8].ToInt();
    ComboBox41->ItemIndex=pList->Strings[9].ToInt();
    ComboBox42->ItemIndex=pList->Strings[10].ToInt();
    ComboBox43->ItemIndex=pList->Strings[11].ToInt();
    ComboBox44->ItemIndex=pList->Strings[12].ToInt();
    ComboBox45->ItemIndex=pList->Strings[13].ToInt();
    ComboBox46->ItemIndex=pList->Strings[14].ToInt();

    delete ini;
    delete pList;
}
//---------------------------------------------------------------------------

