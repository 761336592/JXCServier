//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include   <inifiles.hpp>
#include <FileCtrl.hpp>

#include "Unit6.h"
#include "Unit1.h"
#include "Unit20.h"
#include "Unit2.h"
#include "Unit26.h"
#include "Unit38.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;

String exportCK[]={"条码","出库数量","出库时间","出库仓库","出库单据","员工编号","员工姓名","名称","货号","规格","型号","进价","售价","单位","备注一","备注二","备注三"};
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm6::BitBtn1Click(TObject *Sender)
{
    if(Form38->TBdata=="3")
    {
        ShowMessage("正在同步出库数据");
        return;
    }
    String str1="";
    String str2="";
    String str="";
    String str3="";
    int index=1;
    String SelectINF[]={"条码","名称","货号","规格","型号","进价","售价","单位","备注一","备注二","备注三"};
    index=1;
    str1="SELECT * FROM 出库 WHERE";
    str2="SELECT sum(出库数量) AS 总数量 FROM 出库 WHERE";
    str="";

    if(CheckCKbar->Checked==True)
    {
       str=str+" "+SelectINF[ComboBox1->ItemIndex]+" like \"%"+Check_CK_bar->Text.Trim()+"%\"";
       index=0;
    }
    if(CheckCKdate->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 出库时间 >= \""+Check_CK_date1->DateTime.FormatString("yyyy-mm-dd")+"\"";
        //if(Check_CK_date2->Text.Trim().Length()!=0)
        //{
           str=str+" AND";
           str=str+" 出库时间 <= \""+Check_CK_date2->DateTime.FormatString("yyyy-mm-dd")+"\"";
        //}
        index=0;
    }
    if(CheckCKck->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 出库仓库 like \""+Check_CK_ck->Text.Trim()+"\"";
        index=0;
    }
    if(CheckCKdj->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 出库单据 like '%"+Check_CK_dj->Text.Trim()+"%'";
        index=0;
    }
    if(CheckCKbh->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 员工编号 like \""+Check_CK_bh->Text.Trim()+"\"";
        index=0;
    }
    if(CheckCKnm->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 员工姓名 like \""+Check_CK_nm->Text.Trim()+"\"";
        index=0;
    }

    if(CheckCKbar->Checked==False&&CheckCKdate->Checked==False&&CheckCKdj->Checked==False&&CheckCKck->Checked==False&&CheckCKbh->Checked==False&&CheckCKnm->Checked==False)
    {
            str="";
            str1="SELECT * FROM 出库";
            str2="SELECT sum(出库数量) AS 总数量 FROM 出库";
            
    }
    //MessageDlg(str,mtInformation,TMsgDlgButtons()<<mbOK,0);
    Form1->CK_ADOQuery->Close();
    Form1->CK_ADOQuery->SQL->Clear();
    Form1->CK_ADOQuery->SQL->Add(str1+str);
    Form1->CK_ADOQuery->Active= true;
    Double ZJ=0;
  //  ShowMessage(Form1->CK_ADOQuery->RecordCount);
    for(int i=0;i<Form1->CK_ADOQuery->RecordCount;i++)
    {
        ZJ+=Form1->CK_ADOQuery->FieldByName("出库数量")->AsFloat*Form1->CK_ADOQuery->FieldByName("售价")->AsFloat;
        Form1->CK_ADOQuery->Next();
    }
    Form1->CK_ADOQuery->Close();
    Form1->CK_ADOQuery->SQL->Clear();
    Form1->CK_ADOQuery->SQL->Add(str1+str);
    Form1->CK_ADOQuery->Active= true;

    Form1->Search_ADOQuery->Close();
    Form1->Search_ADOQuery->SQL->Clear();
    Form1->Search_ADOQuery->SQL->Add(str2+str);
    Form1->Search_ADOQuery->Active= true;
    StatusBar1->Panels->Items[0]->Text="查询结果    总条数： "+String(Form1->CK_ADOQuery->RecordCount)+"    出库总数量： "+Form1->Search_ADOQuery->FieldByName("总数量")->AsString+"    总价:  "+String(ZJ);
     DBGrid1->SetFocus();

}
//---------------------------------------------------------------------------
void __fastcall TForm6::FormShow(TObject *Sender)
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
    DBGrid1->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm6::FormCreate(TObject *Sender)
{
      for(int i=0;i<DBGrid1->Columns->Count;i++)
      DBGrid1->Columns->Items[i]->Width=(DBGrid1->Width-50)/DBGrid1->Columns->Count;
      Check_CK_date1->Date=Now();
      Check_CK_date2->Date=Now();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::BitBtn2Click(TObject *Sender)
{
   if(Form38->TBdata=="3")
    {
        ShowMessage("正在同步出库数据");
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
      TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
      String CK=ini->ReadString("Sys","CK","0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16");
      CK=CK+",-1";
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
      Form1->CrnListSplitString(CK,pList,',');

      TStringList *SaveList=new TStringList();
      int selectnum=Form1->CK_ADOQuery->RecordCount;
      String str="";
      String FileName="出库明细";
      String datetime= Now().FormatString("yyyymmddhhnnss");
      SaveList->Text="";
      for(int i=0;i<selectnum;i++)
      {
             if(type=="0")str="";
             else str="CK,";

             for(int j=0;j<pList->Count;j++)
             {
                  if(pList->Strings[j].ToInt()!=-1)str=str+Form1->CK_ADOQuery->FieldByName(exportCK[pList->Strings[j].ToInt()])->AsString;
                  if(pList->Strings[j+1].ToInt()!=-1)str=str+sepindex;
                  if(pList->Strings[j+1].ToInt()==-1)break;
             }


             SaveList->Add(str);
             Form1->CK_ADOQuery->Next();
      }
      if(type=="0") SaveList->SaveToFile(Dir.Trim()+FileName+"-"+datetime+".TXT");
      else
      Form1->SaveExcel(SaveList,Dir.Trim()+FileName+"-"+datetime+".xls") ;
      MessageDlg("导出完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

      delete pList;
      delete SaveList;
   }
   else
   return;
}
//---------------------------------------------------------------------------

void __fastcall TForm6::BitBtn3Click(TObject *Sender)
{
     if(Form38->TBdata=="3")
    {
        ShowMessage("正在同步出库数据");
        return;
    }

     if(CheckCKdj->Checked==false||Check_CK_dj->Text.Trim().Length()==0)
     {
           ShowMessage("只能按照单据打印，请先填写单据号！");
           return;
     }
     BitBtn1Click(Sender);

     Form26->Show();

    /* //在此处输入需要打印的单据信息和备注
     CKprint->QRLabel15->Caption=CKinfm;
     if(CKnote.Trim().Length()==0)CKprint->QRLabel16->Caption="";
     else CKprint->QRLabel16->Caption=CKinfm;



     Double all=0;
       //计算总金额
     for(int i=0;i<Form1->CK_ADOQuery->RecordCount;i++)
     {
            all=all+Form1->CK_ADOQuery->FieldByName("出库数量")->AsFloat*Form1->CK_ADOQuery->FieldByName("售价")->AsFloat;
            Form1->CK_ADOQuery->Next();
     }
     CKprint->QRLabel13->Caption=String(all);
     TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
     CKprint->QRLabel5->Caption=ini->ReadString("Sys","CK3","广州润山信息科技有限公司");
     delete  ini;
     CKprint->QRLabel3->Caption=Now().FormatString("yyyy-mm-dd hh:nn:ss");
     CKprint->QuickRep1->Preview();  */
}
//---------------------------------------------------------------------------


void __fastcall TForm6::BitBtn4Click(TObject *Sender)
{
     if(Form38->TBdata=="3")
    {
        ShowMessage("正在同步出库数据");
        return;
    }

     if(Form2->wComm==INVALID_HANDLE_VALUE||Form2->wComm==NULL)
     {
            //提示串口没有打开
            ShowMessage("请先连接打印机（打开串口）");
            return;
     }
     if(CheckCKdj->Checked==false||Check_CK_dj->Text.Trim().Length()==0)
     {
           ShowMessage("请先选择要打印的单据");
           return;
     }

     String print[]={"条码","名称","货号","规格","型号","进价","售价","单位","备注一","备注二","备注三"};
     TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
     String CK1=ini->ReadString("Sys","CK1","1*2*7");

     if(strstr(CK1.c_str(),"6")&&Form1->Pshow=="unshow")
     {
          ShowMessage("您没有权限打印出进价");
          return;
     }

     TStringList *bList =new TStringList();
     Form1->CrnListSplitString(CK1,bList,'*');
     String CK2=ini->ReadString("Sys","CK2","7");
     String CK3=ini->ReadString("Sys","CK3","广州润山信息科技有限公司");
     int index=0;
     for(int j=0;j<bList->Count;j++)
     {
         if(bList->Strings[j].Trim().ToInt()==CK2.Trim().ToInt())
         index=1;
     }
     //获取到条码======================================================
     String barcode="";
     unsigned long lrc;

     float num=0;
     float count=0;
     float allcount=0;
     String printstr="";

     int selectnum=0;

     Form1->CK_ADOQuery->Close();
     Form1->CK_ADOQuery->SQL->Clear();
     Form1->CK_ADOQuery->SQL->Add("SELECT * FROM 出库 WHERE 出库单据 like \""+Check_CK_dj->Text.Trim()+"\"");
     Form1->CK_ADOQuery->Active= true;

     selectnum=Form1->CK_ADOQuery->RecordCount;
     printstr="";
     printstr=CK3+"\r\n单号："+Check_CK_dj->Text.Trim()+"\r\n"+"时间："+Now().FormatString("yyyy-mm-dd hh:nn:ss")+"\r\n--------------------------------";
     WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL);
     allcount=0;
     for(int i=0;i<selectnum;i++)
     {
            num=Form1->CK_ADOQuery->FieldByName("出库数量")->AsFloat;
            if(index==1)
            {
                count=Form1->CK_ADOQuery->FieldByName(print[CK2.Trim().ToInt()-1])->AsFloat*Form1->CK_ADOQuery->FieldByName("出库数量")->AsFloat;
                allcount=allcount+count;
            }
            printstr="";

            for(int j=0;j<bList->Count;j++)
            {
                 printstr+="\r\n"+Form1->CK_ADOQuery->FieldByName(print[bList->Strings[j].Trim().ToInt()-1])->AsString;
                 if(bList->Strings[j].Trim().ToInt()==CK2.Trim().ToInt())
                 {
                     index=1;
                     for(int m=0;m<17-Form1->CK_ADOQuery->FieldByName(print[bList->Strings[j].Trim().ToInt()-1])->AsString.Trim().Length();m++ )
                     printstr+=" ";
                     printstr+=Form1->CK_ADOQuery->FieldByName(print[bList->Strings[j].Trim().ToInt()-1])->AsString + "*"+ String(num);
                 }
            }
            WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL);
            Form1->CK_ADOQuery->Next();
       }
       printstr="";
       if(index==1)
       {
           printstr="\r\n--------------------------------总  计："+String(allcount);
           printstr+="\r\n负责人："+ Form1->CK_ADOQuery->FieldByName("员工编号")->AsString;
       }
       else  printstr="\r\n--------------------------------负责人："+ Form1->CK_ADOQuery->FieldByName("员工编号")->AsString;
       printstr+="\r\n\r\n\r\n\r\n\r\n\r\n";
       WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL);

       //提示打印完成
     //  ShowMessage("打印成功");

       delete ini;
       delete bList;

  
}
//---------------------------------------------------------------------------

void __fastcall TForm6::DBGrid1TitleClick(TColumn *Column)
{
  String s;
  if(Form1->CK_ADOQuery->Active)
  {
      if (DBGrid1->Tag==0) //顺序排列
      {
         Form1->CK_ADOQuery->Sort=Column->FieldName+" ASC";
         DBGrid1->Tag=1;
      }
      else   //反序排列,改变字体颜色
      {
         Form1->CK_ADOQuery->Sort=Column->FieldName+" DESC";
         DBGrid1->Tag=0;
      }
  }        
}
//---------------------------------------------------------------------------

void __fastcall TForm6::BitBtn5Click(TObject *Sender)
{
     if(Form38->TBdata=="3")
    {
        ShowMessage("正在同步出库数据");
        return;
    }

     BitBtn1Click(Sender);

     if(mrYes!=MessageDlg("是否确认删除表格里边所有显示的数据？",mtInformation,TMsgDlgButtons()<<mbYes<<mbNo,0))
     {
            return;
     }

     String str="";

     for(int i=0;i<Form1->CK_ADOQuery->RecordCount;i++)
     {
        //修改库存表格
        str="";
        Form1->KC_ADOQuery->Close();
        Form1->KC_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM 库存 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",Form1->CK_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->CK_ADOQuery->FieldByName("出库仓库")->AsString.Trim());
        Form1->KC_ADOQuery->SQL->Add(str);
        Form1->KC_ADOQuery->Active= true;
        
        str="";
        if(Form1->KC_ADOQuery->FieldByName("入库数量")->AsFloat==0&&
        (Form1->KC_ADOQuery->FieldByName("出库数量")->AsFloat-Form1->CK_ADOQuery->FieldByName("出库数量")->AsFloat==0)&&
        (Form1->KC_ADOQuery->FieldByName("库存")->AsFloat+Form1->CK_ADOQuery->FieldByName("出库数量")->AsFloat==0))
         str=String().sprintf("DELETE FROM KC WHERE 条码 = \"%s\" AND 仓库 = \"%s\"",Form1->CK_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->CK_ADOQuery->FieldByName("出库仓库")->AsString.Trim());
        else
        str=String().sprintf("UPDATE KC SET  出库数量 = %f , 库存 = %f WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                 ,(Form1->KC_ADOQuery->FieldByName("出库数量")->AsFloat-Form1->CK_ADOQuery->FieldByName("出库数量")->AsFloat)
                                 ,(Form1->KC_ADOQuery->FieldByName("库存")->AsFloat+Form1->CK_ADOQuery->FieldByName("出库数量")->AsFloat)
                                 ,Form1->CK_ADOQuery->FieldByName("条码")->AsString.Trim()
                                 ,Form1->CK_ADOQuery->FieldByName("出库仓库")->AsString.Trim());
         Form1->ADOCommand1->CommandText = str;
         Form1->ADOCommand1->Execute();
         //修改销售统计表格====================================================
         str="";
         Form1->XSTJ_ADOQuery->Close();
         Form1->XSTJ_ADOQuery->SQL->Clear();
         str=String().sprintf("SELECT * FROM 销售统计 WHERE 出库单据 like \"%s\" ",Form1->CK_ADOQuery->FieldByName("出库单据")->AsString.Trim());
         Form1->XSTJ_ADOQuery->SQL->Add(str);
         Form1->XSTJ_ADOQuery->Active= true;

         Double SJT=Form1->CK_ADOQuery->FieldByName("出库数量")->AsFloat*Form1->CK_ADOQuery->FieldByName("售价")->AsFloat;
         Double JJT=Form1->CK_ADOQuery->FieldByName("出库数量")->AsFloat*Form1->CK_ADOQuery->FieldByName("进价")->AsFloat;
         Double LRT=Form1->CK_ADOQuery->FieldByName("出库数量")->AsFloat*(Form1->CK_ADOQuery->FieldByName("售价")->AsFloat-Form1->CK_ADOQuery->FieldByName("进价")->AsFloat);
         if(Form1->XSTJ_ADOQuery->FieldByName("销售额")->AsFloat-SJT==0&&Form1->XSTJ_ADOQuery->FieldByName("成本")->AsFloat-JJT==0&&Form1->XSTJ_ADOQuery->FieldByName("利润")->AsFloat-LRT==0)
         {
            //删除
            Form1->ADOCommand1->CommandText = "DELETE  FROM XSTJ WHERE 出库单据 = \""+Form1->CK_ADOQuery->FieldByName("出库单据")->AsString.Trim()+"\"";
            Form1->ADOCommand1->Execute();

         }
         else
         {
            //修改   销售额 利润 成本
            str="";
            str=String().sprintf("UPDATE XSTJ SET  成本 = %f, 销售额 =%f , 利润 =%f  WHERE 出库单据 like \"%s\""
                                 ,Form1->XSTJ_ADOQuery->FieldByName("成本")->AsFloat-JJT
                                 ,Form1->XSTJ_ADOQuery->FieldByName("销售额")->AsFloat-SJT
                                 ,Form1->XSTJ_ADOQuery->FieldByName("利润")->AsFloat-LRT
                                 ,Form1->CK_ADOQuery->FieldByName("出库单据")->AsString.Trim());
            Form1->ADOCommand1->CommandText = str;
            Form1->ADOCommand1->Execute();

         }

         //修改销售统计表格====================================================

        str="";
        str=String().sprintf("DELETE FROM CK WHERE 条码 = \"%s\" AND 出库单据 = \"%s\" AND 出库仓库 = \"%s\"",Form1->CK_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->CK_ADOQuery->FieldByName("出库单据")->AsString.Trim(),Form1->CK_ADOQuery->FieldByName("出库仓库")->AsString.Trim());

        Form1->ADOCommand1->CommandText = str;
        Form1->ADOCommand1->Execute();


        Form1->CK_ADOQuery->Next();

     }

    str="SELECT * FROM 出库";
    Form1->CK_ADOQuery->Close();
    Form1->CK_ADOQuery->SQL->Clear();
    Form1->CK_ADOQuery->SQL->Add(str);
    Form1->CK_ADOQuery->Active= true;

    Form1->KC_ADOQuery->Close();
    Form1->KC_ADOQuery->SQL->Clear();
    Form1->KC_ADOQuery->SQL->Add("SELECT * FROM 库存");
    Form1->KC_ADOQuery->Active= true;

    ShowMessage("删除成功");
}
//---------------------------------------------------------------------------

void __fastcall TForm6::DBGrid1CellClick(TColumn *Column)
{
   if(DBGrid1->Columns->Grid->Fields[13]->IsNull==false)Check_CK_ck->Text=DBGrid1->Columns->Grid->Fields[13]->Value;
   if(DBGrid1->Columns->Grid->Fields[14]->IsNull==false)Check_CK_dj->Text=DBGrid1->Columns->Grid->Fields[14]->Value;
   if(DBGrid1->Columns->Grid->Fields[ComboBox1->ItemIndex]->IsNull==false)Check_CK_bar->Text=DBGrid1->Columns->Grid->Fields[ComboBox1->ItemIndex]->Value;
   if(DBGrid1->Columns->Grid->Fields[15]->IsNull==false)Check_CK_bh->Text=DBGrid1->Columns->Grid->Fields[15]->Value;
   if(DBGrid1->Columns->Grid->Fields[16]->IsNull==false)Check_CK_nm->Text=DBGrid1->Columns->Grid->Fields[16]->Value;
}
//---------------------------------------------------------------------------

void __fastcall TForm6::ComboBox1Change(TObject *Sender)
{
      if(Form1->Pshow=="unshow")
      {
         if(ComboBox1->Text=="进价")
         {
             Check_CK_bar->Visible=false;
             CheckCKbar->Checked=false;
             CheckCKbar->Enabled=false;
         }
         else
         {
             Check_CK_bar->Text="";
             Check_CK_bar->Visible=true;
             CheckCKbar->Enabled=true;
         }
      }
}
//---------------------------------------------------------------------------

void __fastcall TForm6::BitBtn6Click(TObject *Sender)
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


    if(Form1->CK_ADOQuery->RecordCount==0)
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
    Form38->TBdata="3";
    Form38->Timer1->Enabled=true;

}
//---------------------------------------------------------------------------




void __fastcall TForm6::Button1Click(TObject *Sender)
{
    if(Form38->TBdata=="3")
    {
        ShowMessage("正在同步出库数据");
        return;
    }

    String ss="Provider=Microsoft.Jet.OLEDB.4.0;Data Source="+ExtractFilePath(Application->ExeName)+"出库导入.xls;Mode=Share Deny None;Extended Properties=\"Excel 8.0;IMEX=1;\";Persist Security Info=False" ;
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
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="出库数量"){num1=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="出库仓库"){num2=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="出库单据"){num3=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="售价"){num4=i;index++;}

        if(index==5)break;
    }

    String str="";
    Double num=0;
    Double Sprace=0;
    Double Jprace=0;
    int indexshow=0;

    Double cost=0;//总成本
    Double sales=0;//总销售额
    Double profits=0;//总利润

    String CK="";
    String DH="";

    while(!Form1->qry1->Eof) //循环写入数据库
    {
        cost=0;//总成本
        sales=0;//总销售额
        profits=0;//总利润

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

        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where 条码 like \""+Form1->qry1->Fields->Fields[num0]->AsString.Trim()+"\"");
        Form1->Search_ADOQuery->Active= true;

        Sprace=Form1->Search_ADOQuery->FieldByName("售价")->AsFloat;
        Jprace=Form1->Search_ADOQuery->FieldByName("进价")->AsFloat;


        if(Form1->qry1->Fields->Fields[num4]->AsString.Trim().Length()!=0)
        {
            try
            {
               Sprace=Form1->qry1->Fields->Fields[num4]->AsString.Trim().ToDouble();
            }
            catch(...)
            {
               Sprace=Form1->Search_ADOQuery->FieldByName("售价")->AsFloat;
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


        str="";
                         Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         str=String().sprintf("SELECT * FROM 出库 WHERE 条码 like \"%s\" AND 出库单据 like \"%s\" AND 出库仓库 like \"%s\"",Form1->qry1->Fields->Fields[num0]->AsString.Trim(),DH,CK);
                         Form1->Search_ADOQuery->SQL->Add(str);
                         Form1->Search_ADOQuery->Active= true;

                         if(Form1->Search_ADOQuery->RecordCount==0)
                         {
                             sales=Sprace*num;
                             cost=Jprace*num;
                             profits=sales-cost;

                             Form1->CK_ADOTable->Insert();
                             Form1->CK_ADOTable->FieldByName("出库仓库")->AsString = CK;
                             Form1->CK_ADOTable->FieldByName("出库单据")->AsString = DH;
                             Form1->CK_ADOTable->FieldByName("条码")->AsString = Form1->qry1->Fields->Fields[num0]->AsString.Trim();
                             Form1->CK_ADOTable->FieldByName("出库数量")->AsFloat = num;
                             Form1->CK_ADOTable->FieldByName("出库时间")->AsString=Now().FormatString("yyyy-mm-dd");
                             Form1->CK_ADOTable->FieldByName("员工编号")->AsString = Form1->LoginName.Trim();
                             Form1->CK_ADOTable->FieldByName("售价")->AsFloat = Sprace;
                             Form1->CK_ADOTable->Post();
                         }
                         else
                         {
                             if(Sprace==Form1->Search_ADOQuery->FieldByName("售价")->AsFloat)
                             {
                                  sales=Sprace*num;
                                  cost=Jprace*num;
                                  profits=sales-cost;

                             }
                             else
                             {
                                  sales=Sprace*num+(Sprace-Form1->Search_ADOQuery->FieldByName("售价")->AsFloat)*Form1->Search_ADOQuery->FieldByName("出库数量")->AsFloat;
                                  cost=Jprace*num;
                                  profits=sales-cost;
                             }


                             str="";
                             str=String().sprintf("UPDATE CK SET  出库数量 = %f , 售价 = %f , 出库时间 =  \"%s\" , 员工编号 =  \"%s\"  WHERE 条码 like \"%s\" AND 出库仓库 like \"%s\" AND 出库单据 like \"%s\""
                                 ,num+Form1->Search_ADOQuery->FieldByName("出库数量")->AsFloat
                                 ,Sprace
                                 ,Now().FormatString("yyyy-mm-dd")
                                 ,Form1->LoginName.Trim()
                                 ,Form1->qry1->Fields->Fields[num0]->AsString.Trim()
                                 ,CK
                                 ,DH);
                            Form1->ADOCommand1->CommandText = str;
                            Form1->ADOCommand1->Execute();
                         }


                        str="";
	                Form1->KC_ADOQuery->Close();
	                Form1->KC_ADOQuery->SQL->Clear();
	                str=String().sprintf("SELECT * FROM 库存 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",Form1->qry1->Fields->Fields[num0]->AsString.Trim(),CK);
	                Form1->KC_ADOQuery->SQL->Add(str);
	                Form1->KC_ADOQuery->Active= true;
	
	                if(Form1->KC_ADOQuery->RecordCount==0)
                        {
                              Form1->KC_ADOTable->Insert();
                              Form1->KC_ADOTable->FieldByName("条码")->AsString = Form1->qry1->Fields->Fields[num0]->AsString.Trim();
                              Form1->KC_ADOTable->FieldByName("出库数量")->AsFloat = num;
                              Form1->KC_ADOTable->FieldByName("仓库")->AsString = CK;
                              Form1->KC_ADOTable->FieldByName("库存")->AsFloat = 0-num;
                              Form1->KC_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE KC SET  出库数量 = %f, 库存 =%f  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                   ,num+Form1->KC_ADOQuery->FieldByName("出库数量")->AsFloat
                                   ,Form1->KC_ADOQuery->FieldByName("库存")->AsFloat-num
                                   ,Form1->qry1->Fields->Fields[num0]->AsString.Trim()
                                   ,CK);
                              Form1->ADOCommand1->CommandText = str;
                              Form1->ADOCommand1->Execute();
                       }

                       //计算销售利润
                       str="";
                       Form1->XSTJ_ADOQuery->Close();
                       Form1->XSTJ_ADOQuery->SQL->Clear();
                       str=String().sprintf("SELECT * FROM 销售统计 WHERE 出库单据 like \"%s\"",DH);
                       Form1->XSTJ_ADOQuery->SQL->Add(str);
                       Form1->XSTJ_ADOQuery->Active= true;

                       if(Form1->XSTJ_ADOQuery->RecordCount==0)
                       {
                           Form1->XSTJ_ADOTable->Insert();
                           Form1->XSTJ_ADOTable->FieldByName("出库单据")->AsString = DH;
                           Form1->XSTJ_ADOTable->FieldByName("成本")->AsFloat = Jprace*num;
                           Form1->XSTJ_ADOTable->FieldByName("销售额")->AsFloat = Sprace*num;
                           Form1->XSTJ_ADOTable->FieldByName("利润")->AsFloat = (Sprace-Jprace)*num;
                           Form1->XSTJ_ADOTable->FieldByName("员工编号")->AsString = Form1->LoginName.Trim();
                           Form1->XSTJ_ADOTable->FieldByName("时间")->AsString = Now().FormatString("yyyy-mm-dd");

                           Form1->XSTJ_ADOTable->Post();
                       }
                       else
                       {
                           str="";
                           str=String().sprintf("UPDATE XSTJ SET  成本 = %f, 销售额 =%f , 利润 =%f , 时间 =  \"%s\" WHERE 出库单据 like \"%s\""
                                 ,cost+Form1->XSTJ_ADOQuery->FieldByName("成本")->AsFloat
                                 ,sales+Form1->XSTJ_ADOQuery->FieldByName("销售额")->AsFloat
                                 ,profits+Form1->XSTJ_ADOQuery->FieldByName("利润")->AsFloat
                                 ,Now().FormatString("yyyy-mm-dd")
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
    Form1->CK_ADOQuery->Close();
    Form1->CK_ADOQuery->SQL->Clear();
    Form1->CK_ADOQuery->SQL->Add("SELECT * FROM CK");
    Form1->CK_ADOQuery->Active= true;

    Form1->KC_ADOQuery->Close();
    Form1->KC_ADOQuery->SQL->Clear();
    Form1->KC_ADOQuery->SQL->Add("SELECT * FROM KC");
    Form1->KC_ADOQuery->Active= true;

    MessageDlg("导入完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

    this->StatusBar1->Panels->Items[0]->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm6::Button2Click(TObject *Sender)
{
    TStringList *DataList=new TStringList();
    TStringList *pList=new TStringList();
    DataList->Text="";
    DataList->LoadFromFile("出库导入.txt");

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
        else if(pList->Strings[i].Trim()=="出库数量"){num1=i;index++;}
        else if(pList->Strings[i].Trim()=="出库仓库"){num2=i;index++;}
        else if(pList->Strings[i].Trim()=="出库单据"){num3=i;index++;}
        else if(pList->Strings[i].Trim()=="售价"){num4=i;index++;}

        if(index==5)break;
    }

    if(index!=5)
    {
            MessageDlg("格式不对",mtInformation,TMsgDlgButtons()<<mbOK,0);
            return;
    }

    String str="";
    Double num=0;
    String CK="";
    String DH="";
    Double Sprace=0;
    Double Jprace=0;

    Double cost=0;//总成本
    Double sales=0;//总销售额
    Double profits=0;//总利润


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

        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where 条码 like \""+pList->Strings[num0].Trim()+"\"");
        Form1->Search_ADOQuery->Active= true;

        Sprace=Form1->Search_ADOQuery->FieldByName("售价")->AsFloat;
        Jprace=Form1->Search_ADOQuery->FieldByName("进价")->AsFloat;


        if(pList->Strings[num4].Trim().Length()!=0)
        {
            try
            {
               Sprace=pList->Strings[num4].Trim().ToDouble();
            }
            catch(...)
            {
               Sprace=Form1->Search_ADOQuery->FieldByName("售价")->AsFloat;
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


        str="";
                         Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         str=String().sprintf("SELECT * FROM 出库 WHERE 条码 like \"%s\" AND 出库单据 like \"%s\" AND 出库仓库 like \"%s\"",pList->Strings[num0].Trim(),DH,CK);
                         Form1->Search_ADOQuery->SQL->Add(str);
                         Form1->Search_ADOQuery->Active= true;

                         if(Form1->Search_ADOQuery->RecordCount==0)
                         {
                             sales=Sprace*num;
                             cost=Jprace*num;
                             profits=sales-cost;

                             Form1->CK_ADOTable->Insert();
                             Form1->CK_ADOTable->FieldByName("出库仓库")->AsString = CK;
                             Form1->CK_ADOTable->FieldByName("出库单据")->AsString = DH;
                             Form1->CK_ADOTable->FieldByName("条码")->AsString = pList->Strings[num0].Trim();
                             Form1->CK_ADOTable->FieldByName("出库数量")->AsFloat = num;
                             Form1->CK_ADOTable->FieldByName("出库时间")->AsString=Now().FormatString("yyyy-mm-dd");
                             Form1->CK_ADOTable->FieldByName("员工编号")->AsString = Form1->LoginName.Trim();
                             Form1->CK_ADOTable->FieldByName("售价")->AsFloat = Sprace;
                             Form1->CK_ADOTable->Post();
                         }
                         else
                         {
                             if(Sprace==Form1->Search_ADOQuery->FieldByName("售价")->AsFloat)
                             {
                                  sales=Sprace*num;
                                  cost=Jprace*num;
                                  profits=sales-cost;

                             }
                             else
                             {
                                  sales=Sprace*num+(Sprace-Form1->Search_ADOQuery->FieldByName("售价")->AsFloat)*Form1->Search_ADOQuery->FieldByName("出库数量")->AsFloat;
                                  cost=Jprace*num;
                                  profits=sales-cost;
                             }


                             str="";
                             str=String().sprintf("UPDATE CK SET  出库数量 = %f , 售价 = %f , 出库时间 =  \"%s\" , 员工编号 =  \"%s\"  WHERE 条码 like \"%s\" AND 出库仓库 like \"%s\" AND 出库单据 like \"%s\""
                                 ,num+Form1->Search_ADOQuery->FieldByName("出库数量")->AsFloat
                                 ,Sprace
                                 ,Now().FormatString("yyyy-mm-dd")
                                 ,Form1->LoginName.Trim()
                                 ,pList->Strings[num0].Trim()
                                 ,CK
                                 ,DH);
                            Form1->ADOCommand1->CommandText = str;
                            Form1->ADOCommand1->Execute();
                         }


                        str="";
	                Form1->KC_ADOQuery->Close();
	                Form1->KC_ADOQuery->SQL->Clear();
	                str=String().sprintf("SELECT * FROM 库存 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",pList->Strings[num0].Trim(),CK);
	                Form1->KC_ADOQuery->SQL->Add(str);
	                Form1->KC_ADOQuery->Active= true;
	
	                if(Form1->KC_ADOQuery->RecordCount==0)
                        {
                              Form1->KC_ADOTable->Insert();
                              Form1->KC_ADOTable->FieldByName("条码")->AsString = pList->Strings[num0].Trim();
                              Form1->KC_ADOTable->FieldByName("出库数量")->AsFloat = num;
                              Form1->KC_ADOTable->FieldByName("仓库")->AsString = CK;
                              Form1->KC_ADOTable->FieldByName("库存")->AsFloat = 0-num;
                              Form1->KC_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE KC SET  出库数量 = %f, 库存 =%f  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                   ,num+Form1->KC_ADOQuery->FieldByName("出库数量")->AsFloat
                                   ,Form1->KC_ADOQuery->FieldByName("库存")->AsFloat-num
                                   ,pList->Strings[num0].Trim()
                                   ,CK);
                              Form1->ADOCommand1->CommandText = str;
                              Form1->ADOCommand1->Execute();
                       }

                       //计算销售利润
                       str="";
                       Form1->XSTJ_ADOQuery->Close();
                       Form1->XSTJ_ADOQuery->SQL->Clear();
                       str=String().sprintf("SELECT * FROM 销售统计 WHERE 出库单据 like \"%s\"",DH);
                       Form1->XSTJ_ADOQuery->SQL->Add(str);
                       Form1->XSTJ_ADOQuery->Active= true;

                       if(Form1->XSTJ_ADOQuery->RecordCount==0)
                       {
                           Form1->XSTJ_ADOTable->Insert();
                           Form1->XSTJ_ADOTable->FieldByName("出库单据")->AsString = DH;
                           Form1->XSTJ_ADOTable->FieldByName("成本")->AsFloat = Jprace*num;
                           Form1->XSTJ_ADOTable->FieldByName("销售额")->AsFloat = Sprace*num;
                           Form1->XSTJ_ADOTable->FieldByName("利润")->AsFloat = (Sprace-Jprace)*num;
                           Form1->XSTJ_ADOTable->FieldByName("员工编号")->AsString = Form1->LoginName.Trim();
                           Form1->XSTJ_ADOTable->FieldByName("时间")->AsString = Now().FormatString("yyyy-mm-dd");

                           Form1->XSTJ_ADOTable->Post();
                       }
                       else
                       {
                           str="";
                           str=String().sprintf("UPDATE XSTJ SET  成本 = %f, 销售额 =%f , 利润 =%f , 时间 =  \"%s\" WHERE 出库单据 like \"%s\""
                                 ,cost+Form1->XSTJ_ADOQuery->FieldByName("成本")->AsFloat
                                 ,sales+Form1->XSTJ_ADOQuery->FieldByName("销售额")->AsFloat
                                 ,profits+Form1->XSTJ_ADOQuery->FieldByName("利润")->AsFloat
                                 ,Now().FormatString("yyyy-mm-dd")
                                 ,DH);
                           Form1->ADOCommand1->CommandText = str;
                           Form1->ADOCommand1->Execute();
                       }


        Application->ProcessMessages();
        Application->ProcessMessages();

    }
    Form1->CK_ADOQuery->Close();
    Form1->CK_ADOQuery->SQL->Clear();
    Form1->CK_ADOQuery->SQL->Add("SELECT * FROM CK");
    Form1->CK_ADOQuery->Active= true;

    Form1->KC_ADOQuery->Close();
    Form1->KC_ADOQuery->SQL->Clear();
    Form1->KC_ADOQuery->SQL->Add("SELECT * FROM KC");
    Form1->KC_ADOQuery->Active= true;

    MessageDlg("导入完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

    this->StatusBar1->Panels->Items[0]->Text="";


    delete DataList;
    delete pList;
}
//---------------------------------------------------------------------------

