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

           str="UPDATE YG SET 密码 = \""+Edit1->Text.Trim()+"\" WHERE 员工编号 like \""+Form1->LoginName+"\"";

           Form1->ADOCommand1->CommandText = str;
           Form1->ADOCommand1->Execute();

           ShowMessage("密码修改成功！");
           return;
       }
       else
       {
           ShowMessage("密码不能为空，并且两次输入一定要一致！");
           return;
       }
}
//---------------------------------------------------------------------------

void __fastcall TForm15::BitBtn2Click(TObject *Sender)
{
    if(Edit3->Text.Trim().Length()==0)
    {
         ShowMessage("员工编号不能为空！");
         return;
    }
    if(Edit7->Text.Trim().Length()==0)
    {
         ShowMessage("员工姓名不能为空！");
         return;
    }
    if(Edit4->Text.Trim().Length()==0)
    {
         ShowMessage("密码不能为空！");
         return;
    }
    if(Edit5->Text.Trim().Length()==0)
    {
         ShowMessage("请重复输入密码");
         return;
    }

    if(Edit4->Text.Trim()!=Edit5->Text.Trim())
    {
         ShowMessage("两次输入的密码不一致，请重新输入");
         Edit5->Text="";
         Edit5->SetFocus();
         return;
    }
    
    Form1->Search_ADOQuery->Close();
    Form1->Search_ADOQuery->SQL->Clear();
    Form1->Search_ADOQuery->SQL->Add("SELECT * FROM YG where 员工编号 like \""+Edit3->Text.Trim()+"\"");
    Form1->Search_ADOQuery->Active= true;

    if(Form1->Search_ADOQuery->RecordCount!=0)
    {
         ShowMessage("该员工编号已经存在，不可重复添加！");
         return;
    }


    Form1->YG_ADOTable->Insert();
    Form1->YG_ADOTable->FieldByName("员工编号")->AsString = Edit3->Text.Trim();
    Form1->YG_ADOTable->FieldByName("员工姓名")->AsString = Edit7->Text.Trim();
    Form1->YG_ADOTable->FieldByName("密码")->AsString = Edit4->Text.Trim();
    Form1->YG_ADOTable->Post();

    ShowMessage("员工编号添加成功！");

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
         ShowMessage("员工编号不能为空！");
         return;
     }

     if(Edit6->Text.Trim()=="01")
     {
         ShowMessage("不能删除员工编号01");
         return;
     }

    String str="";
    str=String().sprintf("DELETE FROM YG WHERE 员工编号 = \"%s\"",Edit6->Text.Trim());
    Form1->ADOCommand1->CommandText = str;
    Form1->ADOCommand1->Execute();

    ShowMessage("删除成功");

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

    //显示设置
    Form1->Search_ADOQuery->Close();
    Form1->Search_ADOQuery->SQL->Clear();
    Form1->Search_ADOQuery->SQL->Add("SELECT * FROM ZC where 序列号 like \"23d5f7eab74g\"");
    Form1->Search_ADOQuery->Active= true;

     if(Form1->Search_ADOQuery->RecordCount==0)
     {
         RadioButton2->Checked=true;
     }
     else
     {
         if(Form1->Search_ADOQuery->FieldByName("注册码")->AsString.Trim()=="a3c5-67ff-3f5d")
         RadioButton1->Checked=true;
         else RadioButton2->Checked=true;
     }

    Form1->Search_ADOQuery->Close();
    Form1->Search_ADOQuery->SQL->Clear();
    Form1->Search_ADOQuery->SQL->Add("SELECT * FROM ZC where 序列号 like \"23d5f7eab74h\"");
    Form1->Search_ADOQuery->Active= true;

     if(Form1->Search_ADOQuery->RecordCount==0)
     {
         RadioButton4->Checked=true;
     }
     else
     {
         if(Form1->Search_ADOQuery->FieldByName("注册码")->AsString.Trim()=="a3c5-67ff-3f5d")
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


     Form1->ADOCommand1->CommandText = "DELETE FROM ZC where 序列号 like \"23d5f7eab74g\"";
     Form1->ADOCommand1->Execute();

     

     Form1->ZC_ADOTable->Insert();
     Form1->ZC_ADOTable->FieldByName("序列号")->AsString = "23d5f7eab74g";
     Form1->ZC_ADOTable->FieldByName("注册码")->AsString = ZCM;
     Form1->ZC_ADOTable->Post();

     ShowMessage("设置成功");
}
//---------------------------------------------------------------------------

void __fastcall TForm15::Button2Click(TObject *Sender)
{
       if(Edit8->Text.Trim().Length()!=0)
       {
           String str="";

           str="UPDATE YG SET 员工姓名 = \""+Edit8->Text.Trim()+"\" WHERE 员工编号 like \""+Form1->LoginName+"\"";

           Form1->ADOCommand1->CommandText = str;
           Form1->ADOCommand1->Execute();

           ShowMessage("员工姓名设置成功！");

           Form1->YG_ADOQuery->Close();
           Form1->YG_ADOQuery->SQL->Clear();
           Form1->YG_ADOQuery->SQL->Add("SELECT * FROM YG");
           Form1->YG_ADOQuery->Active= true;
           return;
       }
       else
       {
           ShowMessage("员工姓名为空，无法设置！");
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


     Form1->ADOCommand1->CommandText = "DELETE FROM ZC where 序列号 like \"23d5f7eab74h\"";
     Form1->ADOCommand1->Execute();



     Form1->ZC_ADOTable->Insert();
     Form1->ZC_ADOTable->FieldByName("序列号")->AsString = "23d5f7eab74h";
     Form1->ZC_ADOTable->FieldByName("注册码")->AsString = ZCM;
     Form1->ZC_ADOTable->Post();

     ShowMessage("设置成功");
}
//---------------------------------------------------------------------------

