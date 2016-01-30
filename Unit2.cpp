//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <FileCtrl.hpp>
#include   <inifiles.hpp>
#include <registry.hpp>

#include "Unit2.h"
#include "Unit1.h"
#include "Unit3.h"
#include "Unit4.h"
#include "Unit5.h"
#include "Unit6.h"
#include "Unit7.h"
#include "Unit8.h"
#include "Unit9.h"
#include "Unit10.h"
#include "Unit12.h"
#include "Unit11.h"
#include "Unit13.h"
#include "Unit14.h"
#include "Unit15.h"
#include "Unit16.h"
#include "Unit17.h"
#include "Unit18.h"
#include "Unit19.h"
#include "Unit20.h"
#include "Unit21.h"
#include "Unit22.h"
#include "Unit23.h"
#include "Unit25.h"
#include "Unit27.h"
#include "Unit34.h"
#include "Unit37.h"
#include "Unit38.h"
#include "Unit39.h"
#include "Unit40.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

TStringList *wifelessData=new TStringList();
TStringList *wifelessDataPL=new TStringList();
//TStringList *INFList=new TStringList();


TStringList *sourcename=new TStringList();
TStringList *runningnum=new TStringList();
TStringList *startpovit=new TStringList();




//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
    if(Form14->DBGrid1->DataSource->DataSet->State==2||Form14->DBGrid1->DataSource->DataSet->State==3)
    Form14->DBGrid1->DataSource->DataSet->Post();

    if(Form13->DBGrid1->DataSource->DataSet->State==2||Form13->DBGrid1->DataSource->DataSet->State==3)
    Form13->DBGrid1->DataSource->DataSet->Post();

    Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N11Click(TObject *Sender)
{
    Form3->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N12Click(TObject *Sender)
{
    Form4->BitBtn6->Visible=false;
    Form4->Show();
}
//---------------------------------------------------------------------------



void __fastcall TForm2::N13Click(TObject *Sender)
{
   Form5->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N14Click(TObject *Sender)
{
   Form6->BitBtn6->Visible=false;
   Form6->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::N3Click(TObject *Sender)
{
    if(Form1->KCshow=="show")Form12->Show();
    else
    ShowMessage("您没有权限查看库存！");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N15Click(TObject *Sender)
{
    Form8->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N16Click(TObject *Sender)
{
    Form9->BitBtn3->Visible=false;
    Form9->Show();
}
//---------------------------------------------------------------------------



void __fastcall TForm2::N18Click(TObject *Sender)
{
    Form11->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N19Click(TObject *Sender)
{
    Form10->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N22Click(TObject *Sender)
{
    Form23->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N23Click(TObject *Sender)
{
    Form25->Show();
   
}
//---------------------------------------------------------------------------




void __fastcall TForm2::N6Click(TObject *Sender)
{
    Form14->BitBtn6->Visible=false;
    Form14->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N7Click(TObject *Sender)
{
    Form13->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N9Click(TObject *Sender)
{
    Form15->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N10Click(TObject *Sender)
{
    Form16->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N21Click(TObject *Sender)
{
    Form17->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::N20Click(TObject *Sender)
{
    Form18->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormShow(TObject *Sender)
{
     Label4->Caption=Form1->infshow1+"   ";
     Label6->Caption=Form1->infshow2+"   ";
     Label7->Caption=Form1->infshow3+"   ";
     Label8->Caption=Form1->infshow4+"   ";
     Label9->Caption=Form1->infshow5+"   ";
     Label10->Caption=Form1->infshow6+"   ";
     Label11->Caption=Form1->infshow7+"   ";
     Label12->Caption=Form1->infshow8+"   ";
     Label13->Caption=Form1->infshow9+"   ";
     Label14->Caption=Form1->infshow10+"   ";
     Label15->Caption=Form1->infshow11+"   ";


     TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
     ServerSocket1->Port=ini->ReadString("Sys","port","10000").ToInt();
     PORT->Text=ini->ReadString("Sys","port","10000");
     Edit1->Text=ini-> ReadString( "Sys", "RSname", "RS");

     ServerSocket1->Active=true;
     this->StatusBar1->Panels->Items[0]->Text="服务器已经开启，正在监听...";

     delete ini;

    //获取局域网ip
    WSADATA Data_WSA;
    int Result_WSAStartup = 1;

    hostent *P_Host = NULL;
    char Computer_Name[128] = "";
    Result_WSAStartup = WSAStartup(MAKEWORD(2, 2), &Data_WSA);
     if (Result_WSAStartup != 0)//无错返回0
     {
         MessageBox(NULL, "本机故障，无法启动网络服务，请联系网络管理员","提示",MB_ICONASTERISK);
         return ;
     }
     gethostname(Computer_Name, 128);//获取指定计算机的名字
     if(Computer_Name[0] == '\0')
     {
         MessageBox(NULL, "本机网络故障，无法接入局域网，请联系网络管理员","提示",MB_ICONASTERISK);
         return ;
     }
     //Memo1->Text = s;
     P_Host = gethostbyname(Computer_Name);
     if(P_Host == NULL)
     {
         //Memo1->Text = "p NULL ";
         MessageBox(NULL, "本机网络故障，无法获取IP，请联系管理员","提示",MB_ICONASTERISK);
         return ;
     }
     String IP_Host=inet_ntoa(*((in_addr *)P_Host->h_addr));//获取指定计算机的IP地址

     P_Host = NULL;
     WSACleanup();//完成对WSAStartup()的调用
     IP->Text=IP_Host;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::ServerSocket1ClientError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
      switch( ErrorCode )
     {
       case 10053: Socket->Close();
                   break;
     }
 
     ErrorCode = 0;
}
//---------------------------------------------------------------------------
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


unsigned int crcx(unsigned char * InData,unsigned int length)
{

  int num1=0;
  for(unsigned int i=0;i<length;i++)
  {
    num1=num1^InData[i];
  }
  return num1;
}
//--------------------------------------------------------------------------------------
void WriteKey(String inbuff)
{
     int j=0;
     /*小键盘上的数字键，一定要用这个才能打得出内码*/
    int value[10]={VK_NUMPAD0,VK_NUMPAD1,VK_NUMPAD2,VK_NUMPAD3,VK_NUMPAD4,VK_NUMPAD5,VK_NUMPAD6,VK_NUMPAD7,VK_NUMPAD8,VK_NUMPAD9} ;
    bool bShift = false;
    char s[3]={0};      //用来存放中文字的
    int length =strlen(inbuff.c_str());
    for(int index = 0;index < length;index+=j)
    {
        int val = inbuff.c_str()[index];
        if(val>=0 && val<=127)
       {
         // ShowMessage(inbuff.c_str()[index]);
         j=1;
        if(val >= 97 && val <= 122)    //小写a-z
        {
           val -= 32;
           bShift = false;
        }
        else if(val >= 65 && val <= 90) //大写A-Z
        {
            bShift = true;
        }
        else if(val >= 48 && val <= 57) //数字0-9
        {
             bShift = false;
        }
        //特殊符号
        else if((val>=33&&val<=43)||val==58||val==60||(val>=62&&val<=90)||(val>=94&&val<=95)||(val>=123&&val<=126))
         {
               bShift = true;
         }
         else
         {

                bShift = false;
         }

      if(bShift)


            keybd_event(VK_SHIFT,0,KEYEVENTF_EXTENDEDKEY|0,0);
        keybd_event(VkKeyScan(val),MapVirtualKey(val,0),0,0);
        keybd_event(VkKeyScan(val),MapVirtualKey(val,0),KEYEVENTF_KEYUP,0);

        if(bShift)
            keybd_event(VK_SHIFT,0,KEYEVENTF_EXTENDEDKEY|KEYEVENTF_KEYUP,0);
      }else  //打印中文的
      {
         j=2;
         s[0]=inbuff.c_str()[index], s[1]=inbuff.c_str()[index+1];   //获取中文字符

         String str=String(((BYTE)s[0]<<8)+(BYTE)s[1]);   //转化成内码
         keybd_event(VK_MENU, MapVirtualKey(VK_MENU, 0), 0, 0);    //开始打印
         for(int i=0;i<strlen(str.Trim().c_str());i++)
         {
            int v=str.Trim().c_str()[i]-'0';
            keybd_event(value[v], MapVirtualKey(value[v], 0), 0, 0);
            keybd_event(value[v], MapVirtualKey(value[v], 0), KEYEVENTF_KEYUP, 0);
         }
            keybd_event(VK_MENU, MapVirtualKey(VK_MENU, 0), KEYEVENTF_KEYUP, 0);
      }
    }
}

//---------------------------------------------------------------------------------------------
String Send(String str,int android)
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
            if(android==0)
            crc_i= crc(str.c_str(),str.Length());
            else  crc_i= crcx(str.c_str(),str.Length());
            crc_i=crc_i%99;
            str = str + String(splitcom2) + String().sprintf("%.2d",crc_i) + String(splitcom2);
            //WriteFile(wComm,str.c_str(),str.Length(),&lrc,NULL);
           // ServerSocket1->Socket->Connections[0]->SendText(str);
           return str;

}

static unsigned char Encryptedcard[16][16]={
					   {0xa3,0xe4,0x9b,0x2e,0x3d,0x88,0x5b,0x6a,0x72,0x88,0x59,0x27,0xf6,0x62,0x08,0xbb},
                                           {0xb3,0x55,0x0b,0x85,0xe8,0x4b,0x7f,0x15,0xc6,0x96,0x23,0x6c,0x36,0xdd,0x5e,0xf7},
                                           {0xab,0x66,0x06,0xc7,0x54,0xf8,0x27,0x8b,0x35,0xaf,0x48,0xe7,0xbe,0xd9,0x27,0x9d},
	                                   {0x35,0x22,0xa8,0x45,0x56,0x68,0x19,0xb6,0xc4,0xf8,0x88,0x3e,0x9d,0xdf,0xeb,0x0a},
                                           {0x6c,0x05,0x63,0xa7,0x28,0xc7,0x7f,0xe5,0x1a,0xd7,0x86,0xf6,0x95,0x3e,0xb8,0x4d},
					   {0x95,0xb6,0xa7,0x8c,0x27,0x7e,0x6f,0xc8,0x52,0x49,0x37,0xe5,0x23,0x12,0x03,0xf8},
				           {0x56,0xc3,0x64,0x46,0x76,0x8b,0x94,0x2c,0xa9,0xb4,0x3d,0xc7,0xfe,0x1f,0xd8,0xe4},
                                           {0xc3,0x78,0x1f,0x3d,0x88,0x16,0x7c,0x4f,0xce,0x54,0x93,0xa6,0xb7,0xc3,0xd2,0xe3},
                                           {0x0c,0xf2,0x77,0xcf,0x69,0x5c,0xef,0x47,0xb4,0x35,0x27,0xd4,0x86,0xe3,0xf8,0x15},
					   {0xd7,0x57,0xa3,0xb4,0xc7,0xf7,0xe6,0xdd,0x2d,0x4e,0x1c,0x0f,0x9b,0x69,0x70,0x8a},
					   {0x35,0x4a,0x0c,0x2d,0x1a,0x0b,0xee,0x9f,0xd1,0x86,0x75,0x66,0x5d,0xf5,0xa6,0x48},
					   {0xf6,0x97,0x17,0x2d,0x3e,0x4f,0x5a,0x6b,0x78,0x58,0x95,0xa7,0xb4,0xc4,0xd3,0xe3},
					   {0x8f,0xd4,0x04,0xc7,0x56,0xf5,0x28,0x88,0x37,0xa7,0x98,0xe8,0xbf,0xd1,0x7d,0x9e},
                                           {0xe4,0x6e,0xd8,0x85,0x77,0xaa,0xb0,0x39,0xc6,0xb6,0x68,0x2c,0xf7,0xa5,0x46,0x35},
					   {0xe6,0x47,0xa3,0x0b,0x86,0xe7,0x4c,0x75,0x16,0xc7,0x97,0x29,0x7e,0x8e,0xde,0x5f},
                                           {0x43,0x88,0x1a,0xe6,0x4d,0x97,0x25,0x8c,0x5f,0xde,0x68,0x33,0x06,0x72,0x18,0x8e} };


void __fastcall TForm2::ServerSocket1ClientRead(TObject *Sender,
      TCustomWinSocket *Socket)
{
     // Memo1->Lines->Add(Socket->ReceiveText());
     //ServerSocket1->Socket->Connections[0]->SendText("111");

     //在此处写接收协议===================================================

      TStringList *revv=new TStringList();
      TStringList *splitString =new TStringList();

      TStringList *showinf1 =new TStringList();
      TStringList *showinf2 =new TStringList();
      String barcode="";
      TStringList *bList =new TStringList();
     // TStringList *barlist =new TStringList();
      //TStringList *numlist =new TStringList();
      int AddData=1;

      int android=0;  //0盘点机   1手机

    //  int crc_i;
            unsigned long lrc;


      String wifelessstr="";


      int LinkNum=0;
      int SourceNameNum=0;


     String szString=Socket->ReceiveText();
     String szStringIndex;
     String ip=Socket->RemoteAddress;
     String port=Socket->RemotePort;

     String RSname="";

     RSname=Edit1->Text.Trim();

     int length=szString.Length();
     char splitcom1[3];
     memset(splitcom1,0,3);
     splitcom1[0]=0xA1;splitcom1[1]=0xF5;

     char splitcom2[3];
     memset(splitcom2,0,3);
     splitcom2[0]=0xA1;splitcom2[1]=0xF6;

  //REVLIST->Items->Add(szString);
  //SendMessage(REVLIST-> Handle,   WM_VSCROLL,   SB_BOTTOM,   NULL);

     if(szString.SubString(0,4)=="talk"&&
    (
    (szString.SubString(length-1,2)==String(splitcom2)&&szString.SubString(length-5,2)==String(splitcom2))||
    (szString.SubString(length-2,2)==String(splitcom2)&&szString.SubString(length-6,2)==String(splitcom2))
    )
    )
    {

    }
    else return;

      AddData=1;


   //  try
    // {
                String sendstr = "";
                int len=0;
                int crc_i=0;

                ResolveString(szString,revv,String(splitcom2));

                if(szString.SubString(0,11)!="talkandroid")
                {
                    android=0;
                    len= crc(revv->Strings[0].c_str(),revv->Strings[0].Length());
                }
                else
                {
                    android=1;
                    len= crcx(revv->Strings[0].c_str(),revv->Strings[0].Length());
                }
	              len=len%99;
                crc_i = len;
                if (crc_i !=revv->Strings[1].ToInt())
                {
                    MessageBox(NULL, "校验失败","提示",MB_ICONASTERISK);
                    return;//校验失败，返回
                }

                splitString->Text="";
                ResolveString(szString,splitString,String(splitcom1));

                //看名字是否正确
                bList->Text="";
                Form1->CrnListSplitString(splitString->Strings[0]+"-",bList,'-');
                if(bList->Strings[1].Trim()!=RSname) //名字不正确，返回
                return;

                //检验是否是已经是记录过的

                int i = 0;
              //  int j=0;

                if(splitString->Strings[1]=="COMPUTER")
                {
                    splitString->Strings[1]=Socket->RemoteAddress+":"+Socket->RemotePort;
                }

                for (i = 0; i < sourcename->Count; i++) //查是否有分配空间
                {
                        if (sourcename->Strings[i] == splitString->Strings[1])
                        {
                          SourceNameNum=i;
                          break;
                        }
                 }
                 if(i == sourcename->Count)
                 {
                        SourceNameNum= sourcename->Count;
                        sourcename->Add(splitString->Strings[1]);
                        runningnum->Add("0");
                        startpovit->Add("0");
                        ListBox1->Items->Add(splitString->Strings[1]);

                 }


                     // 定位客户端
                 for(LinkNum=ServerSocket1->Socket->ActiveConnections-1;LinkNum>=0;LinkNum--)
                 {
                         if(ServerSocket1->Socket->Connections[LinkNum]->RemoteAddress==ip&&ServerSocket1->Socket->Connections[LinkNum]->RemotePort==port)
                         {

                             break;
                         }
                 }

                 if(LinkNum==ServerSocket1->Socket->ActiveConnections)
                 {
                        //失去了联系，返回
                        MessageBox(NULL, "失去联系","提示",MB_ICONASTERISK);
                        return;
                 }

                 if (splitString->Strings[2] == "LOGIN")
                 {
                        //校验密码是否正确
                        char cDrive='D';
                        AnsiString StrDrive=cDrive;  StrDrive+=":";
                        char VolName[200],FSName[50];
                        DWORD dwVolSer,lpMaxComLen,lpFSFlags;

                        int serial_number[6];
                        long original=0;



                        if( GetVolumeInformation(StrDrive.c_str(),VolName,200,&dwVolSer,&lpMaxComLen,&lpFSFlags,FSName,50))
                        {
                            if(dwVolSer==0)
                            original=568469;
                            else
                            original=Integer(dwVolSer);
                        }
                        else  original=658495;

                        //在此处计算序列号
                        serial_number[0]=original%99;
                        serial_number[1]=original%239;
                        serial_number[2]=original%178;
                        serial_number[3]=Encryptedcard[serial_number[0]%16][serial_number[2]%16];
                        serial_number[4]=Encryptedcard[serial_number[1]%16][serial_number[3]%16];
                        serial_number[5]=Encryptedcard[serial_number[4]%16][serial_number[1]%16];
                        String XLH=String().sprintf("%.2x%.2x%.2x%.2x%.2x%.2x",serial_number[0],serial_number[3],serial_number[4],serial_number[2],serial_number[5],serial_number[1]);

                        Char serial_char[13];
                        memset(serial_char,0,sizeof(serial_char));
                        memcpy(serial_char,XLH.Trim().c_str(),12);

                        Char username_char[16];
                        memset(username_char,0x20,sizeof(username_char));
                        memcpy(&username_char[0],splitString->Strings[3].Trim().c_str(),splitString->Strings[3].Trim().Length());

                        int password_number[5];//算出4位即可，有八位密码

			password_number[0]=(Encryptedcard[(serial_char[0]+serial_char[3]+serial_char[5])%16][(serial_char[1]+serial_char[4]+serial_char[2])%16]*2
			                       +username_char[0]*1+username_char[1]*2+username_char[2]*3+username_char[3]*4+username_char[4]*5+username_char[5]*6
			                       +username_char[6]*6+username_char[7]*5+username_char[8]*4+username_char[9]*3+username_char[10]*2+username_char[11]
			                       +username_char[12]*3+username_char[13]*2+username_char[14])%153;
			password_number[1]=(Encryptedcard[(serial_char[9]+serial_char[7]+serial_char[11])%16][(serial_char[9]+serial_char[10]+serial_char[8]+
			                       Encryptedcard[(serial_char[6]+username_char[6]+username_char[8]+username_char[10])%16][(serial_char[6]+username_char[1]+username_char[3]+username_char[5])%16])%16])*8%226;
			password_number[2]=(4*password_number[0]+2*password_number[1]+serial_char[2]+username_char[0]+username_char[2]+username_char[4])%188;
			    password_number[3]=(3*password_number[0]+8*Encryptedcard[(serial_char[0]+3*serial_char[1]+serial_char[2]+username_char[5]+username_char[7]+username_char[9])%16][(serial_char[3]+serial_char[4]+6*serial_char[5]
			                        +username_char[11]+username_char[12]+username_char[14]
			                        +username_char[13]+username_char[8]+username_char[3])%16])%253;
			
		        String password=String().sprintf("%.2x%.2x%.2x%.2x",password_number[0],password_number[2],password_number[3],password_number[1]);

                        if(password==splitString->Strings[4].Trim())
                        {
                            //成功
                            sendstr = "";
                            sendstr = "talk"+String(splitcom1)+ splitString->Strings[1] +String(splitcom1)+"SUCCESSFUL";
                            ServerSocket1->Socket->Connections[LinkNum]->SendText(Send(sendstr,android));
                            return;
                        }
                        else
                        {
                           //shibai
                            sendstr = "";
                            sendstr = "talk"+String(splitcom1)+ splitString->Strings[1] +String(splitcom1)+"FALSE";
                            ServerSocket1->Socket->Connections[LinkNum]->SendText(Send(sendstr,android));
                            return;
                        }
                 }

                if (splitString->Strings[2] == "QUERY")
                {
                    //查询资料并且发送
                    // Talk^机器名^条码,资料1，资料2，资料3^+校验+
                    String inf="";
                    Form1->Search_ADOQuery->Close();
                    Form1->Search_ADOQuery->SQL->Clear();
                    Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where 条码 like \""+splitString->Strings[3].Trim()+"\"");
                    Form1->Search_ADOQuery->Active= true;


                    if(Form1->Search_ADOQuery->RecordCount==0)
                    {
                        inf=String().sprintf("%s,无--,",splitString->Strings[3].Trim());
                    }
                    else
                    {
                        if(splitString->Strings[5].Trim()=="UD"||splitString->Strings[5].Trim()=="CX")
                        {
                            if(android==0)
                            {
                                if(Form1->Pshow=="show")
                                inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",
                                             Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("名称")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("货号")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("规格")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("型号")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("进价")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("售价")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("单位")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("备注一")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("备注二")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("备注三")->AsString.Trim()
                                             );
                                  else
                                  inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",
                                             Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("名称")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("货号")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("规格")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("型号")->AsString.Trim(),
                                             "0",
                                             Form1->Search_ADOQuery->FieldByName("售价")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("单位")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("备注一")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("备注二")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("备注三")->AsString.Trim()
                                             );
                            }
                            else
                            {
                                if(Form1->Pshow=="show")
                                inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",
                                             Form1->infshow1,
                                             Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),
                                             Form1->infshow2,
                                             Form1->Search_ADOQuery->FieldByName("名称")->AsString.Trim(),
                                             Form1->infshow3,
                                             Form1->Search_ADOQuery->FieldByName("货号")->AsString.Trim(),
                                             Form1->infshow4,
                                             Form1->Search_ADOQuery->FieldByName("规格")->AsString.Trim(),
                                             Form1->infshow5,
                                             Form1->Search_ADOQuery->FieldByName("型号")->AsString.Trim(),
                                             Form1->infshow6,
                                             Form1->Search_ADOQuery->FieldByName("进价")->AsString.Trim(),
                                             Form1->infshow7,
                                             Form1->Search_ADOQuery->FieldByName("售价")->AsString.Trim(),
                                             Form1->infshow8,
                                             Form1->Search_ADOQuery->FieldByName("单位")->AsString.Trim(),
                                             Form1->infshow9,
                                             Form1->Search_ADOQuery->FieldByName("备注一")->AsString.Trim(),
                                             Form1->infshow10,
                                             Form1->Search_ADOQuery->FieldByName("备注二")->AsString.Trim(),
                                             Form1->infshow11,
                                             Form1->Search_ADOQuery->FieldByName("备注三")->AsString.Trim()
                                             );
                                  else
                                  inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",
                                             Form1->infshow1,
                                             Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),
                                             Form1->infshow2,
                                             Form1->Search_ADOQuery->FieldByName("名称")->AsString.Trim(),
                                             Form1->infshow3,
                                             Form1->Search_ADOQuery->FieldByName("货号")->AsString.Trim(),
                                             Form1->infshow4,
                                             Form1->Search_ADOQuery->FieldByName("规格")->AsString.Trim(),
                                             Form1->infshow5,
                                             Form1->Search_ADOQuery->FieldByName("型号")->AsString.Trim(),
                                             Form1->infshow6,
                                             "0",
                                             Form1->infshow7,
                                             Form1->Search_ADOQuery->FieldByName("售价")->AsString.Trim(),
                                             Form1->infshow8,
                                             Form1->Search_ADOQuery->FieldByName("单位")->AsString.Trim(),
                                             Form1->infshow9,
                                             Form1->Search_ADOQuery->FieldByName("备注一")->AsString.Trim(),
                                             Form1->infshow10,
                                             Form1->Search_ADOQuery->FieldByName("备注二")->AsString.Trim(),
                                             Form1->infshow11,
                                             Form1->Search_ADOQuery->FieldByName("备注三")->AsString.Trim()
                                             );
                            }
                        }
                        else if(splitString->Strings[5].Trim()=="RK")
                        {
                            if(Form1->Pshow=="show")
                            {
                                if(android==0)inf=String().sprintf("%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->rksendback1)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->rksendback2)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->rksendback3)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->rksendback4)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->rksendback5)->AsString.Trim());
                                else inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->rksendstring1,Form1->Search_ADOQuery->FieldByName(Form1->rksendback1)->AsString.Trim(),Form1->rksendstring2,Form1->Search_ADOQuery->FieldByName(Form1->rksendback2)->AsString.Trim(),Form1->rksendstring3,Form1->Search_ADOQuery->FieldByName(Form1->rksendback3)->AsString.Trim(),Form1->rksendstring4,Form1->Search_ADOQuery->FieldByName(Form1->rksendback4)->AsString.Trim(),Form1->rksendstring5,Form1->Search_ADOQuery->FieldByName(Form1->rksendback5)->AsString.Trim());
                            }
                            else
                            {
                                String str1="";
                                String str2="";
                                String str3="";
                                String str4="";
                                String str5="";
                                if(Form1->rksendback1=="进价")str1="0";else str1=Form1->Search_ADOQuery->FieldByName(Form1->rksendback1)->AsString.Trim();
                                if(Form1->rksendback2=="进价")str2="0";else str2=Form1->Search_ADOQuery->FieldByName(Form1->rksendback2)->AsString.Trim();
                                if(Form1->rksendback3=="进价")str3="0";else str3=Form1->Search_ADOQuery->FieldByName(Form1->rksendback3)->AsString.Trim();
                                if(Form1->rksendback4=="进价")str4="0";else str4=Form1->Search_ADOQuery->FieldByName(Form1->rksendback4)->AsString.Trim();
                                if(Form1->rksendback5=="进价")str5="0";else str5=Form1->Search_ADOQuery->FieldByName(Form1->rksendback5)->AsString.Trim();
                                if(android==0)inf=String().sprintf("%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),str1,str2,str3,str4,str5);
                                else inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->rksendstring1,str1,Form1->rksendstring2,str2,Form1->rksendstring3,str3,Form1->rksendstring4,str4,Form1->rksendstring5,str5);
                            }
                        }
                        else if(splitString->Strings[5].Trim()=="PD")
                        {
                            if(Form1->Pshow=="show")
                            {
                                if(android==0)inf=String().sprintf("%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->pdsendback1)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->pdsendback2)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->pdsendback3)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->pdsendback4)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->pdsendback5)->AsString.Trim());
                                else inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->pdsendstring1,Form1->Search_ADOQuery->FieldByName(Form1->pdsendback1)->AsString.Trim(),Form1->pdsendstring2,Form1->Search_ADOQuery->FieldByName(Form1->pdsendback2)->AsString.Trim(),Form1->pdsendstring3,Form1->Search_ADOQuery->FieldByName(Form1->pdsendback3)->AsString.Trim(),Form1->pdsendstring4,Form1->Search_ADOQuery->FieldByName(Form1->pdsendback4)->AsString.Trim(),Form1->pdsendstring5,Form1->Search_ADOQuery->FieldByName(Form1->pdsendback5)->AsString.Trim());
                            }
                            else
                            {
                                String str1="";
                                String str2="";
                                String str3="";
                                String str4="";
                                String str5="";
                                if(Form1->pdsendback1=="进价")str1="0";else str1=Form1->Search_ADOQuery->FieldByName(Form1->pdsendback1)->AsString.Trim();
                                if(Form1->pdsendback2=="进价")str2="0";else str2=Form1->Search_ADOQuery->FieldByName(Form1->pdsendback2)->AsString.Trim();
                                if(Form1->pdsendback3=="进价")str3="0";else str3=Form1->Search_ADOQuery->FieldByName(Form1->pdsendback3)->AsString.Trim();
                                if(Form1->pdsendback4=="进价")str4="0";else str4=Form1->Search_ADOQuery->FieldByName(Form1->pdsendback4)->AsString.Trim();
                                if(Form1->pdsendback5=="进价")str5="0";else str5=Form1->Search_ADOQuery->FieldByName(Form1->pdsendback5)->AsString.Trim();
                                if(android==0)inf=String().sprintf("%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),str1,str2,str3,str4,str5);
                                else inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->pdsendstring1,str1,Form1->pdsendstring2,str2,Form1->pdsendstring3,str3,Form1->pdsendstring4,str4,Form1->pdsendstring5,str5);
                            }
                        }
                        else if(splitString->Strings[5].Trim()=="YK")
                        {
                            if(Form1->Pshow=="show")
                            {
                                if(android==0)inf=String().sprintf("%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->yksendback1)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->yksendback2)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->yksendback3)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->yksendback4)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->yksendback5)->AsString.Trim());
                                else inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->yksendstring1,Form1->Search_ADOQuery->FieldByName(Form1->yksendback1)->AsString.Trim(),Form1->yksendstring2,Form1->Search_ADOQuery->FieldByName(Form1->yksendback2)->AsString.Trim(),Form1->yksendstring3,Form1->Search_ADOQuery->FieldByName(Form1->yksendback3)->AsString.Trim(),Form1->yksendstring4,Form1->Search_ADOQuery->FieldByName(Form1->yksendback4)->AsString.Trim(),Form1->yksendstring5,Form1->Search_ADOQuery->FieldByName(Form1->yksendback5)->AsString.Trim());
                            }
                            else
                            {
                                String str1="";
                                String str2="";
                                String str3="";
                                String str4="";
                                String str5="";
                                if(Form1->yksendback1=="进价")str1="0";else str1=Form1->Search_ADOQuery->FieldByName(Form1->yksendback1)->AsString.Trim();
                                if(Form1->yksendback2=="进价")str2="0";else str2=Form1->Search_ADOQuery->FieldByName(Form1->yksendback2)->AsString.Trim();
                                if(Form1->yksendback3=="进价")str3="0";else str3=Form1->Search_ADOQuery->FieldByName(Form1->yksendback3)->AsString.Trim();
                                if(Form1->yksendback4=="进价")str4="0";else str4=Form1->Search_ADOQuery->FieldByName(Form1->yksendback4)->AsString.Trim();
                                if(Form1->yksendback5=="进价")str5="0";else str5=Form1->Search_ADOQuery->FieldByName(Form1->yksendback5)->AsString.Trim();
                                if(android==0)inf=String().sprintf("%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),str1,str2,str3,str4,str5);
                                else inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->yksendstring1,str1,Form1->yksendstring2,str2,Form1->yksendstring3,str3,Form1->yksendstring4,str4,Form1->yksendstring5,str5);
                            }
                        }
                        else if(splitString->Strings[5].Trim()=="YD")
                        {
                            if(Form1->Pshow=="show")
                            {
                                if(android==0)inf=String().sprintf("%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->ydsendback1)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->ydsendback2)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->ydsendback3)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->ydsendback4)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->ydsendback5)->AsString.Trim());
                                else inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->ydsendstring1,Form1->Search_ADOQuery->FieldByName(Form1->ydsendback1)->AsString.Trim(),Form1->ydsendstring2,Form1->Search_ADOQuery->FieldByName(Form1->ydsendback2)->AsString.Trim(),Form1->ydsendstring3,Form1->Search_ADOQuery->FieldByName(Form1->ydsendback3)->AsString.Trim(),Form1->ydsendstring4,Form1->Search_ADOQuery->FieldByName(Form1->ydsendback4)->AsString.Trim(),Form1->ydsendstring5,Form1->Search_ADOQuery->FieldByName(Form1->ydsendback5)->AsString.Trim());
                            }
                            else
                            {
                                String str1="";
                                String str2="";
                                String str3="";
                                String str4="";
                                String str5="";
                                if(Form1->ydsendback1=="进价")str1="0";else str1=Form1->Search_ADOQuery->FieldByName(Form1->ydsendback1)->AsString.Trim();
                                if(Form1->ydsendback2=="进价")str2="0";else str2=Form1->Search_ADOQuery->FieldByName(Form1->ydsendback2)->AsString.Trim();
                                if(Form1->ydsendback3=="进价")str3="0";else str3=Form1->Search_ADOQuery->FieldByName(Form1->ydsendback3)->AsString.Trim();
                                if(Form1->ydsendback4=="进价")str4="0";else str4=Form1->Search_ADOQuery->FieldByName(Form1->ydsendback4)->AsString.Trim();
                                if(Form1->ydsendback5=="进价")str5="0";else str5=Form1->Search_ADOQuery->FieldByName(Form1->ydsendback5)->AsString.Trim();
                                if(android==0)inf=String().sprintf("%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),str1,str2,str3,str4,str5);
                                else inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->ydsendstring1,str1,Form1->ydsendstring2,str2,Form1->ydsendstring3,str3,Form1->ydsendstring4,str4,Form1->ydsendstring5,str5);
                            }
                        }
                        else if(splitString->Strings[5].Trim()=="CK")
                        {
                            if(Form1->Pshow=="show")
                            {
                                if(android==0)inf=String().sprintf("%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->cksendback1)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->cksendback2)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->cksendback3)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->cksendback4)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->cksendback5)->AsString.Trim());
                                else inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->cksendstring1,Form1->Search_ADOQuery->FieldByName(Form1->cksendback1)->AsString.Trim(),Form1->cksendstring2,Form1->Search_ADOQuery->FieldByName(Form1->cksendback2)->AsString.Trim(),Form1->cksendstring3,Form1->Search_ADOQuery->FieldByName(Form1->cksendback3)->AsString.Trim(),Form1->cksendstring4,Form1->Search_ADOQuery->FieldByName(Form1->cksendback4)->AsString.Trim(),Form1->cksendstring5,Form1->Search_ADOQuery->FieldByName(Form1->cksendback5)->AsString.Trim());
                            }
                            else
                            {
                                String str1="";
                                String str2="";
                                String str3="";
                                String str4="";
                                String str5="";
                                if(Form1->cksendback1=="进价")str1="0";else str1=Form1->Search_ADOQuery->FieldByName(Form1->cksendback1)->AsString.Trim();
                                if(Form1->cksendback2=="进价")str2="0";else str2=Form1->Search_ADOQuery->FieldByName(Form1->cksendback2)->AsString.Trim();
                                if(Form1->cksendback3=="进价")str3="0";else str3=Form1->Search_ADOQuery->FieldByName(Form1->cksendback3)->AsString.Trim();
                                if(Form1->cksendback4=="进价")str4="0";else str4=Form1->Search_ADOQuery->FieldByName(Form1->cksendback4)->AsString.Trim();
                                if(Form1->cksendback5=="进价")str5="0";else str5=Form1->Search_ADOQuery->FieldByName(Form1->cksendback5)->AsString.Trim();
                                if(android==0)inf=String().sprintf("%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),str1,str2,str3,str4,str5);
                                else inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("条码")->AsString.Trim(),Form1->cksendstring1,str1,Form1->cksendstring2,str2,Form1->cksendstring3,str3,Form1->cksendstring4,str4,Form1->cksendstring5,str5);
                            }
                        }
                    }



                    if(splitString->Strings[5].Trim()=="RK")
                    {
                         Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         Form1->Search_ADOQuery->SQL->Add("SELECT * FROM 库存 where 条码 like \""+splitString->Strings[3].Trim()+"\" AND 仓库 like \""+splitString->Strings[4].Trim()+"\"");
                         Form1->Search_ADOQuery->Active= true;

                         if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("库存")->AsFloat)+",";
                         else  inf=inf+"库存,"+String(Form1->Search_ADOQuery->FieldByName("库存")->AsFloat)+",";

                         Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         Form1->Search_ADOQuery->SQL->Add("SELECT * FROM 入库 where 条码 like \""+splitString->Strings[3].Trim()+"\" AND 入库单据 like \""+splitString->Strings[6].Trim()+"\"");
                         Form1->Search_ADOQuery->Active= true;

                         int selectnum=0;
                         Double num=0;
                         selectnum=Form1->Search_ADOQuery->RecordCount;
                         for(int i=0;i<selectnum;i++)
                         {
                             num=num+Form1->Search_ADOQuery->FieldByName("入库数量")->AsFloat;
                             Form1->Search_ADOQuery->Next();
                         }
                         if(android==0)inf=inf+String(num)+",";
                         else  inf=inf+"入库数量,"+String(num)+",";
                    }
                    else if(splitString->Strings[5].Trim()=="CK")
                    {
                         Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         Form1->Search_ADOQuery->SQL->Add("SELECT * FROM 库存 where 条码 like \""+splitString->Strings[3].Trim()+"\" AND 仓库 like \""+splitString->Strings[4].Trim()+"\"");
                         Form1->Search_ADOQuery->Active= true;

                         if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("库存")->AsFloat)+",";
                         else  inf=inf+"库存,"+String(Form1->Search_ADOQuery->FieldByName("库存")->AsFloat)+",";

                         Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         Form1->Search_ADOQuery->SQL->Add("SELECT * FROM 出库 where 条码 like \""+splitString->Strings[3].Trim()+"\" AND 出库单据 like \""+splitString->Strings[6].Trim()+"\"");
                         Form1->Search_ADOQuery->Active= true;

                         int selectnum=0;
                         Double num=0;
                         selectnum=Form1->Search_ADOQuery->RecordCount;
                         for(int i=0;i<selectnum;i++)
                         {
                             num=num+Form1->Search_ADOQuery->FieldByName("出库数量")->AsFloat;
                             Form1->Search_ADOQuery->Next();
                         }
                         if(android==0)inf=inf+String(num)+",";
                         else  inf=inf+"出库数量,"+String(num)+",";
                    }
                    else if(splitString->Strings[5].Trim()=="PD")
                    {
                       Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         Form1->Search_ADOQuery->SQL->Add("SELECT * FROM 库存 where 条码 like \""+splitString->Strings[3].Trim()+"\" AND 仓库 like \""+splitString->Strings[4].Trim()+"\"");
                         Form1->Search_ADOQuery->Active= true;

                         if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("库存")->AsFloat)+",";
                         else  inf=inf+"库存,"+String(Form1->Search_ADOQuery->FieldByName("库存")->AsFloat)+",";

                       Form1->Search_ADOQuery->Close();
                       Form1->Search_ADOQuery->SQL->Clear();
                       Form1->Search_ADOQuery->SQL->Add("SELECT * FROM 盘点 where 条码 like \""+splitString->Strings[3].Trim()+"\" AND 仓库 like \""+splitString->Strings[4].Trim()+"\" AND 单号 like \""+splitString->Strings[6].Trim()+"\"");
                       Form1->Search_ADOQuery->Active= true;

                       if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("盘点库存")->AsFloat)+",";
                         else  inf=inf+"盘点库存,"+String(Form1->Search_ADOQuery->FieldByName("盘点库存")->AsFloat)+",";
                    }
                    else if(splitString->Strings[5].Trim()=="YK")
                    {
                       Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         Form1->Search_ADOQuery->SQL->Add("SELECT * FROM 库存 where 条码 like \""+splitString->Strings[3].Trim()+"\" AND 仓库 like \""+splitString->Strings[4].Trim()+"\"");
                         Form1->Search_ADOQuery->Active= true;

                         if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("库存")->AsFloat)+",";
                         else  inf=inf+"库存,"+String(Form1->Search_ADOQuery->FieldByName("库存")->AsFloat)+",";

                       Form1->Search_ADOQuery->Close();
                       Form1->Search_ADOQuery->SQL->Clear();
                       Form1->Search_ADOQuery->SQL->Add("SELECT * FROM 移库 where 条码 like \""+splitString->Strings[3].Trim()+"\" AND 原仓库 like \""+splitString->Strings[4].Trim()+"\" AND 目的仓库 like \""+splitString->Strings[6].Trim()+"\" AND 移库单号 like \""+splitString->Strings[7].Trim()+"\"");
                       Form1->Search_ADOQuery->Active= true;
                      // inf=inf+String(Form1->Search_ADOQuery->FieldByName("数量")->AsFloat)+",";
                      int selectnum=0;
                      Double num=0;
                      selectnum=Form1->Search_ADOQuery->RecordCount;
                      for(int i=0;i<selectnum;i++)
                      {
                             num=num+Form1->Search_ADOQuery->FieldByName("数量")->AsFloat;
                             Form1->Search_ADOQuery->Next();
                      }

                       if(android==0)inf=inf+String(num)+",";
                         else  inf=inf+"已移数量,"+String(num)+",";
                    }
                    else if(splitString->Strings[5].Trim()=="YD")
                    {
                         Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         Form1->Search_ADOQuery->SQL->Add("SELECT * FROM 验单 where 条码 like \""+splitString->Strings[3].Trim()+"\" AND 单据 like \""+splitString->Strings[4].Trim()+"\"");
                         Form1->Search_ADOQuery->Active= true;


                         if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("应扫数量")->AsFloat)+",";
                         else  inf=inf+"应扫数量,"+String(Form1->Search_ADOQuery->FieldByName("应扫数量")->AsFloat)+",";

                         if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("已扫数量")->AsFloat)+",";
                         else  inf=inf+"已扫数量,"+String(Form1->Search_ADOQuery->FieldByName("已扫数量")->AsFloat)+",";



                    }
                    else if(splitString->Strings[5].Trim()=="CX")
                    {
                       Form1->Search_ADOQuery->Close();
                       Form1->Search_ADOQuery->SQL->Clear();
                       Form1->Search_ADOQuery->SQL->Add("SELECT * FROM 库存 where 条码 like \""+splitString->Strings[3].Trim()+"\" AND 仓库 like \""+splitString->Strings[4].Trim()+"\"");
                       Form1->Search_ADOQuery->Active= true;
                       if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("库存")->AsFloat)+",";
                         else  inf=inf+"库存,"+String(Form1->Search_ADOQuery->FieldByName("库存")->AsFloat)+",";
                       if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("入库数量")->AsFloat)+",";
                         else  inf=inf+"入库数量,"+String(Form1->Search_ADOQuery->FieldByName("入库数量")->AsFloat)+",";
                       if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("出库数量")->AsFloat)+",";
                         else  inf=inf+"出库数量,"+String(Form1->Search_ADOQuery->FieldByName("出库数量")->AsFloat)+",";
                       Form1->Search_ADOQuery->Close();
                       Form1->Search_ADOQuery->SQL->Clear();
                       Form1->Search_ADOQuery->SQL->Add("SELECT * FROM 盘点统计 where 条码 like \""+splitString->Strings[3].Trim()+"\" AND 仓库 like \""+splitString->Strings[4].Trim()+"\"");
                       Form1->Search_ADOQuery->Active= true;
                       if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("盘点库存")->AsFloat)+",";
                         else  inf=inf+"盘点库存,"+String(Form1->Search_ADOQuery->FieldByName("盘点库存")->AsFloat)+",";
                    }

                    sendstr = "";
                    sendstr = "talk"+String(splitcom1)+ splitString->Strings[1] +String(splitcom1)+inf;
                    ServerSocket1->Socket->Connections[LinkNum]->SendText(Send(sendstr,android));
                    return;

                }

                if (splitString->Strings[2] == "PRINT")
                {
                    //查询资料并且发送
                    // Talk^机器名^单号^+校验+
                    //需要打印的资料    条码 名称 价格 数量 小计
                    //回复给机器的================================================================================
                   if(wComm==INVALID_HANDLE_VALUE||wComm==NULL)
                   {
                       /*sendstr = "";
                       sendstr = "talk"+String(splitcom1)+splitString->Strings[3].Trim()+String(splitcom1)+"UNOPEN";
                       ServerSocket1->Socket->Connections[LinkNum]->SendText(Send(sendstr,android)); */


      //屏蔽提示                //REVLIST->Items->Add("提示|还没有连接串口打印机，单据"+splitString->Strings[3].Trim()+"打印失败！");
                       //SendMessage(REVLIST-> Handle,   WM_VSCROLL,   SB_BOTTOM,   NULL);
                      // return;
                   }
                    /*sendstr = "";
                    sendstr = "talk"+String(splitcom1)+splitString->Strings[3].Trim()+String(splitcom1)+"PRINT";
                    ServerSocket1->Socket->Connections[LinkNum]->SendText(Send(sendstr,android)); //告诉采集器数据接收到了*/

                    if(splitString->Strings[4].Trim()=="RK")  //打印入库单据
                    {
			
	 /* 	     String print[]={"条码","名称","货号","规格","型号","进价","售价","单位","备注一","备注二","备注三"};
			     TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
			     String RK1=ini->ReadString("Sys","RK1","1*2*6");

			     if(strstr(RK1.c_str(),"6")&&Form1->Pshow=="unshow")
			     {
			          REVLIST->Items->Add("提示|单据"+splitString->Strings[3].Trim()+"打印失败！您没有权限打印进价！");
                                  SendMessage(REVLIST-> Handle,   WM_VSCROLL,   SB_BOTTOM,   NULL);
                                  return;
			     }
			
			     TStringList *bList =new TStringList();
			     Form1->CrnListSplitString(RK1,bList,'*');
			     String RK2=ini->ReadString("Sys","RK2","7");
			     String RK3=ini->ReadString("Sys","RK3","广州润山信息科技有限公司");
			     int index=0;
			     for(int j=0;j<bList->Count;j++)
			     {
			         if(bList->Strings[j].Trim().ToInt()==RK2.Trim().ToInt())
			         index=1;
			     }
			
			     //获取到条码======================================================
			     String barcode="";
			     unsigned long lrc;
			
			     float num=0;
			     float count=0;
			     float allcount=0;
			     String printstr="";
			
			     int selectnum=0;
			
			     Form1->RK_ADOQuery->Close();
			     Form1->RK_ADOQuery->SQL->Clear();
			     Form1->RK_ADOQuery->SQL->Add("SELECT * FROM 入库 WHERE 入库单据 like \""+splitString->Strings[3].Trim()+"\"");
			     Form1->RK_ADOQuery->Active= true;
			
			     selectnum=Form1->RK_ADOQuery->RecordCount;
			     printstr="";
			     printstr=RK3+"\r\n单号："+splitString->Strings[3].Trim()+"\r\n"+"时间："+Now().FormatString("yyyy-mm-dd hh:nn:ss")+"\r\n--------------------------------";
			     WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL);
			     allcount=0;
			     for(int i=0;i<selectnum;i++)
			     {
			            num=Form1->RK_ADOQuery->FieldByName("入库数量")->AsFloat;
			            if(index==1)
			            {
			                count=Form1->RK_ADOQuery->FieldByName(print[RK2.Trim().ToInt()-1])->AsFloat*Form1->RK_ADOQuery->FieldByName("入库数量")->AsFloat;
			                allcount=allcount+count;
			            }
			            printstr="";
			
			            for(int j=0;j<bList->Count;j++)
			            {
			                 printstr+="\r\n"+Form1->RK_ADOQuery->FieldByName(print[bList->Strings[j].Trim().ToInt()-1])->AsString;
			                 if(bList->Strings[j].Trim().ToInt()==RK2.Trim().ToInt())
			                 {
			                     index=1;
			                     for(int m=0;m<17-Form1->RK_ADOQuery->FieldByName(print[bList->Strings[j].Trim().ToInt()-1])->AsString.Trim().Length();m++ )
			                     printstr+=" ";
			                     printstr+=Form1->RK_ADOQuery->FieldByName(print[bList->Strings[j].Trim().ToInt()-1])->AsString + "*"+ String(num);
			                 }
			            }
			            WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL);
			            Form1->RK_ADOQuery->Next();
			       }
			       printstr="";
			       if(index==1)
			       {
			           printstr="\r\n--------------------------------总  计："+String(allcount);
			           printstr+="\r\n负责人："+ Form1->RK_ADOQuery->FieldByName("员工编号")->AsString;
			       }
			       else  printstr="\r\n--------------------------------负责人："+ Form1->RK_ADOQuery->FieldByName("员工编号")->AsString;
			       printstr+="\r\n\r\n\r\n\r\n\r\n\r\n";
			       WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL);
			
			       //提示打印完成
			       //ShowMessage("打印成功");

			       delete ini;
			       delete bList;*/

			     Form1->RK_ADOQuery->Close();
			     Form1->RK_ADOQuery->SQL->Clear();
			     Form1->RK_ADOQuery->SQL->Add("SELECT * FROM 入库 WHERE 入库单据 like \""+splitString->Strings[3].Trim()+"\"");
			     Form1->RK_ADOQuery->Active= true;


     RKprint->QRLabel15->Caption="";
    RKprint->QRLabel16->Caption="备    注：";
     RKprint->QRLabel7->Caption=Form1->infshow2.Trim();


     /*
     Double all=0;
       //计算总金额
       for(int i=0;i<Form1->RK_ADOQuery->RecordCount;i++)
       {
            all=all+Form1->RK_ADOQuery->FieldByName("入库数量")->AsFloat*Form1->RK_ADOQuery->FieldByName("进价")->AsFloat;
            Form1->RK_ADOQuery->Next();
       }
       RKprint->QRLabel13->Caption=String(all);       */

       TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
       RKprint->QRLabel5->Caption=ini->ReadString("Sys","RK3","广州润山信息科技有限公司");
       delete  ini;
       RKprint->QRLabel3->Caption=Now().FormatString("yyyy-mm-dd hh:nn:ss");
       //RKprint->QuickRep1->Preview();
       RKprint->QuickRep1->Print();
       RKprint->Close();

                        REVLIST->Items->Add("入库单："+splitString->Strings[3].Trim()+"打印成功");
                       SendMessage(REVLIST-> Handle,   WM_VSCROLL,   SB_BOTTOM,   NULL);
                    }
                    else if(splitString->Strings[4].Trim()=="CK")  //打印出库单据
                    {
			
  /*			     String print[]={"条码","名称","货号","规格","型号","进价","售价","单位","备注一","备注二","备注三"};
			     TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
			     String CK1=ini->ReadString("Sys","CK1","1*2*7");
			
			     if(strstr(CK1.c_str(),"6")&&Form1->Pshow=="unshow")
			     {
			          REVLIST->Items->Add("提示|单据"+splitString->Strings[3].Trim()+"打印失败！您没有权限打印进价！");
                                  SendMessage(REVLIST-> Handle,   WM_VSCROLL,   SB_BOTTOM,   NULL);
                                  return;
			     }
			
			     TStringList *bList =new TStringList();
			     Form1->CrnListSplitString(CK1,bList,'*');
			     String CK2=ini->ReadString("Sys","CK2","7");
			     String CK3=ini->ReadString("Sys","CK3","广州润山信息科技有限公司");
			     int index=0;
			     for(int j=0;j<bList->Count;j++)
			     {
			         if(bList->Strings[j].Trim().ToInt()==CK2.Trim().ToInt())
			         index=1;
			     }
			     //获取到条码======================================================
			     String barcode="";
			     unsigned long lrc;
			
			     float num=0;
			     float count=0;
			     float allcount=0;
			     String printstr="";
			
			     int selectnum=0;
			
			     Form1->CK_ADOQuery->Close();
			     Form1->CK_ADOQuery->SQL->Clear();
			     Form1->CK_ADOQuery->SQL->Add("SELECT * FROM 出库 WHERE 出库单据 like \""+splitString->Strings[3].Trim()+"\"");
			     Form1->CK_ADOQuery->Active= true;
			
			     selectnum=Form1->CK_ADOQuery->RecordCount;
			     printstr="";
			     printstr=CK3+"\r\n单号："+splitString->Strings[3].Trim()+"\r\n"+"时间："+Now().FormatString("yyyy-mm-dd hh:nn:ss")+"\r\n--------------------------------";
			     WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL);
			     allcount=0;
			     for(int i=0;i<selectnum;i++)
			     {
			            num=Form1->CK_ADOQuery->FieldByName("出库数量")->AsFloat;
			            if(index==1)
			            {
			                count=Form1->CK_ADOQuery->FieldByName(print[CK2.Trim().ToInt()-1])->AsFloat*Form1->CK_ADOQuery->FieldByName("出库数量")->AsFloat;
			                allcount=allcount+count;
			            }
			            printstr="";
			
			            for(int j=0;j<bList->Count;j++)
			            {
			                 printstr+="\r\n"+Form1->CK_ADOQuery->FieldByName(print[bList->Strings[j].Trim().ToInt()-1])->AsString;
			                 if(bList->Strings[j].Trim().ToInt()==CK2.Trim().ToInt())
			                 {
			                     index=1;
			                     for(int m=0;m<17-Form1->CK_ADOQuery->FieldByName(print[bList->Strings[j].Trim().ToInt()-1])->AsString.Trim().Length();m++ )
			                     printstr+=" ";
			                     printstr+=Form1->CK_ADOQuery->FieldByName(print[bList->Strings[j].Trim().ToInt()-1])->AsString + "*"+ String(num);
			                 }
			            }
			            WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL);
			            Form1->CK_ADOQuery->Next();
			       }
			       printstr="";
			       if(index==1)
			       {
			           printstr="\r\n--------------------------------总  计："+String(allcount);
			           printstr+="\r\n负责人："+ Form1->CK_ADOQuery->FieldByName("员工编号")->AsString;
			       }
			       else  printstr="\r\n--------------------------------负责人："+ Form1->CK_ADOQuery->FieldByName("员工编号")->AsString;
			       printstr+="\r\n\r\n\r\n\r\n\r\n\r\n";
			       WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL);
			
			       //提示打印完成
			     //  ShowMessage("打印成功");
			
			       delete ini;
			       delete bList;  */


			     Form1->CK_ADOQuery->Close();
			     Form1->CK_ADOQuery->SQL->Clear();
			     Form1->CK_ADOQuery->SQL->Add("SELECT * FROM 出库 WHERE 出库单据 like \""+splitString->Strings[3].Trim()+"\"");
			     Form1->CK_ADOQuery->Active= true;


     CKprint->QRLabel15->Caption="";
    CKprint->QRLabel16->Caption="备    注：";
     CKprint->QRLabel7->Caption=Form1->infshow2.Trim();


       /*
     Double all=0;
       //计算总金额
     for(int i=0;i<Form1->CK_ADOQuery->RecordCount;i++)
     {
            all=all+Form1->CK_ADOQuery->FieldByName("出库数量")->AsFloat*Form1->CK_ADOQuery->FieldByName("售价")->AsFloat;
            Form1->CK_ADOQuery->Next();
     }
     CKprint->QRLabel13->Caption=String(all);  */
     TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
     CKprint->QRLabel5->Caption=ini->ReadString("Sys","CK3","广州润山信息科技有限公司");
     delete  ini;
     CKprint->QRLabel3->Caption=Now().FormatString("yyyy-mm-dd hh:nn:ss");

    // CKprint->QuickRep1->Preview();

       CKprint->QuickRep1->Print();
       CKprint->Close();
                        REVLIST->Items->Add("出库单："+splitString->Strings[3].Trim()+"打印成功");
                       SendMessage(REVLIST-> Handle,   WM_VSCROLL,   SB_BOTTOM,   NULL);
                    }


                    return;
                }




                //当客户端断开连接的时候服务器的反应，相关链表的处理

                if (splitString->Strings[2].SubString(2,2).ToInt() > 20)
                {
                        if (startpovit->Strings[SourceNameNum] == "0" || splitString->Strings[2].SubString(2,2).ToInt() == 21)
                        {
                            REVLIST->Items->Add(splitString->Strings[2].SubString(7,splitString->Strings[2].Length()-7));
                            SendMessage(REVLIST-> Handle,   WM_VSCROLL,   SB_BOTTOM,   NULL);
                           // if(CheckBox1->Checked==True)WriteKey(splitString->Strings[2].SubString(10,splitString->Strings[2].Length()-10)+"\n");
                            wifelessstr="";
                            wifelessstr=splitString->Strings[2].SubString(7,splitString->Strings[2].Length()-7);
                            if(splitString->Strings[2].SubString(4,2)=="RT")
                            {
                              wifelessData->Add(wifelessstr);
                              AddData=0;
                            }
                            else  wifelessDataPL->Add(wifelessstr);
                        }
                        //发送收到第一条了
                        runningnum->Strings[SourceNameNum] = "1";
                        startpovit->Strings[SourceNameNum] = "1";

                 }
                 else if (splitString->Strings[2].SubString(2,2).ToInt()== runningnum->Strings[SourceNameNum].ToInt() && runningnum->Strings[SourceNameNum].ToInt() == 1)
                 {
                        runningnum->Strings[SourceNameNum] = "2";
                        startpovit->Strings[SourceNameNum] = "1";

                        REVLIST->Items->Add(splitString->Strings[2].SubString(7,splitString->Strings[2].Length()-7));
                        SendMessage(REVLIST-> Handle,   WM_VSCROLL,   SB_BOTTOM,   NULL);
                       // if(CheckBox1->Checked==True)WriteKey(splitString->Strings[2].SubString(10,splitString->Strings[2].Length()-10)+"\n");

                        wifelessstr="";
                        wifelessstr=splitString->Strings[2].SubString(7,splitString->Strings[2].Length()-7);
                        if(splitString->Strings[2].SubString(4,2)=="RT")
                        {
                              wifelessData->Add(wifelessstr);
                              AddData=0;
                        }
                        else  wifelessDataPL->Add(wifelessstr);

                       // SaveToDateBase(splitString->Strings[2].SubString(7,splitString->Strings[2].Length()-7));
                 }
                 else if (splitString->Strings[2].SubString(2,2).ToInt() == runningnum->Strings[SourceNameNum].ToInt())
                 {
                        if (runningnum->Strings[SourceNameNum].ToInt() == 20)
                        {
                            runningnum->Strings[SourceNameNum] = "1";
                        }
                        else
                        {
                           runningnum->Strings[SourceNameNum] = String(splitString->Strings[2].SubString(2,2).ToInt()+1);
                        }

                        REVLIST->Items->Add(splitString->Strings[2].SubString(7,splitString->Strings[2].Length()-7));
                        SendMessage(REVLIST-> Handle,   WM_VSCROLL,   SB_BOTTOM,   NULL);
                      //  if(CheckBox1->Checked==True)WriteKey(splitString->Strings[2].SubString(10,splitString->Strings[2].Length()-10)+"\n");
                       
                        wifelessstr="";
                        wifelessstr=splitString->Strings[2].SubString(7,splitString->Strings[2].Length()-7);
                        if(splitString->Strings[2].SubString(4,2)=="RT")
                        {
                              wifelessData->Add(wifelessstr);
                              AddData=0;
                        }
                        else  wifelessDataPL->Add(wifelessstr);

                 }

                 sendstr = "";
                 sendstr = String().sprintf("talk%s%s%s%.2d",String(splitcom1),sourcename->Strings[SourceNameNum],String(splitcom1),runningnum->Strings[SourceNameNum].ToInt());

                 ServerSocket1->Socket->Connections[LinkNum]->SendText(Send(sendstr,android));

                 //在此处显示
                 showinf1->Text="";
                 showinf2->Text="";
                 Form1->CrnListSplitString(splitString->Strings[2].Trim()+",0",showinf1,',');
                 if(splitString->Strings[2].SubString(7,2)!="UD")NUM->Text=showinf1->Strings[2];

                 if(splitString->Strings[2].SubString(4,2)=="RT")
                 {
                      //Form1->CrnListSplitString(showinf1->Strings[1].SubString(4,showinf1->Strings[1].Length()-1),bList,'|');
                      Form1->CrnListSplitString(showinf1->Strings[1],bList,'|');
                      barcode=bList->Strings[1];
                 }
                 else
                 {
                     Form1->CrnListSplitString(showinf1->Strings[1].SubString(4,showinf1->Strings[1].Length()-1),bList,'|');
                     if(bList->Count==1)barcode=showinf1->Strings[1].SubString(4,showinf1->Strings[1].Length()-1);
                     else  barcode=bList->Strings[1];
                 }

                 //----------------------------------------------------------------------------------------
                  Form1->Search_ADOQuery->Close();
                  Form1->Search_ADOQuery->SQL->Clear();

                  Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where 条码 like \""+barcode.Trim()+"\"");

                  Form1->Search_ADOQuery->Active= true;

                  inf1->Text=barcode;
                  inf2->Text=Form1->Search_ADOQuery->FieldByName("名称")->AsString;
                  inf3->Text=Form1->Search_ADOQuery->FieldByName("货号")->AsString;
                  inf4->Text=Form1->Search_ADOQuery->FieldByName("规格")->AsString;
                  inf5->Text=Form1->Search_ADOQuery->FieldByName("型号")->AsString;
                  if(Form1->Pshow=="show")inf6->Text=String(Form1->Search_ADOQuery->FieldByName("进价")->AsFloat);
                  inf7->Text=String(Form1->Search_ADOQuery->FieldByName("售价")->AsFloat);
                  inf8->Text=Form1->Search_ADOQuery->FieldByName("单位")->AsString;
                  inf9->Text=Form1->Search_ADOQuery->FieldByName("备注一")->AsString;
                  inf10->Text=Form1->Search_ADOQuery->FieldByName("备注二")->AsString;
                  inf11->Text=Form1->Search_ADOQuery->FieldByName("备注三")->AsString;


                  float Sprace=Form1->Search_ADOQuery->FieldByName("售价")->AsFloat;
                  float Jprace=Form1->Search_ADOQuery->FieldByName("进价")->AsFloat;

                 //----------------------------------------------------------------------------------------


                 //修改数据库的入库出库信息===========================================================================
                 if(AddData==0)
                 {
                       TStringList *plist=new TStringList();
                       TStringList *qlist=new TStringList();

                       TStringList *mlist=new TStringList();

                       plist->Text="";
                       Form1->CrnListSplitString(splitString->Strings[2].SubString(7,splitString->Strings[2].Length()-7)+"|",plist,'|');
                       qlist->Text="";
                       Form1->CrnListSplitString(plist->Strings[0]+"-",qlist,'-');

                       mlist->Text="";
                       Form1->CrnListSplitString(plist->Strings[1]+",",mlist,',');

                       if(CheckBox1->Checked==True||qlist->Strings[0]=="PS")WriteKey(mlist->Strings[0].Trim()+"\n");

                       float RKnum=0;
                       float CKnum=0;
                       float KCnum=0;

                       int index0=1;

                       String str="";

                       index0=1;

                      if(qlist->Strings[0]=="CK"||qlist->Strings[0]=="RK"||qlist->Strings[0]=="PD"||qlist->Strings[0]=="YK")
                       {
                       Form1->Search_ADOQuery->Close();
                       Form1->Search_ADOQuery->SQL->Clear();
                       if(qlist->Strings[0]=="CK"||qlist->Strings[0]=="RK")str=String().sprintf("SELECT * FROM 库存 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[2].Trim());
                       else if(qlist->Strings[0]=="PD")  str=String().sprintf("SELECT * FROM 库存 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim());
                       else if(qlist->Strings[0]=="YK")  str=String().sprintf("SELECT * FROM 库存 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[2].Trim());
                       Form1->Search_ADOQuery->SQL->Add(str);
                       Form1->Search_ADOQuery->Active= true;

                       if(Form1->Search_ADOQuery->RecordCount==0)index0=0;
                       else index0=1;

                       RKnum=Form1->Search_ADOQuery->FieldByName("入库数量")->AsFloat;
                       CKnum=Form1->Search_ADOQuery->FieldByName("出库数量")->AsFloat;
                       KCnum=Form1->Search_ADOQuery->FieldByName("库存")->AsFloat;
                       }


                      if(qlist->Strings[0]=="UD")
                      {
                           Form1->Search_ADOQuery->Close();
                           Form1->Search_ADOQuery->SQL->Clear();
                           Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where 条码 like \""+mlist->Strings[0].Trim()+"\"");
                           Form1->Search_ADOQuery->Active= true;

                           if(Form1->Search_ADOQuery->RecordCount==0)
                           {
                                 Form1->ADOTable1->Insert();
                                 Form1->ADOTable1->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
                                 if(mlist->Strings[1].Trim().Length()!=0)Form1->ADOTable1->FieldByName("名称")->AsString = mlist->Strings[1].Trim();
                                 else  Form1->ADOTable1->FieldByName("名称")->AsString ="   ";
                                 if(mlist->Strings[2].Trim().Length()!=0)Form1->ADOTable1->FieldByName("货号")->AsString = mlist->Strings[2].Trim();
                                 else  Form1->ADOTable1->FieldByName("货号")->AsString ="   ";
                                 if(mlist->Strings[3].Trim().Length()!=0)Form1->ADOTable1->FieldByName("规格")->AsString = mlist->Strings[3].Trim();
                                 else  Form1->ADOTable1->FieldByName("规格")->AsString ="   ";
                                 if(mlist->Strings[4].Trim()!=0)Form1->ADOTable1->FieldByName("型号")->AsString = mlist->Strings[4].Trim();
                                 else  Form1->ADOTable1->FieldByName("型号")->AsString ="   ";
                                 if(Form1->Pshow=="show")
                                 {
                                     if(mlist->Strings[5].Trim().Length()!=0)Form1->ADOTable1->FieldByName("进价")->AsFloat = mlist->Strings[5].Trim().ToDouble();
                                     else  Form1->ADOTable1->FieldByName("进价")->AsFloat =0;
                                 }
                                 if(mlist->Strings[6].Trim().Length()!=0)Form1->ADOTable1->FieldByName("售价")->AsFloat = mlist->Strings[6].Trim().ToDouble();
                                 else  Form1->ADOTable1->FieldByName("售价")->AsFloat =0;
                                 if(mlist->Strings[7].Trim().Length()!=0)Form1->ADOTable1->FieldByName("单位")->AsString = mlist->Strings[7].Trim();
                                 else  Form1->ADOTable1->FieldByName("单位")->AsString ="   ";
                                 if(mlist->Strings[8].Trim().Length()!=0)Form1->ADOTable1->FieldByName("备注一")->AsString = mlist->Strings[8].Trim();
                                 else  Form1->ADOTable1->FieldByName("备注一")->AsString ="   ";
                                 if(mlist->Strings[9].Trim().Length()!=0)Form1->ADOTable1->FieldByName("备注二")->AsString = mlist->Strings[9].Trim();
                                 else  Form1->ADOTable1->FieldByName("备注二")->AsString ="   ";
                                 if(mlist->Strings[10].Trim().Length()!=0)Form1->ADOTable1->FieldByName("备注三")->AsString = mlist->Strings[10].Trim();
                                 else  Form1->ADOTable1->FieldByName("备注三")->AsString ="   ";
                                 Form1->ADOTable1->Post();
                           }
                           else
                           {
                                 str="";
                                 int index = 1;
                                 str="UPDATE JBZL SET";
                                 if(mlist->Strings[1].Trim().Length()!=0)
                                 {
                                     if(index==0)str=str+" ,";
                                     str=str+" 名称 = \""+mlist->Strings[1].Trim()+" \"";
                                     index=0;
                                 }
                                 if(mlist->Strings[2].Trim().Length()!=0)
                                 {
                                     if(index==0)str=str+" ,";
                                     str=str+" 货号 = \""+mlist->Strings[2].Trim()+" \"";
                                     index=0;
                                 }
                                 if(mlist->Strings[3].Trim().Length()!=0)
                                 {
                                     if(index==0)str=str+" ,";
                                     str=str+" 规格 = \""+mlist->Strings[3].Trim()+" \"";
                                     index=0;
                                 }
                                 if(mlist->Strings[4].Trim().Length()!=0)
                                 {
                                     if(index==0)str=str+" ,";
                                     str=str+" 型号 = \""+mlist->Strings[4].Trim()+" \"";
                                     index=0;
                                 }
                                 if(Form1->Pshow=="show")
                                 {
                                     if(mlist->Strings[5].Trim().Length()!=0)
                                     {
                                        if(index==0)str=str+" ,";
                                        str=str+" 进价 = "+mlist->Strings[5].Trim().ToDouble();
                                        index=0;
                                     }
                                 }
                                 if(mlist->Strings[6].Trim().Length()!=0)
                                 {
                                    if(index==0)str=str+" ,";
                                    str=str+" 售价 = "+mlist->Strings[6].Trim().ToDouble();
                                    index=0;
                                 }
                                 if(mlist->Strings[7].Trim().Length()!=0)
                                 {
                                    if(index==0)str=str+" ,";
                                    str=str+" 单位 = \""+mlist->Strings[7].Trim()+" \"";
                                    index=0;
                                 }
                                 if(mlist->Strings[8].Trim().Length()!=0)
                                 {
                                    if(index==0)str=str+" ,";
                                    str=str+" 备注一 = \""+mlist->Strings[8].Trim()+" \"";
                                    index=0;
                                 }
                                 if(mlist->Strings[9].Trim().Length()!=0)
                                 {
                                    if(index==0)str=str+" ,";
                                    str=str+" 备注二 = \""+mlist->Strings[9].Trim()+" \"";
                                    index=0;
                                 }
                                 if(mlist->Strings[10].Trim().Length()!=0)
                                 {
                                    if(index==0)str=str+" ,";
                                    str=str+" 备注三 = \""+mlist->Strings[10].Trim()+" \"";
                                    index=0;
                                 }
                                 if(mlist->Strings[1].Trim().Length()==0&&mlist->Strings[2].Trim().Length()==0&&mlist->Strings[3].Trim().Length()==0&&
                                    mlist->Strings[4].Trim().Length()==0&&mlist->Strings[5].Trim().Length()==0&&mlist->Strings[6].Trim().Length()==0&&
                                    mlist->Strings[7].Trim().Length()==0&&mlist->Strings[8].Trim().Length()==0&&mlist->Strings[9].Trim().Length()==0&&
                                    mlist->Strings[10].Trim().Length()==0)return;
                                 str=str+" WHERE 条码 like \""+mlist->Strings[0].Trim()+"\"";

                                 Form1->ADOCommand1->CommandText = str;
                                 Form1->ADOCommand1->Execute();

                           }

                      }
                      else if(qlist->Strings[0]=="RK")
                      {
                         str="";
                         Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         str=String().sprintf("SELECT * FROM 入库 WHERE 条码 like \"%s\" AND 入库单据 like \"%s\" AND 入库仓库 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim(),qlist->Strings[2].Trim());
                         Form1->Search_ADOQuery->SQL->Add(str);
                         Form1->Search_ADOQuery->Active= true;

                         if(Form1->Search_ADOQuery->RecordCount==0)
                         {
                             Form1->RK_ADOTable->Insert();
                             Form1->RK_ADOTable->FieldByName("入库仓库")->AsString = qlist->Strings[2].Trim();
                             Form1->RK_ADOTable->FieldByName("入库单据")->AsString = qlist->Strings[1].Trim();
                             Form1->RK_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
                             Form1->RK_ADOTable->FieldByName("入库数量")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                             Form1->RK_ADOTable->FieldByName("入库时间")->AsString=StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
                             Form1->RK_ADOTable->FieldByName("员工编号")->AsString = mlist->Strings[3].Trim();
                             Form1->RK_ADOTable->Post();
                         }
                         else
                         {
                             str="";
                             str=String().sprintf("UPDATE RK SET  入库数量 = %f , 入库时间 =  \"%s\" , 员工编号 =  \"%s\"  WHERE 条码 like \"%s\" AND 入库仓库 like \"%s\" AND 入库单据 like \"%s\""
                                 ,mlist->Strings[1].Trim().ToDouble()+Form1->Search_ADOQuery->FieldByName("入库数量")->AsFloat
                                 ,StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase)
                                 ,mlist->Strings[3].Trim()
                                 ,mlist->Strings[0].Trim()
                                 ,qlist->Strings[2].Trim()
                                 ,qlist->Strings[1].Trim());
                            Form1->ADOCommand1->CommandText = str;
                            Form1->ADOCommand1->Execute();
                         }



                        if(index0==0)
                        {
                            Form1->KC_ADOTable->Insert();
                            Form1->KC_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
                            Form1->KC_ADOTable->FieldByName("入库数量")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                            Form1->KC_ADOTable->FieldByName("仓库")->AsString = qlist->Strings[2].Trim();
                            Form1->KC_ADOTable->FieldByName("库存")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                            Form1->KC_ADOTable->Post();

                        }
                        else
                        {
                            str="";
                            str=String().sprintf("UPDATE KC SET  入库数量 = %f, 库存 =%f  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                 ,mlist->Strings[1].Trim().ToDouble()+RKnum
                                 ,mlist->Strings[1].Trim().ToDouble()+KCnum
                                 ,mlist->Strings[0].Trim()
                                 ,qlist->Strings[2].Trim());
                            Form1->ADOCommand1->CommandText = str;
                            Form1->ADOCommand1->Execute();
                        }

                  }
                  else if(qlist->Strings[0]=="CK")
                  {
                         Double cost=0;//总成本
                         Double sales=0;//总销售额
                         Double profits=0;//总利润

                         if(KCnum<mlist->Strings[1].Trim().ToDouble())
                         {
                               REVLIST->Items->Add("提示|在仓库"+ qlist->Strings[2].Trim()+"里边，条码"+mlist->Strings[0].Trim()+"库存不足");
                               SendMessage(REVLIST-> Handle,   WM_VSCROLL,   SB_BOTTOM,   NULL);
                         }

                         if(mlist->Strings[4].Trim().Length()!=0||mlist->Strings[5].Trim()=="0")//0代表修改了
                         Sprace= mlist->Strings[4].Trim().ToDouble();

                         str="";
                         Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         str=String().sprintf("SELECT * FROM 出库 WHERE 条码 like \"%s\" AND 出库单据 like \"%s\" AND 出库仓库 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim(),qlist->Strings[2].Trim());
                         Form1->Search_ADOQuery->SQL->Add(str);
                         Form1->Search_ADOQuery->Active= true;

                         if(Form1->Search_ADOQuery->RecordCount==0)
                         {
                             sales=Sprace*mlist->Strings[1].Trim().ToDouble();
                             cost=Jprace*mlist->Strings[1].Trim().ToDouble();
                             profits=sales-cost;

                             Form1->CK_ADOTable->Insert();
                             Form1->CK_ADOTable->FieldByName("出库仓库")->AsString = qlist->Strings[2].Trim();
                             Form1->CK_ADOTable->FieldByName("出库单据")->AsString = qlist->Strings[1].Trim();
                             Form1->CK_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
                             Form1->CK_ADOTable->FieldByName("出库数量")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                             Form1->CK_ADOTable->FieldByName("出库时间")->AsString=StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
                             Form1->CK_ADOTable->FieldByName("员工编号")->AsString = mlist->Strings[3].Trim();
                             Form1->CK_ADOTable->FieldByName("售价")->AsFloat = Sprace;
                             Form1->CK_ADOTable->Post();
                         }
                         else
                         {
                             if(Sprace==Form1->Search_ADOQuery->FieldByName("售价")->AsFloat)
                             {
                                  sales=Sprace*mlist->Strings[1].Trim().ToDouble();
                                  cost=Jprace*mlist->Strings[1].Trim().ToDouble();
                                  profits=sales-cost;

                             }
                             else
                             {
                                  sales=Sprace*mlist->Strings[1].Trim().ToDouble()+(Sprace-Form1->Search_ADOQuery->FieldByName("售价")->AsFloat)*Form1->Search_ADOQuery->FieldByName("出库数量")->AsFloat;
                                  cost=Jprace*mlist->Strings[1].Trim().ToDouble();
                                  profits=sales-cost;
                             }


                             str="";
                             str=String().sprintf("UPDATE CK SET  出库数量 = %f , 售价 = %f , 出库时间 =  \"%s\" , 员工编号 =  \"%s\"  WHERE 条码 like \"%s\" AND 出库仓库 like \"%s\" AND 出库单据 like \"%s\""
                                 ,mlist->Strings[1].Trim().ToDouble()+Form1->Search_ADOQuery->FieldByName("出库数量")->AsFloat
                                 ,Sprace
                                 ,StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase)
                                 ,mlist->Strings[3].Trim()
                                 ,mlist->Strings[0].Trim()
                                 ,qlist->Strings[2].Trim()
                                 ,qlist->Strings[1].Trim());
                            Form1->ADOCommand1->CommandText = str;
                            Form1->ADOCommand1->Execute();
                         }


                        if(index0==0)
                        {
                              Form1->KC_ADOTable->Insert();
                              Form1->KC_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
                              Form1->KC_ADOTable->FieldByName("出库数量")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                              Form1->KC_ADOTable->FieldByName("仓库")->AsString = qlist->Strings[2].Trim();
                              Form1->KC_ADOTable->FieldByName("库存")->AsFloat = 0-mlist->Strings[1].Trim().ToDouble();
                              Form1->KC_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE KC SET  出库数量 = %f, 库存 =%f  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                   ,mlist->Strings[1].Trim().ToDouble()+CKnum
                                   ,KCnum-mlist->Strings[1].Trim().ToDouble()
                                   ,mlist->Strings[0].Trim()
                                   ,qlist->Strings[2].Trim());
                              Form1->ADOCommand1->CommandText = str;
                              Form1->ADOCommand1->Execute();
                       }

                       //计算销售利润
                       str="";
                       Form1->XSTJ_ADOQuery->Close();
                       Form1->XSTJ_ADOQuery->SQL->Clear();
                       str=String().sprintf("SELECT * FROM 销售统计 WHERE 出库单据 like \"%s\"",qlist->Strings[1].Trim());
                       Form1->XSTJ_ADOQuery->SQL->Add(str);
                       Form1->XSTJ_ADOQuery->Active= true;

                       if(Form1->XSTJ_ADOQuery->RecordCount==0)
                       {
                           Form1->XSTJ_ADOTable->Insert();
                           Form1->XSTJ_ADOTable->FieldByName("出库单据")->AsString = qlist->Strings[1].Trim();
                           Form1->XSTJ_ADOTable->FieldByName("成本")->AsFloat = Jprace*mlist->Strings[1].Trim().ToDouble();
                           Form1->XSTJ_ADOTable->FieldByName("销售额")->AsFloat = Sprace*mlist->Strings[1].Trim().ToDouble();
                           Form1->XSTJ_ADOTable->FieldByName("利润")->AsFloat = (Sprace-Jprace)*mlist->Strings[1].Trim().ToDouble();
                           Form1->XSTJ_ADOTable->FieldByName("员工编号")->AsString = mlist->Strings[3].Trim();
                           Form1->XSTJ_ADOTable->FieldByName("时间")->AsString = StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);

                           Form1->XSTJ_ADOTable->Post();
                       }
                       else
                       {
                           str="";
                           str=String().sprintf("UPDATE XSTJ SET  成本 = %f, 销售额 =%f , 利润 =%f , 时间 =  \"%s\" WHERE 出库单据 like \"%s\""
                                 ,cost+Form1->XSTJ_ADOQuery->FieldByName("成本")->AsFloat
                                 ,sales+Form1->XSTJ_ADOQuery->FieldByName("销售额")->AsFloat
                                 ,profits+Form1->XSTJ_ADOQuery->FieldByName("利润")->AsFloat
                                 ,StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase)
                                 ,qlist->Strings[1].Trim());
                           Form1->ADOCommand1->CommandText = str;
                           Form1->ADOCommand1->Execute();
                       }
                       



                 }
                 else if(qlist->Strings[0]=="PD")
                 {
                        //修改盘点统计表================================================================================================
                        float pdkc=0;
		        String str="";
		        Form1->Search_ADOQuery->Close();
		        Form1->Search_ADOQuery->SQL->Clear();
		        str=String().sprintf("SELECT * FROM 盘点统计 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[2].Trim());
		        Form1->Search_ADOQuery->SQL->Add(str);
		        Form1->Search_ADOQuery->Active= true;
                        pdkc=Form1->Search_ADOQuery->FieldByName("盘点库存")->AsFloat;
		
		        if(Form1->Search_ADOQuery->RecordCount==0)
		        {
		            Form1->PDTJ_ADOTable->Insert();
		            Form1->PDTJ_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
		            Form1->PDTJ_ADOTable->FieldByName("盘点库存")->AsFloat = mlist->Strings[1].Trim().ToDouble();
		            Form1->PDTJ_ADOTable->FieldByName("仓库")->AsString = qlist->Strings[2].Trim();  //单据1  仓库2
		            Form1->PDTJ_ADOTable->Post();
		        }
		        else
		        {
		            str="";
		            str=String().sprintf("UPDATE PDTJ SET  盘点库存 = %f WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
		                                   ,pdkc+mlist->Strings[1].Trim().ToDouble()
		                                   ,mlist->Strings[0].Trim()
		                                   ,qlist->Strings[2].Trim());
		            Form1->ADOCommand1->CommandText = str;
		            Form1->ADOCommand1->Execute();
		        }

		        //修改盘点明细表==================================================================================================
		        Form1->Search_ADOQuery->Close();
		        Form1->Search_ADOQuery->SQL->Clear();
		        str=String().sprintf("SELECT * FROM 盘点 WHERE 条码 like \"%s\" AND 仓库 like \"%s\" AND 单号 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[2].Trim(),qlist->Strings[1].Trim());
		        Form1->Search_ADOQuery->SQL->Add(str);
		        Form1->Search_ADOQuery->Active= true;
		        pdkc=Form1->Search_ADOQuery->FieldByName("盘点库存")->AsFloat;

		        if(Form1->Search_ADOQuery->RecordCount==0)
		        {
		            Form1->PD_ADOTable->Insert();
		            Form1->PD_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
		            Form1->PD_ADOTable->FieldByName("盘点库存")->AsFloat = mlist->Strings[1].Trim().ToDouble();
		            Form1->PD_ADOTable->FieldByName("仓库")->AsString = qlist->Strings[2].Trim();
		            Form1->PD_ADOTable->FieldByName("单号")->AsString = qlist->Strings[1].Trim();
		            Form1->PD_ADOTable->FieldByName("盘点时间")->AsString = StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
		            Form1->PD_ADOTable->FieldByName("员工编号")->AsString = mlist->Strings[3].Trim();
		            Form1->PD_ADOTable->Post();
		        }
		        else
		        {
		            str="";
		            str=String().sprintf("UPDATE PD SET  盘点库存 = %f , 盘点时间 =\"%s\" , 员工编号 = \"%s\" WHERE 条码 like \"%s\" AND 仓库 like \"%s\" AND 单号 like \"%s\""
		                                   ,mlist->Strings[1].Trim().ToDouble()+pdkc
		                                   ,StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase)
		                                   ,mlist->Strings[3].Trim()
		                                   ,mlist->Strings[0].Trim()
		                                   ,qlist->Strings[2].Trim()
		                                   ,qlist->Strings[1].Trim());
		            Form1->ADOCommand1->CommandText = str;
		            Form1->ADOCommand1->Execute();
		        }

                         /*float pdkc=0;

                        String str="";
                        Form1->Search_ADOQuery->Close();
                        Form1->Search_ADOQuery->SQL->Clear();
                        str=String().sprintf("SELECT * FROM 盘点 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim());
                        Form1->Search_ADOQuery->SQL->Add(str);
                        Form1->Search_ADOQuery->Active= true;

                        pdkc=Form1->Search_ADOQuery->FieldByName("盘点库存")->AsFloat;

                        if(Form1->Search_ADOQuery->RecordCount==0)
                        {
                              Form1->PD_ADOTable->Insert();
                              Form1->PD_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
                              Form1->PD_ADOTable->FieldByName("盘点库存")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                              Form1->PD_ADOTable->FieldByName("仓库")->AsString = qlist->Strings[1].Trim();
                              Form1->PD_ADOTable->FieldByName("盘点时间")->AsString = StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
                              Form1->PD_ADOTable->FieldByName("员工编号")->AsString = mlist->Strings[3].Trim();
                              Form1->PD_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE PD SET  盘点库存 = %f ,盘点时间 = \"%s\" ,员工编号 = \"%s\"  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                   ,pdkc+mlist->Strings[1].Trim().ToDouble()
                                   ,StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase)
                                   ,mlist->Strings[3].Trim()
                                   ,mlist->Strings[0].Trim()
                                   ,qlist->Strings[1].Trim());
                              //ShowMessage(str);
                              Form1->ADOCommand1->CommandText = str;
                              Form1->ADOCommand1->Execute();
                       } */
                    }
                    else if(qlist->Strings[0]=="YD")
                    {
                        float pdkc=0;

                        String str="";
                        Form1->Search_ADOQuery->Close();
                        Form1->Search_ADOQuery->SQL->Clear();
                        str=String().sprintf("SELECT * FROM 验单 WHERE 条码 like \"%s\" AND 单据 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim());
                        Form1->Search_ADOQuery->SQL->Add(str);
                        Form1->Search_ADOQuery->Active= true;

                        pdkc=Form1->Search_ADOQuery->FieldByName("已扫数量")->AsFloat;

                        if(Form1->Search_ADOQuery->RecordCount==0)
                        {
                              Form1->YD_ADOTable->Insert();
                              Form1->YD_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
                              Form1->YD_ADOTable->FieldByName("应扫数量")->AsFloat = 0;
                              Form1->YD_ADOTable->FieldByName("已扫数量")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                              Form1->YD_ADOTable->FieldByName("时间")->AsString=StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
                              Form1->YD_ADOTable->FieldByName("单据")->AsString = qlist->Strings[1].Trim();
                              Form1->YD_ADOTable->FieldByName("员工编号")->AsString = mlist->Strings[3].Trim();
                              Form1->YD_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE YD SET  已扫数量 = %f ,时间 = \"%s\" ,员工编号 = \"%s\"  WHERE 条码 like \"%s\" AND 单据 like \"%s\""
                                   ,pdkc+mlist->Strings[1].Trim().ToDouble()
                                   ,StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase)
                                   ,mlist->Strings[3].Trim()
                                   ,mlist->Strings[0].Trim()
                                   ,qlist->Strings[1].Trim());
                              //ShowMessage(str);
                              Form1->ADOCommand1->CommandText = str;
                              Form1->ADOCommand1->Execute();
                       }
                    }
                    else if(qlist->Strings[0]=="YK")
                    {
                       // float pdkc=0;

                       /* String str="";
                        Form1->Search_ADOQuery->Close();
                        Form1->Search_ADOQuery->SQL->Clear();
                        str=String().sprintf("SELECT * FROM 移库 WHERE 条码 like \"%s\" AND 移库单号 like \"%s\" AND 原仓库 like \"%s\" AND 目的仓库 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim(),qlist->Strings[2].Trim(),qlist->Strings[3].Trim());
                        Form1->Search_ADOQuery->SQL->Add(str);
                        Form1->Search_ADOQuery->Active= true;

                        pdkc=Form1->Search_ADOQuery->FieldByName("数量")->AsFloat;

                        if(Form1->Search_ADOQuery->RecordCount==0)
                        { */
                              Form1->YK_ADOTable->Insert();
                              Form1->YK_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
                              Form1->YK_ADOTable->FieldByName("数量")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                              Form1->YK_ADOTable->FieldByName("移库时间")->AsString = StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
                              Form1->YK_ADOTable->FieldByName("移库单号")->AsString = qlist->Strings[1].Trim();
                              Form1->YK_ADOTable->FieldByName("原仓库")->AsString = qlist->Strings[2].Trim();
                              Form1->YK_ADOTable->FieldByName("目的仓库")->AsString = qlist->Strings[3].Trim();
                              Form1->YK_ADOTable->FieldByName("员工编号")->AsString = mlist->Strings[3].Trim();
                              Form1->YK_ADOTable->Post();

                        /*}
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE YK SET  数量 = %f , 移库时间 =  \"%s\" , 员工编号 =  \"%s\"  WHERE 条码 like \"%s\" AND 原仓库 like \"%s\" AND 目的仓库 like \"%s\""
                                 ,mlist->Strings[1].Trim().ToDouble()+pdkc
                                 ,StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase)
                                 ,mlist->Strings[3].Trim()
                                 ,mlist->Strings[0].Trim()
                                 ,qlist->Strings[1].Trim()
                                 ,qlist->Strings[2].Trim());
                            Form1->ADOCommand1->CommandText = str;
                            Form1->ADOCommand1->Execute();
                       } */

                       //修改原仓库库存
                    if(index0==0)
                        {
                              Form1->KC_ADOTable->Insert();
                              Form1->KC_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
                              Form1->KC_ADOTable->FieldByName("出库数量")->AsFloat = 0;
                              Form1->KC_ADOTable->FieldByName("入库数量")->AsFloat = 0;
                              Form1->KC_ADOTable->FieldByName("仓库")->AsString = qlist->Strings[2].Trim();
                              Form1->KC_ADOTable->FieldByName("库存")->AsFloat = 0-mlist->Strings[1].Trim().ToDouble();
                              Form1->KC_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE KC SET  库存 =%f  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                   ,KCnum-mlist->Strings[1].Trim().ToDouble()
                                   ,mlist->Strings[0].Trim()
                                   ,qlist->Strings[2].Trim());
                              Form1->ADOCommand1->CommandText = str;
                              Form1->ADOCommand1->Execute();
                       }

                       //修改目的仓库库存
                       Form1->Search_ADOQuery->Close();
                       Form1->Search_ADOQuery->SQL->Clear();
                       str=String().sprintf("SELECT * FROM 库存 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[3].Trim());
                       Form1->Search_ADOQuery->SQL->Add(str);
                       Form1->Search_ADOQuery->Active= true;
                       KCnum=Form1->Search_ADOQuery->FieldByName("库存")->AsFloat;


                       if(Form1->Search_ADOQuery->RecordCount==0)
                        {
                              Form1->KC_ADOTable->Insert();
                              Form1->KC_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
                              Form1->KC_ADOTable->FieldByName("出库数量")->AsFloat = 0;
                              Form1->KC_ADOTable->FieldByName("入库数量")->AsFloat = 0;
                              Form1->KC_ADOTable->FieldByName("仓库")->AsString = qlist->Strings[3].Trim();
                              Form1->KC_ADOTable->FieldByName("库存")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                              Form1->KC_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE KC SET  库存 =%f  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                   ,KCnum+mlist->Strings[1].Trim().ToDouble()
                                   ,mlist->Strings[0].Trim()
                                   ,qlist->Strings[3].Trim());
                              Form1->ADOCommand1->CommandText = str;
                              Form1->ADOCommand1->Execute();
                       }
                    }

                    delete plist;
                    delete qlist;
                    delete mlist;
                 }

      delete revv;
      delete splitString;

      delete showinf1;
      delete showinf2;
      delete bList;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::REVLISTClick(TObject *Sender)
{
try
 {
    TStringList *showinf1 =new TStringList();
    TStringList *showinf2 =new TStringList();

    TStringList *bList =new TStringList();
    String barcode;

    showinf1->Text="";
    showinf2->Text="";
    Form1->CrnListSplitString(REVLIST->Items->Strings[REVLIST->ItemIndex]+",0",showinf1,',');
   // NUM->Text=showinf1->Strings[1];
    Form1->CrnListSplitString(showinf1->Strings[0],bList,'|');
    barcode=bList->Strings[1];

    if(bList->Strings[0].Trim()!="UD")NUM->Text=showinf1->Strings[1];


   Form1->Search_ADOQuery->Close();
   Form1->Search_ADOQuery->SQL->Clear();
   Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where 条码 like \""+barcode.Trim()+"\"");
   Form1->Search_ADOQuery->Active= true;

   inf1->Text=barcode;
   inf2->Text=Form1->Search_ADOQuery->FieldByName("名称")->AsString;
   inf3->Text=Form1->Search_ADOQuery->FieldByName("货号")->AsString;
   inf4->Text=Form1->Search_ADOQuery->FieldByName("规格")->AsString;
   inf5->Text=Form1->Search_ADOQuery->FieldByName("型号")->AsString;
   if(Form1->Pshow=="show")inf6->Text=String(Form1->Search_ADOQuery->FieldByName("进价")->AsFloat);
   inf7->Text=String(Form1->Search_ADOQuery->FieldByName("售价")->AsFloat);
   inf8->Text=Form1->Search_ADOQuery->FieldByName("单位")->AsString;
   inf9->Text=Form1->Search_ADOQuery->FieldByName("备注一")->AsString;
   inf10->Text=Form1->Search_ADOQuery->FieldByName("备注二")->AsString;
   inf11->Text=Form1->Search_ADOQuery->FieldByName("备注三")->AsString;
 }
 catch (Exception &exception)
 {
      return;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn1Click(TObject *Sender)
{
        char *ComNo;
        DCB dcb;
        String Temp;
        AnsiString Com_Number;
        Com_Number=ComboBox1->Text;
        ComNo=Com_Number.c_str();
        wComm = CreateFile(ComNo,GENERIC_READ | GENERIC_WRITE,
                0, NULL, OPEN_EXISTING, 0, 0);

            if(wComm==INVALID_HANDLE_VALUE)//串口未打开
            {

               MessageDlg("\n打开端口失败\n端口被占用",mtWarning ,TMsgDlgButtons()<<mbOK,0);
               return;

            }
            GetCommState(wComm,&dcb);

            dcb.BaudRate =9600;


            dcb.ByteSize = 8;

            dcb.Parity   = NOPARITY;
            dcb.StopBits = ONESTOPBIT;
        //通信端口设置
            if(!SetCommState(wComm,&dcb))
              {  //设置通信端口的状态
                 //MessageBox(0,"通信端口设置错误","Set Error",MB_OK);
                  MessageDlg("\n通信端口设置错误！",mtError,TMsgDlgButtons()<<mbOK,0);
                  CloseHandle (wComm);
                  wComm=NULL;
                  return;
              }
            else
              {
                  //  Timer1->Enabled = true;

                  //  Memo3->Text="";
                   // runNum="0";
                   // List->Text="";

                  // MessageDlg("\n打开端口成功",mtWarning ,TMsgDlgButtons()<<mbOK,0);
                   BitBtn1->Enabled=false;
                   BitBtn2->Enabled=true;

              }


}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn2Click(TObject *Sender)
{

        if(wComm!=INVALID_HANDLE_VALUE&&wComm!=NULL)
        {
           CloseHandle(wComm);
           wComm=NULL;
           BitBtn1->Enabled=true;
           BitBtn2->Enabled=false;

        }
        else
        {
             MessageDlg("\n串口未打开！",mtInformation,TMsgDlgButtons()<<mbOK,0);
        }
        ComboBox1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn3Click(TObject *Sender)
{

        //TStringList *revv=new TStringList();
        TStringList *DataList=new TStringList();
        TStringList *plist=new TStringList();
        TStringList *qlist=new TStringList();
        TStringList *mlist=new TStringList();

        float RKnum=0;
        float CKnum=0;
        float KCnum=0;

        int index0=1;

        /*this->OpenDialog1->Filter="文本文件(*.txt*)|*.txt" ;
        if(OpenDialog1->Execute()==false)
        {
                return;
        }
        else
        {*/
         String Dir;
        if(SelectDirectory("Directory Name","",Dir))
        {
              if(Dir.SubString(Dir.Length(),1)!="\\")
              {
                   Dir=Dir+"\\";
              }
              DataList->Text="";
              DataList->LoadFromFile(Dir+IMPORTDATA);
              for(int i=0;i<DataList->Count;i++)
              {
                       REVLIST->Items->Add(DataList->Strings[i]);
                       SendMessage(REVLIST-> Handle,   WM_VSCROLL,   SB_BOTTOM,   NULL);
                      // this->StatusBar1->Panels->Items[0]->Text="正在上传USB数据    条数： "+String(i+1);
                       plist->Text="";
                       Form1->CrnListSplitString(DataList->Strings[i]+"|",plist,'|');
                       qlist->Text="";
                       Form1->CrnListSplitString(plist->Strings[0]+"-",qlist,'-');
                       mlist->Text="";
                       Form1->CrnListSplitString(plist->Strings[1]+",",mlist,',');

                       Form1->Search_ADOQuery->Close();
                       Form1->Search_ADOQuery->SQL->Clear();
                       Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where 条码 like \""+mlist->Strings[0].Trim()+"\"");
                       Form1->Search_ADOQuery->Active= true;
                       float Sprace=Form1->Search_ADOQuery->FieldByName("售价")->AsFloat;
                       float Jprace=Form1->Search_ADOQuery->FieldByName("进价")->AsFloat;


                       RKnum=0;
                       CKnum=0;
                       KCnum=0;

                       index0=1;

                       String str="";
                       if(qlist->Strings[0]=="CK"||qlist->Strings[0]=="RK"||qlist->Strings[0]=="PD"||qlist->Strings[0]=="YK")
                       {
                       Form1->Search_ADOQuery->Close();
                       Form1->Search_ADOQuery->SQL->Clear();
                       if(qlist->Strings[0]=="CK"||qlist->Strings[0]=="RK")str=String().sprintf("SELECT * FROM 库存 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[2].Trim());
                       else if(qlist->Strings[0]=="PD")  str=String().sprintf("SELECT * FROM 库存 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim());
                       else if(qlist->Strings[0]=="YK")  str=String().sprintf("SELECT * FROM 库存 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[2].Trim());
                       Form1->Search_ADOQuery->SQL->Add(str);
                       Form1->Search_ADOQuery->Active= true;

                       if(Form1->Search_ADOQuery->RecordCount==0)index0=0;
                       else index0=1;

                       RKnum=Form1->Search_ADOQuery->FieldByName("入库数量")->AsFloat;
                       CKnum=Form1->Search_ADOQuery->FieldByName("出库数量")->AsFloat;
                       KCnum=Form1->Search_ADOQuery->FieldByName("库存")->AsFloat;
                       }


                      if(qlist->Strings[0]=="UD")
                      {
                           Form1->Search_ADOQuery->Close();
                           Form1->Search_ADOQuery->SQL->Clear();
                           Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where 条码 like \""+mlist->Strings[0].Trim()+"\"");
                           Form1->Search_ADOQuery->Active= true;

                           if(Form1->Search_ADOQuery->RecordCount==0)
                           {
                                 Form1->ADOTable1->Insert();
                                 Form1->ADOTable1->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
                                 if(mlist->Strings[1].Trim().Length()!=0)Form1->ADOTable1->FieldByName("名称")->AsString = mlist->Strings[1].Trim();
                                 else  Form1->ADOTable1->FieldByName("名称")->AsString ="   ";
                                 if(mlist->Strings[2].Trim().Length()!=0)Form1->ADOTable1->FieldByName("货号")->AsString = mlist->Strings[2].Trim();
                                 else  Form1->ADOTable1->FieldByName("货号")->AsString ="   ";
                                 if(mlist->Strings[3].Trim().Length()!=0)Form1->ADOTable1->FieldByName("规格")->AsString = mlist->Strings[3].Trim();
                                 else  Form1->ADOTable1->FieldByName("规格")->AsString ="   ";
                                 if(mlist->Strings[4].Trim()!=0)Form1->ADOTable1->FieldByName("型号")->AsString = mlist->Strings[4].Trim();
                                 else  Form1->ADOTable1->FieldByName("型号")->AsString ="   ";
                                 if(Form1->Pshow=="show")
                                 {
                                     if(mlist->Strings[5].Trim().Length()!=0)Form1->ADOTable1->FieldByName("进价")->AsFloat = mlist->Strings[5].Trim().ToDouble();
                                     else  Form1->ADOTable1->FieldByName("进价")->AsFloat =0;
                                 }
                                 if(mlist->Strings[6].Trim().Length()!=0)Form1->ADOTable1->FieldByName("售价")->AsFloat = mlist->Strings[6].Trim().ToDouble();
                                 else  Form1->ADOTable1->FieldByName("售价")->AsFloat =0;
                                 if(mlist->Strings[7].Trim().Length()!=0)Form1->ADOTable1->FieldByName("单位")->AsString = mlist->Strings[7].Trim();
                                 else  Form1->ADOTable1->FieldByName("单位")->AsString ="   ";
                                 if(mlist->Strings[8].Trim().Length()!=0)Form1->ADOTable1->FieldByName("备注一")->AsString = mlist->Strings[8].Trim();
                                 else  Form1->ADOTable1->FieldByName("备注一")->AsString ="   ";
                                 if(mlist->Strings[9].Trim().Length()!=0)Form1->ADOTable1->FieldByName("备注二")->AsString = mlist->Strings[9].Trim();
                                 else  Form1->ADOTable1->FieldByName("备注二")->AsString ="   ";
                                 if(mlist->Strings[10].Trim().Length()!=0)Form1->ADOTable1->FieldByName("备注三")->AsString = mlist->Strings[10].Trim();
                                 else  Form1->ADOTable1->FieldByName("备注三")->AsString ="   ";
                                 Form1->ADOTable1->Post();
                           }
                           else
                           {
                                 str="";
                                 int index = 1;
                                 str="UPDATE JBZL SET";
                                 if(mlist->Strings[1].Trim().Length()!=0)
                                 {
                                     if(index==0)str=str+" ,";
                                     str=str+" 名称 = \""+mlist->Strings[1].Trim()+" \"";
                                     index=0;
                                 }
                                 if(mlist->Strings[2].Trim().Length()!=0)
                                 {
                                     if(index==0)str=str+" ,";
                                     str=str+" 货号 = \""+mlist->Strings[2].Trim()+" \"";
                                     index=0;
                                 }
                                 if(mlist->Strings[3].Trim().Length()!=0)
                                 {
                                     if(index==0)str=str+" ,";
                                     str=str+" 规格 = \""+mlist->Strings[3].Trim()+" \"";
                                     index=0;
                                 }
                                 if(mlist->Strings[4].Trim().Length()!=0)
                                 {
                                     if(index==0)str=str+" ,";
                                     str=str+" 型号 = \""+mlist->Strings[4].Trim()+" \"";
                                     index=0;
                                 }
                                 if(Form1->Pshow=="show")
                                 {
                                     if(mlist->Strings[5].Trim().Length()!=0)
                                     {
                                        if(index==0)str=str+" ,";
                                        str=str+" 进价 = "+mlist->Strings[5].Trim().ToDouble();
                                        index=0;
                                     }
                                 }
                                 if(mlist->Strings[6].Trim().Length()!=0)
                                 {
                                    if(index==0)str=str+" ,";
                                    str=str+" 售价 = "+mlist->Strings[6].Trim().ToDouble();
                                    index=0;
                                 }
                                 if(mlist->Strings[7].Trim().Length()!=0)
                                 {
                                    if(index==0)str=str+" ,";
                                    str=str+" 单位 = \""+mlist->Strings[7].Trim()+" \"";
                                    index=0;
                                 }
                                 if(mlist->Strings[8].Trim().Length()!=0)
                                 {
                                    if(index==0)str=str+" ,";
                                    str=str+" 备注一 = \""+mlist->Strings[8].Trim()+" \"";
                                    index=0;
                                 }
                                 if(mlist->Strings[9].Trim().Length()!=0)
                                 {
                                    if(index==0)str=str+" ,";
                                    str=str+" 备注二 = \""+mlist->Strings[9].Trim()+" \"";
                                    index=0;
                                 }
                                 if(mlist->Strings[10].Trim().Length()!=0)
                                 {
                                    if(index==0)str=str+" ,";
                                    str=str+" 备注三 = \""+mlist->Strings[10].Trim()+" \"";
                                    index=0;
                                 }
                                 if(mlist->Strings[1].Trim().Length()==0&&mlist->Strings[2].Trim().Length()==0&&mlist->Strings[3].Trim().Length()==0&&
                                    mlist->Strings[4].Trim().Length()==0&&mlist->Strings[5].Trim().Length()==0&&mlist->Strings[6].Trim().Length()==0&&
                                    mlist->Strings[7].Trim().Length()==0&&mlist->Strings[8].Trim().Length()==0&&mlist->Strings[9].Trim().Length()==0&&
                                    mlist->Strings[10].Trim().Length()==0)continue;
                                 str=str+" WHERE 条码 like \""+mlist->Strings[0].Trim()+"\"";

                                 Form1->ADOCommand1->CommandText = str;
                                 Form1->ADOCommand1->Execute();

                           }

                      }
                      else if(qlist->Strings[0]=="RK")
                      {
                         str="";
                         Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         str=String().sprintf("SELECT * FROM 入库 WHERE 条码 like \"%s\" AND 入库单据 like \"%s\" AND 入库仓库 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim(),qlist->Strings[2].Trim());
                         Form1->Search_ADOQuery->SQL->Add(str);
                         Form1->Search_ADOQuery->Active= true;

                         if(Form1->Search_ADOQuery->RecordCount==0)
                         {
                             Form1->RK_ADOTable->Insert();
                             Form1->RK_ADOTable->FieldByName("入库仓库")->AsString = qlist->Strings[2].Trim();
                             Form1->RK_ADOTable->FieldByName("入库单据")->AsString = qlist->Strings[1].Trim();
                             Form1->RK_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
                             Form1->RK_ADOTable->FieldByName("入库数量")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                             Form1->RK_ADOTable->FieldByName("入库时间")->AsString=StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
                             Form1->RK_ADOTable->FieldByName("员工编号")->AsString = mlist->Strings[3].Trim();
                             Form1->RK_ADOTable->Post();
                         }
                         else
                         {
                             str="";
                             str=String().sprintf("UPDATE RK SET  入库数量 = %f , 入库时间 =  \"%s\" , 员工编号 =  \"%s\"  WHERE 条码 like \"%s\" AND 入库仓库 like \"%s\" AND 入库单据 like \"%s\""
                                 ,mlist->Strings[1].Trim().ToDouble()+Form1->Search_ADOQuery->FieldByName("入库数量")->AsFloat
                                 ,StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase)
                                 ,mlist->Strings[3].Trim()
                                 ,mlist->Strings[0].Trim()
                                 ,qlist->Strings[2].Trim()
                                 ,qlist->Strings[1].Trim());
                            Form1->ADOCommand1->CommandText = str;
                            Form1->ADOCommand1->Execute();
                         }



                        if(index0==0)
                        {
                            Form1->KC_ADOTable->Insert();
                            Form1->KC_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
                            Form1->KC_ADOTable->FieldByName("入库数量")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                            Form1->KC_ADOTable->FieldByName("仓库")->AsString = qlist->Strings[2].Trim();
                            Form1->KC_ADOTable->FieldByName("库存")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                            Form1->KC_ADOTable->Post();

                        }
                        else
                        {
                            str="";
                            str=String().sprintf("UPDATE KC SET  入库数量 = %f, 库存 =%f  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                 ,mlist->Strings[1].Trim().ToDouble()+RKnum
                                 ,mlist->Strings[1].Trim().ToDouble()+KCnum
                                 ,mlist->Strings[0].Trim()
                                 ,qlist->Strings[2].Trim());
                            Form1->ADOCommand1->CommandText = str;
                            Form1->ADOCommand1->Execute();
                        }

                  }
                  else if(qlist->Strings[0]=="CK")
                  {
                         Double cost=0;//总成本
                         Double sales=0;//总销售额
                         Double profits=0;//总利润

                         if(KCnum<mlist->Strings[1].Trim().ToDouble())
                         {
                               REVLIST->Items->Add("提示|在仓库"+ qlist->Strings[2].Trim()+"里边，条码"+mlist->Strings[0].Trim()+"库存不足");
                               SendMessage(REVLIST-> Handle,   WM_VSCROLL,   SB_BOTTOM,   NULL);
                         }

                         if(mlist->Strings[4].Trim().Length()!=0||mlist->Strings[5].Trim()=="0")//0代表修改了
                         Sprace= mlist->Strings[4].Trim().ToDouble();

                         str="";
                         Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         str=String().sprintf("SELECT * FROM 出库 WHERE 条码 like \"%s\" AND 出库单据 like \"%s\" AND 出库仓库 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim(),qlist->Strings[2].Trim());
                         Form1->Search_ADOQuery->SQL->Add(str);
                         Form1->Search_ADOQuery->Active= true;

                         if(Form1->Search_ADOQuery->RecordCount==0)
                         {
                             sales=Sprace*mlist->Strings[1].Trim().ToDouble();
                             cost=Jprace*mlist->Strings[1].Trim().ToDouble();
                             profits=sales-cost;
                             
                             Form1->CK_ADOTable->Insert();
                             Form1->CK_ADOTable->FieldByName("出库仓库")->AsString = qlist->Strings[2].Trim();
                             Form1->CK_ADOTable->FieldByName("出库单据")->AsString = qlist->Strings[1].Trim();
                             Form1->CK_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
                             Form1->CK_ADOTable->FieldByName("出库数量")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                             Form1->CK_ADOTable->FieldByName("出库时间")->AsString=StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
                             Form1->CK_ADOTable->FieldByName("员工编号")->AsString = mlist->Strings[3].Trim();
                             Form1->CK_ADOTable->FieldByName("售价")->AsFloat = Sprace;
                             Form1->CK_ADOTable->Post();
                         }
                         else
                         {
                             if(Sprace==Form1->Search_ADOQuery->FieldByName("售价")->AsFloat)
                             {
                                  sales=Sprace*mlist->Strings[1].Trim().ToDouble();
                                  cost=Jprace*mlist->Strings[1].Trim().ToDouble();
                                  profits=sales-cost;

                             }
                             else
                             {
                                  sales=Sprace*mlist->Strings[1].Trim().ToDouble()+(Sprace-Form1->Search_ADOQuery->FieldByName("售价")->AsFloat)*Form1->Search_ADOQuery->FieldByName("出库数量")->AsFloat;
                                  cost=Jprace*mlist->Strings[1].Trim().ToDouble();
                                  profits=sales-cost;
                             }
                             str="";
                             str=String().sprintf("UPDATE CK SET  出库数量 = %f , 售价 = %f , 出库时间 =  \"%s\" , 员工编号 =  \"%s\"  WHERE 条码 like \"%s\" AND 出库仓库 like \"%s\" AND 出库单据 like \"%s\""
                                 ,mlist->Strings[1].Trim().ToDouble()+Form1->Search_ADOQuery->FieldByName("出库数量")->AsFloat
                                 ,Sprace
                                 ,StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase)
                                 ,mlist->Strings[3].Trim()
                                 ,mlist->Strings[0].Trim()
                                 ,qlist->Strings[2].Trim()
                                 ,qlist->Strings[1].Trim());
                            Form1->ADOCommand1->CommandText = str;
                            Form1->ADOCommand1->Execute();
                         }


                        if(index0==0)
                        {
                              Form1->KC_ADOTable->Insert();
                              Form1->KC_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
                              Form1->KC_ADOTable->FieldByName("出库数量")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                              Form1->KC_ADOTable->FieldByName("仓库")->AsString = qlist->Strings[2].Trim();
                              Form1->KC_ADOTable->FieldByName("库存")->AsFloat = 0-mlist->Strings[1].Trim().ToDouble();
                              Form1->KC_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE KC SET  出库数量 = %f, 库存 =%f  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                   ,mlist->Strings[1].Trim().ToDouble()+CKnum
                                   ,KCnum-mlist->Strings[1].Trim().ToDouble()
                                   ,mlist->Strings[0].Trim()
                                   ,qlist->Strings[2].Trim());
                              Form1->ADOCommand1->CommandText = str;
                              Form1->ADOCommand1->Execute();
                       }

                       //计算销售利润
                       str="";
                       Form1->XSTJ_ADOQuery->Close();
                       Form1->XSTJ_ADOQuery->SQL->Clear();
                       str=String().sprintf("SELECT * FROM 销售统计 WHERE 出库单据 like \"%s\"",qlist->Strings[1].Trim());
                       Form1->XSTJ_ADOQuery->SQL->Add(str);
                       Form1->XSTJ_ADOQuery->Active= true;

                       if(Form1->XSTJ_ADOQuery->RecordCount==0)
                       {
                           Form1->XSTJ_ADOTable->Insert();
                           Form1->XSTJ_ADOTable->FieldByName("出库单据")->AsString = qlist->Strings[1].Trim();
                           Form1->XSTJ_ADOTable->FieldByName("成本")->AsFloat = Jprace*mlist->Strings[1].Trim().ToDouble();
                           Form1->XSTJ_ADOTable->FieldByName("销售额")->AsFloat = Sprace*mlist->Strings[1].Trim().ToDouble();
                           Form1->XSTJ_ADOTable->FieldByName("利润")->AsFloat = (Sprace-Jprace)*mlist->Strings[1].Trim().ToDouble();
                           Form1->XSTJ_ADOTable->FieldByName("员工编号")->AsString = mlist->Strings[3].Trim();
                           Form1->XSTJ_ADOTable->FieldByName("时间")->AsString = StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);

                           Form1->XSTJ_ADOTable->Post();
                       }
                       else
                       {
                           str="";
                           str=String().sprintf("UPDATE XSTJ SET  成本 = %f, 销售额 =%f , 利润 =%f , 时间 =  \"%s\" WHERE 出库单据 like \"%s\""
                                 ,cost+Form1->XSTJ_ADOQuery->FieldByName("成本")->AsFloat
                                 ,sales+Form1->XSTJ_ADOQuery->FieldByName("销售额")->AsFloat
                                 ,profits+Form1->XSTJ_ADOQuery->FieldByName("利润")->AsFloat
                                 ,StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase)
                                 ,qlist->Strings[1].Trim());
                           Form1->ADOCommand1->CommandText = str;
                           Form1->ADOCommand1->Execute();
                       }
                       



                 }
                 else if(qlist->Strings[0]=="PD")
                 {
                        //修改盘点统计表================================================================================================
                        float pdkc=0;
		        String str="";
		        Form1->Search_ADOQuery->Close();
		        Form1->Search_ADOQuery->SQL->Clear();
		        str=String().sprintf("SELECT * FROM 盘点统计 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[2].Trim());
		        Form1->Search_ADOQuery->SQL->Add(str);
		        Form1->Search_ADOQuery->Active= true;
                        pdkc=Form1->Search_ADOQuery->FieldByName("盘点库存")->AsFloat;
		
		        if(Form1->Search_ADOQuery->RecordCount==0)
		        {
		            Form1->PDTJ_ADOTable->Insert();
		            Form1->PDTJ_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
		            Form1->PDTJ_ADOTable->FieldByName("盘点库存")->AsFloat = mlist->Strings[1].Trim().ToDouble();
		            Form1->PDTJ_ADOTable->FieldByName("仓库")->AsString = qlist->Strings[2].Trim();  //单据1  仓库2
		            Form1->PDTJ_ADOTable->Post();
		        }
		        else
		        {
		            str="";
		            str=String().sprintf("UPDATE PDTJ SET  盘点库存 = %f WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
		                                   ,pdkc+mlist->Strings[1].Trim().ToDouble()
		                                   ,mlist->Strings[0].Trim()
		                                   ,qlist->Strings[2].Trim());
		            Form1->ADOCommand1->CommandText = str;
		            Form1->ADOCommand1->Execute();
		        }

		        //修改盘点明细表==================================================================================================
		        Form1->Search_ADOQuery->Close();
		        Form1->Search_ADOQuery->SQL->Clear();
		        str=String().sprintf("SELECT * FROM 盘点 WHERE 条码 like \"%s\" AND 仓库 like \"%s\" AND 单号 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[2].Trim(),qlist->Strings[1].Trim());
		        Form1->Search_ADOQuery->SQL->Add(str);
		        Form1->Search_ADOQuery->Active= true;
		        pdkc=Form1->Search_ADOQuery->FieldByName("盘点库存")->AsFloat;

		        if(Form1->Search_ADOQuery->RecordCount==0)
		        {
		            Form1->PD_ADOTable->Insert();
		            Form1->PD_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
		            Form1->PD_ADOTable->FieldByName("盘点库存")->AsFloat = mlist->Strings[1].Trim().ToDouble();
		            Form1->PD_ADOTable->FieldByName("仓库")->AsString = qlist->Strings[2].Trim();
		            Form1->PD_ADOTable->FieldByName("单号")->AsString = qlist->Strings[1].Trim();
		            Form1->PD_ADOTable->FieldByName("盘点时间")->AsString = StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
		            Form1->PD_ADOTable->FieldByName("员工编号")->AsString = mlist->Strings[3].Trim();
		            Form1->PD_ADOTable->Post();
		        }
		        else
		        {
		            str="";
		            str=String().sprintf("UPDATE PD SET  盘点库存 = %f , 盘点时间 =\"%s\" , 员工编号 = \"%s\" WHERE 条码 like \"%s\" AND 仓库 like \"%s\" AND 单号 like \"%s\""
		                                   ,mlist->Strings[1].Trim().ToDouble()+pdkc
		                                   ,StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase)
		                                   ,mlist->Strings[3].Trim()
		                                   ,mlist->Strings[0].Trim()
		                                   ,qlist->Strings[2].Trim()
		                                   ,qlist->Strings[1].Trim());
		            Form1->ADOCommand1->CommandText = str;
		            Form1->ADOCommand1->Execute();
		        }

                         /*float pdkc=0;

                        String str="";
                        Form1->Search_ADOQuery->Close();
                        Form1->Search_ADOQuery->SQL->Clear();
                        str=String().sprintf("SELECT * FROM 盘点 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim());
                        Form1->Search_ADOQuery->SQL->Add(str);
                        Form1->Search_ADOQuery->Active= true;

                        pdkc=Form1->Search_ADOQuery->FieldByName("盘点库存")->AsFloat;

                        if(Form1->Search_ADOQuery->RecordCount==0)
                        {
                              Form1->PD_ADOTable->Insert();
                              Form1->PD_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
                              Form1->PD_ADOTable->FieldByName("盘点库存")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                              Form1->PD_ADOTable->FieldByName("仓库")->AsString = qlist->Strings[1].Trim();
                              Form1->PD_ADOTable->FieldByName("盘点时间")->AsString = StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
                              Form1->PD_ADOTable->FieldByName("员工编号")->AsString = mlist->Strings[3].Trim();
                              Form1->PD_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE PD SET  盘点库存 = %f ,盘点时间 = \"%s\" ,员工编号 = \"%s\"  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                   ,pdkc+mlist->Strings[1].Trim().ToDouble()
                                   ,StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase)
                                   ,mlist->Strings[3].Trim()
                                   ,mlist->Strings[0].Trim()
                                   ,qlist->Strings[1].Trim());
                              //ShowMessage(str);
                              Form1->ADOCommand1->CommandText = str;
                              Form1->ADOCommand1->Execute();
                       } */
                    }
                    else if(qlist->Strings[0]=="YD")
                    {
                        float pdkc=0;

                        String str="";
                        Form1->Search_ADOQuery->Close();
                        Form1->Search_ADOQuery->SQL->Clear();
                        str=String().sprintf("SELECT * FROM 验单 WHERE 条码 like \"%s\" AND 单据 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim());
                        Form1->Search_ADOQuery->SQL->Add(str);
                        Form1->Search_ADOQuery->Active= true;

                        pdkc=Form1->Search_ADOQuery->FieldByName("已扫数量")->AsFloat;

                        if(Form1->Search_ADOQuery->RecordCount==0)
                        {
                              Form1->YD_ADOTable->Insert();
                              Form1->YD_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
                              Form1->YD_ADOTable->FieldByName("应扫数量")->AsFloat = 0;
                              Form1->YD_ADOTable->FieldByName("已扫数量")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                              Form1->YD_ADOTable->FieldByName("时间")->AsString=StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
                              Form1->YD_ADOTable->FieldByName("单据")->AsString = qlist->Strings[1].Trim();
                              Form1->YD_ADOTable->FieldByName("员工编号")->AsString = mlist->Strings[3].Trim();
                              Form1->YD_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE YD SET  已扫数量 = %f ,时间 = \"%s\" ,员工编号 = \"%s\"  WHERE 条码 like \"%s\" AND 单据 like \"%s\""
                                   ,pdkc+mlist->Strings[1].Trim().ToDouble()
                                   ,StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase)
                                   ,mlist->Strings[3].Trim()
                                   ,mlist->Strings[0].Trim()
                                   ,qlist->Strings[1].Trim());
                              //ShowMessage(str);
                              Form1->ADOCommand1->CommandText = str;
                              Form1->ADOCommand1->Execute();
                       }
                    }
                    else if(qlist->Strings[0]=="YK")
                    {
                       // float pdkc=0;

                       /* String str="";
                        Form1->Search_ADOQuery->Close();
                        Form1->Search_ADOQuery->SQL->Clear();
                        str=String().sprintf("SELECT * FROM 移库 WHERE 条码 like \"%s\" AND 移库单号 like \"%s\" AND 原仓库 like \"%s\" AND 目的仓库 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim(),qlist->Strings[2].Trim(),qlist->Strings[3].Trim());
                        Form1->Search_ADOQuery->SQL->Add(str);
                        Form1->Search_ADOQuery->Active= true;

                        pdkc=Form1->Search_ADOQuery->FieldByName("数量")->AsFloat;

                        if(Form1->Search_ADOQuery->RecordCount==0)
                        { */
                              Form1->YK_ADOTable->Insert();
                              Form1->YK_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
                              Form1->YK_ADOTable->FieldByName("数量")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                              Form1->YK_ADOTable->FieldByName("移库时间")->AsString = StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
                              Form1->YK_ADOTable->FieldByName("移库单号")->AsString = qlist->Strings[1].Trim();
                              Form1->YK_ADOTable->FieldByName("原仓库")->AsString = qlist->Strings[2].Trim();
                              Form1->YK_ADOTable->FieldByName("目的仓库")->AsString = qlist->Strings[3].Trim();
                              Form1->YK_ADOTable->FieldByName("员工编号")->AsString = mlist->Strings[3].Trim();
                              Form1->YK_ADOTable->Post();

                        /*}
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE YK SET  数量 = %f , 移库时间 =  \"%s\" , 员工编号 =  \"%s\"  WHERE 条码 like \"%s\" AND 原仓库 like \"%s\" AND 目的仓库 like \"%s\""
                                 ,mlist->Strings[1].Trim().ToDouble()+pdkc
                                 ,StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase)
                                 ,mlist->Strings[3].Trim()
                                 ,mlist->Strings[0].Trim()
                                 ,qlist->Strings[1].Trim()
                                 ,qlist->Strings[2].Trim());
                            Form1->ADOCommand1->CommandText = str;
                            Form1->ADOCommand1->Execute();
                       } */

                       //修改原仓库库存
                    if(index0==0)
                        {
                              Form1->KC_ADOTable->Insert();
                              Form1->KC_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
                              Form1->KC_ADOTable->FieldByName("出库数量")->AsFloat = 0;
                              Form1->KC_ADOTable->FieldByName("入库数量")->AsFloat = 0;
                              Form1->KC_ADOTable->FieldByName("仓库")->AsString = qlist->Strings[2].Trim();
                              Form1->KC_ADOTable->FieldByName("库存")->AsFloat = 0-mlist->Strings[1].Trim().ToDouble();
                              Form1->KC_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE KC SET  库存 =%f  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                   ,KCnum-mlist->Strings[1].Trim().ToDouble()
                                   ,mlist->Strings[0].Trim()
                                   ,qlist->Strings[2].Trim());
                              Form1->ADOCommand1->CommandText = str;
                              Form1->ADOCommand1->Execute();
                       }

                       //修改目的仓库库存
                       Form1->Search_ADOQuery->Close();
                       Form1->Search_ADOQuery->SQL->Clear();
                       str=String().sprintf("SELECT * FROM 库存 WHERE 条码 like \"%s\" AND 仓库 like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[3].Trim());
                       Form1->Search_ADOQuery->SQL->Add(str);
                       Form1->Search_ADOQuery->Active= true;
                       KCnum=Form1->Search_ADOQuery->FieldByName("库存")->AsFloat;


                       if(Form1->Search_ADOQuery->RecordCount==0)
                        {
                              Form1->KC_ADOTable->Insert();
                              Form1->KC_ADOTable->FieldByName("条码")->AsString = mlist->Strings[0].Trim();
                              Form1->KC_ADOTable->FieldByName("出库数量")->AsFloat = 0;
                              Form1->KC_ADOTable->FieldByName("入库数量")->AsFloat = 0;
                              Form1->KC_ADOTable->FieldByName("仓库")->AsString = qlist->Strings[3].Trim();
                              Form1->KC_ADOTable->FieldByName("库存")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                              Form1->KC_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE KC SET  库存 =%f  WHERE 条码 like \"%s\" AND 仓库 like \"%s\""
                                   ,KCnum+mlist->Strings[1].Trim().ToDouble()
                                   ,mlist->Strings[0].Trim()
                                   ,qlist->Strings[3].Trim());
                              Form1->ADOCommand1->CommandText = str;
                              Form1->ADOCommand1->Execute();
                       }
                    }
                 Application->ProcessMessages();


               }

               MessageDlg("上传完成",mtInformation,TMsgDlgButtons()<<mbOK,0);
             //  this->StatusBar1->Panels->Items[0]->Text="服务器已经开启，正在监听...";
        }

        delete DataList;
        delete plist;
        delete qlist;
        delete mlist;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn4Click(TObject *Sender)
{
   String Dir;
   if(SelectDirectory("Directory Name","",Dir))
   {
         if(Dir.SubString(Dir.Length(),1)!="\\")
         {
                   Dir=Dir+"\\";
         }

        TStringList *pList=new TStringList();
        TStringList *SaveList=new TStringList();
        TStringList *wList=new TStringList();
        String szString="";
        String str="";
        String INFstr="";




        char AdrStr[20];
        try
        {

              //保存批量上传的数据======================================================================
              SaveList->Text="";
              wList->Text="";
              for(int i=0;i<wifelessDataPL->Count;i++)
              {
                 wList->Add("普通盘点-"+wifelessDataPL->Strings[i]);
              }
              String datetime= Now().FormatString("yyyymmddhhnnss");
              wList->Sort();
              String FileName="";
              for(int i=0;i<wList->Count;i++)
              {
                    pList->Text="";
                    Form1->CrnListSplitString(wList->Strings[i].Trim(),pList,'|');
                    if(FileName!=pList->Strings[0].Trim())
                    {
                          if(FileName.Length()>0)
                          {
                                  Form1->SaveExcel(SaveList,Dir.Trim()+FileName+"-"+datetime+".xls") ;
                                  SaveList->Text="";
                          }
                          FileName= pList->Strings[0].Trim();

                          SaveList->Add("PL,"+pList->Strings[1].Trim());
                    }
                    else
                    {
                          SaveList->Add("PL,"+pList->Strings[1].Trim());
                    }
              }
              if(SaveList->Text.Length()>0)
              {
                   if(FileName.Length()>0)
                   {
                        Form1->SaveExcel(SaveList,Dir.Trim()+FileName+"-"+datetime+".xls") ;
                   }
              }


              MessageDlg("保存成功",mtInformation,TMsgDlgButtons()<<mbOK,0);

              delete wList;
              delete pList;
              delete SaveList;
        }
        catch (Exception &exception)
        {
                Application->ShowException(&exception);
                delete wList;
               delete pList;
               delete SaveList;
        }
   }
   else
   return;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N24Click(TObject *Sender)
{
    Form21->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N27Click(TObject *Sender)
{
    Form34->BitBtn1->Visible=false;
    Form34->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N26Click(TObject *Sender)
{
    Form22->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::FormCreate(TObject *Sender)
{
//显示出串口
     TRegistry *reg = new TRegistry;
     reg->RootKey = HKEY_LOCAL_MACHINE;
     reg->OpenKey("HARDWARE\\DEVICEMAP\\SERIALCOMM", true);
     ComboBox1->Sorted = false;
     reg->GetValueNames(ComboBox1->Items);
     ComboBox1->Items->BeginUpdate();
     for (int i=0;i<ComboBox1->Items->Count; i++)
     ComboBox1->Items->Strings[i] = reg->ReadString(ComboBox1->Items->Strings[i]);
     ComboBox1->Items->EndUpdate();
     delete reg;
     ComboBox1->Sorted = true;
     ComboBox1->ItemIndex=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit1Change(TObject *Sender)
{
   TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
   ini-> WriteString( "Sys", "RSname", Edit1->Text.Trim());
   delete ini;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::N28Click(TObject *Sender)
{
   Form7->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::N29Click(TObject *Sender)
{
   Form39->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::BitBtn5Click(TObject *Sender)
{
    if(Form2->ClientSocket1->Active==false)
    {
        try
        {
              Form2->ClientSocket1->Active=true;
        }
        catch(...)
        {
              MessageDlg("同步失败，服务器没有开启",mtInformation,TMsgDlgButtons()<<mbOK,0);
              return;
        }
     }

     String name="";
     String password="";
NM:
     name="";
     if(InputQuery("IP网络同步","请输入同步账号:           ",name))
     {
         if(name.Length() ==0)
	 {
             Form2->ClientSocket1->Active=false;
	     return;
	 }
     }
     else
     {
         Form2->ClientSocket1->Active=false;
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

     char splitcom1[3];
     memset(splitcom1,0,3);
     splitcom1[0]=0xA1;splitcom1[1]=0xF5;

     char splitcom2[3];
     memset(splitcom2,0,3);
     splitcom2[0]=0xA1;splitcom2[1]=0xF6;

     String sendstr = "";
     sendstr = String().sprintf("talk%s%s%s%s%s%s",String(splitcom1),"update",String(splitcom1),name.Trim(),String(splitcom1),password.Trim());
     //talk  注册 用户名  校验
     //talk OK
     ClientSocket1->Socket->SendText(Send(sendstr,0));

    /* sendstr = "";
     sendstr = String().sprintf("talk%s%s%s%s",String(splitcom1),"update",String(splitcom1),"OK");
     //talk  注册 用户名  校验
     returnstr=Send(sendstr);   */
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ClientSocket1Read(TObject *Sender,
      TCustomWinSocket *Socket)
{
 //  int LinkNum=0;
   String sendstr = "";
   String str="";
   TStringList *revv=new TStringList();
   TStringList *splitString =new TStringList();
   char splitcom1[3];
   memset(splitcom1,0,3);
   splitcom1[0]=0xA1;splitcom1[1]=0xF5;

   char splitcom2[3];
   memset(splitcom2,0,3);
   splitcom2[0]=0xA1;splitcom2[1]=0xF6;

   String szString=Socket->ReceiveText();
 //  Memo1->Lines->Add(szString);

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


   splitString->Text="";
   ResolveString(szString,splitString,String(splitcom1));

   if(splitString->Strings[1].Trim()=="registerok")
   {
        MessageDlg("注册成功",mtInformation,TMsgDlgButtons()<<mbOK,0);
   }
   else if(splitString->Strings[1].Trim()=="registerexist")
   {
        MessageDlg("注册失败，此用户名已经存在",mtInformation,TMsgDlgButtons()<<mbOK,0);
   }
   else if(splitString->Strings[1].Trim()=="updatefail")
   {
        MessageDlg("IP同步失败，请先注册该用户名",mtInformation,TMsgDlgButtons()<<mbOK,0);
   }
   else if(splitString->Strings[1].Trim()=="updateok")
   {
        MessageDlg("IP同步成功",mtInformation,TMsgDlgButtons()<<mbOK,0);
   }
   else if(splitString->Strings[1].Trim()=="updatepasswordok")
   {
        MessageDlg("密码修改成功",mtInformation,TMsgDlgButtons()<<mbOK,0);
   }
   else if(splitString->Strings[1].Trim()=="updatepasswordfail")
   {
        MessageDlg("密码修改失败，请先该注册用户名",mtInformation,TMsgDlgButtons()<<mbOK,0);
   }
   else if(splitString->Strings[1].Trim()=="passworderror")
   {
        MessageDlg("密码输入错误，请重新输入",mtInformation,TMsgDlgButtons()<<mbOK,0);
   }
   else if(splitString->Strings[1].Trim()=="unknow")
   {
        MessageDlg("未知错误",mtInformation,TMsgDlgButtons()<<mbOK,0);
   }

   Form2->ClientSocket1->Active=false;

   this->StatusBar1->Panels->Items[0]->Text="服务器已经开启，正在监听...";


}
//---------------------------------------------------------------------------


void __fastcall TForm2::BitBtn6Click(TObject *Sender)
{
   String Dir;
   if(SelectDirectory("Directory Name","",Dir))
   {
         if(Dir.SubString(Dir.Length(),1)!="\\")
         {
                   Dir=Dir+"\\";
         }
        try
        {
              String datetime= Now().FormatString("yyyymmddhhnnss");
              String FileName="数据备份";
              REVLIST->Items->SaveToFile(Dir+FileName+"-"+datetime+".txt") ;

              MessageDlg("保存成功",mtInformation,TMsgDlgButtons()<<mbOK,0);
        }
        catch (Exception &exception)
        {
                Application->ShowException(&exception);
        }
   }
   else
   return;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn9Click(TObject *Sender)
{
       IMPORTDATA="未传.TXT";
       BitBtn3Click(Sender); 
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn7Click(TObject *Sender)
{
     IMPORTDATA="进销存.TXT";
     BitBtn3Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn8Click(TObject *Sender)
{
     IMPORTDATA="基本资料.TXT";
     BitBtn3Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N30Click(TObject *Sender)
{
    Form38->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N31Click(TObject *Sender)
{
    Form40->Show();
}
//---------------------------------------------------------------------------

