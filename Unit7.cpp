//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include   <inifiles.hpp>
#include <FileCtrl.hpp>

#include "Unit7.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//String exportPD[]={"����","�̵���","�̵�ʱ��","�ֿ�","Ա�����","Ա������","����","����","���","�ͺ�","����","�ۼ�","��λ","��עһ","��ע��","��ע��"};
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm7::BitBtn1Click(TObject *Sender)
{
    String str1="";
    String str2="";
    if(RadioButton1->Checked==True)
    {
       str1="SELECT * FROM �̵�ͳ��";
       str2="SELECT sum(�̵���) AS �̵��ܿ�� , sum(���) AS �ܿ�� FROM �̵�ͳ��";
    }
    else if(RadioButton2->Checked==True)
    {
       str1="SELECT * FROM �̵�ͳ�� WHERE �̵��� > ��� OR (�̵��� > 0 AND ��� IS NULL)";
       str2="SELECT sum(�̵���) AS �̵��ܿ�� , sum(���) AS �ܿ�� FROM �̵�ͳ�� WHERE �̵��� > ��� OR (�̵��� > 0 AND ��� IS NULL)";
    }
    else  if(RadioButton3->Checked==True)
    {
       str1="SELECT * FROM �̵�ͳ�� WHERE �̵��� < ��� OR (�̵��� < 0 AND ��� IS NULL)";
       str2="SELECT sum(�̵���) AS �̵��ܿ�� , sum(���) AS �ܿ�� FROM �̵�ͳ�� WHERE �̵��� < ��� OR (�̵��� < 0 AND ��� IS NULL)";
    }
    else
    {
       str1="SELECT * FROM ©�� WHERE �̵��� IS NULL";
       str2="SELECT sum(�̵���) AS �̵��ܿ�� , sum(���) AS �ܿ�� FROM ©�� WHERE �̵��� IS NULL";
    }


   /* {
         str="SELECT KC.*, PDTJ.�̵���, JBZL.����, JBZL.����, JBZL.���, JBZL.�ͺ�, JBZL.����, JBZL.�ۼ�, JBZL.��λ, JBZL.��עһ, JBZL.��ע��, JBZL.��ע�� FROM (KC LEFT JOIN PDTJ ON (KC.�ֿ� = PDTJ.�ֿ�) AND (KC.���� = PD.����)) LEFT JOIN JBZL ON KC.���� = JBZL.���� WHERE �̵��� IS NULL";
    } */


    Form1->PDTJ_ADOQuery->Close();
    Form1->PDTJ_ADOQuery->SQL->Clear();
    Form1->PDTJ_ADOQuery->SQL->Add(str1);
    Form1->PDTJ_ADOQuery->Active= true;

    Form1->Search_ADOQuery->Close();
    Form1->Search_ADOQuery->SQL->Clear();
    Form1->Search_ADOQuery->SQL->Add(str2);
    Form1->Search_ADOQuery->Active= true;


    StatusBar1->Panels->Items[0]->Text="��ѯ���    �������� "+String(Form1->PDTJ_ADOQuery->RecordCount)+"    �̵��ܿ�棺 "+Form1->Search_ADOQuery->FieldByName("�̵��ܿ��")->AsString+"    ʵ���ܿ�棺 "+Form1->Search_ADOQuery->FieldByName("�ܿ��")->AsString;

}
//---------------------------------------------------------------------------

void __fastcall TForm7::FormShow(TObject *Sender)
{
    DBGrid1->Columns->Items[0]->Title->Caption=Form1->infshow1;
    DBGrid1->Columns->Items[1]->Title->Caption=Form1->infshow2;
    DBGrid1->Columns->Items[2]->Title->Caption=Form1->infshow3;
    DBGrid1->Columns->Items[3]->Title->Caption=Form1->infshow4;
    DBGrid1->Columns->Items[4]->Title->Caption=Form1->infshow5;
    if(Form1->Pshow=="show")DBGrid1->Columns->Items[5]->Title->Caption=Form1->infshow6;
    DBGrid1->Columns->Items[6]->Title->Caption=Form1->infshow7;
    DBGrid1->Columns->Items[7]->Title->Caption=Form1->infshow8;
    DBGrid1->Columns->Items[8]->Title->Caption=Form1->infshow9;
    DBGrid1->Columns->Items[9]->Title->Caption=Form1->infshow10;
    DBGrid1->Columns->Items[10]->Title->Caption=Form1->infshow11;

    if(Form1->Pshow=="show")
    DBGrid1->Columns->Items[5]->Visible=true;

    if(Form1->KCshow=="show")
    DBGrid1->Columns->Items[12]->Visible=true;

}
//---------------------------------------------------------------------------
void __fastcall TForm7::FormCreate(TObject *Sender)
{
      for(int i=0;i<DBGrid1->Columns->Count;i++)
      DBGrid1->Columns->Items[i]->Width=(DBGrid1->Width-50)/DBGrid1->Columns->Count;        
}
//---------------------------------------------------------------------------

void __fastcall TForm7::BitBtn2Click(TObject *Sender)
{
    BitBtn1Click(Sender);
   String Dir;
   if(SelectDirectory("Directory Name","",Dir))
   {
         if(Dir.SubString(Dir.Length(),1)!="\\")
         {
                   Dir=Dir+"\\";
         }


      TStringList *SaveList=new TStringList();
      int selectnum=Form1->PDTJ_ADOQuery->RecordCount;
      String str="";
      String FileName="";
      if(RadioButton1->Checked==true)
         FileName="�̵���ܱ�";
      else if(RadioButton2->Checked==true)
         FileName="��ӯ��";
      else if(RadioButton3->Checked==true)
         FileName="�̿���";
      else if(RadioButton4->Checked==true)
         FileName="©�̱�";

      String datetime= Now().FormatString("yyyymmddhhnnss");
      SaveList->Text="";
      for(int i=0;i<selectnum;i++)
      {
             str="";
           //  RK_Grid->Columns->Items[0]->Field->
             str="PDTJ,"+
                 Form1->PDTJ_ADOQuery->FieldByName("����")->AsString+","+
                 Form1->PDTJ_ADOQuery->FieldByName("����")->AsString+","+
                 Form1->PDTJ_ADOQuery->FieldByName("����")->AsString+","+
                 Form1->PDTJ_ADOQuery->FieldByName("���")->AsString+","+
                 Form1->PDTJ_ADOQuery->FieldByName("�ͺ�")->AsString+",";
                 if(Form1->Pshow=="show")str+=Form1->PDTJ_ADOQuery->FieldByName("����")->AsString+",";
                 str+=Form1->PDTJ_ADOQuery->FieldByName("�ۼ�")->AsString+","+
                 Form1->PDTJ_ADOQuery->FieldByName("��λ")->AsString+","+
                 Form1->PDTJ_ADOQuery->FieldByName("��עһ")->AsString+","+
                 Form1->PDTJ_ADOQuery->FieldByName("��ע��")->AsString+","+
                 Form1->PDTJ_ADOQuery->FieldByName("��ע��")->AsString+","+
                 Form1->PDTJ_ADOQuery->FieldByName("�̵���")->AsString+",";
                 if(Form1->KCshow=="show")str+=Form1->PDTJ_ADOQuery->FieldByName("���")->AsString+",";
                 str+=Form1->PDTJ_ADOQuery->FieldByName("�ֿ�")->AsString;
             SaveList->Add(str);

             Form1->PDTJ_ADOQuery->Next();
      }
      Form1->SaveExcel(SaveList,Dir.Trim()+FileName+"-"+datetime+".xls") ;
      MessageDlg("�������",mtInformation,TMsgDlgButtons()<<mbOK,0);

      delete SaveList;
   }
   else
   return;

}
//---------------------------------------------------------------------------

void __fastcall TForm7::DBGrid1TitleClick(TColumn *Column)
{
  String s;
  if(Form1->PDTJ_ADOQuery->Active)
  {
      if (DBGrid1->Tag==0) //˳������
      {
         Form1->PDTJ_ADOQuery->Sort=Column->FieldName+" ASC";
         DBGrid1->Tag=1;
      }
      else   //��������,�ı�������ɫ
      {
         Form1->PDTJ_ADOQuery->Sort=Column->FieldName+" DESC";
         DBGrid1->Tag=0;
      }
  }        
}
//---------------------------------------------------------------------------

