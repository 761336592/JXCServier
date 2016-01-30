object Form5: TForm5
  Left = 296
  Top = 162
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #26032#24314#20986#24211#21333
  ClientHeight = 614
  ClientWidth = 846
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 24
    Width = 60
    Height = 13
    Caption = #20986#24211#21333#21495#65306
  end
  object Label2: TLabel
    Left = 224
    Top = 24
    Width = 48
    Height = 13
    Caption = #20179#24211#21495#65306
  end
  object Label7: TLabel
    Left = 32
    Top = 576
    Width = 348
    Height = 13
    Caption = #28201#39336#25552#31034#65306#25970#20987#22238#36710#38190#36339#21040#19979#19968#20010#36755#20837#26684'                                            '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object CK_dj: TEdit
    Left = 88
    Top = 24
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 0
    OnKeyDown = CK_djKeyDown
  end
  object CK_ck: TEdit
    Left = 280
    Top = 24
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 1
    OnKeyDown = CK_ckKeyDown
  end
  object sgPurDetail: TStringGrid
    Left = 25
    Top = 88
    Width = 808
    Height = 473
    ColCount = 7
    DefaultRowHeight = 20
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 2
    OnClick = sgPurDetailClick
    OnDrawCell = sgPurDetailDrawCell
    OnKeyPress = sgPurDetailKeyPress
    OnSelectCell = sgPurDetailSelectCell
    RowHeights = (
      20
      20
      20
      20
      20)
  end
  object CheckBox1: TCheckBox
    Left = 752
    Top = 24
    Width = 97
    Height = 17
    Caption = 'pos'#20986#24211
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    OnClick = CheckBox1Click
  end
  object Panel1: TPanel
    Left = 240
    Top = 200
    Width = 489
    Height = 313
    TabOrder = 4
    Visible = False
    object Label4: TLabel
      Left = 120
      Top = 104
      Width = 99
      Height = 20
      Caption = #24212#25910#27454#65306'      '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 120
      Top = 144
      Width = 89
      Height = 20
      Caption = #23454#25910#27454#65306'    '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label6: TLabel
      Left = 120
      Top = 184
      Width = 99
      Height = 20
      Caption = #24212#25214#38646#65306'      '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 240
      Top = 104
      Width = 121
      Height = 28
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      ParentFont = False
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 240
      Top = 144
      Width = 121
      Height = 28
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      ParentFont = False
      TabOrder = 1
      OnKeyDown = Edit2KeyDown
    end
    object Edit3: TEdit
      Left = 240
      Top = 184
      Width = 121
      Height = 28
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
      ParentFont = False
      TabOrder = 2
      OnKeyDown = Edit3KeyDown
    end
    object Button2: TButton
      Left = 400
      Top = 272
      Width = 75
      Height = 25
      Caption = #21333#25454#20462#25913
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      OnClick = Button2Click
    end
  end
  object Button1: TButton
    Left = 432
    Top = 24
    Width = 75
    Height = 25
    Caption = #30830#23450
    TabOrder = 5
    OnClick = Button1Click
  end
  object RadioButton1: TRadioButton
    Left = 32
    Top = 56
    Width = 81
    Height = 17
    Caption = #19981#25171#21360
    Checked = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clFuchsia
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    TabStop = True
  end
  object RadioButton2: TRadioButton
    Left = 112
    Top = 56
    Width = 81
    Height = 17
    Caption = #25171#21360#23567#31080
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clFuchsia
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
  end
  object RadioButton3: TRadioButton
    Left = 200
    Top = 56
    Width = 81
    Height = 17
    Caption = #25171#21360#21333#25454
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clFuchsia
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
  end
  object RadioButton4: TRadioButton
    Left = 288
    Top = 56
    Width = 169
    Height = 17
    Caption = #25171#21360#23567#31080#21644#25171#21360#21333#25454
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clFuchsia
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 9
  end
  object Button3: TButton
    Left = 528
    Top = 24
    Width = 75
    Height = 25
    Caption = #26032#24314#21333#25454
    TabOrder = 10
    OnClick = Button3Click
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 595
    Width = 846
    Height = 19
    Panels = <
      item
        Text = #24635#35745#65306
        Width = 50
      end>
    SimplePanel = False
  end
end
