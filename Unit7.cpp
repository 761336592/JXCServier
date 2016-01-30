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
//String exportPD[]={"条码","盘点库存","盘点时间","仓库","员工编号","员工姓名","名称","货号","规格","型号","进价","售价","单位","备注一","备注二","备注三"};
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
       str1="SELECT * FROM 盘点统计";
       str2="SELECT sum(盘点库存) AS 盘点总库存 , sum(库存) AS 总库存 FROM 盘点统计";
    }
    else if(RadioButton2->Checked==True)
    {
       str1="SELECT * FROM 盘点统计 WHERE 盘点库存 > 库存 OR (盘点库存 > 0 AND 库存 IS NULL)";
       str2="SELECT sum(盘点库存) AS 盘点总库存 , sum(库存) AS 总库存 FROM 盘点统计 WHERE 盘点库存 > 库存 OR (盘点库存 > 0 AND 库存 IS NULL)";
    }
    else  if(RadioButton3->Checked==True)
    {
       str1="SELECT * FROM 盘点统计 WHERE 盘点库存 < 库存 OR (盘点库存 < 0 AND 库存 IS NULL)";
       str2="SELECT sum(盘点库存) AS 盘点总库存 , sum(库存) AS 总库存 FROM 盘点统计 WHERE 盘点库存 < 库存 OR (盘点库存 < 0 AND 库存 IS NULL)";
    }
    else
    {
       str1="SELECT * FROM 漏盘 WHERE 盘点库存 IS NULL";
       str2="SELECT sum(盘点库存) AS 盘点总库存 , sum(库存) AS 总库存 FROM 漏盘 WHERE 盘点库存 IS NULL";
    }


   /* {
         str="SELECT KC.*, PDTJ.盘点库存, JBZL.名称, JBZL.货号, JBZL.规格, JBZL.型号, JBZL.进价, JBZL.售价, JBZL.单位, JBZL.备注一, JBZL.备注二, JBZL.备注三 FROM (KC LEFT JOIN PDTJ ON (KC.仓库 = PDTJ.仓库) AND (KC.条码 = PD.条码)) LEFT JOIN JBZL ON KC.条码 = JBZL.条码 WHERE 盘点库存 IS NULL";
    } */


    Form1->PDTJ_ADOQuery->Close();
    Form1->PDTJ_ADOQuery->SQL->Clear();
    Form1->PDTJ_ADOQuery->SQL->Add(str1);
    Form1->PDTJ_ADOQuery->Active= true;

    Form1->Search_ADOQuery->Close();
    Form1->Search_ADOQuery->SQL->Clear();
    Form1->Search_ADOQuery->SQL->Add(str2);
    Form1->Search_ADOQuery->Active= true;


    StatusBar1->Panels->Items[0]->Text="查询结果    总条数： "+String(Form1->PDTJ_ADOQuery->RecordCount)+"    盘点总库存： "+Form1->Search_ADOQuery->FieldByName("盘点总库存")->AsString+"    实际总库存： "+Form1->Search_ADOQuery->FieldByName("总库存")->AsString;

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
         FileName="盘点汇总表";
      else if(RadioButton2->Checked==true)
         FileName="盘盈表";
      else if(RadioButton3->Checked==true)
         FileName="盘亏表";
      else if(RadioButton4->Checked==true)
         FileName="漏盘表";

      String datetime= Now().FormatString("yyyymmddhhnnss");
      SaveList->Text="";
      for(int i=0;i<selectnum;i++)
      {
             str="";
           //  RK_Grid->Columns->Items[0]->Field->
             str="PDTJ,"+
                 Form1->PDTJ_ADOQuery->FieldByName("条码")->AsString+","+
                 Form1->PDTJ_ADOQuery->FieldByName("名称")->AsString+","+
                 Form1->PDTJ_ADOQuery->FieldByName("货号")->AsString+","+
                 Form1->PDTJ_ADOQuery->FieldByName("规格")->AsString+","+
                 Form1->PDTJ_ADOQuery->FieldByName("型号")->AsString+",";
                 if(Form1->Pshow=="show")str+=Form1->PDTJ_ADOQuery->FieldByName("进价")->AsString+",";
                 str+=Form1->PDTJ_ADOQuery->FieldByName("售价")->AsString+","+
                 Form1->PDTJ_ADOQuery->FieldByName("单位")->AsString+","+
                 Form1->PDTJ_ADOQuery->FieldByName("备注一")->AsString+","+
                 Form1->PDTJ_ADOQuery->FieldByName("备注二")->AsString+","+
                 Form1->PDTJ_ADOQuery->FieldByName("备注三")->AsString+","+
                 Form1->PDTJ_ADOQuery->FieldByName("盘点库存")->AsString+",";
                 if(Form1->KCshow=="show")str+=Form1->PDTJ_ADOQuery->FieldByName("库存")->AsString+",";
                 str+=Form1->PDTJ_ADOQuery->FieldByName("仓库")->AsString;
             SaveList->Add(str);

             Form1->PDTJ_ADOQuery->Next();
      }
      Form1->SaveExcel(SaveList,Dir.Trim()+FileName+"-"+datetime+".xls") ;
      MessageDlg("导出完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

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
      if (DBGrid1->Tag==0) //顺序排列
      {
         Form1->PDTJ_ADOQuery->Sort=Column->FieldName+" ASC";
         DBGrid1->Tag=1;
      }
      else   //反序排列,改变字体颜色
      {
         Form1->PDTJ_ADOQuery->Sort=Column->FieldName+" DESC";
         DBGrid1->Tag=0;
      }
  }        
}
//---------------------------------------------------------------------------

