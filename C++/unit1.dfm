object Form1: TForm1
  Left = 185
  Top = 222
  HorzScrollBar.Visible = False
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Document Reader SDK - Test Application'
  ClientHeight = 967
  ClientWidth = 1014
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Arial'
  Font.Style = []
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000080020000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    0000000000000000000000000000000000000000000000000000000000000003
    0FFFFFFFFFFFFFFFFFFFFFFFFFFF00F030FFFFFFFFFFFFFFFFFFFFFFFFFF00F0
    B30FFFFFBFFFBFFFFBFFFBFFFBFF0FFF0B30FFFFFFFFFFFFFFFFFFFFFFFF0FFF
    0BB30FFFFFFFFFFFFFFFFFFFFFFF0FFFF0BB30F7F0FFFFFF70F0770F07F00FFF
    F0BBB30F7F7FFFFF7FBF7BFF070F0FFF7F0BBB3007FFFFFFFFFFFFFFFFFF0FFF
    000BBBB3076FFFFFFFFFFFFFFFFF0FFF07F0BBBB30FFFFFFF0F00F7B7FF00FFF
    6B70BBBBB30FFFFF77FF7FFBF7FF0FFF677F0BBBBB30FFFFFF7FFFFFFFFF0FFF
    7F000BBBBBB30FFFFFFFFFFF70F00FFF770BBBBBBBBB30FF0F7FF07BF7F00FFF
    0670BBBBBB33330F7FFB7F7FFF7F0FFF77F0BBBBBB30000FFFFFFFFFFFFF0FFF
    70070BBBBBB30FFFFFFFFFFFFFFF0FFFF77F0BBBBBBB30FFFFFFFFFFFFFF0FFF
    F77700BBBBBBB30F1F1F11F1F1FF0FFFFFFFF0BBBBBBBB301F11FF11F11F0FFF
    FFFFF00BBBBBBBB30F1F1FFBF1F100FFFBFBFF0BBBBBBBBB30F1FFF1FF1F00FF
    FFFFFF00BBBBBBBBB30FFFFFFFFF0000FFFFFFF0BBBBBBBBBB30FFFFFFFF0000
    000000000BBBBBBBBBB3000000000000000000000BBBBBBBBBBB300000000000
    0000000000BBBBBBBBBBB300000000000000000000BBBBBBBBBBBB3000000000
    00000000000BBBBBBBBBBBB3000000000000000000000000000000000000FFFF
    FFFFC0000000C000000080000000800000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000000000000000000000000000000000000000000000000800000008000
    0000C0000000F0000000FFF0003FFFF8001FFFF8000FFFFC0007FFFC0003}
  Position = poScreenCenter
  Scaled = False
  OnClose = FormClose
  OnCreate = FormCreate
  DesignSize = (
    1014
    967)
  TextHeight = 14
  object Label1: TLabel
    Left = 184
    Top = 12
    Width = 67
    Height = 14
    Caption = 'SDK Version :'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object LibraryVersionLabel: TLabel
    Left = 264
    Top = 12
    Width = 97
    Height = 14
    Caption = 'LibraryVersionLabel'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
  end
  object Bevel5: TBevel
    Left = 536
    Top = 0
    Width = 3
    Height = 963
    Anchors = [akLeft, akTop, akBottom]
    Shape = bsLeftLine
    ExplicitHeight = 735
  end
  object Bevel1: TBevel
    Left = 8
    Top = 40
    Width = 529
    Height = 9
    Shape = bsTopLine
  end
  object ConnectDeviceButton: TSpeedButton
    Left = 8
    Top = 79
    Width = 72
    Height = 25
    AllowAllUp = True
    GroupIndex = 1
    Caption = 'Connect'
    OnClick = ConnectDeviceButtonClick
  end
  object Shape1: TShape
    Left = 472
    Top = 6
    Width = 25
    Height = 25
    Brush.Color = clSilver
  end
  object Bevel2: TBevel
    Left = 10
    Top = 312
    Width = 529
    Height = 190
    Anchors = [akLeft, akBottom]
    Shape = bsTopLine
    ExplicitTop = 240
  end
  object Bevel3: TBevel
    Left = 8
    Top = 508
    Width = 529
    Height = 9
    Anchors = [akLeft, akBottom]
    Shape = bsTopLine
    ExplicitTop = 280
  end
  object SB_1mp: TSpeedButton
    Left = 86
    Top = 77
    Width = 38
    Height = 18
    GroupIndex = 512
    Down = True
    Caption = '1 MP'
    Visible = False
    OnClick = SB_1mpClick
  end
  object SB_3mp: TSpeedButton
    Left = 86
    Top = 94
    Width = 38
    Height = 18
    GroupIndex = 512
    Caption = '3 MP'
    Visible = False
    OnClick = SB_3mpClick
  end
  object SB_VideoDetection: TSpeedButton
    Left = 86
    Top = 48
    Width = 38
    Height = 20
    Hint = 'Enable video detection (use before connect)'
    AllowAllUp = True
    GroupIndex = 584
    Caption = 'VD'
    ParentShowHint = False
    ShowHint = True
  end
  object SB_5mp: TSpeedButton
    Left = 86
    Top = 111
    Width = 38
    Height = 18
    GroupIndex = 512
    Caption = '5 MP'
    Visible = False
    OnClick = SB_5mpClick
  end
  object SB_92mp: TSpeedButton
    Left = 86
    Top = 128
    Width = 38
    Height = 18
    GroupIndex = 512
    Caption = '9/2 Mp'
    Visible = False
    OnClick = SB_92mpClick
  end
  object SB_9mp: TSpeedButton
    Left = 86
    Top = 145
    Width = 38
    Height = 18
    GroupIndex = 512
    Caption = '9 MP'
    Visible = False
    OnClick = SB_9mpClick
  end
  object UVExpLabel: TLabel
    Left = 409
    Top = 61
    Width = 64
    Height = 14
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 5
    Caption = 'UV exposure'
  end
  object LoadLibraryButton: TButton
    Left = 8
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Load library'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = LoadLibraryButtonClick
  end
  object IntializeButton: TButton
    Left = 8
    Top = 48
    Width = 72
    Height = 25
    Caption = 'Initialize'
    Enabled = False
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = IntializeButtonClick
  end
  object FreeLibraryButton: TButton
    Left = 88
    Top = 8
    Width = 75
    Height = 25
    Caption = 'Free library'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = FreeLibraryButtonClick
  end
  object FDSPanel: TPanel
    Left = 545
    Top = 387
    Width = 465
    Height = 577
    Anchors = [akLeft, akBottom]
    BevelInner = bvRaised
    BevelOuter = bvLowered
    Color = clSilver
    TabOrder = 3
    ExplicitTop = 369
  end
  object Memo1: TMemo
    Left = 543
    Top = 8
    Width = 465
    Height = 373
    TabStop = False
    Anchors = [akLeft, akTop, akBottom]
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 4
    ExplicitHeight = 355
  end
  object ProcessButton: TButton
    Left = 8
    Top = 110
    Width = 72
    Height = 25
    Caption = 'Process'
    TabOrder = 5
    OnClick = ProcessButtonClick
  end
  object ImagesTabControl: TTabControl
    Left = 8
    Top = 508
    Width = 521
    Height = 449
    Anchors = [akLeft, akBottom]
    TabOrder = 6
    Tabs.Strings = (
      '1'
      '2')
    TabIndex = 0
    OnChange = ImagesTabControlChange
    ExplicitTop = 490
    object PaintBox: TPaintBox
      Left = 4
      Top = 25
      Width = 513
      Height = 420
      Align = alClient
      OnPaint = PaintBoxPaint
      ExplicitLeft = 0
      ExplicitTop = 33
    end
  end
  object SaveImagesCheckBox: TCheckBox
    Left = 128
    Top = 77
    Width = 233
    Height = 17
    Hint = 'Form a buffer'
    Caption = 'ofrFormat_FileBuffer'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = [fsItalic]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 7
  end
  object LocateCheckBox: TCheckBox
    Left = 215
    Top = 340
    Width = 113
    Height = 17
    Hint = 'Crops images along document borders'
    Anchors = [akLeft, akBottom]
    Caption = 'Locate Document'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 8
    ExplicitTop = 322
  end
  object XMLCheckBox: TCheckBox
    Left = 128
    Top = 100
    Width = 233
    Height = 17
    Hint = 'Form XML-representation'
    Caption = 'ofrFormat_XML'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = [fsItalic]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 9
  end
  object ClipboardCheckBox: TCheckBox
    Left = 128
    Top = 123
    Width = 233
    Height = 17
    Hint = 'Place the result into clipboard'
    Caption = 'ofrTransport_Clipboard'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = [fsItalic]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 10
  end
  object FileCheckBox: TCheckBox
    Left = 128
    Top = 145
    Width = 233
    Height = 17
    Hint = 'Write to file'
    Caption = 'ofrTransport_File'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = [fsItalic]
    ParentFont = False
    ParentShowHint = False
    ShowHint = True
    TabOrder = 11
  end
  object MRZCheckBox: TCheckBox
    Left = 215
    Top = 357
    Width = 97
    Height = 17
    Hint = 'Reads Machine Readable Zone (MRZ)'
    Anchors = [akLeft, akBottom]
    Caption = 'Read MRZ'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 12
    OnClick = CheckBoxClick
    ExplicitTop = 339
  end
  object MRZTestQualityCheckBox: TCheckBox
    Left = 215
    Top = 374
    Width = 121
    Height = 17
    Hint = 'Checks Machine Readable Zone (MRZ)'
    Anchors = [akLeft, akBottom]
    Caption = 'MRZ Test Quality'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 13
    OnClick = CheckBoxClick
    ExplicitTop = 356
  end
  object ScanImagesCheckBox: TCheckBox
    Left = 215
    Top = 323
    Width = 113
    Height = 17
    Hint = 'Shows images for all selected lighting scheme checkboxes'
    Anchors = [akLeft, akBottom]
    Caption = 'Get Images'
    Checked = True
    ParentShowHint = False
    ShowHint = True
    State = cbChecked
    TabOrder = 14
    ExplicitTop = 305
  end
  object BarCodesCheckBox: TCheckBox
    Left = 376
    Top = 323
    Width = 121
    Height = 17
    Hint = 'Reads barcodes'
    Anchors = [akLeft, akBottom]
    Caption = 'Read Barcodes'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 15
    OnClick = CheckBoxClick
    ExplicitTop = 305
  end
  object DocTypeCheckBox: TCheckBox
    Left = 376
    Top = 339
    Width = 153
    Height = 17
    Hint = 'Tries to determine document type'
    Anchors = [akLeft, akBottom]
    Caption = 'Determine Document Type'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 16
    OnClick = CheckBoxClick
    ExplicitTop = 321
  end
  object VisualOCRCheckBox: TCheckBox
    Left = 376
    Top = 355
    Width = 121
    Height = 17
    Hint = 'Obtains document text and graphic filling'
    Anchors = [akLeft, akBottom]
    Caption = 'Visual Zone OCR'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 17
    OnClick = CheckBoxClick
    ExplicitTop = 337
  end
  object AuthenticityCheckBox: TCheckBox
    Left = 376
    Top = 371
    Width = 121
    Height = 17
    Hint = 'Obtains document authenticity check results'
    Anchors = [akLeft, akBottom]
    Caption = 'Authenticity Check'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 18
    OnClick = CheckBoxClick
    ExplicitTop = 353
  end
  object OCRLexAnalisysButton: TButton
    Left = 376
    Top = 395
    Width = 153
    Height = 25
    Anchors = [akLeft, akBottom]
    Caption = 'OCR Lexical Analisys'
    TabOrder = 19
    OnClick = OCRLexAnalisysButtonClick
    ExplicitTop = 377
  end
  object ProgressBar: TProgressBar
    Left = 8
    Top = 266
    Width = 531
    Height = 29
    TabOrder = 20
    Visible = False
  end
  object AllImagesCheckBox: TCheckBox
    Left = 128
    Top = 54
    Width = 233
    Height = 17
    Hint = 'Get all images being taken automatically during scanning'
    Caption = 'Receive all scanned images (scan time only)'
    ParentShowHint = False
    ShowHint = True
    TabOrder = 21
  end
  object LightCheckListBox: TCheckListBox
    Left = 8
    Top = 323
    Width = 201
    Height = 115
    Hint = 'Lightning schemes'
    Anchors = [akLeft, akBottom]
    BorderStyle = bsNone
    Color = 12040119
    Columns = 2
    ItemHeight = 20
    ParentShowHint = False
    ShowHint = True
    TabOrder = 22
    ExplicitTop = 305
  end
  object UVExpSpinEdit: TCSpinEdit
    Left = 481
    Top = 55
    Width = 49
    Height = 41
    Hint = 'UV exposure value'
    Anchors = [akLeft, akTop, akBottom]
    AutoSize = False
    MaxValue = 10
    MinValue = 1
    ParentShowHint = False
    ShowHint = True
    TabOrder = 23
    Value = 6
    OnChange = UVExpSpinEditChange
    ExplicitHeight = 23
  end
end
