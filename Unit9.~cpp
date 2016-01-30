//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <FileCtrl.hpp>

#include "Unit9.h"
#include "Unit1.h"
#include "Unit29.h"
#include "Unit38.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm9::BitBtn1Click(TObject *Sender)
{
   if(Form38->TBdata=="5")
    {
        ShowMessage("正在同步移库数据");
        return;
    }

 // MessageDlg(Form1->infshow1,mtInformation,TMsgDlgButtons()<<mbOK,0);
    String str1="";
    String str2="";
    String str="";
    int index=1;
    String SelectINF[]={"条码","名称","货号","规格","型号","进价","售价","单位","备注一","备注二","备注三"};
    index=1;
    str1="SELECT * FROM 移库 WHERE";
    str2="SELECT sum(数量) AS 总数量 FROM 移库 WHERE";
    str="";
    if(CheckBox1->Checked==True)
    {
       str=str+" "+SelectINF[ComboBox1->ItemIndex]+" like \"%"+Edit1->Text.Trim()+"%\"";
       index=0;
    }
    if(CheckBox7->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 移库单号 like \"%"+Edit6->Text.Trim()+"%\"";
        index=0;
    }
    if(CheckBox6->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 移库时间 >= \""+DateTimePicker1->DateTime.FormatString("yyyy-mm-dd")+"\"";
        //if(Check_CK_date2->Text.Trim().Length()!=0)
        //{
           str=str+" AND";
           str=str+" 移库时间 <= \""+DateTimePicker2->DateTime.FormatString("yyyy-mm-dd")+"\"";
        //}
        index=0;
    }
    if(CheckBox2->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 原仓库 like \""+Edit2->Text.Trim()+"\"";
        index=0;
    }
    if(CheckBox3->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 目的仓库 like \""+Edit3->Text.Trim()+"\"";
        index=0;
    }

    if(CheckBox4->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 员工编号 like \""+Edit4->Text.Trim()+"\"";
        index=0;
    }

    if(CheckBox5->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 员工姓名 like \""+Edit5->Text.Trim()+"\"";
        index=0;
    }

    if(CheckBox1->Checked==False&&CheckBox2->Checked==False&&CheckBox3->Checked==False&&CheckBox4->Checked==False&&CheckBox5->Checked==False&&CheckBox6->Checked==False&&CheckBox7->Checked==False)
    {
            str="";
            str1="SELECT * FROM 移库";
            str2="SELECT sum(数量) AS 总数量 FROM 移库";
    }
    //MessageDlg(str,mtInformation,TMsgDlgButtons()<<mbOK,0);
    Form1->YK_ADOQuery->Close();
    Form1->YK_ADOQuery->SQL->Clear();
    Form1->YK_ADOQuery->SQL->Add(str1+str);
    Form1->YK_ADOQuery->Active= true;

    Form1->Search_ADOQuery->Close();
    Form1->Search_ADOQuery->SQL->Clear();
    Form1->Search_ADOQuery->SQL->Add(str2+str);
    Form1->Search_ADOQuery->Active= true;



    StatusBar1->Panels->Items[0]->Text="查询结果    总条数： "+String(Form1->YK_ADOQuery->RecordCount)+"    总数量： "+Form1->Search_ADOQuery->FieldByName("总数量")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TForm9::FormShow(TObject *Sender)
{
    

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

    if(Form1->Pshow=="show")
    {
       DBGrid1->Columns->Items[5]->Visible=true;
    }

}
//---------------------------------------------------------------------------
void __fastcall TForm9::FormCreate(TObject *Sender)
{
      for(int i=0;i<DBGrid1->Columns->Count;i++)
      DBGrid1->Columns->Items[i]->Width=(DBGrid1->Width-50)/DBGrid1->Columns->Count;

      DateTimePicker1->Date=Now();
      DateTimePicker2->Date=Now();
}
//---------------------------------------------------------------------------

void __fastcall TForm9::BitBtn2Click(TObject *Sender)
{
   if(Form38->TBdata=="5")
    {
        ShowMessage("正在同步移库数据");
        return;
    }

   BitBtn1Click(Sender);
   String Dir;
   if(SelectDirectory("Directory Name","",Dir))
   {
         if(Dir.SubString(Dir.Length(),1)!="\\")
         {
                   Dir=Dir+"\\";
         }


      TStringList *SaveList=new TStringList();
      int selectnum=Form1->YK_ADOQuery->RecordCount;
      String str="";
      String FileName="移库表";
      String datetime= Now().FormatString("yyyymmddhhnnss");
      SaveList->Text="";
      for(int i=0;i<selectnum;i++)
      {
             str="";
           //  RK_Grid->Columns->Items[0]->Field->
             str="YK,"+
                 Form1->YK_ADOQuery->FieldByName("条码")->AsString+","+
                 Form1->YK_ADOQuery->FieldByName("名称")->AsString+","+
                 Form1->YK_ADOQuery->FieldByName("货号")->AsString+","+
                 Form1->YK_ADOQuery->FieldByName("规格")->AsString+","+
                 Form1->YK_ADOQuery->FieldByName("型号")->AsString+",";
             if(Form1->Pshow=="show")str+=Form1->YK_ADOQuery->FieldByName("进价")->AsString+",";
             str+=Form1->YK_ADOQuery->FieldByName("售价")->AsString+","+
                 Form1->YK_ADOQuery->FieldByName("单位")->AsString+","+
                 Form1->YK_ADOQuery->FieldByName("备注一")->AsString+","+
                 Form1->YK_ADOQuery->FieldByName("备注二")->AsString+","+
                 Form1->YK_ADOQuery->FieldByName("备注三")->AsString+","+
                 Form1->YK_ADOQuery->FieldByName("原仓库")->AsString+","+
                 Form1->YK_ADOQuery->FieldByName("目的仓库")->AsString+","+
                 Form1->YK_ADOQuery->FieldByName("数量")->AsString+","+
                 Form1->YK_ADOQuery->FieldByName("移库时间")->AsString+","+
                 Form1->YK_ADOQuery->FieldByName("员工编号")->AsString+","+
                 Form1->YK_ADOQuery->FieldByName("员工姓名")->AsString;
             SaveList->Add(str);
             Form1->YK_ADOQuery->Next();
      }
      Form1->SaveExcel(SaveList,Dir.Trim()+FileName+"-"+datetime+".xls") ;
      MessageDlg("导出完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

      delete SaveList;
   }
   else
   return;
}
//---------------------------------------------------------------------------

void __fastcall TForm9::DBGrid1TitleClick(TColumn *Column)
{
  String s;
  if(Form1->YK_ADOQuery->Active)
  {
      if (DBGrid1->Tag==0) //顺序排列
      {
         Form1->YK_ADOQuery->Sort=Column->FieldName+" ASC";
         DBGrid1->Tag=1;
      }
      else   //反序排列,改变字体颜色
      {
         Form1->YK_ADOQuery->Sort=Column->FieldName+" DESC";
         DBGrid1->Tag=0;
      }
  }        
}
//---------------------------------------------------------------------------

void __fastcall TForm9::DBGrid1CellClick(TColumn *Column)
{
   if(DBGrid1->Columns->Grid->Fields[ComboBox1->ItemIndex]->IsNull==false)Edit1->Text=DBGrid1->Columns->Grid->Fields[ComboBox1->ItemIndex]->Value;
   if(DBGrid1->Columns->Grid->Fields[11]->IsNull==false)Edit6->Text=DBGrid1->Columns->Grid->Fields[11]->Value;
   if(DBGrid1->Columns->Grid->Fields[12]->IsNull==false)Edit2->Text=DBGrid1->Columns->Grid->Fields[12]->Value;
   if(DBGrid1->Columns->Grid->Fields[13]->IsNull==false)Edit3->Text=DBGrid1->Columns->Grid->Fields[13]->Value;
   if(DBGrid1->Columns->Grid->Fields[16]->IsNull==false)Edit4->Text=DBGrid1->Columns->Grid->Fields[16]->Value;
   if(DBGrid1->Columns->Grid->Fields[17]->IsNull==false)Edit5->Text=DBGrid1->Columns->Grid->Fields[17]->Value;
}
//---------------------------------------------------------------------------

void __fastcall TForm9::ComboBox1Change(TObject *Sender)
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



void __fastcall TForm9::Button1Click(TObject *Sender)
{
       if(Form38->TBdata=="5")
       {
          ShowMessage("正在同步移库数据");
          return;
       }

       if(CheckBox7->Checked==false||Edit6->Text.Trim().Length()==0)
       {
           ShowMessage("只能按照单据打印，请先填写单据号！");
           return;
       }

       BitBtn1Click(Sender);

       Form29->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm9::BitBtn3Click(TObject *Sender)
{
    if(Form38->IPTB=="0")
    {
        Form38->ClientSocket1->Active=false;
        Form38->IPTB="1";
    }
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

    if(Form1->YK_ADOQuery->RecordCount==0)
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
    Form38->TBdata="5";
    Form38->Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Button2Click(TObject *Sender)
{
      //================================================

    if(Form38->TBdata=="5")
    {
        ShowMessage("正在同步移库数据");
        return;
    }

    String ss="Provider=Microsoft.Jet.OLEDB.4.0;Data Source="+ExtractFilePath(Application->ExeName)+"移库导入.xls;Mode=Share Deny None;Extended Properties=\"Excel 8.0;IMEX=1;\";Persist Security Info=False" ;
    Form1->con1->Close();
    Form1->con1->ConnectionString=ss;
    Form1->con1->Connected  =   true;
    Form1->qry1->Close();
    Form1->qry1->SQL->Clear();
    Form1->qry1->SQL->Add("select * from [Sheet1$]");
    Form1->qry1->Open();
    Form1->qry1->Active=true;


    //单号，仓库，条码，数量

    int num0=0;
    int num1=0;
    int num2=0;
    int num3=0;
    int num4=0;

    int index=0;
    for(int i=0;;i++)
    {
        if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="条码"){num0=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="数量"){num1=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="原仓库"){num2=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="目的仓库"){num3=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="移库单号"){num4=i;index++;}

        if(index==5)break;
    }

    String str="";
    Double num=0;
    int indexshow=0;
    String DH="";
    while(!Form1->qry1->Eof) //循环写入数据库
    {
        if(Form1->qry1->Fields->Fields[num0]->AsString.Trim().Length()==0)
        {
           Form1->qry1->Next();
           continue;
        }
        indexshow++;
        this->StatusBar1->Panels->Items[0]->Text="正在导入资料    条数： "+String(indexshow);
        if(Form1->qry1->Fields->Fields[num1]->AsString.Trim().Length()==0)num=1;
        else
        {
            try
            {
               num=Form1->qry1->Fields->Fields[num1]->AsString.Trim().ToDouble();
            }
            catch(...)
            {
               num=1;
            }
        }

        if(Form1->qry1->Fields->Fields[num4]->AsString.Trim().Length()==0)DH="DH001";
        else
        {
            DH= Form1->qry1->Fields->Fields[num4]->AsString.Trim();
        }
        

        String str="";
        /*Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM 移库 WHERE 条码 like \"%s\" AND 原仓库 like \"%s\" AND 目的仓库 like \"%s\"",Form1->qry1->Fields->Fields[num0]->AsString.Trim(),Form1->qry1->Fields->Fields[num2]->AsString.Trim(),Form1->qry1->Fields->Fields[num3]->AsString.Trim());
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;

        if(Form1->Search_ADOQuery->RecordCount==0)
        {*/
            Form1->YK_ADOTable->Insert();
            Form1->YK_ADOTable->FieldByName("条码")->AsString = Form1->qry1->Fields->Fields[num0]->AsString.Trim();
            Form1->YK_ADOTable->FieldByName("数量")->AsFloat = num;
            Form1->YK_ADOTable->FieldByName("移库时间")->AsString=Now().FormatString("yyyy-mm-dd");
            Form1->YK_ADOTable->FieldByName("移库单号")->AsString = DH;
            Form1->YK_ADOTable->FieldByName("原仓库")->AsString = Form1->qry1->Fields->Fields[num2]->AsString.Trim();
            Form1->YK_ADOTable->FieldByName("目的仓库")->AsString = Form1->qry1->Fields->Fields[num3]->AsString.Trim();
            Form1->YK_ADOTable->FieldByName("员工编号")->AsString = Form1->LoginName.Trim();
            Form1->YK_ADOTable->Post();
        /*}
        else
        {
            str="";
            str=String().sprintf("UPDATE YK SET  数量 = %f , 移库时间 =  \"%s\" , 员工编号 =  \"%s\"  WHERE 条码 like \"%s\" AND 原仓库 like \"%s\" AND 目的仓库 like \"%s\""
                                 ,num+Form1->Search_ADOQuery->FieldByName("数量")->AsFloat
                                 ,Now().FormatString("yyyy-mm-dd")
                                 ,Form1->LoginName.Trim()
                                 ,Form1->qry1->Fields->Fields[num0]->AsString.Trim()
                                 ,Form1->qry1->Fields->Fields[num2]->AsString.Trim()
                                 ,Form1->qry1->Fields->Fields[num3]->AsString.Trim());
                            Form1->ADOCommand1->CommandText = str;
                            Form1->ADOCommand1->Execute();
        } */

        //修改库存表格

        str="";
        Form1->KC_ADOQuery->Close();
        Form1->KC_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM 库存 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",Form1->qry1->Fields->Fields[num0]->AsString.Trim(),Form1->qry1->Fields->Fields[num2]->AsString.Trim());
        Form1->KC_ADOQuery->SQL->Add(str);
        Form1->KC_ADOQuery->Active= true;

        if(Form1->KC_ADOQuery->RecordCount==0)
        {
            //MessageDlg("11",mtInformation,TMsgDlgButtons()<<mbOK,0);
            Form1->KC_ADOTable->Insert();
            Form1->KC_ADOTable->FieldByName("条码")->AsString = Form1->qry1->Fields->Fields[num0]->AsString.Trim();
            Form1->KC_ADOTable->FieldByName("出库数量")->AsFloat = 0;
            Form1->KC_ADOTable->FieldByName("入库数量")->AsFloat = 0;
            Form1->KC_ADOTable->FieldByName("仓库")->AsString = Form1->qry1->Fields->Fields[num2]->AsString.Trim();
            Form1->KC_ADOTable->FieldByName("库存")->AsFloat = 0 -num;
            Form1->KC_ADOTable->Post();
         }
         else
         {
            str="";
            str=String().sprintf("UPDATE KC SET   库存 =%f  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                 ,Form1->KC_ADOQuery->FieldByName("库存")->AsFloat-num
                                 ,Form1->qry1->Fields->Fields[num0]->AsString.Trim()
                                 ,Form1->qry1->Fields->Fields[num2]->AsString.Trim());
            Form1->ADOCommand1->CommandText = str;
            Form1->ADOCommand1->Execute();
         }


        str="";
        Form1->KC_ADOQuery->Close();
        Form1->KC_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM 库存 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",Form1->qry1->Fields->Fields[num0]->AsString.Trim(),Form1->qry1->Fields->Fields[num3]->AsString.Trim());
        Form1->KC_ADOQuery->SQL->Add(str);
        Form1->KC_ADOQuery->Active= true;

        if(Form1->KC_ADOQuery->RecordCount==0)
        {
            //MessageDlg("11",mtInformation,TMsgDlgButtons()<<mbOK,0);
            Form1->KC_ADOTable->Insert();
            Form1->KC_ADOTable->FieldByName("条码")->AsString = Form1->qry1->Fields->Fields[num0]->AsString.Trim();
            Form1->KC_ADOTable->FieldByName("出库数量")->AsFloat = 0;
            Form1->KC_ADOTable->FieldByName("入库数量")->AsFloat = 0;
            Form1->KC_ADOTable->FieldByName("仓库")->AsString = Form1->qry1->Fields->Fields[num3]->AsString.Trim();
            Form1->KC_ADOTable->FieldByName("库存")->AsFloat = num;
            Form1->KC_ADOTable->Post();
         }
         else
         {
            str="";
            str=String().sprintf("UPDATE KC SET   库存 =%f  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                 ,Form1->KC_ADOQuery->FieldByName("库存")->AsFloat+num
                                 ,Form1->qry1->Fields->Fields[num0]->AsString.Trim()
                                 ,Form1->qry1->Fields->Fields[num3]->AsString.Trim());
            Form1->ADOCommand1->CommandText = str;
            Form1->ADOCommand1->Execute();
         }

        Application->ProcessMessages();
        //
        Form1->qry1->Next();
    }
   // ADOTable1->Close();

    Form1->con1->Close();
    Form1->qry1->Close();
    Form1->qry1->SQL->Clear();
    Form1->KC_ADOQuery->Close();
    Form1->KC_ADOQuery->SQL->Clear();
    Form1->KC_ADOQuery->SQL->Add("SELECT * FROM 库存");
    Form1->KC_ADOQuery->Active= true;

    Form1->YK_ADOQuery->Close();
    Form1->YK_ADOQuery->SQL->Clear();
    Form1->YK_ADOQuery->SQL->Add("SELECT * FROM 移库");
    Form1->YK_ADOQuery->Active= true;

    MessageDlg("导入完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

    this->StatusBar1->Panels->Items[0]->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm9::Button3Click(TObject *Sender)
{
    TStringList *DataList=new TStringList();
    TStringList *pList=new TStringList();
    DataList->Text="";
    DataList->LoadFromFile("移库导入.txt");

    pList->Text="";
    Form1->CrnListSplitString(DataList->Strings[0],pList,'\t');

    int num0=0;
    int num1=0;
    int num2=0;
    int num3=0;
    int num4=0;

    int index=0;
    for(int i=0;i<pList->Count;i++)
    {
        if(pList->Strings[i].Trim()=="条码"){num0=i;index++;}
        else if(pList->Strings[i].Trim()=="数量"){num1=i;index++;}
        else if(pList->Strings[i].Trim()=="原仓库"){num2=i;index++;}
        else if(pList->Strings[i].Trim()=="目的仓库"){num3=i;index++;}
        else if(pList->Strings[i].Trim()=="移库单号"){num4=i;index++;}

        if(index==5)break;
    }

    if(index!=5)
    {
            MessageDlg("格式不对",mtInformation,TMsgDlgButtons()<<mbOK,0);
            return;
    }

    String str="";
    Double num=0;
    String DH="";

    int indexshow=0;

    for(int i=1;i<DataList->Count;i++)
    {

        pList->Text="";
        Form1->CrnListSplitString(DataList->Strings[i]+"\t\t\t\t\t\t\t\t\t\t\t",pList,'\t');

        if(pList->Strings[num0].Trim().Length()==0)continue;

        indexshow++;
        this->StatusBar1->Panels->Items[0]->Text="正在导入资料    条数： "+String(indexshow);
        if(pList->Strings[num1].Trim().Length()==0)num=0;
        else
        {
            try
            {
               num=pList->Strings[num1].Trim().ToDouble();
            }
            catch(...)
            {
               num=1;
            }
        }

        if(pList->Strings[num4].Trim().Length()==0)DH="DH001";
        else
        {
            DH= pList->Strings[num4].Trim();
        }


        String str="";
        /*Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM 移库 WHERE 条码 like \"%s\" AND 原仓库 like \"%s\" AND 目的仓库 like \"%s\"",pList->Strings[num0].Trim(),pList->Strings[num2].Trim(),pList->Strings[num3].Trim());
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;

        if(Form1->Search_ADOQuery->RecordCount==0)
        {*/
            Form1->YK_ADOTable->Insert();
            Form1->YK_ADOTable->FieldByName("条码")->AsString = pList->Strings[num0].Trim();
            Form1->YK_ADOTable->FieldByName("数量")->AsFloat = num;
            Form1->YK_ADOTable->FieldByName("移库时间")->AsString=Now().FormatString("yyyy-mm-dd");
            Form1->YK_ADOTable->FieldByName("移库单号")->AsString = DH;
            Form1->YK_ADOTable->FieldByName("原仓库")->AsString = pList->Strings[num2].Trim();
            Form1->YK_ADOTable->FieldByName("目的仓库")->AsString = pList->Strings[num3].Trim();
            Form1->YK_ADOTable->FieldByName("员工编号")->AsString = Form1->LoginName.Trim();
            Form1->YK_ADOTable->Post();
        /*}
        else
        {
            str="";
            str=String().sprintf("UPDATE YK SET  数量 = %f , 移库时间 =  \"%s\" , 员工编号 =  \"%s\"  WHERE 条码 like \"%s\" AND 原仓库 like \"%s\" AND 目的仓库 like \"%s\""
                                 ,num+Form1->Search_ADOQuery->FieldByName("数量")->AsFloat
                                 ,Now().FormatString("yyyy-mm-dd")
                                 ,Form1->LoginName.Trim()
                                 ,pList->Strings[num0].Trim()
                                 ,pList->Strings[num2].Trim()
                                 ,pList->Strings[num3].Trim());
                            Form1->ADOCommand1->CommandText = str;
                            Form1->ADOCommand1->Execute();
        } */

        //修改库存表格

        str="";
        Form1->KC_ADOQuery->Close();
        Form1->KC_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM 库存 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",pList->Strings[num0].Trim(),pList->Strings[num2].Trim());
        Form1->KC_ADOQuery->SQL->Add(str);
        Form1->KC_ADOQuery->Active= true;

        if(Form1->KC_ADOQuery->RecordCount==0)
        {
            //MessageDlg("11",mtInformation,TMsgDlgButtons()<<mbOK,0);
            Form1->KC_ADOTable->Insert();
            Form1->KC_ADOTable->FieldByName("条码")->AsString = pList->Strings[num0].Trim();
            Form1->KC_ADOTable->FieldByName("出库数量")->AsFloat = 0;
            Form1->KC_ADOTable->FieldByName("入库数量")->AsFloat = 0;
            Form1->KC_ADOTable->FieldByName("仓库")->AsString = pList->Strings[num2].Trim();
            Form1->KC_ADOTable->FieldByName("库存")->AsFloat = 0 -num;
            Form1->KC_ADOTable->Post();
         }
         else
         {
            str="";
            str=String().sprintf("UPDATE KC SET   库存 =%f  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                 ,Form1->KC_ADOQuery->FieldByName("库存")->AsFloat-num
                                 ,pList->Strings[num0].Trim()
                                 ,pList->Strings[num2].Trim());
            Form1->ADOCommand1->CommandText = str;
            Form1->ADOCommand1->Execute();
         }


        str="";
        Form1->KC_ADOQuery->Close();
        Form1->KC_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM 库存 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",pList->Strings[num0].Trim(),pList->Strings[num3].Trim());
        Form1->KC_ADOQuery->SQL->Add(str);
        Form1->KC_ADOQuery->Active= true;

        if(Form1->KC_ADOQuery->RecordCount==0)
        {
            //MessageDlg("11",mtInformation,TMsgDlgButtons()<<mbOK,0);
            Form1->KC_ADOTable->Insert();
            Form1->KC_ADOTable->FieldByName("条码")->AsString = pList->Strings[num0].Trim();
            Form1->KC_ADOTable->FieldByName("出库数量")->AsFloat = 0;
            Form1->KC_ADOTable->FieldByName("入库数量")->AsFloat = 0;
            Form1->KC_ADOTable->FieldByName("仓库")->AsString = pList->Strings[num3].Trim();
            Form1->KC_ADOTable->FieldByName("库存")->AsFloat = num;
            Form1->KC_ADOTable->Post();
         }
         else
         {
            str="";
            str=String().sprintf("UPDATE KC SET   库存 =%f  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                 ,Form1->KC_ADOQuery->FieldByName("库存")->AsFloat+num
                                 ,pList->Strings[num0].Trim()
                                 ,pList->Strings[num3].Trim());
            Form1->ADOCommand1->CommandText = str;
            Form1->ADOCommand1->Execute();
         }



        Application->ProcessMessages();

    }

    Form1->KC_ADOQuery->Close();
    Form1->KC_ADOQuery->SQL->Clear();
    Form1->KC_ADOQuery->SQL->Add("SELECT * FROM 库存");
    Form1->KC_ADOQuery->Active= true;

    Form1->YK_ADOQuery->Close();
    Form1->YK_ADOQuery->SQL->Clear();
    Form1->YK_ADOQuery->SQL->Add("SELECT * FROM 移库");
    Form1->YK_ADOQuery->Active= true;

    MessageDlg("导入完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

    this->StatusBar1->Panels->Items[0]->Text="";


    delete DataList;
    delete pList;

}
//---------------------------------------------------------------------------

