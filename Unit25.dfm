object Form25: TForm25
  Left = 540
  Top = 90
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #21830#21697#39564#21333
  ClientHeight = 600
  ClientWidth = 810
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
    Left = 28
    Top = 24
    Width = 36
    Height = 13
    Caption = #21333#21495#65306
  end
  object Label4: TLabel
    Left = 32
    Top = 560
    Width = 471
    Height = 13
    Caption = 
      #28201#39336#25552#31034#65306#25970#20987#22238#36710#38190#36339#21040#19979#19968#20010#36755#20837#26684#65292#25970#20987#31354#26684#38190#30830#35748#39564#21333'                                    ' +
      '         '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object sgPurDetail: TStringGrid
    Left = 24
    Top = 88
    Width = 761
    Height = 457
    ColCount = 6
    DefaultRowHeight = 20
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 0
    OnClick = sgPurDetailClick
    OnDrawCell = sgPurDetailDrawCell
    OnKeyPress = sgPurDetailKeyPress
    OnSelectCell = sgPurDetailSelectCell
  end
  object Edit1: TEdit
    Left = 76
    Top = 16
    Width = 121
    Height = 21
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 1
  end
  object Button1: TButton
    Left = 212
    Top = 16
    Width = 75
    Height = 25
    Caption = #30830#35748#39564#21333
    TabOrder = 2
    OnClick = Button1Click
  end
  object CheckBox1: TCheckBox
    Left = 662
    Top = 24
    Width = 97
    Height = 17
    Caption = 'pos'#39564#21333
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 3
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
    TabOrder = 4
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
    TabOrder = 5
  end
  object Button2: TButton
    Left = 376
    Top = 16
    Width = 75
    Height = 25
    Caption = #23548#20837'EXCEL'
    TabOrder = 6
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 464
    Top = 16
    Width = 75
    Height = 25
    Caption = #23548#20837'TXT'
    TabOrder = 7
    OnClick = Button3Click
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 581
    Width = 810
    Height = 19
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object Button4: TButton
    Left = 296
    Top = 16
    Width = 75
    Height = 25
    Caption = #26032#24314#39564#21333
    TabOrder = 9
    OnClick = Button4Click
  end
end
