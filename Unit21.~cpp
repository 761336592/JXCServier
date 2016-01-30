//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <FileCtrl.hpp>

#include "Unit21.h"
#include "Unit1.h"
#include "Unit6.h"
#include "Unit24.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm21 *Form21;
//---------------------------------------------------------------------------
__fastcall TForm21::TForm21(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm21::FormCreate(TObject *Sender)
{
      for(int i=0;i<DBGrid1->Columns->Count;i++)
      DBGrid1->Columns->Items[i]->Width=(DBGrid1->Width-50)/DBGrid1->Columns->Count;
}
//---------------------------------------------------------------------------
void __fastcall TForm21::BitBtn1Click(TObject *Sender)
{
    String str1="";
    String str2="";
    String str="";
    int index=1;
    index=1;
    str1="SELECT * FROM 销售统计 WHERE";
    str2="SELECT sum(成本) AS 总成本 , sum(利润) AS 总利润 , sum(销售额) AS 总销售额 FROM 销售统计 WHERE";
    str="";
    if(CheckBox1->Checked==True)
    {
        // str=str+" "+SelectINF[ComboBox1->ItemIndex]+" like '%"+Check_CK_bar->Text.Trim()+"%'";
       str=str+" 出库单据 like '%"+Edit1->Text.Trim()+"%'";
       index=0;
    }
    if(CheckBox2->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 时间 >= \""+DateTimePicker1->DateTime.FormatString("yyyy-mm-dd")+"\"";
        //if(Check_CK_date2->Text.Trim().Length()!=0)
        //{
           str=str+" AND";
           str=str+" 时间 <= \""+DateTimePicker2->DateTime.FormatString("yyyy-mm-dd")+"\"";
        //}
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


    if(CheckBox1->Checked==False&&CheckBox2->Checked==False&&CheckBox3->Checked==False&&CheckBox4->Checked==False)
    {
            str1="SELECT * FROM 销售统计";
            str2="SELECT sum(成本) AS 总成本 , sum(利润) AS 总利润 , sum(销售额) AS 总销售额 FROM 销售统计";
            str="";
    }
    //MessageDlg(str,mtInformation,TMsgDlgButtons()<<mbOK,0);
    Form1->XSTJ_ADOQuery->Close();
    Form1->XSTJ_ADOQuery->SQL->Clear();
    Form1->XSTJ_ADOQuery->SQL->Add(str1+str);
    Form1->XSTJ_ADOQuery->Active= true;

    Form1->Search_ADOQuery->Close();
    Form1->Search_ADOQuery->SQL->Clear();
    Form1->Search_ADOQuery->SQL->Add(str2+str);
    Form1->Search_ADOQuery->Active= true;



    if(Form1->Pshow=="show")
    StatusBar1->Panels->Items[0]->Text="查询结果    总条数： "+String(Form1->XSTJ_ADOQuery->RecordCount)+"    总成本： "+Form1->Search_ADOQuery->FieldByName("总成本")->AsString+"    总销售额： "+Form1->Search_ADOQuery->FieldByName("总销售额")->AsString+"    总利润： "+Form1->Search_ADOQuery->FieldByName("总利润")->AsString;
    else
    StatusBar1->Panels->Items[0]->Text="查询结果    总条数： "+String(Form1->XSTJ_ADOQuery->RecordCount)+"    总销售额： "+Form1->Search_ADOQuery->FieldByName("总销售额")->AsString+"    总利润： "+Form1->Search_ADOQuery->FieldByName("总利润")->AsString;
}
//---------------------------------------------------------------------------
void __fastcall TForm21::DBGrid1CellClick(TColumn *Column)
{
   if(DBGrid1->Columns->Grid->Fields[0]->IsNull==false)Edit1->Text=DBGrid1->Columns->Grid->Fields[0]->Value;
   if(DBGrid1->Columns->Grid->Fields[5]->IsNull==false)Edit3->Text=DBGrid1->Columns->Grid->Fields[5]->Value;
   if(DBGrid1->Columns->Grid->Fields[6]->IsNull==false)Edit4->Text=DBGrid1->Columns->Grid->Fields[6]->Value;

}
//---------------------------------------------------------------------------

void __fastcall TForm21::FormShow(TObject *Sender)
{
    if(Form1->Pshow=="show")
    {
        DBGrid1->Columns->Items[1]->Visible=true;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm21::DBGrid1TitleClick(TColumn *Column)
{
  String s;
  if(Form1->XSTJ_ADOQuery->Active)
  {
      if (DBGrid1->Tag==0) //顺序排列
      {
         Form1->XSTJ_ADOQuery->Sort=Column->FieldName+" ASC";
         DBGrid1->Tag=1;
      }
      else   //反序排列,改变字体颜色
      {
         Form1->XSTJ_ADOQuery->Sort=Column->FieldName+" DESC";
         DBGrid1->Tag=0;
      }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm21::DBGrid1DblClick(TObject *Sender)
{
//if(DBGrid1->Columns->Grid->Fields[0]->IsNull==false)Edit1->Text=DBGrid1->Columns->Grid->Fields[0]->Value;
    //MessageDlg(str,mtInformation,TMsgDlgButtons()<<mbOK,0);
    Form1->XSXQ_ADOQuery->Close();
    Form1->XSXQ_ADOQuery->SQL->Clear();
    Form1->XSXQ_ADOQuery->SQL->Add("SELECT * FROM 出库 where 出库单据 = \""+DBGrid1->Columns->Grid->Fields[0]->Value+"\"");
    Form1->XSXQ_ADOQuery->Active= true;

    Form24->Caption="销售单据："+DBGrid1->Columns->Grid->Fields[0]->Value;
    Form24->Show();

}
//---------------------------------------------------------------------------

void __fastcall TForm21::BitBtn2Click(TObject *Sender)
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
      int selectnum=Form1->XSTJ_ADOQuery->RecordCount;
      String str="";
      String FileName="销售利润统计表";
      String datetime= Now().FormatString("yyyymmddhhnnss");
      SaveList->Text="";
      for(int i=0;i<selectnum;i++)
      {
             str="";
           //  RK_Grid->Columns->Items[0]->Field->
             str="XSTJ,"+
                 Form1->XSTJ_ADOQuery->FieldByName("出库单据")->AsString+","+
                 Form1->XSTJ_ADOQuery->FieldByName("成本")->AsString+","+
                 Form1->XSTJ_ADOQuery->FieldByName("销售额")->AsString+","+
                 Form1->XSTJ_ADOQuery->FieldByName("利润")->AsString+","+
                 Form1->XSTJ_ADOQuery->FieldByName("时间")->AsString+","+
                 Form1->XSTJ_ADOQuery->FieldByName("员工编号")->AsString+","+
                 Form1->XSTJ_ADOQuery->FieldByName("员工姓名")->AsString
                 ;
             SaveList->Add(str);
             Form1->XSTJ_ADOQuery->Next();
      }
      Form1->SaveExcel(SaveList,Dir.Trim()+FileName+"-"+datetime+".xls") ;
      MessageDlg("导出完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

      delete SaveList;
   }
   else
   return;
}
//---------------------------------------------------------------------------

