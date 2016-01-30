//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include   <inifiles.hpp>
#include <FileCtrl.hpp>

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//String LoginName="";
String serialstr="";
String passwordstr="";
String tria="1";


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}



static unsigned char Encryptedcard[16][16]={
					   {0xa3,0xe4,0x9b,0x2e,0x3d,0x88,0x5b,0x6a,0x72,0x88,0x59,0x27,0xf6,0x62,0x08,0xbb},
                                           {0xb3,0x55,0x0b,0x85,0xe8,0x4b,0x7f,0x15,0xc6,0x96,0x23,0x6c,0x36,0xdd,0x5e,0xf7},
                                           {0xab,0x66,0x06,0xc7,0x54,0xf8,0x27,0x8b,0x35,0xaf,0x48,0xe7,0xbe,0xd9,0x27,0x9d},
	                                   {0x35,0x22,0xa8,0x45,0x56,0x68,0x19,0xb6,0xc4,0xf8,0x88,0x3e,0x9d,0xdf,0xeb,0x0a},
                                           {0x6c,0x05,0x63,0xa7,0x28,0xc7,0x7f,0xe5,0x1a,0xd7,0x86,0xf6,0x95,0x3e,0xb8,0x4d},
					   {0x95,0xb6,0xa7,0x8c,0x27,0x7e,0x6f,0xc8,0x52,0x49,0x37,0xe5,0x23,0x12,0x03,0xf8},
				           {0x56,0xc3,0x64,0x46,0x76,0x8b,0x94,0x2c,0xa9,0xb4,0x3d,0xc7,0xfe,0x1f,0xd8,0xe4},
                                           {0xc3,0x78,0x1f,0x3d,0x88,0x16,0x7c,0x4f,0xce,0x54,0x93,0xa6,0xb7,0xc3,0xd2,0xe3},
                                           {0x0c,0xf2,0x77,0xcf,0x69,0x5c,0xef,0x47,0xb4,0x35,0x27,0xd4,0x86,0xe3,0xf8,0x15},
					   {0xd7,0x57,0xa3,0xb4,0xc7,0xf7,0xe6,0xdd,0x2d,0x4e,0x1c,0x0f,0x9b,0x69,0x70,0x8a},
					   {0x35,0x4a,0x0c,0x2d,0x1a,0x0b,0xee,0x9f,0xd1,0x86,0x75,0x66,0x5d,0xf5,0xa6,0x48},
					   {0xf6,0x97,0x17,0x2d,0x3e,0x4f,0x5a,0x6b,0x78,0x58,0x95,0xa7,0xb4,0xc4,0xd3,0xe3},
					   {0x8f,0xd4,0x04,0xc7,0x56,0xf5,0x28,0x88,0x37,0xa7,0x98,0xe8,0xbf,0xd1,0x7d,0x9e},
                                           {0xe4,0x6e,0xd8,0x85,0x77,0xaa,0xb0,0x39,0xc6,0xb6,0x68,0x2c,0xf7,0xa5,0x46,0x35},
					   {0xe6,0x47,0xa3,0x0b,0x86,0xe7,0x4c,0x75,0x16,0xc7,0x97,0x29,0x7e,0x8e,0xde,0x5f},
                                           {0x43,0x88,0x1a,0xe6,0x4d,0x97,0x25,0x8c,0x5f,0xde,0x68,0x33,0x06,0x72,0x18,0x8e} };


//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
   
     Search_ADOQuery->Close();
     Search_ADOQuery->SQL->Clear();
     Search_ADOQuery->SQL->Add("SELECT * FROM ZC where ���к� like \"23d5f7eab74g\"");
     Search_ADOQuery->Active= true;

     if(Search_ADOQuery->RecordCount==0)
     {
         Pshow="unshow";
     }
     else
     {
         if(Search_ADOQuery->FieldByName("ע����")->AsString.Trim()=="a3c5-67ff-3f5d")
         Pshow="show";
         else Pshow="unshow";
     }

     Search_ADOQuery->Close();
     Search_ADOQuery->SQL->Clear();
     Search_ADOQuery->SQL->Add("SELECT * FROM ZC where ���к� like \"23d5f7eab74h\"");
     Search_ADOQuery->Active= true;

     if(Search_ADOQuery->RecordCount==0)
     {
         KCshow="unshow";
     }
     else
     {
         if(Search_ADOQuery->FieldByName("ע����")->AsString.Trim()=="a3c5-67ff-3f5d")
         KCshow="show";
         else KCshow="unshow";
     }


     if(name->Text.Trim().Length()==0)
     {
         ShowMessage("�û�������Ϊ�գ�");
         name->SetFocus();
         return;
     }
     if(password->Text.Trim().Length()==0)
     {
         ShowMessage("���벻��Ϊ�գ�");
         password->SetFocus();
         return;
     }

     Search_ADOQuery->Close();
     Search_ADOQuery->SQL->Clear();
     Search_ADOQuery->SQL->Add("SELECT * FROM YG where Ա����� like \""+name->Text.Trim()+"\"");
     Search_ADOQuery->Active= true;

     if(Search_ADOQuery->FieldByName("����")->AsString.Trim()!=password->Text.Trim())
     {
         ShowMessage("�������û�����ƥ�䣬���������룡");
         return;
     }
     LoginName="";
     LoginName= name->Text.Trim();

     if(LoginName=="01")
     {
         Pshow="show";
         KCshow="show";
     }

     RK_ADOQuery->Close();
     RK_ADOQuery->SQL->Clear();
     RK_ADOQuery->SQL->Add("SELECT * FROM ���");
     RK_ADOQuery->Active= true;

     RK_ADOTable->TableName = "RK";
     RK_ADOTable->Open();

     KC_ADOQuery->Close();
     KC_ADOQuery->SQL->Clear();
     KC_ADOQuery->SQL->Add("SELECT * FROM ���");
     KC_ADOQuery->Active= true;

     KC_ADOTable->TableName = "KC";
     KC_ADOTable->Open();

     CK_ADOQuery->Close();
     CK_ADOQuery->SQL->Clear();
     CK_ADOQuery->SQL->Add("SELECT * FROM ����");
     CK_ADOQuery->Active= true;

     CK_ADOTable->TableName = "CK";
     CK_ADOTable->Open();

     PD_ADOQuery->Close();
     PD_ADOQuery->SQL->Clear();
     PD_ADOQuery->SQL->Add("SELECT * FROM �̵�");
     PD_ADOQuery->Active= true;

     PD_ADOTable->TableName = "PD";
     PD_ADOTable->Open();

     PDTJ_ADOQuery->Close();
     PDTJ_ADOQuery->SQL->Clear();
     PDTJ_ADOQuery->SQL->Add("SELECT * FROM �̵�ͳ��");
     PDTJ_ADOQuery->Active= true;

     PDTJ_ADOTable->TableName = "PDTJ";
     PDTJ_ADOTable->Open();

     YK_ADOQuery->Close();
     YK_ADOQuery->SQL->Clear();
     YK_ADOQuery->SQL->Add("SELECT * FROM �ƿ�");
     YK_ADOQuery->Active= true;

     YK_ADOTable->TableName = "YK";
     YK_ADOTable->Open();

     YD_ADOQuery->Close();
     YD_ADOQuery->SQL->Clear();
     YD_ADOQuery->SQL->Add("SELECT * FROM �鵥");
     YD_ADOQuery->Active= true;

     YD_ADOTable->TableName = "YD";
     YD_ADOTable->Open();

     ADOQuery1->Close();
     ADOQuery1->SQL->Clear();
     ADOQuery1->SQL->Add("SELECT * FROM JBZL");
     ADOQuery1->Active= true;


     ADOTable1->TableName = "JBZL";
     ADOTable1->Open();

     YG_ADOQuery->Close();
     YG_ADOQuery->SQL->Clear();
     YG_ADOQuery->SQL->Add("SELECT * FROM YG");
     YG_ADOQuery->Active= true;

     YG_ADOTable->TableName = "YG";
     YG_ADOTable->Open();

     XSTJ_ADOQuery->Close();
     XSTJ_ADOQuery->SQL->Clear();
     XSTJ_ADOQuery->SQL->Add("SELECT * FROM ����ͳ��");
     XSTJ_ADOQuery->Active= true;

     XSTJ_ADOTable->TableName = "XSTJ";
     XSTJ_ADOTable->Open();

     //DL_ADOTable->TableName = "DL";
    // DL_ADOTable->Open();

     ZC_ADOTable->TableName = "ZC";
     ZC_ADOTable->Open();

     Form2->Show();
     Form1->Hide();


}
//---------------------------------------------------------------------------


//--------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
    TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
    String password=";Jet OLEDB:Database Password="+ini->ReadString("Sys","password","rsa1314")+";Data Source=";

    ADOConnection1->Close();
    AnsiString ConnectionString, accPath;
    ConnectionString = "Provider=Microsoft Jet 4.0 OLE DB Provider"+password;
    accPath = ExtractFilePath(Application->ExeName)+"JXC.mdb";
    if(FileExists(accPath))
    {
        accPath += ";Persist Security Info=False";
        ConnectionString +=  accPath;
        ADOConnection1->ConnectionString = ConnectionString;
        ADOConnection1->Open();
        if(ADOConnection1->Connected)
        {
          //  ShowMessage("���ݿ����ӳɹ�..");

        }
        else
        {
            ShowMessage("���ݿ����Ӵ���");
        }
        ADOConnection1->Close();
    }
    else
    {
         ShowMessage("���ݿ��ļ�������");
        // return ;
    }

    //������ʾ����
    infshow1="����";
    infshow2=ini->ReadString("Sys","inf2","����");
    infshow3=ini->ReadString("Sys","inf3","����");
    infshow4=ini->ReadString("Sys","inf4","���");
    infshow5=ini->ReadString("Sys","inf5","�ͺ�");
    infshow6="����";
    infshow7="�ۼ�";
    infshow8=ini->ReadString("Sys","inf8","��λ");
    infshow9=ini->ReadString("Sys","inf9","��עһ");
    infshow10=ini->ReadString("Sys","inf10","��ע��");
    infshow11=ini->ReadString("Sys","inf11","��ע��");


    rksendback1=ini->ReadString("Sys","rksendback1","2");
    rksendback2=ini->ReadString("Sys","rksendback2","3");
    rksendback3=ini->ReadString("Sys","rksendback3","6");
    rksendback4=ini->ReadString("Sys","rksendback4","7");
    rksendback5=ini->ReadString("Sys","rksendback5","9");
    if(rksendback1=="1"){rksendback1="����";rksendstring1=infshow1;}
    else if(rksendback1=="2"){rksendback1="����";rksendstring1=infshow2;}
    else if(rksendback1=="3"){rksendback1="����";rksendstring1=infshow3;}
    else if(rksendback1=="4"){rksendback1="���";rksendstring1=infshow4;}
    else if(rksendback1=="5"){rksendback1="�ͺ�";rksendstring1=infshow5;}
    else if(rksendback1=="6"){rksendback1="����";rksendstring1=infshow6;}
    else if(rksendback1=="7"){rksendback1="�ۼ�";rksendstring1=infshow7;}
    else if(rksendback1=="8"){rksendback1="��λ";rksendstring1=infshow8;}
    else if(rksendback1=="9"){rksendback1="��עһ";rksendstring1=infshow9;}
    else if(rksendback1=="10"){rksendback1="��ע��";rksendstring1=infshow10;}
    else if(rksendback1=="11"){rksendback1="��ע��";rksendstring1=infshow11;}
    else {rksendback1="����";rksendstring1=infshow2;}

    if(rksendback2=="1"){rksendback2="����";rksendstring2=infshow1;}
    else if(rksendback2=="2"){rksendback2="����";rksendstring2=infshow2;}
    else if(rksendback2=="3"){rksendback2="����";rksendstring2=infshow3;}
    else if(rksendback2=="4"){rksendback2="���";rksendstring2=infshow4;}
    else if(rksendback2=="5"){rksendback2="�ͺ�";rksendstring2=infshow5;}
    else if(rksendback2=="6"){rksendback2="����";rksendstring2=infshow6;}
    else if(rksendback2=="7"){rksendback2="�ۼ�";rksendstring2=infshow7;}
    else if(rksendback2=="8"){rksendback2="��λ";rksendstring2=infshow8;}
    else if(rksendback2=="9"){rksendback2="��עһ";rksendstring2=infshow9;}
    else if(rksendback2=="10"){rksendback2="��ע��";rksendstring2=infshow10;}
    else if(rksendback2=="11"){rksendback2="��ע��";rksendstring2=infshow11;}
    else {rksendback2="����";rksendstring2=infshow3;}

    if(rksendback3=="1"){rksendback3="����";rksendstring3=infshow1;}
    else if(rksendback3=="2"){rksendback3="����";rksendstring3=infshow2;}
    else if(rksendback3=="3"){rksendback3="����";rksendstring3=infshow3;}
    else if(rksendback3=="4"){rksendback3="���";rksendstring3=infshow4;}
    else if(rksendback3=="5"){rksendback3="�ͺ�";rksendstring3=infshow5;}
    else if(rksendback3=="6"){rksendback3="����";rksendstring3=infshow6;}
    else if(rksendback3=="7"){rksendback3="�ۼ�";rksendstring3=infshow7;}
    else if(rksendback3=="8"){rksendback3="��λ";rksendstring3=infshow8;}
    else if(rksendback3=="9"){rksendback3="��עһ";rksendstring3=infshow9;}
    else if(rksendback3=="10"){rksendback3="��ע��";rksendstring3=infshow10;}
    else if(rksendback3=="11"){rksendback3="��ע��";rksendstring3=infshow11;}
    else {rksendback3="����";rksendstring3=infshow6;}

    if(rksendback4=="1"){rksendback4="����";rksendstring4=infshow1;}
    else if(rksendback4=="2"){rksendback4="����";rksendstring4=infshow2;}
    else if(rksendback4=="3"){rksendback4="����";rksendstring4=infshow3;}
    else if(rksendback4=="4"){rksendback4="���";rksendstring4=infshow4;}
    else if(rksendback4=="5"){rksendback4="�ͺ�";rksendstring4=infshow5;}
    else if(rksendback4=="6"){rksendback4="����";rksendstring4=infshow6;}
    else if(rksendback4=="7"){rksendback4="�ۼ�";rksendstring4=infshow7;}
    else if(rksendback4=="8"){rksendback4="��λ";rksendstring4=infshow8;}
    else if(rksendback4=="9"){rksendback4="��עһ";rksendstring4=infshow9;}
    else if(rksendback4=="10"){rksendback4="��ע��";rksendstring4=infshow10;}
    else if(rksendback4=="11"){rksendback4="��ע��";rksendstring4=infshow11;}
    else {rksendback4="�ۼ�";rksendstring4=infshow7;}

    if(rksendback5=="1"){rksendback5="����";rksendstring5=infshow1;}
    else if(rksendback5=="2"){rksendback5="����";rksendstring5=infshow2;}
    else if(rksendback5=="3"){rksendback5="����";rksendstring5=infshow3;}
    else if(rksendback5=="4"){rksendback5="���";rksendstring5=infshow4;}
    else if(rksendback5=="5"){rksendback5="�ͺ�";rksendstring5=infshow5;}
    else if(rksendback5=="6"){rksendback5="����";rksendstring5=infshow6;}
    else if(rksendback5=="7"){rksendback5="�ۼ�";rksendstring5=infshow7;}
    else if(rksendback5=="8"){rksendback5="��λ";rksendstring5=infshow8;}
    else if(rksendback5=="9"){rksendback5="��עһ";rksendstring5=infshow9;}
    else if(rksendback5=="10"){rksendback5="��ע��";rksendstring5=infshow10;}
    else if(rksendback5=="11"){rksendback5="��ע��";rksendstring5=infshow11;}
    else {rksendback5="��עһ";rksendstring5=infshow9;}

    cksendback1=ini->ReadString("Sys","cksendback1","2");
    cksendback2=ini->ReadString("Sys","cksendback2","3");
    cksendback3=ini->ReadString("Sys","cksendback3","6");
    cksendback4=ini->ReadString("Sys","cksendback4","7");
    cksendback5=ini->ReadString("Sys","cksendback5","9");
    if(cksendback1=="1"){cksendback1="����";cksendstring1=infshow1;}
    else if(cksendback1=="2"){cksendback1="����";cksendstring1=infshow2;}
    else if(cksendback1=="3"){cksendback1="����";cksendstring1=infshow3;}
    else if(cksendback1=="4"){cksendback1="���";cksendstring1=infshow4;}
    else if(cksendback1=="5"){cksendback1="�ͺ�";cksendstring1=infshow5;}
    else if(cksendback1=="6"){cksendback1="����";cksendstring1=infshow6;}
    else if(cksendback1=="7"){cksendback1="�ۼ�";cksendstring1=infshow7;}
    else if(cksendback1=="8"){cksendback1="��λ";cksendstring1=infshow8;}
    else if(cksendback1=="9"){cksendback1="��עһ";cksendstring1=infshow9;}
    else if(cksendback1=="10"){cksendback1="��ע��";cksendstring1=infshow10;}
    else if(cksendback1=="11"){cksendback1="��ע��";cksendstring1=infshow11;}
    else {cksendback1="����";cksendstring1=infshow2;}

    if(cksendback2=="1"){cksendback2="����";cksendstring2=infshow1;}
    else if(cksendback2=="2"){cksendback2="����";cksendstring2=infshow2;}
    else if(cksendback2=="3"){cksendback2="����";cksendstring2=infshow3;}
    else if(cksendback2=="4"){cksendback2="���";cksendstring2=infshow4;}
    else if(cksendback2=="5"){cksendback2="�ͺ�";cksendstring2=infshow5;}
    else if(cksendback2=="6"){cksendback2="����";cksendstring2=infshow6;}
    else if(cksendback2=="7"){cksendback2="�ۼ�";cksendstring2=infshow7;}
    else if(cksendback2=="8"){cksendback2="��λ";cksendstring2=infshow8;}
    else if(cksendback2=="9"){cksendback2="��עһ";cksendstring2=infshow9;}
    else if(cksendback2=="10"){cksendback2="��ע��";cksendstring2=infshow10;}
    else if(cksendback2=="11"){cksendback2="��ע��";cksendstring2=infshow11;}
    else {cksendback2="����";cksendstring2=infshow3;}

    if(cksendback3=="1"){cksendback3="����";cksendstring3=infshow1;}
    else if(cksendback3=="2"){cksendback3="����";cksendstring3=infshow2;}
    else if(cksendback3=="3"){cksendback3="����";cksendstring3=infshow3;}
    else if(cksendback3=="4"){cksendback3="���";cksendstring3=infshow4;}
    else if(cksendback3=="5"){cksendback3="�ͺ�";cksendstring3=infshow5;}
    else if(cksendback3=="6"){cksendback3="����";cksendstring3=infshow6;}
    else if(cksendback3=="7"){cksendback3="�ۼ�";cksendstring3=infshow7;}
    else if(cksendback3=="8"){cksendback3="��λ";cksendstring3=infshow8;}
    else if(cksendback3=="9"){cksendback3="��עһ";cksendstring3=infshow9;}
    else if(cksendback3=="10"){cksendback3="��ע��";cksendstring3=infshow10;}
    else if(cksendback3=="11"){cksendback3="��ע��";cksendstring3=infshow11;}
    else {cksendback3="����";cksendstring3=infshow6;}

    if(cksendback4=="1"){cksendback4="����";cksendstring4=infshow1;}
    else if(cksendback4=="2"){cksendback4="����";cksendstring4=infshow2;}
    else if(cksendback4=="3"){cksendback4="����";cksendstring4=infshow3;}
    else if(cksendback4=="4"){cksendback4="���";cksendstring4=infshow4;}
    else if(cksendback4=="5"){cksendback4="�ͺ�";cksendstring4=infshow5;}
    else if(cksendback4=="6"){cksendback4="����";cksendstring4=infshow6;}
    else if(cksendback4=="7"){cksendback4="�ۼ�";cksendstring4=infshow7;}
    else if(cksendback4=="8"){cksendback4="��λ";cksendstring4=infshow8;}
    else if(cksendback4=="9"){cksendback4="��עһ";cksendstring4=infshow9;}
    else if(cksendback4=="10"){cksendback4="��ע��";cksendstring4=infshow10;}
    else if(cksendback4=="11"){cksendback4="��ע��";cksendstring4=infshow11;}
    else {cksendback4="�ۼ�";cksendstring4=infshow7;}

    if(cksendback5=="1"){cksendback5="����";cksendstring5=infshow1;}
    else if(cksendback5=="2"){cksendback5="����";cksendstring5=infshow2;}
    else if(cksendback5=="3"){cksendback5="����";cksendstring5=infshow3;}
    else if(cksendback5=="4"){cksendback5="���";cksendstring5=infshow4;}
    else if(cksendback5=="5"){cksendback5="�ͺ�";cksendstring5=infshow5;}
    else if(cksendback5=="6"){cksendback5="����";cksendstring5=infshow6;}
    else if(cksendback5=="7"){cksendback5="�ۼ�";cksendstring5=infshow7;}
    else if(cksendback5=="8"){cksendback5="��λ";cksendstring5=infshow8;}
    else if(cksendback5=="9"){cksendback5="��עһ";cksendstring5=infshow9;}
    else if(cksendback5=="10"){cksendback5="��ע��";cksendstring5=infshow10;}
    else if(cksendback5=="11"){cksendback5="��ע��";cksendstring5=infshow11;}
    else {cksendback5="��עһ";cksendstring5=infshow9;}

    pdsendback1=ini->ReadString("Sys","pdsendback1","2");
    pdsendback2=ini->ReadString("Sys","pdsendback2","3");
    pdsendback3=ini->ReadString("Sys","pdsendback3","6");
    pdsendback4=ini->ReadString("Sys","pdsendback4","7");
    pdsendback5=ini->ReadString("Sys","pdsendback5","9");
    if(pdsendback1=="1"){pdsendback1="����";pdsendstring1=infshow1;}
    else if(pdsendback1=="2"){pdsendback1="����";pdsendstring1=infshow2;}
    else if(pdsendback1=="3"){pdsendback1="����";pdsendstring1=infshow3;}
    else if(pdsendback1=="4"){pdsendback1="���";pdsendstring1=infshow4;}
    else if(pdsendback1=="5"){pdsendback1="�ͺ�";pdsendstring1=infshow5;}
    else if(pdsendback1=="6"){pdsendback1="����";pdsendstring1=infshow6;}
    else if(pdsendback1=="7"){pdsendback1="�ۼ�";pdsendstring1=infshow7;}
    else if(pdsendback1=="8"){pdsendback1="��λ";pdsendstring1=infshow8;}
    else if(pdsendback1=="9"){pdsendback1="��עһ";pdsendstring1=infshow9;}
    else if(pdsendback1=="10"){pdsendback1="��ע��";pdsendstring1=infshow10;}
    else if(pdsendback1=="11"){pdsendback1="��ע��";pdsendstring1=infshow11;}
    else {pdsendback1="����";pdsendstring1=infshow2;}

    if(pdsendback2=="1"){pdsendback2="����";pdsendstring2=infshow1;}
    else if(pdsendback2=="2"){pdsendback2="����";pdsendstring2=infshow2;}
    else if(pdsendback2=="3"){pdsendback2="����";pdsendstring2=infshow3;}
    else if(pdsendback2=="4"){pdsendback2="���";pdsendstring2=infshow4;}
    else if(pdsendback2=="5"){pdsendback2="�ͺ�";pdsendstring2=infshow5;}
    else if(pdsendback2=="6"){pdsendback2="����";pdsendstring2=infshow6;}
    else if(pdsendback2=="7"){pdsendback2="�ۼ�";pdsendstring2=infshow7;}
    else if(pdsendback2=="8"){pdsendback2="��λ";pdsendstring2=infshow8;}
    else if(pdsendback2=="9"){pdsendback2="��עһ";pdsendstring2=infshow9;}
    else if(pdsendback2=="10"){pdsendback2="��ע��";pdsendstring2=infshow10;}
    else if(pdsendback2=="11"){pdsendback2="��ע��";pdsendstring2=infshow11;}
    else {pdsendback2="����";pdsendstring2=infshow3;}

    if(pdsendback3=="1"){pdsendback3="����";pdsendstring3=infshow1;}
    else if(pdsendback3=="2"){pdsendback3="����";pdsendstring3=infshow2;}
    else if(pdsendback3=="3"){pdsendback3="����";pdsendstring3=infshow3;}
    else if(pdsendback3=="4"){pdsendback3="���";pdsendstring3=infshow4;}
    else if(pdsendback3=="5"){pdsendback3="�ͺ�";pdsendstring3=infshow5;}
    else if(pdsendback3=="6"){pdsendback3="����";pdsendstring3=infshow6;}
    else if(pdsendback3=="7"){pdsendback3="�ۼ�";pdsendstring3=infshow7;}
    else if(pdsendback3=="8"){pdsendback3="��λ";pdsendstring3=infshow8;}
    else if(pdsendback3=="9"){pdsendback3="��עһ";pdsendstring3=infshow9;}
    else if(pdsendback3=="10"){pdsendback3="��ע��";pdsendstring3=infshow10;}
    else if(pdsendback3=="11"){pdsendback3="��ע��";pdsendstring3=infshow11;}
    else {pdsendback3="����";pdsendstring3=infshow6;}

    if(pdsendback4=="1"){pdsendback4="����";pdsendstring4=infshow1;}
    else if(pdsendback4=="2"){pdsendback4="����";pdsendstring4=infshow2;}
    else if(pdsendback4=="3"){pdsendback4="����";pdsendstring4=infshow3;}
    else if(pdsendback4=="4"){pdsendback4="���";pdsendstring4=infshow4;}
    else if(pdsendback4=="5"){pdsendback4="�ͺ�";pdsendstring4=infshow5;}
    else if(pdsendback4=="6"){pdsendback4="����";pdsendstring4=infshow6;}
    else if(pdsendback4=="7"){pdsendback4="�ۼ�";pdsendstring4=infshow7;}
    else if(pdsendback4=="8"){pdsendback4="��λ";pdsendstring4=infshow8;}
    else if(pdsendback4=="9"){pdsendback4="��עһ";pdsendstring4=infshow9;}
    else if(pdsendback4=="10"){pdsendback4="��ע��";pdsendstring4=infshow10;}
    else if(pdsendback4=="11"){pdsendback4="��ע��";pdsendstring4=infshow11;}
    else {pdsendback4="�ۼ�";pdsendstring4=infshow7;}

    if(pdsendback5=="1"){pdsendback5="����";pdsendstring5=infshow1;}
    else if(pdsendback5=="2"){pdsendback5="����";pdsendstring5=infshow2;}
    else if(pdsendback5=="3"){pdsendback5="����";pdsendstring5=infshow3;}
    else if(pdsendback5=="4"){pdsendback5="���";pdsendstring5=infshow4;}
    else if(pdsendback5=="5"){pdsendback5="�ͺ�";pdsendstring5=infshow5;}
    else if(pdsendback5=="6"){pdsendback5="����";pdsendstring5=infshow6;}
    else if(pdsendback5=="7"){pdsendback5="�ۼ�";pdsendstring5=infshow7;}
    else if(pdsendback5=="8"){pdsendback5="��λ";pdsendstring5=infshow8;}
    else if(pdsendback5=="9"){pdsendback5="��עһ";pdsendstring5=infshow9;}
    else if(pdsendback5=="10"){pdsendback5="��ע��";pdsendstring5=infshow10;}
    else if(pdsendback5=="11"){pdsendback5="��ע��";pdsendstring5=infshow11;}
    else {pdsendback5="��עһ";pdsendstring5=infshow9;}

    ydsendback1=ini->ReadString("Sys","ydsendback1","2");
    ydsendback2=ini->ReadString("Sys","ydsendback2","3");
    ydsendback3=ini->ReadString("Sys","ydsendback3","6");
    ydsendback4=ini->ReadString("Sys","ydsendback4","7");
    ydsendback5=ini->ReadString("Sys","ydsendback5","9");
    if(ydsendback1=="1"){ydsendback1="����";ydsendstring1=infshow1;}
    else if(ydsendback1=="2"){ydsendback1="����";ydsendstring1=infshow2;}
    else if(ydsendback1=="3"){ydsendback1="����";ydsendstring1=infshow3;}
    else if(ydsendback1=="4"){ydsendback1="���";ydsendstring1=infshow4;}
    else if(ydsendback1=="5"){ydsendback1="�ͺ�";ydsendstring1=infshow5;}
    else if(ydsendback1=="6"){ydsendback1="����";ydsendstring1=infshow6;}
    else if(ydsendback1=="7"){ydsendback1="�ۼ�";ydsendstring1=infshow7;}
    else if(ydsendback1=="8"){ydsendback1="��λ";ydsendstring1=infshow8;}
    else if(ydsendback1=="9"){ydsendback1="��עһ";ydsendstring1=infshow9;}
    else if(ydsendback1=="10"){ydsendback1="��ע��";ydsendstring1=infshow10;}
    else if(ydsendback1=="11"){ydsendback1="��ע��";ydsendstring1=infshow11;}
    else {ydsendback1="����";ydsendstring1=infshow2;}

    if(ydsendback2=="1"){ydsendback2="����";ydsendstring2=infshow1;}
    else if(ydsendback2=="2"){ydsendback2="����";ydsendstring2=infshow2;}
    else if(ydsendback2=="3"){ydsendback2="����";ydsendstring2=infshow3;}
    else if(ydsendback2=="4"){ydsendback2="���";ydsendstring2=infshow4;}
    else if(ydsendback2=="5"){ydsendback2="�ͺ�";ydsendstring2=infshow5;}
    else if(ydsendback2=="6"){ydsendback2="����";ydsendstring2=infshow6;}
    else if(ydsendback2=="7"){ydsendback2="�ۼ�";ydsendstring2=infshow7;}
    else if(ydsendback2=="8"){ydsendback2="��λ";ydsendstring2=infshow8;}
    else if(ydsendback2=="9"){ydsendback2="��עһ";ydsendstring2=infshow9;}
    else if(ydsendback2=="10"){ydsendback2="��ע��";ydsendstring2=infshow10;}
    else if(ydsendback2=="11"){ydsendback2="��ע��";ydsendstring2=infshow11;}
    else {ydsendback2="����";ydsendstring2=infshow3;}

    if(ydsendback3=="1"){ydsendback3="����";ydsendstring3=infshow1;}
    else if(ydsendback3=="2"){ydsendback3="����";ydsendstring3=infshow2;}
    else if(ydsendback3=="3"){ydsendback3="����";ydsendstring3=infshow3;}
    else if(ydsendback3=="4"){ydsendback3="���";ydsendstring3=infshow4;}
    else if(ydsendback3=="5"){ydsendback3="�ͺ�";ydsendstring3=infshow5;}
    else if(ydsendback3=="6"){ydsendback3="����";ydsendstring3=infshow6;}
    else if(ydsendback3=="7"){ydsendback3="�ۼ�";ydsendstring3=infshow7;}
    else if(ydsendback3=="8"){ydsendback3="��λ";ydsendstring3=infshow8;}
    else if(ydsendback3=="9"){ydsendback3="��עһ";ydsendstring3=infshow9;}
    else if(ydsendback3=="10"){ydsendback3="��ע��";ydsendstring3=infshow10;}
    else if(ydsendback3=="11"){ydsendback3="��ע��";ydsendstring3=infshow11;}
    else {ydsendback3="����";ydsendstring3=infshow6;}

    if(ydsendback4=="1"){ydsendback4="����";ydsendstring4=infshow1;}
    else if(ydsendback4=="2"){ydsendback4="����";ydsendstring4=infshow2;}
    else if(ydsendback4=="3"){ydsendback4="����";ydsendstring4=infshow3;}
    else if(ydsendback4=="4"){ydsendback4="���";ydsendstring4=infshow4;}
    else if(ydsendback4=="5"){ydsendback4="�ͺ�";ydsendstring4=infshow5;}
    else if(ydsendback4=="6"){ydsendback4="����";ydsendstring4=infshow6;}
    else if(ydsendback4=="7"){ydsendback4="�ۼ�";ydsendstring4=infshow7;}
    else if(ydsendback4=="8"){ydsendback4="��λ";ydsendstring4=infshow8;}
    else if(ydsendback4=="9"){ydsendback4="��עһ";ydsendstring4=infshow9;}
    else if(ydsendback4=="10"){ydsendback4="��ע��";ydsendstring4=infshow10;}
    else if(ydsendback4=="11"){ydsendback4="��ע��";ydsendstring4=infshow11;}
    else {ydsendback4="�ۼ�";ydsendstring4=infshow7;}

    if(ydsendback5=="1"){ydsendback5="����";ydsendstring5=infshow1;}
    else if(ydsendback5=="2"){ydsendback5="����";ydsendstring5=infshow2;}
    else if(ydsendback5=="3"){ydsendback5="����";ydsendstring5=infshow3;}
    else if(ydsendback5=="4"){ydsendback5="���";ydsendstring5=infshow4;}
    else if(ydsendback5=="5"){ydsendback5="�ͺ�";ydsendstring5=infshow5;}
    else if(ydsendback5=="6"){ydsendback5="����";ydsendstring5=infshow6;}
    else if(ydsendback5=="7"){ydsendback5="�ۼ�";ydsendstring5=infshow7;}
    else if(ydsendback5=="8"){ydsendback5="��λ";ydsendstring5=infshow8;}
    else if(ydsendback5=="9"){ydsendback5="��עһ";ydsendstring5=infshow9;}
    else if(ydsendback5=="10"){ydsendback5="��ע��";ydsendstring5=infshow10;}
    else if(ydsendback5=="11"){ydsendback5="��ע��";ydsendstring5=infshow11;}
    else {ydsendback5="��עһ";ydsendstring5=infshow9;}

    yksendback1=ini->ReadString("Sys","yksendback1","2");
    yksendback2=ini->ReadString("Sys","yksendback2","3");
    yksendback3=ini->ReadString("Sys","yksendback3","6");
    yksendback4=ini->ReadString("Sys","yksendback4","7");
    yksendback5=ini->ReadString("Sys","yksendback5","9");
    if(yksendback1=="1"){yksendback1="����";yksendstring1=infshow1;}
    else if(yksendback1=="2"){yksendback1="����";yksendstring1=infshow2;}
    else if(yksendback1=="3"){yksendback1="����";yksendstring1=infshow3;}
    else if(yksendback1=="4"){yksendback1="���";yksendstring1=infshow4;}
    else if(yksendback1=="5"){yksendback1="�ͺ�";yksendstring1=infshow5;}
    else if(yksendback1=="6"){yksendback1="����";yksendstring1=infshow6;}
    else if(yksendback1=="7"){yksendback1="�ۼ�";yksendstring1=infshow7;}
    else if(yksendback1=="8"){yksendback1="��λ";yksendstring1=infshow8;}
    else if(yksendback1=="9"){yksendback1="��עһ";yksendstring1=infshow9;}
    else if(yksendback1=="10"){yksendback1="��ע��";yksendstring1=infshow10;}
    else if(yksendback1=="11"){yksendback1="��ע��";yksendstring1=infshow11;}
    else {yksendback1="����";yksendstring1=infshow2;}

    if(yksendback2=="1"){yksendback2="����";yksendstring2=infshow1;}
    else if(yksendback2=="2"){yksendback2="����";yksendstring2=infshow2;}
    else if(yksendback2=="3"){yksendback2="����";yksendstring2=infshow3;}
    else if(yksendback2=="4"){yksendback2="���";yksendstring2=infshow4;}
    else if(yksendback2=="5"){yksendback2="�ͺ�";yksendstring2=infshow5;}
    else if(yksendback2=="6"){yksendback2="����";yksendstring2=infshow6;}
    else if(yksendback2=="7"){yksendback2="�ۼ�";yksendstring2=infshow7;}
    else if(yksendback2=="8"){yksendback2="��λ";yksendstring2=infshow8;}
    else if(yksendback2=="9"){yksendback2="��עһ";yksendstring2=infshow9;}
    else if(yksendback2=="10"){yksendback2="��ע��";yksendstring2=infshow10;}
    else if(yksendback2=="11"){yksendback2="��ע��";yksendstring2=infshow11;}
    else {yksendback2="����";yksendstring2=infshow3;}

    if(yksendback3=="1"){yksendback3="����";yksendstring3=infshow1;}
    else if(yksendback3=="2"){yksendback3="����";yksendstring3=infshow2;}
    else if(yksendback3=="3"){yksendback3="����";yksendstring3=infshow3;}
    else if(yksendback3=="4"){yksendback3="���";yksendstring3=infshow4;}
    else if(yksendback3=="5"){yksendback3="�ͺ�";yksendstring3=infshow5;}
    else if(yksendback3=="6"){yksendback3="����";yksendstring3=infshow6;}
    else if(yksendback3=="7"){yksendback3="�ۼ�";yksendstring3=infshow7;}
    else if(yksendback3=="8"){yksendback3="��λ";yksendstring3=infshow8;}
    else if(yksendback3=="9"){yksendback3="��עһ";yksendstring3=infshow9;}
    else if(yksendback3=="10"){yksendback3="��ע��";yksendstring3=infshow10;}
    else if(yksendback3=="11"){yksendback3="��ע��";yksendstring3=infshow11;}
    else {yksendback3="����";yksendstring3=infshow6;}

    if(yksendback4=="1"){yksendback4="����";yksendstring4=infshow1;}
    else if(yksendback4=="2"){yksendback4="����";yksendstring4=infshow2;}
    else if(yksendback4=="3"){yksendback4="����";yksendstring4=infshow3;}
    else if(yksendback4=="4"){yksendback4="���";yksendstring4=infshow4;}
    else if(yksendback4=="5"){yksendback4="�ͺ�";yksendstring4=infshow5;}
    else if(yksendback4=="6"){yksendback4="����";yksendstring4=infshow6;}
    else if(yksendback4=="7"){yksendback4="�ۼ�";yksendstring4=infshow7;}
    else if(yksendback4=="8"){yksendback4="��λ";yksendstring4=infshow8;}
    else if(yksendback4=="9"){yksendback4="��עһ";yksendstring4=infshow9;}
    else if(yksendback4=="10"){yksendback4="��ע��";yksendstring4=infshow10;}
    else if(yksendback4=="11"){yksendback4="��ע��";yksendstring4=infshow11;}
    else {yksendback4="�ۼ�";yksendstring4=infshow7;}

    if(yksendback5=="1"){yksendback5="����";yksendstring5=infshow1;}
    else if(yksendback5=="2"){yksendback5="����";yksendstring5=infshow2;}
    else if(yksendback5=="3"){yksendback5="����";yksendstring5=infshow3;}
    else if(yksendback5=="4"){yksendback5="���";yksendstring5=infshow4;}
    else if(yksendback5=="5"){yksendback5="�ͺ�";yksendstring5=infshow5;}
    else if(yksendback5=="6"){yksendback5="����";yksendstring5=infshow6;}
    else if(yksendback5=="7"){yksendback5="�ۼ�";yksendstring5=infshow7;}
    else if(yksendback5=="8"){yksendback5="��λ";yksendstring5=infshow8;}
    else if(yksendback5=="9"){yksendback5="��עһ";yksendstring5=infshow9;}
    else if(yksendback5=="10"){yksendback5="��ע��";yksendstring5=infshow10;}
    else if(yksendback5=="11"){yksendback5="��ע��";yksendstring5=infshow11;}
    else {yksendback5="��עһ";yksendstring5=infshow9;}





    delete ini;


}
//---------------------------------------------------------------------------

void __fastcall TForm1::SaveExcel(TStringList * sList, String szFile)
{
        //TODO: Add your source code here
          //TODO: Add your source code here
       Variant   Ex,newxls,sh;
      try
      {
          Ex=Variant::CreateObject("Excel.Application");
          Ex.OlePropertySet("Visible",(Variant)false);   //ʹExcel������ɼ�
          newxls=(Ex.OlePropertyGet("Workbooks")).OleFunction("Add");//�½�һ��������
          //newxls=Ex.OlePropertyGet("ActiveWorkBook");
          sh=newxls.OlePropertyGet("ActiveSheet");
      }
      catch(...)
      {
          MessageBox(Application->Handle,"����Excel������������Excelû����ȷ��װ��","����",MB_ICONERROR);
          return;
      }
      Ex.OlePropertySet("Caption","����");
      if(sList->Count==0)return;
      else
      {
          TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
          String RKxls=ini->ReadString("Sys","RKxls",",,,,,,,,,,");
          String CKxls=ini->ReadString("Sys","CKxls",",,,,,,,,,,");
          String PDxls=ini->ReadString("Sys","PDxls",",,,,,,,,,,");

          sh.OlePropertyGet("Cells").OlePropertyGet("Font").OlePropertySet("Size",11);
          TStringList *pList=new TStringList();
          int order=1;
         // String BT[20];

          pList->Text="";
          CrnListSplitString(sList->Strings[0].Trim(), pList, ',');

          if(pList->Strings[0]=="RK")
          {
                pList->Text="";
                CrnListSplitString(RKxls.Trim(), pList, ',');
                for(int i=0;i<pList->Count&&pList->Strings[i].Trim().Length()!=0;i++)
                {
                   sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("NumberFormatLocal","@");
                   sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("Value",pList->Strings[i].Trim().c_str());
                   sh.OlePropertyGet("Cells",1,i+1).OlePropertyGet("Font").OlePropertySet("Bold",true);
                }
          }

          else if(pList->Strings[0]=="CK")
          {
                pList->Text="";
                CrnListSplitString(CKxls.Trim(), pList, ',');
                for(int i=0;i<pList->Count&&pList->Strings[i].Trim().Length()!=0;i++)
                {
                   sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("NumberFormatLocal","@");
                   sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("Value",pList->Strings[i].Trim().c_str());
                   sh.OlePropertyGet("Cells",1,i+1).OlePropertyGet("Font").OlePropertySet("Bold",true);
                }
          }
          else if(pList->Strings[0]=="PD")
          {
                pList->Text="";
                CrnListSplitString(PDxls.Trim(), pList, ',');
                for(int i=0;i<pList->Count&&pList->Strings[i].Trim().Length()!=0;i++)
                {
                   sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("NumberFormatLocal","@");
                   sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("Value",pList->Strings[i].Trim().c_str());
                   sh.OlePropertyGet("Cells",1,i+1).OlePropertyGet("Font").OlePropertySet("Bold",true);
                }
          }
          else if(pList->Strings[0]=="URK"||pList->Strings[0]=="UCK")
          {
            String BT[]={"����","�ֿ�","����","����","����"};
            order=5;
            for(int i=0;i<order;i++)
            {
                sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("NumberFormatLocal","@");
                sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("Value",BT[i].c_str());
                sh.OlePropertyGet("Cells",1,i+1).OlePropertyGet("Font").OlePropertySet("Bold",true);
            }
          }
          else if(pList->Strings[0]=="UPD")
          {
             String BT[]={"�ֿ�","����","����","����"};
             order=4;
             for(int i=0;i<order;i++)
             {
                sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("NumberFormatLocal","@");
                sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("Value",BT[i].c_str());
                sh.OlePropertyGet("Cells",1,i+1).OlePropertyGet("Font").OlePropertySet("Bold",true);
             }
          }
          else if(pList->Strings[0]=="KC")
          {
             if(Form1->Pshow=="show")
             {
                 String BT[]={infshow1,infshow2,infshow3,infshow4,infshow5,infshow6,infshow7,infshow8,infshow9,infshow10,infshow11,"�������","��������","�ֿ�","���"};
                 order=15;
                 for(int i=0;i<order;i++)
                 {
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("NumberFormatLocal","@");
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("Value",BT[i].c_str());
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertyGet("Font").OlePropertySet("Bold",true);
                 }
             }
             else
             {
                 String BT[]={infshow1,infshow2,infshow3,infshow4,infshow5,infshow7,infshow8,infshow9,infshow10,infshow11,"�������","��������","�ֿ�","���"};
                 order=14;
                 for(int i=0;i<order;i++)
                 {
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("NumberFormatLocal","@");
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("Value",BT[i].c_str());
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertyGet("Font").OlePropertySet("Bold",true);
                 }
             }
          }
          else if(pList->Strings[0]=="PDTJ")
          {
             if(Form1->Pshow=="show"&&Form1->KCshow=="show")
             {
                 String BT[]={infshow1,infshow2,infshow3,infshow4,infshow5,infshow6,infshow7,infshow8,infshow9,infshow10,infshow11,"�̵���","ʵ�ʿ��","�ֿ�"};
                 order=14;
                 for(int i=0;i<order;i++)
                 {
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("NumberFormatLocal","@");
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("Value",BT[i].c_str());
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertyGet("Font").OlePropertySet("Bold",true);
                 }
             }
             else if(Form1->Pshow!="show"&&Form1->KCshow!="show")
             {
                 String BT[]={infshow1,infshow2,infshow3,infshow4,infshow5,infshow7,infshow8,infshow9,infshow10,infshow11,"�̵���","�ֿ�"};
                 order=12;
                 for(int i=0;i<order;i++)
                 {
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("NumberFormatLocal","@");
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("Value",BT[i].c_str());
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertyGet("Font").OlePropertySet("Bold",true);
                 }
             }
             else if(Form1->Pshow=="show"&&Form1->KCshow!="show")
             {
                 String BT[]={infshow1,infshow2,infshow3,infshow4,infshow5,infshow6,infshow7,infshow8,infshow9,infshow10,infshow11,"�̵���","�ֿ�"};
                 order=13;
                 for(int i=0;i<order;i++)
                 {
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("NumberFormatLocal","@");
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("Value",BT[i].c_str());
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertyGet("Font").OlePropertySet("Bold",true);
                 }
             }
             else if(Form1->Pshow!="show"&&Form1->KCshow=="show")
             {
                 String BT[]={infshow1,infshow2,infshow3,infshow4,infshow5,infshow7,infshow8,infshow9,infshow10,infshow11,"�̵���","ʵ�ʿ��","�ֿ�"};
                 order=13;
                 for(int i=0;i<order;i++)
                 {
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("NumberFormatLocal","@");
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("Value",BT[i].c_str());
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertyGet("Font").OlePropertySet("Bold",true);
                 }
             }
          }
          else if(pList->Strings[0]=="YK")
          {
             if(Form1->Pshow=="show")
             {
                 String BT[]={infshow1,infshow2,infshow3,infshow4,infshow5,infshow6,infshow7,infshow8,infshow9,infshow10,infshow11,"ԭ�ֿ�","Ŀ�Ĳֿ�","����","�ƿ�ʱ��","Ա�����","Ա������"};
                 order=17;
                 for(int i=0;i<order;i++)
                 {
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("NumberFormatLocal","@");
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("Value",BT[i].c_str());
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertyGet("Font").OlePropertySet("Bold",true);
                 }
             }
             else
             {
                 String BT[]={infshow1,infshow2,infshow3,infshow4,infshow5,infshow7,infshow8,infshow9,infshow10,infshow11,"ԭ�ֿ�","Ŀ�Ĳֿ�","����","�ƿ�ʱ��","Ա�����","Ա������"};
                 order=16;
                 for(int i=0;i<order;i++)
                 {
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("NumberFormatLocal","@");
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("Value",BT[i].c_str());
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertyGet("Font").OlePropertySet("Bold",true);
                 }
             }

          }
          else if(pList->Strings[0]=="YD")
          {
             if(Form1->Pshow=="show")
             {
                 String BT[]={"����",infshow1,infshow2,infshow3,infshow4,infshow5,infshow6,infshow7,infshow8,infshow9,infshow10,infshow11,"Ӧɨ����","��ɨ����","ʱ��","Ա�����","Ա������"};
                 order=17;
                 for(int i=0;i<order;i++)
                 {
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("NumberFormatLocal","@");
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("Value",BT[i].c_str());
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertyGet("Font").OlePropertySet("Bold",true);
                 }
             }
             else
             {
                 String BT[]={"����",infshow1,infshow2,infshow3,infshow4,infshow5,infshow7,infshow8,infshow9,infshow10,infshow11,"Ӧɨ����","��ɨ����","ʱ��","Ա�����","Ա������"};
                 order=16;
                 for(int i=0;i<order;i++)
                 {
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("NumberFormatLocal","@");
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("Value",BT[i].c_str());
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertyGet("Font").OlePropertySet("Bold",true);
                 }
             }
          }
          else if(pList->Strings[0]=="PL")
          {
             String BT[]={"����","����"};
             order=2;
             for(int i=0;i<order;i++)
             {
                sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("NumberFormatLocal","@");
                sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("Value",BT[i].c_str());
                sh.OlePropertyGet("Cells",1,i+1).OlePropertyGet("Font").OlePropertySet("Bold",true);
             }
          }
          else if(pList->Strings[0]=="XSTJ")
          {
             String BT[]={"���ⵥ��","�ɱ�","���۶�","����","ʱ��","Ա�����","Ա������"};
             order=7;
             for(int i=0;i<order;i++)
             {
                sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("NumberFormatLocal","@");
                sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("Value",BT[i].c_str());
                sh.OlePropertyGet("Cells",1,i+1).OlePropertyGet("Font").OlePropertySet("Bold",true);
             }
          }
          else if(pList->Strings[0]=="JBZL")
          {
             if(Form1->Pshow=="show")
             {
                 String BT[]={infshow1,infshow2,infshow3,infshow4,infshow5,infshow6,infshow7,infshow8,infshow9,infshow10,infshow11};
                 order=11;
                 for(int i=0;i<order;i++)
                 {
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("NumberFormatLocal","@");
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("Value",BT[i].c_str());
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertyGet("Font").OlePropertySet("Bold",true);
                 }
             }
             else
             {
                 String BT[]={infshow1,infshow2,infshow3,infshow4,infshow5,infshow7,infshow8,infshow9,infshow10,infshow11};
                 order=10;
                 for(int i=0;i<order;i++)
                 {
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("NumberFormatLocal","@");
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertySet("Value",BT[i].c_str());
                    sh.OlePropertyGet("Cells",1,i+1).OlePropertyGet("Font").OlePropertySet("Bold",true);
                 }
             }
          }

         // String strs="���ڱ����ļ� "+szFile;
         // this->StatusBar1->Panels->Items[0]->Text=strs;



          String str="";;
          for(int   i=0;i<sList->Count;i++)
          {
                pList->Text="";
                CrnListSplitString(sList->Strings[i].Trim(), pList, ',');
                for(int   j=1;j<pList->Count;j++)
                {
                      str=pList->Strings[j].Trim();
                      sh.OlePropertyGet("Cells",i+2,j).OlePropertySet("NumberFormatLocal","@");
                      sh.OlePropertyGet("Cells",i+2,j).OlePropertySet("Value",str.c_str());
                      Application->ProcessMessages();
                }
               // this->StatusBar1->Panels->Items[0]->Text="�����ļ� "+szFile+"    ����:"+String(i+1);
          }

          delete  pList;
          newxls.OleFunction("SaveAs",szFile.c_str());

          newxls.OleProcedure("Close");
          Ex.OleFunction ("Quit");
          Ex=Unassigned;

          //this->StatusBar1->Panels->Items[0]->Text="�������Ѿ����������ڼ���...";
      }
}

int TForm1::CrnListSplitString(String str, TStrings * pList, TCHAR cSplit)
{
        //TODO: Add your source code here
         pList->Clear();

    if (str.IsEmpty())
        return 0;

  //  if (str.Length() > 0 && str[str.Length()] == cSplit)
  //      str = str.SubString(1, str.Length() - 1);

    String strTemp;
    if (!str.Pos(cSplit))
    {
        pList->Add(str);
    }
    else
    {
        while (str.Pos(cSplit))
        {
            strTemp = str.SubString(1, str.Pos(cSplit) - 1);
            if (strTemp != String(cSplit));
                pList->Add(strTemp);
            str = str.Delete(1, str.Pos(cSplit));
        }
       // if (str != String(cSplit) && strTemp.Length() > 0)
       if (str != String(cSplit))
            pList->Add(str);
    }
    return pList->Count;
}
void __fastcall TForm1::nameKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 if(Key==VK_RETURN)password->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::passwordKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==VK_RETURN)BitBtn1Click(Sender);        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
       name->Text="";
       password->Text="";
       name->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
   //���������Ƿ���һ���ģ������ȷ����д��
   if(passwordstr==Edit2->Text.Trim()+"-"+Edit3->Text.Trim()+"-"+Edit4->Text.Trim())
   {
      //д�����ݿ�
       String str="";
       str=String().sprintf("UPDATE ZC SET  ע���� = \"%s\" WHERE ���к� like \"%s\""
                                 ,passwordstr
                                 ,serialstr);
                            Form1->ADOCommand1->CommandText = str;
                            Form1->ADOCommand1->Execute();
       Panel1->Visible=false;
   }
   else
   {
       ShowMessage("ע���������������д��");
   }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
    if(RadioButton1->Checked==true)
    {
        //ע��
        Panel1->Visible=true;
        Panel2->Visible=false;
        return;

    }
    else
    {
        Panel2->Visible=false;
        return;
    }//����
}
//---------------------------------------------------------------------------



