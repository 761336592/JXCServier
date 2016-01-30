object Form10: TForm10
  Left = 361
  Top = 384
  Width = 1232
  Height = 746
  BorderIcons = [biSystemMenu, biMinimize]
  Caption = #39564#21333#26597#35810
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
    Left = 424
    Top = 48
    Width = 24
    Height = 13
    Caption = '--------'
  end
  object DBGrid1: TDBGrid
    Left = 16
    Top = 112
    Width = 1185
    Height = 577
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
        FieldName = #21333#25454
        Visible = True
      end
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
        FieldName = #24212#25195#25968#37327
        Visible = True
      end
      item
        Expanded = False
        FieldName = #24050#25195#25968#37327
        Visible = True
      end
      item
        Expanded = False
        FieldName = #26102#38388
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
  object CheckBox1: TCheckBox
    Left = 16
    Top = 16
    Width = 57
    Height = 17
    Caption = #26465#30721
    TabOrder = 1
  end
  object Edit1: TEdit
    Left = 136
    Top = 16
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 2
  end
  object CheckBox2: TCheckBox
    Left = 264
    Top = 16
    Width = 57
    Height = 17
    Caption = #21333#25454
    TabOrder = 3
  end
  object Edit2: TEdit
    Left = 328
    Top = 16
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 4
  end
  object CheckBox3: TCheckBox
    Left = 464
    Top = 16
    Width = 81
    Height = 17
    Caption = #32534#21495'    '
    TabOrder = 5
  end
  object Edit3: TEdit
    Left = 544
    Top = 16
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 6
  end
  object CheckBox4: TCheckBox
    Left = 16
    Top = 48
    Width = 97
    Height = 17
    Caption = #22995'    '#21517
    TabOrder = 7
  end
  object Edit4: TEdit
    Left = 136
    Top = 48
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 8
  end
  object CheckBox5: TCheckBox
    Left = 264
    Top = 48
    Width = 65
    Height = 17
    Caption = #26102#38388
    TabOrder = 9
  end
  object DateTimePicker1: TDateTimePicker
    Left = 336
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
    TabOrder = 10
  end
  object DateTimePicker2: TDateTimePicker
    Left = 448
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
    TabOrder = 11
  end
  object BitBtn1: TBitBtn
    Left = 720
    Top = 16
    Width = 75
    Height = 25
    Caption = #26597#35810
    TabOrder = 12
    OnClick = BitBtn1Click
  end
  object BitBtn2: TBitBtn
    Left = 720
    Top = 48
    Width = 75
    Height = 25
    Caption = #23548#20986
    TabOrder = 13
    OnClick = BitBtn2Click
  end
  object BitBtn3: TBitBtn
    Left = 16
    Top = 80
    Width = 75
    Height = 25
    Caption = #24212#25195'='#24050#25195
    TabOrder = 14
    OnClick = BitBtn3Click
  end
  object BitBtn4: TBitBtn
    Left = 136
    Top = 80
    Width = 75
    Height = 25
    Caption = #24212#25195'>'#24050#25195
    TabOrder = 15
    OnClick = BitBtn4Click
  end
  object BitBtn5: TBitBtn
    Left = 272
    Top = 80
    Width = 75
    Height = 25
    Caption = #24212#25195'<'#24050#25195
    TabOrder = 16
    OnClick = BitBtn5Click
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 689
    Width = 1216
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
    Width = 97
    Height = 21
    Style = csDropDownList
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    ItemHeight = 13
    TabOrder = 18
    OnChange = ComboBox1Change
  end
  object Button1: TButton
    Left = 808
    Top = 16
    Width = 75
    Height = 25
    Caption = #21333#25454#25171#21360
    TabOrder = 19
    OnClick = Button1Click
  end
  object DataSource1: TDataSource
    DataSet = Form1.YD_ADOQuery
    Left = 912
    Top = 16
  end
end
