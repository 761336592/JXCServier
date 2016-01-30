//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include   <inifiles.hpp>
#include <FileCtrl.hpp>

#include "Unit34.h"
#include "Unit1.h"
#include "Unit36.h"
#include "Unit38.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm34 *Form34;
String exportPD[]={"条码","盘点库存","盘点时间","仓库","单号","员工编号","员工姓名","名称","货号","规格","型号","进价","售价","单位","备注一","备注二","备注三"};
//---------------------------------------------------------------------------
__fastcall TForm34::TForm34(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm34::Button1Click(TObject *Sender)
{
    if(Form38->TBdata=="4")
    {
        ShowMessage("正在同步盘点数据");
        return;
    }

    String str1="";
    String str2="";
    String str="";
    int index=1;
    String SelectINF[]={"条码","名称","货号","规格","型号","进价","售价","单位","备注一","备注二","备注三"};
    index=1;
    str1="SELECT * FROM 盘点 WHERE";
    str2="SELECT sum(盘点库存) AS 总数量 FROM 盘点 WHERE";
    if(CheckPDbar->Checked==True)
    {
       str=str+" "+SelectINF[ComboBox1->ItemIndex]+" like \"%"+Check_PD_bar->Text.Trim()+"%\"";
       index=0;
    }
    if(CheckPDdate->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 盘点时间 >= \""+Check_PD_date1->DateTime.FormatString("yyyy-mm-dd")+"\"";
        str=str+" AND";
        str=str+" 盘点时间 <= \""+Check_PD_date2->DateTime.FormatString("yyyy-mm-dd")+"\"";
        index=0;
    }
    if(CheckPDck->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 仓库 like \""+Check_PD_ck->Text.Trim()+"\"";
        index=0;
    }
    if(CheckPDdj->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 单号 like \"%"+Check_PD_dj->Text.Trim()+"%\"";
        index=0;
    }
    if(CheckPDbh->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 员工编号 like \""+Check_PD_bh->Text.Trim()+"\"";
        index=0;
    }
    if(CheckPDnm->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 员工姓名 like \""+Check_PD_nm->Text.Trim()+"\"";
        index=0;
    }

    if(CheckPDbar->Checked==False&&CheckPDdate->Checked==False&&CheckPDdj->Checked==False&&CheckPDck->Checked==False&&CheckPDbh->Checked==False&&CheckPDnm->Checked==False)
    {
            str="";
            str1="SELECT * FROM 盘点";
            str2="SELECT sum(盘点库存) AS 总数量 FROM 盘点";
    }
    Form1->PD_ADOQuery->Close();
    Form1->PD_ADOQuery->SQL->Clear();
    Form1->PD_ADOQuery->SQL->Add(str1+str);
    Form1->PD_ADOQuery->Active= true;

    Form1->Search_ADOQuery->Close();
    Form1->Search_ADOQuery->SQL->Clear();
    Form1->Search_ADOQuery->SQL->Add(str2+str);
    Form1->Search_ADOQuery->Active= true;

    StatusBar1->Panels->Items[0]->Text="查询结果    总条数： "+String(Form1->PD_ADOQuery->RecordCount)+"    盘点总库存： "+Form1->Search_ADOQuery->FieldByName("总数量")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TForm34::FormCreate(TObject *Sender)
{
      for(int i=0;i<DBGrid1->Columns->Count;i++)
      DBGrid1->Columns->Items[i]->Width=(DBGrid1->Width-50)/DBGrid1->Columns->Count;

      Check_PD_date1->Date=Now();//.FormatString("yyyymmddhhnnss")
      Check_PD_date2->Date=Now();
}
//---------------------------------------------------------------------------

void __fastcall TForm34::FormShow(TObject *Sender)
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

    if(Form1->Pshow=="show")
    {
       DBGrid1->Columns->Items[5]->Visible=true;
    }

    ComboBox1->ItemIndex=0;

}
//---------------------------------------------------------------------------

void __fastcall TForm34::DBGrid1CellClick(TColumn *Column)
{
   if(DBGrid1->Columns->Grid->Fields[13]->IsNull==false)Check_PD_ck->Text=DBGrid1->Columns->Grid->Fields[13]->Value;
   if(DBGrid1->Columns->Grid->Fields[14]->IsNull==false)Check_PD_dj->Text=DBGrid1->Columns->Grid->Fields[14]->Value;
   if(DBGrid1->Columns->Grid->Fields[ComboBox1->ItemIndex]->IsNull==false)Check_PD_bar->Text=DBGrid1->Columns->Grid->Fields[ComboBox1->ItemIndex]->Value;
   if(DBGrid1->Columns->Grid->Fields[15]->IsNull==false)Check_PD_bh->Text=DBGrid1->Columns->Grid->Fields[15]->Value;
   if(DBGrid1->Columns->Grid->Fields[16]->IsNull==false)Check_PD_nm->Text=DBGrid1->Columns->Grid->Fields[16]->Value;
}
//---------------------------------------------------------------------------

void __fastcall TForm34::Button2Click(TObject *Sender)
{
   if(Form38->TBdata=="4")
    {
        ShowMessage("正在同步盘点数据");
        return;
    }

   Button1Click(Sender);
   String Dir;
   if(SelectDirectory("Directory Name","",Dir))
   {
         if(Dir.SubString(Dir.Length(),1)!="\\")
         {
                   Dir=Dir+"\\";
         }

      TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
      String PD=ini->ReadString("Sys","PD","0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15");
      PD=PD+",-1";
      String type=ini->ReadString("Sys","type","0");
      String sep=ini->ReadString("Sys","sep","0");
      String sepother=ini->ReadString("Sys","sepother","~");
      String sepindex="";

      if(sep=="0")sep=",";
      else if(sep==1)sep=";";
      else if(sep==2)sep="\t";
      else if(sep==3)sep=" ";
      else sep=sepother;


      if(type=="0")sepindex=sep;
      else sepindex=",";
      TStringList *pList=new TStringList();
      pList->Text="";
      Form1->CrnListSplitString(PD,pList,',');

      if(Form1->Pshow=="unshow")
      {
         for(int i=0;i<pList->Count;i++)
         {
             if(pList->Strings[i].Trim()=="10")
             {
                  MessageDlg("您没有权限导出进价，请修改导出格式！",mtInformation,TMsgDlgButtons()<<mbOK,0);
                  return;
             }
         }
      }


      TStringList *SaveList=new TStringList();
      int selectnum=Form1->PD_ADOQuery->RecordCount;
      String str="";
      String FileName="盘点明细";
      String datetime= Now().FormatString("yyyymmddhhnnss");
      SaveList->Text="";
      for(int i=0;i<selectnum;i++)
      {
             if(type=="0")str="";
             else str="PD,";

             for(int j=0;j<pList->Count;j++)
             {
                  if(pList->Strings[j].ToInt()!=-1)str=str+Form1->PD_ADOQuery->FieldByName(exportPD[pList->Strings[j].ToInt()])->AsString;
                  if(pList->Strings[j+1].ToInt()!=-1)str=str+sepindex;
                  if(pList->Strings[j+1].ToInt()==-1)break;
             }

             SaveList->Add(str);
             Form1->PD_ADOQuery->Next();
      }
      if(type=="0") SaveList->SaveToFile(Dir.Trim()+FileName+"-"+datetime+".TXT");
      else
      Form1->SaveExcel(SaveList,Dir.Trim()+FileName+"-"+datetime+".xls") ;
      MessageDlg("导出完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

      delete SaveList;
      delete pList;
   }
   else
   return;
}
//---------------------------------------------------------------------------

void __fastcall TForm34::DBGrid1TitleClick(TColumn *Column)
{
  String s;
  if(Form1->PD_ADOQuery->Active)
  {
      if (DBGrid1->Tag==0) //顺序排列
      {
         Form1->PD_ADOQuery->Sort=Column->FieldName+" ASC";
         DBGrid1->Tag=1;
      }
      else   //反序排列,改变字体颜色
      {
         Form1->PD_ADOQuery->Sort=Column->FieldName+" DESC";
         DBGrid1->Tag=0;
      }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm34::Button3Click(TObject *Sender)
{
       if(Form38->TBdata=="4")
       {
           ShowMessage("正在同步盘点数据");
           return;
       }

       if(CheckPDdj->Checked==false||Check_PD_dj->Text.Trim().Length()==0)
       {
           ShowMessage("只能按照单据打印，请先填写单据号！");
           return;
       }

       Button1Click(Sender);

       Form36->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm34::BitBtn1Click(TObject *Sender)
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

    Button1Click(Sender);

    if(Form1->PD_ADOQuery->RecordCount==0)
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
    Form38->TBdata="4";
    Form38->Timer1->Enabled=true;        
}
//---------------------------------------------------------------------------

void __fastcall TForm34::Button4Click(TObject *Sender)
{
    if(Form38->TBdata=="4")
    {
        ShowMessage("正在同步盘点数据");
        return;
    }

    String ss="Provider=Microsoft.Jet.OLEDB.4.0;Data Source="+ExtractFilePath(Application->ExeName)+"盘点导入.xls;Mode=Share Deny None;Extended Properties=\"Excel 8.0;IMEX=1;\";Persist Security Info=False" ;
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

    int index=0;
    for(int i=0;;i++)
    {
        if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="条码"){num0=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="盘点库存"){num1=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="仓库"){num2=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="单号"){num3=i;index++;}

        if(index==4)break;
    }

    String str="";
    Double num=0;
    int indexshow=0;
    String CK="";
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

        if(Form1->qry1->Fields->Fields[num2]->AsString.Trim().Length()==0)CK="CK001";
        else
        {
            CK= Form1->qry1->Fields->Fields[num2]->AsString.Trim();
        }

        if(Form1->qry1->Fields->Fields[num3]->AsString.Trim().Length()==0)DH="DH001";
        else
        {
            DH= Form1->qry1->Fields->Fields[num3]->AsString.Trim();
        }


            //修改盘点统计表================================================================================================
        String str="";
        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM 盘点统计 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",Form1->qry1->Fields->Fields[num0]->AsString.Trim(),CK);
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;

        if(Form1->Search_ADOQuery->RecordCount==0)
        {
            Form1->PDTJ_ADOTable->Insert();
            Form1->PDTJ_ADOTable->FieldByName("条码")->AsString = Form1->qry1->Fields->Fields[num0]->AsString.Trim();
            Form1->PDTJ_ADOTable->FieldByName("盘点库存")->AsFloat = num;
            Form1->PDTJ_ADOTable->FieldByName("仓库")->AsString = CK;
            Form1->PDTJ_ADOTable->Post();
        }
        else
        {
            str="";
            str=String().sprintf("UPDATE PDTJ SET  盘点库存 = %f WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                   ,num+Form1->Search_ADOQuery->FieldByName("盘点库存")->AsFloat
                                   ,Form1->qry1->Fields->Fields[num0]->AsString.Trim()
                                   ,CK);
            Form1->ADOCommand1->CommandText = str;
            Form1->ADOCommand1->Execute();
        }

        //修改盘点明细表==================================================================================================
        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM 盘点 WHERE 条码 like \"%s\" AND 仓库 like \"%s\" AND 单号 like \"%s\"",Form1->qry1->Fields->Fields[num0]->AsString.Trim(),CK,DH);
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;

        if(Form1->Search_ADOQuery->RecordCount==0)
        {
            Form1->PD_ADOTable->Insert();
            Form1->PD_ADOTable->FieldByName("条码")->AsString = Form1->qry1->Fields->Fields[num0]->AsString.Trim();
            Form1->PD_ADOTable->FieldByName("盘点库存")->AsFloat = num;
            Form1->PD_ADOTable->FieldByName("仓库")->AsString = CK;
            Form1->PD_ADOTable->FieldByName("单号")->AsString = DH;
            Form1->PD_ADOTable->FieldByName("盘点时间")->AsString = Now().FormatString("yyyy-mm-dd");
            Form1->PD_ADOTable->FieldByName("员工编号")->AsString = Form1->LoginName.Trim();
            Form1->PD_ADOTable->Post();
        }
        else
        {
            str="";
            str=String().sprintf("UPDATE PD SET  盘点库存 = %f , 盘点时间 =\"%s\" , 员工编号 = \"%s\" WHERE 条码 like \"%s\" AND 仓库 like \"%s\" AND 单号 like \"%s\""
                                   ,num+Form1->Search_ADOQuery->FieldByName("盘点库存")->AsFloat
                                   ,Now().FormatString("yyyy-mm-dd")
                                   ,Form1->LoginName.Trim()
                                   ,Form1->qry1->Fields->Fields[num0]->AsString.Trim()
                                   ,CK
                                   ,DH);
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
    Form1->PD_ADOQuery->Close();
    Form1->PD_ADOQuery->SQL->Clear();
    Form1->PD_ADOQuery->SQL->Add("SELECT * FROM 盘点");
    Form1->PD_ADOQuery->Active= true;

    Form1->PDTJ_ADOQuery->Close();
    Form1->PDTJ_ADOQuery->SQL->Clear();
    Form1->PDTJ_ADOQuery->SQL->Add("SELECT * FROM 盘点统计");
    Form1->PDTJ_ADOQuery->Active= true;

    MessageDlg("导入完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

    this->StatusBar1->Panels->Items[0]->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm34::Button5Click(TObject *Sender)
{
    if(Form38->TBdata=="4")
    {
        ShowMessage("正在同步盘点数据");
        return;
    }


    TStringList *DataList=new TStringList();
    TStringList *pList=new TStringList();
    DataList->Text="";
    DataList->LoadFromFile("盘点导入.txt");

    pList->Text="";
    Form1->CrnListSplitString(DataList->Strings[0],pList,'\t');

    int num0=0;
    int num1=0;
    int num2=0;
    int num3=0;

    int index=0;
    for(int i=0;i<pList->Count;i++)
    {
        if(pList->Strings[i].Trim()=="条码"){num0=i;index++;}
        else if(pList->Strings[i].Trim()=="盘点库存"){num1=i;index++;}
        else if(pList->Strings[i].Trim()=="仓库"){num2=i;index++;}
        else if(pList->Strings[i].Trim()=="单号"){num3=i;index++;}

        if(index==4)break;
    }

    if(index!=4)
    {
            MessageDlg("格式不对",mtInformation,TMsgDlgButtons()<<mbOK,0);
            return;
    }

    String str="";
    Double num=0;
    String CK="";
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

        if(pList->Strings[num2].Trim().Length()==0)CK="CK001";
        else
        {
            CK= pList->Strings[num2].Trim();
        }

        if(pList->Strings[num3].Trim().Length()==0)DH="DH001";
        else
        {
            DH= pList->Strings[num3].Trim();
        }


            //修改盘点统计表================================================================================================
        String str="";
        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM 盘点统计 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",pList->Strings[num0].Trim(),CK);
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;

        if(Form1->Search_ADOQuery->RecordCount==0)
        {
            Form1->PDTJ_ADOTable->Insert();
            Form1->PDTJ_ADOTable->FieldByName("条码")->AsString = pList->Strings[num0].Trim();
            Form1->PDTJ_ADOTable->FieldByName("盘点库存")->AsFloat = num;
            Form1->PDTJ_ADOTable->FieldByName("仓库")->AsString = CK;
            Form1->PDTJ_ADOTable->Post();
        }
        else
        {
            str="";
            str=String().sprintf("UPDATE PDTJ SET  盘点库存 = %f WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                   ,num+Form1->Search_ADOQuery->FieldByName("盘点库存")->AsFloat
                                   ,pList->Strings[num0].Trim()
                                   ,CK);
            Form1->ADOCommand1->CommandText = str;
            Form1->ADOCommand1->Execute();
        }

        //修改盘点明细表==================================================================================================
        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM 盘点 WHERE 条码 like \"%s\" AND 仓库 like \"%s\" AND 单号 like \"%s\"",pList->Strings[num0].Trim(),CK,DH);
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;

        if(Form1->Search_ADOQuery->RecordCount==0)
        {
            Form1->PD_ADOTable->Insert();
            Form1->PD_ADOTable->FieldByName("条码")->AsString = pList->Strings[num0].Trim();
            Form1->PD_ADOTable->FieldByName("盘点库存")->AsFloat = num;
            Form1->PD_ADOTable->FieldByName("仓库")->AsString = CK;
            Form1->PD_ADOTable->FieldByName("单号")->AsString = DH;
            Form1->PD_ADOTable->FieldByName("盘点时间")->AsString = Now().FormatString("yyyy-mm-dd");
            Form1->PD_ADOTable->FieldByName("员工编号")->AsString = Form1->LoginName.Trim();
            Form1->PD_ADOTable->Post();
        }
        else
        {
            str="";
            str=String().sprintf("UPDATE PD SET  盘点库存 = %f , 盘点时间 =\"%s\" , 员工编号 = \"%s\" WHERE 条码 like \"%s\" AND 仓库 like \"%s\" AND 单号 like \"%s\""
                                   ,num+Form1->Search_ADOQuery->FieldByName("盘点库存")->AsFloat
                                   ,Now().FormatString("yyyy-mm-dd")
                                   ,Form1->LoginName.Trim()
                                   ,pList->Strings[num0].Trim()
                                   ,CK
                                   ,DH);
            Form1->ADOCommand1->CommandText = str;
            Form1->ADOCommand1->Execute();
        }


        Application->ProcessMessages();

    }

    Form1->PD_ADOQuery->Close();
    Form1->PD_ADOQuery->SQL->Clear();
    Form1->PD_ADOQuery->SQL->Add("SELECT * FROM 盘点");
    Form1->PD_ADOQuery->Active= true;

    Form1->PDTJ_ADOQuery->Close();
    Form1->PDTJ_ADOQuery->SQL->Clear();
    Form1->PDTJ_ADOQuery->SQL->Add("SELECT * FROM 盘点统计");
    Form1->PDTJ_ADOQuery->Active= true;

    MessageDlg("导入完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

    this->StatusBar1->Panels->Items[0]->Text="";


    delete DataList;
    delete pList;

}
//---------------------------------------------------------------------------

