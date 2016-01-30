//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit1.h"
#include "Unit2.h"
#include "Unit6.h"
#include "Unit32.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;


int ck_CurrentCol;   // �ر����ڵ�ǰ��
int ck_CurrentRow;  // �ر����ڵ�ǰ��
double all=0;  //�ܼ�

//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm5::sgPurDetailKeyPress(TObject *Sender, char &Key)
{
    if(Key ==13)
    {
        // ������һ����Ԫ��
        if(ck_CurrentCol == 1 )
        {


            //�����������������д�ڿ����
            Form1->Search_ADOQuery->Close();
            Form1->Search_ADOQuery->SQL->Clear();
            Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where ���� like \""+sgPurDetail->Cells[1][sgPurDetail->Row].Trim()+"\"");
            Form1->Search_ADOQuery->Active= true;

           // ShowMessage(sgPurDetail->Cells[1][sgPurDetail->Row].Trim());

            sgPurDetail->Cells[2][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim();
            sgPurDetail->Cells[3][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("�ۼ�")->AsString.Trim();
            sgPurDetail->Cells[5][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim();


            if(CheckBox1->Checked==true)
            {
               sgPurDetail->Cells[4][sgPurDetail->Row]="1";
               sgPurDetail->RowCount++;
               sgPurDetail->Cells[0][sgPurDetail->RowCount-1] = sgPurDetail->RowCount-1;
               sgPurDetail->Col = 1;
               sgPurDetail->Row = ck_CurrentRow + 1;
            }
            else
            sgPurDetail->Col = 3;


        }
        else if(ck_CurrentCol == 3)
        {
            sgPurDetail->Col = 4;
        }
        else if(ck_CurrentCol == 4)   // ��һ��
        {
            double CKnum=0;
            double SJ=0;
            try
	    {
                 if(sgPurDetail->Cells[4][sgPurDetail->Row].Trim().Length()!=0)
	           CKnum=sgPurDetail->Cells[4][sgPurDetail->Row].Trim().ToDouble();
                   else CKnum=1;
	    }
            catch(...)
	    {
	         CKnum=1;
            }
	    try
	    {
	        SJ=sgPurDetail->Cells[3][sgPurDetail->Row].Trim().ToDouble();
            }
	    catch(...)
	    {
	      SJ=0;
	    }
            all+=CKnum*SJ;
            sgPurDetail->Cells[6][sgPurDetail->Row]= String(CKnum*SJ);
            this->StatusBar1->Panels->Items[0]->Text="�ܼ�:"+String(all);
            sgPurDetail->RowCount++;
            sgPurDetail->Cells[0][sgPurDetail->RowCount-1] = sgPurDetail->RowCount-1;
            sgPurDetail->Col = 1;
            sgPurDetail->Row = ck_CurrentRow + 1;
        }

        ck_CurrentCol = sgPurDetail->Col;
        ck_CurrentRow = sgPurDetail->Row;
    }
  /*  else if(Key==VK_SPACE)
    {
         if(Application->MessageBoxA("ȷ������֮���޷��޸ģ��Ƿ�����","�½�����",MB_OKCANCEL)==1) {
           if(Button1->Enabled==true)Button1Click(Sender);
         }else return ;
    } */
}
//---------------------------------------------------------------------------
void __fastcall TForm5::sgPurDetailSelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
        if( ACol==2)
            sgPurDetail->Options >> goEditing;
        else
            sgPurDetail->Options << goEditing;

        ck_CurrentCol = ACol;
        ck_CurrentRow = ARow;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormShow(TObject *Sender)
{
//���
    Panel1->Visible=false;
    CK_dj->Text="";
    CK_ck->Text="";

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
    sgPurDetail->ColWidths[4] = 100;
    sgPurDetail->Cells[5][0] = "";
    sgPurDetail->ColWidths[5] =0;
    sgPurDetail->Cells[6][0] = "С��";
    sgPurDetail->ColWidths[6] =100;

    for(int i=0;i<sgPurDetail->RowCount;i++)
    {
       sgPurDetail->Cells[1][i+1]="";
       sgPurDetail->Cells[2][i+1]="";
       sgPurDetail->Cells[3][i+1]="";
       sgPurDetail->Cells[4][i+1]="";
       sgPurDetail->Cells[5][i+1]="";
        sgPurDetail->Cells[6][i+1]="";
    }
    sgPurDetail->RowCount=2;
    sgPurDetail->Cells[0][1] = 1;

    ck_CurrentCol = 1;
    ck_CurrentRow = 1;

    if(CheckBox1->Checked==true)
    {
        if(CK_dj->Text.Trim().Length()==0||CK_ck->Text.Trim().Length()==0)
        {
            if(CK_dj->Text.Trim().Length()==0)CK_dj->Text="DH"+Now().FormatString("yyyymmddhhnnss");
            if(CK_ck->Text.Trim().Length()==0)CK_ck->Text="CK001";
        }
        sgPurDetail->SetFocus();
    }
    all=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Edit2KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key==VK_SPACE||Key==13)
    {
       if(Edit2->Text.Trim().Length()==0)Edit2->Text="0";
       Edit3->Text=String(Edit2->Text.Trim().ToDouble()-Edit1->Text.Trim().ToDouble());
       Edit3->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Edit3KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
       if(Key==VK_SPACE||Key==13)
       {         //ShowMessage("1121") ;
            //ȷ�ϵ���=======================================
            	    if(CK_dj->Text.Trim().Length()==0||CK_ck->Text.Trim().Length()==0)
		    {
		        if(CK_dj->Text.Trim().Length()==0)CK_dj->Text="DH001";
		        if(CK_ck->Text.Trim().Length()==0)CK_ck->Text="CK001";
		        if(mrYes!=MessageDlg("���ⵥ�š��ֿ�ţ�������Ϊ�գ��Ƿ�ȷ�ϳ��⣿",mtInformation,TMsgDlgButtons()<<mbYes<<mbNo,0))
		        {
		            return;
		        }
		    }
		    String barcode="";
		    Double CKnum=0;
		    Double SJ=0;
		    Double JJ=0;
		
		    Double cost=0;//�ܳɱ�
		    Double sales=0;//�����۶�
		    Double profits=0;//������
		
		    for(int i=0;i<sgPurDetail->RowCount;i++)
		    {
		        if(sgPurDetail->Cells[1][i+1].Trim().Length()==0)continue;
	                barcode=sgPurDetail->Cells[1][i+1].Trim();
	                try
	                {
                           if(sgPurDetail->Cells[4][i+1].Trim().Length()!=0)
	                   CKnum=sgPurDetail->Cells[4][i+1].Trim().ToDouble();
                           else CKnum=1;
	                }
	                catch(...)
	                {
	                   CKnum=1;
	                }
	                try
	                {
	                    SJ=sgPurDetail->Cells[3][i+1].Trim().ToDouble();
	                }
	                 catch(...)
	                {
	                    SJ=0;
	                }

	                try
	                {
                            if(sgPurDetail->Cells[5][i+1].Trim().Length()!=0)
	                    JJ=sgPurDetail->Cells[5][i+1].Trim().ToDouble();
                            else
                            {
                                //JJ=1;
	                        //��ѯ����
	                        Form1->Search_ADOQuery->Close();
	                        Form1->Search_ADOQuery->SQL->Clear();
	                        Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where ���� like \""+barcode.Trim()+"\"");
	                        Form1->Search_ADOQuery->Active= true;

	                        sgPurDetail->Cells[5][i+1]=Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim();

	                        if(sgPurDetail->Cells[5][i+1].Trim().Length()==0)
	                        JJ=0;
	                        else
	                        JJ=sgPurDetail->Cells[5][i+1].Trim().ToDouble();
                            }
	                }
	                catch(...)
	                {
	                    //JJ=1;
	                    //��ѯ����
	                    Form1->Search_ADOQuery->Close();
	                    Form1->Search_ADOQuery->SQL->Clear();
	                    Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where ���� like \""+barcode.Trim()+"\"");
	                    Form1->Search_ADOQuery->Active= true;

	                    sgPurDetail->Cells[5][i+1]=Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim();

	                    if(sgPurDetail->Cells[5][i+1].Trim().Length()==0)
	                    JJ=0;
	                    else
	                   JJ=sgPurDetail->Cells[5][i+1].Trim().ToDouble();

	               }


		      //  profits=(SJ-JJ)*CKnum;


		        String str="";
		        Form1->Search_ADOQuery->Close();
		        Form1->Search_ADOQuery->SQL->Clear();
		        str=String().sprintf("SELECT * FROM ���� WHERE ���� like \"%s\" AND ���ⵥ�� like \"%s\" AND ����ֿ� like \"%s\"",barcode.Trim(),CK_dj->Text.Trim(),CK_ck->Text.Trim());
		        Form1->Search_ADOQuery->SQL->Add(str);
		        Form1->Search_ADOQuery->Active= true;
		
		        if(Form1->Search_ADOQuery->RecordCount==0)
		        {
		            cost=cost+JJ*CKnum;
		            sales=sales+SJ*CKnum;
		            profits=sales-cost;
		
		            Form1->CK_ADOTable->Insert();
		            Form1->CK_ADOTable->FieldByName("����")->AsString = barcode.Trim();
		            Form1->CK_ADOTable->FieldByName("��������")->AsFloat = CKnum;
		            Form1->CK_ADOTable->FieldByName("����ʱ��")->AsString=Now().FormatString("yyyy-mm-dd");
		            Form1->CK_ADOTable->FieldByName("����ֿ�")->AsString = CK_ck->Text.Trim();
		            Form1->CK_ADOTable->FieldByName("���ⵥ��")->AsString = CK_dj->Text.Trim();
		            Form1->CK_ADOTable->FieldByName("Ա�����")->AsString = Form1->LoginName.Trim();
		            Form1->CK_ADOTable->FieldByName("�ۼ�")->AsFloat = SJ;
		            Form1->CK_ADOTable->Post();
		        }
		        else
		        {
		            if(SJ==Form1->Search_ADOQuery->FieldByName("�ۼ�")->AsFloat)
		            {
		                cost=cost+JJ*CKnum;
		                sales=sales+SJ*CKnum;
		                profits=sales-cost;
		
		            }
		            else
		            {
		
		                //���۶��������Ҫ�޸�
		                sales=sales+SJ*CKnum+(SJ-Form1->Search_ADOQuery->FieldByName("�ۼ�")->AsFloat)*Form1->Search_ADOQuery->FieldByName("��������")->AsFloat;
		                cost=cost+JJ*CKnum;
		                profits=sales-cost;
		            }
		            str="";
		            str=String().sprintf("UPDATE CK SET  �������� = %f , �ۼ� = %f , ����ʱ�� =  \"%s\" , Ա����� =  \"%s\"  WHERE ���� like \"%s\" AND ����ֿ� like \"%s\" AND ���ⵥ�� like \"%s\""
		                                 ,CKnum+Form1->Search_ADOQuery->FieldByName("��������")->AsFloat
		                                 ,SJ
		                                 ,Now().FormatString("yyyy-mm-dd")
		                                 ,Form1->LoginName.Trim()
		                                 ,barcode.Trim()
		                                 ,CK_ck->Text.Trim()
		                                 ,CK_dj->Text.Trim());
		                            Form1->ADOCommand1->CommandText = str;
		                            Form1->ADOCommand1->Execute();
		
		        }
		
		        str="";
		        Form1->KC_ADOQuery->Close();
		        Form1->KC_ADOQuery->SQL->Clear();
		        str=String().sprintf("SELECT * FROM ��� WHERE ���� like \"%s\" AND �ֿ� like \"%s\"",barcode.Trim(),CK_ck->Text.Trim());
		        Form1->KC_ADOQuery->SQL->Add(str);
		        Form1->KC_ADOQuery->Active= true;
		
		        if(Form1->KC_ADOQuery->RecordCount==0)
		        {
		            Form1->KC_ADOTable->Insert();
		            Form1->KC_ADOTable->FieldByName("����")->AsString = barcode.Trim();
		            Form1->KC_ADOTable->FieldByName("��������")->AsFloat = CKnum;
		            Form1->KC_ADOTable->FieldByName("�ֿ�")->AsString = CK_ck->Text.Trim();
		            Form1->KC_ADOTable->FieldByName("���")->AsFloat = 0 - CKnum;
		            Form1->KC_ADOTable->Post();
		         }
		         else
		         {
		            str="";
		            str=String().sprintf("UPDATE KC SET  �������� = %f, ��� =%f  WHERE ���� like \"%s\" AND �ֿ� like \"%s\""
		                                 ,CKnum+Form1->KC_ADOQuery->FieldByName("��������")->AsFloat
		                                 ,Form1->KC_ADOQuery->FieldByName("���")->AsFloat-CKnum
		                                 ,barcode.Trim()
		                                 ,CK_ck->Text.Trim());
		            Form1->ADOCommand1->CommandText = str;
		            Form1->ADOCommand1->Execute();
		         }
		    }
		
		    //�޸�����ͳ�Ʊ�
		    String str="";
		    Form1->XSTJ_ADOQuery->Close();
		    Form1->XSTJ_ADOQuery->SQL->Clear();
		    str=String().sprintf("SELECT * FROM ����ͳ�� WHERE ���ⵥ�� like \"%s\"",CK_dj->Text.Trim());
		    Form1->XSTJ_ADOQuery->SQL->Add(str);
		    Form1->XSTJ_ADOQuery->Active= true;
		
		    if(Form1->XSTJ_ADOQuery->RecordCount==0)
		    {
		            Form1->XSTJ_ADOTable->Insert();
		            Form1->XSTJ_ADOTable->FieldByName("���ⵥ��")->AsString = CK_dj->Text.Trim();
		            Form1->XSTJ_ADOTable->FieldByName("�ɱ�")->AsFloat = cost;
		            Form1->XSTJ_ADOTable->FieldByName("���۶�")->AsFloat = sales;
		            Form1->XSTJ_ADOTable->FieldByName("����")->AsFloat = profits;
		            Form1->XSTJ_ADOTable->FieldByName("Ա�����")->AsString = Form1->LoginName.Trim();
		            Form1->XSTJ_ADOTable->FieldByName("ʱ��")->AsString = Now().FormatString("yyyy-mm-dd");
		
		            Form1->XSTJ_ADOTable->Post();
		     }
		     else
		     {
		
		            str="";
		            str=String().sprintf("UPDATE XSTJ SET  �ɱ� = %f, ���۶� =%f , ���� =%f , ʱ�� =  \"%s\" WHERE ���ⵥ�� like \"%s\""
		                                 ,cost+Form1->XSTJ_ADOQuery->FieldByName("�ɱ�")->AsFloat
		                                 ,sales+Form1->XSTJ_ADOQuery->FieldByName("���۶�")->AsFloat
		                                 ,profits+Form1->XSTJ_ADOQuery->FieldByName("����")->AsFloat
		                                 ,Now().FormatString("yyyy-mm-dd")
		                                 ,CK_dj->Text.Trim());
		            Form1->ADOCommand1->CommandText = str;
		            Form1->ADOCommand1->Execute();
		     }
		
		    /*Form1->KC_ADOQuery->Close();
		    Form1->KC_ADOQuery->SQL->Clear();
		    Form1->KC_ADOQuery->SQL->Add("SELECT * FROM ���");
		    Form1->KC_ADOQuery->Active= true;
		
		    Form1->XSTJ_ADOQuery->Close();
		    Form1->XSTJ_ADOQuery->SQL->Clear();
		    Form1->XSTJ_ADOQuery->SQL->Add("SELECT * FROM ����ͳ��");
		    Form1->XSTJ_ADOQuery->Active= true; */


            //��ӡСƱ=================================================================================================================
                    /*if(RadioButton1->Checked==true)
		    {
		        Form1->CK_ADOQuery->Close();
		        Form1->CK_ADOQuery->SQL->Clear();
		        Form1->CK_ADOQuery->SQL->Add("SELECT * FROM ����");
		        Form1->CK_ADOQuery->Active= true;
		    }
		    else */
                    if(RadioButton2->Checked==true) //��ӡСƱ
		    {
		        Form6->CheckCKbar->Checked=false;
		        Form6->CheckCKck->Checked=false;
		        Form6->CheckCKbh->Checked=false;
		        Form6->CheckCKnm->Checked=false;
		        Form6->CheckCKdate->Checked=false;
		
		        Form6->CheckCKdj->Checked=true;
		        Form6->Check_CK_dj->Text=CK_dj->Text.Trim();
		
		        Form6->BitBtn4Click(Sender);
		    }
		    else if(RadioButton3->Checked==true)
		    {
		        Form6->CheckCKbar->Checked=false;
		        Form6->CheckCKck->Checked=false;
		        Form6->CheckCKbh->Checked=false;
		        Form6->CheckCKnm->Checked=false;
		        Form6->CheckCKdate->Checked=false;
		
		        Form6->CheckCKdj->Checked=true;
		        Form6->Check_CK_dj->Text=CK_dj->Text.Trim();
		
		        Form6->BitBtn3Click(Sender);
		    }
		    else if(RadioButton4->Checked==true) //��ӡСƱ
		    {
		        Form6->CheckCKbar->Checked=false;
		        Form6->CheckCKck->Checked=false;
		        Form6->CheckCKbh->Checked=false;
		        Form6->CheckCKnm->Checked=false;
		        Form6->CheckCKdate->Checked=false;
		
		        Form6->CheckCKdj->Checked=true;
		        Form6->Check_CK_dj->Text=CK_dj->Text.Trim();
		
		        Form6->BitBtn4Click(Sender);
		        Form6->BitBtn3Click(Sender);
		    }

            /* if(Form2->wComm==INVALID_HANDLE_VALUE||Form2->wComm==NULL)
	     {
	            //��ʾ����û�д�
	            ShowMessage("�������Ӵ�ӡ�����򿪴��ڣ�,��ӡʧ��");
                     for(int i=0;i<sgPurDetail->RowCount;i++)
                     {
                         sgPurDetail->Cells[1][i+1]="";
                         sgPurDetail->Cells[2][i+1]="";
                         sgPurDetail->Cells[3][i+1]="";
                         sgPurDetail->Cells[4][i+1]="";
                         sgPurDetail->Cells[5][i+1]="";
                     }
                     sgPurDetail->RowCount=2;
                     sgPurDetail->Cells[0][1] = 1;

                     ck_CurrentCol = 1;
                     ck_CurrentRow = 1;

                     CK_dj->Text="DH"+Now().FormatString("yyyymmddhhnnss");

                     sgPurDetail->SetFocus();

                     Panel1->Visible=false;
	             return;
	     }

	     unsigned long lrc;

	     float num=0;
	     float count=0;
	     float allcount=0;
	     String printstr="";

	     printstr="";
	     printstr="���ţ�"+CK_dj->Text.Trim()+"\r\n"+"ʱ�䣺"+Now().FormatString("yyyy-mm-dd hh:nn:ss")+"\r\n\r\n--------------------------------";
	     WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL);
	     allcount=0;
	     for(int i=0;i<sgPurDetail->RowCount;i++)
	     {
                    if(sgPurDetail->Cells[1][i+1].Trim().Length()==0)continue;
	            num=sgPurDetail->Cells[4][i+1].Trim().ToDouble();
	            count=sgPurDetail->Cells[3][i+1].Trim().ToDouble()*sgPurDetail->Cells[4][i+1].Trim().ToDouble();
	            allcount=allcount+count;
	            printstr="";
	            printstr="\r\n"+sgPurDetail->Cells[1][i+1].Trim() + "\r\n"+sgPurDetail->Cells[2][i+1].Trim() + "\r\n"+sgPurDetail->Cells[3][i+1].Trim() + "*"+ String(num) + "                   "+ String(count);

	            WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL);
	       }
	       printstr="";
	       printstr="\r\n--------------------------------Ӧ�տ"+String(allcount);
               printstr="\r\nʵ�տ"+ Edit2->Text.Trim();
               printstr="\r\n��  �㣺"+ Edit3->Text.Trim()+"\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n";

	       WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL); */
            //��ӡСƱ=================================================================================================================

            for(int i=0;i<sgPurDetail->RowCount;i++)
            {
                sgPurDetail->Cells[1][i+1]="";
                sgPurDetail->Cells[2][i+1]="";
                sgPurDetail->Cells[3][i+1]="";
                sgPurDetail->Cells[4][i+1]="";
                sgPurDetail->Cells[5][i+1]="";
            }
            sgPurDetail->RowCount=2;
            sgPurDetail->Cells[0][1] = 1;

            ck_CurrentCol = 1;
            ck_CurrentRow = 1;

            CK_dj->Text="DH"+Now().FormatString("yyyymmddhhnnss");

            sgPurDetail->SetFocus();

            Panel1->Visible=false;
       }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::CheckBox1Click(TObject *Sender)
{
    if(CheckBox1->Checked==true)
    {
        if(CK_dj->Text.Trim().Length()==0||CK_ck->Text.Trim().Length()==0)
        {
            if(CK_dj->Text.Trim().Length()==0)CK_dj->Text="DH"+Now().FormatString("yyyymmddhhnnss");
            if(CK_ck->Text.Trim().Length()==0)CK_ck->Text="CK001";
        }
        sgPurDetail->SetFocus();
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button1Click(TObject *Sender)
{
    if(CK_dj->Text.Trim().Length()==0||CK_ck->Text.Trim().Length()==0)
    {
        if(CK_dj->Text.Trim().Length()==0)CK_dj->Text="DH001";
        if(CK_ck->Text.Trim().Length()==0)CK_ck->Text="CK001";
        if(mrYes!=MessageDlg("���ⵥ�š��ֿ�ţ�������Ϊ�գ��Ƿ�ȷ�ϳ��⣿",mtInformation,TMsgDlgButtons()<<mbYes<<mbNo,0))
        {
            return;
        }
    }

    if(CheckBox1->Checked==false)
    {
	    String barcode="";
	    Double CKnum=0;
	    Double SJ=0;
	    Double JJ=0;
	
	    Double cost=0;//�ܳɱ�
	    Double sales=0;//�����۶�
	    Double profits=0;//������
	
	    for(int i=0;i<sgPurDetail->RowCount;i++)
	    {
	        if(sgPurDetail->Cells[1][i+1].Trim().Length()==0)continue;
	        barcode=sgPurDetail->Cells[1][i+1].Trim();
	        try
	        {
                   if(sgPurDetail->Cells[4][i+1].Trim().Length()!=0)
	           CKnum=sgPurDetail->Cells[4][i+1].Trim().ToDouble();
                   else CKnum=1;
	        }
	        catch(...)
	        {
	           CKnum=1;
	        }
	        try
	        {
	          SJ=sgPurDetail->Cells[3][i+1].Trim().ToDouble();
	        }
	        catch(...)
	        {
	           SJ=0;
	        }
	        try
	        {
                   if(sgPurDetail->Cells[5][i+1].Trim().Length()!=0)
	           JJ=sgPurDetail->Cells[5][i+1].Trim().ToDouble();
                   else
                   {
                        //JJ=1;
	                //��ѯ����
	                 Form1->Search_ADOQuery->Close();
	                 Form1->Search_ADOQuery->SQL->Clear();
	                 Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where ���� like \""+barcode.Trim()+"\"");
	                 Form1->Search_ADOQuery->Active= true;
	                 sgPurDetail->Cells[5][i+1]=Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim();

	                 if(sgPurDetail->Cells[5][i+1].Trim().Length()==0)
	                 JJ=0;
	                 else
	                 JJ=sgPurDetail->Cells[5][i+1].Trim().ToDouble();
                   }
	        }
	        catch(...)
	        {
	           //JJ=1;
	           //��ѯ����
	            Form1->Search_ADOQuery->Close();
	            Form1->Search_ADOQuery->SQL->Clear();
	            Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where ���� like \""+barcode.Trim()+"\"");
	            Form1->Search_ADOQuery->Active= true;

	            sgPurDetail->Cells[5][i+1]=Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim();

	            if(sgPurDetail->Cells[5][i+1].Trim().Length()==0)
	            JJ=0;
	            else
	            JJ=sgPurDetail->Cells[5][i+1].Trim().ToDouble();

	        }

	        String str="";
	        Form1->Search_ADOQuery->Close();
	        Form1->Search_ADOQuery->SQL->Clear();
	        str=String().sprintf("SELECT * FROM ���� WHERE ���� like \"%s\" AND ���ⵥ�� like \"%s\" AND ����ֿ� like \"%s\"",barcode.Trim(),CK_dj->Text.Trim(),CK_ck->Text.Trim());
	        Form1->Search_ADOQuery->SQL->Add(str);
	        Form1->Search_ADOQuery->Active= true;
	
	        if(Form1->Search_ADOQuery->RecordCount==0)
	        {
	            cost=cost+JJ*CKnum;
	            sales=sales+SJ*CKnum;
	            profits=sales-cost;
	
	            Form1->CK_ADOTable->Insert();
	            Form1->CK_ADOTable->FieldByName("����")->AsString = barcode.Trim();
	            Form1->CK_ADOTable->FieldByName("��������")->AsFloat = CKnum;
	            Form1->CK_ADOTable->FieldByName("����ʱ��")->AsString=Now().FormatString("yyyy-mm-dd");
	            Form1->CK_ADOTable->FieldByName("����ֿ�")->AsString = CK_ck->Text.Trim();
	            Form1->CK_ADOTable->FieldByName("���ⵥ��")->AsString = CK_dj->Text.Trim();
	            Form1->CK_ADOTable->FieldByName("Ա�����")->AsString = Form1->LoginName.Trim();
	            Form1->CK_ADOTable->FieldByName("�ۼ�")->AsFloat = SJ;
	            Form1->CK_ADOTable->Post();
	        }
	        else
	        {
	            if(SJ==Form1->Search_ADOQuery->FieldByName("�ۼ�")->AsFloat)
	            {
	                cost=cost+JJ*CKnum;
	                sales=sales+SJ*CKnum;
	                profits=sales-cost;
	
	            }
	            else
	            {
	                //���۶��������Ҫ�޸�
	                sales=sales+SJ*CKnum+(SJ-Form1->Search_ADOQuery->FieldByName("�ۼ�")->AsFloat)*Form1->Search_ADOQuery->FieldByName("��������")->AsFloat;
	                cost=cost+JJ*CKnum;
	                profits=sales-cost;
	            }
	            str="";
	            str=String().sprintf("UPDATE CK SET  �������� = %f , �ۼ� = %f , ����ʱ�� =  \"%s\" , Ա����� =  \"%s\"  WHERE ���� like \"%s\" AND ����ֿ� like \"%s\" AND ���ⵥ�� like \"%s\""
	                                 ,CKnum+Form1->Search_ADOQuery->FieldByName("��������")->AsFloat
	                                 ,SJ
	                                 ,Now().FormatString("yyyy-mm-dd")
	                                 ,Form1->LoginName.Trim()
	                                 ,barcode.Trim()
	                                 ,CK_ck->Text.Trim()
	                                 ,CK_dj->Text.Trim());
	                            Form1->ADOCommand1->CommandText = str;
	                            Form1->ADOCommand1->Execute();
	        }
	
	        str="";
	        Form1->KC_ADOQuery->Close();
	        Form1->KC_ADOQuery->SQL->Clear();
	        str=String().sprintf("SELECT * FROM ��� WHERE ���� like \"%s\" AND �ֿ� like \"%s\"",barcode.Trim(),CK_ck->Text.Trim());
	        Form1->KC_ADOQuery->SQL->Add(str);
	        Form1->KC_ADOQuery->Active= true;
	
	        if(Form1->KC_ADOQuery->RecordCount==0)
	        {
	            Form1->KC_ADOTable->Insert();
	            Form1->KC_ADOTable->FieldByName("����")->AsString = barcode.Trim();
	            Form1->KC_ADOTable->FieldByName("��������")->AsFloat = CKnum;
	            Form1->KC_ADOTable->FieldByName("�ֿ�")->AsString = CK_ck->Text.Trim();
	            Form1->KC_ADOTable->FieldByName("���")->AsFloat = 0 - CKnum;
	            Form1->KC_ADOTable->Post();
	         }
	         else
	         {
	            str="";
	            str=String().sprintf("UPDATE KC SET  �������� = %f, ��� =%f  WHERE ���� like \"%s\" AND �ֿ� like \"%s\""
	                                 ,CKnum+Form1->KC_ADOQuery->FieldByName("��������")->AsFloat
	                                 ,Form1->KC_ADOQuery->FieldByName("���")->AsFloat-CKnum
	                                 ,barcode.Trim()
	                                 ,CK_ck->Text.Trim());
	            Form1->ADOCommand1->CommandText = str;
	            Form1->ADOCommand1->Execute();
	         }
	    }
	
	    //�޸�����ͳ�Ʊ�
	    String str="";
	    Form1->XSTJ_ADOQuery->Close();
	    Form1->XSTJ_ADOQuery->SQL->Clear();
	    str=String().sprintf("SELECT * FROM ����ͳ�� WHERE ���ⵥ�� like \"%s\"",CK_dj->Text.Trim());
	    Form1->XSTJ_ADOQuery->SQL->Add(str);
	    Form1->XSTJ_ADOQuery->Active= true;
	
	    if(Form1->XSTJ_ADOQuery->RecordCount==0)
	    {
	            Form1->XSTJ_ADOTable->Insert();
	            Form1->XSTJ_ADOTable->FieldByName("���ⵥ��")->AsString = CK_dj->Text.Trim();
	            Form1->XSTJ_ADOTable->FieldByName("�ɱ�")->AsFloat = cost;
	            Form1->XSTJ_ADOTable->FieldByName("���۶�")->AsFloat = sales;
	            Form1->XSTJ_ADOTable->FieldByName("����")->AsFloat = profits;
	            Form1->XSTJ_ADOTable->FieldByName("Ա�����")->AsString = Form1->LoginName.Trim();
	            Form1->XSTJ_ADOTable->FieldByName("ʱ��")->AsString = Now().FormatString("yyyy-mm-dd");
	            Form1->XSTJ_ADOTable->Post();
	     }
	     else
	     {
	
	            str="";
	            str=String().sprintf("UPDATE XSTJ SET  �ɱ� = %f, ���۶� =%f , ���� =%f , ʱ�� =  \"%s\" WHERE ���ⵥ�� like \"%s\""
	                                 ,cost+Form1->XSTJ_ADOQuery->FieldByName("�ɱ�")->AsFloat
	                                 ,sales+Form1->XSTJ_ADOQuery->FieldByName("���۶�")->AsFloat
	                                 ,profits+Form1->XSTJ_ADOQuery->FieldByName("����")->AsFloat
	                                 ,Now().FormatString("yyyy-mm-dd")
	                                 ,CK_dj->Text.Trim());
	            Form1->ADOCommand1->CommandText = str;
	            Form1->ADOCommand1->Execute();
	     }
	    Form1->KC_ADOQuery->Close();
	    Form1->KC_ADOQuery->SQL->Clear();
	    Form1->KC_ADOQuery->SQL->Add("SELECT * FROM ���");
	    Form1->KC_ADOQuery->Active= true;
	
	    Form1->XSTJ_ADOQuery->Close();
	    Form1->XSTJ_ADOQuery->SQL->Clear();
	    Form1->XSTJ_ADOQuery->SQL->Add("SELECT * FROM ����ͳ��");
	    Form1->XSTJ_ADOQuery->Active= true;
	
	
	
	    if(RadioButton1->Checked==true)
	    {
	        Form1->CK_ADOQuery->Close();
	        Form1->CK_ADOQuery->SQL->Clear();
	        Form1->CK_ADOQuery->SQL->Add("SELECT * FROM ����");
	        Form1->CK_ADOQuery->Active= true;
	        ShowMessage("���ݽ����ɹ���");
	    }
	    else if(RadioButton2->Checked==true) //��ӡСƱ
	    {
	        Form6->CheckCKbar->Checked=false;
	        Form6->CheckCKck->Checked=false;
	        Form6->CheckCKbh->Checked=false;
	        Form6->CheckCKnm->Checked=false;
	        Form6->CheckCKdate->Checked=false;
	
	        Form6->CheckCKdj->Checked=true;
	        Form6->Check_CK_dj->Text=CK_dj->Text.Trim();
	
	        Form6->BitBtn4Click(Sender);
	    }
	    else if(RadioButton3->Checked==true)
	    {
	        Form6->CheckCKbar->Checked=false;
	        Form6->CheckCKck->Checked=false;
	        Form6->CheckCKbh->Checked=false;
	        Form6->CheckCKnm->Checked=false;
	        Form6->CheckCKdate->Checked=false;
	
	        Form6->CheckCKdj->Checked=true;
	        Form6->Check_CK_dj->Text=CK_dj->Text.Trim();
	
	        Form6->BitBtn3Click(Sender);
	    }
	    else if(RadioButton4->Checked==true) //��ӡСƱ
	    {
	        Form6->CheckCKbar->Checked=false;
	        Form6->CheckCKck->Checked=false;
	        Form6->CheckCKbh->Checked=false;
	        Form6->CheckCKnm->Checked=false;
	        Form6->CheckCKdate->Checked=false;
	
	        Form6->CheckCKdj->Checked=true;
	        Form6->Check_CK_dj->Text=CK_dj->Text.Trim();
	
	        Form6->BitBtn4Click(Sender);
	        Form6->BitBtn3Click(Sender);
	    }
            if(CheckBox1->Checked==false)Button1->Enabled=false;
    }
    else
    {
         // ShowMessage("1111") ;
            String barcode="";
	    Double CKnum=0;
	    Double SJ=0;
	    Double JJ=0;

	    Double cost=0;//�ܳɱ�
	    Double sales=0;//�����۶�

	    for(int i=0;i<sgPurDetail->RowCount;i++)
	    {
	        if(sgPurDetail->Cells[1][i+1].Trim().Length()==0)continue;
	        barcode=sgPurDetail->Cells[1][i+1].Trim();
	        try
	        {
                   if(sgPurDetail->Cells[4][i+1].Trim().Length()!=0)
	           CKnum=sgPurDetail->Cells[4][i+1].Trim().ToDouble();
                   else CKnum=1;
	        }
	        catch(...)
	        {
	           CKnum=1;
	        }
	        try
	        {
	             SJ=sgPurDetail->Cells[3][i+1].Trim().ToDouble();
	        }
	        catch(...)
	        {
	             SJ=0;
	        }

	        try
	        {
                   if(sgPurDetail->Cells[5][i+1].Trim().Length()!=0)
	           JJ=sgPurDetail->Cells[5][i+1].Trim().ToDouble();
                   else
                   {
                        //JJ=1;
	                //��ѯ����
	                 Form1->Search_ADOQuery->Close();
	                 Form1->Search_ADOQuery->SQL->Clear();
	                 Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where ���� like \""+barcode.Trim()+"\"");
	                 Form1->Search_ADOQuery->Active= true;

	                 sgPurDetail->Cells[5][i+1]=Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim();

	                 if(sgPurDetail->Cells[5][i+1].Trim().Length()==0)
	                 JJ=0;
	                 else
	                 JJ=sgPurDetail->Cells[5][i+1].Trim().ToDouble();
                   }
	        }
	        catch(...)
	        {
	           //JJ=1;
	           //��ѯ����
	            Form1->Search_ADOQuery->Close();
	            Form1->Search_ADOQuery->SQL->Clear();
	            Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where ���� like \""+barcode.Trim()+"\"");
	            Form1->Search_ADOQuery->Active= true;

	            sgPurDetail->Cells[5][i+1]=Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim();

	            if(sgPurDetail->Cells[5][i+1].Trim().Length()==0)
	            JJ=0;
	            else
	            JJ=sgPurDetail->Cells[5][i+1].Trim().ToDouble();

	        }


	
	        String str="";
	        Form1->Search_ADOQuery->Close();
	        Form1->Search_ADOQuery->SQL->Clear();
	        str=String().sprintf("SELECT * FROM ���� WHERE ���� like \"%s\" AND ���ⵥ�� like \"%s\" AND ����ֿ� like \"%s\"",barcode.Trim(),CK_dj->Text.Trim(),CK_ck->Text.Trim());
	        Form1->Search_ADOQuery->SQL->Add(str);
	        Form1->Search_ADOQuery->Active= true;
	
	        if(Form1->Search_ADOQuery->RecordCount==0)
	        {
	            cost=cost+JJ*CKnum;
	            sales=sales+SJ*CKnum;
	        }
	        else
	        {
	            if(SJ==Form1->Search_ADOQuery->FieldByName("�ۼ�")->AsFloat)
	            {
	                cost=cost+JJ*CKnum;
	                sales=sales+SJ*CKnum;
	            }
	            else
	            {
	                //���۶��������Ҫ�޸�
	                sales=sales+SJ*CKnum+(SJ-Form1->Search_ADOQuery->FieldByName("�ۼ�")->AsFloat)*Form1->Search_ADOQuery->FieldByName("��������")->AsFloat;
	                cost=cost+JJ*CKnum;
	            }
	
	        }
	    }

            Panel1->Visible=true;
	    //��ʾ��Ӧ�տʵ�տӦ����
	    Edit1->Text=String(sales);
            Edit2->Text="";
	    Edit3->Text="";
		
	    Edit2->SetFocus();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm5::Button2Click(TObject *Sender)
{
      Panel1->Visible=false;
      sgPurDetail->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::sgPurDetailClick(TObject *Sender)
{
     //�����ʱ����в�ѯ

     if(sgPurDetail->Col==2)
     {
          //��ʾ����ѯ����
          Form32->typeindex="5";
          Form32->Show();

     }        
}
//---------------------------------------------------------------------------

void __fastcall TForm5::sgPurDetailDrawCell(TObject *Sender, int ACol,
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

void __fastcall TForm5::Button3Click(TObject *Sender)
{
    all=0;
    for(int i=0;i<sgPurDetail->RowCount;i++)
    {
       sgPurDetail->Cells[1][i+1]="";
       sgPurDetail->Cells[2][i+1]="";
       sgPurDetail->Cells[3][i+1]="";
       sgPurDetail->Cells[4][i+1]="";
       sgPurDetail->Cells[5][i+1]="";
       sgPurDetail->Cells[6][i+1]="";
    }
    sgPurDetail->RowCount=2;
    sgPurDetail->Cells[0][1] = 1;

    ck_CurrentCol = 1;
    ck_CurrentRow = 1;


    Button1->Enabled=true;

    StatusBar1->Panels->Items[0]->Text="";

    CK_dj->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::CK_djKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
     if(Key==VK_RETURN)CK_ck->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::CK_ckKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(Key==VK_RETURN)sgPurDetail->SetFocus();     
}
//---------------------------------------------------------------------------
