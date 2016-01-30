//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include   <inifiles.hpp>

#include "Unit18.h"
#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm18 *Form18;
//---------------------------------------------------------------------------
__fastcall TForm18::TForm18(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------


void __fastcall TForm18::Button1Click(TObject *Sender)
{
//MessageDlg(Form1->infshow1,mtInformation,TMsgDlgButtons()<<mbOK,0);
     TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");

     Form1->infshow1=Edit1->Text.Trim();
     Form1->infshow2=Edit2->Text.Trim();
     Form1->infshow3=Edit3->Text.Trim();
     Form1->infshow4=Edit4->Text.Trim();
     Form1->infshow5=Edit5->Text.Trim();
     Form1->infshow6=Edit6->Text.Trim();
     Form1->infshow7=Edit7->Text.Trim();
     Form1->infshow8=Edit8->Text.Trim();
     Form1->infshow9=Edit9->Text.Trim();
     Form1->infshow10=Edit10->Text.Trim();
     Form1->infshow11=Edit11->Text.Trim();

     Form2->Label4->Caption=Form1->infshow1+"   ";
     Form2->Label6->Caption=Form1->infshow2+"   ";
     Form2->Label7->Caption=Form1->infshow3+"   ";
     Form2->Label8->Caption=Form1->infshow4+"   ";
     Form2->Label9->Caption=Form1->infshow5+"   ";
     Form2->Label10->Caption=Form1->infshow6+"   ";
     Form2->Label11->Caption=Form1->infshow7+"   ";
     Form2->Label12->Caption=Form1->infshow8+"   ";
     Form2->Label13->Caption=Form1->infshow9+"   ";
     Form2->Label14->Caption=Form1->infshow10+"   ";
     Form2->Label15->Caption=Form1->infshow11+"   ";

     Form1->rksendback1=ComboBox1->Text.Trim();
     Form1->rksendback2=ComboBox2->Text.Trim();
     Form1->rksendback3=ComboBox3->Text.Trim();
     Form1->rksendback4=ComboBox4->Text.Trim();
     Form1->rksendback5=ComboBox5->Text.Trim();

     Form1->cksendback1=ComboBox6->Text.Trim();
     Form1->cksendback2=ComboBox7->Text.Trim();
     Form1->cksendback3=ComboBox8->Text.Trim();
     Form1->cksendback4=ComboBox9->Text.Trim();
     Form1->cksendback5=ComboBox10->Text.Trim();

     Form1->pdsendback1=ComboBox11->Text.Trim();
     Form1->pdsendback2=ComboBox12->Text.Trim();
     Form1->pdsendback3=ComboBox13->Text.Trim();
     Form1->pdsendback4=ComboBox14->Text.Trim();
     Form1->pdsendback5=ComboBox15->Text.Trim();

     Form1->yksendback1=ComboBox16->Text.Trim();
     Form1->yksendback2=ComboBox17->Text.Trim();
     Form1->yksendback3=ComboBox18->Text.Trim();
     Form1->yksendback4=ComboBox19->Text.Trim();
     Form1->yksendback5=ComboBox20->Text.Trim();

     Form1->ydsendback1=ComboBox21->Text.Trim();
     Form1->ydsendback2=ComboBox22->Text.Trim();
     Form1->ydsendback3=ComboBox23->Text.Trim();
     Form1->ydsendback4=ComboBox24->Text.Trim();
     Form1->ydsendback5=ComboBox25->Text.Trim();



     ini-> WriteString( "Sys", "inf1", Edit1->Text.Trim());
     ini-> WriteString( "Sys", "inf2", Edit2->Text.Trim());
     ini-> WriteString( "Sys", "inf3", Edit3->Text.Trim());
     ini-> WriteString( "Sys", "inf4", Edit4->Text.Trim());
     ini-> WriteString( "Sys", "inf5", Edit5->Text.Trim());
     ini-> WriteString( "Sys", "inf6", Edit6->Text.Trim());
     ini-> WriteString( "Sys", "inf7", Edit7->Text.Trim());
     ini-> WriteString( "Sys", "inf8", Edit8->Text.Trim());
     ini-> WriteString( "Sys", "inf9", Edit9->Text.Trim());
     ini-> WriteString( "Sys", "inf10", Edit10->Text.Trim());
     ini-> WriteString( "Sys", "inf11", Edit11->Text.Trim());

     ini-> WriteString( "Sys", "rksendback1", Form1->rksendback1.Trim());
     ini-> WriteString( "Sys", "rksendback2", Form1->rksendback2.Trim());
     ini-> WriteString( "Sys", "rksendback3", Form1->rksendback3.Trim());
     ini-> WriteString( "Sys", "rksendback4", Form1->rksendback4.Trim());
     ini-> WriteString( "Sys", "rksendback5", Form1->rksendback5.Trim());

     ini-> WriteString( "Sys", "cksendback1", Form1->cksendback1.Trim());
     ini-> WriteString( "Sys", "cksendback2", Form1->cksendback2.Trim());
     ini-> WriteString( "Sys", "cksendback3", Form1->cksendback3.Trim());
     ini-> WriteString( "Sys", "cksendback4", Form1->cksendback4.Trim());
     ini-> WriteString( "Sys", "cksendback5", Form1->cksendback5.Trim());

     ini-> WriteString( "Sys", "pdsendback1", Form1->pdsendback1.Trim());
     ini-> WriteString( "Sys", "pdsendback2", Form1->pdsendback2.Trim());
     ini-> WriteString( "Sys", "pdsendback3", Form1->pdsendback3.Trim());
     ini-> WriteString( "Sys", "pdsendback4", Form1->pdsendback4.Trim());
     ini-> WriteString( "Sys", "pdsendback5", Form1->pdsendback5.Trim());

     ini-> WriteString( "Sys", "yksendback1", Form1->yksendback1.Trim());
     ini-> WriteString( "Sys", "yksendback2", Form1->yksendback2.Trim());
     ini-> WriteString( "Sys", "yksendback3", Form1->yksendback3.Trim());
     ini-> WriteString( "Sys", "yksendback4", Form1->yksendback4.Trim());
     ini-> WriteString( "Sys", "yksendback5", Form1->yksendback5.Trim());

     ini-> WriteString( "Sys", "ydsendback1", Form1->ydsendback1.Trim());
     ini-> WriteString( "Sys", "ydsendback2", Form1->ydsendback2.Trim());
     ini-> WriteString( "Sys", "ydsendback3", Form1->ydsendback3.Trim());
     ini-> WriteString( "Sys", "ydsendback4", Form1->ydsendback4.Trim());
     ini-> WriteString( "Sys", "ydsendback5", Form1->ydsendback5.Trim());

     ini-> WriteString( "Sys", "RK1", Edit12->Text.Trim());
     ini-> WriteString( "Sys", "RK2", String(ComboBox26->ItemIndex+1));
     ini-> WriteString( "Sys", "RK3", Edit14->Text.Trim());

     ini-> WriteString( "Sys", "CK1", Edit13->Text.Trim());
     ini-> WriteString( "Sys", "CK2", String(ComboBox27->ItemIndex+1));
     ini-> WriteString( "Sys", "CK3", Edit15->Text.Trim());

     ini-> WriteString( "Sys", "YK3", Edit16->Text.Trim());

     ini-> WriteString( "Sys", "YD3", Edit17->Text.Trim());

     ini-> WriteString( "Sys", "PD3", Edit18->Text.Trim());




    if(Form1->rksendback1=="1"){Form1->rksendback1="条码";Form1->rksendstring1=Form1->infshow1;}
    else if(Form1->rksendback1=="2"){Form1->rksendback1="名称";Form1->rksendstring1=Form1->infshow2;}
    else if(Form1->rksendback1=="3"){Form1->rksendback1="货号";Form1->rksendstring1=Form1->infshow3;}
    else if(Form1->rksendback1=="4"){Form1->rksendback1="规格";Form1->rksendstring1=Form1->infshow4;}
    else if(Form1->rksendback1=="5"){Form1->rksendback1="型号";Form1->rksendstring1=Form1->infshow5;}
    else if(Form1->rksendback1=="6"){Form1->rksendback1="进价";Form1->rksendstring1=Form1->infshow6;}
    else if(Form1->rksendback1=="7"){Form1->rksendback1="售价";Form1->rksendstring1=Form1->infshow7;}
    else if(Form1->rksendback1=="8"){Form1->rksendback1="单位";Form1->rksendstring1=Form1->infshow8;}
    else if(Form1->rksendback1=="9"){Form1->rksendback1="备注一";Form1->rksendstring1=Form1->infshow9;}
    else if(Form1->rksendback1=="10"){Form1->rksendback1="备注二";Form1->rksendstring1=Form1->infshow10;}
    else if(Form1->rksendback1=="11"){Form1->rksendback1="备注三";Form1->rksendstring1=Form1->infshow11;}
    else {Form1->rksendback1="名称";Form1->rksendstring1=Form1->infshow2;}

    if(Form1->rksendback2=="1"){Form1->rksendback2="条码";Form1->rksendstring2=Form1->infshow1;}
    else if(Form1->rksendback2=="2"){Form1->rksendback2="名称";Form1->rksendstring2=Form1->infshow2;}
    else if(Form1->rksendback2=="3"){Form1->rksendback2="货号";Form1->rksendstring2=Form1->infshow3;}
    else if(Form1->rksendback2=="4"){Form1->rksendback2="规格";Form1->rksendstring2=Form1->infshow4;}
    else if(Form1->rksendback2=="5"){Form1->rksendback2="型号";Form1->rksendstring2=Form1->infshow5;}
    else if(Form1->rksendback2=="6"){Form1->rksendback2="进价";Form1->rksendstring2=Form1->infshow6;}
    else if(Form1->rksendback2=="7"){Form1->rksendback2="售价";Form1->rksendstring2=Form1->infshow7;}
    else if(Form1->rksendback2=="8"){Form1->rksendback2="单位";Form1->rksendstring2=Form1->infshow8;}
    else if(Form1->rksendback2=="9"){Form1->rksendback2="备注一";Form1->rksendstring2=Form1->infshow9;}
    else if(Form1->rksendback2=="10"){Form1->rksendback2="备注二";Form1->rksendstring2=Form1->infshow10;}
    else if(Form1->rksendback2=="11"){Form1->rksendback2="备注三";Form1->rksendstring2=Form1->infshow11;}
    else {Form1->rksendback2="货号";Form1->rksendstring2=Form1->infshow3;}

    if(Form1->rksendback3=="1"){Form1->rksendback3="条码";Form1->rksendstring3=Form1->infshow1;}
    else if(Form1->rksendback3=="2"){Form1->rksendback3="名称";Form1->rksendstring3=Form1->infshow2;}
    else if(Form1->rksendback3=="3"){Form1->rksendback3="货号";Form1->rksendstring3=Form1->infshow3;}
    else if(Form1->rksendback3=="4"){Form1->rksendback3="规格";Form1->rksendstring3=Form1->infshow4;}
    else if(Form1->rksendback3=="5"){Form1->rksendback3="型号";Form1->rksendstring3=Form1->infshow5;}
    else if(Form1->rksendback3=="6"){Form1->rksendback3="进价";Form1->rksendstring3=Form1->infshow6;}
    else if(Form1->rksendback3=="7"){Form1->rksendback3="售价";Form1->rksendstring3=Form1->infshow7;}
    else if(Form1->rksendback3=="8"){Form1->rksendback3="单位";Form1->rksendstring3=Form1->infshow8;}
    else if(Form1->rksendback3=="9"){Form1->rksendback3="备注一";Form1->rksendstring3=Form1->infshow9;}
    else if(Form1->rksendback3=="10"){Form1->rksendback3="备注二";Form1->rksendstring3=Form1->infshow10;}
    else if(Form1->rksendback3=="11"){Form1->rksendback3="备注三";Form1->rksendstring3=Form1->infshow11;}
    else {Form1->rksendback3="进价";Form1->rksendstring3=Form1->infshow6;}

    if(Form1->rksendback4=="1"){Form1->rksendback4="条码";Form1->rksendstring4=Form1->infshow1;}
    else if(Form1->rksendback4=="2"){Form1->rksendback4="名称";Form1->rksendstring4=Form1->infshow2;}
    else if(Form1->rksendback4=="3"){Form1->rksendback4="货号";Form1->rksendstring4=Form1->infshow3;}
    else if(Form1->rksendback4=="4"){Form1->rksendback4="规格";Form1->rksendstring4=Form1->infshow4;}
    else if(Form1->rksendback4=="5"){Form1->rksendback4="型号";Form1->rksendstring4=Form1->infshow5;}
    else if(Form1->rksendback4=="6"){Form1->rksendback4="进价";Form1->rksendstring4=Form1->infshow6;}
    else if(Form1->rksendback4=="7"){Form1->rksendback4="售价";Form1->rksendstring4=Form1->infshow7;}
    else if(Form1->rksendback4=="8"){Form1->rksendback4="单位";Form1->rksendstring4=Form1->infshow8;}
    else if(Form1->rksendback4=="9"){Form1->rksendback4="备注一";Form1->rksendstring4=Form1->infshow9;}
    else if(Form1->rksendback4=="10"){Form1->rksendback4="备注二";Form1->rksendstring4=Form1->infshow10;}
    else if(Form1->rksendback4=="11"){Form1->rksendback4="备注三";Form1->rksendstring4=Form1->infshow11;}
    else {Form1->rksendback4="售价";Form1->rksendstring4=Form1->infshow7;}

    if(Form1->rksendback5=="1"){Form1->rksendback5="条码";Form1->rksendstring5=Form1->infshow1;}
    else if(Form1->rksendback5=="2"){Form1->rksendback5="名称";Form1->rksendstring5=Form1->infshow2;}
    else if(Form1->rksendback5=="3"){Form1->rksendback5="货号";Form1->rksendstring5=Form1->infshow3;}
    else if(Form1->rksendback5=="4"){Form1->rksendback5="规格";Form1->rksendstring5=Form1->infshow4;}
    else if(Form1->rksendback5=="5"){Form1->rksendback5="型号";Form1->rksendstring5=Form1->infshow5;}
    else if(Form1->rksendback5=="6"){Form1->rksendback5="进价";Form1->rksendstring5=Form1->infshow6;}
    else if(Form1->rksendback5=="7"){Form1->rksendback5="售价";Form1->rksendstring5=Form1->infshow7;}
    else if(Form1->rksendback5=="8"){Form1->rksendback5="单位";Form1->rksendstring5=Form1->infshow8;}
    else if(Form1->rksendback5=="9"){Form1->rksendback5="备注一";Form1->rksendstring5=Form1->infshow9;}
    else if(Form1->rksendback5=="10"){Form1->rksendback5="备注二";Form1->rksendstring5=Form1->infshow10;}
    else if(Form1->rksendback5=="11"){Form1->rksendback5="备注三";Form1->rksendstring5=Form1->infshow11;}
    else {Form1->rksendback5="备注一";Form1->rksendstring5=Form1->infshow9;}


    if(Form1->cksendback1=="1"){Form1->cksendback1="条码";Form1->cksendstring1=Form1->infshow1;}
    else if(Form1->cksendback1=="2"){Form1->cksendback1="名称";Form1->cksendstring1=Form1->infshow2;}
    else if(Form1->cksendback1=="3"){Form1->cksendback1="货号";Form1->cksendstring1=Form1->infshow3;}
    else if(Form1->cksendback1=="4"){Form1->cksendback1="规格";Form1->cksendstring1=Form1->infshow4;}
    else if(Form1->cksendback1=="5"){Form1->cksendback1="型号";Form1->cksendstring1=Form1->infshow5;}
    else if(Form1->cksendback1=="6"){Form1->cksendback1="进价";Form1->cksendstring1=Form1->infshow6;}
    else if(Form1->cksendback1=="7"){Form1->cksendback1="售价";Form1->cksendstring1=Form1->infshow7;}
    else if(Form1->cksendback1=="8"){Form1->cksendback1="单位";Form1->cksendstring1=Form1->infshow8;}
    else if(Form1->cksendback1=="9"){Form1->cksendback1="备注一";Form1->cksendstring1=Form1->infshow9;}
    else if(Form1->cksendback1=="10"){Form1->cksendback1="备注二";Form1->cksendstring1=Form1->infshow10;}
    else if(Form1->cksendback1=="11"){Form1->cksendback1="备注三";Form1->cksendstring1=Form1->infshow11;}
    else {Form1->cksendback1="名称";Form1->cksendstring1=Form1->infshow2;}

    if(Form1->cksendback2=="1"){Form1->cksendback2="条码";Form1->cksendstring2=Form1->infshow1;}
    else if(Form1->cksendback2=="2"){Form1->cksendback2="名称";Form1->cksendstring2=Form1->infshow2;}
    else if(Form1->cksendback2=="3"){Form1->cksendback2="货号";Form1->cksendstring2=Form1->infshow3;}
    else if(Form1->cksendback2=="4"){Form1->cksendback2="规格";Form1->cksendstring2=Form1->infshow4;}
    else if(Form1->cksendback2=="5"){Form1->cksendback2="型号";Form1->cksendstring2=Form1->infshow5;}
    else if(Form1->cksendback2=="6"){Form1->cksendback2="进价";Form1->cksendstring2=Form1->infshow6;}
    else if(Form1->cksendback2=="7"){Form1->cksendback2="售价";Form1->cksendstring2=Form1->infshow7;}
    else if(Form1->cksendback2=="8"){Form1->cksendback2="单位";Form1->cksendstring2=Form1->infshow8;}
    else if(Form1->cksendback2=="9"){Form1->cksendback2="备注一";Form1->cksendstring2=Form1->infshow9;}
    else if(Form1->cksendback2=="10"){Form1->cksendback2="备注二";Form1->cksendstring2=Form1->infshow10;}
    else if(Form1->cksendback2=="11"){Form1->cksendback2="备注三";Form1->cksendstring2=Form1->infshow11;}
    else {Form1->cksendback2="货号";Form1->cksendstring2=Form1->infshow3;}

    if(Form1->cksendback3=="1"){Form1->cksendback3="条码";Form1->cksendstring3=Form1->infshow1;}
    else if(Form1->cksendback3=="2"){Form1->cksendback3="名称";Form1->cksendstring3=Form1->infshow2;}
    else if(Form1->cksendback3=="3"){Form1->cksendback3="货号";Form1->cksendstring3=Form1->infshow3;}
    else if(Form1->cksendback3=="4"){Form1->cksendback3="规格";Form1->cksendstring3=Form1->infshow4;}
    else if(Form1->cksendback3=="5"){Form1->cksendback3="型号";Form1->cksendstring3=Form1->infshow5;}
    else if(Form1->cksendback3=="6"){Form1->cksendback3="进价";Form1->cksendstring3=Form1->infshow6;}
    else if(Form1->cksendback3=="7"){Form1->cksendback3="售价";Form1->cksendstring3=Form1->infshow7;}
    else if(Form1->cksendback3=="8"){Form1->cksendback3="单位";Form1->cksendstring3=Form1->infshow8;}
    else if(Form1->cksendback3=="9"){Form1->cksendback3="备注一";Form1->cksendstring3=Form1->infshow9;}
    else if(Form1->cksendback3=="10"){Form1->cksendback3="备注二";Form1->cksendstring3=Form1->infshow10;}
    else if(Form1->cksendback3=="11"){Form1->cksendback3="备注三";Form1->cksendstring3=Form1->infshow11;}
    else {Form1->cksendback3="进价";Form1->cksendstring3=Form1->infshow6;}

    if(Form1->cksendback4=="1"){Form1->cksendback4="条码";Form1->cksendstring4=Form1->infshow1;}
    else if(Form1->cksendback4=="2"){Form1->cksendback4="名称";Form1->cksendstring4=Form1->infshow2;}
    else if(Form1->cksendback4=="3"){Form1->cksendback4="货号";Form1->cksendstring4=Form1->infshow3;}
    else if(Form1->cksendback4=="4"){Form1->cksendback4="规格";Form1->cksendstring4=Form1->infshow4;}
    else if(Form1->cksendback4=="5"){Form1->cksendback4="型号";Form1->cksendstring4=Form1->infshow5;}
    else if(Form1->cksendback4=="6"){Form1->cksendback4="进价";Form1->cksendstring4=Form1->infshow6;}
    else if(Form1->cksendback4=="7"){Form1->cksendback4="售价";Form1->cksendstring4=Form1->infshow7;}
    else if(Form1->cksendback4=="8"){Form1->cksendback4="单位";Form1->cksendstring4=Form1->infshow8;}
    else if(Form1->cksendback4=="9"){Form1->cksendback4="备注一";Form1->cksendstring4=Form1->infshow9;}
    else if(Form1->cksendback4=="10"){Form1->cksendback4="备注二";Form1->cksendstring4=Form1->infshow10;}
    else if(Form1->cksendback4=="11"){Form1->cksendback4="备注三";Form1->cksendstring4=Form1->infshow11;}
    else {Form1->cksendback4="售价";Form1->cksendstring4=Form1->infshow7;}

    if(Form1->cksendback5=="1"){Form1->cksendback5="条码";Form1->cksendstring5=Form1->infshow1;}
    else if(Form1->cksendback5=="2"){Form1->cksendback5="名称";Form1->cksendstring5=Form1->infshow2;}
    else if(Form1->cksendback5=="3"){Form1->cksendback5="货号";Form1->cksendstring5=Form1->infshow3;}
    else if(Form1->cksendback5=="4"){Form1->cksendback5="规格";Form1->cksendstring5=Form1->infshow4;}
    else if(Form1->cksendback5=="5"){Form1->cksendback5="型号";Form1->cksendstring5=Form1->infshow5;}
    else if(Form1->cksendback5=="6"){Form1->cksendback5="进价";Form1->cksendstring5=Form1->infshow6;}
    else if(Form1->cksendback5=="7"){Form1->cksendback5="售价";Form1->cksendstring5=Form1->infshow7;}
    else if(Form1->cksendback5=="8"){Form1->cksendback5="单位";Form1->cksendstring5=Form1->infshow8;}
    else if(Form1->cksendback5=="9"){Form1->cksendback5="备注一";Form1->cksendstring5=Form1->infshow9;}
    else if(Form1->cksendback5=="10"){Form1->cksendback5="备注二";Form1->cksendstring5=Form1->infshow10;}
    else if(Form1->cksendback5=="11"){Form1->cksendback5="备注三";Form1->cksendstring5=Form1->infshow11;}
    else {Form1->cksendback5="备注一";Form1->cksendstring5=Form1->infshow9;}


    if(Form1->pdsendback1=="1"){Form1->pdsendback1="条码";Form1->pdsendstring1=Form1->infshow1;}
    else if(Form1->pdsendback1=="2"){Form1->pdsendback1="名称";Form1->pdsendstring1=Form1->infshow2;}
    else if(Form1->pdsendback1=="3"){Form1->pdsendback1="货号";Form1->pdsendstring1=Form1->infshow3;}
    else if(Form1->pdsendback1=="4"){Form1->pdsendback1="规格";Form1->pdsendstring1=Form1->infshow4;}
    else if(Form1->pdsendback1=="5"){Form1->pdsendback1="型号";Form1->pdsendstring1=Form1->infshow5;}
    else if(Form1->pdsendback1=="6"){Form1->pdsendback1="进价";Form1->pdsendstring1=Form1->infshow6;}
    else if(Form1->pdsendback1=="7"){Form1->pdsendback1="售价";Form1->pdsendstring1=Form1->infshow7;}
    else if(Form1->pdsendback1=="8"){Form1->pdsendback1="单位";Form1->pdsendstring1=Form1->infshow8;}
    else if(Form1->pdsendback1=="9"){Form1->pdsendback1="备注一";Form1->pdsendstring1=Form1->infshow9;}
    else if(Form1->pdsendback1=="10"){Form1->pdsendback1="备注二";Form1->pdsendstring1=Form1->infshow10;}
    else if(Form1->pdsendback1=="11"){Form1->pdsendback1="备注三";Form1->pdsendstring1=Form1->infshow11;}
    else {Form1->pdsendback1="名称";Form1->pdsendstring1=Form1->infshow2;}

    if(Form1->pdsendback2=="1"){Form1->pdsendback2="条码";Form1->pdsendstring2=Form1->infshow1;}
    else if(Form1->pdsendback2=="2"){Form1->pdsendback2="名称";Form1->pdsendstring2=Form1->infshow2;}
    else if(Form1->pdsendback2=="3"){Form1->pdsendback2="货号";Form1->pdsendstring2=Form1->infshow3;}
    else if(Form1->pdsendback2=="4"){Form1->pdsendback2="规格";Form1->pdsendstring2=Form1->infshow4;}
    else if(Form1->pdsendback2=="5"){Form1->pdsendback2="型号";Form1->pdsendstring2=Form1->infshow5;}
    else if(Form1->pdsendback2=="6"){Form1->pdsendback2="进价";Form1->pdsendstring2=Form1->infshow6;}
    else if(Form1->pdsendback2=="7"){Form1->pdsendback2="售价";Form1->pdsendstring2=Form1->infshow7;}
    else if(Form1->pdsendback2=="8"){Form1->pdsendback2="单位";Form1->pdsendstring2=Form1->infshow8;}
    else if(Form1->pdsendback2=="9"){Form1->pdsendback2="备注一";Form1->pdsendstring2=Form1->infshow9;}
    else if(Form1->pdsendback2=="10"){Form1->pdsendback2="备注二";Form1->pdsendstring2=Form1->infshow10;}
    else if(Form1->pdsendback2=="11"){Form1->pdsendback2="备注三";Form1->pdsendstring2=Form1->infshow11;}
    else {Form1->pdsendback2="货号";Form1->pdsendstring2=Form1->infshow3;}

    if(Form1->pdsendback3=="1"){Form1->pdsendback3="条码";Form1->pdsendstring3=Form1->infshow1;}
    else if(Form1->pdsendback3=="2"){Form1->pdsendback3="名称";Form1->pdsendstring3=Form1->infshow2;}
    else if(Form1->pdsendback3=="3"){Form1->pdsendback3="货号";Form1->pdsendstring3=Form1->infshow3;}
    else if(Form1->pdsendback3=="4"){Form1->pdsendback3="规格";Form1->pdsendstring3=Form1->infshow4;}
    else if(Form1->pdsendback3=="5"){Form1->pdsendback3="型号";Form1->pdsendstring3=Form1->infshow5;}
    else if(Form1->pdsendback3=="6"){Form1->pdsendback3="进价";Form1->pdsendstring3=Form1->infshow6;}
    else if(Form1->pdsendback3=="7"){Form1->pdsendback3="售价";Form1->pdsendstring3=Form1->infshow7;}
    else if(Form1->pdsendback3=="8"){Form1->pdsendback3="单位";Form1->pdsendstring3=Form1->infshow8;}
    else if(Form1->pdsendback3=="9"){Form1->pdsendback3="备注一";Form1->pdsendstring3=Form1->infshow9;}
    else if(Form1->pdsendback3=="10"){Form1->pdsendback3="备注二";Form1->pdsendstring3=Form1->infshow10;}
    else if(Form1->pdsendback3=="11"){Form1->pdsendback3="备注三";Form1->pdsendstring3=Form1->infshow11;}
    else {Form1->pdsendback3="进价";Form1->pdsendstring3=Form1->infshow6;}

    if(Form1->pdsendback4=="1"){Form1->pdsendback4="条码";Form1->pdsendstring4=Form1->infshow1;}
    else if(Form1->pdsendback4=="2"){Form1->pdsendback4="名称";Form1->pdsendstring4=Form1->infshow2;}
    else if(Form1->pdsendback4=="3"){Form1->pdsendback4="货号";Form1->pdsendstring4=Form1->infshow3;}
    else if(Form1->pdsendback4=="4"){Form1->pdsendback4="规格";Form1->pdsendstring4=Form1->infshow4;}
    else if(Form1->pdsendback4=="5"){Form1->pdsendback4="型号";Form1->pdsendstring4=Form1->infshow5;}
    else if(Form1->pdsendback4=="6"){Form1->pdsendback4="进价";Form1->pdsendstring4=Form1->infshow6;}
    else if(Form1->pdsendback4=="7"){Form1->pdsendback4="售价";Form1->pdsendstring4=Form1->infshow7;}
    else if(Form1->pdsendback4=="8"){Form1->pdsendback4="单位";Form1->pdsendstring4=Form1->infshow8;}
    else if(Form1->pdsendback4=="9"){Form1->pdsendback4="备注一";Form1->pdsendstring4=Form1->infshow9;}
    else if(Form1->pdsendback4=="10"){Form1->pdsendback4="备注二";Form1->pdsendstring4=Form1->infshow10;}
    else if(Form1->pdsendback4=="11"){Form1->pdsendback4="备注三";Form1->pdsendstring4=Form1->infshow11;}
    else {Form1->pdsendback4="售价";Form1->pdsendstring4=Form1->infshow7;}

    if(Form1->pdsendback5=="1"){Form1->pdsendback5="条码";Form1->pdsendstring5=Form1->infshow1;}
    else if(Form1->pdsendback5=="2"){Form1->pdsendback5="名称";Form1->pdsendstring5=Form1->infshow2;}
    else if(Form1->pdsendback5=="3"){Form1->pdsendback5="货号";Form1->pdsendstring5=Form1->infshow3;}
    else if(Form1->pdsendback5=="4"){Form1->pdsendback5="规格";Form1->pdsendstring5=Form1->infshow4;}
    else if(Form1->pdsendback5=="5"){Form1->pdsendback5="型号";Form1->pdsendstring5=Form1->infshow5;}
    else if(Form1->pdsendback5=="6"){Form1->pdsendback5="进价";Form1->pdsendstring5=Form1->infshow6;}
    else if(Form1->pdsendback5=="7"){Form1->pdsendback5="售价";Form1->pdsendstring5=Form1->infshow7;}
    else if(Form1->pdsendback5=="8"){Form1->pdsendback5="单位";Form1->pdsendstring5=Form1->infshow8;}
    else if(Form1->pdsendback5=="9"){Form1->pdsendback5="备注一";Form1->pdsendstring5=Form1->infshow9;}
    else if(Form1->pdsendback5=="10"){Form1->pdsendback5="备注二";Form1->pdsendstring5=Form1->infshow10;}
    else if(Form1->pdsendback5=="11"){Form1->pdsendback5="备注三";Form1->pdsendstring5=Form1->infshow11;}
    else {Form1->pdsendback5="备注一";Form1->pdsendstring5=Form1->infshow9;}


    if(Form1->ydsendback1=="1"){Form1->ydsendback1="条码";Form1->ydsendstring1=Form1->infshow1;}
    else if(Form1->ydsendback1=="2"){Form1->ydsendback1="名称";Form1->ydsendstring1=Form1->infshow2;}
    else if(Form1->ydsendback1=="3"){Form1->ydsendback1="货号";Form1->ydsendstring1=Form1->infshow3;}
    else if(Form1->ydsendback1=="4"){Form1->ydsendback1="规格";Form1->ydsendstring1=Form1->infshow4;}
    else if(Form1->ydsendback1=="5"){Form1->ydsendback1="型号";Form1->ydsendstring1=Form1->infshow5;}
    else if(Form1->ydsendback1=="6"){Form1->ydsendback1="进价";Form1->ydsendstring1=Form1->infshow6;}
    else if(Form1->ydsendback1=="7"){Form1->ydsendback1="售价";Form1->ydsendstring1=Form1->infshow7;}
    else if(Form1->ydsendback1=="8"){Form1->ydsendback1="单位";Form1->ydsendstring1=Form1->infshow8;}
    else if(Form1->ydsendback1=="9"){Form1->ydsendback1="备注一";Form1->ydsendstring1=Form1->infshow9;}
    else if(Form1->ydsendback1=="10"){Form1->ydsendback1="备注二";Form1->ydsendstring1=Form1->infshow10;}
    else if(Form1->ydsendback1=="11"){Form1->ydsendback1="备注三";Form1->ydsendstring1=Form1->infshow11;}
    else {Form1->ydsendback1="名称";Form1->ydsendstring1=Form1->infshow2;}

    if(Form1->ydsendback2=="1"){Form1->ydsendback2="条码";Form1->ydsendstring2=Form1->infshow1;}
    else if(Form1->ydsendback2=="2"){Form1->ydsendback2="名称";Form1->ydsendstring2=Form1->infshow2;}
    else if(Form1->ydsendback2=="3"){Form1->ydsendback2="货号";Form1->ydsendstring2=Form1->infshow3;}
    else if(Form1->ydsendback2=="4"){Form1->ydsendback2="规格";Form1->ydsendstring2=Form1->infshow4;}
    else if(Form1->ydsendback2=="5"){Form1->ydsendback2="型号";Form1->ydsendstring2=Form1->infshow5;}
    else if(Form1->ydsendback2=="6"){Form1->ydsendback2="进价";Form1->ydsendstring2=Form1->infshow6;}
    else if(Form1->ydsendback2=="7"){Form1->ydsendback2="售价";Form1->ydsendstring2=Form1->infshow7;}
    else if(Form1->ydsendback2=="8"){Form1->ydsendback2="单位";Form1->ydsendstring2=Form1->infshow8;}
    else if(Form1->ydsendback2=="9"){Form1->ydsendback2="备注一";Form1->ydsendstring2=Form1->infshow9;}
    else if(Form1->ydsendback2=="10"){Form1->ydsendback2="备注二";Form1->ydsendstring2=Form1->infshow10;}
    else if(Form1->ydsendback2=="11"){Form1->ydsendback2="备注三";Form1->ydsendstring2=Form1->infshow11;}
    else {Form1->ydsendback2="货号";Form1->ydsendstring2=Form1->infshow3;}

    if(Form1->ydsendback3=="1"){Form1->ydsendback3="条码";Form1->ydsendstring3=Form1->infshow1;}
    else if(Form1->ydsendback3=="2"){Form1->ydsendback3="名称";Form1->ydsendstring3=Form1->infshow2;}
    else if(Form1->ydsendback3=="3"){Form1->ydsendback3="货号";Form1->ydsendstring3=Form1->infshow3;}
    else if(Form1->ydsendback3=="4"){Form1->ydsendback3="规格";Form1->ydsendstring3=Form1->infshow4;}
    else if(Form1->ydsendback3=="5"){Form1->ydsendback3="型号";Form1->ydsendstring3=Form1->infshow5;}
    else if(Form1->ydsendback3=="6"){Form1->ydsendback3="进价";Form1->ydsendstring3=Form1->infshow6;}
    else if(Form1->ydsendback3=="7"){Form1->ydsendback3="售价";Form1->ydsendstring3=Form1->infshow7;}
    else if(Form1->ydsendback3=="8"){Form1->ydsendback3="单位";Form1->ydsendstring3=Form1->infshow8;}
    else if(Form1->ydsendback3=="9"){Form1->ydsendback3="备注一";Form1->ydsendstring3=Form1->infshow9;}
    else if(Form1->ydsendback3=="10"){Form1->ydsendback3="备注二";Form1->ydsendstring3=Form1->infshow10;}
    else if(Form1->ydsendback3=="11"){Form1->ydsendback3="备注三";Form1->ydsendstring3=Form1->infshow11;}
    else {Form1->ydsendback3="进价";Form1->ydsendstring3=Form1->infshow6;}

    if(Form1->ydsendback4=="1"){Form1->ydsendback4="条码";Form1->ydsendstring4=Form1->infshow1;}
    else if(Form1->ydsendback4=="2"){Form1->ydsendback4="名称";Form1->ydsendstring4=Form1->infshow2;}
    else if(Form1->ydsendback4=="3"){Form1->ydsendback4="货号";Form1->ydsendstring4=Form1->infshow3;}
    else if(Form1->ydsendback4=="4"){Form1->ydsendback4="规格";Form1->ydsendstring4=Form1->infshow4;}
    else if(Form1->ydsendback4=="5"){Form1->ydsendback4="型号";Form1->ydsendstring4=Form1->infshow5;}
    else if(Form1->ydsendback4=="6"){Form1->ydsendback4="进价";Form1->ydsendstring4=Form1->infshow6;}
    else if(Form1->ydsendback4=="7"){Form1->ydsendback4="售价";Form1->ydsendstring4=Form1->infshow7;}
    else if(Form1->ydsendback4=="8"){Form1->ydsendback4="单位";Form1->ydsendstring4=Form1->infshow8;}
    else if(Form1->ydsendback4=="9"){Form1->ydsendback4="备注一";Form1->ydsendstring4=Form1->infshow9;}
    else if(Form1->ydsendback4=="10"){Form1->ydsendback4="备注二";Form1->ydsendstring4=Form1->infshow10;}
    else if(Form1->ydsendback4=="11"){Form1->ydsendback4="备注三";Form1->ydsendstring4=Form1->infshow11;}
    else {Form1->ydsendback4="售价";Form1->ydsendstring4=Form1->infshow7;}

    if(Form1->ydsendback5=="1"){Form1->ydsendback5="条码";Form1->ydsendstring5=Form1->infshow1;}
    else if(Form1->ydsendback5=="2"){Form1->ydsendback5="名称";Form1->ydsendstring5=Form1->infshow2;}
    else if(Form1->ydsendback5=="3"){Form1->ydsendback5="货号";Form1->ydsendstring5=Form1->infshow3;}
    else if(Form1->ydsendback5=="4"){Form1->ydsendback5="规格";Form1->ydsendstring5=Form1->infshow4;}
    else if(Form1->ydsendback5=="5"){Form1->ydsendback5="型号";Form1->ydsendstring5=Form1->infshow5;}
    else if(Form1->ydsendback5=="6"){Form1->ydsendback5="进价";Form1->ydsendstring5=Form1->infshow6;}
    else if(Form1->ydsendback5=="7"){Form1->ydsendback5="售价";Form1->ydsendstring5=Form1->infshow7;}
    else if(Form1->ydsendback5=="8"){Form1->ydsendback5="单位";Form1->ydsendstring5=Form1->infshow8;}
    else if(Form1->ydsendback5=="9"){Form1->ydsendback5="备注一";Form1->ydsendstring5=Form1->infshow9;}
    else if(Form1->ydsendback5=="10"){Form1->ydsendback5="备注二";Form1->ydsendstring5=Form1->infshow10;}
    else if(Form1->ydsendback5=="11"){Form1->ydsendback5="备注三";Form1->ydsendstring5=Form1->infshow11;}
    else {Form1->ydsendback5="备注一";Form1->ydsendstring5=Form1->infshow9;}


    if(Form1->yksendback1=="1"){Form1->yksendback1="条码";Form1->yksendstring1=Form1->infshow1;}
    else if(Form1->yksendback1=="2"){Form1->yksendback1="名称";Form1->yksendstring1=Form1->infshow2;}
    else if(Form1->yksendback1=="3"){Form1->yksendback1="货号";Form1->yksendstring1=Form1->infshow3;}
    else if(Form1->yksendback1=="4"){Form1->yksendback1="规格";Form1->yksendstring1=Form1->infshow4;}
    else if(Form1->yksendback1=="5"){Form1->yksendback1="型号";Form1->yksendstring1=Form1->infshow5;}
    else if(Form1->yksendback1=="6"){Form1->yksendback1="进价";Form1->yksendstring1=Form1->infshow6;}
    else if(Form1->yksendback1=="7"){Form1->yksendback1="售价";Form1->yksendstring1=Form1->infshow7;}
    else if(Form1->yksendback1=="8"){Form1->yksendback1="单位";Form1->yksendstring1=Form1->infshow8;}
    else if(Form1->yksendback1=="9"){Form1->yksendback1="备注一";Form1->yksendstring1=Form1->infshow9;}
    else if(Form1->yksendback1=="10"){Form1->yksendback1="备注二";Form1->yksendstring1=Form1->infshow10;}
    else if(Form1->yksendback1=="11"){Form1->yksendback1="备注三";Form1->yksendstring1=Form1->infshow11;}
    else {Form1->yksendback1="名称";Form1->yksendstring1=Form1->infshow2;}

    if(Form1->yksendback2=="1"){Form1->yksendback2="条码";Form1->yksendstring2=Form1->infshow1;}
    else if(Form1->yksendback2=="2"){Form1->yksendback2="名称";Form1->yksendstring2=Form1->infshow2;}
    else if(Form1->yksendback2=="3"){Form1->yksendback2="货号";Form1->yksendstring2=Form1->infshow3;}
    else if(Form1->yksendback2=="4"){Form1->yksendback2="规格";Form1->yksendstring2=Form1->infshow4;}
    else if(Form1->yksendback2=="5"){Form1->yksendback2="型号";Form1->yksendstring2=Form1->infshow5;}
    else if(Form1->yksendback2=="6"){Form1->yksendback2="进价";Form1->yksendstring2=Form1->infshow6;}
    else if(Form1->yksendback2=="7"){Form1->yksendback2="售价";Form1->yksendstring2=Form1->infshow7;}
    else if(Form1->yksendback2=="8"){Form1->yksendback2="单位";Form1->yksendstring2=Form1->infshow8;}
    else if(Form1->yksendback2=="9"){Form1->yksendback2="备注一";Form1->yksendstring2=Form1->infshow9;}
    else if(Form1->yksendback2=="10"){Form1->yksendback2="备注二";Form1->yksendstring2=Form1->infshow10;}
    else if(Form1->yksendback2=="11"){Form1->yksendback2="备注三";Form1->yksendstring2=Form1->infshow11;}
    else {Form1->yksendback2="货号";Form1->yksendstring2=Form1->infshow3;}

    if(Form1->yksendback3=="1"){Form1->yksendback3="条码";Form1->yksendstring3=Form1->infshow1;}
    else if(Form1->yksendback3=="2"){Form1->yksendback3="名称";Form1->yksendstring3=Form1->infshow2;}
    else if(Form1->yksendback3=="3"){Form1->yksendback3="货号";Form1->yksendstring3=Form1->infshow3;}
    else if(Form1->yksendback3=="4"){Form1->yksendback3="规格";Form1->yksendstring3=Form1->infshow4;}
    else if(Form1->yksendback3=="5"){Form1->yksendback3="型号";Form1->yksendstring3=Form1->infshow5;}
    else if(Form1->yksendback3=="6"){Form1->yksendback3="进价";Form1->yksendstring3=Form1->infshow6;}
    else if(Form1->yksendback3=="7"){Form1->yksendback3="售价";Form1->yksendstring3=Form1->infshow7;}
    else if(Form1->yksendback3=="8"){Form1->yksendback3="单位";Form1->yksendstring3=Form1->infshow8;}
    else if(Form1->yksendback3=="9"){Form1->yksendback3="备注一";Form1->yksendstring3=Form1->infshow9;}
    else if(Form1->yksendback3=="10"){Form1->yksendback3="备注二";Form1->yksendstring3=Form1->infshow10;}
    else if(Form1->yksendback3=="11"){Form1->yksendback3="备注三";Form1->yksendstring3=Form1->infshow11;}
    else {Form1->yksendback3="进价";Form1->yksendstring3=Form1->infshow6;}

    if(Form1->yksendback4=="1"){Form1->yksendback4="条码";Form1->yksendstring4=Form1->infshow1;}
    else if(Form1->yksendback4=="2"){Form1->yksendback4="名称";Form1->yksendstring4=Form1->infshow2;}
    else if(Form1->yksendback4=="3"){Form1->yksendback4="货号";Form1->yksendstring4=Form1->infshow3;}
    else if(Form1->yksendback4=="4"){Form1->yksendback4="规格";Form1->yksendstring4=Form1->infshow4;}
    else if(Form1->yksendback4=="5"){Form1->yksendback4="型号";Form1->yksendstring4=Form1->infshow5;}
    else if(Form1->yksendback4=="6"){Form1->yksendback4="进价";Form1->yksendstring4=Form1->infshow6;}
    else if(Form1->yksendback4=="7"){Form1->yksendback4="售价";Form1->yksendstring4=Form1->infshow7;}
    else if(Form1->yksendback4=="8"){Form1->yksendback4="单位";Form1->yksendstring4=Form1->infshow8;}
    else if(Form1->yksendback4=="9"){Form1->yksendback4="备注一";Form1->yksendstring4=Form1->infshow9;}
    else if(Form1->yksendback4=="10"){Form1->yksendback4="备注二";Form1->yksendstring4=Form1->infshow10;}
    else if(Form1->yksendback4=="11"){Form1->yksendback4="备注三";Form1->yksendstring4=Form1->infshow11;}
    else {Form1->yksendback4="售价";Form1->yksendstring4=Form1->infshow7;}

    if(Form1->yksendback5=="1"){Form1->yksendback5="条码";Form1->yksendstring5=Form1->infshow1;}
    else if(Form1->yksendback5=="2"){Form1->yksendback5="名称";Form1->yksendstring5=Form1->infshow2;}
    else if(Form1->yksendback5=="3"){Form1->yksendback5="货号";Form1->yksendstring5=Form1->infshow3;}
    else if(Form1->yksendback5=="4"){Form1->yksendback5="规格";Form1->yksendstring5=Form1->infshow4;}
    else if(Form1->yksendback5=="5"){Form1->yksendback5="型号";Form1->yksendstring5=Form1->infshow5;}
    else if(Form1->yksendback5=="6"){Form1->yksendback5="进价";Form1->yksendstring5=Form1->infshow6;}
    else if(Form1->yksendback5=="7"){Form1->yksendback5="售价";Form1->yksendstring5=Form1->infshow7;}
    else if(Form1->yksendback5=="8"){Form1->yksendback5="单位";Form1->yksendstring5=Form1->infshow8;}
    else if(Form1->yksendback5=="9"){Form1->yksendback5="备注一";Form1->yksendstring5=Form1->infshow9;}
    else if(Form1->yksendback5=="10"){Form1->yksendback5="备注二";Form1->yksendstring5=Form1->infshow10;}
    else if(Form1->yksendback5=="11"){Form1->yksendback5="备注三";Form1->yksendstring5=Form1->infshow11;}
    else {Form1->yksendback5="备注一";Form1->yksendstring5=Form1->infshow9;}




     delete ini;

     if(mrYes!=MessageDlg("设置成功，是否生成商品资料导入模板？",mtInformation,TMsgDlgButtons()<<mbYes<<mbNo,0))
     {
            return;
     }
     else
     {
         TStringList *SaveList=new TStringList();
         
         SaveList->Text="";
         SaveList->Add(Form1->infshow1+"\t"+Form1->infshow2+"\t"+Form1->infshow3+"\t"+Form1->infshow4+"\t"+Form1->infshow5+"\t"+Form1->infshow6+"\t"+Form1->infshow7+"\t"+Form1->infshow8+"\t"+Form1->infshow9+"\t"+Form1->infshow10+"\t"+Form1->infshow11);
         SaveList->SaveToFile("商品资料.txt") ;

         SaveList->Text="";
         SaveList->Add("JBZL,");
         Form1->SaveExcel(SaveList,ExtractFilePath(Application->ExeName)+"商品资料.xls") ;


         delete SaveList;
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm18::FormShow(TObject *Sender)
{
     Edit1->Text=Form1->infshow1;
     Edit2->Text=Form1->infshow2;
     Edit3->Text=Form1->infshow3;
     Edit4->Text=Form1->infshow4;
     Edit5->Text=Form1->infshow5;
     Edit6->Text=Form1->infshow6;
     Edit7->Text=Form1->infshow7;
     Edit8->Text=Form1->infshow8;
     Edit9->Text=Form1->infshow9;
     Edit10->Text=Form1->infshow10;
     Edit11->Text=Form1->infshow11;

     TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");



     ComboBox1->ItemIndex=ini->ReadString("Sys","rksendback1","2").ToInt()-1;
     ComboBox2->ItemIndex=ini->ReadString("Sys","rksendback2","3").ToInt()-1;
     ComboBox3->ItemIndex=ini->ReadString("Sys","rksendback3","6").ToInt()-1;
     ComboBox4->ItemIndex=ini->ReadString("Sys","rksendback4","7").ToInt()-1;
     ComboBox5->ItemIndex=ini->ReadString("Sys","rksendback5","9").ToInt()-1;

     ComboBox6->ItemIndex=ini->ReadString("Sys","cksendback1","2").ToInt()-1;
     ComboBox7->ItemIndex=ini->ReadString("Sys","cksendback2","3").ToInt()-1;
     ComboBox8->ItemIndex=ini->ReadString("Sys","cksendback3","6").ToInt()-1;
     ComboBox9->ItemIndex=ini->ReadString("Sys","cksendback4","7").ToInt()-1;
     ComboBox10->ItemIndex=ini->ReadString("Sys","cksendback5","9").ToInt()-1;

     ComboBox11->ItemIndex=ini->ReadString("Sys","pdsendback1","2").ToInt()-1;
     ComboBox12->ItemIndex=ini->ReadString("Sys","pdsendback2","3").ToInt()-1;
     ComboBox13->ItemIndex=ini->ReadString("Sys","pdsendback3","6").ToInt()-1;
     ComboBox14->ItemIndex=ini->ReadString("Sys","pdsendback4","7").ToInt()-1;
     ComboBox15->ItemIndex=ini->ReadString("Sys","pdsendback5","9").ToInt()-1;

     ComboBox16->ItemIndex=ini->ReadString("Sys","ydsendback1","2").ToInt()-1;
     ComboBox17->ItemIndex=ini->ReadString("Sys","ydsendback2","3").ToInt()-1;
     ComboBox18->ItemIndex=ini->ReadString("Sys","ydsendback3","6").ToInt()-1;
     ComboBox19->ItemIndex=ini->ReadString("Sys","ydsendback4","7").ToInt()-1;
     ComboBox20->ItemIndex=ini->ReadString("Sys","ydsendback5","9").ToInt()-1;

     ComboBox21->ItemIndex=ini->ReadString("Sys","yksendback1","2").ToInt()-1;
     ComboBox22->ItemIndex=ini->ReadString("Sys","yksendback2","3").ToInt()-1;
     ComboBox23->ItemIndex=ini->ReadString("Sys","yksendback3","6").ToInt()-1;
     ComboBox24->ItemIndex=ini->ReadString("Sys","yksendback4","7").ToInt()-1;
     ComboBox25->ItemIndex=ini->ReadString("Sys","yksendback5","9").ToInt()-1;

     Edit12->Text= ini->ReadString("Sys","RK1","2*6");
     ComboBox26->ItemIndex=ini->ReadString("Sys","RK2","6").ToInt()-1;
     Edit14->Text= ini->ReadString("Sys","RK3","广州润山信息科技有限公司");

     Edit13->Text= ini->ReadString("Sys","CK1","2*7");
     ComboBox27->ItemIndex=ini->ReadString("Sys","CK2","7").ToInt()-1;
     Edit15->Text= ini->ReadString("Sys","CK3","广州润山信息科技有限公司");

     Edit16->Text= ini->ReadString("Sys","YK3","广州润山信息科技有限公司");

     Edit17->Text= ini->ReadString("Sys","YD3","广州润山信息科技有限公司");

     Edit18->Text= ini->ReadString("Sys","PD3","广州润山信息科技有限公司");


     delete ini;

}
//---------------------------------------------------------------------------



