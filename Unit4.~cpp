//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"

#include   <inifiles.hpp>
#include <FileCtrl.hpp>
#include "Unit19.h"
#include "Unit2.h"
#include "Unit27.h"
#include "Unit38.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;


String exportRK[]={"条码","入库数量","入库时间","入库仓库","入库单据","员工编号","员工姓名","名称","货号","规格","型号","进价","售价","单位","备注一","备注二","备注三"};
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm4::BitBtn1Click(TObject *Sender)
{
    if(Form38->TBdata=="2")
    {
        ShowMessage("正在同步入库数据");
        return;
    }

    String str1="";
    String str2="";
    String str="";
    int index=1;
    String SelectINF[]={"条码","名称","货号","规格","型号","进价","售价","单位","备注一","备注二","备注三"};
    index=1;
    str1="SELECT * FROM 入库 WHERE";
    str2="SELECT sum(入库数量) AS 总数量 FROM 入库 WHERE";
    str="";
    if(CheckRKbar->Checked==True)
    {
       str=str+" "+SelectINF[ComboBox1->ItemIndex]+" like \"%"+Check_RK_bar->Text.Trim()+"%\"";
       index=0;
    }
    if(CheckRKdate->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 入库时间 >= \""+Check_RK_date1->DateTime.FormatString("yyyy-mm-dd")+"\"";
        str=str+" AND";
        str=str+" 入库时间 <= \""+Check_RK_date2->DateTime.FormatString("yyyy-mm-dd")+"\"";
        index=0;
    }
    if(CheckRKck->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 入库仓库 like \""+Check_RK_ck->Text.Trim()+"\"";
        index=0;
    }
    if(CheckRKdj->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 入库单据 like \"%"+Check_RK_dj->Text.Trim()+"%\"";
        index=0;
    }
    if(CheckRKbh->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 员工编号 like \""+Check_RK_bh->Text.Trim()+"\"";
        index=0;
    }
    if(CheckRKnm->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" 员工姓名 like \""+Check_RK_nm->Text.Trim()+"\"";
        index=0;
    }

    if(CheckRKbar->Checked==False&&CheckRKdate->Checked==False&&CheckRKdj->Checked==False&&CheckRKck->Checked==False&&CheckRKbh->Checked==False&&CheckRKnm->Checked==False)
    {
            str="";
            str1="SELECT * FROM 入库";
            str2="SELECT sum(入库数量) AS 总数量 FROM 入库";
    }
    Form1->RK_ADOQuery->Close();
    Form1->RK_ADOQuery->SQL->Clear();
    Form1->RK_ADOQuery->SQL->Add(str1+str);
    Form1->RK_ADOQuery->Active= true;

    Form1->Search_ADOQuery->Close();
    Form1->Search_ADOQuery->SQL->Clear();
    Form1->Search_ADOQuery->SQL->Add(str2+str);
    Form1->Search_ADOQuery->Active= true;

    StatusBar1->Panels->Items[0]->Text="查询结果    总条数： "+String(Form1->RK_ADOQuery->RecordCount)+"        入库总数量： "+Form1->Search_ADOQuery->FieldByName("总数量")->AsString;
    DBGrid1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::FormShow(TObject *Sender)
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
void __fastcall TForm4::FormCreate(TObject *Sender)
{
      for(int i=0;i<DBGrid1->Columns->Count;i++)
      DBGrid1->Columns->Items[i]->Width=(DBGrid1->Width-50)/DBGrid1->Columns->Count;

      Check_RK_date1->Date=Now();//.FormatString("yyyymmddhhnnss")
      Check_RK_date2->Date=Now();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::BitBtn2Click(TObject *Sender)
{
   if(Form38->TBdata=="2")
    {
        ShowMessage("正在同步入库数据");
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
      String RK=ini->ReadString("Sys","RK","0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16");
      RK=RK+",-1";
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
      Form1->CrnListSplitString(RK,pList,',');

      if(Form1->Pshow=="unshow")
      {
         for(int i=0;i<pList->Count;i++)
         {
             if(pList->Strings[i].Trim()=="11")
             {
                  MessageDlg("您没有权限导出进价，请修改导出格式！",mtInformation,TMsgDlgButtons()<<mbOK,0);
                  return;
             }
         }
      }

      TStringList *SaveList=new TStringList();
      int selectnum=Form1->RK_ADOQuery->RecordCount;
      String str="";
      String FileName="入库明细";
      String datetime= Now().FormatString("yyyymmddhhnnss");
      SaveList->Text="";
      for(int i=0;i<selectnum;i++)
      {
             if(type=="0")str="";
             else str="RK,";

             for(int j=0;j<pList->Count;j++)
             {
                 // MessageDlg(String(j),mtInformation,TMsgDlgButtons()<<mbOK,0);
                 // MessageDlg(pList->Strings[j],mtInformation,TMsgDlgButtons()<<mbOK,0);
                  if(pList->Strings[j].ToInt()!=-1)str=str+Form1->RK_ADOQuery->FieldByName(exportRK[pList->Strings[j].ToInt()])->AsString;
                  if(pList->Strings[j+1].ToInt()!=-1)str=str+sepindex;
                  if(pList->Strings[j+1].ToInt()==-1)break;
             }


             SaveList->Add(str);
             Form1->RK_ADOQuery->Next();
      }
      if(type=="0") SaveList->SaveToFile(Dir.Trim()+FileName+"-"+datetime+".TXT");
      else
      Form1->SaveExcel(SaveList,Dir.Trim()+FileName+"-"+datetime+".xls") ;
      MessageDlg("导出完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

    //  delete ini;
    //  delete pList;
     // delete SaveList;

   }
   else
   return;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::BitBtn3Click(TObject *Sender)
{
       if(Form38->TBdata=="2")
      {
        ShowMessage("正在同步入库数据");
        return;
      }

       if(CheckRKdj->Checked==false||Check_RK_dj->Text.Trim().Length()==0)
       {
           ShowMessage("只能按照单据打印，请先填写单据号！");
           return;
       }

       if(Form1->Pshow=="unshow")
       {
          ShowMessage("您没有权限打印出进价");
          return;
       }

       BitBtn1Click(Sender);

       Form27->Show();
      /* Double all=0;
       //计算总金额
       for(int i=0;i<Form1->RK_ADOQuery->RecordCount;i++)
       {
            all=all+Form1->RK_ADOQuery->FieldByName("入库数量")->AsFloat*Form1->RK_ADOQuery->FieldByName("进价")->AsFloat;
            Form1->RK_ADOQuery->Next();
       }
       RKprint->QRLabel13->Caption=String(all);

       TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
       RKprint->QRLabel5->Caption=ini->ReadString("Sys","RK3","广州润山信息科技有限公司");
       delete  ini;
       RKprint->QRLabel3->Caption=Now().FormatString("yyyy-mm-dd hh:nn:ss");
       RKprint->QuickRep1->Preview();   */
}
//---------------------------------------------------------------------------

void __fastcall TForm4::BitBtn4Click(TObject *Sender)
{
     if(Form38->TBdata=="2")
    {
        ShowMessage("正在同步入库数据");
        return;
    }

     BitBtn1Click(Sender);

     if(mrYes!=MessageDlg("是否确认删除所选择的数据？",mtInformation,TMsgDlgButtons()<<mbYes<<mbNo,0))
     {
            return;
     }

     String str="";



     for(int i=0;i<Form1->RK_ADOQuery->RecordCount;i++)
     {
        //修改库存表格
        str="";
        Form1->KC_ADOQuery->Close();
        Form1->KC_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM 库存 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",Form1->RK_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->RK_ADOQuery->FieldByName("入库仓库")->AsString.Trim());
        Form1->KC_ADOQuery->SQL->Add(str);
        Form1->KC_ADOQuery->Active= true;

        str="";
        if(Form1->KC_ADOQuery->FieldByName("出库数量")->AsFloat==0&&
        (Form1->KC_ADOQuery->FieldByName("入库数量")->AsFloat-Form1->RK_ADOQuery->FieldByName("入库数量")->AsFloat==0)&&
        (Form1->KC_ADOQuery->FieldByName("库存")->AsFloat-Form1->RK_ADOQuery->FieldByName("入库数量")->AsFloat==0))
         str=String().sprintf("DELETE FROM KC WHERE 条码 = \"%s\" AND 仓库 = \"%s\"",Form1->RK_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->RK_ADOQuery->FieldByName("入库仓库")->AsString.Trim());
        else
             str=String().sprintf("UPDATE KC SET  入库数量 = %f , 库存 = %f WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                 ,(Form1->KC_ADOQuery->FieldByName("入库数量")->AsFloat-Form1->RK_ADOQuery->FieldByName("入库数量")->AsFloat)
                                 ,(Form1->KC_ADOQuery->FieldByName("库存")->AsFloat-Form1->RK_ADOQuery->FieldByName("入库数量")->AsFloat)
                                 ,Form1->RK_ADOQuery->FieldByName("条码")->AsString.Trim()
                                 ,Form1->RK_ADOQuery->FieldByName("入库仓库")->AsString.Trim());




         Form1->ADOCommand1->CommandText = str;
         Form1->ADOCommand1->Execute();

        str="";
        str=String().sprintf("DELETE FROM RK WHERE 条码 = \"%s\" AND 入库单据 = \"%s\" AND 入库仓库 = \"%s\"",Form1->RK_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->RK_ADOQuery->FieldByName("入库单据")->AsString.Trim(),Form1->RK_ADOQuery->FieldByName("入库仓库")->AsString.Trim());

        Form1->ADOCommand1->CommandText = str;
        Form1->ADOCommand1->Execute();

         Form1->RK_ADOQuery->Next();

     }

    str="SELECT * FROM 入库";
    Form1->RK_ADOQuery->Close();
    Form1->RK_ADOQuery->SQL->Clear();
    Form1->RK_ADOQuery->SQL->Add(str);
    Form1->RK_ADOQuery->Active= true;

    Form1->KC_ADOQuery->Close();
    Form1->KC_ADOQuery->SQL->Clear();
    Form1->KC_ADOQuery->SQL->Add("SELECT * FROM 库存");
    Form1->KC_ADOQuery->Active= true;

    ShowMessage("删除成功");
}
//---------------------------------------------------------------------------

void __fastcall TForm4::DBGrid1TitleClick(TColumn *Column)
{
  String s;
  if(Form1->RK_ADOQuery->Active)
  {
      if (DBGrid1->Tag==0) //顺序排列
      {
         Form1->RK_ADOQuery->Sort=Column->FieldName+" ASC";
         DBGrid1->Tag=1;
      }
      else   //反序排列,改变字体颜色
      {
         Form1->RK_ADOQuery->Sort=Column->FieldName+" DESC";
         DBGrid1->Tag=0;
      }
  }        
}
//---------------------------------------------------------------------------

void __fastcall TForm4::DBGrid1CellClick(TColumn *Column)
{
   if(DBGrid1->Columns->Grid->Fields[13]->IsNull==false)Check_RK_ck->Text=DBGrid1->Columns->Grid->Fields[13]->Value;
   if(DBGrid1->Columns->Grid->Fields[14]->IsNull==false)Check_RK_dj->Text=DBGrid1->Columns->Grid->Fields[14]->Value;
   if(DBGrid1->Columns->Grid->Fields[ComboBox1->ItemIndex]->IsNull==false)Check_RK_bar->Text=DBGrid1->Columns->Grid->Fields[ComboBox1->ItemIndex]->Value;
   if(DBGrid1->Columns->Grid->Fields[15]->IsNull==false)Check_RK_bh->Text=DBGrid1->Columns->Grid->Fields[15]->Value;
   if(DBGrid1->Columns->Grid->Fields[16]->IsNull==false)Check_RK_nm->Text=DBGrid1->Columns->Grid->Fields[16]->Value;


}
//---------------------------------------------------------------------------

void __fastcall TForm4::BitBtn5Click(TObject *Sender)
{
     if(Form38->TBdata=="2")
    {
        ShowMessage("正在同步入库数据");
        return;
    }

     if(Form2->wComm==INVALID_HANDLE_VALUE||Form2->wComm==NULL)
     {
            //提示串口没有打开
            ShowMessage("请先连接打印机（打开串口）");
            return;
     }
     if(CheckRKdj->Checked==false||Check_RK_dj->Text.Trim().Length()==0)
     {
           ShowMessage("请先选择要打印的单据");
           return;
     }

     String print[]={"条码","名称","货号","规格","型号","进价","售价","单位","备注一","备注二","备注三"};
     TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
     String RK1=ini->ReadString("Sys","RK1","1*2*6");

     if(strstr(RK1.c_str(),"6")&&Form1->Pshow=="unshow")
     {
          ShowMessage("您没有权限打印出进价");
          return;
     }

     TStringList *bList =new TStringList();
     Form1->CrnListSplitString(RK1,bList,'*');
     String RK2=ini->ReadString("Sys","RK2","7");
     String RK3=ini->ReadString("Sys","RK3","广州润山信息科技有限公司");
     int index=0;
     for(int j=0;j<bList->Count;j++)
     {
         if(bList->Strings[j].Trim().ToInt()==RK2.Trim().ToInt())
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

     Form1->RK_ADOQuery->Close();
     Form1->RK_ADOQuery->SQL->Clear();
     Form1->RK_ADOQuery->SQL->Add("SELECT * FROM 入库 WHERE 入库单据 like \""+Check_RK_dj->Text.Trim()+"\"");
     Form1->RK_ADOQuery->Active= true;

     selectnum=Form1->RK_ADOQuery->RecordCount;
     printstr="";
     printstr=RK3+"\r\n单号："+Check_RK_dj->Text.Trim()+"\r\n"+"时间："+Now().FormatString("yyyy-mm-dd hh:nn:ss")+"\r\n--------------------------------";
     WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL);
     allcount=0;
     for(int i=0;i<selectnum;i++)
     {
            num=Form1->RK_ADOQuery->FieldByName("入库数量")->AsFloat;
            if(index==1)
            {
                count=Form1->RK_ADOQuery->FieldByName(print[RK2.Trim().ToInt()-1])->AsFloat*Form1->RK_ADOQuery->FieldByName("入库数量")->AsFloat;
                allcount=allcount+count;
            }
            printstr="";

            for(int j=0;j<bList->Count;j++)
            {
                 printstr+="\r\n"+Form1->RK_ADOQuery->FieldByName(print[bList->Strings[j].Trim().ToInt()-1])->AsString;
                 if(bList->Strings[j].Trim().ToInt()==RK2.Trim().ToInt())
                 {
                     index=1;
                     for(int m=0;m<17-Form1->RK_ADOQuery->FieldByName(print[bList->Strings[j].Trim().ToInt()-1])->AsString.Trim().Length();m++ )
                     printstr+=" ";
                     printstr+=Form1->RK_ADOQuery->FieldByName(print[bList->Strings[j].Trim().ToInt()-1])->AsString + "*"+ String(num);
                 }
            }
            WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL);
            Form1->RK_ADOQuery->Next();
       }
       printstr="";
       if(index==1)
       {
           printstr="\r\n--------------------------------总  计："+String(allcount);
           printstr+="\r\n负责人："+ Form1->RK_ADOQuery->FieldByName("员工编号")->AsString;
       }
       else  printstr="\r\n--------------------------------负责人："+ Form1->RK_ADOQuery->FieldByName("员工编号")->AsString;
       printstr+="\r\n\r\n\r\n\r\n\r\n\r\n";
       WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL);

       //提示打印完成
       //ShowMessage("打印成功");

       delete ini;
       delete bList;


}
//---------------------------------------------------------------------------

void __fastcall TForm4::ComboBox1Change(TObject *Sender)
{
      if(Form1->Pshow=="unshow")
      {
         if(ComboBox1->Text=="进价")
         {
             Check_RK_bar->Visible=false;
             CheckRKbar->Checked=false;
             CheckRKbar->Enabled=false;
         }
         else
         {
             Check_RK_bar->Text="";
             Check_RK_bar->Visible=true;
             CheckRKbar->Enabled=true;
         }
      }
}
//---------------------------------------------------------------------------


void __fastcall TForm4::BitBtn6Click(TObject *Sender)
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


            //登录一下看是否正确，如果不正确提示并且不让上传

            
        }
        catch(...)
        {
            MessageDlg("服务器连接失败，请确认服务器是否开启，或者服务器信息是否设置成功",mtInformation,TMsgDlgButtons()<<mbOK,0);
        }
    }



    if(Form38->TBdata!="0"&&Form38->ClientSocket1->Active==true)
    {
        MessageDlg("有数据正在同步，请稍等",mtInformation,TMsgDlgButtons()<<mbOK,0);
        return;
    }

    BitBtn1Click(Sender);

    if(Form1->RK_ADOQuery->RecordCount==0)
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
    Form38->TBdata="2";
    Form38->Timer1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender)
{
      //================================================

    if(Form38->TBdata=="2")
    {
        ShowMessage("正在同步入库数据");
        return;
    }

    String ss="Provider=Microsoft.Jet.OLEDB.4.0;Data Source="+ExtractFilePath(Application->ExeName)+"入库导入.xls;Mode=Share Deny None;Extended Properties=\"Excel 8.0;IMEX=1;\";Persist Security Info=False" ;
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
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="入库数量"){num1=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="入库仓库"){num2=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="入库单据"){num3=i;index++;}

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
        

        String str="";
        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM 入库 WHERE 条码 like \"%s\" AND 入库单据 like \"%s\" AND 入库仓库 like \"%s\"",Form1->qry1->Fields->Fields[num0]->AsString.Trim(),DH,CK);
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;

        if(Form1->Search_ADOQuery->RecordCount==0)
        {
            Form1->RK_ADOTable->Insert();
            Form1->RK_ADOTable->FieldByName("条码")->AsString = Form1->qry1->Fields->Fields[num0]->AsString.Trim();
            Form1->RK_ADOTable->FieldByName("入库数量")->AsFloat = num;
            Form1->RK_ADOTable->FieldByName("入库时间")->AsString=Now().FormatString("yyyy-mm-dd");
            Form1->RK_ADOTable->FieldByName("入库仓库")->AsString = CK;
            Form1->RK_ADOTable->FieldByName("入库单据")->AsString = DH;
            Form1->RK_ADOTable->FieldByName("员工编号")->AsString = Form1->LoginName.Trim();
            Form1->RK_ADOTable->Post();
        }
        else
        {
            str="";
            str=String().sprintf("UPDATE RK SET  入库数量 = %f , 入库时间 =  \"%s\" , 员工编号 =  \"%s\" WHERE 条码 like \"%s\" AND 入库仓库 like \"%s\" AND 入库单据 like \"%s\""
                                 ,num+Form1->Search_ADOQuery->FieldByName("入库数量")->AsFloat
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
            Form1->KC_ADOTable->FieldByName("入库数量")->AsFloat = num;
            Form1->KC_ADOTable->FieldByName("仓库")->AsString = CK;
            Form1->KC_ADOTable->FieldByName("库存")->AsFloat = num;
            Form1->KC_ADOTable->Post();
         }
         else
         {
            str="";
            str=String().sprintf("UPDATE KC SET  入库数量 = %f, 库存 =%f  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                 ,num+Form1->KC_ADOQuery->FieldByName("入库数量")->AsFloat
                                 ,num+Form1->KC_ADOQuery->FieldByName("库存")->AsFloat
                                 ,Form1->qry1->Fields->Fields[num0]->AsString.Trim()
                                 ,CK);
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
    Form1->RK_ADOQuery->Close();
    Form1->RK_ADOQuery->SQL->Clear();
    Form1->RK_ADOQuery->SQL->Add("SELECT * FROM RK");
    Form1->RK_ADOQuery->Active= true;

    Form1->KC_ADOQuery->Close();
    Form1->KC_ADOQuery->SQL->Clear();
    Form1->KC_ADOQuery->SQL->Add("SELECT * FROM KC");
    Form1->KC_ADOQuery->Active= true;

    MessageDlg("导入完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

    this->StatusBar1->Panels->Items[0]->Text="";
        
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button2Click(TObject *Sender)
{
    TStringList *DataList=new TStringList();
    TStringList *pList=new TStringList();
    DataList->Text="";
    DataList->LoadFromFile("入库导入.txt");

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
        else if(pList->Strings[i].Trim()=="入库数量"){num1=i;index++;}
        else if(pList->Strings[i].Trim()=="入库仓库"){num2=i;index++;}
        else if(pList->Strings[i].Trim()=="入库单据"){num3=i;index++;}

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


        String str="";
        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM 入库 WHERE 条码 like \"%s\" AND 入库单据 like \"%s\" AND 入库仓库 like \"%s\"",pList->Strings[num0].Trim(),DH,CK);
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;

        if(Form1->Search_ADOQuery->RecordCount==0)
        {
            Form1->RK_ADOTable->Insert();
            Form1->RK_ADOTable->FieldByName("条码")->AsString = pList->Strings[num0].Trim();
            Form1->RK_ADOTable->FieldByName("入库数量")->AsFloat = num;
            Form1->RK_ADOTable->FieldByName("入库时间")->AsString=Now().FormatString("yyyy-mm-dd");
            Form1->RK_ADOTable->FieldByName("入库仓库")->AsString = CK;
            Form1->RK_ADOTable->FieldByName("入库单据")->AsString = DH;
            Form1->RK_ADOTable->FieldByName("员工编号")->AsString = Form1->LoginName.Trim();
            Form1->RK_ADOTable->Post();
        }
        else
        {
            str="";
            str=String().sprintf("UPDATE RK SET  入库数量 = %f , 入库时间 =  \"%s\" , 员工编号 =  \"%s\" WHERE 条码 like \"%s\" AND 入库仓库 like \"%s\" AND 入库单据 like \"%s\""
                                 ,num+Form1->Search_ADOQuery->FieldByName("入库数量")->AsFloat
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
            Form1->KC_ADOTable->FieldByName("入库数量")->AsFloat = num;
            Form1->KC_ADOTable->FieldByName("仓库")->AsString = CK;
            Form1->KC_ADOTable->FieldByName("库存")->AsFloat = num;
            Form1->KC_ADOTable->Post();
         }
         else
         {
            str="";
            str=String().sprintf("UPDATE KC SET  入库数量 = %f, 库存 =%f  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                 ,num+Form1->KC_ADOQuery->FieldByName("入库数量")->AsFloat
                                 ,num+Form1->KC_ADOQuery->FieldByName("库存")->AsFloat
                                 ,pList->Strings[num0].Trim()
                                 ,CK);
            Form1->ADOCommand1->CommandText = str;
            Form1->ADOCommand1->Execute();
         }

        Application->ProcessMessages();

    }

    Form1->RK_ADOQuery->Close();
    Form1->RK_ADOQuery->SQL->Clear();
    Form1->RK_ADOQuery->SQL->Add("SELECT * FROM RK");
    Form1->RK_ADOQuery->Active= true;

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

