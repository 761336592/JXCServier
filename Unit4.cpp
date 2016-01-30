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


String exportRK[]={"����","�������","���ʱ��","���ֿ�","��ⵥ��","Ա�����","Ա������","����","����","���","�ͺ�","����","�ۼ�","��λ","��עһ","��ע��","��ע��"};
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
        ShowMessage("����ͬ���������");
        return;
    }

    String str1="";
    String str2="";
    String str="";
    int index=1;
    String SelectINF[]={"����","����","����","���","�ͺ�","����","�ۼ�","��λ","��עһ","��ע��","��ע��"};
    index=1;
    str1="SELECT * FROM ��� WHERE";
    str2="SELECT sum(�������) AS ������ FROM ��� WHERE";
    str="";
    if(CheckRKbar->Checked==True)
    {
       str=str+" "+SelectINF[ComboBox1->ItemIndex]+" like \"%"+Check_RK_bar->Text.Trim()+"%\"";
       index=0;
    }
    if(CheckRKdate->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" ���ʱ�� >= \""+Check_RK_date1->DateTime.FormatString("yyyy-mm-dd")+"\"";
        str=str+" AND";
        str=str+" ���ʱ�� <= \""+Check_RK_date2->DateTime.FormatString("yyyy-mm-dd")+"\"";
        index=0;
    }
    if(CheckRKck->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" ���ֿ� like \""+Check_RK_ck->Text.Trim()+"\"";
        index=0;
    }
    if(CheckRKdj->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" ��ⵥ�� like \"%"+Check_RK_dj->Text.Trim()+"%\"";
        index=0;
    }
    if(CheckRKbh->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" Ա����� like \""+Check_RK_bh->Text.Trim()+"\"";
        index=0;
    }
    if(CheckRKnm->Checked==True)
    {
        if(index==0)str=str+" AND";
        str=str+" Ա������ like \""+Check_RK_nm->Text.Trim()+"\"";
        index=0;
    }

    if(CheckRKbar->Checked==False&&CheckRKdate->Checked==False&&CheckRKdj->Checked==False&&CheckRKck->Checked==False&&CheckRKbh->Checked==False&&CheckRKnm->Checked==False)
    {
            str="";
            str1="SELECT * FROM ���";
            str2="SELECT sum(�������) AS ������ FROM ���";
    }
    Form1->RK_ADOQuery->Close();
    Form1->RK_ADOQuery->SQL->Clear();
    Form1->RK_ADOQuery->SQL->Add(str1+str);
    Form1->RK_ADOQuery->Active= true;

    Form1->Search_ADOQuery->Close();
    Form1->Search_ADOQuery->SQL->Clear();
    Form1->Search_ADOQuery->SQL->Add(str2+str);
    Form1->Search_ADOQuery->Active= true;

    StatusBar1->Panels->Items[0]->Text="��ѯ���    �������� "+String(Form1->RK_ADOQuery->RecordCount)+"        ����������� "+Form1->Search_ADOQuery->FieldByName("������")->AsString;
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
    ComboBox1->Items->Add("����");
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
        ShowMessage("����ͬ���������");
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
                  MessageDlg("��û��Ȩ�޵������ۣ����޸ĵ�����ʽ��",mtInformation,TMsgDlgButtons()<<mbOK,0);
                  return;
             }
         }
      }

      TStringList *SaveList=new TStringList();
      int selectnum=Form1->RK_ADOQuery->RecordCount;
      String str="";
      String FileName="�����ϸ";
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
      MessageDlg("�������",mtInformation,TMsgDlgButtons()<<mbOK,0);

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
        ShowMessage("����ͬ���������");
        return;
      }

       if(CheckRKdj->Checked==false||Check_RK_dj->Text.Trim().Length()==0)
       {
           ShowMessage("ֻ�ܰ��յ��ݴ�ӡ��������д���ݺţ�");
           return;
       }

       if(Form1->Pshow=="unshow")
       {
          ShowMessage("��û��Ȩ�޴�ӡ������");
          return;
       }

       BitBtn1Click(Sender);

       Form27->Show();
      /* Double all=0;
       //�����ܽ��
       for(int i=0;i<Form1->RK_ADOQuery->RecordCount;i++)
       {
            all=all+Form1->RK_ADOQuery->FieldByName("�������")->AsFloat*Form1->RK_ADOQuery->FieldByName("����")->AsFloat;
            Form1->RK_ADOQuery->Next();
       }
       RKprint->QRLabel13->Caption=String(all);

       TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
       RKprint->QRLabel5->Caption=ini->ReadString("Sys","RK3","������ɽ��Ϣ�Ƽ����޹�˾");
       delete  ini;
       RKprint->QRLabel3->Caption=Now().FormatString("yyyy-mm-dd hh:nn:ss");
       RKprint->QuickRep1->Preview();   */
}
//---------------------------------------------------------------------------

void __fastcall TForm4::BitBtn4Click(TObject *Sender)
{
     if(Form38->TBdata=="2")
    {
        ShowMessage("����ͬ���������");
        return;
    }

     BitBtn1Click(Sender);

     if(mrYes!=MessageDlg("�Ƿ�ȷ��ɾ����ѡ������ݣ�",mtInformation,TMsgDlgButtons()<<mbYes<<mbNo,0))
     {
            return;
     }

     String str="";



     for(int i=0;i<Form1->RK_ADOQuery->RecordCount;i++)
     {
        //�޸Ŀ����
        str="";
        Form1->KC_ADOQuery->Close();
        Form1->KC_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM ��� WHERE ���� like \"%s\" AND �ֿ� like \"%s\"",Form1->RK_ADOQuery->FieldByName("����")->AsString.Trim(),Form1->RK_ADOQuery->FieldByName("���ֿ�")->AsString.Trim());
        Form1->KC_ADOQuery->SQL->Add(str);
        Form1->KC_ADOQuery->Active= true;

        str="";
        if(Form1->KC_ADOQuery->FieldByName("��������")->AsFloat==0&&
        (Form1->KC_ADOQuery->FieldByName("�������")->AsFloat-Form1->RK_ADOQuery->FieldByName("�������")->AsFloat==0)&&
        (Form1->KC_ADOQuery->FieldByName("���")->AsFloat-Form1->RK_ADOQuery->FieldByName("�������")->AsFloat==0))
         str=String().sprintf("DELETE FROM KC WHERE ���� = \"%s\" AND �ֿ� = \"%s\"",Form1->RK_ADOQuery->FieldByName("����")->AsString.Trim(),Form1->RK_ADOQuery->FieldByName("���ֿ�")->AsString.Trim());
        else
             str=String().sprintf("UPDATE KC SET  ������� = %f , ��� = %f WHERE ���� like \"%s\" AND �ֿ� like \"%s\""
                                 ,(Form1->KC_ADOQuery->FieldByName("�������")->AsFloat-Form1->RK_ADOQuery->FieldByName("�������")->AsFloat)
                                 ,(Form1->KC_ADOQuery->FieldByName("���")->AsFloat-Form1->RK_ADOQuery->FieldByName("�������")->AsFloat)
                                 ,Form1->RK_ADOQuery->FieldByName("����")->AsString.Trim()
                                 ,Form1->RK_ADOQuery->FieldByName("���ֿ�")->AsString.Trim());




         Form1->ADOCommand1->CommandText = str;
         Form1->ADOCommand1->Execute();

        str="";
        str=String().sprintf("DELETE FROM RK WHERE ���� = \"%s\" AND ��ⵥ�� = \"%s\" AND ���ֿ� = \"%s\"",Form1->RK_ADOQuery->FieldByName("����")->AsString.Trim(),Form1->RK_ADOQuery->FieldByName("��ⵥ��")->AsString.Trim(),Form1->RK_ADOQuery->FieldByName("���ֿ�")->AsString.Trim());

        Form1->ADOCommand1->CommandText = str;
        Form1->ADOCommand1->Execute();

         Form1->RK_ADOQuery->Next();

     }

    str="SELECT * FROM ���";
    Form1->RK_ADOQuery->Close();
    Form1->RK_ADOQuery->SQL->Clear();
    Form1->RK_ADOQuery->SQL->Add(str);
    Form1->RK_ADOQuery->Active= true;

    Form1->KC_ADOQuery->Close();
    Form1->KC_ADOQuery->SQL->Clear();
    Form1->KC_ADOQuery->SQL->Add("SELECT * FROM ���");
    Form1->KC_ADOQuery->Active= true;

    ShowMessage("ɾ���ɹ�");
}
//---------------------------------------------------------------------------

void __fastcall TForm4::DBGrid1TitleClick(TColumn *Column)
{
  String s;
  if(Form1->RK_ADOQuery->Active)
  {
      if (DBGrid1->Tag==0) //˳������
      {
         Form1->RK_ADOQuery->Sort=Column->FieldName+" ASC";
         DBGrid1->Tag=1;
      }
      else   //��������,�ı�������ɫ
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
        ShowMessage("����ͬ���������");
        return;
    }

     if(Form2->wComm==INVALID_HANDLE_VALUE||Form2->wComm==NULL)
     {
            //��ʾ����û�д�
            ShowMessage("�������Ӵ�ӡ�����򿪴��ڣ�");
            return;
     }
     if(CheckRKdj->Checked==false||Check_RK_dj->Text.Trim().Length()==0)
     {
           ShowMessage("����ѡ��Ҫ��ӡ�ĵ���");
           return;
     }

     String print[]={"����","����","����","���","�ͺ�","����","�ۼ�","��λ","��עһ","��ע��","��ע��"};
     TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
     String RK1=ini->ReadString("Sys","RK1","1*2*6");

     if(strstr(RK1.c_str(),"6")&&Form1->Pshow=="unshow")
     {
          ShowMessage("��û��Ȩ�޴�ӡ������");
          return;
     }

     TStringList *bList =new TStringList();
     Form1->CrnListSplitString(RK1,bList,'*');
     String RK2=ini->ReadString("Sys","RK2","7");
     String RK3=ini->ReadString("Sys","RK3","������ɽ��Ϣ�Ƽ����޹�˾");
     int index=0;
     for(int j=0;j<bList->Count;j++)
     {
         if(bList->Strings[j].Trim().ToInt()==RK2.Trim().ToInt())
         index=1;
     }

     //��ȡ������======================================================
     String barcode="";
     unsigned long lrc;

     float num=0;
     float count=0;
     float allcount=0;
     String printstr="";

     int selectnum=0;

     Form1->RK_ADOQuery->Close();
     Form1->RK_ADOQuery->SQL->Clear();
     Form1->RK_ADOQuery->SQL->Add("SELECT * FROM ��� WHERE ��ⵥ�� like \""+Check_RK_dj->Text.Trim()+"\"");
     Form1->RK_ADOQuery->Active= true;

     selectnum=Form1->RK_ADOQuery->RecordCount;
     printstr="";
     printstr=RK3+"\r\n���ţ�"+Check_RK_dj->Text.Trim()+"\r\n"+"ʱ�䣺"+Now().FormatString("yyyy-mm-dd hh:nn:ss")+"\r\n--------------------------------";
     WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL);
     allcount=0;
     for(int i=0;i<selectnum;i++)
     {
            num=Form1->RK_ADOQuery->FieldByName("�������")->AsFloat;
            if(index==1)
            {
                count=Form1->RK_ADOQuery->FieldByName(print[RK2.Trim().ToInt()-1])->AsFloat*Form1->RK_ADOQuery->FieldByName("�������")->AsFloat;
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
           printstr="\r\n--------------------------------��  �ƣ�"+String(allcount);
           printstr+="\r\n�����ˣ�"+ Form1->RK_ADOQuery->FieldByName("Ա�����")->AsString;
       }
       else  printstr="\r\n--------------------------------�����ˣ�"+ Form1->RK_ADOQuery->FieldByName("Ա�����")->AsString;
       printstr+="\r\n\r\n\r\n\r\n\r\n\r\n";
       WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL);

       //��ʾ��ӡ���
       //ShowMessage("��ӡ�ɹ�");

       delete ini;
       delete bList;


}
//---------------------------------------------------------------------------

void __fastcall TForm4::ComboBox1Change(TObject *Sender)
{
      if(Form1->Pshow=="unshow")
      {
         if(ComboBox1->Text=="����")
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
            StatusBar1->Panels->Items[0]->Text="�������ӷ�����";
            Form38->ClientSocket1->Host=Form38->Edit2->Text.Trim();
            Form38->ClientSocket1->Port=Form38->Edit3->Text.Trim().ToInt();
            Form38->ClientSocket1->Active=true;


            //��¼һ�¿��Ƿ���ȷ���������ȷ��ʾ���Ҳ����ϴ�

            
        }
        catch(...)
        {
            MessageDlg("����������ʧ�ܣ���ȷ�Ϸ������Ƿ��������߷�������Ϣ�Ƿ����óɹ�",mtInformation,TMsgDlgButtons()<<mbOK,0);
        }
    }



    if(Form38->TBdata!="0"&&Form38->ClientSocket1->Active==true)
    {
        MessageDlg("����������ͬ�������Ե�",mtInformation,TMsgDlgButtons()<<mbOK,0);
        return;
    }

    BitBtn1Click(Sender);

    if(Form1->RK_ADOQuery->RecordCount==0)
    {
        MessageDlg("û��������Ҫͬ��",mtInformation,TMsgDlgButtons()<<mbOK,0);
        return;
    }

    if(mrYes!=MessageDlg("����ͬ��������������ʾ�����ݣ��Ƿ�ȷ��ͬ����",mtInformation,TMsgDlgButtons()<<mbYes<<mbNo,0))
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
        ShowMessage("����ͬ���������");
        return;
    }

    String ss="Provider=Microsoft.Jet.OLEDB.4.0;Data Source="+ExtractFilePath(Application->ExeName)+"��⵼��.xls;Mode=Share Deny None;Extended Properties=\"Excel 8.0;IMEX=1;\";Persist Security Info=False" ;
    Form1->con1->Close();
    Form1->con1->ConnectionString=ss;
    Form1->con1->Connected  =   true;
    Form1->qry1->Close();
    Form1->qry1->SQL->Clear();
    Form1->qry1->SQL->Add("select * from [Sheet1$]");
    Form1->qry1->Open();
    Form1->qry1->Active=true;


    //���ţ��ֿ⣬���룬����

    int num0=0;
    int num1=0;
    int num2=0;
    int num3=0;

    int index=0;
    for(int i=0;;i++)
    {
        if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="����"){num0=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="�������"){num1=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="���ֿ�"){num2=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="��ⵥ��"){num3=i;index++;}

        if(index==4)break;
    }

    String str="";
    Double num=0;
    int indexshow=0;
    String CK="";
    String DH="";
    while(!Form1->qry1->Eof) //ѭ��д�����ݿ�
    {
        if(Form1->qry1->Fields->Fields[num0]->AsString.Trim().Length()==0)
        {
           Form1->qry1->Next();
           continue;
        }
        indexshow++;
        this->StatusBar1->Panels->Items[0]->Text="���ڵ�������    ������ "+String(indexshow);
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
        str=String().sprintf("SELECT * FROM ��� WHERE ���� like \"%s\" AND ��ⵥ�� like \"%s\" AND ���ֿ� like \"%s\"",Form1->qry1->Fields->Fields[num0]->AsString.Trim(),DH,CK);
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;

        if(Form1->Search_ADOQuery->RecordCount==0)
        {
            Form1->RK_ADOTable->Insert();
            Form1->RK_ADOTable->FieldByName("����")->AsString = Form1->qry1->Fields->Fields[num0]->AsString.Trim();
            Form1->RK_ADOTable->FieldByName("�������")->AsFloat = num;
            Form1->RK_ADOTable->FieldByName("���ʱ��")->AsString=Now().FormatString("yyyy-mm-dd");
            Form1->RK_ADOTable->FieldByName("���ֿ�")->AsString = CK;
            Form1->RK_ADOTable->FieldByName("��ⵥ��")->AsString = DH;
            Form1->RK_ADOTable->FieldByName("Ա�����")->AsString = Form1->LoginName.Trim();
            Form1->RK_ADOTable->Post();
        }
        else
        {
            str="";
            str=String().sprintf("UPDATE RK SET  ������� = %f , ���ʱ�� =  \"%s\" , Ա����� =  \"%s\" WHERE ���� like \"%s\" AND ���ֿ� like \"%s\" AND ��ⵥ�� like \"%s\""
                                 ,num+Form1->Search_ADOQuery->FieldByName("�������")->AsFloat
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
        str=String().sprintf("SELECT * FROM ��� WHERE ���� like \"%s\" AND �ֿ� like \"%s\"",Form1->qry1->Fields->Fields[num0]->AsString.Trim(),CK);
        Form1->KC_ADOQuery->SQL->Add(str);
        Form1->KC_ADOQuery->Active= true;

        if(Form1->KC_ADOQuery->RecordCount==0)
        {
            Form1->KC_ADOTable->Insert();
            Form1->KC_ADOTable->FieldByName("����")->AsString = Form1->qry1->Fields->Fields[num0]->AsString.Trim();
            Form1->KC_ADOTable->FieldByName("�������")->AsFloat = num;
            Form1->KC_ADOTable->FieldByName("�ֿ�")->AsString = CK;
            Form1->KC_ADOTable->FieldByName("���")->AsFloat = num;
            Form1->KC_ADOTable->Post();
         }
         else
         {
            str="";
            str=String().sprintf("UPDATE KC SET  ������� = %f, ��� =%f  WHERE ���� like \"%s\" AND �ֿ� like \"%s\""
                                 ,num+Form1->KC_ADOQuery->FieldByName("�������")->AsFloat
                                 ,num+Form1->KC_ADOQuery->FieldByName("���")->AsFloat
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

    MessageDlg("�������",mtInformation,TMsgDlgButtons()<<mbOK,0);

    this->StatusBar1->Panels->Items[0]->Text="";
        
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button2Click(TObject *Sender)
{
    TStringList *DataList=new TStringList();
    TStringList *pList=new TStringList();
    DataList->Text="";
    DataList->LoadFromFile("��⵼��.txt");

    pList->Text="";
    Form1->CrnListSplitString(DataList->Strings[0],pList,'\t');

    int num0=0;
    int num1=0;
    int num2=0;
    int num3=0;

    int index=0;
    for(int i=0;i<pList->Count;i++)
    {
        if(pList->Strings[i].Trim()=="����"){num0=i;index++;}
        else if(pList->Strings[i].Trim()=="�������"){num1=i;index++;}
        else if(pList->Strings[i].Trim()=="���ֿ�"){num2=i;index++;}
        else if(pList->Strings[i].Trim()=="��ⵥ��"){num3=i;index++;}

        if(index==4)break;
    }

    if(index!=4)
    {
            MessageDlg("��ʽ����",mtInformation,TMsgDlgButtons()<<mbOK,0);
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
        this->StatusBar1->Panels->Items[0]->Text="���ڵ�������    ������ "+String(indexshow);
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
        str=String().sprintf("SELECT * FROM ��� WHERE ���� like \"%s\" AND ��ⵥ�� like \"%s\" AND ���ֿ� like \"%s\"",pList->Strings[num0].Trim(),DH,CK);
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;

        if(Form1->Search_ADOQuery->RecordCount==0)
        {
            Form1->RK_ADOTable->Insert();
            Form1->RK_ADOTable->FieldByName("����")->AsString = pList->Strings[num0].Trim();
            Form1->RK_ADOTable->FieldByName("�������")->AsFloat = num;
            Form1->RK_ADOTable->FieldByName("���ʱ��")->AsString=Now().FormatString("yyyy-mm-dd");
            Form1->RK_ADOTable->FieldByName("���ֿ�")->AsString = CK;
            Form1->RK_ADOTable->FieldByName("��ⵥ��")->AsString = DH;
            Form1->RK_ADOTable->FieldByName("Ա�����")->AsString = Form1->LoginName.Trim();
            Form1->RK_ADOTable->Post();
        }
        else
        {
            str="";
            str=String().sprintf("UPDATE RK SET  ������� = %f , ���ʱ�� =  \"%s\" , Ա����� =  \"%s\" WHERE ���� like \"%s\" AND ���ֿ� like \"%s\" AND ��ⵥ�� like \"%s\""
                                 ,num+Form1->Search_ADOQuery->FieldByName("�������")->AsFloat
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
        str=String().sprintf("SELECT * FROM ��� WHERE ���� like \"%s\" AND �ֿ� like \"%s\"",pList->Strings[num0].Trim(),CK);
        Form1->KC_ADOQuery->SQL->Add(str);
        Form1->KC_ADOQuery->Active= true;

        if(Form1->KC_ADOQuery->RecordCount==0)
        {
            Form1->KC_ADOTable->Insert();
            Form1->KC_ADOTable->FieldByName("����")->AsString = pList->Strings[num0].Trim();
            Form1->KC_ADOTable->FieldByName("�������")->AsFloat = num;
            Form1->KC_ADOTable->FieldByName("�ֿ�")->AsString = CK;
            Form1->KC_ADOTable->FieldByName("���")->AsFloat = num;
            Form1->KC_ADOTable->Post();
         }
         else
         {
            str="";
            str=String().sprintf("UPDATE KC SET  ������� = %f, ��� =%f  WHERE ���� like \"%s\" AND �ֿ� like \"%s\""
                                 ,num+Form1->KC_ADOQuery->FieldByName("�������")->AsFloat
                                 ,num+Form1->KC_ADOQuery->FieldByName("���")->AsFloat
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

    MessageDlg("�������",mtInformation,TMsgDlgButtons()<<mbOK,0);

    this->StatusBar1->Panels->Items[0]->Text="";


    delete DataList;
    delete pList;

}
//---------------------------------------------------------------------------

