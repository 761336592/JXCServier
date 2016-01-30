//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit11.h"
#include "Unit1.h"
#include "Unit32.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm11 *Form11;

int yd_CurrentCol;   // �ر����ڵ�ǰ��
int yd_CurrentRow;  // �ر����ڵ�ǰ��

//---------------------------------------------------------------------------
__fastcall TForm11::TForm11(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm11::sgPurDetailKeyPress(TObject *Sender, char &Key)
{
    if(Key ==13)
    {
        // ������һ����Ԫ��
        if(yd_CurrentCol == 1 )
        {


            //�����������������д�ڿ����
            Form1->Search_ADOQuery->Close();
            Form1->Search_ADOQuery->SQL->Clear();
            Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where ���� like \""+sgPurDetail->Cells[1][sgPurDetail->Row].Trim()+"\"");
            Form1->Search_ADOQuery->Active= true;

           // ShowMessage(sgPurDetail->Cells[1][sgPurDetail->Row].Trim());

            sgPurDetail->Cells[2][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim();
            sgPurDetail->Cells[3][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("�ۼ�")->AsString.Trim();

            if(CheckBox1->Checked==true)
            {
               sgPurDetail->Cells[4][sgPurDetail->Row]="1";
               sgPurDetail->RowCount++;
               sgPurDetail->Cells[0][sgPurDetail->RowCount-1] = sgPurDetail->RowCount-1;
               sgPurDetail->Col = 1;
               sgPurDetail->Row = yd_CurrentRow + 1;
            }
            else
            sgPurDetail->Col = 4;
        }
        else if(yd_CurrentCol == 4)   // ��һ��
        {
            sgPurDetail->RowCount++;
            sgPurDetail->Cells[0][sgPurDetail->RowCount-1] = sgPurDetail->RowCount-1;
            sgPurDetail->Col = 1;
            sgPurDetail->Row = yd_CurrentRow + 1;
        }

        yd_CurrentCol = sgPurDetail->Col;
        yd_CurrentRow = sgPurDetail->Row;
    }
    /*else if(Key==VK_SPACE)
    {
         Button1Click(Sender);
    } */
}
//---------------------------------------------------------------------------
void __fastcall TForm11::sgPurDetailSelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
       if(  ACol==2 || ACol==3)  // �����Ա༭����
            sgPurDetail->Options >> goEditing;
        else
            sgPurDetail->Options << goEditing;

        yd_CurrentCol = ACol;
        yd_CurrentRow = ARow;
}
//---------------------------------------------------------------------------
void __fastcall TForm11::FormShow(TObject *Sender)
{
     //���
    Edit1->Text="";

       // ������ϸ�б�������
    sgPurDetail->Cells[0][0] = "���";
    sgPurDetail->ColWidths[0] = 32;
    sgPurDetail->Cells[1][0] = Form1->infshow1;
    sgPurDetail->ColWidths[1] = 200;
    sgPurDetail->Cells[2][0] = Form1->infshow2+"        ���������п�ѡ����Ʒ��";
    sgPurDetail->ColWidths[2] = 250;
    sgPurDetail->Cells[3][0] = Form1->infshow7;
    sgPurDetail->ColWidths[3] = 64;
    sgPurDetail->Cells[4][0] = "����";
    sgPurDetail->ColWidths[3] = 100;


    for(int i=0;i<sgPurDetail->RowCount;i++)
    {
       sgPurDetail->Cells[1][i+1]="";
       sgPurDetail->Cells[2][i+1]="";
       sgPurDetail->Cells[3][i+1]="";
       sgPurDetail->Cells[4][i+1]="";
    }
    sgPurDetail->RowCount=2;
    sgPurDetail->Cells[0][1] = 1;

    yd_CurrentCol = 1;
    yd_CurrentRow = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm11::BitBtn2Click(TObject *Sender)
{
String ss="Provider=Microsoft.Jet.OLEDB.4.0;Data Source="+ExtractFilePath(Application->ExeName)+"����.xls;Mode=Share Deny None;Extended Properties=\"Excel 8.0;IMEX=1;\";Persist Security Info=False" ;
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
        if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="����"){num0=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="����"){num1=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="����"){num2=i;index++;}
        if(index==3)break;
    }

    String str="";
    Double kc=0;
    String name="";



    int indexshow=0;
    while(!Form1->qry1->Eof) //ѭ��д�����ݿ�
    {
        if(Form1->qry1->Fields->Fields[num0]->AsString.Trim().Length()==0)
        {
           Form1->qry1->Next();
           continue;
        }
        indexshow++;
        StatusBar1->Panels->Items[0]->Text="���ڵ�������    ������ "+String(indexshow);

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

        //��ѯ����Ƿ���� ���������ֱ�Ӹ��£���������������������Ժ������ӽ�ȥ
        str="";
        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM YD WHERE ���� like \"%s\" AND ���� like \"%s\"",Form1->qry1->Fields->Fields[num0]->AsString.Trim(),Form1->qry1->Fields->Fields[num1]->AsString.Trim());
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;



        if(Form1->Search_ADOQuery->RecordCount==0)
        {
            Form1->YD_ADOTable->Insert();
            Form1->YD_ADOTable->FieldByName("����")->AsString = Form1->qry1->Fields->Fields[num0]->AsString.Trim();
            Form1->YD_ADOTable->FieldByName("����")->AsString = Form1->qry1->Fields->Fields[num1]->AsString.Trim();
            Form1->YD_ADOTable->FieldByName("Ӧɨ����")->AsFloat = kc;
            Form1->YD_ADOTable->FieldByName("��ɨ����")->AsFloat = 0;
            Form1->YD_ADOTable->FieldByName("ʱ��")->AsString=Now().FormatString("yyyy-mm-dd");
            Form1->YD_ADOTable->FieldByName("Ա�����")->AsString = "";
            Form1->YD_ADOTable->Post();
         }
         else
         {
            str="";
            str=String().sprintf("UPDATE YD SET  Ӧɨ���� = %f , ʱ�� =  \"%s\"  WHERE ���� like \"%s\" AND ���� like \"%s\""
                                 ,kc+Form1->Search_ADOQuery->FieldByName("Ӧɨ����")->AsFloat
                                 ,Now().FormatString("yyyy-mm-dd")
                                 ,Form1->qry1->Fields->Fields[num0]->AsString.Trim()
                                 ,Form1->qry1->Fields->Fields[num1]->AsString.Trim());
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
    Form1->YD_ADOQuery->Close();
    Form1->YD_ADOQuery->SQL->Clear();
    Form1->YD_ADOQuery->SQL->Add("SELECT * FROM �鵥");
    Form1->YD_ADOQuery->Active= true;
    MessageDlg("�������",mtInformation,TMsgDlgButtons()<<mbOK,0);

    StatusBar1->Panels->Items[0]->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm11::CheckBox1Click(TObject *Sender)
{
    if(CheckBox1->Checked==true)
    {
        sgPurDetail->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm11::Button1Click(TObject *Sender)
{
    if(Edit1->Text.Trim().Length()==0)
    {
        Edit1->Text="DH001";
        if(mrYes!=MessageDlg("���ݺŲ���Ϊ�գ���Ĭ��ΪDH001���Ƿ�ȷ�ϣ�",mtInformation,TMsgDlgButtons()<<mbYes<<mbNo,0))
        {
            return;
        }
    }

    String barcode="";
    float YDnum=0;

    for(int i=0;i<sgPurDetail->RowCount;i++)
    {
        if(sgPurDetail->Cells[1][i+1].Trim().Length()==0)continue;
        barcode=sgPurDetail->Cells[1][i+1].Trim();
        YDnum=sgPurDetail->Cells[4][i+1].Trim().ToDouble();

        String str="";
        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM �鵥 WHERE ���� like \"%s\" AND ���� like \"%s\"",barcode.Trim(),Edit1->Text.Trim());
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;

        if(Form1->Search_ADOQuery->RecordCount==0)
        {
            Form1->YD_ADOTable->Insert();
            Form1->YD_ADOTable->FieldByName("����")->AsString = barcode.Trim();
            Form1->YD_ADOTable->FieldByName("Ӧɨ����")->AsFloat = YDnum;
            Form1->YD_ADOTable->FieldByName("��ɨ����")->AsFloat = 0;
            Form1->YD_ADOTable->FieldByName("ʱ��")->AsString=Now().FormatString("yyyy-mm-dd");
            Form1->YD_ADOTable->FieldByName("����")->AsString = Edit1->Text.Trim();
            Form1->YD_ADOTable->FieldByName("Ա�����")->AsString = "";
            Form1->YD_ADOTable->Post();
        }
        else
        {
            str="";
            str=String().sprintf("UPDATE YD SET  Ӧɨ���� = %f , ʱ�� =  \"%s\"  WHERE ���� like \"%s\" AND ���� like \"%s\""
                                 ,YDnum+Form1->Search_ADOQuery->FieldByName("Ӧɨ����")->AsFloat
                                 ,Now().FormatString("yyyy-mm-dd")
                                 ,barcode.Trim()
                                 ,Edit1->Text.Trim());
                            Form1->ADOCommand1->CommandText = str;
                            Form1->ADOCommand1->Execute();
        }
    }

    ShowMessage("�������ӳɹ���");

    Form1->YD_ADOQuery->Close();
    Form1->YD_ADOQuery->SQL->Clear();
    Form1->YD_ADOQuery->SQL->Add("SELECT * FROM �鵥");
    Form1->YD_ADOQuery->Active= true;

    if(CheckBox1->Checked==false)Button1->Enabled=false;
    else
    {
        Button2Click(Sender);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm11::sgPurDetailClick(TObject *Sender)
{
     if(sgPurDetail->Col==2||sgPurDetail->Col==3)
     {
          //��ʾ����ѯ����
          Form32->typeindex="11";
          Form32->Show();

     }
}
//---------------------------------------------------------------------------

void __fastcall TForm11::sgPurDetailDrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    if(ACol==2&&ARow==0)
     {
         TRect rect=sgPurDetail->CellRect(ACol,ARow);
         sgPurDetail->Canvas->Font->Color=clRed; //����������ɫ
         sgPurDetail->Canvas->TextRect(Rect, Rect.left, 2,
         sgPurDetail->Cells[ACol][ARow]);
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm11::BitBtn1Click(TObject *Sender)
{
    TStringList *DataList=new TStringList();
    TStringList *pList=new TStringList();
    DataList->Text="";
    DataList->LoadFromFile("����.txt");

    pList->Text="";
    Form1->CrnListSplitString(DataList->Strings[0],pList,'\t');

    int num0=0;
    int num1=0;
    int num2=0;

    int index=0;
    for(int i=0;i<pList->Count;i++)
    {
        if(pList->Strings[i].Trim()=="����"){num0=i;index++;}
        else if(pList->Strings[i].Trim()=="����"){num1=i;index++;}
        else if(pList->Strings[i].Trim()=="����"){num2=i;index++;}
        if(index==3)break;
    }

    if(index!=3)
    {
            MessageDlg("��ʽ����",mtInformation,TMsgDlgButtons()<<mbOK,0);
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
        this->StatusBar1->Panels->Items[0]->Text="���ڵ�������    ������ "+String(indexshow);


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





        //��ѯ����Ƿ���� ���������ֱ�Ӹ��£���������������������Ժ������ӽ�ȥ
        str="";
        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM YD WHERE ���� like \"%s\" AND ���� like \"%s\"",pList->Strings[num0].Trim(),pList->Strings[num1].Trim());
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;



        if(Form1->Search_ADOQuery->RecordCount==0)
        {
            Form1->YD_ADOTable->Insert();
            Form1->YD_ADOTable->FieldByName("����")->AsString = pList->Strings[num0].Trim();
            Form1->YD_ADOTable->FieldByName("����")->AsString = pList->Strings[num1].Trim();
            Form1->YD_ADOTable->FieldByName("Ӧɨ����")->AsFloat = kc;
            Form1->YD_ADOTable->FieldByName("��ɨ����")->AsFloat = 0;
            Form1->YD_ADOTable->FieldByName("ʱ��")->AsString=Now().FormatString("yyyy-mm-dd");
            Form1->YD_ADOTable->FieldByName("Ա�����")->AsString = "";
            Form1->YD_ADOTable->Post();
         }
         else
         {
            str="";
            str=String().sprintf("UPDATE YD SET  Ӧɨ���� = %f , ʱ�� =  \"%s\"  WHERE ���� like \"%s\" AND ���� like \"%s\""
                                 ,kc+Form1->Search_ADOQuery->FieldByName("Ӧɨ����")->AsFloat
                                 ,Now().FormatString("yyyy-mm-dd")
                                 ,pList->Strings[num0].Trim()
                                 ,pList->Strings[num1].Trim());
                            Form1->ADOCommand1->CommandText = str;
                            Form1->ADOCommand1->Execute();
         }



        Application->ProcessMessages();

    }

    Form1->YD_ADOQuery->Close();
    Form1->YD_ADOQuery->SQL->Clear();
    Form1->YD_ADOQuery->SQL->Add("SELECT * FROM �鵥");
    Form1->YD_ADOQuery->Active= true;
    MessageDlg("�������",mtInformation,TMsgDlgButtons()<<mbOK,0);

    this->StatusBar1->Panels->Items[0]->Text="";


    delete DataList;
    delete pList;

}
//---------------------------------------------------------------------------

void __fastcall TForm11::Button2Click(TObject *Sender)
{
    for(int i=0;i<sgPurDetail->RowCount;i++)
    {
       sgPurDetail->Cells[1][i+1]="";
       sgPurDetail->Cells[2][i+1]="";
       sgPurDetail->Cells[3][i+1]="";
       sgPurDetail->Cells[4][i+1]="";
    }
    sgPurDetail->RowCount=2;
    sgPurDetail->Cells[0][1] = 1;
     Edit1->Clear();
     Edit1->SetFocus();
    yd_CurrentCol = 1;
    yd_CurrentRow = 1;

    Button1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm11::Edit1KeyPress(TObject *Sender, char &Key)
{
     if(Key==VK_RETURN)sgPurDetail->SetFocus();  
}
//---------------------------------------------------------------------------
