//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit25.h"
#include "Unit1.h"
#include "Unit10.h"
#include "Unit33.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm25 *Form25;

int yd2_CurrentCol;   // 关标所在当前列
int yd2_CurrentRow;  // 关标所在当前行


//---------------------------------------------------------------------------
__fastcall TForm25::TForm25(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm25::FormShow(TObject *Sender)
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
    sgPurDetail->Cells[3][0] = "应扫数量";
    sgPurDetail->ColWidths[3] = 80;
    sgPurDetail->Cells[4][0] = "已扫数量";
    sgPurDetail->ColWidths[4] = 80;
    sgPurDetail->Cells[5][0] = "验单数量";
    sgPurDetail->ColWidths[5] = 80;


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

    yd2_CurrentCol = 1;
    yd2_CurrentRow = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm25::sgPurDetailKeyPress(TObject *Sender, char &Key)
{
    if(Key ==13)
    {
        if(Edit1->Text.Trim().Length()==0)
        {
            ShowMessage("单据号不能为空，请先填写单据号！");
            return;
        }

        // 跳到下一个单元格
        if(yd2_CurrentCol == 1 )
        {


            //搜索出此条码的资料写在框里边
            Form1->Search_ADOQuery->Close();
            Form1->Search_ADOQuery->SQL->Clear();
            Form1->Search_ADOQuery->SQL->Add("SELECT * FROM 验单 where 条码 like \""+sgPurDetail->Cells[1][sgPurDetail->Row].Trim()+"\" AND 单据 like \""+Edit1->Text.Trim()+"\"");
            Form1->Search_ADOQuery->Active= true;

            if(Form1->Search_ADOQuery->RecordCount!=0)
            {
                sgPurDetail->Cells[2][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("名称")->AsString.Trim();
                sgPurDetail->Cells[3][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("应扫数量")->AsString.Trim();
                sgPurDetail->Cells[4][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("已扫数量")->AsString.Trim();
            }
            else
            {
                Form1->Search_ADOQuery->Close();
                Form1->Search_ADOQuery->SQL->Clear();
                Form1->Search_ADOQuery->SQL->Add("SELECT * FROM 验单 where 条码 like \""+sgPurDetail->Cells[1][sgPurDetail->Row].Trim()+"\"");
                Form1->Search_ADOQuery->Active= true;

                sgPurDetail->Cells[2][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("名称")->AsString.Trim();
                sgPurDetail->Cells[3][sgPurDetail->Row]="0";
                sgPurDetail->Cells[4][sgPurDetail->Row]="0";
            }

            if(CheckBox1->Checked==true)
            {
               sgPurDetail->Cells[5][sgPurDetail->Row]="1";
               sgPurDetail->RowCount++;
               sgPurDetail->Cells[0][sgPurDetail->RowCount-1] = sgPurDetail->RowCount-1;
               sgPurDetail->Col = 1;
               sgPurDetail->Row = yd2_CurrentRow + 1;
            }
            else
            sgPurDetail->Col = 5;
        }
        else if(yd2_CurrentCol == 5)   // 下一行
        {
            sgPurDetail->RowCount++;
            sgPurDetail->Cells[0][sgPurDetail->RowCount-1] = sgPurDetail->RowCount-1;
            sgPurDetail->Col = 1;
            sgPurDetail->Row = yd2_CurrentRow + 1;
        }

        yd2_CurrentCol = sgPurDetail->Col;
        yd2_CurrentRow = sgPurDetail->Row;
    }
    else if(Key==VK_SPACE)
    {
         Button1Click(Sender);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm25::Button1Click(TObject *Sender)
{
  //fgdfg
    if(Edit1->Text.Trim().Length()==0)
    {
            ShowMessage("单据号不能为空，请先填写单据号！");
            return;
    }



    float YSSL=0;
    float YDSL=0;
    String str="";
    String barcode="";

    for(int i=0;i<sgPurDetail->RowCount;i++)
    {
        if(sgPurDetail->Cells[1][i+1].Trim().Length()==0)continue;
        barcode=sgPurDetail->Cells[1][i+1].Trim();

        try
        {
           YDSL=sgPurDetail->Cells[5][i+1].Trim().ToDouble();
        }
        catch(...)
        {
           YDSL=1;
        }


        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM 验单 WHERE 条码 like \"%s\" AND 单据 like \"%s\"",barcode.Trim(),Edit1->Text.Trim());
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;
        YSSL=Form1->Search_ADOQuery->FieldByName("已扫数量")->AsFloat;
        if(Form1->Search_ADOQuery->RecordCount==0)
        {
             Form1->YD_ADOTable->Insert();
             Form1->YD_ADOTable->FieldByName("条码")->AsString = barcode.Trim();
             Form1->YD_ADOTable->FieldByName("应扫数量")->AsFloat = 0;
             Form1->YD_ADOTable->FieldByName("已扫数量")->AsFloat = YDSL;
             Form1->YD_ADOTable->FieldByName("时间")->AsString=Now().FormatString("yyyy-mm-dd");
             Form1->YD_ADOTable->FieldByName("单据")->AsString = Edit1->Text.Trim();
             Form1->YD_ADOTable->FieldByName("员工编号")->AsString = Form1->LoginName.Trim();
             Form1->YD_ADOTable->Post();
        }
        else
        {
             str="";
             str=String().sprintf("UPDATE YD SET  已扫数量 = %f ,时间 = \"%s\" ,员工编号 = \"%s\"  WHERE 条码 like \"%s\" AND 单据 like \"%s\""
                                   ,YSSL+YDSL
                                   ,Now().FormatString("yyyy-mm-dd")
                                   ,Form1->LoginName.Trim()
                                   ,barcode.Trim()
                                   ,Edit1->Text.Trim());
             Form1->ADOCommand1->CommandText = str;
             Form1->ADOCommand1->Execute();
        }
     }



    if(RadioButton1->Checked==true)
    {
        Form1->YD_ADOQuery->Close();
        Form1->YD_ADOQuery->SQL->Clear();
        Form1->YD_ADOQuery->SQL->Add("SELECT * FROM 验单");
        Form1->YD_ADOQuery->Active= true;


        ShowMessage("验单成功！");
    }
    else
    {
         Form10->CheckBox1->Checked=false;
         Form10->CheckBox2->Checked=true;
         Form10->CheckBox3->Checked=false;
         Form10->CheckBox4->Checked=false;
         Form10->CheckBox5->Checked=false;

         Form10->Edit2->Text=Edit1->Text.Trim();
         Form10->Button1Click(Sender);
    }
    if(CheckBox1->Checked==false)Button1->Enabled=false;
    else
    {
        Button4Click(Sender);
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm25::sgPurDetailSelectCell(TObject *Sender, int ACol,
      int ARow, bool &CanSelect)
{
        
        if( ACol==2|| ACol==3|| ACol==4)
            sgPurDetail->Options >> goEditing;
        else
            sgPurDetail->Options << goEditing;
}
//---------------------------------------------------------------------------


void __fastcall TForm25::sgPurDetailClick(TObject *Sender)
{
     if(sgPurDetail->Col==2)
     {

          Form33->Show();

     }
}
//---------------------------------------------------------------------------

void __fastcall TForm25::sgPurDetailDrawCell(TObject *Sender, int ACol,
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

void __fastcall TForm25::Button2Click(TObject *Sender)
{

    String ss="Provider=Microsoft.Jet.OLEDB.4.0;Data Source="+ExtractFilePath(Application->ExeName)+"验单导入.xls;Mode=Share Deny None;Extended Properties=\"Excel 8.0;IMEX=1;\";Persist Security Info=False" ;
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
    float YSSL=0;

    int index=0;
    for(int i=0;;i++)
    {
        if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="条码"){num0=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="数量"){num1=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="单据"){num2=i;index++;}
        if(index==3)break;
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

        if(Form1->qry1->Fields->Fields[num2]->AsString.Trim().Length()==0)DH="DH001";
        else
        {
            DH= Form1->qry1->Fields->Fields[num2]->AsString.Trim();
        }


        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM 验单 WHERE 条码 like \"%s\" AND 单据 like \"%s\"",Form1->qry1->Fields->Fields[num0]->AsString.Trim(),DH);
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;
        YSSL=Form1->Search_ADOQuery->FieldByName("已扫数量")->AsFloat;
        if(Form1->Search_ADOQuery->RecordCount==0)
        {
             Form1->YD_ADOTable->Insert();
             Form1->YD_ADOTable->FieldByName("条码")->AsString = Form1->qry1->Fields->Fields[num0]->AsString.Trim();
             Form1->YD_ADOTable->FieldByName("应扫数量")->AsFloat = 0;
             Form1->YD_ADOTable->FieldByName("已扫数量")->AsFloat = num;
             Form1->YD_ADOTable->FieldByName("时间")->AsString=Now().FormatString("yyyy-mm-dd");
             Form1->YD_ADOTable->FieldByName("单据")->AsString = DH;
             Form1->YD_ADOTable->FieldByName("员工编号")->AsString = Form1->LoginName.Trim();
             Form1->YD_ADOTable->Post();
        }
        else
        {
             str="";
             str=String().sprintf("UPDATE YD SET  已扫数量 = %f ,时间 = \"%s\" ,员工编号 = \"%s\"  WHERE 条码 like \"%s\" AND 单据 like \"%s\""
                                   ,YSSL+num
                                   ,Now().FormatString("yyyy-mm-dd")
                                   ,Form1->LoginName.Trim()
                                   ,Form1->qry1->Fields->Fields[num0]->AsString.Trim()
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

    Form1->YD_ADOQuery->Close();
    Form1->YD_ADOQuery->SQL->Clear();
    Form1->YD_ADOQuery->SQL->Add("SELECT * FROM 验单");
    Form1->YD_ADOQuery->Active= true;

    MessageDlg("导入完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

    this->StatusBar1->Panels->Items[0]->Text="";
}
//---------------------------------------------------------------------------

void __fastcall TForm25::Button3Click(TObject *Sender)
{
    TStringList *DataList=new TStringList();
    TStringList *pList=new TStringList();
    DataList->Text="";
    DataList->LoadFromFile("验单导入.txt");

    pList->Text="";
    Form1->CrnListSplitString(DataList->Strings[0],pList,'\t');

    int num0=0;
    int num1=0;
    int num2=0;
    float YSSL=0;

    int index=0;
    for(int i=0;i<pList->Count;i++)
    {
        if(pList->Strings[i].Trim()=="条码"){num0=i;index++;}
        else if(pList->Strings[i].Trim()=="数量"){num1=i;index++;}
        else if(pList->Strings[i].Trim()=="单据"){num2=i;index++;}

        if(index==3)break;
    }

    if(index!=3)
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

        if(pList->Strings[num2].Trim().Length()==0)DH="DH001";
        else
        {
            DH= pList->Strings[num2].Trim();
        }

        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM 验单 WHERE 条码 like \"%s\" AND 单据 like \"%s\"",pList->Strings[num0],DH);
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;
        YSSL=Form1->Search_ADOQuery->FieldByName("已扫数量")->AsFloat;
        if(Form1->Search_ADOQuery->RecordCount==0)
        {
             Form1->YD_ADOTable->Insert();
             Form1->YD_ADOTable->FieldByName("条码")->AsString = pList->Strings[num0];
             Form1->YD_ADOTable->FieldByName("应扫数量")->AsFloat = 0;
             Form1->YD_ADOTable->FieldByName("已扫数量")->AsFloat = num;
             Form1->YD_ADOTable->FieldByName("时间")->AsString=Now().FormatString("yyyy-mm-dd");
             Form1->YD_ADOTable->FieldByName("单据")->AsString = DH;
             Form1->YD_ADOTable->FieldByName("员工编号")->AsString = Form1->LoginName.Trim();
             Form1->YD_ADOTable->Post();
        }
        else
        {
             str="";
             str=String().sprintf("UPDATE YD SET  已扫数量 = %f ,时间 = \"%s\" ,员工编号 = \"%s\"  WHERE 条码 like \"%s\" AND 单据 like \"%s\""
                                   ,YSSL+num
                                   ,Now().FormatString("yyyy-mm-dd")
                                   ,Form1->LoginName.Trim()
                                   ,pList->Strings[num0]
                                   ,DH);
             Form1->ADOCommand1->CommandText = str;
             Form1->ADOCommand1->Execute();
        }

        Application->ProcessMessages();

    }

    Form1->YD_ADOQuery->Close();
    Form1->YD_ADOQuery->SQL->Clear();
    Form1->YD_ADOQuery->SQL->Add("SELECT * FROM 验单");
    Form1->YD_ADOQuery->Active= true;

    MessageDlg("导入完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

    this->StatusBar1->Panels->Items[0]->Text="";


    delete DataList;
    delete pList;

}
//---------------------------------------------------------------------------

void __fastcall TForm25::Button4Click(TObject *Sender)
{
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
    yd2_CurrentCol = 1;
    yd2_CurrentRow = 1;
    Edit1->Clear();
    Edit1->SetFocus();
    Button1->Enabled=true;
}
//---------------------------------------------------------------------------

