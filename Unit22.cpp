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

int pd_CurrentCol;   // 关标所在当前列
int pd_CurrentRow;  // 关标所在当前行


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
        // 跳到下一个单元格
        if(pd_CurrentCol == 1 )
        {
            //搜索出此条码的资料写在框里边
            Form1->Search_ADOQuery->Close();
            Form1->Search_ADOQuery->SQL->Clear();
            Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where 条码 like \""+sgPurDetail->Cells[1][sgPurDetail->Row].Trim()+"\"");
            Form1->Search_ADOQuery->Active= true;

           // ShowMessage(sgPurDetail->Cells[1][sgPurDetail->Row].Trim());

            sgPurDetail->Cells[2][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("名称")->AsString.Trim();
            sgPurDetail->Cells[3][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("货号")->AsString.Trim();

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
        else if(pd_CurrentCol == 4)   // 下一行
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
     //清空
    Edit1->Text="";

       // 设置明细列表的内容
    sgPurDetail->Cells[0][0] = "序号";
    sgPurDetail->ColWidths[0] = 32;
    sgPurDetail->Cells[1][0] = Form1->infshow1;
    sgPurDetail->ColWidths[1] = 200;
    sgPurDetail->Cells[2][0] = Form1->infshow2+"        （单击此列可选择商品）";
    sgPurDetail->ColWidths[2] = 250;
    sgPurDetail->Cells[3][0] = Form1->infshow3;
    sgPurDetail->ColWidths[3] = 64;
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
        if(mrYes!=MessageDlg("单号、仓库号不能为空，是否确认盘点？",mtInformation,TMsgDlgButtons()<<mbYes<<mbNo,0))
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

        //修改盘点统计表================================================================================================
        String str="";
        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM 盘点统计 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",barcode.Trim(),Edit1->Text.Trim());
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;

        if(Form1->Search_ADOQuery->RecordCount==0)
        {
            Form1->PDTJ_ADOTable->Insert();
            Form1->PDTJ_ADOTable->FieldByName("条码")->AsString = barcode.Trim();
            Form1->PDTJ_ADOTable->FieldByName("盘点库存")->AsFloat = RKnum;
            Form1->PDTJ_ADOTable->FieldByName("仓库")->AsString = Edit1->Text.Trim();
            Form1->PDTJ_ADOTable->Post();
        }
        else
        {
            str="";
            str=String().sprintf("UPDATE PDTJ SET  盘点库存 = %f WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                   ,RKnum+Form1->Search_ADOQuery->FieldByName("盘点库存")->AsFloat
                                   ,barcode.Trim()
                                   ,Edit1->Text.Trim());
            Form1->ADOCommand1->CommandText = str;
            Form1->ADOCommand1->Execute();
        }

        //修改盘点明细表==================================================================================================
        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM 盘点 WHERE 条码 like \"%s\" AND 仓库 like \"%s\" AND 单号 like \"%s\"",barcode.Trim(),Edit1->Text.Trim(),Edit2->Text.Trim());
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;

        if(Form1->Search_ADOQuery->RecordCount==0)
        {
            Form1->PD_ADOTable->Insert();
            Form1->PD_ADOTable->FieldByName("条码")->AsString = barcode.Trim();
            Form1->PD_ADOTable->FieldByName("盘点库存")->AsFloat = RKnum;
            Form1->PD_ADOTable->FieldByName("仓库")->AsString = Edit1->Text.Trim();
            Form1->PD_ADOTable->FieldByName("单号")->AsString = Edit2->Text.Trim();
            Form1->PD_ADOTable->FieldByName("盘点时间")->AsString = Now().FormatString("yyyy-mm-dd");
            Form1->PD_ADOTable->FieldByName("员工编号")->AsString = Form1->LoginName.Trim();
            Form1->PD_ADOTable->Post();
        }
        else
        {
            str="";
            str=String().sprintf("UPDATE PD SET  盘点库存 = %f , 盘点时间 =\"%s\" , 员工编号 = \"%s\" WHERE 条码 like \"%s\" AND 仓库 like \"%s\" AND 单号 like \"%s\""
                                   ,RKnum+Form1->Search_ADOQuery->FieldByName("盘点库存")->AsFloat
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
    Form1->PD_ADOQuery->SQL->Add("SELECT * FROM 盘点");
    Form1->PD_ADOQuery->Active= true;

    Form1->PDTJ_ADOQuery->Close();
    Form1->PDTJ_ADOQuery->SQL->Clear();
    Form1->PDTJ_ADOQuery->SQL->Add("SELECT * FROM 盘点统计");
    Form1->PDTJ_ADOQuery->Active= true;
    
    if(CheckBox1->Checked==false)Button1->Enabled=false;
    else
    {
        Button2Click(Sender);
        Edit2->Text="DH"+Now().FormatString("yyyymmddhhnnss");
    }

    ShowMessage("盘点成功！");
}
//---------------------------------------------------------------------------

void __fastcall TForm22::sgPurDetailClick(TObject *Sender)
{
//点击的时候进行查询

     if(sgPurDetail->Col==2||sgPurDetail->Col==3)
     {
          //显示出查询即可
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
         sgPurDetail->Canvas->Font->Color=clRed; //部分字体颜色
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

