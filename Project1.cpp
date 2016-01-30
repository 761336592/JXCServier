//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Form1);
USEFORM("Unit2.cpp", Form2);
USEFORM("Unit3.cpp", Form3);
USEFORM("Unit4.cpp", Form4);
USEFORM("Unit5.cpp", Form5);
USEFORM("Unit6.cpp", Form6);
USEFORM("Unit7.cpp", Form7);
USEFORM("Unit8.cpp", Form8);
USEFORM("Unit9.cpp", Form9);
USEFORM("Unit10.cpp", Form10);
USEFORM("Unit11.cpp", Form11);
USEFORM("Unit12.cpp", Form12);
USEFORM("Unit13.cpp", Form13);
USEFORM("Unit14.cpp", Form14);
USEFORM("Unit15.cpp", Form15);
USEFORM("Unit16.cpp", Form16);
USEFORM("Unit17.cpp", Form17);
USEFORM("Unit18.cpp", Form18);
USEFORM("Unit19.cpp", RKprint);
USEFORM("Unit20.cpp", CKprint);
USEFORM("Unit21.cpp", Form21);
USEFORM("Unit22.cpp", Form22);
USEFORM("Unit23.cpp", Form23);
USEFORM("Unit24.cpp", Form24);
USEFORM("Unit25.cpp", Form25);
USEFORM("Unit26.cpp", Form26);
USEFORM("Unit27.cpp", Form27);
USEFORM("Unit28.cpp", YKprint);
USEFORM("Unit29.cpp", Form29);
USEFORM("Unit30.cpp", YDprint);
USEFORM("Unit31.cpp", Form31);
USEFORM("Unit32.cpp", Form32);
USEFORM("Unit33.cpp", Form33);
USEFORM("Unit34.cpp", Form34);
USEFORM("Unit35.cpp", PDprint);
USEFORM("Unit36.cpp", Form36);
USEFORM("Unit37.cpp", Form37);
USEFORM("Unit38.cpp", Form38);
USEFORM("Unit39.cpp", Form39);
USEFORM("Unit40.cpp", Form40);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "½øÏú´æ(²Ö¿â°æ)";
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->CreateForm(__classid(TForm2), &Form2);
                 Application->CreateForm(__classid(TForm3), &Form3);
                 Application->CreateForm(__classid(TForm4), &Form4);
                 Application->CreateForm(__classid(TForm5), &Form5);
                 Application->CreateForm(__classid(TForm6), &Form6);
                 Application->CreateForm(__classid(TForm7), &Form7);
                 Application->CreateForm(__classid(TForm8), &Form8);
                 Application->CreateForm(__classid(TForm9), &Form9);
                 Application->CreateForm(__classid(TForm10), &Form10);
                 Application->CreateForm(__classid(TForm11), &Form11);
                 Application->CreateForm(__classid(TForm12), &Form12);
                 Application->CreateForm(__classid(TForm13), &Form13);
                 Application->CreateForm(__classid(TForm14), &Form14);
                 Application->CreateForm(__classid(TForm15), &Form15);
                 Application->CreateForm(__classid(TForm16), &Form16);
                 Application->CreateForm(__classid(TForm17), &Form17);
                 Application->CreateForm(__classid(TForm18), &Form18);
                 Application->CreateForm(__classid(TRKprint), &RKprint);
                 Application->CreateForm(__classid(TCKprint), &CKprint);
                 Application->CreateForm(__classid(TForm21), &Form21);
                 Application->CreateForm(__classid(TForm22), &Form22);
                 Application->CreateForm(__classid(TForm23), &Form23);
                 Application->CreateForm(__classid(TForm24), &Form24);
                 Application->CreateForm(__classid(TForm25), &Form25);
                 Application->CreateForm(__classid(TForm26), &Form26);
                 Application->CreateForm(__classid(TForm27), &Form27);
                 Application->CreateForm(__classid(TYKprint), &YKprint);
                 Application->CreateForm(__classid(TForm29), &Form29);
                 Application->CreateForm(__classid(TYDprint), &YDprint);
                 Application->CreateForm(__classid(TForm31), &Form31);
                 Application->CreateForm(__classid(TForm32), &Form32);
                 Application->CreateForm(__classid(TForm33), &Form33);
                 Application->CreateForm(__classid(TForm34), &Form34);
                 Application->CreateForm(__classid(TPDprint), &PDprint);
                 Application->CreateForm(__classid(TForm36), &Form36);
                 Application->CreateForm(__classid(TForm37), &Form37);
                 Application->CreateForm(__classid(TForm38), &Form38);
                 Application->CreateForm(__classid(TForm39), &Form39);
                 Application->CreateForm(__classid(TForm40), &Form40);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
