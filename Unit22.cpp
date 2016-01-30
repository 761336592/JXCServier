//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit22.h"
#include "Unit1.h"
#include "Unit32.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm22 *Form22;

int pd_CurrentCol;   // �ر����ڵ�ǰ��
int pd_CurrentRow;  // �ر����ڵ�ǰ��


//---------------------------------------------------------------------------
__fastcall TForm22::TForm22(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm22::sgPurDetailKeyPress(TObject *Sender, char &Key)
{
    if(Key ==13)
    {
        // ������һ����Ԫ��
        if(pd_CurrentCol == 1 )
        {
            //�����������������д�ڿ����
            Form1->Search_ADOQuery->Close();
            Form1->Search_ADOQuery->SQL->Clear();
            Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where ���� like \""+sgPurDetail->Cells[1][sgPurDetail->Row].Trim()+"\"");
            Form1->Search_ADOQuery->Active= true;

           // ShowMessage(sgPurDetail->Cells[1][sgPurDetail->Row].Trim());

            sgPurDetail->Cells[2][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim();
            sgPurDetail->Cells[3][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim();

            if(CheckBox1->Checked==true)
            {
               sgPurDetail->Cells[4][sgPurDetail->Row]="1";
               sgPurDetail->RowCount++;
               sgPurDetail->Cells[0][sgPurDetail->RowCount-1] = sgPurDetail->RowCount-1;
               sgPurDetail->Col = 1;
               sgPurDetail->Row = pd_CurrentRow + 1;
            }
            else
            sgPurDetail->Col = 4;
        }
        else if(pd_CurrentCol == 4)   // ��һ��
        {
            sgPurDetail->RowCount++;
            sgPurDetail->Cells[0][sgPurDetail->RowCount-1] = sgPurDetail->RowCount-1;
            sgPurDetail->Col = 1;
            sgPurDetail->Row = pd_CurrentRow + 1;
        }

        pd_CurrentCol = sgPurDetail->Col;
        pd_CurrentRow = sgPurDetail->Row;
    }
   /* else if(Key==VK_SPACE)
    {
         Button1Click(Sender);
    }*/
}
//---------------------------------------------------------------------------

void __fastcall TForm22::FormShow(TObject *Sender)
{
     //���
    Edit1->Text="";

       // ������ϸ�б������
    sgPurDetail->Cells[0][0] = "���";
    sgPurDetail->ColWidths[0] = 32;
    sgPurDetail->Cells[1][0] = Form1->infshow1;
    sgPurDetail->ColWidths[1] = 200;
    sgPurDetail->Cells[2][0] = Form1->infshow2+"        ���������п�ѡ����Ʒ��";
    sgPurDetail->ColWidths[2] = 250;
    sgPurDetail->Cells[3][0] = Form1->infshow3;
    sgPurDetail->ColWidths[3] = 64;
    sgPurDetail->Cells[4][0] = "����";
    sgPurDetail->ColWidths[4] = 100;

    for(int i=0;i<sgPurDetail->RowCount;i++)
    {
       sgPurDetail->Cells[1][i+1]="";
       sgPurDetail->Cells[2][i+1]="";
       sgPurDetail->Cells[3][i+1]="";
       sgPurDetail->Cells[4][i+1]="";
    }

    sgPurDetail->RowCount=2;
    sgPurDetail->Cells[0][1] = 1;

    pd_CurrentCol = 1;
    pd_CurrentRow = 1;

    if(CheckBox1->Checked==true)
    {
        if(Edit1->Text.Trim().Length()==0)
        {
            if(Edit1->Text.Trim().Length()==0)Edit1->Text="CK001";
        }
        sgPurDetail->SetFocus();
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm22::sgPurDetailSelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
       if( ACol==2|| ACol==3)
            sgPurDetail->Options >> goEditing;
        else
            sgPurDetail->Options << goEditing;

        pd_CurrentCol = ACol;
        pd_CurrentRow = ARow;
}
//---------------------------------------------------------------------------

void __fastcall TForm22::CheckBox1Click(TObject *Sender)
{
    if(CheckBox1->Checked==true)
    {
        if(Edit1->Text.Trim().Length()==0)
        {
            if(Edit1->Text.Trim().Length()==0)Edit1->Text="CK001";
        }
        sgPurDetail->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm22::Button1Click(TObject *Sender)
{

    if(Edit1->Text.Trim().Length()==0||Edit2->Text.Trim().Length()==0)
    {
        if(Edit2->Text.Trim().Length()==0)Edit2->Text="DH001";
        if(Edit1->Text.Trim().Length()==0)Edit1->Text="CK001";
        if(mrYes!=MessageDlg("���š��ֿ�Ų���Ϊ�գ��Ƿ�ȷ���̵㣿",mtInformation,TMsgDlgButtons()<<mbYes<<mbNo,0))
        {
            return;
        }
    }

    String barcode="";
    float RKnum=0;

    for(int i=0;i<sgPurDetail->RowCount;i++)
    {
        if(sgPurDetail->Cells[1][i+1].Trim().Length()==0)continue;
        barcode=sgPurDetail->Cells[1][i+1].Trim();

        try
        {
           RKnum=sgPurDetail->Cells[4][i+1].Trim().ToDouble();
        }
        catch(...)
        {
           RKnum=1;
        }

        //�޸��̵�ͳ�Ʊ�================================================================================================
        String str="";
        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM �̵�ͳ�� WHERE ���� like \"%s\" AND �ֿ� like \"%s\"",barcode.Trim(),Edit1->Text.Trim());
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;

        if(Form1->Search_ADOQuery->RecordCount==0)
        {
            Form1->PDTJ_ADOTable->Insert();
            Form1->PDTJ_ADOTable->FieldByName("����")->AsString = barcode.Trim();
            Form1->PDTJ_ADOTable->FieldByName("�̵���")->AsFloat = RKnum;
            Form1->PDTJ_ADOTable->FieldByName("�ֿ�")->AsString = Edit1->Text.Trim();
            Form1->PDTJ_ADOTable->Post();
        }
        else
        {
            str="";
            str=String().sprintf("UPDATE PDTJ SET  �̵��� = %f WHERE ���� like \"%s\" AND �ֿ� like \"%s\""
                                   ,RKnum+Form1->Search_ADOQuery->FieldByName("�̵���")->AsFloat
                                   ,barcode.Trim()
                                   ,Edit1->Text.Trim());
            Form1->ADOCommand1->CommandText = str;
            Form1->ADOCommand1->Execute();
        }

        //�޸��̵���ϸ��==================================================================================================
        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM �̵� WHERE ���� like \"%s\" AND �ֿ� like \"%s\" AND ���� like \"%s\"",barcode.Trim(),Edit1->Text.Trim(),Edit2->Text.Trim());
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;

        if(Form1->Search_ADOQuery->RecordCount==0)
        {
            Form1->PD_ADOTable->Insert();
            Form1->PD_ADOTable->FieldByName("����")->AsString = barcode.Trim();
            Form1->PD_ADOTable->FieldByName("�̵���")->AsFloat = RKnum;
            Form1->PD_ADOTable->FieldByName("�ֿ�")->AsString = Edit1->Text.Trim();
            Form1->PD_ADOTable->FieldByName("����")->AsString = Edit2->Text.Trim();
            Form1->PD_ADOTable->FieldByName("�̵�ʱ��")->AsString = Now().FormatString("yyyy-mm-dd");
            Form1->PD_ADOTable->FieldByName("Ա�����")->AsString = Form1->LoginName.Trim();
            Form1->PD_ADOTable->Post();
        }
        else
        {
            str="";
            str=String().sprintf("UPDATE PD SET  �̵��� = %f , �̵�ʱ�� =\"%s\" , Ա����� = \"%s\" WHERE ���� like \"%s\" AND �ֿ� like \"%s\" AND ���� like \"%s\""
                                   ,RKnum+Form1->Search_ADOQuery->FieldByName("�̵���")->AsFloat
                                   ,Now().FormatString("yyyy-mm-dd")
                                   ,Form1->LoginName.Trim()
                                   ,barcode.Trim()
                                   ,Edit1->Text.Trim()
                                   ,Edit2->Text.Trim());
            Form1->ADOCommand1->CommandText = str;
            Form1->ADOCommand1->Execute();
        }

    }

    Form1->PD_ADOQuery->Close();
    Form1->PD_ADOQuery->SQL->Clear();
    Form1->PD_ADOQuery->SQL->Add("SELECT * FROM �̵�");
    Form1->PD_ADOQuery->Active= true;

    Form1->PDTJ_ADOQuery->Close();
    Form1->PDTJ_ADOQuery->SQL->Clear();
    Form1->PDTJ_ADOQuery->SQL->Add("SELECT * FROM �̵�ͳ��");
    Form1->PDTJ_ADOQuery->Active= true;
    
    if(CheckBox1->Checked==false)Button1->Enabled=false;
    else
    {
        Button2Click(Sender);
        Edit2->Text="DH"+Now().FormatString("yyyymmddhhnnss");
    }

    ShowMessage("�̵�ɹ���");
}
//---------------------------------------------------------------------------

void __fastcall TForm22::sgPurDetailClick(TObject *Sender)
{
//�����ʱ����в�ѯ

     if(sgPurDetail->Col==2||sgPurDetail->Col==3)
     {
          //��ʾ����ѯ����
          Form32->typeindex="22";
          Form32->Show();

     }
}
//---------------------------------------------------------------------------

void __fastcall TForm22::sgPurDetailDrawCell(TObject *Sender, int ACol,
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

void __fastcall TForm22::Button2Click(TObject *Sender)
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
    Edit2->Clear();
    Edit2->SetFocus();
    pd_CurrentCol = 1;
    pd_CurrentRow = 1;

    Button1->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TForm22::Edit2KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(Key==VK_RETURN)Edit1->SetFocus();      
}
//---------------------------------------------------------------------------

void __fastcall TForm22::Edit1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(Key==VK_RETURN)sgPurDetail->SetFocus();       
}
//---------------------------------------------------------------------------

