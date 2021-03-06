//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <FileCtrl.hpp>

#include "Unit10.h"
#include "Unit1.h"
#include "Unit31.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm10 *Form10;
//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm10::FormShow(TObject *Sender)
{
    DBGrid1->Columns->Items[1]->Title->Caption=Form1->infshow1;
    DBGrid1->Columns->Items[2]->Title->Caption=Form1->infshow2;
    DBGrid1->Columns->Items[3]->Title->Caption=Form1->infshow3;
    DBGrid1->Columns->Items[4]->Title->Caption=Form1->infshow4;
    DBGrid1->Columns->Items[5]->Title->Caption=Form1->infshow5;
    DBGrid1->Columns->Items[6]->Title->Caption=Form1->infshow6;
    DBGrid1->Columns->Items[7]->Title->Caption=Form1->infshow7;
    DBGrid1->Columns->Items[8]->Title->Caption=Form1->infshow8;
    DBGrid1->Columns->Items[9]->Title->Caption=Form1->infshow9;
    DBGrid1->Columns->Items[10]->Title->Caption=Form1->infshow10;
    DBGrid1->Columns->Items[11]->Title->Caption=Form1->infshow11;

    ComboBox1->Clear();
    ComboBox1->Items->Add("条码");
    ComboBox1->Items->Add(Form1->infshow2);
    ComboBox1->Items->Add(Form1->infshow3);
    ComboBox1->Items->Add(Form1->infshow4);
    ComboBox1->Items->Add(Form1->infshow5);
    ComboBox1->Items->Add(Form1->infshow6);
    ComboBox1->Items->Add(Form1->infshow7);
    ComboBox1->Items->Add(Form1->infshow8);
    ComboBox1->Items->Add(Form1->infshow9);
    ComboBox1->Items->Add(Form1->infshow10);
    ComboBox1->Items->Add(Form1->infshow11);
    ComboBox1->ItemIndex=0;

    if(Form1->Pshow=="show")
    {
       DBGrid1->Columns->Items[6]->Visible=true;
    }

}
//---------------------------------------------------------------------------
void __fastcall TForm10::BitBtn1Click(TObject *Sender)
{
    String str1="";
    String str2="";
    String str="";
    int index=1;
    String SelectINF[]={"条码","名称","货号","规格","型号","进价","售价","单位","备注一","备注二","备注三"};
    index=1;
    str1="SELECT * FROM 验单 WHERE";
    str2="SELECT sum(应扫数量) AS 应扫总数量 , sum(已扫数量) AS 已扫总数量 FROM 验单 WHERE";
    str="";
    if(CheckBox1->Checked==True)
    {
       str=str+" "+SelectINF[ComboBox1->ItemIndex]+" like \"%"+Edit1->Text.Trim()+"%\"";
       index=0;
    }
    if(CheckBox5->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 时间 >= \""+DateTimePicker1->DateTime.FormatString("yyyy-mm-dd")+"\"";

        str=str+" AND";
        str=str+" 时间 <= \""+DateTimePicker2->DateTime.FormatString("yyyy-mm-dd")+"\"";

        index=0;
    }
    if(CheckBox2->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 单据 like \"%"+Edit2->Text.Trim()+"%\"";
        index=0;
    }


    if(CheckBox3->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 员工编号 like \""+Edit3->Text.Trim()+"\"";
        index=0;
    }

    if(CheckBox4->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 员工姓名 like \""+Edit4->Text.Trim()+"\"";
        index=0;
    }

    if(CheckBox1->Checked==False&&CheckBox2->Checked==False&&CheckBox3->Checked==False&&CheckBox4->Checked==False&&CheckBox5->Checked==False)
    {
            str="";
            str1="SELECT * FROM 验单";
            str2="SELECT sum(应扫数量) AS 应扫总数量 , sum(已扫数量) AS 已扫总数量 FROM 验单";
    }
    //MessageDlg(str,mtInformation,TMsgDlgButtons()<<mbOK,0);
    Form1->YD_ADOQuery->Close();
    Form1->YD_ADOQuery->SQL->Clear();
    Form1->YD_ADOQuery->SQL->Add(str1+str);
    Form1->YD_ADOQuery->Active= true;

    Form1->Search_ADOQuery->Close();
    Form1->Search_ADOQuery->SQL->Clear();
    Form1->Search_ADOQuery->SQL->Add(str2+str);
    Form1->Search_ADOQuery->Active= true;


    StatusBar1->Panels->Items[0]->Text="查询结果    总条数： "+String(Form1->YD_ADOQuery->RecordCount)+"    应扫总数量： "+Form1->Search_ADOQuery->FieldByName("应扫总数量")->AsString+"    已扫总数量： "+Form1->Search_ADOQuery->FieldByName("已扫总数量")->AsString;

}
//---------------------------------------------------------------------------
void __fastcall TForm10::FormCreate(TObject *Sender)
{
      for(int i=0;i<DBGrid1->Columns->Count;i++)
      DBGrid1->Columns->Items[i]->Width=(DBGrid1->Width-50)/DBGrid1->Columns->Count;

      DateTimePicker1->Date=Now();
      DateTimePicker2->Date=Now();
}
//---------------------------------------------------------------------------

void __fastcall TForm10::BitBtn2Click(TObject *Sender)
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
      int selectnum=Form1->YD_ADOQuery->RecordCount;
      String str="";
      String FileName="验单表";
      String datetime= Now().FormatString("yyyymmddhhnnss");
      SaveList->Text="";
      for(int i=0;i<selectnum;i++)
      {
             str="";
           //  RK_Grid->Columns->Items[0]->Field->
             str="YD,"+
                 Form1->YD_ADOQuery->FieldByName("单据")->AsString+","+
                 Form1->YD_ADOQuery->FieldByName("条码")->AsString+","+
                 Form1->YD_ADOQuery->FieldByName("名称")->AsString+","+
                 Form1->YD_ADOQuery->FieldByName("货号")->AsString+","+
                 Form1->YD_ADOQuery->FieldByName("规格")->AsString+","+
                 Form1->YD_ADOQuery->FieldByName("型号")->AsString+",";
             if(Form1->Pshow=="show")str+=Form1->YD_ADOQuery->FieldByName("进价")->AsString+",";
             str+=Form1->YD_ADOQuery->FieldByName("售价")->AsString+","+
                 Form1->YD_ADOQuery->FieldByName("单位")->AsString+","+
                 Form1->YD_ADOQuery->FieldByName("备注一")->AsString+","+
                 Form1->YD_ADOQuery->FieldByName("备注二")->AsString+","+
                 Form1->YD_ADOQuery->FieldByName("备注三")->AsString+","+
                 Form1->YD_ADOQuery->FieldByName("应扫数量")->AsString+","+
                 Form1->YD_ADOQuery->FieldByName("已扫数量")->AsString+","+
                 Form1->YD_ADOQuery->FieldByName("时间")->AsString+","+
                 Form1->YD_ADOQuery->FieldByName("员工编号")->AsString+","+
                 Form1->YD_ADOQuery->FieldByName("员工姓名")->AsString;
             SaveList->Add(str);
             Form1->YD_ADOQuery->Next();
      }
      Form1->SaveExcel(SaveList,Dir.Trim()+FileName+"-"+datetime+".xls") ;
      MessageDlg("导出完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

      delete SaveList;
   }
   else
   return;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::BitBtn3Click(TObject *Sender)
{
    Form1->YD_ADOQuery->Close();
    Form1->YD_ADOQuery->SQL->Clear();
    Form1->YD_ADOQuery->SQL->Add("SELECT * FROM 验单 WHERE 应扫数量 = 已扫数量");
    Form1->YD_ADOQuery->Active= true;

    Form1->Search_ADOQuery->Close();
    Form1->Search_ADOQuery->SQL->Clear();
    Form1->Search_ADOQuery->SQL->Add("SELECT sum(应扫数量) AS 应扫总数量 , sum(已扫数量) AS 已扫总数量 FROM 验单 WHERE 应扫数量 = 已扫数量");
    Form1->Search_ADOQuery->Active= true;

    StatusBar1->Panels->Items[0]->Text="查询结果    总条数： "+String(Form1->YD_ADOQuery->RecordCount)+"    应扫总数量： "+Form1->Search_ADOQuery->FieldByName("应扫总数量")->AsString+"    已扫总数量： "+Form1->Search_ADOQuery->FieldByName("已扫总数量")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::BitBtn4Click(TObject *Sender)
{
    Form1->YD_ADOQuery->Close();
    Form1->YD_ADOQuery->SQL->Clear();
    Form1->YD_ADOQuery->SQL->Add("SELECT * FROM 验单 WHERE 应扫数量 > 已扫数量");
    Form1->YD_ADOQuery->Active= true;
    Form1->Search_ADOQuery->Close();
    Form1->Search_ADOQuery->SQL->Clear();
    Form1->Search_ADOQuery->SQL->Add("SELECT sum(应扫数量) AS 应扫总数量 , sum(已扫数量) AS 已扫总数量 FROM 验单 WHERE 应扫数量 > 已扫数量");
    Form1->Search_ADOQuery->Active= true;

    StatusBar1->Panels->Items[0]->Text="查询结果    总条数： "+String(Form1->YD_ADOQuery->RecordCount)+"    应扫总数量： "+Form1->Search_ADOQuery->FieldByName("应扫总数量")->AsString+"    已扫总数量： "+Form1->Search_ADOQuery->FieldByName("已扫总数量")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::BitBtn5Click(TObject *Sender)
{
    Form1->YD_ADOQuery->Close();
    Form1->YD_ADOQuery->SQL->Clear();
    Form1->YD_ADOQuery->SQL->Add("SELECT * FROM 验单 WHERE 应扫数量 < 已扫数量");
    Form1->YD_ADOQuery->Active= true;
    Form1->Search_ADOQuery->Close();
    Form1->Search_ADOQuery->SQL->Clear();
    Form1->Search_ADOQuery->SQL->Add("SELECT sum(应扫数量) AS 应扫总数量 , sum(已扫数量) AS 已扫总数量 FROM 验单 WHERE 应扫数量 < 已扫数量");
    Form1->Search_ADOQuery->Active= true;

    StatusBar1->Panels->Items[0]->Text="查询结果    总条数： "+String(Form1->YD_ADOQuery->RecordCount)+"    应扫总数量： "+Form1->Search_ADOQuery->FieldByName("应扫总数量")->AsString+"    已扫总数量： "+Form1->Search_ADOQuery->FieldByName("已扫总数量")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TForm10::DBGrid1TitleClick(TColumn *Column)
{
  String s;
  if(Form1->YD_ADOQuery->Active)
  {
      if (DBGrid1->Tag==0) //顺序排列
      {
         Form1->YD_ADOQuery->Sort=Column->FieldName+" ASC";
         DBGrid1->Tag=1;
      }
      else   //反序排列,改变字体颜色
      {
         Form1->YD_ADOQuery->Sort=Column->FieldName+" DESC";
         DBGrid1->Tag=0;
      }
  }        
}
//---------------------------------------------------------------------------

void __fastcall TForm10::DBGrid1CellClick(TColumn *Column)
{
   if(DBGrid1->Columns->Grid->Fields[ComboBox1->ItemIndex+1]->IsNull==false)Edit1->Text=DBGrid1->Columns->Grid->Fields[ComboBox1->ItemIndex+1]->Value;
   if(DBGrid1->Columns->Grid->Fields[0]->IsNull==false)Edit2->Text=DBGrid1->Columns->Grid->Fields[0]->Value;
   if(DBGrid1->Columns->Grid->Fields[15]->IsNull==false)Edit3->Text=DBGrid1->Columns->Grid->Fields[15]->Value;
   if(DBGrid1->Columns->Grid->Fields[16]->IsNull==false)Edit4->Text=DBGrid1->Columns->Grid->Fields[16]->Value;
}
//---------------------------------------------------------------------------


void __fastcall TForm10::ComboBox1Change(TObject *Sender)
{
      if(Form1->Pshow=="unshow")
      {
         if(ComboBox1->Text=="进价")
         {
             Edit1->Visible=false;
             CheckBox1->Checked=false;
             CheckBox1->Enabled=false;
         }
         else
         {
             Edit1->Text="";
             Edit1->Visible=true;
             CheckBox1->Enabled=true;
         }
      }
}
//---------------------------------------------------------------------------

void __fastcall TForm10::Button1Click(TObject *Sender)
{
       if(CheckBox2->Checked==false||Edit2->Text.Trim().Length()==0)
       {
           ShowMessage("只能按照单据打印，请先填写单据号！");
           return;
       }

       BitBtn1Click(Sender);

       Form31->Show();
}
//---------------------------------------------------------------------------

