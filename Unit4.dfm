object Form4: TForm4
  Left = 178
  Top = 340
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #20837#24211#26126#32454#26597#35810
  ClientHeight = 746
  ClientWidth = 1268
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
    Left = 392
    Top = 48
    Width = 24
    Height = 13
    Caption = '--------'
  end
  object DBGrid1: TDBGrid
    Left = 16
    Top = 80
    Width = 1233
    Height = 665
    DataSource = DataSource1
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
    ReadOnly = True
    TabOrder = 0
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
        FieldName = #20837#24211#25968#37327
        Visible = True
      end
      item
        Expanded = False
        FieldName = #20837#24211#26102#38388
        Visible = True
      end
      item
        Expanded = False
        FieldName = #20837#24211#20179#24211
        Visible = True
      end
      item
        Expanded = False
        FieldName = #20837#24211#21333#25454
        Visible = True
      end
      item
        Expanded = False
        FieldName = #21592#24037#32534#21495
        Width = 57
        Visible = True
      end
      item
        Expanded = False
        FieldName = #21592#24037#22995#21517
        Visible = True
      end>
  end
  object CheckRKbar: TCheckBox
    Left = 24
    Top = 16
    Width = 97
    Height = 17
    Caption = #26465#30721
    TabOrder = 1
  end
  object Check_RK_bar: TEdit
    Left = 128
    Top = 16
    Width = 113
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 2
  end
  object CheckRKck: TCheckBox
    Left = 248
    Top = 16
    Width = 97
    Height = 17
    Caption = #20179#24211
    TabOrder = 3
  end
  object Check_RK_ck: TEdit
    Left = 304
    Top = 16
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 4
  end
  object CheckRKdj: TCheckBox
    Left = 440
    Top = 16
    Width = 97
    Height = 17
    Caption = #21333#25454
    TabOrder = 5
  end
  object Check_RK_dj: TEdit
    Left = 496
    Top = 16
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 6
  end
  object CheckRKbh: TCheckBox
    Left = 632
    Top = 16
    Width = 97
    Height = 17
    Caption = #32534#21495
    TabOrder = 7
  end
  object Check_RK_bh: TEdit
    Left = 688
    Top = 16
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 8
  end
  object CheckRKnm: TCheckBox
    Left = 24
    Top = 48
    Width = 97
    Height = 17
    Caption = #22995'      '#21517
    TabOrder = 9
  end
  object Check_RK_nm: TEdit
    Left = 128
    Top = 48
    Width = 113
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 10
  end
  object CheckRKdate: TCheckBox
    Left = 248
    Top = 48
    Width = 97
    Height = 17
    Caption = #26102#38388
    TabOrder = 11
  end
  object Check_RK_date1: TDateTimePicker
    Left = 304
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
    TabOrder = 12
  end
  object Check_RK_date2: TDateTimePicker
    Left = 416
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
    TabOrder = 13
  end
  object BitBtn1: TBitBtn
    Left = 832
    Top = 16
    Width = 75
    Height = 25
    Caption = #26597#35810
    TabOrder = 14
    OnClick = BitBtn1Click
  end
  object BitBtn2: TBitBtn
    Left = 992
    Top = 16
    Width = 73
    Height = 25
    Caption = #23548#20986
    TabOrder = 15
    OnClick = BitBtn2Click
  end
  object BitBtn3: TBitBtn
    Left = 744
    Top = 48
    Width = 73
    Height = 25
    Hint = #25353#29031#21333#25454#25171#21360#25253#34920#65292#38656#35201#36873#20013#26576#20010#21333#25454#20877#25171#21360
    Caption = #21333#25454#25171#21360
    ParentShowHint = False
    ShowHint = True
    TabOrder = 16
    OnClick = BitBtn3Click
  end
  object BitBtn4: TBitBtn
    Left = 912
    Top = 16
    Width = 75
    Height = 25
    Caption = #21024#38500
    TabOrder = 17
    OnClick = BitBtn4Click
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 727
    Width = 1268
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
    Width = 81
    Height = 21
    Style = csDropDownList
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    ItemHeight = 13
    TabOrder = 19
    OnChange = ComboBox1Change
  end
  object BitBtn5: TBitBtn
    Left = 832
    Top = 48
    Width = 75
    Height = 25
    Hint = #25353#29031#21333#25454#25171#21360#23567#31080#65292#38656#35201#36873#20013#26576#20010#21333#25454#20877#25171#21360
    Caption = #23567#31080#25171#21360
    ParentShowHint = False
    ShowHint = True
    TabOrder = 20
    OnClick = BitBtn5Click
  end
  object BitBtn6: TBitBtn
    Left = 600
    Top = 48
    Width = 139
    Height = 25
    Caption = #32593#32476#21516#27493#20837#24211#25968#25454
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
    Left = 912
    Top = 48
    Width = 75
    Height = 25
    Caption = #23548#20837'EXCEL'
    TabOrder = 22
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 992
    Top = 48
    Width = 75
    Height = 25
    Caption = #23548#20837'TXT'
    TabOrder = 23
    OnClick = Button2Click
  end
  object DataSource1: TDataSource
    DataSet = Form1.RK_ADOQuery
    Left = 1176
    Top = 16
  end
end
