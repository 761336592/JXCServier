object Form9: TForm9
  Left = 171
  Top = 291
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #31227#24211#26597#35810
  ClientHeight = 714
  ClientWidth = 1297
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
    Left = 608
    Top = 48
    Width = 24
    Height = 13
    Caption = '--------'
  end
  object DBGrid1: TDBGrid
    Left = 24
    Top = 88
    Width = 1241
    Height = 593
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
        FieldName = #31227#24211#21333#21495
        Visible = True
      end
      item
        Expanded = False
        FieldName = #21407#20179#24211
        Visible = True
      end
      item
        Expanded = False
        FieldName = #30446#30340#20179#24211
        Visible = True
      end
      item
        Expanded = False
        FieldName = #25968#37327
        Visible = True
      end
      item
        Expanded = False
        FieldName = #31227#24211#26102#38388
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
  object DateTimePicker1: TDateTimePicker
    Left = 520
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
    TabOrder = 1
  end
  object DateTimePicker2: TDateTimePicker
    Left = 640
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
    TabOrder = 2
  end
  object BitBtn1: TBitBtn
    Left = 888
    Top = 16
    Width = 75
    Height = 25
    Caption = #26597#35810
    TabOrder = 3
    OnClick = BitBtn1Click
  end
  object CheckBox1: TCheckBox
    Left = 16
    Top = 16
    Width = 57
    Height = 17
    Caption = #26465#30721
    TabOrder = 4
  end
  object CheckBox2: TCheckBox
    Left = 456
    Top = 16
    Width = 57
    Height = 17
    Caption = #21407#20179#24211
    TabOrder = 5
  end
  object CheckBox3: TCheckBox
    Left = 656
    Top = 16
    Width = 81
    Height = 17
    Caption = #30446#30340#20179#24211'    '
    TabOrder = 6
  end
  object CheckBox4: TCheckBox
    Left = 16
    Top = 48
    Width = 105
    Height = 17
    Caption = #32534'         '#21495
    TabOrder = 7
  end
  object CheckBox5: TCheckBox
    Left = 256
    Top = 48
    Width = 97
    Height = 17
    Caption = #22995'     '#21517
    TabOrder = 8
  end
  object CheckBox6: TCheckBox
    Left = 456
    Top = 48
    Width = 81
    Height = 17
    Caption = #26102'    '#38388
    TabOrder = 9
  end
  object Edit1: TEdit
    Left = 128
    Top = 16
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 10
  end
  object Edit2: TEdit
    Left = 520
    Top = 16
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 11
  end
  object Edit3: TEdit
    Left = 736
    Top = 16
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 12
  end
  object Edit4: TEdit
    Left = 128
    Top = 48
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 13
  end
  object Edit5: TEdit
    Left = 320
    Top = 48
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 14
  end
  object BitBtn2: TBitBtn
    Left = 968
    Top = 48
    Width = 75
    Height = 25
    Caption = #23548#20986
    TabOrder = 15
    OnClick = BitBtn2Click
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 695
    Width = 1297
    Height = 19
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object ComboBox1: TComboBox
    Left = 32
    Top = 16
    Width = 89
    Height = 21
    Style = csDropDownList
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    ItemHeight = 13
    TabOrder = 17
    OnChange = ComboBox1Change
  end
  object CheckBox7: TCheckBox
    Left = 256
    Top = 16
    Width = 97
    Height = 17
    Caption = #21333'    '#21495
    TabOrder = 18
  end
  object Edit6: TEdit
    Left = 320
    Top = 16
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 19
  end
  object Button1: TButton
    Left = 968
    Top = 16
    Width = 75
    Height = 25
    Caption = #21333#25454#25171#21360
    TabOrder = 20
    OnClick = Button1Click
  end
  object BitBtn3: TBitBtn
    Left = 808
    Top = 48
    Width = 155
    Height = 25
    Caption = #32593#32476#21516#27493#31227#24211#25968#25454
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clRed
    Font.Height = -13
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 21
    OnClick = BitBtn3Click
  end
  object Button2: TButton
    Left = 1048
    Top = 16
    Width = 75
    Height = 25
    Caption = #23548#20837'EXCEL'
    TabOrder = 22
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 1048
    Top = 48
    Width = 75
    Height = 25
    Caption = #23548#20837'TXT'
    TabOrder = 23
    OnClick = Button3Click
  end
  object DataSource1: TDataSource
    DataSet = Form1.YK_ADOQuery
    Left = 1152
    Top = 8
  end
end