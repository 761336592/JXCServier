//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include   <inifiles.hpp>
#include <FileCtrl.hpp>

#include "Unit14.h"
#include "Unit1.h"
#include "Unit38.h"
#include "Unit2.h"
#include "Unit40.h"

String exportcode[]={"条码","名称","货号","规格","型号","进价","售价","单位","备注一","备注二","备注三"};
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm14 *Form14;
//---------------------------------------------------------------------------
__fastcall TForm14::TForm14(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm14::FormShow(TObject *Sender)
{
    
     if(Form1->LoginName!="01")
     {
          BitBtn2->Enabled=false;
          BitBtn4->Enabled=false;
          DBGrid1->Options=TDBGridOptions(DBGrid1->Options)<<dgRowSelect;

     }

    DBGrid1->Columns->Items[0]->Title->Caption=Form1->infshow1;
    DBGrid1->Columns->Items[1]->Title->Caption=Form1->infshow2;
    DBGrid1->Columns->Items[2]->Title->Caption=Form1->infshow3;
    DBGrid1->Columns->Items[3]->Title->Caption=Form1->infshow4;
    DBGrid1->Columns->Items[4]->Title->Caption=Form1->infshow5;
    DBGrid1->Columns->Items[5]->Title->Caption=Form1->infshow6;
    DBGrid1->Columns->Items[6]->Title->Caption=Form1->infshow7;
    DBGrid1->Columns->Items[7]->Title->Caption=Form1->infshow8;
    DBGrid1->Columns->Items[8]->Title->Caption=Form1->infshow9;
    DBGrid1->Columns->Items[9]->Title->Caption=Form1->infshow10;
    DBGrid1->Columns->Items[10]->Title->Caption=Form1->infshow11;

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

    if(Form1->Pshow=="show")DBGrid1->Columns->Items[5]->Visible=true;

    StatusBar1->Panels->Items[0]->Text="查询结果    条数： "+String(Form1->ADOQuery1->RecordCount);
}
//---------------------------------------------------------------------------
void __fastcall TForm14::BitBtn1Click(TObject *Sender)
{
    if(Form38->TBdata=="1")
    {
        ShowMessage("正在同步基本资料");
        return;
    }

    String SelectINF[]={"条码","名称","货号","规格","型号","进价","售价","单位","备注一","备注二","备注三"};
    Form1->ADOQuery1->Close();
    Form1->ADOQuery1->SQL->Clear();
    if(Edit1->Text.Trim().Length()!=0)
    Form1->ADOQuery1->SQL->Add("SELECT * FROM JBZL where "+SelectINF[ComboBox1->ItemIndex]+" like \"%"+Edit1->Text.Trim()+"%\"");
    else
    Form1->ADOQuery1->SQL->Add("SELECT * FROM JBZL");
    Form1->ADOQuery1->Active= true;

    StatusBar1->Panels->Items[0]->Text="查询结果    条数： "+String(Form1->ADOQuery1->RecordCount);
}
//---------------------------------------------------------------------------
void __fastcall TForm14::BitBtn2Click(TObject *Sender)
{
     if(Form38->TBdata=="1")
    {
        ShowMessage("正在同步基本资料");
        return;
    }

     if(Edit1->Text.Trim().Length()==0)
     {
         ShowMessage(ComboBox1->Text.Trim()+"不能为空！");
         return;
     }
     //BitBtn1Click(Sender);
     String SelectINF[]={"条码","名称","货号","规格","型号","进价","售价","单位","备注一","备注二","备注三"};
     Form1->ADOQuery1->Close();
     Form1->ADOQuery1->SQL->Clear();
     Form1->ADOQuery1->SQL->Add("SELECT * FROM JBZL where "+SelectINF[ComboBox1->ItemIndex]+" like \""+Edit1->Text.Trim()+"\"");
     Form1->ADOQuery1->Active= true;

     if(mrYes!=MessageDlg("是否确认删除表格里边所有显示的数据？",mtInformation,TMsgDlgButtons()<<mbYes<<mbNo,0))
     {
            return;
     }

    //String SelectINF[]={"条码","名称","货号","规格","型号","进价","售价","单位","备注一","备注二","备注三"};
    String str="";
    str=String().sprintf("DELETE FROM JBZL WHERE %s like \"%s\"",SelectINF[ComboBox1->ItemIndex],Edit1->Text.Trim());
    Form1->ADOCommand1->CommandText = str;
    Form1->ADOCommand1->Execute();

    Form1->ADOQuery1->Close();
    Form1->ADOQuery1->SQL->Clear();
    Form1->ADOQuery1->SQL->Add("SELECT * FROM JBZL");
    Form1->ADOQuery1->Active= true;

    ShowMessage("删除成功");
}
//---------------------------------------------------------------------------
int __fastcall List_strcmp(TStringList *List,int   Index1,   int   Index2)
{
      return   strcmp(List->Strings[Index1].Trim().c_str(),List->Strings[Index2].Trim().c_str());

}
//----------------------------------------------------------------------------
void __fastcall TForm14::BitBtn3Click(TObject *Sender)
{
   if(Form38->TBdata=="1")
    {
        ShowMessage("正在同步基本资料");
        return;
    }

   String Dir;
   if(SelectDirectory("Directory Name","",Dir))
   {
         if(Dir.SubString(Dir.Length(),1)!="\\")
         {
                   Dir=Dir+"\\";
         }

         TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
         String interfacerk="界面rk ,"+ini->ReadString("Sys","rksendback1","2")+"*"+ini->ReadString("Sys","rksendback2","3")+"*"+ini->ReadString("Sys","rksendback3","6")+"*"+ini->ReadString("Sys","rksendback4","7")+"*"+ini->ReadString("Sys","rksendback5","9")+",";
         String interfaceck="界面ck ,"+ini->ReadString("Sys","cksendback1","2")+"*"+ini->ReadString("Sys","cksendback2","3")+"*"+ini->ReadString("Sys","cksendback3","6")+"*"+ini->ReadString("Sys","cksendback4","7")+"*"+ini->ReadString("Sys","cksendback5","9")+",";
         String interfacepd="界面pd ,"+ini->ReadString("Sys","pdsendback1","2")+"*"+ini->ReadString("Sys","pdsendback2","3")+"*"+ini->ReadString("Sys","pdsendback3","6")+"*"+ini->ReadString("Sys","pdsendback4","7")+"*"+ini->ReadString("Sys","pdsendback5","9")+",";
         String interfaceyk="界面yk ,"+ini->ReadString("Sys","yksendback1","2")+"*"+ini->ReadString("Sys","yksendback2","3")+"*"+ini->ReadString("Sys","yksendback3","6")+"*"+ini->ReadString("Sys","yksendback4","7")+"*"+ini->ReadString("Sys","yksendback5","9")+",";
         String interfaceyd="界面yd ,"+ini->ReadString("Sys","ydsendback1","2")+"*"+ini->ReadString("Sys","ydsendback2","3")+"*"+ini->ReadString("Sys","ydsendback3","6")+"*"+ini->ReadString("Sys","ydsendback4","7")+"*"+ini->ReadString("Sys","ydsendback5","9")+",";

         String printfRK="打印RK ,"+ini->ReadString("Sys","RK1","2*6")+","+ini->ReadString("Sys","RK2","6")+","+ini->ReadString("Sys","RK3","广州润山信息科技有限公司")+",";
         String printfCK="打印CK ,"+ini->ReadString("Sys","CK1","2*7")+","+ini->ReadString("Sys","CK2","7")+","+ini->ReadString("Sys","CK3","广州润山信息科技有限公司")+",";

         delete ini;



      String szBT=Form1->infshow1+" ,"+Form1->infshow2+" ,"+Form1->infshow3+" ,"+Form1->infshow4+" ,"+Form1->infshow5+" ,"+Form1->infshow6+" ,"+Form1->infshow7+" ,"+Form1->infshow8+" ,"+Form1->infshow9+" ,"+Form1->infshow10+" ,"+Form1->infshow11+" ,";


      Form1->Search_ADOQuery->Close();
      Form1->Search_ADOQuery->SQL->Clear();
      Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL");
      Form1->Search_ADOQuery->Active= true;

      TStringList *ZLlist=new TStringList();
      int selectnum=Form1->Search_ADOQuery->RecordCount;
      String str="";
      String szString="";
      int ZL_RowLen=150;
      ZLlist->Text="";


      interfacerk=String().sprintf("%-*.*s",ZL_RowLen,ZL_RowLen,interfacerk) ;
      ZLlist->Add(interfacerk);
      interfaceck=String().sprintf("%-*.*s",ZL_RowLen,ZL_RowLen,interfaceck) ;
      ZLlist->Add(interfaceck);
      interfacepd=String().sprintf("%-*.*s",ZL_RowLen,ZL_RowLen,interfacepd) ;
      ZLlist->Add(interfacepd);
      interfaceyd=String().sprintf("%-*.*s",ZL_RowLen,ZL_RowLen,interfaceyd) ;
      ZLlist->Add(interfaceyd);
      interfaceyk=String().sprintf("%-*.*s",ZL_RowLen,ZL_RowLen,interfaceyk) ;
      ZLlist->Add(interfaceyk);
      printfRK=String().sprintf("%-*.*s",ZL_RowLen,ZL_RowLen,printfRK) ;
      ZLlist->Add(printfRK);
      printfCK=String().sprintf("%-*.*s",ZL_RowLen,ZL_RowLen,printfCK) ;
      ZLlist->Add(printfCK);


      for(int i=0;i<selectnum;i++)
      {
             str="";
             if(Form1->Pshow=="show")
             {
                 str=Form1->Search_ADOQuery->FieldByName("条码")->AsString+" ,"+
                     Form1->Search_ADOQuery->FieldByName("名称")->AsString+" ,"+
                     Form1->Search_ADOQuery->FieldByName("货号")->AsString+" ,"+
                     Form1->Search_ADOQuery->FieldByName("规格")->AsString+" ,"+
                     Form1->Search_ADOQuery->FieldByName("型号")->AsString+" ,"+
                     Form1->Search_ADOQuery->FieldByName("进价")->AsString+" ,"+
                     Form1->Search_ADOQuery->FieldByName("售价")->AsString+" ,"+
                     Form1->Search_ADOQuery->FieldByName("单位")->AsString+" ,"+
                     Form1->Search_ADOQuery->FieldByName("备注一")->AsString+" ,"+
                     Form1->Search_ADOQuery->FieldByName("备注二")->AsString+" ,"+
                     Form1->Search_ADOQuery->FieldByName("备注三")->AsString+" ,";
             }
             else
             {
                 str=Form1->Search_ADOQuery->FieldByName("条码")->AsString+" ,"+
                     Form1->Search_ADOQuery->FieldByName("名称")->AsString+" ,"+
                     Form1->Search_ADOQuery->FieldByName("货号")->AsString+" ,"+
                     Form1->Search_ADOQuery->FieldByName("规格")->AsString+" ,"+
                     Form1->Search_ADOQuery->FieldByName("型号")->AsString+" ,0 ,"+
                     Form1->Search_ADOQuery->FieldByName("售价")->AsString+" ,"+
                     Form1->Search_ADOQuery->FieldByName("单位")->AsString+" ,"+
                     Form1->Search_ADOQuery->FieldByName("备注一")->AsString+" ,"+
                     Form1->Search_ADOQuery->FieldByName("备注二")->AsString+" ,"+
                     Form1->Search_ADOQuery->FieldByName("备注三")->AsString+" ,";
             }
             str=String().sprintf("%-*.*s",ZL_RowLen,ZL_RowLen,str) ;
             ZLlist->Add(str);
             Form1->Search_ADOQuery->Next();
      }
        ZLlist->CustomSort(List_strcmp);
        szString=String().sprintf("%-*.*s",ZL_RowLen,ZL_RowLen,szBT) ;
        ZLlist->Insert(0,szString);
        szString=String().sprintf("2,%d,%d,",ZLlist->Count+1,ZL_RowLen) ;
        szString=String().sprintf("%-*.*s",ZL_RowLen,ZL_RowLen,szString) ;
        ZLlist->Insert(0,szString);
        ZLlist->SaveToFile(Dir+"INF.TXT");

        MessageDlg("生成完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

        delete ZLlist;

   }
   else
   return;
}
//---------------------------------------------------------------------------
void __fastcall TForm14::FormClose(TObject *Sender, TCloseAction &Action)
{
    if(DBGrid1->DataSource->DataSet->State==2||DBGrid1->DataSource->DataSet->State==3)
    {
       DBGrid1->DataSource->DataSet->Post();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm14::FormCreate(TObject *Sender)
{
      for(int i=0;i<DBGrid1->Columns->Count;i++)
      DBGrid1->Columns->Items[i]->Width=(DBGrid1->Width-50)/DBGrid1->Columns->Count;

}
//---------------------------------------------------------------------------

void __fastcall TForm14::BitBtn4Click(TObject *Sender)
{
    if(Form38->TBdata=="1")
    {
        ShowMessage("正在同步基本资料");
        return;
    }

    String ss="Provider=Microsoft.Jet.OLEDB.4.0;Data Source="+ExtractFilePath(Application->ExeName)+"商品资料.xls;Mode=Share Deny None;Extended Properties=\"Excel 8.0;IMEX=1;\";Persist Security Info=False" ;
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
    int num3=0;
    int num4=0;
    int num5=0;
    int num6=0;
    int num7=0;
    int num8=0;
    int num9=0;
    int num10=0;

    int index=0;
    for(int i=0;;i++)
    {
        if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()==Form1->infshow1){num0=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()==Form1->infshow2){num1=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()==Form1->infshow3){num2=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()==Form1->infshow4){num3=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()==Form1->infshow5){num4=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()==Form1->infshow6){num5=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()==Form1->infshow7){num6=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()==Form1->infshow8){num7=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()==Form1->infshow9){num8=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()==Form1->infshow10){num9=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()==Form1->infshow11){num10=i;index++;}
        if(index==11)break;
    }

    String str="";
    Double Jprace=0;
    Double Sprace=0;

    int indexshow=0;
    while(!Form1->qry1->Eof) //循环写入数据库
    {
        if(Form1->qry1->Fields->Fields[num0]->AsString.Trim().Length()==0)
        {
           Form1->qry1->Next();
           continue;
        }
        indexshow++;
        this->StatusBar1->Panels->Items[0]->Text="正在导入资料    条数： "+String(indexshow);
        if(Form1->qry1->Fields->Fields[num5]->AsString.Trim().Length()==0)Jprace=0;
        else
        {
            try
            {
               Jprace=Form1->qry1->Fields->Fields[num5]->AsString.Trim().ToDouble();
            }
            catch(...)
            {
               Jprace=0;
            }
        }
        if(Form1->qry1->Fields->Fields[num6]->AsString.Trim().Length()==0)Sprace=0;
        else
        {
            try
            {
               Sprace=Form1->qry1->Fields->Fields[num6]->AsString.Trim().ToDouble();
            }
            catch(...)
            {
               Sprace=0;
            }
        }

        str="";
        str=String().sprintf("DELETE FROM JBZL  WHERE 条码  like \"%s\"",Form1->qry1->Fields->Fields[num0]->AsString.Trim());
        Form1->ADOCommand1->CommandText = str;
        Form1->ADOCommand1->Execute();

        Form1->ADOTable1->Insert();
        Form1->ADOTable1->FieldByName("条码")->AsString = Form1->qry1->Fields->Fields[num0]->AsString.Trim();
        Form1->ADOTable1->FieldByName("名称")->AsString = Form1->qry1->Fields->Fields[num1]->AsString.Trim();
        Form1->ADOTable1->FieldByName("货号")->AsString = Form1->qry1->Fields->Fields[num2]->AsString.Trim();
        Form1->ADOTable1->FieldByName("规格")->AsString = Form1->qry1->Fields->Fields[num3]->AsString.Trim();
        Form1->ADOTable1->FieldByName("型号")->AsString = Form1->qry1->Fields->Fields[num4]->AsString.Trim();
        Form1->ADOTable1->FieldByName("进价")->AsFloat = Jprace;
        Form1->ADOTable1->FieldByName("售价")->AsFloat = Sprace;
        Form1->ADOTable1->FieldByName("单位")->AsString = Form1->qry1->Fields->Fields[num7]->AsString.Trim();
        Form1->ADOTable1->FieldByName("备注一")->AsString = Form1->qry1->Fields->Fields[num8]->AsString.Trim();
        Form1->ADOTable1->FieldByName("备注二")->AsString = Form1->qry1->Fields->Fields[num9]->AsString.Trim();
        Form1->ADOTable1->FieldByName("备注三")->AsString = Form1->qry1->Fields->Fields[num10]->AsString.Trim();
       // ADOTable1->Refresh();
        Form1->ADOTable1->Post();

        Application->ProcessMessages();
        //
        Form1->qry1->Next();
    }
   // ADOTable1->Close();

    Form1->con1->Close();
    Form1->qry1->Close();
    Form1->qry1->SQL->Clear();
    Form1->ADOQuery1->Close();
    Form1->ADOQuery1->SQL->Clear();
    Form1->ADOQuery1->SQL->Add("SELECT * FROM JBZL");
    Form1->ADOQuery1->Active= true;
    MessageDlg("导入完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

    this->StatusBar1->Panels->Items[0]->Text="";
}


//-----------------------------------------------------------------------------
void __fastcall TForm14::BitBtn5Click(TObject *Sender)
{
  if(Form38->TBdata=="1")
    {
        ShowMessage("正在同步基本资料");
        return;
    }

   String Dir;
   if(SelectDirectory("Directory Name","",Dir))
   {
         if(Dir.SubString(Dir.Length(),1)!="\\")
         {
                   Dir=Dir+"\\";
         }

      Form1->Search_ADOQuery->Close();
      Form1->Search_ADOQuery->SQL->Clear();
      Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL");
      Form1->Search_ADOQuery->Active= true;

      TStringList *SaveList=new TStringList();
      int selectnum=Form1->Search_ADOQuery->RecordCount;
      String str="";
      String FileName="基本资料";
      String datetime= Now().FormatString("yyyymmddhhnnss");
      SaveList->Text="";
      for(int i=0;i<selectnum;i++)
      {
             str="";
           //  RK_Grid->Columns->Items[0]->Field->
             str="JBZL,"+
                 Form1->Search_ADOQuery->FieldByName("条码")->AsString+","+
                 Form1->Search_ADOQuery->FieldByName("名称")->AsString+","+
                 Form1->Search_ADOQuery->FieldByName("货号")->AsString+","+
                 Form1->Search_ADOQuery->FieldByName("规格")->AsString+","+
                 Form1->Search_ADOQuery->FieldByName("型号")->AsString+",";
             if(Form1->Pshow=="show")str+=Form1->Search_ADOQuery->FieldByName("进价")->AsString+",";
             str+=Form1->Search_ADOQuery->FieldByName("售价")->AsString+","+
                 Form1->Search_ADOQuery->FieldByName("单位")->AsString+","+
                 Form1->Search_ADOQuery->FieldByName("备注一")->AsString+","+
                 Form1->Search_ADOQuery->FieldByName("备注二")->AsString+","+
                 Form1->Search_ADOQuery->FieldByName("备注三")->AsString;
             SaveList->Add(str);
             Form1->Search_ADOQuery->Next();
      }
      Form1->SaveExcel(SaveList,Dir.Trim()+FileName+"-"+datetime+".xls") ;
      MessageDlg("导出完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

      delete SaveList;
   }
   else
   return;
}
//---------------------------------------------------------------------------

void __fastcall TForm14::DBGrid1TitleClick(TColumn *Column)
{
  String s;
  if(Form1->ADOQuery1->Active)
  {
      if (DBGrid1->Tag==0) //顺序排列
      {
         Form1->ADOQuery1->Sort=Column->FieldName+" ASC";
         DBGrid1->Tag=1;
      }
      else   //反序排列,改变字体颜色
      {
         Form1->ADOQuery1->Sort=Column->FieldName+" DESC";
         DBGrid1->Tag=0;
      }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm14::DBGrid1CellClick(TColumn *Column)
{
   if(DBGrid1->Columns->Grid->Fields[ComboBox1->ItemIndex]->IsNull==false)Edit1->Text=DBGrid1->Columns->Grid->Fields[ComboBox1->ItemIndex]->Value;        
}
//---------------------------------------------------------------------------

void __fastcall TForm14::ComboBox1Change(TObject *Sender)
{
      if(Form1->Pshow=="unshow")
      {
         if(ComboBox1->Text=="进价")
         {
             Edit1->Visible=false;
         }
         else
         {
             Edit1->Text="";
             Edit1->Visible=true;
         }
      }
}
//---------------------------------------------------------------------------

void __fastcall TForm14::BitBtn6Click(TObject *Sender)
{
   if(Form38->ClientSocket1->Active==false)
    {
        try
        {
            StatusBar1->Panels->Items[0]->Text="正在连接服务器";
            Form38->ClientSocket1->Host=Form38->Edit2->Text.Trim();
            Form38->ClientSocket1->Port=Form38->Edit3->Text.Trim().ToInt();
            Form38->ClientSocket1->Active=true;
        }
        catch(...)
        {
            MessageDlg("服务器连接失败，请确认服务器是否开启，或者服务器信息是否设置成功",mtInformation,TMsgDlgButtons()<<mbOK,0);
        }
    }

    if(Form38->TBdata!="0")
    {
        MessageDlg("有数据正在同步，请稍等",mtInformation,TMsgDlgButtons()<<mbOK,0);
        return;
    }

    BitBtn1Click(Sender);

    if(Form1->ADOQuery1->RecordCount==0)
    {
        MessageDlg("没有数据需要同步",mtInformation,TMsgDlgButtons()<<mbOK,0);
        return;
    }

    if(mrYes!=MessageDlg("您将同步表格里边所有显示的数据，是否确定同步？",mtInformation,TMsgDlgButtons()<<mbYes<<mbNo,0))
    {
            return;
    }

    DBGrid1->Enabled=false;


    Form38->sendnum=0;
    Form38->runningnum=21;
    Form38->TBdata="1";
    Form38->Timer1->Enabled=true;        
}
//---------------------------------------------------------------------------


void __fastcall TForm14::BitBtn7Click(TObject *Sender)
{
    TStringList *DataList=new TStringList();
    TStringList *pList=new TStringList();
    DataList->Text="";
    DataList->LoadFromFile("商品资料.txt");

    pList->Text="";
    Form1->CrnListSplitString(DataList->Strings[0],pList,'\t');

    int num0=0;
    int num1=0;
    int num2=0;
    int num3=0;
    int num4=0;
    int num5=0;
    int num6=0;
    int num7=0;
    int num8=0;
    int num9=0;
    int num10=0;

    int index=0;
    for(int i=0;i<pList->Count;i++)
    {
        if(pList->Strings[i].Trim()==Form1->infshow1){num0=i;index++;}
        else if(pList->Strings[i].Trim()==Form1->infshow2){num1=i;index++;}
        else if(pList->Strings[i].Trim()==Form1->infshow3){num2=i;index++;}
        else if(pList->Strings[i].Trim()==Form1->infshow4){num3=i;index++;}
        else if(pList->Strings[i].Trim()==Form1->infshow5){num4=i;index++;}
        else if(pList->Strings[i].Trim()==Form1->infshow6){num5=i;index++;}
        else if(pList->Strings[i].Trim()==Form1->infshow7){num6=i;index++;}
        else if(pList->Strings[i].Trim()==Form1->infshow8){num7=i;index++;}
        else if(pList->Strings[i].Trim()==Form1->infshow9){num8=i;index++;}
        else if(pList->Strings[i].Trim()==Form1->infshow10){num9=i;index++;}
        else if(pList->Strings[i].Trim()==Form1->infshow11){num10=i;index++;}
        if(index==11)break;
    }

    if(index!=11)
    {
            MessageDlg("格式不对",mtInformation,TMsgDlgButtons()<<mbOK,0);
            return;
    }

    String str="";
    Double Jprace=0;
    Double Sprace=0;

    int indexshow=0;

    for(int i=1;i<DataList->Count;i++)
    {

        pList->Text="";
        Form1->CrnListSplitString(DataList->Strings[i]+"\t\t\t\t\t\t\t\t\t\t\t",pList,'\t');

        if(pList->Strings[num0].Trim().Length()==0)continue;

        indexshow++;
        this->StatusBar1->Panels->Items[0]->Text="正在导入资料    条数： "+String(indexshow);
        if(pList->Strings[num5].Trim().Length()==0)Jprace=0;
        else
        {
            try
            {
               Jprace=pList->Strings[num5].Trim().ToDouble();
            }
            catch(...)
            {
               Jprace=0;
            }
        }
        if(pList->Strings[num6].Trim().Length()==0)Sprace=0;
        else
        {
            try
            {
               Sprace=pList->Strings[num6].Trim().ToDouble();
            }
            catch(...)
            {
               Sprace=0;
            }
        }

        str="";
        str=String().sprintf("DELETE FROM JBZL  WHERE 条码  like \"%s\"",pList->Strings[num0].Trim());
        Form1->ADOCommand1->CommandText = str;
        Form1->ADOCommand1->Execute();

        Form1->ADOTable1->Insert();
        Form1->ADOTable1->FieldByName("条码")->AsString = pList->Strings[num0].Trim();
        Form1->ADOTable1->FieldByName("名称")->AsString = pList->Strings[num1].Trim();
        Form1->ADOTable1->FieldByName("货号")->AsString = pList->Strings[num2].Trim();
        Form1->ADOTable1->FieldByName("规格")->AsString = pList->Strings[num3].Trim();
        Form1->ADOTable1->FieldByName("型号")->AsString = pList->Strings[num4].Trim();
        Form1->ADOTable1->FieldByName("进价")->AsFloat = Jprace;
        Form1->ADOTable1->FieldByName("售价")->AsFloat = Sprace;
        Form1->ADOTable1->FieldByName("单位")->AsString = pList->Strings[num7].Trim();
        Form1->ADOTable1->FieldByName("备注一")->AsString = pList->Strings[num8].Trim();
        Form1->ADOTable1->FieldByName("备注二")->AsString = pList->Strings[num9].Trim();
        Form1->ADOTable1->FieldByName("备注三")->AsString = pList->Strings[num10].Trim();

        Form1->ADOTable1->Post();
        
        Application->ProcessMessages();

    }

    Form1->ADOQuery1->Close();
    Form1->ADOQuery1->SQL->Clear();
    Form1->ADOQuery1->SQL->Add("SELECT * FROM JBZL");
    Form1->ADOQuery1->Active= true;
    MessageDlg("导入完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

    this->StatusBar1->Panels->Items[0]->Text="";


    delete DataList;
    delete pList;
}


//---------------------------------------------------------------------------

void __fastcall TForm14::Button1Click(TObject *Sender)
{
        TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
      String RK=ini->ReadString("Sys","code","0,1,2,3,4,5,6,7,8,9,10,");
      RK=RK+",-1";

      TStringList *pList=new TStringList();
      pList->Text="";
      Form1->CrnListSplitString(RK,pList,',');


     String RKexls=ini->ReadString("Sys","codexls",",,,,,,,,,,,");
      RKexls=RKexls+",";

      TStringList *bList=new TStringList();
      bList->Text="";
      Form1->CrnListSplitString(RKexls,bList,',');
      unsigned long lrc;
    char buf[]={0x1D,0x6B,0x61,0x08,0x04} ;
     char buf1[]={0x1b,0x33,0x21} ;
    String str="";
    int i=0;
     if(Form2->wComm==INVALID_HANDLE_VALUE||Form2->wComm==NULL)
     {
            //提示串口没有打开
            ShowMessage("请先连接打印机（打开串口）");
            return;
     }
     BitBtn1Click(Sender) ;
    /* Form1->ADOQuery1->Close();
    Form1->ADOQuery1->SQL->Clear();

    Form1->ADOQuery1->SQL->Add("SELECT * FROM JBZL");
    Form1->ADOQuery1->Active= true;    */
   for(i=0;i<Form1->ADOQuery1->RecordCount;i++)
    {
         str=Form1->ADOQuery1->FieldByName("条码")->AsString.Trim();

          char bufx[]={""} ;
           char h=str.Length()/256;
         char l=str.Length()%256;


          bufx[0]=l;
         bufx[1]=h;

         //String s="\r\n";
        //   WriteFile(Form2->wComm,s.c_str(),s.Length(),&lrc,NULL);
             WriteFile(Form2->wComm,buf1,3,&lrc,NULL);
            WriteFile(Form2->wComm,buf,5,&lrc,NULL);
            WriteFile(Form2->wComm,bufx,2,&lrc,NULL);
            WriteFile(Form2->wComm,str.Trim().c_str(),str.Trim().Length(),&lrc,NULL);
            /*开始打印资料*/
            for(int j=0;j<2;j++)
             {

                  if(pList->Strings[j].ToInt()!=-1)
                  {
                     str=bList->Strings[j].Trim()+":  ";
                     WriteFile(Form2->wComm,str.Trim().c_str(),str.Trim().Length(),&lrc,NULL);
                     str=Form1->ADOQuery1->FieldByName(exportcode[pList->Strings[j].ToInt()])->AsString;
                     WriteFile(Form2->wComm,str.Trim().c_str(),str.Trim().Length(),&lrc,NULL);
                     WriteFile(Form2->wComm,"\r\n",2,&lrc,NULL);

                  }

                  if(pList->Strings[j+1].ToInt()==-1)break;
             }

         String  s="----\r\n----\r\n----\r\n";
         WriteFile(Form2->wComm,s.c_str(),s.Trim().Length(),&lrc,NULL);
        Form1->ADOQuery1->Next();
    }
}
char ConvertHexChar(char ch)
{
	if((ch>='0')&&(ch<='9'))
		return ch-0x30;
	else if((ch>='A')&&(ch<='F'))
		return ch-'A'+10;
	else if((ch>='a')&&(ch<='f'))
		return ch-'a'+10;
	else return (-1);
}

/*
	作用：使用打印机打印条形码
	参数一：需要打印的条形码数据
	参数二：进行串口传输的动态数组
	参数三：码种（如下所示）
	UPC-A：65	  UPC-E：66	      JAN13：67	   JAN8：68	     CODE39：69
	ITF：70		  CODABAR：71	  CODE93：72   CODE128：73
*/
int  String2Dec(String str, unsigned char senddata[],int Code)
{
	int hexdatalen=0;
	int len=str.Length();
	int i;
         unsigned long lrc;
     //     unsigned char senddata[]={0x20};
	senddata[hexdatalen]=(char)29;
	hexdatalen++;
	senddata[hexdatalen]=(char)107;
	hexdatalen++;
	senddata[hexdatalen]=(char)Code;
	hexdatalen++;
	senddata[hexdatalen]=(char)len;
	hexdatalen++;
	for(i=0;i<len;i++)
	{
		senddata[hexdatalen]=str.c_str()[i];
		hexdatalen++;
	}
        return  hexdatalen;
     //   WriteFile(Form2->wComm,senddata,hexdatalen,&lrc,NULL);
}

/*
	作用：对打印机传输命令（十六进制）
	参数1：需要传输的命令
	参数2：进行串口传输的动态数组
	设置宽度命令：1D 77 N（01 ≤ n ≤ 06） N越小条码越窄（开机默认为03，盘点机最小识别宽度为02）
	设置条码可读字符打印位置：1D 48 N （N=30：不打印	N=31：打印在上方	N=32：打印在下方	N=33：打印在上方和下方）
*/

void StringOrder(String str, unsigned char senddata[])
{
	int hexdata,lowhexdata;
	int hexdatalen=0;
	int len=str.Length();

	for(int i=0;i<len;)
	{
		char lstr,hstr=str.c_str()[i];
		if(hstr==' ')
		{
			i++;
			hstr=str.c_str()[i];
		}
		i++;
		if(i>=len)
			break;
		lstr=str[i];
		hexdata=ConvertHexChar(hstr);
		lowhexdata=ConvertHexChar(lstr);
		if((hexdata==16)||(lowhexdata==16))
			break;
		else 
			hexdata=hexdata*16+lowhexdata;
		i++;
		senddata[hexdatalen]=(char)hexdata;
		hexdatalen++;
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm14::Button2Click(TObject *Sender)
{

        TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
      String RK=ini->ReadString("Sys","code","0,1,2,3,4,5,6,7,8,9,10,");
      RK=RK+",-1";

      TStringList *pList=new TStringList();
      pList->Text="";
      Form1->CrnListSplitString(RK,pList,',');
      int i=0;

     String RKexls=ini->ReadString("Sys","codexls",",,,");
      RKexls=RKexls+",";

      TStringList *bList=new TStringList();
      bList->Text="";
      Form1->CrnListSplitString(RKexls,bList,',');
       unsigned long lrc;
     int k=0;
   unsigned char buf1[]={0x1D,0x77,0x02} ;
   unsigned char buf2[]={0x1D,0x48,0x32} ;
   unsigned char buf3[]={0x1D,0x68,0x43} ;
 /*  Form1->ADOQuery1->Close();
    Form1->ADOQuery1->SQL->Clear();

    Form1->ADOQuery1->SQL->Add("SELECT * FROM JBZL");
    Form1->ADOQuery1->Active= true;   */
     BitBtn1Click(Sender) ;
    String str="";
     if(Form2->wComm==INVALID_HANDLE_VALUE||Form2->wComm==NULL)
     {
            //提示串口没有打开
            ShowMessage("请先连接打印机（打开串口）");
            return;
     }
   String s="";
   for(i=0;i<Form1->ADOQuery1->RecordCount;i++)
    {

       // s="\r\n" ;
       // WriteFile(Form2->wComm,s.Trim().c_str(),s.Trim().Length(),&lrc,NULL);

       unsigned  char bufx[20]={0X20};


        WriteFile(Form2->wComm,buf1,3,&lrc,NULL);

        WriteFile(Form2->wComm,buf2,3,&lrc,NULL);
        WriteFile(Form2->wComm,buf3,3,&lrc,NULL);
        str=Form1->ADOQuery1->FieldByName("条码")->AsString.Trim();
       int len= String2Dec(str.Trim(),bufx,72);
        WriteFile(Form2->wComm,bufx,len,&lrc,NULL);
        WriteFile(Form2->wComm,"\r\n",2,&lrc,NULL);
         k=0;
        for(int j=1;j<pList->Count;j++)
        {
            if(pList->Strings[j].ToInt()!=-1)
            {
                     k++;
                     str=bList->Strings[j].Trim()+":  ";
                    WriteFile(Form2->wComm,str.Trim().c_str(),str.Trim().Length(),&lrc,NULL);
                     str=Form1->ADOQuery1->FieldByName(exportcode[pList->Strings[j].ToInt()])->AsString;
                   //  ShowMessage(str+"****"+exportcode[pList->Strings[j].ToInt()]+"****"+pList->Strings[j]);

                     WriteFile(Form2->wComm,str.Trim().c_str(),str.Trim().Length(),&lrc,NULL);
                    //
                    WriteFile(Form2->wComm,"\r\n",2,&lrc,NULL);
             }
             if(pList->Strings[j+1].ToInt()==-1)
             {
                WriteFile(Form2->wComm,"\r\n",2,&lrc,NULL);
                break;
             }
         }
       // WriteFile(Form2->wComm,"\r\n",2,&lrc,NULL);
      //  WriteFile(Form2->wComm,"\r\n",2,&lrc,NULL);
        WriteFile(Form2->wComm,"\r\n",2,&lrc,NULL);
        Form1->ADOQuery1->Next();
    }
}
//---------------------------------------------------------------------------

