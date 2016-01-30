//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <FileCtrl.hpp>
#include   <inifiles.hpp>

#include "Unit16.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm16 *Form16;
//---------------------------------------------------------------------------
__fastcall TForm16::TForm16(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm16::BitBtn1Click(TObject *Sender)
{
   String Dir;
   if(SelectDirectory("Directory Name","",Dir))
   {
         if(Dir.SubString(Dir.Length(),1)!="\\")
         {
                   Dir=Dir+"\\";
         }

         String  FromdirPath= ExtractFileDir(Application->ExeName)+"\\JXC.mdb";
         String  TodirPath= Dir+"JXC.mdb";
         if(CopyFile(FromdirPath.c_str(),TodirPath.c_str(), FALSE)==False)
         {
                 MessageDlg("备份失败",mtConfirmation,TMsgDlgButtons()<<mbOK,0);
                 return;
         }
         else
         MessageDlg("备份成功",mtInformation,TMsgDlgButtons()<<mbOK,0);

   }
   else
   return;
}
//---------------------------------------------------------------------------
void __fastcall TForm16::BitBtn2Click(TObject *Sender)
{
   String Dir;
   if(SelectDirectory("Directory Name","",Dir))
   {
         if(Dir.SubString(Dir.Length(),1)!="\\")
         {
                   Dir=Dir+"\\";
         }

         String  FromdirPath= ExtractFileDir(Application->ExeName)+"\\JXC.mdb";
         String  TodirPath= Dir+"JXC.mdb";
         if(CopyFile(TodirPath.c_str(),FromdirPath.c_str(), FALSE)==False)
         {
                 MessageDlg("恢复失败",mtConfirmation,TMsgDlgButtons()<<mbOK,0);
                 return;
         }
         else
         {

             MessageDlg("恢复成功",mtInformation,TMsgDlgButtons()<<mbOK,0);
         }

            TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
	    String password=";Jet OLEDB:Database Password="+ini->ReadString("Sys","password","rsa1314")+";Data Source=";
	
	    Form1->ADOConnection1->Close();
	    AnsiString ConnectionString, accPath;
	    ConnectionString = "Provider=Microsoft Jet 4.0 OLE DB Provider"+password;
	    accPath = ExtractFilePath(Application->ExeName)+"JXC.mdb";
	    if(FileExists(accPath))
	    {
	        accPath += ";Persist Security Info=False";
	        ConnectionString +=  accPath;
	        Form1->ADOConnection1->ConnectionString = ConnectionString;
	        Form1->ADOConnection1->Open();
	        if(Form1->ADOConnection1->Connected)
	        {
	          //  ShowMessage("数据库连接成功..");
	
	        }
	        else
	        {
	            ShowMessage("数据库连接错误");
	        }
	        Form1->ADOConnection1->Close();
	    }
	    else
	    {
	         ShowMessage("数据库文件不存在");
	        // return ;
	    }

             Form1->RK_ADOQuery->Close();
	     Form1->RK_ADOQuery->SQL->Clear();
	     Form1->RK_ADOQuery->SQL->Add("SELECT * FROM 入库");
	     Form1->RK_ADOQuery->Active= true;
	
	     Form1->RK_ADOTable->TableName = "RK";
	     Form1->RK_ADOTable->Open();
	
	     Form1->KC_ADOQuery->Close();
	     Form1->KC_ADOQuery->SQL->Clear();
	     Form1->KC_ADOQuery->SQL->Add("SELECT * FROM 库存");
	     Form1->KC_ADOQuery->Active= true;
	
	     Form1->KC_ADOTable->TableName = "KC";
	     Form1->KC_ADOTable->Open();
	
	     Form1->CK_ADOQuery->Close();
	     Form1->CK_ADOQuery->SQL->Clear();
	     Form1->CK_ADOQuery->SQL->Add("SELECT * FROM 出库");
	     Form1->CK_ADOQuery->Active= true;
	
	     Form1->CK_ADOTable->TableName = "CK";
	     Form1->CK_ADOTable->Open();

             Form1->XSTJ_ADOQuery->Close();
             Form1->XSTJ_ADOQuery->SQL->Clear();
             Form1->XSTJ_ADOQuery->SQL->Add("SELECT * FROM 销售统计");
             Form1->XSTJ_ADOQuery->Active= true;

             Form1->XSTJ_ADOTable->TableName = "XSTJ";
             Form1->XSTJ_ADOTable->Open();
	
	     Form1->PD_ADOQuery->Close();
	     Form1->PD_ADOQuery->SQL->Clear();
	     Form1->PD_ADOQuery->SQL->Add("SELECT * FROM 盘点");
	     Form1->PD_ADOQuery->Active= true;
	
	     Form1->PD_ADOTable->TableName = "PD";
	     Form1->PD_ADOTable->Open();

             Form1->PDTJ_ADOQuery->Close();
             Form1->PDTJ_ADOQuery->SQL->Clear();
             Form1->PDTJ_ADOQuery->SQL->Add("SELECT * FROM 盘点统计");
             Form1->PDTJ_ADOQuery->Active= true;

             Form1->PDTJ_ADOTable->TableName = "PDTJ";
             Form1->PDTJ_ADOTable->Open();
	
	     Form1->YK_ADOQuery->Close();
	     Form1->YK_ADOQuery->SQL->Clear();
	     Form1->YK_ADOQuery->SQL->Add("SELECT * FROM 移库");
	     Form1->YK_ADOQuery->Active= true;
	
	     Form1->YK_ADOTable->TableName = "YK";
	     Form1->YK_ADOTable->Open();
	
	     Form1->YD_ADOQuery->Close();
	     Form1->YD_ADOQuery->SQL->Clear();
	     Form1->YD_ADOQuery->SQL->Add("SELECT * FROM 验单");
	     Form1->YD_ADOQuery->Active= true;
	
	     Form1->YD_ADOTable->TableName = "YD";
	     Form1->YD_ADOTable->Open();
	
	     Form1->ADOQuery1->Close();
	     Form1->ADOQuery1->SQL->Clear();
	     Form1->ADOQuery1->SQL->Add("SELECT * FROM JBZL");
	     Form1->ADOQuery1->Active= true;
	
	
	     Form1->ADOTable1->TableName = "JBZL";
	     Form1->ADOTable1->Open();
	
	     Form1->YG_ADOQuery->Close();
	     Form1->YG_ADOQuery->SQL->Clear();
	     Form1->YG_ADOQuery->SQL->Add("SELECT * FROM YG");
	     Form1->YG_ADOQuery->Active= true;
	
	     Form1->YG_ADOTable->TableName = "YG";
	     Form1->YG_ADOTable->Open();
	
	     //Form1->DL_ADOTable->TableName = "DL";
	     //Form1->DL_ADOTable->Open();



   }
   else
   return;
}
//---------------------------------------------------------------------------
void __fastcall TForm16::BitBtn3Click(TObject *Sender)
{
    if(CheckBox1->Checked==True)
    {
        Form1->ADOCommand1->CommandText ="DELETE * FROM JBZL";
        Form1->ADOCommand1->Execute();

        Form1->ADOQuery1->Close();
        Form1->ADOQuery1->SQL->Clear();
        Form1->ADOQuery1->SQL->Add("SELECT * FROM JBZL");
        Form1->ADOQuery1->Active= true;

        Form1->RK_ADOQuery->Close();
        Form1->RK_ADOQuery->SQL->Clear();
        Form1->RK_ADOQuery->SQL->Add("SELECT * FROM 入库");
        Form1->RK_ADOQuery->Active= true;

        Form1->CK_ADOQuery->Close();
        Form1->CK_ADOQuery->SQL->Clear();
        Form1->CK_ADOQuery->SQL->Add("SELECT * FROM 出库");
        Form1->CK_ADOQuery->Active= true;

        Form1->KC_ADOQuery->Close();
        Form1->KC_ADOQuery->SQL->Clear();
        Form1->KC_ADOQuery->SQL->Add("SELECT * FROM 库存");
        Form1->KC_ADOQuery->Active= true;

        Form1->PD_ADOQuery->Close();
        Form1->PD_ADOQuery->SQL->Clear();
        Form1->PD_ADOQuery->SQL->Add("SELECT * FROM 盘点");
        Form1->PD_ADOQuery->Active= true;
    }

    if(CheckBox2->Checked==True)
    {
        Form1->ADOCommand1->CommandText ="DELETE * FROM RK";
        Form1->ADOCommand1->Execute();
        Form1->ADOCommand1->CommandText =" alter table [RK] alter column 编号 counter(1,1)";
        Form1->ADOCommand1->Execute();

        Form1->RK_ADOQuery->Close();
        Form1->RK_ADOQuery->SQL->Clear();
        Form1->RK_ADOQuery->SQL->Add("SELECT * FROM 入库");
        Form1->RK_ADOQuery->Active= true;
    }

    if(CheckBox3->Checked==True)
    {
        Form1->ADOCommand1->CommandText ="DELETE * FROM CK";
        Form1->ADOCommand1->Execute();
        Form1->ADOCommand1->CommandText =" alter table [CK] alter column 编号 counter(1,1)";
        Form1->ADOCommand1->Execute();

        Form1->CK_ADOQuery->Close();
        Form1->CK_ADOQuery->SQL->Clear();
        Form1->CK_ADOQuery->SQL->Add("SELECT * FROM 出库");
        Form1->CK_ADOQuery->Active= true;
    }

    if(CheckBox7->Checked==True)
    {
        Form1->ADOCommand1->CommandText ="DELETE * FROM KC";
        Form1->ADOCommand1->Execute();
        Form1->ADOCommand1->CommandText =" alter table [KC] alter column 编号 counter(1,1)";
        Form1->ADOCommand1->Execute();

        Form1->KC_ADOQuery->Close();
        Form1->KC_ADOQuery->SQL->Clear();
        Form1->KC_ADOQuery->SQL->Add("SELECT * FROM 库存");
        Form1->KC_ADOQuery->Active= true;

        Form1->PD_ADOQuery->Close();
        Form1->PD_ADOQuery->SQL->Clear();
        Form1->PD_ADOQuery->SQL->Add("SELECT * FROM 盘点");
        Form1->PD_ADOQuery->Active= true;
    }

    if(CheckBox4->Checked==True)
    {
        Form1->ADOCommand1->CommandText ="DELETE * FROM PD";
        Form1->ADOCommand1->Execute();
        Form1->ADOCommand1->CommandText =" alter table [PD] alter column 编号 counter(1,1)";
        Form1->ADOCommand1->Execute();

        Form1->PD_ADOQuery->Close();
        Form1->PD_ADOQuery->SQL->Clear();
        Form1->PD_ADOQuery->SQL->Add("SELECT * FROM 盘点");
        Form1->PD_ADOQuery->Active= true;
    }

    if(CheckBox5->Checked==True)
    {
        Form1->ADOCommand1->CommandText ="DELETE * FROM YK";
        Form1->ADOCommand1->Execute();
        Form1->ADOCommand1->CommandText =" alter table [YK] alter column 编号 counter(1,1)";
        Form1->ADOCommand1->Execute();

        Form1->YK_ADOQuery->Close();
        Form1->YK_ADOQuery->SQL->Clear();
        Form1->YK_ADOQuery->SQL->Add("SELECT * FROM 移库");
        Form1->YK_ADOQuery->Active= true;
    }

    if(CheckBox6->Checked==True)
    {
        Form1->ADOCommand1->CommandText ="DELETE * FROM YD";
        Form1->ADOCommand1->Execute();
        Form1->ADOCommand1->CommandText =" alter table [YD] alter column 编号 counter(1,1)";
        Form1->ADOCommand1->Execute();

        Form1->YD_ADOQuery->Close();
        Form1->YD_ADOQuery->SQL->Clear();
        Form1->YD_ADOQuery->SQL->Add("SELECT * FROM 验单");
        Form1->YD_ADOQuery->Active= true;
    }

    if(CheckBox8->Checked==True)
    {
        Form1->ADOCommand1->CommandText ="DELETE * FROM YG";
        Form1->ADOCommand1->Execute();

        Form1->YG_ADOTable->Insert();
        Form1->YG_ADOTable->FieldByName("员工编号")->AsString = "01";
        Form1->YG_ADOTable->FieldByName("密码")->AsString = "111111";
        Form1->YG_ADOTable->Post();

        Form1->YG_ADOQuery->Close();
        Form1->YG_ADOQuery->SQL->Clear();
        Form1->YG_ADOQuery->SQL->Add("SELECT * FROM YG");
        Form1->YG_ADOQuery->Active= true;

        Form1->YD_ADOQuery->Close();
        Form1->YD_ADOQuery->SQL->Clear();
        Form1->YD_ADOQuery->SQL->Add("SELECT * FROM 验单");
        Form1->YD_ADOQuery->Active= true;

        Form1->YK_ADOQuery->Close();
        Form1->YK_ADOQuery->SQL->Clear();
        Form1->YK_ADOQuery->SQL->Add("SELECT * FROM 移库");
        Form1->YK_ADOQuery->Active= true;

        Form1->RK_ADOQuery->Close();
        Form1->RK_ADOQuery->SQL->Clear();
        Form1->RK_ADOQuery->SQL->Add("SELECT * FROM 入库");
        Form1->RK_ADOQuery->Active= true;

        Form1->CK_ADOQuery->Close();
        Form1->CK_ADOQuery->SQL->Clear();
        Form1->CK_ADOQuery->SQL->Add("SELECT * FROM 出库");
        Form1->CK_ADOQuery->Active= true;

        Form1->PD_ADOQuery->Close();
        Form1->PD_ADOQuery->SQL->Clear();
        Form1->PD_ADOQuery->SQL->Add("SELECT * FROM 盘点");
        Form1->PD_ADOQuery->Active= true;
    }

    if(CheckBox9->Checked==True)
    {
        Form1->ADOCommand1->CommandText ="DELETE * FROM XSTJ";
        Form1->ADOCommand1->Execute();

        Form1->XSTJ_ADOQuery->Close();
        Form1->XSTJ_ADOQuery->SQL->Clear();
        Form1->XSTJ_ADOQuery->SQL->Add("SELECT * FROM 销售统计");
        Form1->XSTJ_ADOQuery->Active= true;
    }

    if(CheckBox10->Checked==True)
    {
        Form1->ADOCommand1->CommandText ="DELETE * FROM PDTJ";
        Form1->ADOCommand1->Execute();
        Form1->ADOCommand1->CommandText =" alter table [PDTJ] alter column 编号 counter(1,1)";
        Form1->ADOCommand1->Execute();

        Form1->XSTJ_ADOQuery->Close();
        Form1->XSTJ_ADOQuery->SQL->Clear();
        Form1->XSTJ_ADOQuery->SQL->Add("SELECT * FROM 盘点统计");
        Form1->XSTJ_ADOQuery->Active= true;
    }



    ShowMessage("清空完成");
}
//---------------------------------------------------------------------------
void __fastcall TForm16::FormShow(TObject *Sender)
{
      if(Form1->LoginName=="01")
     {
        BitBtn1->Enabled=true;
        BitBtn2->Enabled=true;
        BitBtn3->Enabled=true;
     }
}
//---------------------------------------------------------------------------

