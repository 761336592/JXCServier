//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit8.h"
#include "Unit1.h"
#include "Unit9.h"
#include "Unit32.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;

int yk_CurrentCol;   // �ر����ڵ�ǰ��
int yk_CurrentRow;  // �ر����ڵ�ǰ��

//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm8::FormShow(TObject *Sender)
{
    YK_yck->Text="";
    YK_mck->Text="";

           // ������ϸ�б�������
    sgPurDetail->Cells[0][0] = "���";
    sgPurDetail->ColWidths[0] = 32;
    sgPurDetail->Cells[1][0] = Form1->infshow1;
    sgPurDetail->ColWidths[1] = 200;
    sgPurDetail->Cells[2][0] = Form1->infshow2+"        ���������п�ѡ����Ʒ��";
    sgPurDetail->ColWidths[2] = 250;
    sgPurDetail->Cells[3][0] = Form1->infshow3;
    sgPurDetail->ColWidths[3] = 100;
    sgPurDetail->Cells[4][0] = Form1->infshow4;
    sgPurDetail->ColWidths[4] = 100;
    sgPurDetail->Cells[5][0] = Form1->infshow5;
    sgPurDetail->ColWidths[5] = 100;
    sgPurDetail->Cells[6][0] = "����";
    sgPurDetail->ColWidths[6] = 100;


    yk_CurrentCol = 1;
    yk_CurrentRow = 1;

    for(int i=0;i<sgPurDetail->RowCount;i++)
    {
       sgPurDetail->Cells[1][i+1]="";
       sgPurDetail->Cells[2][i+1]="";
       sgPurDetail->Cells[3][i+1]="";
       sgPurDetail->Cells[4][i+1]="";
    }
    
    sgPurDetail->RowCount=2;
    sgPurDetail->Cells[0][1] = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::sgPurDetailKeyPress(TObject *Sender, char &Key)
{
    if(Key ==13)
    {
        // ������һ����Ԫ��
        if(yk_CurrentCol == 1 )
        {


            //�����������������д�ڿ����
            Form1->Search_ADOQuery->Close();
            Form1->Search_ADOQuery->SQL->Clear();
            Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where ���� like \""+sgPurDetail->Cells[1][sgPurDetail->Row].Trim()+"\"");
            Form1->Search_ADOQuery->Active= true;


            sgPurDetail->Cells[2][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim();
            sgPurDetail->Cells[3][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim();
            sgPurDetail->Cells[4][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("���")->AsString.Trim();
            sgPurDetail->Cells[5][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("�ͺ�")->AsString.Trim();

            if(CheckBox1->Checked==true)
            {
               sgPurDetail->Cells[6][sgPurDetail->Row]="1";
               sgPurDetail->RowCount++;
               sgPurDetail->Cells[0][sgPurDetail->RowCount-1] = sgPurDetail->RowCount-1;
               sgPurDetail->Col = 1;
               sgPurDetail->Row = yk_CurrentRow + 1;
            }
            else
            sgPurDetail->Col = 6;
        }
        else if(yk_CurrentCol == 6)   // ��һ��
        {
            sgPurDetail->RowCount++;
            sgPurDetail->Cells[0][sgPurDetail->RowCount-1] = sgPurDetail->RowCount-1;
            sgPurDetail->Col = 1;
            sgPurDetail->Row = yk_CurrentRow + 1;
        }

        yk_CurrentCol = sgPurDetail->Col;
        yk_CurrentRow = sgPurDetail->Row;
    }
    /*else if(Key==VK_SPACE)
    {
         Button1Click(Sender);
    }*/
}
//---------------------------------------------------------------------------
void __fastcall TForm8::sgPurDetailSelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
        if(  ACol==2 || ACol==3|| ACol==4|| ACol==5)  // �����Ա༭����
            sgPurDetail->Options >> goEditing;
        else
            sgPurDetail->Options << goEditing;

        yk_CurrentCol = ACol;
        yk_CurrentRow = ARow;
}
//---------------------------------------------------------------------------
void __fastcall TForm8::CheckBox1Click(TObject *Sender)
{
    if(CheckBox1->Checked==true)
    {
        sgPurDetail->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button1Click(TObject *Sender)
{
    if(YK_yck->Text.Trim().Length()==0)
    {
            MessageDlg("ԭ�ֿⲻ��Ϊ��",mtInformation,TMsgDlgButtons()<<mbOK,0);
            return;
    }

    if(YK_mck->Text.Trim().Length()==0)
    {
            MessageDlg("Ŀ�Ĳֿⲻ��Ϊ��",mtInformation,TMsgDlgButtons()<<mbOK,0);
            return;
    }

    if(Form1->LoginName.Trim().Length()==0&&YK_dh->Text.Trim().Length()==0)
    {
        YK_dh->Text="DH001";
        if(mrYes!=MessageDlg("�ƿⵥ�Ų���Ϊ�գ��Ƿ��ƿⵥ��Ĭ��ΪYK001��Ա����Ĭ��Ϊ01",mtInformation,TMsgDlgButtons()<<mbYes<<mbNo,0))
        {
            return;
        }
    }
    else if(YK_dh->Text.Trim().Length()==0)
    {
        YK_dh->Text="DH001";
        if(mrYes!=MessageDlg("�ƿⵥ�Ų���Ϊ�գ��Ƿ�Ĭ��ΪYK001",mtInformation,TMsgDlgButtons()<<mbYes<<mbNo,0))
        {
            return;
        }
    }


    String barcode="";
    float YKnum=0;

    for(int i=0;i<sgPurDetail->RowCount;i++)
    {
        if(sgPurDetail->Cells[1][i+1].Trim().Length()==0)continue;
        barcode=sgPurDetail->Cells[1][i+1].Trim();
        YKnum=sgPurDetail->Cells[6][i+1].Trim().ToDouble();

        String str="";
        /*Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM �ƿ� WHERE ���� like \"%s\" AND ԭ�ֿ� like \"%s\" AND Ŀ�Ĳֿ� like \"%s\"",barcode.Trim(),YK_yck->Text.Trim(),YK_mck->Text.Trim());
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;

        if(Form1->Search_ADOQuery->RecordCount==0)
        {*/
            Form1->YK_ADOTable->Insert();
            Form1->YK_ADOTable->FieldByName("����")->AsString = barcode.Trim();
            Form1->YK_ADOTable->FieldByName("����")->AsFloat = YKnum;
            Form1->YK_ADOTable->FieldByName("�ƿ�ʱ��")->AsString=Now().FormatString("yyyy-mm-dd");
            Form1->YK_ADOTable->FieldByName("�ƿⵥ��")->AsString = YK_dh->Text.Trim();
            Form1->YK_ADOTable->FieldByName("ԭ�ֿ�")->AsString = YK_yck->Text.Trim();
            Form1->YK_ADOTable->FieldByName("Ŀ�Ĳֿ�")->AsString = YK_mck->Text.Trim();
            Form1->YK_ADOTable->FieldByName("Ա�����")->AsString = Form1->LoginName.Trim();
            Form1->YK_ADOTable->Post();
        /*}
        else
        {
            str="";
            str=String().sprintf("UPDATE YK SET  ���� = %f , �ƿ�ʱ�� =  \"%s\" , Ա����� =  \"%s\"  WHERE ���� like \"%s\" AND ԭ�ֿ� like \"%s\" AND Ŀ�Ĳֿ� like \"%s\""
                                 ,YKnum+Form1->Search_ADOQuery->FieldByName("����")->AsFloat
                                 ,Now().FormatString("yyyy-mm-dd")
                                 ,Form1->LoginName.Trim()
                                 ,barcode.Trim()
                                 ,YK_yck->Text.Trim()
                                 ,YK_mck->Text.Trim());
                            Form1->ADOCommand1->CommandText = str;
                            Form1->ADOCommand1->Execute();
        } */

        //�޸Ŀ�����

        str="";
        Form1->KC_ADOQuery->Close();
        Form1->KC_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM ��� WHERE ���� like \"%s\" AND �ֿ� like \"%s\"",barcode.Trim(),YK_yck->Text.Trim());
        Form1->KC_ADOQuery->SQL->Add(str);
        Form1->KC_ADOQuery->Active= true;

        if(Form1->KC_ADOQuery->RecordCount==0)
        {
            //MessageDlg("11",mtInformation,TMsgDlgButtons()<<mbOK,0);
            Form1->KC_ADOTable->Insert();
            Form1->KC_ADOTable->FieldByName("����")->AsString = barcode.Trim();
            Form1->KC_ADOTable->FieldByName("��������")->AsFloat = 0;
            Form1->KC_ADOTable->FieldByName("�������")->AsFloat = 0;
            Form1->KC_ADOTable->FieldByName("�ֿ�")->AsString = YK_yck->Text.Trim();
            Form1->KC_ADOTable->FieldByName("���")->AsFloat = 0 -YKnum;
            Form1->KC_ADOTable->Post();
         }
         else
         {
            str="";
            str=String().sprintf("UPDATE KC SET   ��� =%f  WHERE ���� like \"%s\" AND �ֿ� like \"%s\""
                                 ,Form1->KC_ADOQuery->FieldByName("���")->AsFloat-YKnum
                                 ,barcode.Trim()
                                 ,YK_yck->Text.Trim());
            Form1->ADOCommand1->CommandText = str;
            Form1->ADOCommand1->Execute();
         }


        str="";
        Form1->KC_ADOQuery->Close();
        Form1->KC_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM ��� WHERE ���� like \"%s\" AND �ֿ� like \"%s\"",barcode.Trim(),YK_mck->Text.Trim());
        Form1->KC_ADOQuery->SQL->Add(str);
        Form1->KC_ADOQuery->Active= true;

        if(Form1->KC_ADOQuery->RecordCount==0)
        {
            //MessageDlg("11",mtInformation,TMsgDlgButtons()<<mbOK,0);
            Form1->KC_ADOTable->Insert();
            Form1->KC_ADOTable->FieldByName("����")->AsString = barcode.Trim();
            Form1->KC_ADOTable->FieldByName("��������")->AsFloat = 0;
            Form1->KC_ADOTable->FieldByName("�������")->AsFloat = 0;
            Form1->KC_ADOTable->FieldByName("�ֿ�")->AsString = YK_mck->Text.Trim();
            Form1->KC_ADOTable->FieldByName("���")->AsFloat = YKnum;
            Form1->KC_ADOTable->Post();
         }
         else
         {
            str="";
            str=String().sprintf("UPDATE KC SET   ��� =%f  WHERE ���� like \"%s\" AND �ֿ� like \"%s\""
                                 ,Form1->KC_ADOQuery->FieldByName("���")->AsFloat+YKnum
                                 ,barcode.Trim()
                                 ,YK_mck->Text.Trim());
            Form1->ADOCommand1->CommandText = str;
            Form1->ADOCommand1->Execute();
         }

    }

    Form1->KC_ADOQuery->Close();
    Form1->KC_ADOQuery->SQL->Clear();
    Form1->KC_ADOQuery->SQL->Add("SELECT * FROM ���");
    Form1->KC_ADOQuery->Active= true;

    if(RadioButton1->Checked==true)
    {

        Form1->YK_ADOQuery->Close();
        Form1->YK_ADOQuery->SQL->Clear();
        Form1->YK_ADOQuery->SQL->Add("SELECT * FROM �ƿ�");
        Form1->YK_ADOQuery->Active= true;
        ShowMessage("���ݽ����ɹ���");
    }
    else
    {
         Form9->CheckBox1->Checked=false;
         Form9->CheckBox2->Checked=false;
         Form9->CheckBox3->Checked=false;
         Form9->CheckBox4->Checked=false;
         Form9->CheckBox5->Checked=false;
         Form9->CheckBox6->Checked=false;

         Form9->CheckBox7->Checked=true;
         Form9->Edit6->Text=YK_dh->Text.Trim();
         Form9->Button1Click(Sender);
    }
     if(CheckBox1->Checked==false)Button1->Enabled=false;
    else
    {
        Button2Click(Sender);
        YK_dh->Text="DH"+Now().FormatString("yyyymmddhhnnss");
    }


}
//---------------------------------------------------------------------------

void __fastcall TForm8::sgPurDetailClick(TObject *Sender)
{
     if(sgPurDetail->Col==2||sgPurDetail->Col==3||sgPurDetail->Col==4||sgPurDetail->Col==5)
     {
          //��ʾ����ѯ����
          Form32->typeindex="8";
          Form32->Show();

     }
}
//---------------------------------------------------------------------------

void __fastcall TForm8::sgPurDetailDrawCell(TObject *Sender, int ACol,
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

void __fastcall TForm8::Button2Click(TObject *Sender)
{
    yk_CurrentCol = 1;
    yk_CurrentRow = 1;

    for(int i=0;i<sgPurDetail->RowCount;i++)
    {
       sgPurDetail->Cells[1][i+1]="";
       sgPurDetail->Cells[2][i+1]="";
       sgPurDetail->Cells[3][i+1]="";
       sgPurDetail->Cells[4][i+1]="";
    }
    
    sgPurDetail->RowCount=2;
    sgPurDetail->Cells[0][1] = 1;
     YK_dh->Clear();
     YK_dh->SetFocus();
     Button1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::YK_dhKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(Key==VK_RETURN)YK_yck->SetFocus();      
}
//---------------------------------------------------------------------------

void __fastcall TForm8::YK_mckKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(Key==VK_RETURN)sgPurDetail->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm8::YK_yckKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(Key==VK_RETURN)YK_mck->SetFocus();      
}
//---------------------------------------------------------------------------
