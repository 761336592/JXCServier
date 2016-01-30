object Form8: TForm8
  Left = 260
  Top = 42
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #21830#21697#31227#24211
  ClientHeight = 631
  ClientWidth = 1022
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
    Left = 224
    Top = 24
    Width = 48
    Height = 13
    Caption = #21407#20179#24211#65306
  end
  object Label2: TLabel
    Left = 416
    Top = 24
    Width = 60
    Height = 13
    Caption = #30446#30340#20179#24211#65306
  end
  object Label4: TLabel
    Left = 24
    Top = 608
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
  object Label5: TLabel
    Left = 24
    Top = 24
    Width = 60
    Height = 13
    Caption = #31227#24211#21333#21495#65306
  end
  object sgPurDetail: TStringGrid
    Left = 24
    Top = 80
    Width = 969
    Height = 521
    ColCount = 7
    DefaultRowHeight = 20
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
    OnClick = sgPurDetailClick
    OnDrawCell = sgPurDetailDrawCell
    OnKeyPress = sgPurDetailKeyPress
    OnSelectCell = sgPurDetailSelectCell
  end
  object YK_yck: TEdit
    Left = 288
    Top = 24
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 1
    OnKeyDown = YK_yckKeyDown
  end
  object YK_mck: TEdit
    Left = 488
    Top = 24
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 2
    OnKeyDown = YK_mckKeyDown
  end
  object CheckBox1: TCheckBox
    Left = 904
    Top = 24
    Width = 97
    Height = 17
    Caption = 'pos'#31227#24211
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
    OnClick = CheckBox1Click
  end
  object Button1: TButton
    Left = 632
    Top = 24
    Width = 75
    Height = 25
    Caption = #30830#23450
    TabOrder = 4
    OnClick = Button1Click
  end
  object YK_dh: TEdit
    Left = 96
    Top = 24
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 5
    OnKeyDown = YK_dhKeyDown
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
    Left = 128
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
    TabOrder = 7
  end
  object Button2: TButton
    Left = 728
    Top = 24
    Width = 75
    Height = 25
    Caption = #26032#24314#21333#25454
    TabOrder = 8
    OnClick = Button2Click
  end
end
