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
    ShowMessage("��û��Ȩ�޲鿴��棡");
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
     this->StatusBar1->Panels->Items[0]->Text="�������Ѿ����������ڼ���...";

     delete ini;

    //��ȡ������ip
    WSADATA Data_WSA;
    int Result_WSAStartup = 1;

    hostent *P_Host = NULL;
    char Computer_Name[128] = "";
    Result_WSAStartup = WSAStartup(MAKEWORD(2, 2), &Data_WSA);
     if (Result_WSAStartup != 0)//�޴���0
     {
         MessageBox(NULL, "�������ϣ��޷����������������ϵ�������Ա","��ʾ",MB_ICONASTERISK);
         return ;
     }
     gethostname(Computer_Name, 128);//��ȡָ�������������
     if(Computer_Name[0] == '\0')
     {
         MessageBox(NULL, "����������ϣ��޷����������������ϵ�������Ա","��ʾ",MB_ICONASTERISK);
         return ;
     }
     //Memo1->Text = s;
     P_Host = gethostbyname(Computer_Name);
     if(P_Host == NULL)
     {
         //Memo1->Text = "p NULL ";
         MessageBox(NULL, "����������ϣ��޷���ȡIP������ϵ����Ա","��ʾ",MB_ICONASTERISK);
         return ;
     }
     String IP_Host=inet_ntoa(*((in_addr *)P_Host->h_addr));//��ȡָ���������IP��ַ

     P_Host = NULL;
     WSACleanup();//��ɶ�WSAStartup()�ĵ���
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
     int site = 1, Len = 0;//��ǰ��ȡ��λ��
     String astrTemp, OutStr;

    Aim->Clear();
     //����Ҫ�ֽ�Ϊ���ٸ��Ӵ�
     for (int i = 1; i <= Count; i++)
         if (Source.SubString(i,2) == flag) {Len++;i++;}

    //��ʼ��ȡ�ַ�
     for (int i = 0; i < Len; i++)//�����ѭ��
     {
         for (; site <= Count; site++)//�ַ���ѭ��
         {
             astrTemp = Source.SubString(site,2); //��ȡһ���ַ�
             if (astrTemp ==  flag)
             {   /*������ֵ�ǰȡ����Ϊ�ָ�������ô�����ָ���������ѭ��
                   ����ʼ��һ���ַ����Ľ�ȡ*/
                 site++;
                 site++;
                 break;
             }
             OutStr = OutStr + astrTemp.SubString(0,1);//�ϲ����ַ���
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
     /*С�����ϵ����ּ���һ��Ҫ��������ܴ�ó�����*/
    int value[10]={VK_NUMPAD0,VK_NUMPAD1,VK_NUMPAD2,VK_NUMPAD3,VK_NUMPAD4,VK_NUMPAD5,VK_NUMPAD6,VK_NUMPAD7,VK_NUMPAD8,VK_NUMPAD9} ;
    bool bShift = false;
    char s[3]={0};      //������������ֵ�
    int length =strlen(inbuff.c_str());
    for(int index = 0;index < length;index+=j)
    {
        int val = inbuff.c_str()[index];
        if(val>=0 && val<=127)
       {
         // ShowMessage(inbuff.c_str()[index]);
         j=1;
        if(val >= 97 && val <= 122)    //Сдa-z
        {
           val -= 32;
           bShift = false;
        }
        else if(val >= 65 && val <= 90) //��дA-Z
        {
            bShift = true;
        }
        else if(val >= 48 && val <= 57) //����0-9
        {
             bShift = false;
        }
        //�������
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
      }else  //��ӡ���ĵ�
      {
         j=2;
         s[0]=inbuff.c_str()[index], s[1]=inbuff.c_str()[index+1];   //��ȡ�����ַ�

         String str=String(((BYTE)s[0]<<8)+(BYTE)s[1]);   //ת��������
         keybd_event(VK_MENU, MapVirtualKey(VK_MENU, 0), 0, 0);    //��ʼ��ӡ
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
            //У��
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

     //�ڴ˴�д����Э��===================================================

      TStringList *revv=new TStringList();
      TStringList *splitString =new TStringList();

      TStringList *showinf1 =new TStringList();
      TStringList *showinf2 =new TStringList();
      String barcode="";
      TStringList *bList =new TStringList();
     // TStringList *barlist =new TStringList();
      //TStringList *numlist =new TStringList();
      int AddData=1;

      int android=0;  //0�̵��   1�ֻ�

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
                    MessageBox(NULL, "У��ʧ��","��ʾ",MB_ICONASTERISK);
                    return;//У��ʧ�ܣ�����
                }

                splitString->Text="";
                ResolveString(szString,splitString,String(splitcom1));

                //�������Ƿ���ȷ
                bList->Text="";
                Form1->CrnListSplitString(splitString->Strings[0]+"-",bList,'-');
                if(bList->Strings[1].Trim()!=RSname) //���ֲ���ȷ������
                return;

                //�����Ƿ����Ѿ��Ǽ�¼����

                int i = 0;
              //  int j=0;

                if(splitString->Strings[1]=="COMPUTER")
                {
                    splitString->Strings[1]=Socket->RemoteAddress+":"+Socket->RemotePort;
                }

                for (i = 0; i < sourcename->Count; i++) //���Ƿ��з���ռ�
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


                     // ��λ�ͻ���
                 for(LinkNum=ServerSocket1->Socket->ActiveConnections-1;LinkNum>=0;LinkNum--)
                 {
                         if(ServerSocket1->Socket->Connections[LinkNum]->RemoteAddress==ip&&ServerSocket1->Socket->Connections[LinkNum]->RemotePort==port)
                         {

                             break;
                         }
                 }

                 if(LinkNum==ServerSocket1->Socket->ActiveConnections)
                 {
                        //ʧȥ����ϵ������
                        MessageBox(NULL, "ʧȥ��ϵ","��ʾ",MB_ICONASTERISK);
                        return;
                 }

                 if (splitString->Strings[2] == "LOGIN")
                 {
                        //У�������Ƿ���ȷ
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

                        //�ڴ˴��������к�
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

                        int password_number[5];//���4λ���ɣ��а�λ����

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
                            //�ɹ�
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
                    //��ѯ���ϲ��ҷ���
                    // Talk^������^����,����1������2������3^+У��+
                    String inf="";
                    Form1->Search_ADOQuery->Close();
                    Form1->Search_ADOQuery->SQL->Clear();
                    Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where ���� like \""+splitString->Strings[3].Trim()+"\"");
                    Form1->Search_ADOQuery->Active= true;


                    if(Form1->Search_ADOQuery->RecordCount==0)
                    {
                        inf=String().sprintf("%s,��--,",splitString->Strings[3].Trim());
                    }
                    else
                    {
                        if(splitString->Strings[5].Trim()=="UD"||splitString->Strings[5].Trim()=="CX")
                        {
                            if(android==0)
                            {
                                if(Form1->Pshow=="show")
                                inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",
                                             Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("���")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("�ͺ�")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("�ۼ�")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("��λ")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("��עһ")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("��ע��")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("��ע��")->AsString.Trim()
                                             );
                                  else
                                  inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",
                                             Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("���")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("�ͺ�")->AsString.Trim(),
                                             "0",
                                             Form1->Search_ADOQuery->FieldByName("�ۼ�")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("��λ")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("��עһ")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("��ע��")->AsString.Trim(),
                                             Form1->Search_ADOQuery->FieldByName("��ע��")->AsString.Trim()
                                             );
                            }
                            else
                            {
                                if(Form1->Pshow=="show")
                                inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",
                                             Form1->infshow1,
                                             Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),
                                             Form1->infshow2,
                                             Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),
                                             Form1->infshow3,
                                             Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),
                                             Form1->infshow4,
                                             Form1->Search_ADOQuery->FieldByName("���")->AsString.Trim(),
                                             Form1->infshow5,
                                             Form1->Search_ADOQuery->FieldByName("�ͺ�")->AsString.Trim(),
                                             Form1->infshow6,
                                             Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),
                                             Form1->infshow7,
                                             Form1->Search_ADOQuery->FieldByName("�ۼ�")->AsString.Trim(),
                                             Form1->infshow8,
                                             Form1->Search_ADOQuery->FieldByName("��λ")->AsString.Trim(),
                                             Form1->infshow9,
                                             Form1->Search_ADOQuery->FieldByName("��עһ")->AsString.Trim(),
                                             Form1->infshow10,
                                             Form1->Search_ADOQuery->FieldByName("��ע��")->AsString.Trim(),
                                             Form1->infshow11,
                                             Form1->Search_ADOQuery->FieldByName("��ע��")->AsString.Trim()
                                             );
                                  else
                                  inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",
                                             Form1->infshow1,
                                             Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),
                                             Form1->infshow2,
                                             Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),
                                             Form1->infshow3,
                                             Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),
                                             Form1->infshow4,
                                             Form1->Search_ADOQuery->FieldByName("���")->AsString.Trim(),
                                             Form1->infshow5,
                                             Form1->Search_ADOQuery->FieldByName("�ͺ�")->AsString.Trim(),
                                             Form1->infshow6,
                                             "0",
                                             Form1->infshow7,
                                             Form1->Search_ADOQuery->FieldByName("�ۼ�")->AsString.Trim(),
                                             Form1->infshow8,
                                             Form1->Search_ADOQuery->FieldByName("��λ")->AsString.Trim(),
                                             Form1->infshow9,
                                             Form1->Search_ADOQuery->FieldByName("��עһ")->AsString.Trim(),
                                             Form1->infshow10,
                                             Form1->Search_ADOQuery->FieldByName("��ע��")->AsString.Trim(),
                                             Form1->infshow11,
                                             Form1->Search_ADOQuery->FieldByName("��ע��")->AsString.Trim()
                                             );
                            }
                        }
                        else if(splitString->Strings[5].Trim()=="RK")
                        {
                            if(Form1->Pshow=="show")
                            {
                                if(android==0)inf=String().sprintf("%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->rksendback1)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->rksendback2)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->rksendback3)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->rksendback4)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->rksendback5)->AsString.Trim());
                                else inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),Form1->rksendstring1,Form1->Search_ADOQuery->FieldByName(Form1->rksendback1)->AsString.Trim(),Form1->rksendstring2,Form1->Search_ADOQuery->FieldByName(Form1->rksendback2)->AsString.Trim(),Form1->rksendstring3,Form1->Search_ADOQuery->FieldByName(Form1->rksendback3)->AsString.Trim(),Form1->rksendstring4,Form1->Search_ADOQuery->FieldByName(Form1->rksendback4)->AsString.Trim(),Form1->rksendstring5,Form1->Search_ADOQuery->FieldByName(Form1->rksendback5)->AsString.Trim());
                            }
                            else
                            {
                                String str1="";
                                String str2="";
                                String str3="";
                                String str4="";
                                String str5="";
                                if(Form1->rksendback1=="����")str1="0";else str1=Form1->Search_ADOQuery->FieldByName(Form1->rksendback1)->AsString.Trim();
                                if(Form1->rksendback2=="����")str2="0";else str2=Form1->Search_ADOQuery->FieldByName(Form1->rksendback2)->AsString.Trim();
                                if(Form1->rksendback3=="����")str3="0";else str3=Form1->Search_ADOQuery->FieldByName(Form1->rksendback3)->AsString.Trim();
                                if(Form1->rksendback4=="����")str4="0";else str4=Form1->Search_ADOQuery->FieldByName(Form1->rksendback4)->AsString.Trim();
                                if(Form1->rksendback5=="����")str5="0";else str5=Form1->Search_ADOQuery->FieldByName(Form1->rksendback5)->AsString.Trim();
                                if(android==0)inf=String().sprintf("%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),str1,str2,str3,str4,str5);
                                else inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),Form1->rksendstring1,str1,Form1->rksendstring2,str2,Form1->rksendstring3,str3,Form1->rksendstring4,str4,Form1->rksendstring5,str5);
                            }
                        }
                        else if(splitString->Strings[5].Trim()=="PD")
                        {
                            if(Form1->Pshow=="show")
                            {
                                if(android==0)inf=String().sprintf("%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->pdsendback1)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->pdsendback2)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->pdsendback3)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->pdsendback4)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->pdsendback5)->AsString.Trim());
                                else inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),Form1->pdsendstring1,Form1->Search_ADOQuery->FieldByName(Form1->pdsendback1)->AsString.Trim(),Form1->pdsendstring2,Form1->Search_ADOQuery->FieldByName(Form1->pdsendback2)->AsString.Trim(),Form1->pdsendstring3,Form1->Search_ADOQuery->FieldByName(Form1->pdsendback3)->AsString.Trim(),Form1->pdsendstring4,Form1->Search_ADOQuery->FieldByName(Form1->pdsendback4)->AsString.Trim(),Form1->pdsendstring5,Form1->Search_ADOQuery->FieldByName(Form1->pdsendback5)->AsString.Trim());
                            }
                            else
                            {
                                String str1="";
                                String str2="";
                                String str3="";
                                String str4="";
                                String str5="";
                                if(Form1->pdsendback1=="����")str1="0";else str1=Form1->Search_ADOQuery->FieldByName(Form1->pdsendback1)->AsString.Trim();
                                if(Form1->pdsendback2=="����")str2="0";else str2=Form1->Search_ADOQuery->FieldByName(Form1->pdsendback2)->AsString.Trim();
                                if(Form1->pdsendback3=="����")str3="0";else str3=Form1->Search_ADOQuery->FieldByName(Form1->pdsendback3)->AsString.Trim();
                                if(Form1->pdsendback4=="����")str4="0";else str4=Form1->Search_ADOQuery->FieldByName(Form1->pdsendback4)->AsString.Trim();
                                if(Form1->pdsendback5=="����")str5="0";else str5=Form1->Search_ADOQuery->FieldByName(Form1->pdsendback5)->AsString.Trim();
                                if(android==0)inf=String().sprintf("%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),str1,str2,str3,str4,str5);
                                else inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),Form1->pdsendstring1,str1,Form1->pdsendstring2,str2,Form1->pdsendstring3,str3,Form1->pdsendstring4,str4,Form1->pdsendstring5,str5);
                            }
                        }
                        else if(splitString->Strings[5].Trim()=="YK")
                        {
                            if(Form1->Pshow=="show")
                            {
                                if(android==0)inf=String().sprintf("%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->yksendback1)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->yksendback2)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->yksendback3)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->yksendback4)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->yksendback5)->AsString.Trim());
                                else inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),Form1->yksendstring1,Form1->Search_ADOQuery->FieldByName(Form1->yksendback1)->AsString.Trim(),Form1->yksendstring2,Form1->Search_ADOQuery->FieldByName(Form1->yksendback2)->AsString.Trim(),Form1->yksendstring3,Form1->Search_ADOQuery->FieldByName(Form1->yksendback3)->AsString.Trim(),Form1->yksendstring4,Form1->Search_ADOQuery->FieldByName(Form1->yksendback4)->AsString.Trim(),Form1->yksendstring5,Form1->Search_ADOQuery->FieldByName(Form1->yksendback5)->AsString.Trim());
                            }
                            else
                            {
                                String str1="";
                                String str2="";
                                String str3="";
                                String str4="";
                                String str5="";
                                if(Form1->yksendback1=="����")str1="0";else str1=Form1->Search_ADOQuery->FieldByName(Form1->yksendback1)->AsString.Trim();
                                if(Form1->yksendback2=="����")str2="0";else str2=Form1->Search_ADOQuery->FieldByName(Form1->yksendback2)->AsString.Trim();
                                if(Form1->yksendback3=="����")str3="0";else str3=Form1->Search_ADOQuery->FieldByName(Form1->yksendback3)->AsString.Trim();
                                if(Form1->yksendback4=="����")str4="0";else str4=Form1->Search_ADOQuery->FieldByName(Form1->yksendback4)->AsString.Trim();
                                if(Form1->yksendback5=="����")str5="0";else str5=Form1->Search_ADOQuery->FieldByName(Form1->yksendback5)->AsString.Trim();
                                if(android==0)inf=String().sprintf("%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),str1,str2,str3,str4,str5);
                                else inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),Form1->yksendstring1,str1,Form1->yksendstring2,str2,Form1->yksendstring3,str3,Form1->yksendstring4,str4,Form1->yksendstring5,str5);
                            }
                        }
                        else if(splitString->Strings[5].Trim()=="YD")
                        {
                            if(Form1->Pshow=="show")
                            {
                                if(android==0)inf=String().sprintf("%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->ydsendback1)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->ydsendback2)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->ydsendback3)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->ydsendback4)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->ydsendback5)->AsString.Trim());
                                else inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),Form1->ydsendstring1,Form1->Search_ADOQuery->FieldByName(Form1->ydsendback1)->AsString.Trim(),Form1->ydsendstring2,Form1->Search_ADOQuery->FieldByName(Form1->ydsendback2)->AsString.Trim(),Form1->ydsendstring3,Form1->Search_ADOQuery->FieldByName(Form1->ydsendback3)->AsString.Trim(),Form1->ydsendstring4,Form1->Search_ADOQuery->FieldByName(Form1->ydsendback4)->AsString.Trim(),Form1->ydsendstring5,Form1->Search_ADOQuery->FieldByName(Form1->ydsendback5)->AsString.Trim());
                            }
                            else
                            {
                                String str1="";
                                String str2="";
                                String str3="";
                                String str4="";
                                String str5="";
                                if(Form1->ydsendback1=="����")str1="0";else str1=Form1->Search_ADOQuery->FieldByName(Form1->ydsendback1)->AsString.Trim();
                                if(Form1->ydsendback2=="����")str2="0";else str2=Form1->Search_ADOQuery->FieldByName(Form1->ydsendback2)->AsString.Trim();
                                if(Form1->ydsendback3=="����")str3="0";else str3=Form1->Search_ADOQuery->FieldByName(Form1->ydsendback3)->AsString.Trim();
                                if(Form1->ydsendback4=="����")str4="0";else str4=Form1->Search_ADOQuery->FieldByName(Form1->ydsendback4)->AsString.Trim();
                                if(Form1->ydsendback5=="����")str5="0";else str5=Form1->Search_ADOQuery->FieldByName(Form1->ydsendback5)->AsString.Trim();
                                if(android==0)inf=String().sprintf("%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),str1,str2,str3,str4,str5);
                                else inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),Form1->ydsendstring1,str1,Form1->ydsendstring2,str2,Form1->ydsendstring3,str3,Form1->ydsendstring4,str4,Form1->ydsendstring5,str5);
                            }
                        }
                        else if(splitString->Strings[5].Trim()=="CK")
                        {
                            if(Form1->Pshow=="show")
                            {
                                if(android==0)inf=String().sprintf("%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->cksendback1)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->cksendback2)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->cksendback3)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->cksendback4)->AsString.Trim(),Form1->Search_ADOQuery->FieldByName(Form1->cksendback5)->AsString.Trim());
                                else inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),Form1->cksendstring1,Form1->Search_ADOQuery->FieldByName(Form1->cksendback1)->AsString.Trim(),Form1->cksendstring2,Form1->Search_ADOQuery->FieldByName(Form1->cksendback2)->AsString.Trim(),Form1->cksendstring3,Form1->Search_ADOQuery->FieldByName(Form1->cksendback3)->AsString.Trim(),Form1->cksendstring4,Form1->Search_ADOQuery->FieldByName(Form1->cksendback4)->AsString.Trim(),Form1->cksendstring5,Form1->Search_ADOQuery->FieldByName(Form1->cksendback5)->AsString.Trim());
                            }
                            else
                            {
                                String str1="";
                                String str2="";
                                String str3="";
                                String str4="";
                                String str5="";
                                if(Form1->cksendback1=="����")str1="0";else str1=Form1->Search_ADOQuery->FieldByName(Form1->cksendback1)->AsString.Trim();
                                if(Form1->cksendback2=="����")str2="0";else str2=Form1->Search_ADOQuery->FieldByName(Form1->cksendback2)->AsString.Trim();
                                if(Form1->cksendback3=="����")str3="0";else str3=Form1->Search_ADOQuery->FieldByName(Form1->cksendback3)->AsString.Trim();
                                if(Form1->cksendback4=="����")str4="0";else str4=Form1->Search_ADOQuery->FieldByName(Form1->cksendback4)->AsString.Trim();
                                if(Form1->cksendback5=="����")str5="0";else str5=Form1->Search_ADOQuery->FieldByName(Form1->cksendback5)->AsString.Trim();
                                if(android==0)inf=String().sprintf("%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),str1,str2,str3,str4,str5);
                                else inf=String().sprintf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,",Form1->Search_ADOQuery->FieldByName("����")->AsString.Trim(),Form1->cksendstring1,str1,Form1->cksendstring2,str2,Form1->cksendstring3,str3,Form1->cksendstring4,str4,Form1->cksendstring5,str5);
                            }
                        }
                    }



                    if(splitString->Strings[5].Trim()=="RK")
                    {
                         Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         Form1->Search_ADOQuery->SQL->Add("SELECT * FROM ��� where ���� like \""+splitString->Strings[3].Trim()+"\" AND �ֿ� like \""+splitString->Strings[4].Trim()+"\"");
                         Form1->Search_ADOQuery->Active= true;

                         if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("���")->AsFloat)+",";
                         else  inf=inf+"���,"+String(Form1->Search_ADOQuery->FieldByName("���")->AsFloat)+",";

                         Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         Form1->Search_ADOQuery->SQL->Add("SELECT * FROM ��� where ���� like \""+splitString->Strings[3].Trim()+"\" AND ��ⵥ�� like \""+splitString->Strings[6].Trim()+"\"");
                         Form1->Search_ADOQuery->Active= true;

                         int selectnum=0;
                         Double num=0;
                         selectnum=Form1->Search_ADOQuery->RecordCount;
                         for(int i=0;i<selectnum;i++)
                         {
                             num=num+Form1->Search_ADOQuery->FieldByName("�������")->AsFloat;
                             Form1->Search_ADOQuery->Next();
                         }
                         if(android==0)inf=inf+String(num)+",";
                         else  inf=inf+"�������,"+String(num)+",";
                    }
                    else if(splitString->Strings[5].Trim()=="CK")
                    {
                         Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         Form1->Search_ADOQuery->SQL->Add("SELECT * FROM ��� where ���� like \""+splitString->Strings[3].Trim()+"\" AND �ֿ� like \""+splitString->Strings[4].Trim()+"\"");
                         Form1->Search_ADOQuery->Active= true;

                         if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("���")->AsFloat)+",";
                         else  inf=inf+"���,"+String(Form1->Search_ADOQuery->FieldByName("���")->AsFloat)+",";

                         Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         Form1->Search_ADOQuery->SQL->Add("SELECT * FROM ���� where ���� like \""+splitString->Strings[3].Trim()+"\" AND ���ⵥ�� like \""+splitString->Strings[6].Trim()+"\"");
                         Form1->Search_ADOQuery->Active= true;

                         int selectnum=0;
                         Double num=0;
                         selectnum=Form1->Search_ADOQuery->RecordCount;
                         for(int i=0;i<selectnum;i++)
                         {
                             num=num+Form1->Search_ADOQuery->FieldByName("��������")->AsFloat;
                             Form1->Search_ADOQuery->Next();
                         }
                         if(android==0)inf=inf+String(num)+",";
                         else  inf=inf+"��������,"+String(num)+",";
                    }
                    else if(splitString->Strings[5].Trim()=="PD")
                    {
                       Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         Form1->Search_ADOQuery->SQL->Add("SELECT * FROM ��� where ���� like \""+splitString->Strings[3].Trim()+"\" AND �ֿ� like \""+splitString->Strings[4].Trim()+"\"");
                         Form1->Search_ADOQuery->Active= true;

                         if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("���")->AsFloat)+",";
                         else  inf=inf+"���,"+String(Form1->Search_ADOQuery->FieldByName("���")->AsFloat)+",";

                       Form1->Search_ADOQuery->Close();
                       Form1->Search_ADOQuery->SQL->Clear();
                       Form1->Search_ADOQuery->SQL->Add("SELECT * FROM �̵� where ���� like \""+splitString->Strings[3].Trim()+"\" AND �ֿ� like \""+splitString->Strings[4].Trim()+"\" AND ���� like \""+splitString->Strings[6].Trim()+"\"");
                       Form1->Search_ADOQuery->Active= true;

                       if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("�̵���")->AsFloat)+",";
                         else  inf=inf+"�̵���,"+String(Form1->Search_ADOQuery->FieldByName("�̵���")->AsFloat)+",";
                    }
                    else if(splitString->Strings[5].Trim()=="YK")
                    {
                       Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         Form1->Search_ADOQuery->SQL->Add("SELECT * FROM ��� where ���� like \""+splitString->Strings[3].Trim()+"\" AND �ֿ� like \""+splitString->Strings[4].Trim()+"\"");
                         Form1->Search_ADOQuery->Active= true;

                         if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("���")->AsFloat)+",";
                         else  inf=inf+"���,"+String(Form1->Search_ADOQuery->FieldByName("���")->AsFloat)+",";

                       Form1->Search_ADOQuery->Close();
                       Form1->Search_ADOQuery->SQL->Clear();
                       Form1->Search_ADOQuery->SQL->Add("SELECT * FROM �ƿ� where ���� like \""+splitString->Strings[3].Trim()+"\" AND ԭ�ֿ� like \""+splitString->Strings[4].Trim()+"\" AND Ŀ�Ĳֿ� like \""+splitString->Strings[6].Trim()+"\" AND �ƿⵥ�� like \""+splitString->Strings[7].Trim()+"\"");
                       Form1->Search_ADOQuery->Active= true;
                      // inf=inf+String(Form1->Search_ADOQuery->FieldByName("����")->AsFloat)+",";
                      int selectnum=0;
                      Double num=0;
                      selectnum=Form1->Search_ADOQuery->RecordCount;
                      for(int i=0;i<selectnum;i++)
                      {
                             num=num+Form1->Search_ADOQuery->FieldByName("����")->AsFloat;
                             Form1->Search_ADOQuery->Next();
                      }

                       if(android==0)inf=inf+String(num)+",";
                         else  inf=inf+"��������,"+String(num)+",";
                    }
                    else if(splitString->Strings[5].Trim()=="YD")
                    {
                         Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         Form1->Search_ADOQuery->SQL->Add("SELECT * FROM �鵥 where ���� like \""+splitString->Strings[3].Trim()+"\" AND ���� like \""+splitString->Strings[4].Trim()+"\"");
                         Form1->Search_ADOQuery->Active= true;


                         if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("Ӧɨ����")->AsFloat)+",";
                         else  inf=inf+"Ӧɨ����,"+String(Form1->Search_ADOQuery->FieldByName("Ӧɨ����")->AsFloat)+",";

                         if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("��ɨ����")->AsFloat)+",";
                         else  inf=inf+"��ɨ����,"+String(Form1->Search_ADOQuery->FieldByName("��ɨ����")->AsFloat)+",";



                    }
                    else if(splitString->Strings[5].Trim()=="CX")
                    {
                       Form1->Search_ADOQuery->Close();
                       Form1->Search_ADOQuery->SQL->Clear();
                       Form1->Search_ADOQuery->SQL->Add("SELECT * FROM ��� where ���� like \""+splitString->Strings[3].Trim()+"\" AND �ֿ� like \""+splitString->Strings[4].Trim()+"\"");
                       Form1->Search_ADOQuery->Active= true;
                       if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("���")->AsFloat)+",";
                         else  inf=inf+"���,"+String(Form1->Search_ADOQuery->FieldByName("���")->AsFloat)+",";
                       if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("�������")->AsFloat)+",";
                         else  inf=inf+"�������,"+String(Form1->Search_ADOQuery->FieldByName("�������")->AsFloat)+",";
                       if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("��������")->AsFloat)+",";
                         else  inf=inf+"��������,"+String(Form1->Search_ADOQuery->FieldByName("��������")->AsFloat)+",";
                       Form1->Search_ADOQuery->Close();
                       Form1->Search_ADOQuery->SQL->Clear();
                       Form1->Search_ADOQuery->SQL->Add("SELECT * FROM �̵�ͳ�� where ���� like \""+splitString->Strings[3].Trim()+"\" AND �ֿ� like \""+splitString->Strings[4].Trim()+"\"");
                       Form1->Search_ADOQuery->Active= true;
                       if(android==0)inf=inf+String(Form1->Search_ADOQuery->FieldByName("�̵���")->AsFloat)+",";
                         else  inf=inf+"�̵���,"+String(Form1->Search_ADOQuery->FieldByName("�̵���")->AsFloat)+",";
                    }

                    sendstr = "";
                    sendstr = "talk"+String(splitcom1)+ splitString->Strings[1] +String(splitcom1)+inf;
                    ServerSocket1->Socket->Connections[LinkNum]->SendText(Send(sendstr,android));
                    return;

                }

                if (splitString->Strings[2] == "PRINT")
                {
                    //��ѯ���ϲ��ҷ���
                    // Talk^������^����^+У��+
                    //��Ҫ��ӡ������    ���� ���� �۸� ���� С��
                    //�ظ���������================================================================================
                   if(wComm==INVALID_HANDLE_VALUE||wComm==NULL)
                   {
                       /*sendstr = "";
                       sendstr = "talk"+String(splitcom1)+splitString->Strings[3].Trim()+String(splitcom1)+"UNOPEN";
                       ServerSocket1->Socket->Connections[LinkNum]->SendText(Send(sendstr,android)); */


      //������ʾ                //REVLIST->Items->Add("��ʾ|��û�����Ӵ��ڴ�ӡ��������"+splitString->Strings[3].Trim()+"��ӡʧ�ܣ�");
                       //SendMessage(REVLIST-> Handle,   WM_VSCROLL,   SB_BOTTOM,   NULL);
                      // return;
                   }
                    /*sendstr = "";
                    sendstr = "talk"+String(splitcom1)+splitString->Strings[3].Trim()+String(splitcom1)+"PRINT";
                    ServerSocket1->Socket->Connections[LinkNum]->SendText(Send(sendstr,android)); //���߲ɼ������ݽ��յ���*/

                    if(splitString->Strings[4].Trim()=="RK")  //��ӡ��ⵥ��
                    {
			
	 /* 	     String print[]={"����","����","����","���","�ͺ�","����","�ۼ�","��λ","��עһ","��ע��","��ע��"};
			     TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
			     String RK1=ini->ReadString("Sys","RK1","1*2*6");

			     if(strstr(RK1.c_str(),"6")&&Form1->Pshow=="unshow")
			     {
			          REVLIST->Items->Add("��ʾ|����"+splitString->Strings[3].Trim()+"��ӡʧ�ܣ���û��Ȩ�޴�ӡ���ۣ�");
                                  SendMessage(REVLIST-> Handle,   WM_VSCROLL,   SB_BOTTOM,   NULL);
                                  return;
			     }
			
			     TStringList *bList =new TStringList();
			     Form1->CrnListSplitString(RK1,bList,'*');
			     String RK2=ini->ReadString("Sys","RK2","7");
			     String RK3=ini->ReadString("Sys","RK3","������ɽ��Ϣ�Ƽ����޹�˾");
			     int index=0;
			     for(int j=0;j<bList->Count;j++)
			     {
			         if(bList->Strings[j].Trim().ToInt()==RK2.Trim().ToInt())
			         index=1;
			     }
			
			     //��ȡ������======================================================
			     String barcode="";
			     unsigned long lrc;
			
			     float num=0;
			     float count=0;
			     float allcount=0;
			     String printstr="";
			
			     int selectnum=0;
			
			     Form1->RK_ADOQuery->Close();
			     Form1->RK_ADOQuery->SQL->Clear();
			     Form1->RK_ADOQuery->SQL->Add("SELECT * FROM ��� WHERE ��ⵥ�� like \""+splitString->Strings[3].Trim()+"\"");
			     Form1->RK_ADOQuery->Active= true;
			
			     selectnum=Form1->RK_ADOQuery->RecordCount;
			     printstr="";
			     printstr=RK3+"\r\n���ţ�"+splitString->Strings[3].Trim()+"\r\n"+"ʱ�䣺"+Now().FormatString("yyyy-mm-dd hh:nn:ss")+"\r\n--------------------------------";
			     WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL);
			     allcount=0;
			     for(int i=0;i<selectnum;i++)
			     {
			            num=Form1->RK_ADOQuery->FieldByName("�������")->AsFloat;
			            if(index==1)
			            {
			                count=Form1->RK_ADOQuery->FieldByName(print[RK2.Trim().ToInt()-1])->AsFloat*Form1->RK_ADOQuery->FieldByName("�������")->AsFloat;
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
			           printstr="\r\n--------------------------------��  �ƣ�"+String(allcount);
			           printstr+="\r\n�����ˣ�"+ Form1->RK_ADOQuery->FieldByName("Ա�����")->AsString;
			       }
			       else  printstr="\r\n--------------------------------�����ˣ�"+ Form1->RK_ADOQuery->FieldByName("Ա�����")->AsString;
			       printstr+="\r\n\r\n\r\n\r\n\r\n\r\n";
			       WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL);
			
			       //��ʾ��ӡ���
			       //ShowMessage("��ӡ�ɹ�");

			       delete ini;
			       delete bList;*/

			     Form1->RK_ADOQuery->Close();
			     Form1->RK_ADOQuery->SQL->Clear();
			     Form1->RK_ADOQuery->SQL->Add("SELECT * FROM ��� WHERE ��ⵥ�� like \""+splitString->Strings[3].Trim()+"\"");
			     Form1->RK_ADOQuery->Active= true;


     RKprint->QRLabel15->Caption="";
    RKprint->QRLabel16->Caption="��    ע��";
     RKprint->QRLabel7->Caption=Form1->infshow2.Trim();


     /*
     Double all=0;
       //�����ܽ��
       for(int i=0;i<Form1->RK_ADOQuery->RecordCount;i++)
       {
            all=all+Form1->RK_ADOQuery->FieldByName("�������")->AsFloat*Form1->RK_ADOQuery->FieldByName("����")->AsFloat;
            Form1->RK_ADOQuery->Next();
       }
       RKprint->QRLabel13->Caption=String(all);       */

       TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
       RKprint->QRLabel5->Caption=ini->ReadString("Sys","RK3","������ɽ��Ϣ�Ƽ����޹�˾");
       delete  ini;
       RKprint->QRLabel3->Caption=Now().FormatString("yyyy-mm-dd hh:nn:ss");
       //RKprint->QuickRep1->Preview();
       RKprint->QuickRep1->Print();
       RKprint->Close();

                        REVLIST->Items->Add("��ⵥ��"+splitString->Strings[3].Trim()+"��ӡ�ɹ�");
                       SendMessage(REVLIST-> Handle,   WM_VSCROLL,   SB_BOTTOM,   NULL);
                    }
                    else if(splitString->Strings[4].Trim()=="CK")  //��ӡ���ⵥ��
                    {
			
  /*			     String print[]={"����","����","����","���","�ͺ�","����","�ۼ�","��λ","��עһ","��ע��","��ע��"};
			     TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
			     String CK1=ini->ReadString("Sys","CK1","1*2*7");
			
			     if(strstr(CK1.c_str(),"6")&&Form1->Pshow=="unshow")
			     {
			          REVLIST->Items->Add("��ʾ|����"+splitString->Strings[3].Trim()+"��ӡʧ�ܣ���û��Ȩ�޴�ӡ���ۣ�");
                                  SendMessage(REVLIST-> Handle,   WM_VSCROLL,   SB_BOTTOM,   NULL);
                                  return;
			     }
			
			     TStringList *bList =new TStringList();
			     Form1->CrnListSplitString(CK1,bList,'*');
			     String CK2=ini->ReadString("Sys","CK2","7");
			     String CK3=ini->ReadString("Sys","CK3","������ɽ��Ϣ�Ƽ����޹�˾");
			     int index=0;
			     for(int j=0;j<bList->Count;j++)
			     {
			         if(bList->Strings[j].Trim().ToInt()==CK2.Trim().ToInt())
			         index=1;
			     }
			     //��ȡ������======================================================
			     String barcode="";
			     unsigned long lrc;
			
			     float num=0;
			     float count=0;
			     float allcount=0;
			     String printstr="";
			
			     int selectnum=0;
			
			     Form1->CK_ADOQuery->Close();
			     Form1->CK_ADOQuery->SQL->Clear();
			     Form1->CK_ADOQuery->SQL->Add("SELECT * FROM ���� WHERE ���ⵥ�� like \""+splitString->Strings[3].Trim()+"\"");
			     Form1->CK_ADOQuery->Active= true;
			
			     selectnum=Form1->CK_ADOQuery->RecordCount;
			     printstr="";
			     printstr=CK3+"\r\n���ţ�"+splitString->Strings[3].Trim()+"\r\n"+"ʱ�䣺"+Now().FormatString("yyyy-mm-dd hh:nn:ss")+"\r\n--------------------------------";
			     WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL);
			     allcount=0;
			     for(int i=0;i<selectnum;i++)
			     {
			            num=Form1->CK_ADOQuery->FieldByName("��������")->AsFloat;
			            if(index==1)
			            {
			                count=Form1->CK_ADOQuery->FieldByName(print[CK2.Trim().ToInt()-1])->AsFloat*Form1->CK_ADOQuery->FieldByName("��������")->AsFloat;
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
			           printstr="\r\n--------------------------------��  �ƣ�"+String(allcount);
			           printstr+="\r\n�����ˣ�"+ Form1->CK_ADOQuery->FieldByName("Ա�����")->AsString;
			       }
			       else  printstr="\r\n--------------------------------�����ˣ�"+ Form1->CK_ADOQuery->FieldByName("Ա�����")->AsString;
			       printstr+="\r\n\r\n\r\n\r\n\r\n\r\n";
			       WriteFile(Form2->wComm,printstr.c_str(),printstr.Length(),&lrc,NULL);
			
			       //��ʾ��ӡ���
			     //  ShowMessage("��ӡ�ɹ�");
			
			       delete ini;
			       delete bList;  */


			     Form1->CK_ADOQuery->Close();
			     Form1->CK_ADOQuery->SQL->Clear();
			     Form1->CK_ADOQuery->SQL->Add("SELECT * FROM ���� WHERE ���ⵥ�� like \""+splitString->Strings[3].Trim()+"\"");
			     Form1->CK_ADOQuery->Active= true;


     CKprint->QRLabel15->Caption="";
    CKprint->QRLabel16->Caption="��    ע��";
     CKprint->QRLabel7->Caption=Form1->infshow2.Trim();


       /*
     Double all=0;
       //�����ܽ��
     for(int i=0;i<Form1->CK_ADOQuery->RecordCount;i++)
     {
            all=all+Form1->CK_ADOQuery->FieldByName("��������")->AsFloat*Form1->CK_ADOQuery->FieldByName("�ۼ�")->AsFloat;
            Form1->CK_ADOQuery->Next();
     }
     CKprint->QRLabel13->Caption=String(all);  */
     TIniFile   *ini=new   TIniFile(ExtractFileDir(Application->ExeName)+"\\configinfo.ini");
     CKprint->QRLabel5->Caption=ini->ReadString("Sys","CK3","������ɽ��Ϣ�Ƽ����޹�˾");
     delete  ini;
     CKprint->QRLabel3->Caption=Now().FormatString("yyyy-mm-dd hh:nn:ss");

    // CKprint->QuickRep1->Preview();

       CKprint->QuickRep1->Print();
       CKprint->Close();
                        REVLIST->Items->Add("���ⵥ��"+splitString->Strings[3].Trim()+"��ӡ�ɹ�");
                       SendMessage(REVLIST-> Handle,   WM_VSCROLL,   SB_BOTTOM,   NULL);
                    }


                    return;
                }




                //���ͻ��˶Ͽ����ӵ�ʱ��������ķ�Ӧ���������Ĵ���

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
                        //�����յ���һ����
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

                 //�ڴ˴���ʾ
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

                  Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where ���� like \""+barcode.Trim()+"\"");

                  Form1->Search_ADOQuery->Active= true;

                  inf1->Text=barcode;
                  inf2->Text=Form1->Search_ADOQuery->FieldByName("����")->AsString;
                  inf3->Text=Form1->Search_ADOQuery->FieldByName("����")->AsString;
                  inf4->Text=Form1->Search_ADOQuery->FieldByName("���")->AsString;
                  inf5->Text=Form1->Search_ADOQuery->FieldByName("�ͺ�")->AsString;
                  if(Form1->Pshow=="show")inf6->Text=String(Form1->Search_ADOQuery->FieldByName("����")->AsFloat);
                  inf7->Text=String(Form1->Search_ADOQuery->FieldByName("�ۼ�")->AsFloat);
                  inf8->Text=Form1->Search_ADOQuery->FieldByName("��λ")->AsString;
                  inf9->Text=Form1->Search_ADOQuery->FieldByName("��עһ")->AsString;
                  inf10->Text=Form1->Search_ADOQuery->FieldByName("��ע��")->AsString;
                  inf11->Text=Form1->Search_ADOQuery->FieldByName("��ע��")->AsString;


                  float Sprace=Form1->Search_ADOQuery->FieldByName("�ۼ�")->AsFloat;
                  float Jprace=Form1->Search_ADOQuery->FieldByName("����")->AsFloat;

                 //----------------------------------------------------------------------------------------


                 //�޸����ݿ����������Ϣ===========================================================================
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
                       if(qlist->Strings[0]=="CK"||qlist->Strings[0]=="RK")str=String().sprintf("SELECT * FROM ��� WHERE ���� like \"%s\" AND �ֿ� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[2].Trim());
                       else if(qlist->Strings[0]=="PD")  str=String().sprintf("SELECT * FROM ��� WHERE ���� like \"%s\" AND �ֿ� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim());
                       else if(qlist->Strings[0]=="YK")  str=String().sprintf("SELECT * FROM ��� WHERE ���� like \"%s\" AND �ֿ� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[2].Trim());
                       Form1->Search_ADOQuery->SQL->Add(str);
                       Form1->Search_ADOQuery->Active= true;

                       if(Form1->Search_ADOQuery->RecordCount==0)index0=0;
                       else index0=1;

                       RKnum=Form1->Search_ADOQuery->FieldByName("�������")->AsFloat;
                       CKnum=Form1->Search_ADOQuery->FieldByName("��������")->AsFloat;
                       KCnum=Form1->Search_ADOQuery->FieldByName("���")->AsFloat;
                       }


                      if(qlist->Strings[0]=="UD")
                      {
                           Form1->Search_ADOQuery->Close();
                           Form1->Search_ADOQuery->SQL->Clear();
                           Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where ���� like \""+mlist->Strings[0].Trim()+"\"");
                           Form1->Search_ADOQuery->Active= true;

                           if(Form1->Search_ADOQuery->RecordCount==0)
                           {
                                 Form1->ADOTable1->Insert();
                                 Form1->ADOTable1->FieldByName("����")->AsString = mlist->Strings[0].Trim();
                                 if(mlist->Strings[1].Trim().Length()!=0)Form1->ADOTable1->FieldByName("����")->AsString = mlist->Strings[1].Trim();
                                 else  Form1->ADOTable1->FieldByName("����")->AsString ="   ";
                                 if(mlist->Strings[2].Trim().Length()!=0)Form1->ADOTable1->FieldByName("����")->AsString = mlist->Strings[2].Trim();
                                 else  Form1->ADOTable1->FieldByName("����")->AsString ="   ";
                                 if(mlist->Strings[3].Trim().Length()!=0)Form1->ADOTable1->FieldByName("���")->AsString = mlist->Strings[3].Trim();
                                 else  Form1->ADOTable1->FieldByName("���")->AsString ="   ";
                                 if(mlist->Strings[4].Trim()!=0)Form1->ADOTable1->FieldByName("�ͺ�")->AsString = mlist->Strings[4].Trim();
                                 else  Form1->ADOTable1->FieldByName("�ͺ�")->AsString ="   ";
                                 if(Form1->Pshow=="show")
                                 {
                                     if(mlist->Strings[5].Trim().Length()!=0)Form1->ADOTable1->FieldByName("����")->AsFloat = mlist->Strings[5].Trim().ToDouble();
                                     else  Form1->ADOTable1->FieldByName("����")->AsFloat =0;
                                 }
                                 if(mlist->Strings[6].Trim().Length()!=0)Form1->ADOTable1->FieldByName("�ۼ�")->AsFloat = mlist->Strings[6].Trim().ToDouble();
                                 else  Form1->ADOTable1->FieldByName("�ۼ�")->AsFloat =0;
                                 if(mlist->Strings[7].Trim().Length()!=0)Form1->ADOTable1->FieldByName("��λ")->AsString = mlist->Strings[7].Trim();
                                 else  Form1->ADOTable1->FieldByName("��λ")->AsString ="   ";
                                 if(mlist->Strings[8].Trim().Length()!=0)Form1->ADOTable1->FieldByName("��עһ")->AsString = mlist->Strings[8].Trim();
                                 else  Form1->ADOTable1->FieldByName("��עһ")->AsString ="   ";
                                 if(mlist->Strings[9].Trim().Length()!=0)Form1->ADOTable1->FieldByName("��ע��")->AsString = mlist->Strings[9].Trim();
                                 else  Form1->ADOTable1->FieldByName("��ע��")->AsString ="   ";
                                 if(mlist->Strings[10].Trim().Length()!=0)Form1->ADOTable1->FieldByName("��ע��")->AsString = mlist->Strings[10].Trim();
                                 else  Form1->ADOTable1->FieldByName("��ע��")->AsString ="   ";
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
                                     str=str+" ���� = \""+mlist->Strings[1].Trim()+" \"";
                                     index=0;
                                 }
                                 if(mlist->Strings[2].Trim().Length()!=0)
                                 {
                                     if(index==0)str=str+" ,";
                                     str=str+" ���� = \""+mlist->Strings[2].Trim()+" \"";
                                     index=0;
                                 }
                                 if(mlist->Strings[3].Trim().Length()!=0)
                                 {
                                     if(index==0)str=str+" ,";
                                     str=str+" ��� = \""+mlist->Strings[3].Trim()+" \"";
                                     index=0;
                                 }
                                 if(mlist->Strings[4].Trim().Length()!=0)
                                 {
                                     if(index==0)str=str+" ,";
                                     str=str+" �ͺ� = \""+mlist->Strings[4].Trim()+" \"";
                                     index=0;
                                 }
                                 if(Form1->Pshow=="show")
                                 {
                                     if(mlist->Strings[5].Trim().Length()!=0)
                                     {
                                        if(index==0)str=str+" ,";
                                        str=str+" ���� = "+mlist->Strings[5].Trim().ToDouble();
                                        index=0;
                                     }
                                 }
                                 if(mlist->Strings[6].Trim().Length()!=0)
                                 {
                                    if(index==0)str=str+" ,";
                                    str=str+" �ۼ� = "+mlist->Strings[6].Trim().ToDouble();
                                    index=0;
                                 }
                                 if(mlist->Strings[7].Trim().Length()!=0)
                                 {
                                    if(index==0)str=str+" ,";
                                    str=str+" ��λ = \""+mlist->Strings[7].Trim()+" \"";
                                    index=0;
                                 }
                                 if(mlist->Strings[8].Trim().Length()!=0)
                                 {
                                    if(index==0)str=str+" ,";
                                    str=str+" ��עһ = \""+mlist->Strings[8].Trim()+" \"";
                                    index=0;
                                 }
                                 if(mlist->Strings[9].Trim().Length()!=0)
                                 {
                                    if(index==0)str=str+" ,";
                                    str=str+" ��ע�� = \""+mlist->Strings[9].Trim()+" \"";
                                    index=0;
                                 }
                                 if(mlist->Strings[10].Trim().Length()!=0)
                                 {
                                    if(index==0)str=str+" ,";
                                    str=str+" ��ע�� = \""+mlist->Strings[10].Trim()+" \"";
                                    index=0;
                                 }
                                 if(mlist->Strings[1].Trim().Length()==0&&mlist->Strings[2].Trim().Length()==0&&mlist->Strings[3].Trim().Length()==0&&
                                    mlist->Strings[4].Trim().Length()==0&&mlist->Strings[5].Trim().Length()==0&&mlist->Strings[6].Trim().Length()==0&&
                                    mlist->Strings[7].Trim().Length()==0&&mlist->Strings[8].Trim().Length()==0&&mlist->Strings[9].Trim().Length()==0&&
                                    mlist->Strings[10].Trim().Length()==0)return;
                                 str=str+" WHERE ���� like \""+mlist->Strings[0].Trim()+"\"";

                                 Form1->ADOCommand1->CommandText = str;
                                 Form1->ADOCommand1->Execute();

                           }

                      }
                      else if(qlist->Strings[0]=="RK")
                      {
                         str="";
                         Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         str=String().sprintf("SELECT * FROM ��� WHERE ���� like \"%s\" AND ��ⵥ�� like \"%s\" AND ���ֿ� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim(),qlist->Strings[2].Trim());
                         Form1->Search_ADOQuery->SQL->Add(str);
                         Form1->Search_ADOQuery->Active= true;

                         if(Form1->Search_ADOQuery->RecordCount==0)
                         {
                             Form1->RK_ADOTable->Insert();
                             Form1->RK_ADOTable->FieldByName("���ֿ�")->AsString = qlist->Strings[2].Trim();
                             Form1->RK_ADOTable->FieldByName("��ⵥ��")->AsString = qlist->Strings[1].Trim();
                             Form1->RK_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
                             Form1->RK_ADOTable->FieldByName("�������")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                             Form1->RK_ADOTable->FieldByName("���ʱ��")->AsString=StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
                             Form1->RK_ADOTable->FieldByName("Ա�����")->AsString = mlist->Strings[3].Trim();
                             Form1->RK_ADOTable->Post();
                         }
                         else
                         {
                             str="";
                             str=String().sprintf("UPDATE RK SET  ������� = %f , ���ʱ�� =  \"%s\" , Ա����� =  \"%s\"  WHERE ���� like \"%s\" AND ���ֿ� like \"%s\" AND ��ⵥ�� like \"%s\""
                                 ,mlist->Strings[1].Trim().ToDouble()+Form1->Search_ADOQuery->FieldByName("�������")->AsFloat
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
                            Form1->KC_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
                            Form1->KC_ADOTable->FieldByName("�������")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                            Form1->KC_ADOTable->FieldByName("�ֿ�")->AsString = qlist->Strings[2].Trim();
                            Form1->KC_ADOTable->FieldByName("���")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                            Form1->KC_ADOTable->Post();

                        }
                        else
                        {
                            str="";
                            str=String().sprintf("UPDATE KC SET  ������� = %f, ��� =%f  WHERE ���� like \"%s\" AND �ֿ� like \"%s\""
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
                         Double cost=0;//�ܳɱ�
                         Double sales=0;//�����۶�
                         Double profits=0;//������

                         if(KCnum<mlist->Strings[1].Trim().ToDouble())
                         {
                               REVLIST->Items->Add("��ʾ|�ڲֿ�"+ qlist->Strings[2].Trim()+"��ߣ�����"+mlist->Strings[0].Trim()+"��治��");
                               SendMessage(REVLIST-> Handle,   WM_VSCROLL,   SB_BOTTOM,   NULL);
                         }

                         if(mlist->Strings[4].Trim().Length()!=0||mlist->Strings[5].Trim()=="0")//0�����޸���
                         Sprace= mlist->Strings[4].Trim().ToDouble();

                         str="";
                         Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         str=String().sprintf("SELECT * FROM ���� WHERE ���� like \"%s\" AND ���ⵥ�� like \"%s\" AND ����ֿ� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim(),qlist->Strings[2].Trim());
                         Form1->Search_ADOQuery->SQL->Add(str);
                         Form1->Search_ADOQuery->Active= true;

                         if(Form1->Search_ADOQuery->RecordCount==0)
                         {
                             sales=Sprace*mlist->Strings[1].Trim().ToDouble();
                             cost=Jprace*mlist->Strings[1].Trim().ToDouble();
                             profits=sales-cost;

                             Form1->CK_ADOTable->Insert();
                             Form1->CK_ADOTable->FieldByName("����ֿ�")->AsString = qlist->Strings[2].Trim();
                             Form1->CK_ADOTable->FieldByName("���ⵥ��")->AsString = qlist->Strings[1].Trim();
                             Form1->CK_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
                             Form1->CK_ADOTable->FieldByName("��������")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                             Form1->CK_ADOTable->FieldByName("����ʱ��")->AsString=StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
                             Form1->CK_ADOTable->FieldByName("Ա�����")->AsString = mlist->Strings[3].Trim();
                             Form1->CK_ADOTable->FieldByName("�ۼ�")->AsFloat = Sprace;
                             Form1->CK_ADOTable->Post();
                         }
                         else
                         {
                             if(Sprace==Form1->Search_ADOQuery->FieldByName("�ۼ�")->AsFloat)
                             {
                                  sales=Sprace*mlist->Strings[1].Trim().ToDouble();
                                  cost=Jprace*mlist->Strings[1].Trim().ToDouble();
                                  profits=sales-cost;

                             }
                             else
                             {
                                  sales=Sprace*mlist->Strings[1].Trim().ToDouble()+(Sprace-Form1->Search_ADOQuery->FieldByName("�ۼ�")->AsFloat)*Form1->Search_ADOQuery->FieldByName("��������")->AsFloat;
                                  cost=Jprace*mlist->Strings[1].Trim().ToDouble();
                                  profits=sales-cost;
                             }


                             str="";
                             str=String().sprintf("UPDATE CK SET  �������� = %f , �ۼ� = %f , ����ʱ�� =  \"%s\" , Ա����� =  \"%s\"  WHERE ���� like \"%s\" AND ����ֿ� like \"%s\" AND ���ⵥ�� like \"%s\""
                                 ,mlist->Strings[1].Trim().ToDouble()+Form1->Search_ADOQuery->FieldByName("��������")->AsFloat
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
                              Form1->KC_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
                              Form1->KC_ADOTable->FieldByName("��������")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                              Form1->KC_ADOTable->FieldByName("�ֿ�")->AsString = qlist->Strings[2].Trim();
                              Form1->KC_ADOTable->FieldByName("���")->AsFloat = 0-mlist->Strings[1].Trim().ToDouble();
                              Form1->KC_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE KC SET  �������� = %f, ��� =%f  WHERE ���� like \"%s\" AND �ֿ� like \"%s\""
                                   ,mlist->Strings[1].Trim().ToDouble()+CKnum
                                   ,KCnum-mlist->Strings[1].Trim().ToDouble()
                                   ,mlist->Strings[0].Trim()
                                   ,qlist->Strings[2].Trim());
                              Form1->ADOCommand1->CommandText = str;
                              Form1->ADOCommand1->Execute();
                       }

                       //������������
                       str="";
                       Form1->XSTJ_ADOQuery->Close();
                       Form1->XSTJ_ADOQuery->SQL->Clear();
                       str=String().sprintf("SELECT * FROM ����ͳ�� WHERE ���ⵥ�� like \"%s\"",qlist->Strings[1].Trim());
                       Form1->XSTJ_ADOQuery->SQL->Add(str);
                       Form1->XSTJ_ADOQuery->Active= true;

                       if(Form1->XSTJ_ADOQuery->RecordCount==0)
                       {
                           Form1->XSTJ_ADOTable->Insert();
                           Form1->XSTJ_ADOTable->FieldByName("���ⵥ��")->AsString = qlist->Strings[1].Trim();
                           Form1->XSTJ_ADOTable->FieldByName("�ɱ�")->AsFloat = Jprace*mlist->Strings[1].Trim().ToDouble();
                           Form1->XSTJ_ADOTable->FieldByName("���۶�")->AsFloat = Sprace*mlist->Strings[1].Trim().ToDouble();
                           Form1->XSTJ_ADOTable->FieldByName("����")->AsFloat = (Sprace-Jprace)*mlist->Strings[1].Trim().ToDouble();
                           Form1->XSTJ_ADOTable->FieldByName("Ա�����")->AsString = mlist->Strings[3].Trim();
                           Form1->XSTJ_ADOTable->FieldByName("ʱ��")->AsString = StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);

                           Form1->XSTJ_ADOTable->Post();
                       }
                       else
                       {
                           str="";
                           str=String().sprintf("UPDATE XSTJ SET  �ɱ� = %f, ���۶� =%f , ���� =%f , ʱ�� =  \"%s\" WHERE ���ⵥ�� like \"%s\""
                                 ,cost+Form1->XSTJ_ADOQuery->FieldByName("�ɱ�")->AsFloat
                                 ,sales+Form1->XSTJ_ADOQuery->FieldByName("���۶�")->AsFloat
                                 ,profits+Form1->XSTJ_ADOQuery->FieldByName("����")->AsFloat
                                 ,StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase)
                                 ,qlist->Strings[1].Trim());
                           Form1->ADOCommand1->CommandText = str;
                           Form1->ADOCommand1->Execute();
                       }
                       



                 }
                 else if(qlist->Strings[0]=="PD")
                 {
                        //�޸��̵�ͳ�Ʊ�================================================================================================
                        float pdkc=0;
		        String str="";
		        Form1->Search_ADOQuery->Close();
		        Form1->Search_ADOQuery->SQL->Clear();
		        str=String().sprintf("SELECT * FROM �̵�ͳ�� WHERE ���� like \"%s\" AND �ֿ� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[2].Trim());
		        Form1->Search_ADOQuery->SQL->Add(str);
		        Form1->Search_ADOQuery->Active= true;
                        pdkc=Form1->Search_ADOQuery->FieldByName("�̵���")->AsFloat;
		
		        if(Form1->Search_ADOQuery->RecordCount==0)
		        {
		            Form1->PDTJ_ADOTable->Insert();
		            Form1->PDTJ_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
		            Form1->PDTJ_ADOTable->FieldByName("�̵���")->AsFloat = mlist->Strings[1].Trim().ToDouble();
		            Form1->PDTJ_ADOTable->FieldByName("�ֿ�")->AsString = qlist->Strings[2].Trim();  //����1  �ֿ�2
		            Form1->PDTJ_ADOTable->Post();
		        }
		        else
		        {
		            str="";
		            str=String().sprintf("UPDATE PDTJ SET  �̵��� = %f WHERE ���� like \"%s\" AND �ֿ� like \"%s\""
		                                   ,pdkc+mlist->Strings[1].Trim().ToDouble()
		                                   ,mlist->Strings[0].Trim()
		                                   ,qlist->Strings[2].Trim());
		            Form1->ADOCommand1->CommandText = str;
		            Form1->ADOCommand1->Execute();
		        }

		        //�޸��̵���ϸ��==================================================================================================
		        Form1->Search_ADOQuery->Close();
		        Form1->Search_ADOQuery->SQL->Clear();
		        str=String().sprintf("SELECT * FROM �̵� WHERE ���� like \"%s\" AND �ֿ� like \"%s\" AND ���� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[2].Trim(),qlist->Strings[1].Trim());
		        Form1->Search_ADOQuery->SQL->Add(str);
		        Form1->Search_ADOQuery->Active= true;
		        pdkc=Form1->Search_ADOQuery->FieldByName("�̵���")->AsFloat;

		        if(Form1->Search_ADOQuery->RecordCount==0)
		        {
		            Form1->PD_ADOTable->Insert();
		            Form1->PD_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
		            Form1->PD_ADOTable->FieldByName("�̵���")->AsFloat = mlist->Strings[1].Trim().ToDouble();
		            Form1->PD_ADOTable->FieldByName("�ֿ�")->AsString = qlist->Strings[2].Trim();
		            Form1->PD_ADOTable->FieldByName("����")->AsString = qlist->Strings[1].Trim();
		            Form1->PD_ADOTable->FieldByName("�̵�ʱ��")->AsString = StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
		            Form1->PD_ADOTable->FieldByName("Ա�����")->AsString = mlist->Strings[3].Trim();
		            Form1->PD_ADOTable->Post();
		        }
		        else
		        {
		            str="";
		            str=String().sprintf("UPDATE PD SET  �̵��� = %f , �̵�ʱ�� =\"%s\" , Ա����� = \"%s\" WHERE ���� like \"%s\" AND �ֿ� like \"%s\" AND ���� like \"%s\""
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
                        str=String().sprintf("SELECT * FROM �̵� WHERE ���� like \"%s\" AND �ֿ� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim());
                        Form1->Search_ADOQuery->SQL->Add(str);
                        Form1->Search_ADOQuery->Active= true;

                        pdkc=Form1->Search_ADOQuery->FieldByName("�̵���")->AsFloat;

                        if(Form1->Search_ADOQuery->RecordCount==0)
                        {
                              Form1->PD_ADOTable->Insert();
                              Form1->PD_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
                              Form1->PD_ADOTable->FieldByName("�̵���")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                              Form1->PD_ADOTable->FieldByName("�ֿ�")->AsString = qlist->Strings[1].Trim();
                              Form1->PD_ADOTable->FieldByName("�̵�ʱ��")->AsString = StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
                              Form1->PD_ADOTable->FieldByName("Ա�����")->AsString = mlist->Strings[3].Trim();
                              Form1->PD_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE PD SET  �̵��� = %f ,�̵�ʱ�� = \"%s\" ,Ա����� = \"%s\"  WHERE ���� like \"%s\" AND �ֿ� like \"%s\""
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
                        str=String().sprintf("SELECT * FROM �鵥 WHERE ���� like \"%s\" AND ���� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim());
                        Form1->Search_ADOQuery->SQL->Add(str);
                        Form1->Search_ADOQuery->Active= true;

                        pdkc=Form1->Search_ADOQuery->FieldByName("��ɨ����")->AsFloat;

                        if(Form1->Search_ADOQuery->RecordCount==0)
                        {
                              Form1->YD_ADOTable->Insert();
                              Form1->YD_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
                              Form1->YD_ADOTable->FieldByName("Ӧɨ����")->AsFloat = 0;
                              Form1->YD_ADOTable->FieldByName("��ɨ����")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                              Form1->YD_ADOTable->FieldByName("ʱ��")->AsString=StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
                              Form1->YD_ADOTable->FieldByName("����")->AsString = qlist->Strings[1].Trim();
                              Form1->YD_ADOTable->FieldByName("Ա�����")->AsString = mlist->Strings[3].Trim();
                              Form1->YD_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE YD SET  ��ɨ���� = %f ,ʱ�� = \"%s\" ,Ա����� = \"%s\"  WHERE ���� like \"%s\" AND ���� like \"%s\""
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
                        str=String().sprintf("SELECT * FROM �ƿ� WHERE ���� like \"%s\" AND �ƿⵥ�� like \"%s\" AND ԭ�ֿ� like \"%s\" AND Ŀ�Ĳֿ� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim(),qlist->Strings[2].Trim(),qlist->Strings[3].Trim());
                        Form1->Search_ADOQuery->SQL->Add(str);
                        Form1->Search_ADOQuery->Active= true;

                        pdkc=Form1->Search_ADOQuery->FieldByName("����")->AsFloat;

                        if(Form1->Search_ADOQuery->RecordCount==0)
                        { */
                              Form1->YK_ADOTable->Insert();
                              Form1->YK_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
                              Form1->YK_ADOTable->FieldByName("����")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                              Form1->YK_ADOTable->FieldByName("�ƿ�ʱ��")->AsString = StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
                              Form1->YK_ADOTable->FieldByName("�ƿⵥ��")->AsString = qlist->Strings[1].Trim();
                              Form1->YK_ADOTable->FieldByName("ԭ�ֿ�")->AsString = qlist->Strings[2].Trim();
                              Form1->YK_ADOTable->FieldByName("Ŀ�Ĳֿ�")->AsString = qlist->Strings[3].Trim();
                              Form1->YK_ADOTable->FieldByName("Ա�����")->AsString = mlist->Strings[3].Trim();
                              Form1->YK_ADOTable->Post();

                        /*}
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE YK SET  ���� = %f , �ƿ�ʱ�� =  \"%s\" , Ա����� =  \"%s\"  WHERE ���� like \"%s\" AND ԭ�ֿ� like \"%s\" AND Ŀ�Ĳֿ� like \"%s\""
                                 ,mlist->Strings[1].Trim().ToDouble()+pdkc
                                 ,StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase)
                                 ,mlist->Strings[3].Trim()
                                 ,mlist->Strings[0].Trim()
                                 ,qlist->Strings[1].Trim()
                                 ,qlist->Strings[2].Trim());
                            Form1->ADOCommand1->CommandText = str;
                            Form1->ADOCommand1->Execute();
                       } */

                       //�޸�ԭ�ֿ���
                    if(index0==0)
                        {
                              Form1->KC_ADOTable->Insert();
                              Form1->KC_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
                              Form1->KC_ADOTable->FieldByName("��������")->AsFloat = 0;
                              Form1->KC_ADOTable->FieldByName("�������")->AsFloat = 0;
                              Form1->KC_ADOTable->FieldByName("�ֿ�")->AsString = qlist->Strings[2].Trim();
                              Form1->KC_ADOTable->FieldByName("���")->AsFloat = 0-mlist->Strings[1].Trim().ToDouble();
                              Form1->KC_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE KC SET  ��� =%f  WHERE ���� like \"%s\" AND �ֿ� like \"%s\""
                                   ,KCnum-mlist->Strings[1].Trim().ToDouble()
                                   ,mlist->Strings[0].Trim()
                                   ,qlist->Strings[2].Trim());
                              Form1->ADOCommand1->CommandText = str;
                              Form1->ADOCommand1->Execute();
                       }

                       //�޸�Ŀ�Ĳֿ���
                       Form1->Search_ADOQuery->Close();
                       Form1->Search_ADOQuery->SQL->Clear();
                       str=String().sprintf("SELECT * FROM ��� WHERE ���� like \"%s\" AND �ֿ� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[3].Trim());
                       Form1->Search_ADOQuery->SQL->Add(str);
                       Form1->Search_ADOQuery->Active= true;
                       KCnum=Form1->Search_ADOQuery->FieldByName("���")->AsFloat;


                       if(Form1->Search_ADOQuery->RecordCount==0)
                        {
                              Form1->KC_ADOTable->Insert();
                              Form1->KC_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
                              Form1->KC_ADOTable->FieldByName("��������")->AsFloat = 0;
                              Form1->KC_ADOTable->FieldByName("�������")->AsFloat = 0;
                              Form1->KC_ADOTable->FieldByName("�ֿ�")->AsString = qlist->Strings[3].Trim();
                              Form1->KC_ADOTable->FieldByName("���")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                              Form1->KC_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE KC SET  ��� =%f  WHERE ���� like \"%s\" AND �ֿ� like \"%s\""
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
   Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where ���� like \""+barcode.Trim()+"\"");
   Form1->Search_ADOQuery->Active= true;

   inf1->Text=barcode;
   inf2->Text=Form1->Search_ADOQuery->FieldByName("����")->AsString;
   inf3->Text=Form1->Search_ADOQuery->FieldByName("����")->AsString;
   inf4->Text=Form1->Search_ADOQuery->FieldByName("���")->AsString;
   inf5->Text=Form1->Search_ADOQuery->FieldByName("�ͺ�")->AsString;
   if(Form1->Pshow=="show")inf6->Text=String(Form1->Search_ADOQuery->FieldByName("����")->AsFloat);
   inf7->Text=String(Form1->Search_ADOQuery->FieldByName("�ۼ�")->AsFloat);
   inf8->Text=Form1->Search_ADOQuery->FieldByName("��λ")->AsString;
   inf9->Text=Form1->Search_ADOQuery->FieldByName("��עһ")->AsString;
   inf10->Text=Form1->Search_ADOQuery->FieldByName("��ע��")->AsString;
   inf11->Text=Form1->Search_ADOQuery->FieldByName("��ע��")->AsString;
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

            if(wComm==INVALID_HANDLE_VALUE)//����δ��
            {

               MessageDlg("\n�򿪶˿�ʧ��\n�˿ڱ�ռ��",mtWarning ,TMsgDlgButtons()<<mbOK,0);
               return;

            }
            GetCommState(wComm,&dcb);

            dcb.BaudRate =9600;


            dcb.ByteSize = 8;

            dcb.Parity   = NOPARITY;
            dcb.StopBits = ONESTOPBIT;
        //ͨ�Ŷ˿�����
            if(!SetCommState(wComm,&dcb))
              {  //����ͨ�Ŷ˿ڵ�״̬
                 //MessageBox(0,"ͨ�Ŷ˿����ô���","Set Error",MB_OK);
                  MessageDlg("\nͨ�Ŷ˿����ô���",mtError,TMsgDlgButtons()<<mbOK,0);
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

                  // MessageDlg("\n�򿪶˿ڳɹ�",mtWarning ,TMsgDlgButtons()<<mbOK,0);
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
             MessageDlg("\n����δ�򿪣�",mtInformation,TMsgDlgButtons()<<mbOK,0);
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

        /*this->OpenDialog1->Filter="�ı��ļ�(*.txt*)|*.txt" ;
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
                      // this->StatusBar1->Panels->Items[0]->Text="�����ϴ�USB����    ������ "+String(i+1);
                       plist->Text="";
                       Form1->CrnListSplitString(DataList->Strings[i]+"|",plist,'|');
                       qlist->Text="";
                       Form1->CrnListSplitString(plist->Strings[0]+"-",qlist,'-');
                       mlist->Text="";
                       Form1->CrnListSplitString(plist->Strings[1]+",",mlist,',');

                       Form1->Search_ADOQuery->Close();
                       Form1->Search_ADOQuery->SQL->Clear();
                       Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where ���� like \""+mlist->Strings[0].Trim()+"\"");
                       Form1->Search_ADOQuery->Active= true;
                       float Sprace=Form1->Search_ADOQuery->FieldByName("�ۼ�")->AsFloat;
                       float Jprace=Form1->Search_ADOQuery->FieldByName("����")->AsFloat;


                       RKnum=0;
                       CKnum=0;
                       KCnum=0;

                       index0=1;

                       String str="";
                       if(qlist->Strings[0]=="CK"||qlist->Strings[0]=="RK"||qlist->Strings[0]=="PD"||qlist->Strings[0]=="YK")
                       {
                       Form1->Search_ADOQuery->Close();
                       Form1->Search_ADOQuery->SQL->Clear();
                       if(qlist->Strings[0]=="CK"||qlist->Strings[0]=="RK")str=String().sprintf("SELECT * FROM ��� WHERE ���� like \"%s\" AND �ֿ� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[2].Trim());
                       else if(qlist->Strings[0]=="PD")  str=String().sprintf("SELECT * FROM ��� WHERE ���� like \"%s\" AND �ֿ� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim());
                       else if(qlist->Strings[0]=="YK")  str=String().sprintf("SELECT * FROM ��� WHERE ���� like \"%s\" AND �ֿ� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[2].Trim());
                       Form1->Search_ADOQuery->SQL->Add(str);
                       Form1->Search_ADOQuery->Active= true;

                       if(Form1->Search_ADOQuery->RecordCount==0)index0=0;
                       else index0=1;

                       RKnum=Form1->Search_ADOQuery->FieldByName("�������")->AsFloat;
                       CKnum=Form1->Search_ADOQuery->FieldByName("��������")->AsFloat;
                       KCnum=Form1->Search_ADOQuery->FieldByName("���")->AsFloat;
                       }


                      if(qlist->Strings[0]=="UD")
                      {
                           Form1->Search_ADOQuery->Close();
                           Form1->Search_ADOQuery->SQL->Clear();
                           Form1->Search_ADOQuery->SQL->Add("SELECT * FROM JBZL where ���� like \""+mlist->Strings[0].Trim()+"\"");
                           Form1->Search_ADOQuery->Active= true;

                           if(Form1->Search_ADOQuery->RecordCount==0)
                           {
                                 Form1->ADOTable1->Insert();
                                 Form1->ADOTable1->FieldByName("����")->AsString = mlist->Strings[0].Trim();
                                 if(mlist->Strings[1].Trim().Length()!=0)Form1->ADOTable1->FieldByName("����")->AsString = mlist->Strings[1].Trim();
                                 else  Form1->ADOTable1->FieldByName("����")->AsString ="   ";
                                 if(mlist->Strings[2].Trim().Length()!=0)Form1->ADOTable1->FieldByName("����")->AsString = mlist->Strings[2].Trim();
                                 else  Form1->ADOTable1->FieldByName("����")->AsString ="   ";
                                 if(mlist->Strings[3].Trim().Length()!=0)Form1->ADOTable1->FieldByName("���")->AsString = mlist->Strings[3].Trim();
                                 else  Form1->ADOTable1->FieldByName("���")->AsString ="   ";
                                 if(mlist->Strings[4].Trim()!=0)Form1->ADOTable1->FieldByName("�ͺ�")->AsString = mlist->Strings[4].Trim();
                                 else  Form1->ADOTable1->FieldByName("�ͺ�")->AsString ="   ";
                                 if(Form1->Pshow=="show")
                                 {
                                     if(mlist->Strings[5].Trim().Length()!=0)Form1->ADOTable1->FieldByName("����")->AsFloat = mlist->Strings[5].Trim().ToDouble();
                                     else  Form1->ADOTable1->FieldByName("����")->AsFloat =0;
                                 }
                                 if(mlist->Strings[6].Trim().Length()!=0)Form1->ADOTable1->FieldByName("�ۼ�")->AsFloat = mlist->Strings[6].Trim().ToDouble();
                                 else  Form1->ADOTable1->FieldByName("�ۼ�")->AsFloat =0;
                                 if(mlist->Strings[7].Trim().Length()!=0)Form1->ADOTable1->FieldByName("��λ")->AsString = mlist->Strings[7].Trim();
                                 else  Form1->ADOTable1->FieldByName("��λ")->AsString ="   ";
                                 if(mlist->Strings[8].Trim().Length()!=0)Form1->ADOTable1->FieldByName("��עһ")->AsString = mlist->Strings[8].Trim();
                                 else  Form1->ADOTable1->FieldByName("��עһ")->AsString ="   ";
                                 if(mlist->Strings[9].Trim().Length()!=0)Form1->ADOTable1->FieldByName("��ע��")->AsString = mlist->Strings[9].Trim();
                                 else  Form1->ADOTable1->FieldByName("��ע��")->AsString ="   ";
                                 if(mlist->Strings[10].Trim().Length()!=0)Form1->ADOTable1->FieldByName("��ע��")->AsString = mlist->Strings[10].Trim();
                                 else  Form1->ADOTable1->FieldByName("��ע��")->AsString ="   ";
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
                                     str=str+" ���� = \""+mlist->Strings[1].Trim()+" \"";
                                     index=0;
                                 }
                                 if(mlist->Strings[2].Trim().Length()!=0)
                                 {
                                     if(index==0)str=str+" ,";
                                     str=str+" ���� = \""+mlist->Strings[2].Trim()+" \"";
                                     index=0;
                                 }
                                 if(mlist->Strings[3].Trim().Length()!=0)
                                 {
                                     if(index==0)str=str+" ,";
                                     str=str+" ��� = \""+mlist->Strings[3].Trim()+" \"";
                                     index=0;
                                 }
                                 if(mlist->Strings[4].Trim().Length()!=0)
                                 {
                                     if(index==0)str=str+" ,";
                                     str=str+" �ͺ� = \""+mlist->Strings[4].Trim()+" \"";
                                     index=0;
                                 }
                                 if(Form1->Pshow=="show")
                                 {
                                     if(mlist->Strings[5].Trim().Length()!=0)
                                     {
                                        if(index==0)str=str+" ,";
                                        str=str+" ���� = "+mlist->Strings[5].Trim().ToDouble();
                                        index=0;
                                     }
                                 }
                                 if(mlist->Strings[6].Trim().Length()!=0)
                                 {
                                    if(index==0)str=str+" ,";
                                    str=str+" �ۼ� = "+mlist->Strings[6].Trim().ToDouble();
                                    index=0;
                                 }
                                 if(mlist->Strings[7].Trim().Length()!=0)
                                 {
                                    if(index==0)str=str+" ,";
                                    str=str+" ��λ = \""+mlist->Strings[7].Trim()+" \"";
                                    index=0;
                                 }
                                 if(mlist->Strings[8].Trim().Length()!=0)
                                 {
                                    if(index==0)str=str+" ,";
                                    str=str+" ��עһ = \""+mlist->Strings[8].Trim()+" \"";
                                    index=0;
                                 }
                                 if(mlist->Strings[9].Trim().Length()!=0)
                                 {
                                    if(index==0)str=str+" ,";
                                    str=str+" ��ע�� = \""+mlist->Strings[9].Trim()+" \"";
                                    index=0;
                                 }
                                 if(mlist->Strings[10].Trim().Length()!=0)
                                 {
                                    if(index==0)str=str+" ,";
                                    str=str+" ��ע�� = \""+mlist->Strings[10].Trim()+" \"";
                                    index=0;
                                 }
                                 if(mlist->Strings[1].Trim().Length()==0&&mlist->Strings[2].Trim().Length()==0&&mlist->Strings[3].Trim().Length()==0&&
                                    mlist->Strings[4].Trim().Length()==0&&mlist->Strings[5].Trim().Length()==0&&mlist->Strings[6].Trim().Length()==0&&
                                    mlist->Strings[7].Trim().Length()==0&&mlist->Strings[8].Trim().Length()==0&&mlist->Strings[9].Trim().Length()==0&&
                                    mlist->Strings[10].Trim().Length()==0)continue;
                                 str=str+" WHERE ���� like \""+mlist->Strings[0].Trim()+"\"";

                                 Form1->ADOCommand1->CommandText = str;
                                 Form1->ADOCommand1->Execute();

                           }

                      }
                      else if(qlist->Strings[0]=="RK")
                      {
                         str="";
                         Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         str=String().sprintf("SELECT * FROM ��� WHERE ���� like \"%s\" AND ��ⵥ�� like \"%s\" AND ���ֿ� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim(),qlist->Strings[2].Trim());
                         Form1->Search_ADOQuery->SQL->Add(str);
                         Form1->Search_ADOQuery->Active= true;

                         if(Form1->Search_ADOQuery->RecordCount==0)
                         {
                             Form1->RK_ADOTable->Insert();
                             Form1->RK_ADOTable->FieldByName("���ֿ�")->AsString = qlist->Strings[2].Trim();
                             Form1->RK_ADOTable->FieldByName("��ⵥ��")->AsString = qlist->Strings[1].Trim();
                             Form1->RK_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
                             Form1->RK_ADOTable->FieldByName("�������")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                             Form1->RK_ADOTable->FieldByName("���ʱ��")->AsString=StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
                             Form1->RK_ADOTable->FieldByName("Ա�����")->AsString = mlist->Strings[3].Trim();
                             Form1->RK_ADOTable->Post();
                         }
                         else
                         {
                             str="";
                             str=String().sprintf("UPDATE RK SET  ������� = %f , ���ʱ�� =  \"%s\" , Ա����� =  \"%s\"  WHERE ���� like \"%s\" AND ���ֿ� like \"%s\" AND ��ⵥ�� like \"%s\""
                                 ,mlist->Strings[1].Trim().ToDouble()+Form1->Search_ADOQuery->FieldByName("�������")->AsFloat
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
                            Form1->KC_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
                            Form1->KC_ADOTable->FieldByName("�������")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                            Form1->KC_ADOTable->FieldByName("�ֿ�")->AsString = qlist->Strings[2].Trim();
                            Form1->KC_ADOTable->FieldByName("���")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                            Form1->KC_ADOTable->Post();

                        }
                        else
                        {
                            str="";
                            str=String().sprintf("UPDATE KC SET  ������� = %f, ��� =%f  WHERE ���� like \"%s\" AND �ֿ� like \"%s\""
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
                         Double cost=0;//�ܳɱ�
                         Double sales=0;//�����۶�
                         Double profits=0;//������

                         if(KCnum<mlist->Strings[1].Trim().ToDouble())
                         {
                               REVLIST->Items->Add("��ʾ|�ڲֿ�"+ qlist->Strings[2].Trim()+"��ߣ�����"+mlist->Strings[0].Trim()+"��治��");
                               SendMessage(REVLIST-> Handle,   WM_VSCROLL,   SB_BOTTOM,   NULL);
                         }

                         if(mlist->Strings[4].Trim().Length()!=0||mlist->Strings[5].Trim()=="0")//0�����޸���
                         Sprace= mlist->Strings[4].Trim().ToDouble();

                         str="";
                         Form1->Search_ADOQuery->Close();
                         Form1->Search_ADOQuery->SQL->Clear();
                         str=String().sprintf("SELECT * FROM ���� WHERE ���� like \"%s\" AND ���ⵥ�� like \"%s\" AND ����ֿ� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim(),qlist->Strings[2].Trim());
                         Form1->Search_ADOQuery->SQL->Add(str);
                         Form1->Search_ADOQuery->Active= true;

                         if(Form1->Search_ADOQuery->RecordCount==0)
                         {
                             sales=Sprace*mlist->Strings[1].Trim().ToDouble();
                             cost=Jprace*mlist->Strings[1].Trim().ToDouble();
                             profits=sales-cost;
                             
                             Form1->CK_ADOTable->Insert();
                             Form1->CK_ADOTable->FieldByName("����ֿ�")->AsString = qlist->Strings[2].Trim();
                             Form1->CK_ADOTable->FieldByName("���ⵥ��")->AsString = qlist->Strings[1].Trim();
                             Form1->CK_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
                             Form1->CK_ADOTable->FieldByName("��������")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                             Form1->CK_ADOTable->FieldByName("����ʱ��")->AsString=StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
                             Form1->CK_ADOTable->FieldByName("Ա�����")->AsString = mlist->Strings[3].Trim();
                             Form1->CK_ADOTable->FieldByName("�ۼ�")->AsFloat = Sprace;
                             Form1->CK_ADOTable->Post();
                         }
                         else
                         {
                             if(Sprace==Form1->Search_ADOQuery->FieldByName("�ۼ�")->AsFloat)
                             {
                                  sales=Sprace*mlist->Strings[1].Trim().ToDouble();
                                  cost=Jprace*mlist->Strings[1].Trim().ToDouble();
                                  profits=sales-cost;

                             }
                             else
                             {
                                  sales=Sprace*mlist->Strings[1].Trim().ToDouble()+(Sprace-Form1->Search_ADOQuery->FieldByName("�ۼ�")->AsFloat)*Form1->Search_ADOQuery->FieldByName("��������")->AsFloat;
                                  cost=Jprace*mlist->Strings[1].Trim().ToDouble();
                                  profits=sales-cost;
                             }
                             str="";
                             str=String().sprintf("UPDATE CK SET  �������� = %f , �ۼ� = %f , ����ʱ�� =  \"%s\" , Ա����� =  \"%s\"  WHERE ���� like \"%s\" AND ����ֿ� like \"%s\" AND ���ⵥ�� like \"%s\""
                                 ,mlist->Strings[1].Trim().ToDouble()+Form1->Search_ADOQuery->FieldByName("��������")->AsFloat
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
                              Form1->KC_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
                              Form1->KC_ADOTable->FieldByName("��������")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                              Form1->KC_ADOTable->FieldByName("�ֿ�")->AsString = qlist->Strings[2].Trim();
                              Form1->KC_ADOTable->FieldByName("���")->AsFloat = 0-mlist->Strings[1].Trim().ToDouble();
                              Form1->KC_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE KC SET  �������� = %f, ��� =%f  WHERE ���� like \"%s\" AND �ֿ� like \"%s\""
                                   ,mlist->Strings[1].Trim().ToDouble()+CKnum
                                   ,KCnum-mlist->Strings[1].Trim().ToDouble()
                                   ,mlist->Strings[0].Trim()
                                   ,qlist->Strings[2].Trim());
                              Form1->ADOCommand1->CommandText = str;
                              Form1->ADOCommand1->Execute();
                       }

                       //������������
                       str="";
                       Form1->XSTJ_ADOQuery->Close();
                       Form1->XSTJ_ADOQuery->SQL->Clear();
                       str=String().sprintf("SELECT * FROM ����ͳ�� WHERE ���ⵥ�� like \"%s\"",qlist->Strings[1].Trim());
                       Form1->XSTJ_ADOQuery->SQL->Add(str);
                       Form1->XSTJ_ADOQuery->Active= true;

                       if(Form1->XSTJ_ADOQuery->RecordCount==0)
                       {
                           Form1->XSTJ_ADOTable->Insert();
                           Form1->XSTJ_ADOTable->FieldByName("���ⵥ��")->AsString = qlist->Strings[1].Trim();
                           Form1->XSTJ_ADOTable->FieldByName("�ɱ�")->AsFloat = Jprace*mlist->Strings[1].Trim().ToDouble();
                           Form1->XSTJ_ADOTable->FieldByName("���۶�")->AsFloat = Sprace*mlist->Strings[1].Trim().ToDouble();
                           Form1->XSTJ_ADOTable->FieldByName("����")->AsFloat = (Sprace-Jprace)*mlist->Strings[1].Trim().ToDouble();
                           Form1->XSTJ_ADOTable->FieldByName("Ա�����")->AsString = mlist->Strings[3].Trim();
                           Form1->XSTJ_ADOTable->FieldByName("ʱ��")->AsString = StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);

                           Form1->XSTJ_ADOTable->Post();
                       }
                       else
                       {
                           str="";
                           str=String().sprintf("UPDATE XSTJ SET  �ɱ� = %f, ���۶� =%f , ���� =%f , ʱ�� =  \"%s\" WHERE ���ⵥ�� like \"%s\""
                                 ,cost+Form1->XSTJ_ADOQuery->FieldByName("�ɱ�")->AsFloat
                                 ,sales+Form1->XSTJ_ADOQuery->FieldByName("���۶�")->AsFloat
                                 ,profits+Form1->XSTJ_ADOQuery->FieldByName("����")->AsFloat
                                 ,StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase)
                                 ,qlist->Strings[1].Trim());
                           Form1->ADOCommand1->CommandText = str;
                           Form1->ADOCommand1->Execute();
                       }
                       



                 }
                 else if(qlist->Strings[0]=="PD")
                 {
                        //�޸��̵�ͳ�Ʊ�================================================================================================
                        float pdkc=0;
		        String str="";
		        Form1->Search_ADOQuery->Close();
		        Form1->Search_ADOQuery->SQL->Clear();
		        str=String().sprintf("SELECT * FROM �̵�ͳ�� WHERE ���� like \"%s\" AND �ֿ� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[2].Trim());
		        Form1->Search_ADOQuery->SQL->Add(str);
		        Form1->Search_ADOQuery->Active= true;
                        pdkc=Form1->Search_ADOQuery->FieldByName("�̵���")->AsFloat;
		
		        if(Form1->Search_ADOQuery->RecordCount==0)
		        {
		            Form1->PDTJ_ADOTable->Insert();
		            Form1->PDTJ_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
		            Form1->PDTJ_ADOTable->FieldByName("�̵���")->AsFloat = mlist->Strings[1].Trim().ToDouble();
		            Form1->PDTJ_ADOTable->FieldByName("�ֿ�")->AsString = qlist->Strings[2].Trim();  //����1  �ֿ�2
		            Form1->PDTJ_ADOTable->Post();
		        }
		        else
		        {
		            str="";
		            str=String().sprintf("UPDATE PDTJ SET  �̵��� = %f WHERE ���� like \"%s\" AND �ֿ� like \"%s\""
		                                   ,pdkc+mlist->Strings[1].Trim().ToDouble()
		                                   ,mlist->Strings[0].Trim()
		                                   ,qlist->Strings[2].Trim());
		            Form1->ADOCommand1->CommandText = str;
		            Form1->ADOCommand1->Execute();
		        }

		        //�޸��̵���ϸ��==================================================================================================
		        Form1->Search_ADOQuery->Close();
		        Form1->Search_ADOQuery->SQL->Clear();
		        str=String().sprintf("SELECT * FROM �̵� WHERE ���� like \"%s\" AND �ֿ� like \"%s\" AND ���� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[2].Trim(),qlist->Strings[1].Trim());
		        Form1->Search_ADOQuery->SQL->Add(str);
		        Form1->Search_ADOQuery->Active= true;
		        pdkc=Form1->Search_ADOQuery->FieldByName("�̵���")->AsFloat;

		        if(Form1->Search_ADOQuery->RecordCount==0)
		        {
		            Form1->PD_ADOTable->Insert();
		            Form1->PD_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
		            Form1->PD_ADOTable->FieldByName("�̵���")->AsFloat = mlist->Strings[1].Trim().ToDouble();
		            Form1->PD_ADOTable->FieldByName("�ֿ�")->AsString = qlist->Strings[2].Trim();
		            Form1->PD_ADOTable->FieldByName("����")->AsString = qlist->Strings[1].Trim();
		            Form1->PD_ADOTable->FieldByName("�̵�ʱ��")->AsString = StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
		            Form1->PD_ADOTable->FieldByName("Ա�����")->AsString = mlist->Strings[3].Trim();
		            Form1->PD_ADOTable->Post();
		        }
		        else
		        {
		            str="";
		            str=String().sprintf("UPDATE PD SET  �̵��� = %f , �̵�ʱ�� =\"%s\" , Ա����� = \"%s\" WHERE ���� like \"%s\" AND �ֿ� like \"%s\" AND ���� like \"%s\""
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
                        str=String().sprintf("SELECT * FROM �̵� WHERE ���� like \"%s\" AND �ֿ� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim());
                        Form1->Search_ADOQuery->SQL->Add(str);
                        Form1->Search_ADOQuery->Active= true;

                        pdkc=Form1->Search_ADOQuery->FieldByName("�̵���")->AsFloat;

                        if(Form1->Search_ADOQuery->RecordCount==0)
                        {
                              Form1->PD_ADOTable->Insert();
                              Form1->PD_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
                              Form1->PD_ADOTable->FieldByName("�̵���")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                              Form1->PD_ADOTable->FieldByName("�ֿ�")->AsString = qlist->Strings[1].Trim();
                              Form1->PD_ADOTable->FieldByName("�̵�ʱ��")->AsString = StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
                              Form1->PD_ADOTable->FieldByName("Ա�����")->AsString = mlist->Strings[3].Trim();
                              Form1->PD_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE PD SET  �̵��� = %f ,�̵�ʱ�� = \"%s\" ,Ա����� = \"%s\"  WHERE ���� like \"%s\" AND �ֿ� like \"%s\""
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
                        str=String().sprintf("SELECT * FROM �鵥 WHERE ���� like \"%s\" AND ���� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim());
                        Form1->Search_ADOQuery->SQL->Add(str);
                        Form1->Search_ADOQuery->Active= true;

                        pdkc=Form1->Search_ADOQuery->FieldByName("��ɨ����")->AsFloat;

                        if(Form1->Search_ADOQuery->RecordCount==0)
                        {
                              Form1->YD_ADOTable->Insert();
                              Form1->YD_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
                              Form1->YD_ADOTable->FieldByName("Ӧɨ����")->AsFloat = 0;
                              Form1->YD_ADOTable->FieldByName("��ɨ����")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                              Form1->YD_ADOTable->FieldByName("ʱ��")->AsString=StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
                              Form1->YD_ADOTable->FieldByName("����")->AsString = qlist->Strings[1].Trim();
                              Form1->YD_ADOTable->FieldByName("Ա�����")->AsString = mlist->Strings[3].Trim();
                              Form1->YD_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE YD SET  ��ɨ���� = %f ,ʱ�� = \"%s\" ,Ա����� = \"%s\"  WHERE ���� like \"%s\" AND ���� like \"%s\""
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
                        str=String().sprintf("SELECT * FROM �ƿ� WHERE ���� like \"%s\" AND �ƿⵥ�� like \"%s\" AND ԭ�ֿ� like \"%s\" AND Ŀ�Ĳֿ� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[1].Trim(),qlist->Strings[2].Trim(),qlist->Strings[3].Trim());
                        Form1->Search_ADOQuery->SQL->Add(str);
                        Form1->Search_ADOQuery->Active= true;

                        pdkc=Form1->Search_ADOQuery->FieldByName("����")->AsFloat;

                        if(Form1->Search_ADOQuery->RecordCount==0)
                        { */
                              Form1->YK_ADOTable->Insert();
                              Form1->YK_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
                              Form1->YK_ADOTable->FieldByName("����")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                              Form1->YK_ADOTable->FieldByName("�ƿ�ʱ��")->AsString = StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase);
                              Form1->YK_ADOTable->FieldByName("�ƿⵥ��")->AsString = qlist->Strings[1].Trim();
                              Form1->YK_ADOTable->FieldByName("ԭ�ֿ�")->AsString = qlist->Strings[2].Trim();
                              Form1->YK_ADOTable->FieldByName("Ŀ�Ĳֿ�")->AsString = qlist->Strings[3].Trim();
                              Form1->YK_ADOTable->FieldByName("Ա�����")->AsString = mlist->Strings[3].Trim();
                              Form1->YK_ADOTable->Post();

                        /*}
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE YK SET  ���� = %f , �ƿ�ʱ�� =  \"%s\" , Ա����� =  \"%s\"  WHERE ���� like \"%s\" AND ԭ�ֿ� like \"%s\" AND Ŀ�Ĳֿ� like \"%s\""
                                 ,mlist->Strings[1].Trim().ToDouble()+pdkc
                                 ,StringReplace(mlist->Strings[2].Trim(),(char)'/',"-",TReplaceFlags()<<rfReplaceAll<<rfIgnoreCase)
                                 ,mlist->Strings[3].Trim()
                                 ,mlist->Strings[0].Trim()
                                 ,qlist->Strings[1].Trim()
                                 ,qlist->Strings[2].Trim());
                            Form1->ADOCommand1->CommandText = str;
                            Form1->ADOCommand1->Execute();
                       } */

                       //�޸�ԭ�ֿ���
                    if(index0==0)
                        {
                              Form1->KC_ADOTable->Insert();
                              Form1->KC_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
                              Form1->KC_ADOTable->FieldByName("��������")->AsFloat = 0;
                              Form1->KC_ADOTable->FieldByName("�������")->AsFloat = 0;
                              Form1->KC_ADOTable->FieldByName("�ֿ�")->AsString = qlist->Strings[2].Trim();
                              Form1->KC_ADOTable->FieldByName("���")->AsFloat = 0-mlist->Strings[1].Trim().ToDouble();
                              Form1->KC_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE KC SET  ��� =%f  WHERE ���� like \"%s\" AND �ֿ� like \"%s\""
                                   ,KCnum-mlist->Strings[1].Trim().ToDouble()
                                   ,mlist->Strings[0].Trim()
                                   ,qlist->Strings[2].Trim());
                              Form1->ADOCommand1->CommandText = str;
                              Form1->ADOCommand1->Execute();
                       }

                       //�޸�Ŀ�Ĳֿ���
                       Form1->Search_ADOQuery->Close();
                       Form1->Search_ADOQuery->SQL->Clear();
                       str=String().sprintf("SELECT * FROM ��� WHERE ���� like \"%s\" AND �ֿ� like \"%s\"",mlist->Strings[0].Trim(),qlist->Strings[3].Trim());
                       Form1->Search_ADOQuery->SQL->Add(str);
                       Form1->Search_ADOQuery->Active= true;
                       KCnum=Form1->Search_ADOQuery->FieldByName("���")->AsFloat;


                       if(Form1->Search_ADOQuery->RecordCount==0)
                        {
                              Form1->KC_ADOTable->Insert();
                              Form1->KC_ADOTable->FieldByName("����")->AsString = mlist->Strings[0].Trim();
                              Form1->KC_ADOTable->FieldByName("��������")->AsFloat = 0;
                              Form1->KC_ADOTable->FieldByName("�������")->AsFloat = 0;
                              Form1->KC_ADOTable->FieldByName("�ֿ�")->AsString = qlist->Strings[3].Trim();
                              Form1->KC_ADOTable->FieldByName("���")->AsFloat = mlist->Strings[1].Trim().ToDouble();
                              Form1->KC_ADOTable->Post();

                        }
                        else
                        {
                              str="";
                              str=String().sprintf("UPDATE KC SET  ��� =%f  WHERE ���� like \"%s\" AND �ֿ� like \"%s\""
                                   ,KCnum+mlist->Strings[1].Trim().ToDouble()
                                   ,mlist->Strings[0].Trim()
                                   ,qlist->Strings[3].Trim());
                              Form1->ADOCommand1->CommandText = str;
                              Form1->ADOCommand1->Execute();
                       }
                    }
                 Application->ProcessMessages();


               }

               MessageDlg("�ϴ����",mtInformation,TMsgDlgButtons()<<mbOK,0);
             //  this->StatusBar1->Panels->Items[0]->Text="�������Ѿ����������ڼ���...";
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

              //���������ϴ�������======================================================================
              SaveList->Text="";
              wList->Text="";
              for(int i=0;i<wifelessDataPL->Count;i++)
              {
                 wList->Add("��ͨ�̵�-"+wifelessDataPL->Strings[i]);
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


              MessageDlg("����ɹ�",mtInformation,TMsgDlgButtons()<<mbOK,0);

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
//��ʾ������
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
              MessageDlg("ͬ��ʧ�ܣ�������û�п���",mtInformation,TMsgDlgButtons()<<mbOK,0);
              return;
        }
     }

     String name="";
     String password="";
NM:
     name="";
     if(InputQuery("IP����ͬ��","������ͬ���˺�:           ",name))
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
     if(InputQuery("IP����ͬ��","����������:           ",password))
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

     this->StatusBar1->Panels->Items[0]->Text="���ڽ���IPͬ�������Ե�";

     char splitcom1[3];
     memset(splitcom1,0,3);
     splitcom1[0]=0xA1;splitcom1[1]=0xF5;

     char splitcom2[3];
     memset(splitcom2,0,3);
     splitcom2[0]=0xA1;splitcom2[1]=0xF6;

     String sendstr = "";
     sendstr = String().sprintf("talk%s%s%s%s%s%s",String(splitcom1),"update",String(splitcom1),name.Trim(),String(splitcom1),password.Trim());
     //talk  ע�� �û���  У��
     //talk OK
     ClientSocket1->Socket->SendText(Send(sendstr,0));

    /* sendstr = "";
     sendstr = String().sprintf("talk%s%s%s%s",String(splitcom1),"update",String(splitcom1),"OK");
     //talk  ע�� �û���  У��
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
//У��
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
        MessageDlg("ע��ɹ�",mtInformation,TMsgDlgButtons()<<mbOK,0);
   }
   else if(splitString->Strings[1].Trim()=="registerexist")
   {
        MessageDlg("ע��ʧ�ܣ����û����Ѿ�����",mtInformation,TMsgDlgButtons()<<mbOK,0);
   }
   else if(splitString->Strings[1].Trim()=="updatefail")
   {
        MessageDlg("IPͬ��ʧ�ܣ�����ע����û���",mtInformation,TMsgDlgButtons()<<mbOK,0);
   }
   else if(splitString->Strings[1].Trim()=="updateok")
   {
        MessageDlg("IPͬ���ɹ�",mtInformation,TMsgDlgButtons()<<mbOK,0);
   }
   else if(splitString->Strings[1].Trim()=="updatepasswordok")
   {
        MessageDlg("�����޸ĳɹ�",mtInformation,TMsgDlgButtons()<<mbOK,0);
   }
   else if(splitString->Strings[1].Trim()=="updatepasswordfail")
   {
        MessageDlg("�����޸�ʧ�ܣ����ȸ�ע���û���",mtInformation,TMsgDlgButtons()<<mbOK,0);
   }
   else if(splitString->Strings[1].Trim()=="passworderror")
   {
        MessageDlg("���������������������",mtInformation,TMsgDlgButtons()<<mbOK,0);
   }
   else if(splitString->Strings[1].Trim()=="unknow")
   {
        MessageDlg("δ֪����",mtInformation,TMsgDlgButtons()<<mbOK,0);
   }

   Form2->ClientSocket1->Active=false;

   this->StatusBar1->Panels->Items[0]->Text="�������Ѿ����������ڼ���...";


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
              String FileName="���ݱ���";
              REVLIST->Items->SaveToFile(Dir+FileName+"-"+datetime+".txt") ;

              MessageDlg("����ɹ�",mtInformation,TMsgDlgButtons()<<mbOK,0);
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
       IMPORTDATA="δ��.TXT";
       BitBtn3Click(Sender); 
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn7Click(TObject *Sender)
{
     IMPORTDATA="������.TXT";
     BitBtn3Click(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::BitBtn8Click(TObject *Sender)
{
     IMPORTDATA="��������.TXT";
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

