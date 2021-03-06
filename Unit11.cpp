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

int yd_CurrentCol;   // 关标所在当前列
int yd_CurrentRow;  // 关标所在当前行

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
        // 跳到下一个单元格
        if(yd_CurrentCol == 1 )
        {


            //搜索出此条码的资料写在框里边
            Form1->Search_ADOQuery->Close();
            Form1->Search_ADOQuery->SQL->Clear();
            Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where 条码 like \""+sgPurDetail->Cells[1][sgPurDetail->Row].Trim()+"\"");
            Form1->Search_ADOQuery->Active= true;

           // ShowMessage(sgPurDetail->Cells[1][sgPurDetail->Row].Trim());

            sgPurDetail->Cells[2][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("名称")->AsString.Trim();
            sgPurDetail->Cells[3][sgPurDetail->Row]=Form1->Search_ADOQuery->FieldByName("售价")->AsString.Trim();

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
        else if(yd_CurrentCol == 4)   // 下一行
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
       if(  ACol==2 || ACol==3)  // 不可以编辑的列
            sgPurDetail->Options >> goEditing;
        else
            sgPurDetail->Options << goEditing;

        yd_CurrentCol = ACol;
        yd_CurrentRow = ARow;
}
//---------------------------------------------------------------------------
void __fastcall TForm11::FormShow(TObject *Sender)
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
    sgPurDetail->Cells[3][0] = Form1->infshow7;
    sgPurDetail->ColWidths[3] = 64;
    sgPurDetail->Cells[4][0] = "数量";
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
String ss="Provider=Microsoft.Jet.OLEDB.4.0;Data Source="+ExtractFilePath(Application->ExeName)+"订单.xls;Mode=Share Deny None;Extended Properties=\"Excel 8.0;IMEX=1;\";Persist Security Info=False" ;
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
        if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="条码"){num0=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="单据"){num1=i;index++;}
        else if(Form1->qry1->Fields->Fields[i]->FieldName.Trim()=="数量"){num2=i;index++;}
        if(index==3)break;
    }

    String str="";
    Double kc=0;
    String name="";



    int indexshow=0;
    while(!Form1->qry1->Eof) //循环写入数据库
    {
        if(Form1->qry1->Fields->Fields[num0]->AsString.Trim().Length()==0)
        {
           Form1->qry1->Next();
           continue;
        }
        indexshow++;
        StatusBar1->Panels->Items[0]->Text="正在导入资料    条数： "+String(indexshow);

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

        //查询库存是否存在 ，如果存在直接更新，如果不存在先搜索名称以后再添加进去
        str="";
        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM YD WHERE 条码 like \"%s\" AND 单据 like \"%s\"",Form1->qry1->Fields->Fields[num0]->AsString.Trim(),Form1->qry1->Fields->Fields[num1]->AsString.Trim());
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;



        if(Form1->Search_ADOQuery->RecordCount==0)
        {
            Form1->YD_ADOTable->Insert();
            Form1->YD_ADOTable->FieldByName("条码")->AsString = Form1->qry1->Fields->Fields[num0]->AsString.Trim();
            Form1->YD_ADOTable->FieldByName("单据")->AsString = Form1->qry1->Fields->Fields[num1]->AsString.Trim();
            Form1->YD_ADOTable->FieldByName("应扫数量")->AsFloat = kc;
            Form1->YD_ADOTable->FieldByName("已扫数量")->AsFloat = 0;
            Form1->YD_ADOTable->FieldByName("时间")->AsString=Now().FormatString("yyyy-mm-dd");
            Form1->YD_ADOTable->FieldByName("员工编号")->AsString = "";
            Form1->YD_ADOTable->Post();
         }
         else
         {
            str="";
            str=String().sprintf("UPDATE YD SET  应扫数量 = %f , 时间 =  \"%s\"  WHERE 条码 like \"%s\" AND 单据 like \"%s\""
                                 ,kc+Form1->Search_ADOQuery->FieldByName("应扫数量")->AsFloat
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
    Form1->YD_ADOQuery->SQL->Add("SELECT * FROM 验单");
    Form1->YD_ADOQuery->Active= true;
    MessageDlg("导入完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

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
        if(mrYes!=MessageDlg("单据号不能为空，将默认为DH001，是否确认？",mtInformation,TMsgDlgButtons()<<mbYes<<mbNo,0))
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
        str=String().sprintf("SELECT * FROM 验单 WHERE 条码 like \"%s\" AND 单据 like \"%s\"",barcode.Trim(),Edit1->Text.Trim());
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;

        if(Form1->Search_ADOQuery->RecordCount==0)
        {
            Form1->YD_ADOTable->Insert();
            Form1->YD_ADOTable->FieldByName("条码")->AsString = barcode.Trim();
            Form1->YD_ADOTable->FieldByName("应扫数量")->AsFloat = YDnum;
            Form1->YD_ADOTable->FieldByName("已扫数量")->AsFloat = 0;
            Form1->YD_ADOTable->FieldByName("时间")->AsString=Now().FormatString("yyyy-mm-dd");
            Form1->YD_ADOTable->FieldByName("单据")->AsString = Edit1->Text.Trim();
            Form1->YD_ADOTable->FieldByName("员工编号")->AsString = "";
            Form1->YD_ADOTable->Post();
        }
        else
        {
            str="";
            str=String().sprintf("UPDATE YD SET  应扫数量 = %f , 时间 =  \"%s\"  WHERE 条码 like \"%s\" AND 单据 like \"%s\""
                                 ,YDnum+Form1->Search_ADOQuery->FieldByName("应扫数量")->AsFloat
                                 ,Now().FormatString("yyyy-mm-dd")
                                 ,barcode.Trim()
                                 ,Edit1->Text.Trim());
                            Form1->ADOCommand1->CommandText = str;
                            Form1->ADOCommand1->Execute();
        }
    }

    ShowMessage("订单添加成功！");

    Form1->YD_ADOQuery->Close();
    Form1->YD_ADOQuery->SQL->Clear();
    Form1->YD_ADOQuery->SQL->Add("SELECT * FROM 验单");
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
          //显示出查询即可
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
         sgPurDetail->Canvas->Font->Color=clRed; //部分字体颜色
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
    DataList->LoadFromFile("订单.txt");

    pList->Text="";
    Form1->CrnListSplitString(DataList->Strings[0],pList,'\t');

    int num0=0;
    int num1=0;
    int num2=0;

    int index=0;
    for(int i=0;i<pList->Count;i++)
    {
        if(pList->Strings[i].Trim()=="条码"){num0=i;index++;}
        else if(pList->Strings[i].Trim()=="单据"){num1=i;index++;}
        else if(pList->Strings[i].Trim()=="数量"){num2=i;index++;}
        if(index==3)break;
    }

    if(index!=3)
    {
            MessageDlg("格式不对",mtInformation,TMsgDlgButtons()<<mbOK,0);
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
        this->StatusBar1->Panels->Items[0]->Text="正在导入资料    条数： "+String(indexshow);


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





        //查询库存是否存在 ，如果存在直接更新，如果不存在先搜索名称以后再添加进去
        str="";
        Form1->Search_ADOQuery->Close();
        Form1->Search_ADOQuery->SQL->Clear();
        str=String().sprintf("SELECT * FROM YD WHERE 条码 like \"%s\" AND 单据 like \"%s\"",pList->Strings[num0].Trim(),pList->Strings[num1].Trim());
        Form1->Search_ADOQuery->SQL->Add(str);
        Form1->Search_ADOQuery->Active= true;



        if(Form1->Search_ADOQuery->RecordCount==0)
        {
            Form1->YD_ADOTable->Insert();
            Form1->YD_ADOTable->FieldByName("条码")->AsString = pList->Strings[num0].Trim();
            Form1->YD_ADOTable->FieldByName("单据")->AsString = pList->Strings[num1].Trim();
            Form1->YD_ADOTable->FieldByName("应扫数量")->AsFloat = kc;
            Form1->YD_ADOTable->FieldByName("已扫数量")->AsFloat = 0;
            Form1->YD_ADOTable->FieldByName("时间")->AsString=Now().FormatString("yyyy-mm-dd");
            Form1->YD_ADOTable->FieldByName("员工编号")->AsString = "";
            Form1->YD_ADOTable->Post();
         }
         else
         {
            str="";
            str=String().sprintf("UPDATE YD SET  应扫数量 = %f , 时间 =  \"%s\"  WHERE 条码 like \"%s\" AND 单据 like \"%s\""
                                 ,kc+Form1->Search_ADOQuery->FieldByName("应扫数量")->AsFloat
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
    Form1->YD_ADOQuery->SQL->Add("SELECT * FROM 验单");
    Form1->YD_ADOQuery->Active= true;
    MessageDlg("导入完成",mtInformation,TMsgDlgButtons()<<mbOK,0);

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

