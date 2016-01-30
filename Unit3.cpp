//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include   <inifiles.hpp>

#include "Unit3.h"
#include "Unit1.h"
#include "Unit19.h"
#include "Unit4.h"
#include "Unit32.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;


int m_CurrentCol;   // 关标所在当前列
int m_CurrentRow;  // 关标所在当前行

//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::sgPurDetailKeyPress(TObject *Sender, char &Key)
{
    if(Key ==13)
    {
        // 跳到下一个单元格
        if(m_CurrentCol == 1 )
        {
            //搜索出此条码的资料写在框里边
            Form1->Search_ADOQuery->Close();
            Form1->Search_ADOQuery->SQL->Clear();
            Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where 条码 like \""+sgPurDetail->Cells[1][sgPurDetail->Row].Trim()+"\"");
            Form1->Search_ADOQuery->Active= true;
           // ShowMessage(sgPurDetail->Cells[1][sgPurDetail->Row].Trim());
            sgPurDetail->Cells[2][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("名称")->AsString.Trim();
            sgPurDetail->Cells[3][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("进价")->AsString.Trim();

            if(CheckBox1->Checked==true)
            {
               sgPurDetail->Cells[4][sgPurDetail->Row]="1";
               sgPurDetail->RowCount++;
               sgPurDetail->Cells[0][sgPurDetail->RowCount-1] = sgPurDetail->RowCount-1;
               sgPurDetail->Col = 1;
               sgPurDetail->Row = m_CurrentRow + 1;
            }
            else
            sgPurDetail->Col = 4;
        }
        else if(m_CurrentCol == 4)   // 下一行
        {
            sgPurDetail->RowCount++;
            sgPurDetail->Cells[0][sgPurDetail->RowCount-1] = sgPurDetail->RowCount-1;
            sgPurDetail->Col = 1;
            sgPurDetail->Row = m_CurrentRow + 1;
        }
        m_CurrentCol = sgPurDetail->Col;
        m_CurrentRow = sgPurDetail->Row;
    }
  /* else if(Key==VK_SPACE)
    {
         if(Button1->Enabled==true)Button1Click(Sender);
    }   */
}
//---------------------------------------------------------------------------
void __fastcall TForm3::sgPurDetailSelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
        if( ACol==2|| ACol==3)
            sgPurDetail->Options >> goEditing;
        else
            sgPurDetail->Options << goEditing;

        m_CurrentCol = ACol;
        m_CurrentRow = ARow;
}
//---------------------------------------------------------------------------


void __fastcall TForm3::FormShow(TObject *Sender)
{
     //清空
    RK_dj->Text="";
    RK_ck->Text="";

       // 设置明细列表的内容
    sgPurDetail->Cells[0][0] = "序号";
    sgPurDetail->ColWidths[0] = 32;
    sgPurDetail->Cells[1][0] = Form1->infshow1;
    sgPurDetail->ColWidths[1] = 200;
    sgPurDetail->Cells[2][0] = Form1->infshow2+"        （单击此列可选择商品）";
    sgPurDetail->ColWidths[2] = 250;
    sgPurDetail->Cells[3][0] = Form1->infshow6;
    if(Form1->Pshow=="show")sgPurDetail->ColWidths[3] = 64;
    else sgPurDetail->ColWidths[3] = 0;
    sgPurDetail->Cells[4][0] = "数量";
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

    m_CurrentCol = 1;
    m_CurrentRow = 1;

    if(CheckBox1->Checked==true)
    {
        if(RK_dj->Text.Trim().Length()==0||RK_ck->Text.Trim().Length()==0)
        {
            if(RK_dj->Text.Trim().Length()==0)RK_dj->Text="DH"+Now().FormatString("yyyymmddhhnnss");
            if(RK_ck->Text.Trim().Length()==0)RK_ck->Text="CK001";
        }
        sgPurDetail->SetFocus();
    }

}
//---------------------------------------------------------------------------


void __fastcall TForm3::BitBtn2Click(TObject *Sender)
{
    if(RK_dj->Text.Trim().Length()==0)
    {
       ShowMessage("入库单号不能为空，请先填写需要打印的单据！");
       return;
    }

    Form1->RK_ADOQuery->Close();
    Form1->RK_ADOQuery->SQL->Clear();
    Form1->RK_ADOQuery->SQL->Add("SELECT * FROM 入库 WHERE 入库单据 like \""+RK_dj->Text.Trim()+"\"");
    Form1->RK_ADOQuery->Active= true;
    RKprint->QuickRep1->Preview();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::CheckBox1Click(TObject *Sender)
{
    if(CheckBox1->Checked==true)
    {
        if(RK_dj->Text.Trim().Length()==0||RK_ck->Text.Trim().Length()==0)
        {
            if(RK_dj->Text.Trim().Length()==0)RK_dj->Text="DH"+Now().FormatString("yyyymmddhhnnss");
            if(RK_ck->Text.Trim().Length()==0)RK_ck->Text="CK001";
        }
        sgPurDetail->SetFocus();
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
   if(RK_dj->Text.Trim().Length()==0||RK_ck->Text.Trim().Length()==0)
    {
        if(RK_dj->Text.Trim().Length()==0)RK_dj->Text="DH001";
        if(RK_ck->Text.Trim().Length()==0)RK_ck->Text="CK001";
        if(mrYes!=MessageDlg("入库单号、仓库号，都不能为空，是否确认入库？",mtInformation,TMsgDlgButtons()<<mbYes<<mbNo,0))
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
           if(sgPurDetail->Cells[4][i+1].Trim()!=0)
           RKnum=sgPurDetail->Cells[4][i+1].Trim().ToDouble();
           else  RKnum=1;
        }
        catch(...)
        {
           RKnum=1;
        }

        String str="";
        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM 入库 WHERE 条码 like \"%s\" AND 入库单据 like \"%s\" AND 入库仓库 like \"%s\"",barcode.Trim(),RK_dj->Text.Trim(),RK_ck->Text.Trim());
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;

        if(Form1->Search_ADOQuery->RecordCount==0)
        {
            Form1->RK_ADOTable->Insert();
            Form1->RK_ADOTable->FieldByName("条码")->AsString = barcode.Trim();
            Form1->RK_ADOTable->FieldByName("入库数量")->AsFloat = RKnum;
            Form1->RK_ADOTable->FieldByName("入库时间")->AsString=Now().FormatString("yyyy-mm-dd");
            Form1->RK_ADOTable->FieldByName("入库仓库")->AsString = RK_ck->Text.Trim();
            Form1->RK_ADOTable->FieldByName("入库单据")->AsString = RK_dj->Text.Trim();
            Form1->RK_ADOTable->FieldByName("员工编号")->AsString = Form1->LoginName.Trim();
            Form1->RK_ADOTable->Post();
        }
        else
        {
            str="";
            str=String().sprintf("UPDATE RK SET  入库数量 = %f , 入库时间 =  \"%s\" , 员工编号 =  \"%s\" WHERE 条码 like \"%s\" AND 入库仓库 like \"%s\" AND 入库单据 like \"%s\""
                                 ,RKnum+Form1->Search_ADOQuery->FieldByName("入库数量")->AsFloat
                                 ,Now().FormatString("yyyy-mm-dd")
                                 ,Form1->LoginName.Trim()
                                 ,barcode.Trim()
                                 ,RK_ck->Text.Trim()
                                 ,RK_dj->Text.Trim());
                            Form1->ADOCommand1->CommandText = str;
                            Form1->ADOCommand1->Execute();
        }

        str="";
        Form1->KC_ADOQuery->Close();
        Form1->KC_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM 库存 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",barcode.Trim(),RK_ck->Text.Trim());
        Form1->KC_ADOQuery->SQL->Add(str);
        Form1->KC_ADOQuery->Active= true;

        if(Form1->KC_ADOQuery->RecordCount==0)
        {
            Form1->KC_ADOTable->Insert();
            Form1->KC_ADOTable->FieldByName("条码")->AsString = barcode.Trim();
            Form1->KC_ADOTable->FieldByName("入库数量")->AsFloat = RKnum;
            Form1->KC_ADOTable->FieldByName("仓库")->AsString = RK_ck->Text.Trim();
            Form1->KC_ADOTable->FieldByName("库存")->AsFloat = RKnum;
            Form1->KC_ADOTable->Post();
         }
         else
         {
            str="";
            str=String().sprintf("UPDATE KC SET  入库数量 = %f, 库存 =%f  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                 ,RKnum+Form1->KC_ADOQuery->FieldByName("入库数量")->AsFloat
                                 ,RKnum+Form1->KC_ADOQuery->FieldByName("库存")->AsFloat
                                 ,barcode.Trim()
                                 ,RK_ck->Text.Trim());
            Form1->ADOCommand1->CommandText = str;
            Form1->ADOCommand1->Execute();
         }
    }



    Form1->KC_ADOQuery->Close();
    Form1->KC_ADOQuery->SQL->Clear();
    Form1->KC_ADOQuery->SQL->Add("SELECT * FROM 库存");
    Form1->KC_ADOQuery->Active= true;

    if(RadioButton1->Checked==true)
    {
        Form1->RK_ADOQuery->Close();
        Form1->RK_ADOQuery->SQL->Clear();
        Form1->RK_ADOQuery->SQL->Add("SELECT * FROM 入库");
        Form1->RK_ADOQuery->Active= true;
        ShowMessage("单据建立成功！");
    }
    else if(RadioButton2->Checked==true) //打印小票
    {
        Form4->CheckRKbar->Checked=false;
        Form4->CheckRKck->Checked=false;
        Form4->CheckRKbh->Checked=false;
        Form4->CheckRKnm->Checked=false;
        Form4->CheckRKdate->Checked=false;

        Form4->CheckRKdj->Checked=true;
        Form4->Check_RK_dj->Text=RK_dj->Text.Trim();

        Form4->BitBtn5Click(Sender);
    }
    else if(RadioButton3->Checked==true)
    {
        Form4->CheckRKbar->Checked=false;
        Form4->CheckRKck->Checked=false;
        Form4->CheckRKbh->Checked=false;
        Form4->CheckRKnm->Checked=false;
        Form4->CheckRKdate->Checked=false;

        Form4->CheckRKdj->Checked=true;
        Form4->Check_RK_dj->Text=RK_dj->Text.Trim();

        Form4->BitBtn3Click(Sender);
    }
    else if(RadioButton4->Checked==true) //打印小票
    {
        Form4->CheckRKbar->Checked=false;
        Form4->CheckRKck->Checked=false;
        Form4->CheckRKbh->Checked=false;
        Form4->CheckRKnm->Checked=false;
        Form4->CheckRKdate->Checked=false;

        Form4->CheckRKdj->Checked=true;
        Form4->Check_RK_dj->Text=RK_dj->Text.Trim();

        Form4->BitBtn5Click(Sender);
        Form4->BitBtn3Click(Sender);
    }if(CheckBox1->Checked==false)Button1->Enabled=false;
    else
    {
        Button2Click(Sender);
        RK_dj->Text="DH"+Now().FormatString("yyyymmddhhnnss");
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm3::sgPurDetailClick(TObject *Sender)
{
     //点击的时候进行查询

     if(sgPurDetail->Col==2||sgPurDetail->Col==3)
     {
          //显示出查询即可
          Form32->typeindex="3";
          Form32->Show();

     }

}
//---------------------------------------------------------------------------

void __fastcall TForm3::sgPurDetailDrawCell(TObject *Sender, int ACol,
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

void __fastcall TForm3::Button2Click(TObject *Sender)
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

    m_CurrentCol = 1;
    m_CurrentRow = 1;
    RK_dj->Clear();
    RK_dj->SetFocus();
    Button1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RK_djKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
      if(Key==VK_RETURN)RK_ck->SetFocus();  
}
//---------------------------------------------------------------------------

void __fastcall TForm3::RK_ckKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
     if(Key==VK_RETURN)sgPurDetail->SetFocus();    
}
//---------------------------------------------------------------------------


