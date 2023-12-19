object MenuForm: TMenuForm
  Left = 0
  Top = 0
  Caption = 'FCAI - Tic Tac Toe'
  ClientHeight = 442
  ClientWidth = 628
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 192
    Top = 64
    Width = 248
    Height = 15
    Caption = 'Choose the game mode that you want to play: '
  end
  object Button1: TButton
    Left = 240
    Top = 112
    Width = 145
    Height = 33
    Caption = 'Original Tic Tac Toe'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 240
    Top = 168
    Width = 145
    Height = 33
    Caption = 'Pyramic Tic Tac Toe'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 240
    Top = 224
    Width = 145
    Height = 33
    Caption = 'Four-in-Row'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 240
    Top = 280
    Width = 145
    Height = 33
    Caption = '5X5 Tic Tac Toe'
    TabOrder = 3
    OnClick = Button4Click
  end
end
