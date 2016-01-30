//---------------------------------------------------------------------------

#include <vcl.h>
#include <inifiles.hpp>
#pragma hdrstop

#include "Unit38.h"
#include "Unit4.h"
#include "Unit34.h"
#include "Unit6.h"
#include "Unit9.h"
#include "Unit1.h"
#include "Unit14.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm38 *Form38;
//---------------------------------------------------------------------------
__fastcall TForm38::TForm38(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------




void __fastcall TForm38::Button1Click(TObject *Sender)
{
    Form4->BitBtn6->Visible=true;
    Form4->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm38::Button2Click(TObject *Sender)
{
    Form6->BitBtn6->Visible=true;
    Form6->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm38::Button3Click(TObject *Sender)
{
    Form34->BitBtn1->Visible=true;
    Form34->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm38::Button4Click(TObject *Sender)
{
    Form9->BitBtn3->Visible=true;
    Form9->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm38::Edit1Change(TObject *Sender)
{
    TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
    ini-> WriteString( "Sys", "Server-RSname", Edit1->Text.Trim());
    delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TForm38::Edit2Change(TObject *Sender)
{
     TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
     ini-> WriteString( "Sys", "Server-RSIP", Edit2->Text.Trim());
     delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TForm38::Edit3Change(TObject *Sender)
{
     TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
     ini-> WriteString( "Sys", "Server-RSPORT", Edit3->Text.Trim());
     delete ini;
}
//---------------------------------------------------------------------------
void __fastcall TForm38::FormShow(TObject *Sender)
{
     TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
     Edit1->Text=ini-> ReadString( "Sys", "Server-RSname", "RS");
     Edit2->Text=ini-> ReadString( "Sys", "Server-RSIP", "127.0.0.1");
     Edit3->Text=ini-> ReadString( "Sys", "Server-RSPORT", "10000");

     delete ini;
}
 //---------------------------------------------------------------------------------
unsigned int crc(unsigned char * InData,unsigned int length)
{

static unsigned char cst_H[16]=
   {0x00,0x10,0x20,0x30,0x40,0x50,0x60,0x70,
    0x81,0x91,0xa1,0xb1,0xc1,0xd1,0xe1,0xf1
   };
static unsigned char cst_L[16]=
   {0x00,0x21,0x42,0x63,0x84,0xa5,0xc6,0xe7,
    0x08,0x29,0x4a,0x6b,0x8c,0xad,0xce,0xef
   };

 unsigned char j;
 unsigned int i;
 unsigned char kh,kl;

 if(length==0) return(0);

 kh=*InData;
 if(length>1)  kl=*(InData+1);
 else          kl=0;

for(i=0;i<length;i++)
  {
   j= kh/16;

   kh=kh*16;
   kh=kh+(kl/16);

   kl=kl*16;
   if( (i+2)<length )  kl=kl+ (*(InData+i+2)/16);

   kh=kh^cst_H[j];
   kl=kl^cst_L[j];

   j= kh/16;

   kh=kh*16;
   kh=kh+(kl/16);

   kl=kl*16;
   if( (i+2)<length )  kl=kl+ (*(InData+i+2)&0x0F);

   kh=kh^cst_H[j];
   kl=kl^cst_L[j];
  }
return(kh*256+kl);
}
//---------------------------------------------------------------------------

String Send(String str)
{
            char splitcom1[3];
            memset(splitcom1,0,3);
            splitcom1[0]=0xA1;splitcom1[1]=0xF5;

            char splitcom2[3];
            memset(splitcom2,0,3);
            splitcom2[0]=0xA1;splitcom2[1]=0xF6;

            int crc_i;
            unsigned long lrc;
            str = str + String(splitcom1);
            //校验
            crc_i= crc(str.c_str(),str.Length());
            crc_i=crc_i%99;
            str = str + String(splitcom2) + String().sprintf("%.2d",crc_i) + String(splitcom2);
            //WriteFile(wComm,str.c_str(),str.Length(),&lrc,NULL);
           // ServerSocket1->Socket->Connections[0]->SendText(str);
           return str;

}
//----------------------------------------------------------------------------
void __fastcall TForm38::Timer1Timer(TObject *Sender)
{
      char splitcom1[3];
      memset(splitcom1,0,3);
      splitcom1[0]=0xA1;splitcom1[1]=0xF5;

      String sendstr = "";
      String buf="";

      if(TBdata=="1")//发送基本资料数据
      {
          String inf1=" ";String inf2=" ";String inf3=" ";String inf4=" ";String inf5=" ";
          String inf6=" ";String inf7=" ";String inf8=" ";String inf9=" ";String inf10=" ";
          String inf11=" ";

          if(Form1->ADOQuery1->FieldByName("条码")->AsString.Trim().Trim().Length()!=0)inf1=Form1->ADOQuery1->FieldByName("条码")->AsString.Trim().Trim();
          if(Form1->ADOQuery1->FieldByName("名称")->AsString.Trim().Trim().Length()!=0)inf2=Form1->ADOQuery1->FieldByName("名称")->AsString.Trim().Trim();
          if(Form1->ADOQuery1->FieldByName("货号")->AsString.Trim().Trim().Length()!=0)inf3=Form1->ADOQuery1->FieldByName("货号")->AsString.Trim().Trim();
          if(Form1->ADOQuery1->FieldByName("规格")->AsString.Trim().Trim().Length()!=0)inf4=Form1->ADOQuery1->FieldByName("规格")->AsString.Trim().Trim();
          if(Form1->ADOQuery1->FieldByName("型号")->AsString.Trim().Trim().Length()!=0)inf5=Form1->ADOQuery1->FieldByName("型号")->AsString.Trim().Trim();
          if(Form1->ADOQuery1->FieldByName("进价")->AsString.Trim().Trim().Length()!=0)inf6=Form1->ADOQuery1->FieldByName("进价")->AsString.Trim().Trim();
          if(Form1->ADOQuery1->FieldByName("售价")->AsString.Trim().Trim().Length()!=0)inf7=Form1->ADOQuery1->FieldByName("售价")->AsString.Trim().Trim();
          if(Form1->ADOQuery1->FieldByName("单位")->AsString.Trim().Trim().Length()!=0)inf8=Form1->ADOQuery1->FieldByName("单位")->AsString.Trim().Trim();
          if(Form1->ADOQuery1->FieldByName("备注一")->AsString.Trim().Trim().Length()!=0)inf9=Form1->ADOQuery1->FieldByName("备注一")->AsString.Trim().Trim();
          if(Form1->ADOQuery1->FieldByName("备注二")->AsString.Trim().Trim().Length()!=0)inf10=Form1->ADOQuery1->FieldByName("备注二")->AsString.Trim().Trim();
          if(Form1->ADOQuery1->FieldByName("备注三")->AsString.Trim().Trim().Length()!=0)inf11=Form1->ADOQuery1->FieldByName("备注三")->AsString.Trim().Trim();

          buf=String().sprintf("C%.2dRT,UD|%s,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s ,%s\r",runningnum,inf1,inf2,inf3,inf4,inf5,inf6,inf7,inf8,inf9,inf10,inf11);

          StatusBar1->Panels->Items[0]->Text="发送数据： " + String(Form38->sendnum+1);
          Form14->StatusBar1->Panels->Items[0]->Text="发送数据： " + String(Form38->sendnum+1);
      }
      else if(TBdata=="2")//发送入库数据
      {
          buf=String().sprintf("C%.2dRT,RK-%s-%s|%s,%s,%s,%s\r",runningnum,Form1->RK_ADOQuery->FieldByName("入库单据")->AsString.Trim(),Form1->RK_ADOQuery->FieldByName("入库仓库")->AsString.Trim(),Form1->RK_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->RK_ADOQuery->FieldByName("入库数量")->AsString.Trim(),Form1->RK_ADOQuery->FieldByName("入库时间")->AsString.Trim(),Form1->RK_ADOQuery->FieldByName("员工编号")->AsString.Trim());

          StatusBar1->Panels->Items[0]->Text="发送数据： " + String(Form38->sendnum+1);
          Form4->StatusBar1->Panels->Items[0]->Text="发送数据： " + String(Form38->sendnum+1);
      }
      else if(TBdata=="3")//发送出库数据
      {
          buf=String().sprintf("C%.2dRT,CK-%s-%s|%s,%s,%s,%s,%s\r",runningnum,Form1->CK_ADOQuery->FieldByName("出库单据")->AsString.Trim(),Form1->CK_ADOQuery->FieldByName("出库仓库")->AsString.Trim(),Form1->CK_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->CK_ADOQuery->FieldByName("出库数量")->AsString.Trim(),Form1->CK_ADOQuery->FieldByName("出库时间")->AsString.Trim(),Form1->CK_ADOQuery->FieldByName("员工编号")->AsString.Trim(),Form1->CK_ADOQuery->FieldByName("售价")->AsString.Trim());

          StatusBar1->Panels->Items[0]->Text="发送数据： " + String(Form38->sendnum+1);
          Form6->StatusBar1->Panels->Items[0]->Text="发送数据： " + String(Form38->sendnum+1);
      }
      else if(TBdata=="4")//发送盘点数据
      {
          buf=String().sprintf("C%.2dRT,PD-%s-%s|%s,%s,%s,%s\r",runningnum,Form1->PD_ADOQuery->FieldByName("单号")->AsString.Trim(),Form1->PD_ADOQuery->FieldByName("仓库")->AsString.Trim(),Form1->PD_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->PD_ADOQuery->FieldByName("盘点库存")->AsString.Trim(),Form1->PD_ADOQuery->FieldByName("盘点时间")->AsString.Trim(),Form1->PD_ADOQuery->FieldByName("员工编号")->AsString.Trim());

          StatusBar1->Panels->Items[0]->Text="发送数据： " + String(Form38->sendnum+1);
          Form34->StatusBar1->Panels->Items[0]->Text="发送数据： " + String(Form38->sendnum+1);
      }
      else if(TBdata=="5")//发送移库数据
      {
          buf=String().sprintf("C%.2dRT,YK-%s-%s-%s|%s,%s,%s,%s\r",runningnum,Form1->YK_ADOQuery->FieldByName("移库单号")->AsString.Trim(),Form1->YK_ADOQuery->FieldByName("原仓库")->AsString.Trim(),Form1->YK_ADOQuery->FieldByName("目的仓库")->AsString.Trim(),Form1->YK_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->YK_ADOQuery->FieldByName("数量")->AsString.Trim(),Form1->YK_ADOQuery->FieldByName("移库时间")->AsString.Trim(),Form1->YK_ADOQuery->FieldByName("员工编号")->AsString.Trim());

          StatusBar1->Panels->Items[0]->Text="发送数据： " + String(Form38->sendnum+1);
          Form9->StatusBar1->Panels->Items[0]->Text="发送数据： " + String(Form38->sendnum+1);
      }
      else
      return;
     /* else if(TBdata=="6")//发送验单数据
      {
         //验单数据先不同步
      }*/

      sendstr = String().sprintf("talk-%s%s%s%s%s",Edit1->Text.Trim(),String(splitcom1),"COMPUTER",String(splitcom1),buf,String(splitcom1));
      ClientSocket1->Socket->SendText(Send(sendstr));
}

void ResolveString(String Source, TStringList *Aim, String flag)
 {
     const int Count = Source.Length();
     int site = 1, Len = 0;//当前截取的位置
     String astrTemp, OutStr;

    Aim->Clear();
     //测试要分解为多少各子串
     for (int i = 1; i <= Count; i++)
         if (Source.SubString(i,2) == flag) {Len++;i++;}

    //开始攫取字符
     for (int i = 0; i < Len; i++)//数组层循环
     {
         for (; site <= Count; site++)//字符层循环
         {
             astrTemp = Source.SubString(site,2); //获取一个字符
             if (astrTemp ==  flag)
             {   /*如果发现当前取到的为分隔符，那么条过分隔符，结束循环
                   并开始下一组字符串的截取*/
                 site++;
                 site++;
                 break;
             }
             OutStr = OutStr + astrTemp.SubString(0,1);//合并成字符串
         }
         Aim->Add(OutStr);
         OutStr = "";
     }
 }

//---------------------------------------------------------------------------

void __fastcall TForm38::Button5Click(TObject *Sender)
{
    Form14->BitBtn6->Visible=true;
    Form14->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm38::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
    //   校验数据是否成功，如果成功，流水号处理，以及next数据
    //int LinkNum=0;
   String sendstr = "";
   String str="";
   TStringList *revv=new TStringList();
 //  TStringList *splitString =new TStringList();
   char splitcom1[3];
   memset(splitcom1,0,3);
   splitcom1[0]=0xA1;splitcom1[1]=0xF5;

   char splitcom2[3];
   memset(splitcom2,0,3);
   splitcom2[0]=0xA1;splitcom2[1]=0xF6;

   String szString=Socket->ReceiveText();

   if(IPTB=="0")
   {
       IPTB="1";
       Form38->ClientSocket1->Active=false;
       this->StatusBar1->Panels->Items[0]->Text="";

       revv->Text="";
       ResolveString(szString,revv,String(splitcom2));

       int len= crc(revv->Strings[0].c_str(),revv->Strings[0].Length());
       len=len%99;
       int crc_i = len;
       if (crc_i !=revv->Strings[1].ToInt())
       {
           MessageDlg("IP网络同步失败",mtInformation,TMsgDlgButtons()<<mbOK,0);
           return;
       }

       if(memcmp(revv->Strings[0].c_str(),"未注册",6)==0)
       {
           MessageDlg("账号未注册，请先购买IP同步账号",mtInformation,TMsgDlgButtons()<<mbOK,0);
           return;
       }
       else if(memcmp(revv->Strings[0].c_str(),"密码错误",8)==0)
       {
           MessageDlg("密码错误，同步失败",mtInformation,TMsgDlgButtons()<<mbOK,0);
           return;
       }
       else
       {
           Edit2->Text=revv->Strings[0].Trim().SubString(0,revv->Strings[0].Trim().Length()-2);
           MessageDlg("IP同步成功",mtInformation,TMsgDlgButtons()<<mbOK,0);
           return;
       }

   }

   int length=szString.Length();

  if(szString.SubString(0,4)!="talk"||szString.SubString(length-1,2)!=String(splitcom2)||szString.SubString(length-5,2)!=String(splitcom2))
   {
          return;
   }
//校验
   int len=0;
   int crc_i=0;

   revv->Text="";
   ResolveString(szString,revv,String(splitcom2));

   len= crc(revv->Strings[0].c_str(),revv->Strings[0].Length());
   len=len%99;
   crc_i = len;
   if (crc_i !=revv->Strings[1].ToInt())
   {
           return;
   }


   //看流水号是否成功，如果不成功，说明错误，要返回
   revv->Text="";
   ResolveString(szString,revv,String(splitcom1));
   if(runningnum>=20)
   {
      if(revv->Strings[2].Trim().ToInt()!=1)
      return;
   }
   else
   {
      if(revv->Strings[2].Trim().ToInt()!=runningnum+1)
      return;
   }



   if(runningnum>=20)runningnum=1;
   else
   runningnum++;

   if(TBdata=="1") //基本资料
   {
        Form38->sendnum++;
        if(Form38->sendnum<Form1->ADOQuery1->RecordCount)
        {
            Form1->ADOQuery1->Next();
        }
        else
        {
            //完成
            Timer1->Enabled=false;
            MessageDlg("基本资料同步完成",mtInformation,TMsgDlgButtons()<<mbOK,0);
            StatusBar1->Panels->Items[0]->Text="";
            Form14->StatusBar1->Panels->Items[0]->Text="";
            Form38->TBdata="0";
            Form14->DBGrid1->Enabled=true;
        }
   }
   else if(TBdata=="2") //入库资料
   {
        Form38->sendnum++;
        if(Form38->sendnum<Form1->RK_ADOQuery->RecordCount)
        {
            Form1->RK_ADOQuery->Next();
        }
        else
        {
            //完成
            Timer1->Enabled=false;
            MessageDlg("入库数据同步完成",mtInformation,TMsgDlgButtons()<<mbOK,0);
            StatusBar1->Panels->Items[0]->Text="";
            Form4->StatusBar1->Panels->Items[0]->Text="";
            Form38->TBdata="0";
            Form4->DBGrid1->Enabled=true;
        }
   }
   else if(TBdata=="3") //入库资料
   {
        Form38->sendnum++;
        if(Form38->sendnum<Form1->CK_ADOQuery->RecordCount)
        {
            Form1->CK_ADOQuery->Next();
        }
        else
        {
            //完成
            Timer1->Enabled=false;
            MessageDlg("出库数据同步完成",mtInformation,TMsgDlgButtons()<<mbOK,0);
            StatusBar1->Panels->Items[0]->Text="";
            Form6->StatusBar1->Panels->Items[0]->Text="";
            Form38->TBdata="0";
            Form6->DBGrid1->Enabled=true;
        }
   }
    else if(TBdata=="4")
   {
        Form38->sendnum++;
        if(Form38->sendnum<Form1->PD_ADOQuery->RecordCount)
        {
            Form1->PD_ADOQuery->Next();
        }
        else
        {
            //完成
            Timer1->Enabled=false;
            MessageDlg("盘点数据同步完成",mtInformation,TMsgDlgButtons()<<mbOK,0);
            StatusBar1->Panels->Items[0]->Text="";
            Form34->StatusBar1->Panels->Items[0]->Text="";
            Form38->TBdata="0";
            Form34->DBGrid1->Enabled=true;
        }
   }
   else if(TBdata=="5")
   {
        Form38->sendnum++;
        if(Form38->sendnum<Form1->YK_ADOQuery->RecordCount)
        {
            Form1->YK_ADOQuery->Next();
        }
        else
        {
            //完成
            Timer1->Enabled=false;
            MessageDlg("移库数据同步完成",mtInformation,TMsgDlgButtons()<<mbOK,0);
            StatusBar1->Panels->Items[0]->Text="";
            Form9->StatusBar1->Panels->Items[0]->Text="";
            Form38->TBdata="0";
            Form9->DBGrid1->Enabled=true;
        }
   }
   else if(TBdata=="6")
   {
        Form38->sendnum++;
        if(Form38->sendnum<Form1->YD_ADOQuery->RecordCount)
        {
            Form1->YD_ADOQuery->Next();
        }
        else
        {
            //完成
            Timer1->Enabled=false;
            MessageDlg("验单数据同步完成",mtInformation,TMsgDlgButtons()<<mbOK,0);
            StatusBar1->Panels->Items[0]->Text="";
            Form4->StatusBar1->Panels->Items[0]->Text="";
            Form38->TBdata="0";
        }
   }
        
}
//---------------------------------------------------------------------------

void __fastcall TForm38::FormCreate(TObject *Sender)
{
    Form38->TBdata="0";
    Form38->IPTB="1";
}
//---------------------------------------------------------------------------

void __fastcall TForm38::BitBtn1Click(TObject *Sender)
{
        //  MessageDlg(IPTB,mtInformation,TMsgDlgButtons()<<mbOK,0);

          if(IPTB=="1")
          {

              if(Form38->ClientSocket1->Active==false)
              {
                  try
                  {
                      Form38->ClientSocket1->Host="210.209.84.163";
                      Form38->ClientSocket1->Port=50000;
                      Form38->ClientSocket1->Active=true;
                      IPTB="0";
                  }
                  catch(...)
                  {
                      MessageDlg("同步失败，服务器没有开启",mtInformation,TMsgDlgButtons()<<mbOK,0);
                      return;
                  }
              }
              else
              {
                  MessageDlg("客户端已经连接服务器，不可以IP同步",mtInformation,TMsgDlgButtons()<<mbOK,0);
                  return;
              }
          }

          if(IPTB=="0")
          {
	
	              //登录服务器
	      String name="";
	      String password="";
NM:
	      name="";
	      if(InputQuery("IP网络同步","请输入同步账号:           ",name))
	      {
	                if(name.Length() ==0)
	                {
	                   return;
	                }
	       }
	       else
	       {
	                   return;
	       }
	
	       password="";
	       if(InputQuery("IP网络同步","请输入密码:           ",password))
	       {
	                if(password.Length() ==0)
	                {
	                   goto NM;
	                }
	       }
	       else
	       {
	                  goto NM;
	       }




              this->StatusBar1->Panels->Items[0]->Text="正在进行IP同步，请稍等";
             // delay(1000);

              char splitcom1[3];
              memset(splitcom1,0,3);
              splitcom1[0]=0xA1;splitcom1[1]=0xF5;



              String buf=String().sprintf("%s%s%s",name,String(splitcom1),password);

              String sendstr = String().sprintf("talk-%s%s%s%s%s",Edit1->Text.Trim(),String(splitcom1),"search",String(splitcom1),buf,String(splitcom1));
              ClientSocket1->Socket->SendText(Send(sendstr));
          }

          return;        
}
//---------------------------------------------------------------------------

