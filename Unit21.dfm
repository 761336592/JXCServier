object Form21: TForm21
  Left = 158
  Top = 412
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #38144#21806#21033#28070#26597#35810
  ClientHeight = 714
  ClientWidth = 1099
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
  object Label7: TLabel
    Left = 456
    Top = 24
    Width = 24
    Height = 13
    Caption = '--------'
  end
  object Label1: TLabel
    Left = 32
    Top = 672
    Width = 336
    Height = 13
    Caption = #28201#39336#25552#31034#65306#21452#20987#26576#26465#35760#24405#65292#21487#20197#26597#30475#20986#24211#26126#32454'                                '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object DBGrid1: TDBGrid
    Left = 24
    Top = 80
    Width = 1049
    Height = 577
    DataSource = DataSource1
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnCellClick = DBGrid1CellClick
    OnDblClick = DBGrid1DblClick
    OnTitleClick = DBGrid1TitleClick
    Columns = <
      item
        Expanded = False
        FieldName = #20986#24211#21333#25454
        Visible = True
      end
      item
        Expanded = False
        FieldName = #25104#26412
        Visible = False
      end
      item
        Expanded = False
        FieldName = #38144#21806#39069
        Visible = True
      end
      item
        Expanded = False
        FieldName = #21033#28070
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
    Left = 32
    Top = 24
    Width = 97
    Height = 17
    Caption = #20986#24211#21333#25454
    TabOrder = 1
  end
  object Edit1: TEdit
    Left = 120
    Top = 24
    Width = 121
    Height = 21
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 2
  end
  object CheckBox2: TCheckBox
    Left = 280
    Top = 24
    Width = 97
    Height = 17
    Caption = #26102#38388
    TabOrder = 3
  end
  object CheckBox3: TCheckBox
    Left = 32
    Top = 48
    Width = 97
    Height = 17
    Caption = #21592#24037#32534#21495
    TabOrder = 4
  end
  object CheckBox4: TCheckBox
    Left = 280
    Top = 48
    Width = 97
    Height = 17
    Caption = #21592#24037#22995#21517
    TabOrder = 5
  end
  object Edit3: TEdit
    Left = 120
    Top = 48
    Width = 121
    Height = 21
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 6
  end
  object Edit4: TEdit
    Left = 368
    Top = 48
    Width = 121
    Height = 21
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 7
  end
  object BitBtn1: TBitBtn
    Left = 632
    Top = 16
    Width = 75
    Height = 25
    Caption = #26597#35810
    TabOrder = 8
    OnClick = BitBtn1Click
  end
  object DateTimePicker1: TDateTimePicker
    Left = 368
    Top = 24
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
  object DateTimePicker2: TDateTimePicker
    Left = 480
    Top = 24
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
    TabOrder = 10
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 695
    Width = 1099
    Height = 19
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object BitBtn2: TBitBtn
    Left = 632
    Top = 48
    Width = 75
    Height = 25
    Caption = #23548#20986
    TabOrder = 12
    OnClick = BitBtn2Click
  end
  object DataSource1: TDataSource
    DataSet = Form1.XSTJ_ADOQuery
    Left = 912
    Top = 32
  end
end
