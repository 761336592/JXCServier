object Form6: TForm6
  Left = 128
  Top = 193
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #20986#24211#26126#32454#26597#35810
  ClientHeight = 746
  ClientWidth = 1366
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 408
    Top = 48
    Width = 24
    Height = 13
    Caption = '--------'
  end
  object CheckCKbar: TCheckBox
    Left = 24
    Top = 16
    Width = 97
    Height = 17
    Caption = #26465#30721
    TabOrder = 0
  end
  object Check_CK_bar: TEdit
    Left = 136
    Top = 16
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 1
  end
  object CheckCKck: TCheckBox
    Left = 264
    Top = 16
    Width = 97
    Height = 17
    Caption = #20179#24211
    TabOrder = 2
  end
  object Check_CK_ck: TEdit
    Left = 320
    Top = 16
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 3
  end
  object CheckCKdj: TCheckBox
    Left = 456
    Top = 16
    Width = 97
    Height = 17
    Caption = #21333#25454
    TabOrder = 4
  end
  object Check_CK_dj: TEdit
    Left = 512
    Top = 16
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 5
  end
  object CheckCKbh: TCheckBox
    Left = 648
    Top = 16
    Width = 97
    Height = 17
    Caption = #32534#21495
    TabOrder = 6
  end
  object Check_CK_bh: TEdit
    Left = 704
    Top = 16
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 7
  end
  object Check_CK_date2: TDateTimePicker
    Left = 432
    Top = 48
    Width = 89
    Height = 21
    CalAlignment = dtaLeft
    Date = 41849.4886236574
    Time = 41849.4886236574
    DateFormat = dfShort
    DateMode = dmComboBox
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    Kind = dtkDate
    ParseInput = False
    TabOrder = 8
  end
  object Check_CK_date1: TDateTimePicker
    Left = 320
    Top = 48
    Width = 89
    Height = 21
    CalAlignment = dtaLeft
    Date = 41849.4885031134
    Time = 41849.4885031134
    DateFormat = dfShort
    DateMode = dmComboBox
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    Kind = dtkDate
    ParseInput = False
    TabOrder = 9
  end
  object CheckCKdate: TCheckBox
    Left = 264
    Top = 48
    Width = 57
    Height = 17
    Caption = #26102#38388
    TabOrder = 10
  end
  object Check_CK_nm: TEdit
    Left = 136
    Top = 48
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 11
  end
  object CheckCKnm: TCheckBox
    Left = 24
    Top = 48
    Width = 105
    Height = 17
    Caption = #22995'        '#21517
    TabOrder = 12
  end
  object DBGrid1: TDBGrid
    Left = 24
    Top = 88
    Width = 1321
    Height = 649
    DataSource = DataSource1
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
    ReadOnly = True
    TabOrder = 13
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnCellClick = DBGrid1CellClick
    OnTitleClick = DBGrid1TitleClick
    Columns = <
      item
        Expanded = False
        FieldName = #26465#30721
        Visible = True
      end
      item
        Expanded = False
        FieldName = #21517#31216
        Visible = True
      end
      item
        Expanded = False
        FieldName = #36135#21495
        Visible = True
      end
      item
        Expanded = False
        FieldName = #35268#26684
        Visible = True
      end
      item
        Expanded = False
        FieldName = #22411#21495
        Visible = True
      end
      item
        Expanded = False
        FieldName = #36827#20215
        Visible = False
      end
      item
        Expanded = False
        FieldName = #21806#20215
        Visible = True
      end
      item
        Expanded = False
        FieldName = #21333#20301
        Visible = True
      end
      item
        Expanded = False
        FieldName = #22791#27880#19968
        Visible = True
      end
      item
        Expanded = False
        FieldName = #22791#27880#20108
        Visible = True
      end
      item
        Expanded = False
        FieldName = #22791#27880#19977
        Visible = True
      end
      item
        Expanded = False
        FieldName = #20986#24211#25968#37327
        Visible = True
      end
      item
        Expanded = False
        FieldName = #20986#24211#26102#38388
        Visible = True
      end
      item
        Expanded = False
        FieldName = #20986#24211#20179#24211
        Visible = True
      end
      item
        Expanded = False
        FieldName = #20986#24211#21333#25454
        Visible = True
      end
      item
        Expanded = False
        FieldName = #21592#24037#32534#21495
        Visible = True
      end
      item
        Expanded = False
        FieldName = #21592#24037#22995#21517
        Visible = True
      end>
  end
  object BitBtn1: TBitBtn
    Left = 856
    Top = 16
    Width = 75
    Height = 25
    Caption = #26597#35810
    TabOrder = 14
    OnClick = BitBtn1Click
  end
  object BitBtn2: TBitBtn
    Left = 776
    Top = 48
    Width = 75
    Height = 25
    Caption = #23548#20986
    TabOrder = 15
    OnClick = BitBtn2Click
  end
  object BitBtn3: TBitBtn
    Left = 856
    Top = 48
    Width = 75
    Height = 25
    Hint = #25353#29031#21333#25454#25171#21360#25253#34920#65292#38656#35201#36873#20013#26576#20010#21333#25454#20877#25171#21360
    Caption = #21333#25454#25171#21360
    ParentShowHint = False
    ShowHint = True
    TabOrder = 16
    OnClick = BitBtn3Click
  end
  object BitBtn4: TBitBtn
    Left = 936
    Top = 48
    Width = 75
    Height = 25
    Hint = #25353#29031#21333#25454#25171#21360#23567#31080#65292#38656#35201#36873#20013#26576#20010#21333#25454#20877#25171#21360
    Caption = #23567#31080#25171#21360
    ParentShowHint = False
    ShowHint = True
    TabOrder = 17
    OnClick = BitBtn4Click
  end
  object BitBtn5: TBitBtn
    Left = 936
    Top = 16
    Width = 75
    Height = 25
    Caption = #21024#38500
    TabOrder = 18
    OnClick = BitBtn5Click
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 727
    Width = 1366
    Height = 19
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object ComboBox1: TComboBox
    Left = 40
    Top = 16
    Width = 89
    Height = 21
    Style = csDropDownList
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    ItemHeight = 13
    TabOrder = 20
    OnChange = ComboBox1Change
  end
  object BitBtn6: TBitBtn
    Left = 640
    Top = 48
    Width = 129
    Height = 25
    Caption = #32593#32476#21516#27493#20986#24211#25968#25454
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 21
    Visible = False
    OnClick = BitBtn6Click
  end
  object Button1: TButton
    Left = 1024
    Top = 16
    Width = 75
    Height = 25
    Caption = #23548#20837'EXCEL'
    TabOrder = 22
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 1024
    Top = 48
    Width = 75
    Height = 25
    Caption = #23548#20837'TXT'
    TabOrder = 23
    OnClick = Button2Click
  end
  object DataSource1: TDataSource
    DataSet = Form1.CK_ADOQuery
    Left = 1120
    Top = 16
  end
end
