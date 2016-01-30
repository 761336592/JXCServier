//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit15.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm15 *Form15;
//---------------------------------------------------------------------------
__fastcall TForm15::TForm15(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm15::BitBtn1Click(TObject *Sender)
{
       if(Edit1->Text.Trim()==Edit2->Text.Trim()&&Edit2->Text.Trim().Length()!=0)
       {
           String str="";

           str="UPDATE YG SET ���� = \""+Edit1->Text.Trim()+"\" WHERE Ա����� like \""+Form1->LoginName+"\"";

           Form1->ADOCommand1->CommandText = str;
           Form1->ADOCommand1->Execute();

           ShowMessage("�����޸ĳɹ���");
           return;
       }
       else
       {
           ShowMessage("���벻��Ϊ�գ�������������һ��Ҫһ�£�");
           return;
       }
}
//---------------------------------------------------------------------------

void __fastcall TForm15::BitBtn2Click(TObject *Sender)
{
    if(Edit3->Text.Trim().Length()==0)
    {
         ShowMessage("Ա����Ų���Ϊ�գ�");
         return;
    }
    if(Edit7->Text.Trim().Length()==0)
    {
         ShowMessage("Ա����������Ϊ�գ�");
         return;
    }
    if(Edit4->Text.Trim().Length()==0)
    {
         ShowMessage("���벻��Ϊ�գ�");
         return;
    }
    if(Edit5->Text.Trim().Length()==0)
    {
         ShowMessage("���ظ���������");
         return;
    }

    if(Edit4->Text.Trim()!=Edit5->Text.Trim())
    {
         ShowMessage("������������벻һ�£�����������");
         Edit5->Text="";
         Edit5->SetFocus();
         return;
    }
    
    Form1->Search_ADOQuery->Close();
    Form1->Search_ADOQuery->SQL->Clear();
    Form1->Search_ADOQuery->SQL->Add("SELECT * FROM YG where Ա����� like \""+Edit3->Text.Trim()+"\"");
    Form1->Search_ADOQuery->Active= true;

    if(Form1->Search_ADOQuery->RecordCount!=0)
    {
         ShowMessage("��Ա������Ѿ����ڣ������ظ���ӣ�");
         return;
    }


    Form1->YG_ADOTable->Insert();
    Form1->YG_ADOTable->FieldByName("Ա�����")->AsString = Edit3->Text.Trim();
    Form1->YG_ADOTable->FieldByName("Ա������")->AsString = Edit7->Text.Trim();
    Form1->YG_ADOTable->FieldByName("����")->AsString = Edit4->Text.Trim();
    Form1->YG_ADOTable->Post();

    ShowMessage("Ա�������ӳɹ���");

    Form1->YG_ADOQuery->Close();
    Form1->YG_ADOQuery->SQL->Clear();
    Form1->YG_ADOQuery->SQL->Add("SELECT * FROM YG");
    Form1->YG_ADOQuery->Active= true;

}
//---------------------------------------------------------------------------
void __fastcall TForm15::BitBtn3Click(TObject *Sender)
{
     if(Edit6->Text.Trim().Length()==0)
     {
         ShowMessage("Ա����Ų���Ϊ�գ�");
         return;
     }

     if(Edit6->Text.Trim()=="01")
     {
         ShowMessage("����ɾ��Ա�����01");
         return;
     }

    String str="";
    str=String().sprintf("DELETE FROM YG WHERE Ա����� = \"%s\"",Edit6->Text.Trim());
    Form1->ADOCommand1->CommandText = str;
    Form1->ADOCommand1->Execute();

    ShowMessage("ɾ���ɹ�");

    Form1->YG_ADOQuery->Close();
    Form1->YG_ADOQuery->SQL->Clear();
    Form1->YG_ADOQuery->SQL->Add("SELECT * FROM YG");
    Form1->YG_ADOQuery->Active= true;
}
//---------------------------------------------------------------------------
void __fastcall TForm15::FormShow(TObject *Sender)
{
    if(Form1->LoginName=="01")
    {
        BitBtn2->Enabled=true;
        BitBtn3->Enabled=true;
        Button1->Enabled=true;
        Button2->Enabled=true;
        Button3->Enabled=true;
    }

    //��ʾ����
    Form1->Search_ADOQuery->Close();
    Form1->Search_ADOQuery->SQL->Clear();
    Form1->Search_ADOQuery->SQL->Add("SELECT * FROM ZC where ���к� like \"23d5f7eab74g\"");
    Form1->Search_ADOQuery->Active= true;

     if(Form1->Search_ADOQuery->RecordCount==0)
     {
         RadioButton2->Checked=true;
     }
     else
     {
         if(Form1->Search_ADOQuery->FieldByName("ע����")->AsString.Trim()=="a3c5-67ff-3f5d")
         RadioButton1->Checked=true;
         else RadioButton2->Checked=true;
     }

    Form1->Search_ADOQuery->Close();
    Form1->Search_ADOQuery->SQL->Clear();
    Form1->Search_ADOQuery->SQL->Add("SELECT * FROM ZC where ���к� like \"23d5f7eab74h\"");
    Form1->Search_ADOQuery->Active= true;

     if(Form1->Search_ADOQuery->RecordCount==0)
     {
         RadioButton4->Checked=true;
     }
     else
     {
         if(Form1->Search_ADOQuery->FieldByName("ע����")->AsString.Trim()=="a3c5-67ff-3f5d")
         RadioButton3->Checked=true;
         else RadioButton4->Checked=true;
     }
}
//---------------------------------------------------------------------------


void __fastcall TForm15::Button1Click(TObject *Sender)
{
     String ZCM="";
     if(RadioButton1->Checked==true)
     ZCM="a3c5-67ff-3f5d";
     else
     ZCM="a3c5-67ff-3f5f";


     Form1->ADOCommand1->CommandText = "DELETE FROM ZC where ���к� like \"23d5f7eab74g\"";
     Form1->ADOCommand1->Execute();

     

     Form1->ZC_ADOTable->Insert();
     Form1->ZC_ADOTable->FieldByName("���к�")->AsString = "23d5f7eab74g";
     Form1->ZC_ADOTable->FieldByName("ע����")->AsString = ZCM;
     Form1->ZC_ADOTable->Post();

     ShowMessage("���óɹ�");
}
//---------------------------------------------------------------------------

void __fastcall TForm15::Button2Click(TObject *Sender)
{
       if(Edit8->Text.Trim().Length()!=0)
       {
           String str="";

           str="UPDATE YG SET Ա������ = \""+Edit8->Text.Trim()+"\" WHERE Ա����� like \""+Form1->LoginName+"\"";

           Form1->ADOCommand1->CommandText = str;
           Form1->ADOCommand1->Execute();

           ShowMessage("Ա���������óɹ���");

           Form1->YG_ADOQuery->Close();
           Form1->YG_ADOQuery->SQL->Clear();
           Form1->YG_ADOQuery->SQL->Add("SELECT * FROM YG");
           Form1->YG_ADOQuery->Active= true;
           return;
       }
       else
       {
           ShowMessage("Ա������Ϊ�գ��޷����ã�");
           return;
       }
}
//---------------------------------------------------------------------------

void __fastcall TForm15::Button3Click(TObject *Sender)
{
     String ZCM="";
     if(RadioButton3->Checked==true)
     ZCM="a3c5-67ff-3f5d";
     else
     ZCM="a3c5-67ff-3f5f";


     Form1->ADOCommand1->CommandText = "DELETE FROM ZC where ���к� like \"23d5f7eab74h\"";
     Form1->ADOCommand1->Execute();



     Form1->ZC_ADOTable->Insert();
     Form1->ZC_ADOTable->FieldByName("���к�")->AsString = "23d5f7eab74h";
     Form1->ZC_ADOTable->FieldByName("ע����")->AsString = ZCM;
     Form1->ZC_ADOTable->Post();

     ShowMessage("���óɹ�");
}
//---------------------------------------------------------------------------

