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


int ck_CurrentCol;   // 关标所在当前列
int ck_CurrentRow;  // 关标所在当前行
double all=0;  //总计

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
        // 跳到下一个单元格
        if(ck_CurrentCol == 1 )
        {


            //搜索出此条码的资料写在框里边
            Form1->Search_ADOQuery->Close();
            Form1->Search_ADOQuery->SQL->Clear();
            Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where 条码 like \""+sgPurDetail->Cells[1][sgPurDetail->Row].Trim()+"\"");
            Form1->Search_ADOQuery->Active= true;

           // ShowMessage(sgPurDetail->Cells[1][sgPurDetail->Row].Trim());

            sgPurDetail->Cells[2][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("名称")->AsString.Trim();
            sgPurDetail->Cells[3][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("售价")->AsString.Trim();
            sgPurDetail->Cells[5][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("进价")->AsString.Trim();


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
        else if(ck_CurrentCol == 4)   // 下一行
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
            this->StatusBar1->Panels->Items[0]->Text="总计:"+String(all);
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
         if(Application->MessageBoxA("确定单据之后将无法修改，是否建立？","新建单据",MB_OKCANCEL)==1) {
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
//清空
    Panel1->Visible=false;
    CK_dj->Text="";
    CK_ck->Text="";

       // 设置明细列表的内容
    sgPurDetail->Cells[0][0] = "序号";
    sgPurDetail->ColWidths[0] = 32;
    sgPurDetail->Cells[1][0] = Form1->infshow1;
    sgPurDetail->ColWidths[1] = 200;
    sgPurDetail->Cells[2][0] = Form1->infshow2+"        （单击此列可选择商品）";
    sgPurDetail->ColWidths[2] = 250;
    sgPurDetail->Cells[3][0] = Form1->infshow7;
    sgPurDetail->ColWidths[3] = 64;
    sgPurDetail->Cells[4][0] = "数量";
    sgPurDetail->ColWidths[4] = 100;
    sgPurDetail->Cells[5][0] = "";
    sgPurDetail->ColWidths[5] =0;
    sgPurDetail->Cells[6][0] = "小计";
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
            //确认单据=======================================
            	    if(CK_dj->Text.Trim().Length()==0||CK_ck->Text.Trim().Length()==0)
		    {
		        if(CK_dj->Text.Trim().Length()==0)CK_dj->Text="DH001";
		        if(CK_ck->Text.Trim().Length()==0)CK_ck->Text="CK001";
		        if(mrYes!=MessageDlg("出库单号、仓库号，都不能为空，是否确认出库？",mtInformation,TMsgDlgButtons()<<mbYes<<mbNo,0))
		        {
		            return;
		        }
		    }
		    String barcode="";
		    Double CKnum=0;
		    Double SJ=0;
		    Double JJ=0;
		
		    Double cost=0;//总成本
		    Double sales=0;//总销售额
		    Double profits=0;//总利润
		
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
	                        //查询进价
	                        Form1->Search_ADOQuery->Close();
	                        Form1->Search_ADOQuery->SQL->Clear();
	                        Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where 条码 like \""+barcode.Trim()+"\"");
	                        Form1->Search_ADOQuery->Active= true;

	                        sgPurDetail->Cells[5][i+1]=Form1->Search_ADOQuery->FieldByName("进价")->AsString.Trim();

	                        if(sgPurDetail->Cells[5][i+1].Trim().Length()==0)
	                        JJ=0;
	                        else
	                        JJ=sgPurDetail->Cells[5][i+1].Trim().ToDouble();
                            }
	                }
	                catch(...)
	                {
	                    //JJ=1;
	                    //查询进价
	                    Form1->Search_ADOQuery->Close();
	                    Form1->Search_ADOQuery->SQL->Clear();
	                    Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where 条码 like \""+barcode.Trim()+"\"");
	                    Form1->Search_ADOQuery->Active= true;

	                    sgPurDetail->Cells[5][i+1]=Form1->Search_ADOQuery->FieldByName("进价")->AsString.Trim();

	                    if(sgPurDetail->Cells[5][i+1].Trim().Length()==0)
	                    JJ=0;
	                    else
	                   JJ=sgPurDetail->Cells[5][i+1].Trim().ToDouble();

	               }


		      //  profits=(SJ-JJ)*CKnum;


		        String str="";
		        Form1->Search_ADOQuery->Close();
		        Form1->Search_ADOQuery->SQL->Clear();
		        str=String().sprintf("SELECT * FROM 出库 WHERE 条码 like \"%s\" AND 出库单据 like \"%s\" AND 出库仓库 like \"%s\"",barcode.Trim(),CK_dj->Text.Trim(),CK_ck->Text.Trim());
		        Form1->Search_ADOQuery->SQL->Add(str);
		        Form1->Search_ADOQuery->Active= true;
		
		        if(Form1->Search_ADOQuery->RecordCount==0)
		        {
		            cost=cost+JJ*CKnum;
		            sales=sales+SJ*CKnum;
		            profits=sales-cost;
		
		            Form1->CK_ADOTable->Insert();
		            Form1->CK_ADOTable->FieldByName("条码")->AsString = barcode.Trim();
		            Form1->CK_ADOTable->FieldByName("出库数量")->AsFloat = CKnum;
		            Form1->CK_ADOTable->FieldByName("出库时间")->AsString=Now().FormatString("yyyy-mm-dd");
		            Form1->CK_ADOTable->FieldByName("出库仓库")->AsString = CK_ck->Text.Trim();
		            Form1->CK_ADOTable->FieldByName("出库单据")->AsString = CK_dj->Text.Trim();
		            Form1->CK_ADOTable->FieldByName("员工编号")->AsString = Form1->LoginName.Trim();
		            Form1->CK_ADOTable->FieldByName("售价")->AsFloat = SJ;
		            Form1->CK_ADOTable->Post();
		        }
		        else
		        {
		            if(SJ==Form1->Search_ADOQuery->FieldByName("售价")->AsFloat)
		            {
		                cost=cost+JJ*CKnum;
		                sales=sales+SJ*CKnum;
		                profits=sales-cost;
		
		            }
		            else
		            {
		
		                //销售额和利润需要修改
		                sales=sales+SJ*CKnum+(SJ-Form1->Search_ADOQuery->FieldByName("售价")->AsFloat)*Form1->Search_ADOQuery->FieldByName("出库数量")->AsFloat;
		                cost=cost+JJ*CKnum;
		                profits=sales-cost;
		            }
		            str="";
		            str=String().sprintf("UPDATE CK SET  出库数量 = %f , 售价 = %f , 出库时间 =  \"%s\" , 员工编号 =  \"%s\"  WHERE 条码 like \"%s\" AND 出库仓库 like \"%s\" AND 出库单据 like \"%s\""
		                                 ,CKnum+Form1->Search_ADOQuery->FieldByName("出库数量")->AsFloat
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
		        str=String().sprintf("SELECT * FROM 库存 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",barcode.Trim(),CK_ck->Text.Trim());
		        Form1->KC_ADOQuery->SQL->Add(str);
		        Form1->KC_ADOQuery->Active= true;
		
		        if(Form1->KC_ADOQuery->RecordCount==0)
		        {
		            Form1->KC_ADOTable->Insert();
		            Form1->KC_ADOTable->FieldByName("条码")->AsString = barcode.Trim();
		            Form1->KC_ADOTable->FieldByName("出库数量")->AsFloat = CKnum;
		            Form1->KC_ADOTable->FieldByName("仓库")->AsString = CK_ck->Text.Trim();
		            Form1->KC_ADOTable->FieldByName("库存")->AsFloat = 0 - CKnum;
		            Form1->KC_ADOTable->Post();
		         }
		         else
		         {
		            str="";
		            str=String().sprintf("UPDATE KC SET  出库数量 = %f, 库存 =%f  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
		                                 ,CKnum+Form1->KC_ADOQuery->FieldByName("出库数量")->AsFloat
		                                 ,Form1->KC_ADOQuery->FieldByName("库存")->AsFloat-CKnum
		                                 ,barcode.Trim()
		                                 ,CK_ck->Text.Trim());
		            Form1->ADOCommand1->CommandText = str;
		            Form1->ADOCommand1->Execute();
		         }
		    }
		
		    //修改销售统计表
		    String str="";
		    Form1->XSTJ_ADOQuery->Close();
		    Form1->XSTJ_ADOQuery->SQL->Clear();
		    str=String().sprintf("SELECT * FROM 销售统计 WHERE 出库单据 like \"%s\"",CK_dj->Text.Trim());
		    Form1->XSTJ_ADOQuery->SQL->Add(str);
		    Form1->XSTJ_ADOQuery->Active= true;
		
		    if(Form1->XSTJ_ADOQuery->RecordCount==0)
		    {
		            Form1->XSTJ_ADOTable->Insert();
		            Form1->XSTJ_ADOTable->FieldByName("出库单据")->AsString = CK_dj->Text.Trim();
		            Form1->XSTJ_ADOTable->FieldByName("成本")->AsFloat = cost;
		            Form1->XSTJ_ADOTable->FieldByName("销售额")->AsFloat = sales;
		            Form1->XSTJ_ADOTable->FieldByName("利润")->AsFloat = profits;
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
		                                 ,CK_dj->Text.Trim());
		            Form1->ADOCommand1->CommandText = str;
		            Form1->ADOCommand1->Execute();
		     }
		
		    /*Form1->KC_ADOQuery->Close();
		    Form1->KC_ADOQuery->SQL->Clear();
		    Form1->KC_ADOQuery->SQL->Add("SELECT * FROM 库存");
		    Form1->KC_ADOQuery->Active= true;
		
		    Form1->XSTJ_ADOQuery->Close();
		    Form1->XSTJ_ADOQuery->SQL->Clear();
		    Form1->XSTJ_ADOQuery->SQL->Add("SELECT * FROM 销售统计");
		    Form1->XSTJ_ADOQuery->Active= true; */


            //打印小票=================================================================================================================
                    /*if(RadioButton1->Checked==true)
		    {
		        Form1->CK_ADOQuery->Close();
		        Form1->CK_ADOQuery->SQL->Clear();
		        Form1->CK_ADOQuery->SQL->Add("SELECT * FROM 出库");
		        Form1->CK_ADOQuery->Active= true;
		    }
		    else */
                    if(RadioButton2->Checked==true) //打印小票
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
		    else if(RadioButton4->Checked==true) //打印小票
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
	            //提示串口没有打开
	            ShowMessage("请先连接打印机（打开串口）,打印失败");
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
	     printstr="单号："+CK_dj->Text.Trim()+"\r\n"+"时间："+Now().FormatString("yyyy-mm-dd hh:nn:ss")+"\r\n\r\n--------------------------------";
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
	       printstr="\r\n--------------------------------应收款："+String(allcount);
               printstr="\r\n实收款："+ Edit2->Text.Trim();
               printstr="\r\n找  零："+ Edit3->Text.Trim()+"\r\n\r\n\r\n\r\n\r\n\r\n\r\n\r\n";

	       WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL); */
            //打印小票=================================================================================================================

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
        if(mrYes!=MessageDlg("出库单号、仓库号，都不能为空，是否确认出库？",mtInformation,TMsgDlgButtons()<<mbYes<<mbNo,0))
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
	
	    Double cost=0;//总成本
	    Double sales=0;//总销售额
	    Double profits=0;//总利润
	
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
	                //查询进价
	                 Form1->Search_ADOQuery->Close();
	                 Form1->Search_ADOQuery->SQL->Clear();
	                 Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where 条码 like \""+barcode.Trim()+"\"");
	                 Form1->Search_ADOQuery->Active= true;
	                 sgPurDetail->Cells[5][i+1]=Form1->Search_ADOQuery->FieldByName("进价")->AsString.Trim();

	                 if(sgPurDetail->Cells[5][i+1].Trim().Length()==0)
	                 JJ=0;
	                 else
	                 JJ=sgPurDetail->Cells[5][i+1].Trim().ToDouble();
                   }
	        }
	        catch(...)
	        {
	           //JJ=1;
	           //查询进价
	            Form1->Search_ADOQuery->Close();
	            Form1->Search_ADOQuery->SQL->Clear();
	            Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where 条码 like \""+barcode.Trim()+"\"");
	            Form1->Search_ADOQuery->Active= true;

	            sgPurDetail->Cells[5][i+1]=Form1->Search_ADOQuery->FieldByName("进价")->AsString.Trim();

	            if(sgPurDetail->Cells[5][i+1].Trim().Length()==0)
	            JJ=0;
	            else
	            JJ=sgPurDetail->Cells[5][i+1].Trim().ToDouble();

	        }

	        String str="";
	        Form1->Search_ADOQuery->Close();
	        Form1->Search_ADOQuery->SQL->Clear();
	        str=String().sprintf("SELECT * FROM 出库 WHERE 条码 like \"%s\" AND 出库单据 like \"%s\" AND 出库仓库 like \"%s\"",barcode.Trim(),CK_dj->Text.Trim(),CK_ck->Text.Trim());
	        Form1->Search_ADOQuery->SQL->Add(str);
	        Form1->Search_ADOQuery->Active= true;
	
	        if(Form1->Search_ADOQuery->RecordCount==0)
	        {
	            cost=cost+JJ*CKnum;
	            sales=sales+SJ*CKnum;
	            profits=sales-cost;
	
	            Form1->CK_ADOTable->Insert();
	            Form1->CK_ADOTable->FieldByName("条码")->AsString = barcode.Trim();
	            Form1->CK_ADOTable->FieldByName("出库数量")->AsFloat = CKnum;
	            Form1->CK_ADOTable->FieldByName("出库时间")->AsString=Now().FormatString("yyyy-mm-dd");
	            Form1->CK_ADOTable->FieldByName("出库仓库")->AsString = CK_ck->Text.Trim();
	            Form1->CK_ADOTable->FieldByName("出库单据")->AsString = CK_dj->Text.Trim();
	            Form1->CK_ADOTable->FieldByName("员工编号")->AsString = Form1->LoginName.Trim();
	            Form1->CK_ADOTable->FieldByName("售价")->AsFloat = SJ;
	            Form1->CK_ADOTable->Post();
	        }
	        else
	        {
	            if(SJ==Form1->Search_ADOQuery->FieldByName("售价")->AsFloat)
	            {
	                cost=cost+JJ*CKnum;
	                sales=sales+SJ*CKnum;
	                profits=sales-cost;
	
	            }
	            else
	            {
	                //销售额和利润需要修改
	                sales=sales+SJ*CKnum+(SJ-Form1->Search_ADOQuery->FieldByName("售价")->AsFloat)*Form1->Search_ADOQuery->FieldByName("出库数量")->AsFloat;
	                cost=cost+JJ*CKnum;
	                profits=sales-cost;
	            }
	            str="";
	            str=String().sprintf("UPDATE CK SET  出库数量 = %f , 售价 = %f , 出库时间 =  \"%s\" , 员工编号 =  \"%s\"  WHERE 条码 like \"%s\" AND 出库仓库 like \"%s\" AND 出库单据 like \"%s\""
	                                 ,CKnum+Form1->Search_ADOQuery->FieldByName("出库数量")->AsFloat
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
	        str=String().sprintf("SELECT * FROM 库存 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",barcode.Trim(),CK_ck->Text.Trim());
	        Form1->KC_ADOQuery->SQL->Add(str);
	        Form1->KC_ADOQuery->Active= true;
	
	        if(Form1->KC_ADOQuery->RecordCount==0)
	        {
	            Form1->KC_ADOTable->Insert();
	            Form1->KC_ADOTable->FieldByName("条码")->AsString = barcode.Trim();
	            Form1->KC_ADOTable->FieldByName("出库数量")->AsFloat = CKnum;
	            Form1->KC_ADOTable->FieldByName("仓库")->AsString = CK_ck->Text.Trim();
	            Form1->KC_ADOTable->FieldByName("库存")->AsFloat = 0 - CKnum;
	            Form1->KC_ADOTable->Post();
	         }
	         else
	         {
	            str="";
	            str=String().sprintf("UPDATE KC SET  出库数量 = %f, 库存 =%f  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
	                                 ,CKnum+Form1->KC_ADOQuery->FieldByName("出库数量")->AsFloat
	                                 ,Form1->KC_ADOQuery->FieldByName("库存")->AsFloat-CKnum
	                                 ,barcode.Trim()
	                                 ,CK_ck->Text.Trim());
	            Form1->ADOCommand1->CommandText = str;
	            Form1->ADOCommand1->Execute();
	         }
	    }
	
	    //修改销售统计表
	    String str="";
	    Form1->XSTJ_ADOQuery->Close();
	    Form1->XSTJ_ADOQuery->SQL->Clear();
	    str=String().sprintf("SELECT * FROM 销售统计 WHERE 出库单据 like \"%s\"",CK_dj->Text.Trim());
	    Form1->XSTJ_ADOQuery->SQL->Add(str);
	    Form1->XSTJ_ADOQuery->Active= true;
	
	    if(Form1->XSTJ_ADOQuery->RecordCount==0)
	    {
	            Form1->XSTJ_ADOTable->Insert();
	            Form1->XSTJ_ADOTable->FieldByName("出库单据")->AsString = CK_dj->Text.Trim();
	            Form1->XSTJ_ADOTable->FieldByName("成本")->AsFloat = cost;
	            Form1->XSTJ_ADOTable->FieldByName("销售额")->AsFloat = sales;
	            Form1->XSTJ_ADOTable->FieldByName("利润")->AsFloat = profits;
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
	                                 ,CK_dj->Text.Trim());
	            Form1->ADOCommand1->CommandText = str;
	            Form1->ADOCommand1->Execute();
	     }
	    Form1->KC_ADOQuery->Close();
	    Form1->KC_ADOQuery->SQL->Clear();
	    Form1->KC_ADOQuery->SQL->Add("SELECT * FROM 库存");
	    Form1->KC_ADOQuery->Active= true;
	
	    Form1->XSTJ_ADOQuery->Close();
	    Form1->XSTJ_ADOQuery->SQL->Clear();
	    Form1->XSTJ_ADOQuery->SQL->Add("SELECT * FROM 销售统计");
	    Form1->XSTJ_ADOQuery->Active= true;
	
	
	
	    if(RadioButton1->Checked==true)
	    {
	        Form1->CK_ADOQuery->Close();
	        Form1->CK_ADOQuery->SQL->Clear();
	        Form1->CK_ADOQuery->SQL->Add("SELECT * FROM 出库");
	        Form1->CK_ADOQuery->Active= true;
	        ShowMessage("单据建立成功！");
	    }
	    else if(RadioButton2->Checked==true) //打印小票
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
	    else if(RadioButton4->Checked==true) //打印小票
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

	    Double cost=0;//总成本
	    Double sales=0;//总销售额

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
	                //查询进价
	                 Form1->Search_ADOQuery->Close();
	                 Form1->Search_ADOQuery->SQL->Clear();
	                 Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where 条码 like \""+barcode.Trim()+"\"");
	                 Form1->Search_ADOQuery->Active= true;

	                 sgPurDetail->Cells[5][i+1]=Form1->Search_ADOQuery->FieldByName("进价")->AsString.Trim();

	                 if(sgPurDetail->Cells[5][i+1].Trim().Length()==0)
	                 JJ=0;
	                 else
	                 JJ=sgPurDetail->Cells[5][i+1].Trim().ToDouble();
                   }
	        }
	        catch(...)
	        {
	           //JJ=1;
	           //查询进价
	            Form1->Search_ADOQuery->Close();
	            Form1->Search_ADOQuery->SQL->Clear();
	            Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where 条码 like \""+barcode.Trim()+"\"");
	            Form1->Search_ADOQuery->Active= true;

	            sgPurDetail->Cells[5][i+1]=Form1->Search_ADOQuery->FieldByName("进价")->AsString.Trim();

	            if(sgPurDetail->Cells[5][i+1].Trim().Length()==0)
	            JJ=0;
	            else
	            JJ=sgPurDetail->Cells[5][i+1].Trim().ToDouble();

	        }


	
	        String str="";
	        Form1->Search_ADOQuery->Close();
	        Form1->Search_ADOQuery->SQL->Clear();
	        str=String().sprintf("SELECT * FROM 出库 WHERE 条码 like \"%s\" AND 出库单据 like \"%s\" AND 出库仓库 like \"%s\"",barcode.Trim(),CK_dj->Text.Trim(),CK_ck->Text.Trim());
	        Form1->Search_ADOQuery->SQL->Add(str);
	        Form1->Search_ADOQuery->Active= true;
	
	        if(Form1->Search_ADOQuery->RecordCount==0)
	        {
	            cost=cost+JJ*CKnum;
	            sales=sales+SJ*CKnum;
	        }
	        else
	        {
	            if(SJ==Form1->Search_ADOQuery->FieldByName("售价")->AsFloat)
	            {
	                cost=cost+JJ*CKnum;
	                sales=sales+SJ*CKnum;
	            }
	            else
	            {
	                //销售额和利润需要修改
	                sales=sales+SJ*CKnum+(SJ-Form1->Search_ADOQuery->FieldByName("售价")->AsFloat)*Form1->Search_ADOQuery->FieldByName("出库数量")->AsFloat;
	                cost=cost+JJ*CKnum;
	            }
	
	        }
	    }

            Panel1->Visible=true;
	    //显示出应收款，实收款，应找零
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
     //点击的时候进行查询

     if(sgPurDetail->Col==2)
     {
          //显示出查询即可
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
         sgPurDetail->Canvas->Font->Color=clRed; //部分字体颜色
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

