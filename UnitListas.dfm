object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Form1'
  ClientHeight = 177
  ClientWidth = 293
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 293
    Height = 177
    Align = alClient
    TabOrder = 0
    object SpeedButton1: TSpeedButton
      AlignWithMargins = True
      Left = 11
      Top = 4
      Width = 271
      Height = 22
      Margins.Left = 10
      Margins.Right = 10
      Align = alTop
      Caption = 'Geral lista'
      OnClick = SpeedButton1Click
      ExplicitLeft = 136
      ExplicitTop = 80
      ExplicitWidth = 23
    end
    object Memo1: TMemo
      AlignWithMargins = True
      Left = 11
      Top = 32
      Width = 271
      Height = 141
      Margins.Left = 10
      Margins.Right = 10
      Align = alClient
      TabOrder = 0
      ExplicitTop = 61
      ExplicitHeight = 112
    end
  end
end
