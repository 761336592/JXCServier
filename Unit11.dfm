object Form11: TForm11
  Left = 441
  Top = 122
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = #28155#21152#35746#21333
  ClientHeight = 568
  ClientWidth = 824
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
    Left = 32
    Top = 32
    Width = 57
    Height = 13
    Caption = #21333#25454#21495#65306'   '
  end
  object Label2: TLabel
    Left = 32
    Top = 528
    Width = 471
    Height = 13
    Caption = 
      #28201#39336#25552#31034#65306#25970#20987#22238#36710#38190#36339#21040#19979#19968#20010#36755#20837#26684#65292#25970#20987#31354#26684#38190#30830#35748#21333#25454'                                    ' +
      '         '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object Edit1: TEdit
    Left = 96
    Top = 24
    Width = 121
    Height = 21
    BorderStyle = bsNone
    ImeName = #20013#25991'('#31616#20307') - '#25628#29399#25340#38899#36755#20837#27861
    TabOrder = 0
    OnKeyPress = Edit1KeyPress
  end
  object sgPurDetail: TStringGrid
    Left = 32
    Top = 56
    Width = 761
    Height = 457
    DefaultRowHeight = 20
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 1
    OnClick = sgPurDetailClick
    OnDrawCell = sgPurDetailDrawCell
    OnKeyPress = sgPurDetailKeyPress
    OnSelectCell = sgPurDetailSelectCell
  end
  object BitBtn2: TBitBtn
    Left = 424
    Top = 24
    Width = 73
    Height = 25
    Caption = #23548#20837'EXCEL'
    TabOrder = 2
    OnClick = BitBtn2Click
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 549
    Width = 824
    Height = 19
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
  object CheckBox1: TCheckBox
    Left = 695
    Top = 24
    Width = 97
    Height = 17
    Caption = 'pos'#28155#21152#35746#21333
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clGreen
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 4
    OnClick = CheckBox1Click
  end
  object Button1: TButton
    Left = 248
    Top = 24
    Width = 75
    Height = 25
    Caption = #30830#23450
    TabOrder = 5
    OnClick = Button1Click
  end
  object BitBtn1: TBitBtn
    Left = 504
    Top = 24
    Width = 75
    Height = 25
    Caption = #23548#20837'TXT'
    TabOrder = 6
    OnClick = BitBtn1Click
  end
  object Button2: TButton
    Left = 336
    Top = 24
    Width = 75
    Height = 25
    Caption = #26032#24314#21333#25454
    TabOrder = 7
    OnClick = Button2Click
  end
end
