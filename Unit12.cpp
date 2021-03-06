//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <FileCtrl.hpp>

#include "Unit12.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm12 *Form12;
//---------------------------------------------------------------------------
__fastcall TForm12::TForm12(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm12::FormShow(TObject *Sender)
{
    DBGrid1->Columns->Items[0]->Title->Caption=Form1->infshow1;
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

void __fastcall TForm12::BitBtn1Click(TObject *Sender)
{
    String str1="";
    String str2="";
    String str="";
    int index=1;
    String SelectINF[]={"条码","名称","货号","规格","型号","进价","售价","单位","备注一","备注二","备注三"};
    index=1;
    str="";
    str1="SELECT * FROM 库存 WHERE";
    str2="SELECT sum(入库数量) AS 入库总数量 , sum(出库数量) AS 出库总数量 , sum(库存) AS 总库存 FROM 库存 WHERE";
    if(KCbar->Checked==True)
    {
       str=str+" "+SelectINF[ComboBox1->ItemIndex]+" like \"%"+KC_bar->Text.Trim()+"%\"";
       index=0;
    }
    if(KCck->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 仓库 like \""+KC_ck->Text.Trim()+"\"";
        index=0;
    }

    if(KCbar->Checked==False&&KCck->Checked==False)
    {
            str="";
            str1="SELECT * FROM 库存";
            str2="SELECT sum(入库数量) AS 入库总数量 , sum(出库数量) AS 出库总数量 , sum(库存) AS 总库存 FROM 库存";
    }

    Form1->KC_ADOQuery->Close();
    Form1->KC_ADOQuery->SQL->Clear();
    Form1->KC_ADOQuery->SQL->Add(str1+str);
    Form1->KC_ADOQuery->Active= true;

    Form1->Search_ADOQuery->Close();
    Form1->Search_ADOQuery->SQL->Clear();
    Form1->Search_ADOQuery->SQL->Add(str2+str);
    Form1->Search_ADOQuery->Active= true;

    StatusBar1->Panels->Items[0]->Text="查询结果    总条数： "+String(Form1->KC_ADOQuery->RecordCount)+"    入库总数量： "+Form1->Search_ADOQuery->FieldByName("入库总数量")->AsString+"    出库总数量： "+Form1->Search_ADOQuery->FieldByName("出库总数量")->AsString+"    总库存： "+Form1->Search_ADOQuery->FieldByName("总库存")->AsString;
}
//---------------------------------------------------------------------------
void __fastcall TForm12::FormCreate(TObject *Sender)
{
      for(int i=0;i<DBGrid1->Columns->Count;i++)
      DBGrid1->Columns->Items[i]->Width=(DBGrid1->Width-50)/DBGrid1->Columns->Count;        
}
//---------------------------------------------------------------------------

void __fastcall TForm12::DBGrid1TitleClick(TColumn *Column)
{
  String s;
  if(Form1->KC_ADOQuery->Active)
  {
      if (DBGrid1->Tag==0) //顺序排列
      {
         Form1->KC_ADOQuery->Sort=Column->FieldName+" ASC";
         DBGrid1->Tag=1;
      }
      else   //反序排列,改变字体颜色
      {
         Form1->KC_ADOQuery->Sort=Column->FieldName+" DESC";
         DBGrid1->Tag=0;
      }
  }        
}
//---------------------------------------------------------------------------

void __fastcall TForm12::BitBtn2Click(TObject *Sender)
{
    String ss="Provider=Microsoft.Jet.OLEDB.4.0;Data Source="+ExtractFilePath(Application->ExeName)+"库存导入.xls;Mode=Share Deny None;Extended Properties=\"Excel 8.0;IMEX=1;\";Persist Security Info=False" ;
    Form1->con1->Close();
    Form1->con1->ConnectionString=ss;
    Form1->con1->Connected  =   true;
    Form1->qry1->Close();
    Form1->qry1->SQL->Clear();
    Form1->qry1->SQL->Add("select * from [Sheet1$]");
    Form1->qry1->Open();
    Form1->qry1->Active=true;


    int num0=0;
    int num1=0;
    int num2=0;

    int index=0;
    for(int i=0;;i++)
    {
        if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="条码"){num0=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="仓库"){num1=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="库存"){num2=i;index++;}
        if(index==3)break;
    }

    String str="";
    Double kc=0;
    String name="";
    String CK="";


    int indexshow=0;
    while(!Form1->qry1->Eof) //循环写入数据库
    {
        if(Form1->qry1->Fields->Fields[num0]->AsString.Trim().Length()==0)
        {
           Form1->qry1->Next();
           continue;
        }
        indexshow++;
        Form1->StatusBar1->Panels->Items[0]->Text="正在导入资料    条数： "+String(indexshow);
        if(Form1->qry1->Fields->Fields[num1]->AsString.Trim().Length()==0) CK="CK001";
        else{
             CK=Form1->qry1->Fields->Fields[num1]->AsString.Trim();
        }
        if(Form1->qry1->Fields->Fields[num2]->AsString.Trim().Length()==0)kc=0;
        else
        {
            try
            {
               kc=Form1->qry1->Fields->Fields[num2]->AsString.Trim().ToDouble();
            }
            catch(...)
            {
               kc=0;
            }
        }

        //查询库存是否存在 ，如果存在直接更新，如果不存在先搜索名称以后再添加进去
        str="";
        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM KC WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",Form1->qry1->Fields->Fields[num0]->AsString.Trim(),Form1->qry1->Fields->Fields[num1]->AsString.Trim());
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;



        if(Form1->Search_ADOQuery->RecordCount==0)
        {
            Form1->KC_ADOTable->Insert();
            Form1->KC_ADOTable->FieldByName("条码")->AsString = Form1->qry1->Fields->Fields[num0]->AsString.Trim();
          /*  if(Form1->qry1->Fields->Fields[num1]->AsString.Trim().Length()!=0)Form1->KC_ADOTable->FieldByName("仓库")->AsString = Form1->qry1->Fields->Fields[num1]->AsString.Trim();
            else Form1->KC_ADOTable->FieldByName("仓库")->AsString = "CK001"; */
            Form1->KC_ADOTable->FieldByName("仓库")->AsString=CK;
            Form1->KC_ADOTable->FieldByName("库存")->AsFloat = kc;
            Form1->KC_ADOTable->Post();
         }
         else
         {

            str="";
            str=String().sprintf("UPDATE KC SET   库存 =%f  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                 ,Form1->Search_ADOQuery->FieldByName("库存")->AsFloat+kc
                                 ,Form1->qry1->Fields->Fields[num0]->AsString.Trim()
                                 ,CK);
            Form1->ADOCommand1->CommandText = str;
            Form1->ADOCommand1->Execute();
         }
        Application->ProcessMessages();
        //
        Form1->qry1->Next();
    }

    Form1->con1->Close();
    Form1->qry1->Close();
    Form1->qry1->SQL->Clear();
    Form1->KC_ADOQuery->Close();
    Form1->KC_ADOQuery->SQL->Clear();
    Form1->KC_ADOQuery->SQL->Add("SELECT * FROM 库存");
    Form1->KC_ADOQuery->Active= true;
    MessageDlg("导入完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

    StatusBar1->Panels->Items[0]->Text="查询结果    条数： "+String(Form1->KC_ADOQuery->RecordCount);
}
//---------------------------------------------------------------------------

void __fastcall TForm12::BitBtn3Click(TObject *Sender)
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
      int selectnum=Form1->KC_ADOQuery->RecordCount;
      String str="";
      String FileName="库存表";
      String datetime= Now().FormatString("yyyymmddhhnnss");
      SaveList->Text="";
      for(int i=0;i<selectnum;i++)
      {
             str="";
           //  RK_Grid->Columns->Items[0]->Field->
             str="KC,"+
                 Form1->KC_ADOQuery->FieldByName("条码")->AsString+","+
                 Form1->KC_ADOQuery->FieldByName("名称")->AsString+","+
                 Form1->KC_ADOQuery->FieldByName("货号")->AsString+","+
                 Form1->KC_ADOQuery->FieldByName("规格")->AsString+","+
                 Form1->KC_ADOQuery->FieldByName("型号")->AsString+",";
             if(Form1->Pshow=="show")str+=Form1->KC_ADOQuery->FieldByName("进价")->AsString+",";
             str+=Form1->KC_ADOQuery->FieldByName("售价")->AsString+","+
                 Form1->KC_ADOQuery->FieldByName("单位")->AsString+","+
                 Form1->KC_ADOQuery->FieldByName("备注一")->AsString+","+
                 Form1->KC_ADOQuery->FieldByName("备注二")->AsString+","+
                 Form1->KC_ADOQuery->FieldByName("备注三")->AsString+","+
                 Form1->KC_ADOQuery->FieldByName("入库数量")->AsString+","+
                 Form1->KC_ADOQuery->FieldByName("出库数量")->AsString+","+
                 Form1->KC_ADOQuery->FieldByName("仓库")->AsString+","+
                 Form1->KC_ADOQuery->FieldByName("库存")->AsString;
             SaveList->Add(str);
             Form1->KC_ADOQuery->Next();
      }
      Form1->SaveExcel(SaveList,Dir.Trim()+FileName+"-"+datetime+".xls") ;
      MessageDlg("导出完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

      delete SaveList;
   }
   else
   return;
}
//---------------------------------------------------------------------------

void __fastcall TForm12::DBGrid1CellClick(TColumn *Column)
{

   if(ComboBox1->ItemIndex==0){if(DBGrid1->Columns->Grid->Fields[ComboBox1->ItemIndex]->IsNull==false)KC_bar->Text=DBGrid1->Columns->Grid->Fields[ComboBox1->ItemIndex]->Value;}
   else {if(DBGrid1->Columns->Grid->Fields[ComboBox1->ItemIndex+1]->IsNull==false)KC_bar->Text=DBGrid1->Columns->Grid->Fields[ComboBox1->ItemIndex+1]->Value; }
   if(DBGrid1->Columns->Grid->Fields[14]->IsNull==false)KC_ck->Text=DBGrid1->Columns->Grid->Fields[14]->Value;
}
//---------------------------------------------------------------------------

void __fastcall TForm12::ComboBox1Change(TObject *Sender)
{
      if(Form1->Pshow=="unshow")
      {
         if(ComboBox1->Text=="进价")
         {
             KC_bar->Visible=false;
             KCbar->Checked=false;
             KCbar->Enabled=false;
         }
         else
         {
             KC_bar->Text="";
             KC_bar->Visible=true;
             KCbar->Enabled=true;
         }
      }
}
//---------------------------------------------------------------------------

void __fastcall TForm12::Button1Click(TObject *Sender)
{
   BitBtn1Click(Sender);

   String Dir;
   if(SelectDirectory("Directory Name","",Dir))
   {
         if(Dir.SubString(Dir.Length(),1)!="\\")
         {
                   Dir=Dir+"\\";
         }
        try
        {
              TStringList *SaveList=new TStringList();
              int selectnum=Form1->KC_ADOQuery->RecordCount;
              String str="";
              SaveList->Text="";
              for(int i=0;i<selectnum;i++)
              {
                 str="";
                 str=
                 Form1->KC_ADOQuery->FieldByName("条码")->AsString+","+
                 Form1->KC_ADOQuery->FieldByName("库存")->AsString+","+
                 Form1->KC_ADOQuery->FieldByName("仓库")->AsString;
                 SaveList->Add(str);
                 Form1->KC_ADOQuery->Next();
               }
               SaveList->Add("");
              String FileName="DRKC";
              SaveList->SaveToFile(Dir+FileName+".txt") ;

              MessageDlg("导出成功",mtInformation,TMsgDlgButtons()<<mbOK,0);

              delete SaveList;
        }
        catch (Exception &exception)
        {
                Application->ShowException(&exception);
        }
   }
   else
   return;
}
//---------------------------------------------------------------------------

void __fastcall TForm12::BitBtn4Click(TObject *Sender)
{
    TStringList *DataList=new TStringList();
    TStringList *pList=new TStringList();
    DataList->Text="";
    DataList->LoadFromFile("库存导入.txt");

    pList->Text="";
    Form1->CrnListSplitString(DataList->Strings[0],pList,'\t');

    int num0=0;
    int num1=0;
    int num2=0;

    int index=0;
    for(int i=0;i<pList->Count;i++)
    {
        if(pList->Strings[i].Trim()=="条码"){num0=i;index++;}
        else if(pList->Strings[i].Trim()=="仓库"){num1=i;index++;}
        else if(pList->Strings[i].Trim()=="库存"){num2=i;index++;}
        if(index==3)break;
    }

    if(index!=3)
    {
            MessageDlg("格式不对",mtInformation,TMsgDlgButtons()<<mbOK,0);
            return;
    }

    String str="";
    Double kc=0;
    int indexshow=0;

    for(int i=1;i<DataList->Count;i++)
    {

        pList->Text="";
        Form1->CrnListSplitString(DataList->Strings[i]+"\t\t\t\t\t\t\t\t\t\t\t",pList,'\t');

        if(pList->Strings[num0].Trim().Length()==0)continue;

        indexshow++;
        this->StatusBar1->Panels->Items[0]->Text="正在导入资料    条数： "+String(indexshow);


        if(pList->Strings[num2].Trim().Length()==0)kc=0;
        else
        {
            try
            {
               kc=pList->Strings[num2].Trim().ToDouble();
            }
            catch(...)
            {
               kc=0;
            }
        }
        
        //查询库存是否存在 ，如果存在直接更新，如果不存在先搜索名称以后再添加进去
        str="";
        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM KC WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",pList->Strings[num0].Trim(),pList->Strings[num1].Trim());
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;



        if(Form1->Search_ADOQuery->RecordCount==0)
        {
            Form1->KC_ADOTable->Insert();
            Form1->KC_ADOTable->FieldByName("条码")->AsString = pList->Strings[num0].Trim();
            if(pList->Strings[num1].Trim().Length()!=0)Form1->KC_ADOTable->FieldByName("仓库")->AsString = pList->Strings[num1].Trim();
            else Form1->KC_ADOTable->FieldByName("仓库")->AsString = "CK001";
            Form1->KC_ADOTable->FieldByName("库存")->AsFloat = kc;
            Form1->KC_ADOTable->Post();
         }
         else
         {

            str="";
            str=String().sprintf("UPDATE KC SET   库存 =%f  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                 ,Form1->Search_ADOQuery->FieldByName("库存")->AsFloat+kc
                                 ,pList->Strings[num0].Trim()
                                 ,pList->Strings[num1].Trim());
            Form1->ADOCommand1->CommandText = str;
            Form1->ADOCommand1->Execute();
         }

        
        Application->ProcessMessages();

    }

    Form1->KC_ADOQuery->Close();
    Form1->KC_ADOQuery->SQL->Clear();
    Form1->KC_ADOQuery->SQL->Add("SELECT * FROM 库存");
    Form1->KC_ADOQuery->Active= true;
    MessageDlg("导入完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

    this->StatusBar1->Panels->Items[0]->Text="";


    delete DataList;
    delete pList;

}
//---------------------------------------------------------------------------

