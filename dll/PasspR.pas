unit PasspR;

interface

uses SysUtils, Windows, Classes;

type
  TRelRect = record
    Left, Top, Right, Bottom: Single;
  end;

  PArrayOfChar = ^TArrayOfChar;
  TArrayOfChar = array [0 .. 255] of AnsiChar;

  PRegulaDeviceProperties = ^TRegulaDeviceProperties;

  TRegulaDeviceProperties = record
    DeviceID: DWORD; // eRPRM_DeviceTypes
    Lights: DWORD; // eRPRM_Lights combination
    SerialNumber: DWORD; // if available
    Features: DWORD; // eRPRM_DeviceAdditionalFeatures
    DeviceCtrl: DWORD; // eRPRM_DeviceControlTypes
    DirectShowName: PAnsiChar; // DirectShow device name
    SystemUID: PAnsiChar; // System unique device name
    Name: PAnsiChar; // non-DirectShow device name
    AvailableVideoModes: DWORD; // eRPRM_VideoModes combination
    LabelSerialNumber: UINT64; // serial number on label deprecated
    LabelSerialNumberStr: PAnsiChar; // serial number on label extended
    CameraSerialNumber: UINT64; // serial number of the camera
    UID: TGUID; // device unique identifier
    Capabilities: DWORD;
    Authenticity: DWORD;
    Database: DWORD;
    ValidUntil: UINT64;
    WillConnect: Boolean;
  end;

const
  // enum eRPRM_DeviceAdditionalFeatures {
  RPRM_DeviceAdditionalFeature_None = $00000000;
  RPRM_DeviceAdditionalFeature_Accumulator = $00000001;
  RPRM_DeviceAdditionalFeature_Indicators_Triple = $00000002;
  RPRM_DeviceAdditionalFeature_VideoDetection = $00000004;
  RPRM_DeviceAdditionalFeature_IRFilter = $00000008;
  RPRM_DeviceAdditionalFeature_Indicators_Single = $00000010;
  RPRM_DeviceAdditionalFeature_Indicators_Double = $00000020;
  RPRM_DeviceAdditionalFeature_Indicators_Button = $00000040;
  RPRM_DeviceAdditionalFeature_Indicators_Four = $00000080;

  RPRM_DeviceAdditionalFeature_2SidedWhite = $00000100;
  RPRM_DeviceAdditionalFeature_2SidedIR = $00000200;
  RPRM_DeviceAdditionalFeature_2SidedUV = $00000400;

  RPRM_DeviceAdditionalFeature_MagneticStripe = $00001000;
  RPRM_DeviceAdditionalFeature_JPEGCompression = $00002000;
  RPRM_DeviceAdditionalFeature_IntegratedDisplay = $00004000;
  RPRM_DeviceAdditionalFeature_KeyboardLight = $00008000;
  RPRM_DeviceAdditionalFeature_ExternalLight = $00010000;
  RPRM_DeviceAdditionalFeature_FactoryCalibrated = $00020000;
  RPRM_DeviceAdditionalFeature_DocumentSensor = $00040000;
  RPRM_DeviceAdditionalFeature_DocSizeMode = $00080000;

  // enum eRPRM_DeviceControlTypes {
  RPRM_DeviceControlType_DirectShow = 1;
  RPRM_DeviceControlType_DirectIO = 2;
  RPRM_DeviceControlType_Virtual = 3;

  // enum eRPRM_DeviceTypes {
  RPRM_DeviceType_Unknown = $00000000; // Unknown device
  RPRM_DeviceType_Virtual = $FFFFFFFF; // Virtual Device (Security Key)

  // 83x3
  RPRM_DeviceType_FX_8313_115 = $08313115; // OV 1.3
  RPRM_DeviceType_FX_8333_115 = $08333115; // OV 3.0
  RPRM_DeviceType_FX_8353_115 = $08353115; // OV 5.1
  RPRM_DeviceType_FX_8383_115 = $08383115; // Micron 3.1
  RPRM_DeviceType_FX_8883_115 = $08883115; // Micron 9.0
  RPRM_DeviceType_FX_8853_115 = $08853115; // Micron 5.0
  // 83x3M
  RPRM_DeviceType_FX_8303_115 = $08323115; // Micron 3.1

  // 83x4 (83x3 + Bottom light table)
  RPRM_DeviceType_FX_8314_115 = $08314115; // OV 1.3
  RPRM_DeviceType_FX_8334_115 = $08334115; // OV 3.0
  RPRM_DeviceType_FX_8354_115 = $08354115; // OV 3.0
  RPRM_DeviceType_FX_8384_115 = $08384115; // Micron 3.1
  RPRM_DeviceType_FX_8884_115 = $08884115; // Micron 9.0
  RPRM_DeviceType_FX_8854_115 = $08854115; // Micron 5.0

  // 7007
  RPRM_DeviceType_FX_7107_115 = $07107115; // OV 1.3
  RPRM_DeviceType_FX_7117_115 = $07117115; // OV 1.3 Modification 2
  RPRM_DeviceType_FX_7307_115 = $07307115; // OV 3.0
  RPRM_DeviceType_FX_7317_115 = $07317115; // OV 3.1 Modification 2
  RPRM_DeviceType_FX_7507_115 = $07507115; // OV 5.1
  RPRM_DeviceType_FX_7517_115 = $07517115; // OV 5.1 Modification 2
  RPRM_DeviceType_FX_7387_115 = $07387115; // Micron 3.1
  RPRM_DeviceType_FX_7397_115 = $07397115; // Micron 3.1 Modification 2
  RPRM_DeviceType_FX_7887_115 = $07887115; // Micron 9.0
  RPRM_DeviceType_FX_7857_115 = $07857115; // Micron 5.0

  // 8307
  RPRM_DeviceType_FX_8307 = $08307000; // Micron 3.1 Mp (MRZ-only reader)

  // 7024
  RPRM_DeviceType_FX_7104_115 = $07104115; // OV 1.3
  RPRM_DeviceType_FX_7304_115 = $07304115; // OV 3.0
  RPRM_DeviceType_FX_7504_115 = $07504115; // OV 5.0
  RPRM_DeviceType_FX_7384_115 = $07384115; // Micron 3.1          1
  RPRM_DeviceType_FX_7884_115 = $07884115; // Micron 9.0          1
  RPRM_DeviceType_FX_7854_115 = $07854115; // Micron 5.0          1
  RPRM_DeviceType_FX_78A4_115 = $078A4115; // Micron 10.0         1
  RPRM_DeviceType_FX_78E4_115 = $078E4115; // Micron 14.0         1
  RPRM_DeviceType_FX_78x4M = $07864115; // Micron 18.0 Mp         1
  RPRM_DeviceType_FX_75A4M = $075A4115; //AR 5 Mp

  // 7024 Lite functionality
  RPRM_DeviceType_FX_7104_Lite = $07104333; // OV 1.3
  RPRM_DeviceType_FX_7304_Lite = $07304333; // OV 3.0
  RPRM_DeviceType_FX_7504_Lite = $07504333; // OV 5.1
  RPRM_DeviceType_FX_7384_Lite = $07384333; // Micron 3.1
  RPRM_DeviceType_FX_7884_Lite = $07884333; // Micron 9.0
  RPRM_DeviceType_FX_7854_Lite = $07854333; // Micron 5.0
  RPRM_DeviceType_FX_78A4_Lite = $078A4333; // Micron 10.0
  RPRM_DeviceType_FX_78E4_Lite = $078E4333; // Micron 14.0

  // 70x3
  RPRM_DeviceType_FX_7103_115 = $07103115; // OV 1.3
  RPRM_DeviceType_FX_7303_115 = $07303115; // OV 3.0
  RPRM_DeviceType_FX_7503_115 = $07503115; // OV 5.1
  RPRM_DeviceType_FX_7383_115 = $07383115; // Micron 3.1
  RPRM_DeviceType_FX_7883_115 = $07883115; // Micron 9.0
  RPRM_DeviceType_FX_7853_115 = $07853115; // Micron 5.0

  // 4820
  RPRM_DeviceType_FX_4821 = $04821115; // OV 1.3
  RPRM_DeviceType_FX_4823 = $04823115; // OV 3.0
  RPRM_DeviceType_FX_4825 = $04825115; // OV 5.1
  RPRM_DeviceType_FX_4822 = $04822115; // Micron 3.1
  RPRM_DeviceType_FX_4828 = $04828115; // Micron 9.0
  RPRM_DeviceType_FX_4858 = $04858115; // Micron 5.0

  // 7008
  RPRM_DeviceType_FX_7038 = $07038115; // Micron 3.1              1
  RPRM_DeviceType_FX_7038_VB = $17038115; // Micron 3.1           1
  RPRM_DeviceType_FX_7058 = $07058115; // Micron 5.0              1

  // 70x4M small reader
  RPRM_DeviceType_FX_73x4M = $07364115; // Micron 3.1              1
  RPRM_DeviceType_FX_75x4M = $07564115; // Micron 5.0              1
  RPRM_DeviceType_FX_71x4M = $07A64115; // Micron 10.0             1

  // 7308
  RPRM_DeviceType_FX_7338 = $07338115; // Micron 3.1               1

  // 72x3  ID1 reader with 2 cameras
  RPRM_DeviceType_FX_7253 = $07253115; // OV 5.0 Mp with 2 cameras 1

  // 7017 simple reader with W
  RPRM_DeviceType_FX_7517 = $07517000; // Micron 5Mp
  RPRM_DeviceType_FX_7017 = $07017000; // OV 5Mp                   1

  // 7017D double reader master device
  RPRM_DeviceType_FX_7017D_M = $07017100; // OV 5Mp                1

  // 7017D double reader slave device
  RPRM_DeviceType_FX_7017D_S = $07017200; // OV 5Mp                1

  // 7027 simple reader with W rebel
  RPRM_DeviceType_FX_7027 = $07027000; // OV 5Mp                   1

  // 70x8M reader with camera as 7027 and 7017
  RPRM_DeviceType_FX_7058M = $07058110;     // OV 5 Mp             1
  RPRM_DeviceType_FX_7058M_VB = $17058110;  // OV 5 Mp             1
  RPRM_DeviceType_FX_7038M = $07038110;     //AR 13 Mp             1

  // 76x4M reader with camera as 7017 ,
  RPRM_DeviceType_FX_76x4M = $07664115; // OV 5Mp                  1

  // 8850 - Banknote Reader 1/2 pages
  RPRM_DeviceType_EOS_8850_5 = $08850005; // Cannon EOS 5DS (5DSR)
  // 7074
  RPRM_DeviceType_EOS_7074_550 = $07074550; // Cannon EOS 550D

  // 7084
  RPRM_DeviceType_EOS_7084_7 = $07084007; // Cannon EOS 7D

  RPRM_DeviceType_EOS_8824_80 = $08824080; // Cannon EOS 80D
  // 8803 - Banknote Reader
  RPRM_DeviceType_EOS_8803_100 = $08803100; // Cannon EOS 100D

  // Camera Canon EOS
  RPRM_DeviceType_CanonEOS = $20000001; // Canon EOS series

  // 4107
  RPRM_DeviceType_FX_4137 = $04137115; // Micron 3.1
  RPRM_DeviceType_FX_4157 = $04157115; // Micron 5.0

  // ARH
  RPRM_DeviceType_ARH = $10000001;

  // 3M
  RPRM_DeviceType_3M = $10000002;

  // Access-IS
  RPRM_DeviceType_AccessIs = $10000003;

  // TWAIN
  RPRM_DeviceType_TWAIN = $10000004;

  // Bisys Korea
  RPRM_DeviceType_BK = $10000005;

  // Bisys Korea New - 7303
  RPRM_DeviceType_73xx = $10000006;

  // e-seek M500
  RPRM_DeviceType_M500 = $10000007;

  // Desko
  RPRM_DeviceType_Desko    = $10000008;

  //eSeek M600 CCID 1.00 0
  RPRM_DeviceType_M600 = $10000009;

  // DESKO Icon
  RPRM_DeviceType_DeskoIcon = $1000000A;

  // Xperix RealPass
  RPRM_DeviceType_XperixRealPass = $1000000B;

  // Wise Cube wsdef API
  RPRM_DeviceType_WiseCube_wsdef = $1000000C;

  // unused ----------------------------------------------------------------------------------------------
  RPRM_DeviceType_USB20_1  = $00200001; // RdrPassport with USB2.0 camera
  RPRM_DeviceType_7004s    = $00200002; // PR7004S    (W+, IR+)
  RPRM_DeviceType_7003_01  = $00200003; // PR7003_01  (Wt, Ws, W+, IR+)
  RPRM_DeviceType_7003_110 = $07003110; // PR7003_111 (Wt, Ws, W+, IRt, IRs, IR+, UV365)
  RPRM_DeviceType_7003_111 = $07003111; // PR7003_111 (Wt, Ws, W+, IRt, IRs, IR+, UV365, 3MW1, 3MW2, 3MW+)
  RPRM_DeviceType_7004_100 = $07004100; // PR7004_100 / PR7005_100 (W+, IR+)
  RPRM_DeviceType_7004_110 = $07004110; // PR7004_110 / PR7005_110 (W+, IR+, UV)
  RPRM_DeviceType_70x4_111 = $07004111; // PR70x4_111 / PR70x5_111 (W+, IR+, UV, 3MW+)
  RPRM_DeviceType_70x4_114 = $07004114;
  // PR70x4_114 / PR70x5_114 (Wt, Ws, W+, IRt, IRs, IR+, UV365, 3MW1, 3MW2, 3MW+, 3MIR1, 3MIR2, 3MIR+)
  RPRM_DeviceType_70x4_115 = $07004115; // PR70x4_115 / PR70x5_115 (W(m), IR(m), UV365, 3MW1, 3MW2, 3MW+)
  RPRM_DeviceType_8303_100 = $08303100; // PR8303_100 (W+, IR+)
  RPRM_DeviceType_8303_110 = $08303110; // PR8303_110 (W+, IR+, UV)
  RPRM_DeviceType_8303_111 = $08303111; // PR8303_111 (W+, IR+, UV, 3M1, 3M2)
  RPRM_DeviceType_8303_114 = $08303114; // PR8303_114 (W_down, W_up, W+, IR_down, IR_up, IR+, UV365, 3MW1, 3MW2, 3MW+)
  RPRM_DeviceType_8303_115 = $08303115;
  RPRM_DeviceType_8305     = $08305000; // Mobile complex 8305 (Logitech QuickCam Pro web-camera)
  // unused ----------------------------------------------------------------------------------------------

  // enum eRPRM_Lights {
  RPRM_Light_OFF               = $00000000; // Light Off                                                // File names:
  RPRM_Light_OVI               = $00000001; // Light for OVI                                            // OVI
  RPRM_Light_White_Top         = $00000002; // Light White Top                                          // WHITE_TOP
  RPRM_Light_White_Side        = $00000004; // Light White Side                                         // WHITE_SIDE
  RPRM_Light_IR_Top            = $00000008; // Light IR Top                                             // IR_TOP
  RPRM_Light_IR_Side           = $00000010; // Light IR Side                                            // IR_SIDE
  RPRM_Light_Transmitted       = $00000020; // transmitted light                                        // TRANSMITTED
  RPRM_Light_Transmitted_IR    = $00000040; // transmitted IR light                                     // IR_TRANSMITTED
  RPRM_Light_UV                = $00000080; // Light UV                                                 // UV
  RPRM_Light_IR_Luminescence   = $00000100; // Light Green Front                                        // IR_LUM
  RPRM_Light_AXIAL_White_Front = $00000200; // Light Axial (3M) White                                   // AXIAL_WHITE
  RPRM_Light_AXIAL_White_Left  = $00000400; // Light Axial (3M) White Left                              // AXIAL_WHITE_LEFT
  RPRM_Light_AXIAL_White_Right = $00000800; // Light Axial (3M) White Right                             // AXIAL_WHITE_RIGHT
  RPRM_Light_IR_720            = $00001000; // Light IR 720 (mod. 8850)                                 // IR_720
  RPRM_Light_IR_940            = $00002000; // Light IR 940 (mod. 8803, 8850)                           // IR_940
  RPRM_Light_Transmitted_IR940 = $00004000; // Light IR transmitted 940 (mod. 8803, 8850)
  RPRM_Light_IR_700            = $00008000; // Light IR 700 (mod. 8803)
  RPRM_Light_AntiStokes        = $00010000; // Anti Stokes light                                        // AS
  RPRM_Light_OVD_Left          = $00020000; // Light OVD Left
  RPRM_Light_OVD_Right         = $00040000; // Light OVD Right
  RPRM_Light_UVC               = $00080000; // Light UVС 254 (88X0 devices)                             // UV_254
  RPRM_Light_UVB               = $00100000; // Light UVB 313 (88X0 devices)                             // UV_313
  RPRM_Light_White_Obl         = $00200000; // Light oblique white                                      // WHITE_OBL
  RPRM_Light_White_Special     = $00400000; // Light White (special light source)                       // WHITE_SPECIAL
  RPRM_Light_White_Front       = $00800000; // Light White (single light source)                        // WHITE
  RPRM_Light_IR_Front          = $01000000; // Light IR (single light source)                           // IR
  RPRM_Light_White_Gray        = $02000000; // Light GRAY (grayscale made from WHITE)
  RPRM_Light_OVD               = $04000000; // Light OVD (hologram visualization)                       // OVD
  RPRM_Light_Videodetection    = $08000000; // Light Videodetection (for internal use only)
  RPRM_Light_IR_870_Obl        = $10000000; // Light IR 870 oblique                                     // IR_OBL

  RPRM_Light_White_Full        = (RPRM_Light_White_Top or RPRM_Light_White_Side);                       // WHITE
  RPRM_Light_IR_Full           = (RPRM_Light_IR_Top or RPRM_Light_IR_Side);                             // IR
  RPRM_Light_AXIAL_White_Full  = (RPRM_Light_AXIAL_White_Left or RPRM_Light_AXIAL_White_Right);         // AXIAL_WHITE
  RPRM_Light_White_UV          = (RPRM_Light_White_Full or RPRM_Light_UV);                              // WHITE_UV
  // aliases for devices
  RPRM_Light_IR_870            = RPRM_Light_IR_Front; // Light IR 870 (mod. 8803)
  RPRM_Light_Holo              = RPRM_Light_OVD; // Light OVD (hologram visualization) - 8850
  RPRM_Light_White_Full_Holo   = RPRM_Light_White_Full or RPRM_Light_Holo;
  RPRM_Light_IR_Bottom         = RPRM_Light_Transmitted_IR; // Light IR Bottom (mod. 8304)
  RPRM_Light_White_Bottom      = RPRM_Light_Transmitted; // Light White Bottom (mod. 8304)

  RPRM_Light_HR_Light          = $40000000; // [HR]eRPRM_Lights - [this] = eRPRM_Lights
  RPRM_Light_HR_White          = (RPRM_Light_HR_Light or RPRM_Light_White_Full);                        // WHITE.HR
  RPRM_Light_HR_UV             = (RPRM_Light_HR_Light or RPRM_Light_UV);                                // UV.HR
  RPRM_Light_HR_IR             = (RPRM_Light_HR_Light or RPRM_Light_IR_Full);                           // IR.HR

  RPRM_Light_RAW_Data          = $80000000; // RAW data from camera sensor (byte/pixel)
  RPRM_Light_RAW_Data_GRBG     = $90000000; // RAW data from camera sensor (byte/pixel)
  RPRM_Light_RAW_Data_GBRG     = $A0000000; // RAW data from camera sensor (byte/pixel)
  RPRM_Light_RAW_Data_RGGB     = $B0000000; // RAW data from camera sensor (byte/pixel)
  RPRM_Light_RAW_Data_BGGR     = $C0000000; // RAW data from camera sensor (byte/pixel)

  // enum eRPRM_VideoModes {
  RPRM_VM_UNDEFINED = 0;

  RPRM_VM_1MP       = $00000001; // 1280 x 1024 	- OV 1.3
  // 1024 x 768 	- OV 3.0 & Micron 3.1
  RPRM_VM_3MP       = $00000002; // 2048 x 1536	- OV 3.0 & Micron 3.1
  RPRM_VM_5MP       = $00000004; // 2592 x 1944	- Micron 5MP - VM_QSXGA
  RPRM_VM_3MP_MRZ   = $00000010; // 1536 õ 500	- RPRM_DeviceType_FX_8307
  RPRM_VM_9MP_2     = $00000020; // 1744 x 1308	- Micron 9.0
  RPRM_VM_9MP       = $00000040; // 3488 x 2616	- Micron 9.0
  RPRM_VM_5MP_1_3   = $00000080; // 1296 x 972	- skip 2*2 from VM_QSXGA
  RPRM_VM_14MP      = $00000100; // 4384 x 3288  - Micron 14 Mpx video mode
  RPRM_VM_FULL_HD   = $00000200; // 1920 x 1080  - FullHD video mode
  RPRM_VM_10MP      = $00000400; // 3664 x 2748	- Micron 10MP - VM_MP10
  RPRM_VM_10MP_2_5  = $00000800; // 1832 x 1374	- skip 2*2 from VM_MP10 = VM_MP2_5
  RPRM_VM_18MP      = $00001000; // 4896 x 3680 pixels 18 Mp video mode
  RPRM_VM_18MP_SB   = $00002000; // 2448 x 1840 pixels 18 Mp (SB 2X) video mode
  RPRM_VM_18MP_4X   = $00004000; // 1224 x 920 pixels 18 Mp (SB 4X) video mode
  RPRM_VM_13MP      = $00008000; // 4200 x 3120 pixels 13 Mp
  RPRM_VM_13MP_Q    = $00010000; // 2100 x 1560 pixels (1/4 (quarter) of 13 Mp)
  RPRM_VM_13MP_H    = $00020000; // 3360 x 2496 pixels (2/3 (half) of 13 Mp)
  RPRM_VM_20MP      = $00100000; // 5184 x 3888  - Panasonic G9 20Mp default 20MP + RPRM_VM_5MP_1_3
  RPRM_VM_80MP      = $00200000; // 10368x 7776  - Panasonic G9 max 80Mpx 80MP + RPRM_VM_5MP
  RPRM_VM_24MP      = $04000000; // 6000 x 4000  - Canon 80D 24Mpx
  RPRM_VM_24MP_1_5  = $08000000; // 1500 x 1000  - Canon 80D 24Mpx 1.5 MP

  RPRM_VM_50MP      = $01000000; // 8688 x 5792  - Canon EOS 5Ds/5Dsr 50 MP
  RPRM_VM_50MP_3    = $02000000; // 2172 x 1448  - Canon EOS 5Ds/5Dsr 3 MP
  RPRM_VM_ID1xx_600 = $10000000; // 2150 x 1350  - ID1xx card reader 600 DPI mode
  RPRM_VM_300DPI    = $20000000; // 2150 x 1350  - 300 DPI now bound to RPRM_VM_ID1xx_600
  RPRM_VM_5MP_EOS   = $40000000; // 2592 x 1728  - Canon EOS 550D

  RPRM_VM_MAX = RPRM_VM_9MP;

  // enum CDocFormat {
  dfID1 = 0; // Document of ID-1 format
  dfID2 = 1; // Document of ID-2 format
  dfID3 = 2; // Document of ID-3 format - passport
  dfNON = 3; // Document of unknown format
  dfID1_90 = 10;
  dfID1_180 = 11;
  dfID1_270 = 12;
  dfID2_180 = 13;
  dfID3_180 = 14;
  dfID3_x2 = 5; // Open document of ID-3 format - open passport
  dfCustom = 1000;
  dfPhoto = 1001; // photo for document
  dfFlexible = 1002;
  dfUnknown = -1;

  // enum eRPRM_Orientation
  Orientation_0 = 1;
  Orientation_90 = 8;
  Orientation_180 = 2;
  Orientation_270 = 4;
  Orientation_0_180 = Orientation_0 or Orientation_180;
  Orientation_90_270 = Orientation_90 or Orientation_270;
  Orientation_90_180_270 = Orientation_90 or Orientation_180 or Orientation_270;
  Orientation_0_90_180_270 = Orientation_0 or Orientation_90 or Orientation_180 or Orientation_270;

  // enum eRPRM_Capabilities{
  RPRM_Capabilities_Empty                       = $00000000;
  RPRM_Capabilities_Scan                        = $00000001;
  RPRM_Capabilities_SaveFiles                   = $00000002;
  RPRM_Capabilities_LocateDocument              = $00000004;
  RPRM_Capabilities_MRZ_OCR                     = $00000008;
  RPRM_Capabilities_Visual_OCR                  = $00000010;
  RPRM_Capabilities_BarCodes                    = $00000020;
  RPRM_Capabilities_MRZ_TestQuality             = $00000040;
  RPRM_Capabilities_FDS                         = $00000080;
  RPRM_Capabilities_ImageDistortionCompensation = $00000100;
  RPRM_Capabilities_OCR_Analyze                 = $00000200;
  RPRM_Capabilities_Authenticity                = $00000400;

  RPRM_Capabilities_RAW_ImageData               = $00000800;
  RPRM_Capabilities_RAW_CustomDemosaic          = $00001000;

  RPRM_Capabilities_DocumentType                = $00002000;
  RPRM_Capabilities_Visual_Graphics             = $00004000;
  RPRM_Capabilities_Expert_Analyze              = $00008000;
  RPRM_Capabilities_ColorCompensation           = $00010000;
  RPRM_Capabilities_BarcodesExtended            = $00020000;
  RPRM_Capabilities_GlareCompensation           = $00040000;
  RPRM_Capabilities_RFID                        = $00080000;
  RPRM_Capabilities_BankCard                    = $00100000;
  RPRM_Capabilities_LiveFaceComparison          = $00200000;
  RPRM_Capabilities_ServerSideRFID              = $02000000;

  RPRM_Capabilities_ProcessImages               = $10000000;

  RPRM_Capabilities_Custom2                     = $20000000;
  RPRM_Capabilities_Custom3                     = $40000000;
  RPRM_Capabilities_Custom4                     = $80000000;

  // enum eRPRM_GetImage_Modes{

  RPRM_GetImage_Modes_Empty                    = $00000000;
  RPRM_GetImage_Modes_GetUncroppedImages       = $00000001; // to receive unprocessed images
  RPRM_GetImage_Modes_ReceiveAllScannedImages  = $00000002;
  RPRM_GetImage_Modes_GetImages                = $00000008; // no additional actions, to receive preset images
  RPRM_GetImage_Modes_LocateDocument           = $00000010;
  // to locate document page bounds, crop images, correct brightness and color balance
  RPRM_GetImage_Modes_DocumentType             = $00000020; // to try to determine document type
  RPRM_GetImage_Modes_OCR_MRZ                  = $00000040; // to locate MRZ and read it
  RPRM_GetImage_Modes_OCR_Visual_Text          = $00000080; // to read document visual zone text
  RPRM_GetImage_Modes_OCR_Visual_Graphics      = $00000004; // to read graphic fields from document
  RPRM_GetImage_Modes_OCR_Visual               = RPRM_GetImage_Modes_OCR_Visual_Graphics or RPRM_GetImage_Modes_OCR_Visual_Text;
  RPRM_GetImage_Modes_OCR_BarCodes             = $00000100; // to locate and read barcodes
  RPRM_GetImage_Modes_Authenticity             = $00000200;
  RPRM_GetImage_Modes_OCR_TestMRZQuality       = $00000400; // to test MRZ printing quality
  RPRM_GetImage_Modes_RAW_Data                 = $00000800; // Bayer matrix + unprocessed images
  RPRM_GetImage_Modes_RAW_Data_Only            = $00001000; // only Bayer matrix
  RPRM_GetImage_Modes_NoColorCompensation      = $00002000; // correct brightness and color balance
  RPRM_GetImage_Modes_NoDistortionCompensation = $00004000; // correct distortion
  RPRM_GetImage_Modes_DetectDocument           = $00008000;
  RPRM_GetImage_Modes_ImageQA                  = $00010000;
  RPRM_GetImage_Modes_FaceDetect               = $00040000;
  RPRM_GetImage_Modes_CheckVDS                 = $00080000; ///< check VDS, if available

  RPRM_GetImage_Modes_Reserved9 = $00020000;
  RPRM_GetImage_Modes_Reserved11 = $00080000;
  RPRM_GetImage_Modes_Reserved12 = $00100000;
  RPRM_GetImage_Modes_Reserved13 = $00200000;
  RPRM_GetImage_Modes_Reserved14 = $00400000;
  RPRM_GetImage_Modes_Reserved15 = $00800000;
  RPRM_GetImage_Modes_Reserved16 = $01000000;
  RPRM_GetImage_Modes_Reserved17 = $02000000;
  RPRM_GetImage_Modes_Reserved18 = $04000000;
  RPRM_GetImage_Modes_Reserved19 = $08000000;

  RPRM_GetImage_Modes_Custom1 = $10000000;
  RPRM_GetImage_Modes_Custom2 = $20000000;
  RPRM_GetImage_Modes_Custom3 = $40000000;
  RPRM_GetImage_Modes_Custom4 = $80000000;

  // ****************************************************************************
  // ** result types
  // ****************************************************************************

const

  // enum eRPRM_ResultType{
  RPRM_ResultType_Empty = 0;
  RPRM_ResultType_RawImage = 1; // TRawImageContainer
  RPRM_ResultType_FileImage = 2; // byte array
  RPRM_ResultType_MRZ_OCR_Extended = 3; // TDocVisualExtendedInfo
  RPRM_ResultType_BarCodes = 5; // TDocBarCodeInfo
  RPRM_ResultType_Graphics = 6; // TDocGraphicsInfo
  RPRM_ResultType_MRZ_TestQuality = 7; // TDocMRZTestQuality
  RPRM_ResultType_DocumentTypesCandidates = 8; // TCandidatesListContainer
  RPRM_ResultType_ChosenDocumentTypeCandidate = 9; // TOneCandidate
  RPRM_ResultType_DocumentsInfoList = 10; // not used. TListDocsInfo
  RPRM_ResultType_OCRLexicalAnalyze = 15; // TListVerifiedFields
  RPRM_ResultType_RawUncroppedImage = 16; // TRawImageContainer
  RPRM_ResultType_Visual_OCR_Extended = 17; // TDocVisualExtendedInfo
  RPRM_ResultType_BarCodes_TextData = 18; // TDocVisualExtendedInfo
  RPRM_ResultType_BarCodes_ImageData = 19; // TDocGraphicsInfo
  RPRM_ResultType_Authenticity = 20; // TAuthenticityCheckList
  RPRM_ResultType_ExpertAnalyze = 21; // not used
  RPRM_ResultType_OCRLexicalAnalyzeEx = 22; // not used
  RPRM_ResultType_EOSImage = 23; // TRawImageContainer for EOS full-size images
  RPRM_ResultType_BayerImage = 24; // TRawImageContainer
  RPRM_ResultType_MagneticStripe = 25; // byte array
  RPRM_ResultType_MagneticStripe_TextData = 26; // TDocVisualExtendedInfo
  RPRM_ResultType_FieldFileImage = 27; // byte array
  RPRM_ResultType_DatabaseCheck = 28; // TDatabaseCheck
  RPRM_ResultType_FingerprintTemplateISO = 29; // byte array
  RPRM_ResultType_InputImageQuality = 30; // TImageQualityCheckList
  RPRM_ResultType_DeviceInfo = 31; // TRegulaDeviceProperties
  RPRM_ResultType_LivePortrait = 32; // TDocGraphicsInfo
  RPRM_ResultType_Status = 33; // buffer = char* - pointer to status XML or JSON
  RPRM_ResultType_Portrait_Comparison = 34; // TAuthenticityCheckList
  RPRM_ResultType_ExtPortrait = 35; // TDocGraphicsInfo
  RPRM_ResultType_Text = 36; // TTextResult
  RPRM_ResultType_Images = 37; // TImagesResult
  RPRM_ResultType_FingerPrints = 38; // TDocGraphicsInfo
  RPRM_ResultType_FingerPrint_Comparison = 39; // TAuthenticityCheckList
  RPRM_ResultType_FaceDatabaseCheck = 40;           // TDatabaseCheck
  RPRM_ResultType_FingerprintDatabaseCheck = 41;           // TDatabaseCheck
  RPRM_ResultType_BarcodePosition             = 62;           // TBoundsResult;
  RPRM_ResultType_BSI_XML_v2 = 73; // BSI XML v2 result. buffer = char* - pointer to BSI XML v2
  RPRM_ResultType_DocumentPosition = 85; // TBoundsResult
  RPRM_ResultType_BSI_XML = 92; // BSI XML result. buffer = char* - pointer to BSI XML
  RPRM_ResultType_Custom = 100;

  // ****************************************************************************
  // **  result container structure
  // ****************************************************************************
type

  PPResultContainer = ^PResultContainer;
  PResultContainer = ^TResultContainer;

  TResultContainer = record
    result_type: DWORD; // eRPRM_ResultType
    light: DWORD; // eRPRM_Lights
    buf_length: DWORD;
    buffer: PByteArray;
    XML_length: DWORD;
    XML_buffer: PByteArray;
    list_idx: DWORD;
    page_idx: DWORD;
  end;

  PPResultContainerList = ^PResultContainerList;
  PResultContainerList = ^TResultContainerList;

  TResultContainerList = record
    Count: DWORD;
    List: array of TResultContainer;
  end;

  PPResultContainerPointersList = ^PResultContainerPointersList;
  PResultContainerPointersList = ^TResultContainerPointersList;

  TResultContainerPointersList = record
    Count: DWORD;
    List: array of PResultContainer;
  end;

  // ****************************************************************************
  // **  result RPRM_ResultType_RawImage
  // ****************************************************************************
  // 'TResultContainer.buffer' = TRawImageContainer *
type

  PPRawImageContainer = ^PRawImageContainer;
  PRawImageContainer = ^TRawImageContainer;

  TRawImageContainer = record
    bmi: PBitmapInfo; // with valid bmiColors[256]
    bits: PByteArray; // image bits array, DWORD aligned
  end;

  PRawImageContainerList = ^TRawImageContainerList;

  TRawImageContainerList = record
    Count: Integer;
    Images: array of TRawImageContainer;
  end;
  // ****************************************************************************
  // **  result RPRM_ResultType_FileImage
  // ****************************************************************************
  // TResultContainer.buffer points to the whole file image buffer (BYTE *) of length TResultContainer.buf_length

  // ********************************************************************************************************
  // **  result RPRM_ResultType_Visual_OCR and RPRM_ResultType_MRZ_OCR_Parsed
  // ********************************************************************************************************
  // 'TResultContainer.buffer' = TDocVisualInfo *
const
  // enum eVisualFieldType{
  ft_Document_Class_Code = 0;
  ft_Issuing_State_Code = 1;
  ft_Document_Number = 2;
  ft_Date_of_Expiry = 3;
  ft_Date_of_Issue = 4;
  ft_Date_of_Birth = 5;
  ft_Place_of_Birth = 6;
  ft_Personal_Number = 7;
  ft_Surname = 8;
  ft_Given_Names = 9;
  ft_Mothers_Name = 10;
  ft_Nationality = 11;
  ft_Sex = 12;
  ft_Height = 13;
  ft_Weight = 14;
  ft_Eyes_Color = 15;
  ft_Hair_Color = 16;
  ft_Address = 17;
  ft_Donor = 18;
  ft_Social_Security_Number = 19;
  ft_DL_Class = 20;
  ft_DL_Endorsed = 21;
  ft_DL_Restriction_Code = 22;
  ft_DL_Under_21_Date = 23;
  ft_Authority = 24;
  ft_Surname_And_Given_Names = 25;
  ft_Nationality_Code = 26;

  // --- VISA Field Types (added 01.05.2005) ----------
  ft_Passport_Number = 27;
  ft_Invitation_Number = 28;
  ft_Visa_ID = 29;
  ft_Visa_Class = 30;
  ft_Visa_SubClass = 31;

  ft_MRZ_String1 = 32;
  ft_MRZ_String2 = 33;
  ft_MRZ_String3 = 34;
  ft_MRZ_Type = 35;
  ft_Optional_Data = 36;
  ft_Document_Class_Name = 37;
  ft_Issuing_State_Name = 38;
  ft_Place_of_Issue = 39;

  ft_Document_Number_Checksum = 40;
  ft_Date_of_Birth_Checksum = 41;
  ft_Date_of_Expiry_Checksum = 42;
  ft_Personal_Number_Checksum = 43;
  ft_FinalChecksum = 44;

  // --- VISA Field Types (added 01.05.2005) ----------
  ft_Passport_Number_Checksum = 45;
  ft_Invitation_Number_Checksum = 46;
  ft_Visa_ID_Checksum = 47;
  ft_Surname_And_Given_Names_Checksum = 48;
  ft_Visa_Valid_Until_Checksum = 49;

  ft_Other = 50;

  ft_MRZ_Strings = 51;

  // ------- Add 27.02.2006 for BARCODES ------------
  ft_Name_Suffix = 52;
  ft_Name_Prefix = 53;

  ft_Date_of_Issue_Checksum = 54;
  ft_Date_of_Issue_CheckDigit = 55;

  // ------- Add 05.03.2007  ------------------------
  ft_Document_Series = 56;

  ft_RegCert_RegNumber = 57;
  ft_RegCert_CarModel = 58;
  ft_RegCert_CarColor = 59;
  ft_RegCert_BodyNumber = 60;
  ft_RegCert_CarType = 61;
  ft_RegCert_MaxWeight = 62;
  ft_RegCert_Weight = 63;

  ft_Address_Area = 64;
  ft_Address_State = 65;
  ft_Address_Building = 66;
  ft_Address_House = 67;
  ft_Address_Flat = 68;

  ft_Place_of_Registration = 69;
  ft_Date_of_Registration = 70;
  ft_Resident_From = 71;
  ft_Resident_Until = 72;
  ft_Authority_Code = 73;
  ft_Place_of_Birth_Area = 74;
  ft_Place_of_Birth_StateCode = 75;

  ft_Address_Street = 76; // Street portion of the cardholder address.
  ft_Address_City = 77; // City portion of the cardholder address.
  ft_Address_Jurisdiction_Code = 78; // Jurisdiction Code - State portion of the cardholder address.
  ft_Address_Postal_Code = 79; // Postal code portion of the cardholder address in the U.S. and Canada.

  // MRZ recognized checkdigits
  ft_Document_Number_CheckDigit = 80;
  ft_Date_of_Birth_CheckDigit = 81;
  ft_Date_of_Expiry_CheckDigit = 82;
  ft_Personal_Number_CheckDigit = 83;
  ft_FinalCheckDigit = 84;
  ft_Passport_Number_CheckDigit = 85;
  ft_Invitation_Number_CheckDigit = 86;
  ft_Visa_ID_CheckDigit = 87;
  ft_Surname_And_Given_Names_CheckDigit = 88;
  ft_Visa_Valid_Until_CheckDigit = 89;

  ft_Permit_DL_Class = 90;
  ft_Permit_Date_of_Expiry = 91;
  ft_Permit_Identifier = 92;
  ft_Permit_Date_of_Issue = 93;
  ft_Permit_Restriction_Code = 94;
  ft_Permit_Endorsed = 95;

  ft_Issue_Timestamp = 96; // A string used by some jurisdictions to validate the document against their database.
  ft_Number_of_Duplicates = 97;
  ft_Medical_Indicator_Codes = 98;
  ft_Non_Resident_Indicator = 99; // Used by some jurisdictions

  // ------- Added 04.05.2005 for VISA ------------
  ft_Visa_Type = 100;
  ft_Visa_Valid_From = 101;
  ft_Visa_Valid_Until = 102;
  ft_Duration_of_Stay = 103;
  ft_Number_of_Entries = 104;

  // ------- Add 07.06.2005 for SUBFIELDS ------------
  ft_Day = 105;
  ft_Month = 106;
  ft_Year = 107;

  // to indicate holder of the
  // document is a non-resident.
  ft_Unique_Customer_Identifier = 108;
  // A number or alphanumeric string used by some jurisdictions to identify a "customer" across multiple data bases.
  ft_Commercial_Vehicle_Codes = 109; // Federal Commercial Vehicle Codes
  // Federally established codes for vehicle
  // categories, endorsements, and restrictions that
  // are generally applicable to commercial motor
  // vehicles. If the vehicle is not a commercial
  // vehicle, "NONE" is to be entered.
  // AKA (also known as)
  ft_AKA_Date_of_Birth = 110;
  ft_AKA_Social_Security_Number = 111;
  ft_AKA_Surname = 112;
  ft_AKA_Given_Names = 113;
  ft_AKA_Name_Suffix = 114;
  ft_AKA_Name_Prefix = 115;

  ft_Mailing_Address_Street = 116; // (Mailing Street Address)
  ft_Mailing_Address_City = 117; // (Mailing City Address)
  ft_Mailing_Address_Jurisdiction_Code = 118; // (Mailing Jurisdiction Code - State portion of the cardholder address)
  ft_Mailing_Address_Postal_Code = 119; // (Mailing Postal code portion of the cardholder address)
  ft_Audit_Information = 120; // (Audit information)
  ft_Inventory_Number = 121; // (Inventory control number)
  ft_Race_Ethnicity = 122; // (Race/ethnicity)
  ft_Jurisdiction_Vehicle_Class = 123; // (Jurisdiction Vehicle Class)
  ft_Jurisdiction_Endorsement_Code = 124; // (Jurisdiction Endorsement Code)
  ft_Jurisdiction_Restriction_Code = 125; // (Jurisdiction Restriction Code)

  ft_Family_Name = 126; // фамилия владельца документа (русская транскрипция)
  ft_Given_Names_RUS = 127; // имя владельца документа (русская транскрипция)
  ft_Visa_ID_RUS = 128; // идентификационный номер визы (русская транскрипция из рус. визы)
  ft_Fathers_Name = 129; // Отчество владельца документа
  ft_Fathers_Name_RUS = 130; // Отчество владельца документа (русская транскрипция)
  ft_Surname_And_Given_Names_RUS = 131; // ФИО (Фамилия отделена от Имени пробелом)
  ft_Place_Of_Birth_RUS = 132;
  ft_Authority_RUS = 133;
  ft_Issuing_State_Code_Numeric = 134;
  // код государства выдачи документа (three-digit country code defined in ISO 3166-1)
  ft_Nationality_Code_Numeric = 135; // код национальности

  ft_Engine_Power = 136;
  ft_Engine_Volume = 137;
  ft_Chassis_Number = 138;
  ft_Engine_Number = 139;
  ft_Engine_Model = 140;
  ft_Vehicle_Category = 141;

  ft_Identity_Card_Number = 142;
  ft_Control_No = 143;

  ft_Parrent_s_Given_Names = 144; // Имена Родителей владельца документа
  ft_Second_Surname = 145; // Вторая фамилия ВД
  ft_Middle_Name = 146;

  // add 25/08/2010 for Poland Registration Certificate (Vehicle)
  ft_RegCert_VIN = 147; // Vehicle Identification Number
  ft_RegCert_VIN_CheckDigit = 148; // VIN Check Digit
  ft_RegCert_VIN_Checksum = 149; // VIN CheckSum Check Result
  ft_Line1_CheckDigit = 150; // Line 1 Check Digit
  ft_Line2_CheckDigit = 151; // Line 2 Check Digit
  ft_Line3_CheckDigit = 152; // Line 3 Check Digit
  ft_Line1_Checksum = 153; // Line 1 CheckSum Check Result
  ft_Line2_Checksum = 154; // Line 2 CheckSum Check Result
  ft_Line3_Checksum = 155; // Line 3 CheckSum Check Result
  ft_RegCert_RegNumber_CheckDigit = 156; // Registration number (License plates) Check Digit
  ft_RegCert_RegNumber_Checksum = 157; // Registration number (License plates) CheckSum Check Result
  ft_RegCert_Vehicle_ITS_Code = 158; // Vehicle ITS code (from the catalog of the Motor Transport Institute).

  ft_Card_Access_Number = 159; // Card Access Number.
  ft_Marital_Status = 160;
  ft_Company_Name = 161;

  ft_Special_Notes = 162;
  ft_Surname_of_Spose = 163;
  ft_Tracking_Number = 164;
  ft_Booklet_Number = 165;
  ft_Children = 166;
  ft_Copy = 167;
  ft_Serial_Number = 168;
  ft_Dossier_Number = 169;
  ft_AKA_Surname_And_Given_Names = 170;
  ft_Territorial_Validity = 171;

  ft_MRZ_Strings_With_Correct_CheckSums = 172;

  ft_DL_CDL_Restriction_Code = 173;
  ft_DL_Under_18_Date = 174;
  ft_DL_Record_Created = 175;
  ft_DL_Duplicate_Date = 176;
  ft_DL_Iss_Type = 177;

  ft_Military_Book_Number = 178;
  ft_Destination = 179;
  ft_Blood_Group = 180;
  ft_Sequence_Number = 181;
  ft_RegCert_BodyType = 182;
  ft_RegCert_CarMark = 183;
  ft_Transaction_Number = 184;
  ft_Age = 185;
  ft_Folio_Number = 186;
  ft_Voter_Key = 187;
  ft_Address_Municipality = 188;
  ft_Address_Location = 189;
  ft_Section = 190;
  ft_OCR_Number = 191;
  ft_Federal_Elections = 192;
  ft_Reference_Number = 193;
  ft_Optional_Data_Checksum = 194; // for Russian National Passport
  ft_Optional_Data_CheckDigit = 195; // for Russian National Passport
  ft_Visa_Number = 196; // for Visas
  ft_Visa_Number_Checksum = 197; // for Visas
  ft_Visa_Number_CheckDigit = 198; // for Visas
  ft_Voter = 199;
  ft_Previous_Type = 200;

  ft_FieldFromMRZ = 220; // Зарезервирована для внутреннего использования
  ft_CurrentDate = 221;

  ft_Status_Date_of_Expiry = 251;
  ft_Banknote_Number = 252;
  ft_CSC_Code = 253;
  ft_Artistic_Name = 254;
  ft_Academic_Title = 255;
  ft_Address_Country = 256;
  ft_Address_Zipcode = 257;
  ft_eID_Residence_Permit1 = 258;
  ft_eID_Residence_Permit2 = 259;
  ft_eID_PlaceOfBirth_Street = 260;
  ft_eID_PlaceOfBirth_City = 261;
  ft_eID_PlaceOfBirth_State = 262;
  ft_eID_PlaceOfBirth_Country = 263;
  ft_eID_PlaceOfBirth_Zipcode = 264;
  ft_CDL_Class = 265;
  ft_DL_Under_19_Date = 266;
  ft_Weight_pounds = 267;
  ft_Limited_Duration_Document_Indicator = 268;
  ft_Endorsement_Expiration_Date = 269;
  ft_Revision_Date = 270;
  ft_Compliance_Type = 271;
  ft_Family_name_truncation = 272;
  ft_First_name_truncation = 273;
  ft_Middle_name_truncation = 274;
  ft_Exam_Date = 275;
  ft_Organization = 276;
  ft_Department = 277;
  ft_Pay_Grade = 278;
  ft_Rank = 279;
  ft_Benefits_Number = 280;
  ft_Sponsor_Service = 281;
  ft_Sponsor_Status = 282;
  ft_Sponsor = 283;
  ft_Relationship = 284;
  ft_USCIS = 285;
  ft_Category = 286;
  ft_Conditions = 287;
  ft_Identifier = 288;
  ft_Configuration = 289;
  ft_Discretionary_data = 290;
  ft_Line1_Optional_Data = 291;
  ft_Line2_Optional_Data = 292;
  ft_Line3_Optional_Data = 293;
  ft_EQV_Code = 294;
  ft_ALT_Code = 295;
  ft_Binary_Code = 296;
  ft_Pseudo_Code = 297;
  ft_Fee = 298;
  ft_Stamp_Number = 299;
  ft_GNIB_Number = 340;
  ft_Dept_Number = 341;
  ft_Telex_Code = 342;
  ft_Allergies = 343;
  ft_Sp_Code = 344;
  ft_Court_Code = 345;
  ft_Cty = 346;
  ft_Sponsor_SSN = 347;
  ft_DoD_Number = 348;
  ft_MC_Novice_Date = 349;
  ft_DUF_Number = 350;
  ft_AGY = 351;
  ft_PNR_Code = 352;
  ft_From_Airport_Code = 353;
  ft_To_Airport_Code = 354;
  ft_Flight_Number = 355;
  ft_Date_of_Flight = 356;
  ft_Seat_Number = 357;
  ft_Date_of_Issue_Boarding_Pass = 358;
  ft_CCW_Until = 359;
  ft_Reference_Number_Checksum = 360;
  ft_Reference_Number_CheckDigit = 361;
  ft_Room_Number = 362;
  ft_Religion = 363;
  ft_RemainderTerm = 364;
  ft_Electronic_Ticket_Indicator = 365;
  ft_Compartment_Code = 366;
  ft_CheckIn_Sequence_Number = 367;
  ft_Airline_Designator_of_boarding_pass_issuer = 368;
  ft_Airline_Numeric_Code = 369;
  ft_Ticket_Number = 370;
  ft_Frequent_Flyer_Airline_Designator = 371;
  ft_Frequent_Flyer_Number = 372;
  ft_Free_Baggage_Allowance = 373;
  ft_PDF417Codec = 374;
  ft_Identity_Card_Number_Checksum = 375; // for Spain Residence permit (1997-2010) Side B
  ft_Identity_Card_Number_CheckDigit = 376; // for Spain Residence permit (1997-2010) Side B
  ft_Veteran = 377; // Veteran indicator - for USA DL
  ft_DLClassCode_A1_From = 378;
  ft_DLClassCode_A1_To = 379;
  ft_DLClassCode_A1_Notes = 380;
  ft_DLClassCode_A_From = 381;
  ft_DLClassCode_A_To = 382;
  ft_DLClassCode_A_Notes = 383;
  ft_DLClassCode_B_From = 384;
  ft_DLClassCode_B_To = 385;
  ft_DLClassCode_B_Notes = 386;
  ft_DLClassCode_C1_From = 387;
  ft_DLClassCode_C1_To = 388;
  ft_DLClassCode_C1_Notes = 389;
  ft_DLClassCode_C_From = 390;
  ft_DLClassCode_C_To = 391;
  ft_DLClassCode_C_Notes = 392;
  ft_DLClassCode_D1_From = 393;
  ft_DLClassCode_D1_To = 394;
  ft_DLClassCode_D1_Notes = 395;
  ft_DLClassCode_D_From = 396;
  ft_DLClassCode_D_To = 397;
  ft_DLClassCode_D_Notes = 398;
  ft_DLClassCode_BE_From = 399;
  ft_DLClassCode_BE_To = 400;
  ft_DLClassCode_BE_Notes = 401;
  ft_DLClassCode_C1E_From = 402;
  ft_DLClassCode_C1E_To = 403;
  ft_DLClassCode_C1E_Notes = 404;
  ft_DLClassCode_CE_From = 405;
  ft_DLClassCode_CE_To = 406;
  ft_DLClassCode_CE_Notes = 407;
  ft_DLClassCode_D1E_From = 408;
  ft_DLClassCode_D1E_To = 409;
  ft_DLClassCode_D1E_Notes = 410;
  ft_DLClassCode_DE_From = 411;
  ft_DLClassCode_DE_To = 412;
  ft_DLClassCode_DE_Notes = 413;
  ft_DLClassCode_M_From = 414;
  ft_DLClassCode_M_To = 415;
  ft_DLClassCode_M_Notes = 416;
  ft_DLClassCode_L_From = 417;
  ft_DLClassCode_L_To = 418;
  ft_DLClassCode_L_Notes = 419;
  ft_DLClassCode_T_From = 420;
  ft_DLClassCode_T_To = 421;
  ft_DLClassCode_T_Notes = 422;
  ft_DLClassCode_AM_From = 423;
  ft_DLClassCode_AM_To = 424;
  ft_DLClassCode_AM_Notes = 425;
  ft_DLClassCode_A2_From = 426;
  ft_DLClassCode_A2_To = 427;
  ft_DLClassCode_A2_Notes = 428;
  ft_DLClassCode_B1_From = 429;
  ft_DLClassCode_B1_To = 430;
  ft_DLClassCode_B1_Notes = 431;
  ft_Surname_at_Birth = 432;
  ft_Civil_Status = 433;
  ft_Number_of_Seats = 434;
  ft_Number_of_Standing_Places = 435;
  ft_Max_Speed = 436;
  ft_Fuel_Type = 437;
  ft_EC_Environmental_Type = 438;
  ft_Power_Weight_Ratio = 439;
  ft_Max_Mass_of_Trailer_Braked = 440;
  ft_Max_Mass_of_Trailer_Unbraked = 441;
  ft_Transmission_Type = 442;
  ft_Trailer_Hitch = 443;
  ft_Accompanied_by = 444;
  ft_Police_District = 445;
  ft_First_Issue_Date = 446;
  ft_Payload_Capacity = 447;
  ft_Number_of_Axels = 448;
  ft_Permissible_Axle_Load = 449;
  ft_Precinct = 450;
  ft_Invited_by = 451;
  ft_Purpose_of_Entry = 452;
  ft_Skin_Color = 453;
  ft_Complexion = 454;
  ft_Airport_From = 455;
  ft_Airport_To = 456;
  ft_Airline_Name = 457;
  ft_Airline_Name_Frequent_Flyer = 458;
  ft_License_Number = 459;
  ft_In_Tanks = 460;
  ft_Exept_In_Tanks = 461;
  ft_Fast_Track = 462;
  ft_Owner = 463;
  ft_MRZ_Strings_ICAO_RFID = 464;
  ft_Number_of_Card_Issuance = 465;
  // the number of times a card with this number has been issued
  ft_Number_of_Card_Issuance_Checksum = 466;
  ft_Number_of_Card_Issuance_CheckDigit = 467;
  ft_Century_Date_of_Birth = 468;
  ft_DLClassCode_A3_From = 469;
  ft_DLClassCode_A3_To = 470;
  ft_DLClassCode_A3_Notes = 471;
  ft_DLClassCode_C2_From = 472;
  ft_DLClassCode_C2_To = 473;
  ft_DLClassCode_C2_Notes = 474;
  ft_DLClassCode_B2_From = 475;
  ft_DLClassCode_B2_To = 476;
  ft_DLClassCode_B2_Notes = 477;
  ft_DLClassCode_D2_From = 478;
  ft_DLClassCode_D2_To = 479;
  ft_DLClassCode_D2_Notes = 480;
  ft_DLClassCode_B2E_From = 481;
  ft_DLClassCode_B2E_To = 482;
  ft_DLClassCode_B2E_Notes = 483;
  ft_DLClassCode_G_From = 484;
  ft_DLClassCode_G_To = 485;
  ft_DLClassCode_G_Notes = 486;
  ft_DLClassCode_J_From = 487;
  ft_DLClassCode_J_To = 488;
  ft_DLClassCode_J_Notes = 489;
  ft_DLClassCode_LC_From = 490;
  ft_DLClassCode_LC_To = 491;
  ft_DLClassCode_LC_Notes = 492;
  ft_BankCardNumber = 493;
  ft_BankCardValidThru = 494;
  ft_TaxNumber = 495;
  ft_HealthNumber = 496;
  ft_GrandfatherName = 497;
  ft_Selectee_Indicator = 498;
  ft_Mother_Surname = 499;
  ft_Mother_GivenName = 500;
  ft_Father_Surname = 501;
  ft_Father_GivenName = 502;
  ft_Mother_DateOfBirth = 503;
  ft_Father_DateOfBirth = 504;
  ft_Mother_PersonalNumber = 505;
  ft_Father_PersonalNumber = 506;
  ft_Mother_PlaceOfBirth = 507;
  ft_Father_PlaceOfBirth = 508;
  ft_Mother_CountryOfBirth = 509;
  ft_Father_CountryOfBirth = 510;
  ft_Date_First_Renewal = 511;
  ft_Date_Second_Renewal = 512;
  ft_PlaceOfExamination = 513;
  ft_ApplicationNumber = 514;
  ft_VoucherNumber = 515;
  ft_AuthorizationNumber = 516;
  ft_Faculty = 517;
  ft_FormOfEducation = 518;
  ft_DNINumber = 519;
  ft_RetirementNumber = 520;
  ft_ProfessionalIdNumber = 521;
  ft_Age_at_Issue = 522;
  ft_Years_Since_Issue = 523;
  ft_DLClassCode_BTP_From = 524;
  ft_DLClassCode_BTP_Notes = 525;
  ft_DLClassCode_BTP_To = 526;
  ft_DLClassCode_C3_From = 527;
  ft_DLClassCode_C3_Notes = 528;
  ft_DLClassCode_C3_To = 529;
  ft_DLClassCode_E_From = 530;
  ft_DLClassCode_E_Notes = 531;
  ft_DLClassCode_E_To = 532;
  ft_DLClassCode_F_From = 533;
  ft_DLClassCode_F_Notes = 534;
  ft_DLClassCode_F_To = 535;
  ft_DLClassCode_FA_From = 536;
  ft_DLClassCode_FA_Notes = 537;
  ft_DLClassCode_FA_To = 538;
  ft_DLClassCode_FA1_From = 539;
  ft_DLClassCode_FA1_Notes = 540;
  ft_DLClassCode_FA1_To = 541;
  ft_DLClassCode_FB_From = 542;
  ft_DLClassCode_FB_Notes = 543;
  ft_DLClassCode_FB_To = 544;
  ft_DLClassCode_G1_From = 545;
  ft_DLClassCode_G1_Notes = 546;
  ft_DLClassCode_G1_To = 547;
  ft_DLClassCode_H_From = 548;
  ft_DLClassCode_H_Notes = 549;
  ft_DLClassCode_H_To = 550;
  ft_DLClassCode_I_From = 551;
  ft_DLClassCode_I_Notes = 552;
  ft_DLClassCode_I_To = 553;
  ft_DLClassCode_K_From = 554;
  ft_DLClassCode_K_Notes = 555;
  ft_DLClassCode_K_To = 556;
  ft_DLClassCode_LK_From = 557;
  ft_DLClassCode_LK_Notes = 558;
  ft_DLClassCode_LK_To = 559;
  ft_DLClassCode_N_From = 560;
  ft_DLClassCode_N_Notes = 561;
  ft_DLClassCode_N_To = 562;
  ft_DLClassCode_S_From = 563;
  ft_DLClassCode_S_Notes = 564;
  ft_DLClassCode_S_To = 565;
  ft_DLClassCode_TB_From = 566;
  ft_DLClassCode_TB_Notes = 567;
  ft_DLClassCode_TB_To = 568;
  ft_DLClassCode_TM_From = 569;
  ft_DLClassCode_TM_Notes = 570;
  ft_DLClassCode_TM_To = 571;
  ft_DLClassCode_TR_From = 572;
  ft_DLClassCode_TR_Notes = 573;
  ft_DLClassCode_TR_To = 574;
  ft_DLClassCode_TV_From = 575;
  ft_DLClassCode_TV_Notes = 576;
  ft_DLClassCode_TV_To = 577;
  ft_DLClassCode_V_From = 578;
  ft_DLClassCode_V_Notes = 579;
  ft_DLClassCode_V_To = 580;
  ft_DLClassCode_W_From = 581;
  ft_DLClassCode_W_Notes = 582;
  ft_DLClassCode_W_To = 583;
  ft_URL = 584;
  ft_Caliber = 585;
  ft_Model = 586;
  ft_Make = 587;
  ft_NumberOfCylinders = 588;
  ft_SurnameOfHusbandAfterRegistration = 589;
  ft_SurnameOfWifeAfterRegistration = 590;
  ft_DateOfBirthOfWife = 591;
  ft_DateOfBirthOfHusband = 592;
  ft_CitizenshipOfFirstPerson = 593;
  ft_CitizenshipOfSecondPerson = 594;
  ft_CVV = 595;
  ft_Date_of_Insurance_Expiry = 596;
  ft_Mortgage_by = 597;
  ft_Old_Document_Number = 598;
  ft_Old_Date_of_Issue = 599;
  ft_Old_Place_of_Issue = 600;
  ft_DLClassCode_LR_From = 601;
  ft_DLClassCode_LR_To = 602;
  ft_DLClassCode_LR_Notes = 603;
  ft_DLClassCode_MR_From = 604;
  ft_DLClassCode_MR_To = 605;
  ft_DLClassCode_MR_Notes = 606;
  ft_DLClassCode_HR_From = 607;
  ft_DLClassCode_HR_To = 608;
  ft_DLClassCode_HR_Notes = 609;
  ft_DLClassCode_HC_From = 610;
  ft_DLClassCode_HC_To = 611;
  ft_DLClassCode_HC_Notes = 612;
  ft_DLClassCode_MC_From = 613;
  ft_DLClassCode_MC_To = 614;
  ft_DLClassCode_MC_Notes = 615;
  ft_DLClassCode_RE_From = 616;
  ft_DLClassCode_RE_To = 617;
  ft_DLClassCode_RE_Notes = 618;
  ft_DLClassCode_R_From = 619;
  ft_DLClassCode_R_To = 620;
  ft_DLClassCode_R_Notes = 621;
  ft_DLClassCode_CA_From = 622;
  ft_DLClassCode_CA_To = 623;
  ft_DLClassCode_CA_Notes = 624;
  ft_Citizenship_Status = 625;
  ft_Military_Service_From = 626;
  ft_Military_Service_To = 627;
  ft_DLClassCode_NT_From = 628;
  ft_DLClassCode_NT_To = 629;
  ft_DLClassCode_NT_Notes = 630;
  ft_DLClassCode_TN_From = 631;
  ft_DLClassCode_TN_To = 632;
  ft_DLClassCode_TN_Notes = 633;
  ft_DLClassCode_D3_From = 634;
  ft_DLClassCode_D3_To = 635;
  ft_DLClassCode_D3_Notes = 636;
  ft_Alt_Date_Of_Expiry = 637;
  ft_DLClassCode_CD_From = 638;
  ft_DLClassCode_CD_To = 639;
  ft_DLClassCode_CD_Notes = 640;
  ft_Issuer_Identification_Number = 641;
  ft_Payment_Period_From = 642;
  ft_Payment_Period_To = 643;
  ft_VaccinationCertificateIdentifier = 644;
  ft_First_Name = 645;
  ft_Date_of_Arrival = 646;
  ft_Second_Name = 647;
  ft_Third_Name = 648;
  ft_Fourth_Name = 649;
  ft_Last_Name = 650;
  ft_DLClassCode_RM_From = 651;
  ft_DLClassCode_RM_Notes = 652;
  ft_DLClassCode_RM_To = 653;
  ft_DLClassCode_PW_From = 654;
  ft_DLClassCode_PW_Notes = 655;
  ft_DLClassCode_PW_To = 656;
  ft_DLClassCode_EB_From = 657;
  ft_DLClassCode_EB_Notes = 658;
  ft_DLClassCode_EB_To = 659;
  ft_DLClassCode_EC_From = 660;
  ft_DLClassCode_EC_Notes = 661;
  ft_DLClassCode_EC_To = 662;
  ft_DLClassCode_EC1_From = 663;
  ft_DLClassCode_EC1_Notes = 664;
  ft_DLClassCode_EC1_To = 665;
  ft_Place_of_Birth_City = 666;
  ft_Year_of_Birth = 667;
  ft_Year_of_Expiry = 668;
  ft_GrandfatherName_Maternal = 669;
  ft_First_Surname = 670;
  ft_Month_of_Birth = 671;
  ft_Address_Floor_Number = 672;
  ft_Address_Entrance = 673;
  ft_Address_Block_Number = 674;
  ft_Address_Street_Number = 675;
  ft_Address_Street_Type = 676;
  ft_Address_City_Sector = 677;
  ft_Address_County_Type = 678;
  ft_Address_City_Type = 679;
  ft_Address_Building_Type = 680;
  ft_Date_of_Retirement = 681;
  ft_Document_Status = 682;
  ft_Signature = 683;
  ft_UniqueCertificateIdentifier = 684;
  ft_Email = 685;
  ft_Date_of_SpecimenCollection = 686;
  ft_TypeOfTesting = 687;
  ft_ResultOfTesting = 688;
  ft_MethodOfTesting = 689;
  ft_Digital_Travel_Authorization_Number = 690;
  ft_Date_of_First_Positive_Test_Result = 691;
  ft_EF_CardAccess = 692;
type

  PSymbolCandidate = ^TSymbolCandidate;

  TSymbolCandidate = record
    SymbolCode: DWORD; // symbol's ASCII code
    SymbolProbability: DWORD; // confidence level (0-100%)
    RSubClass: WORD;
    RClass: WORD;
  end;

  // single character recognition result
  PSymbolResult = ^TSymbolResult;

  TSymbolResult = record
    SymbolRect: TRect; // symbol's bounds
    CandidatesCount: DWORD; // number of valid candidates in ListOfCandidates
    ListOfCandidates: array [0 .. 3] of TSymbolCandidate; // list of candidates    // reserved: DWORD; - заменяем на:
    CodeSymbolMask: WORD; // сюда буду записывать код символа - маски (C,D,s) по результату геометрической оценки
    PosSymbolInMRZ: WORD; // позиция символа в МРЗ: №строки * 100 + №символа (Индексация начиная с 1!)
  end;

  // single string recognition result
  PStringResultSDK = ^TStringResultSDK;

  TStringResultSDK = record
    SymbolsCount: DWORD; // number of characters
    reserved: DWORD;
    StringResult: array of TSymbolResult;
    // array of character recognition results
  end;

  PPDocVisualExtendedField = ^PDocVisualExtendedField;
  PDocVisualExtendedField = ^TDocVisualExtendedField;

  TDocVisualExtendedField = record
    FieldType: WORD; // eVisualFieldType
    LCID: WORD; //
    FieldRect: TRect; // field area coordinates
    // RFID_OriginDG,                                                 //or additional RFID information
    // RFID_OriginDGTag,
    // RFID_OriginTagEntry,
    // RFID_OriginEntryView: LongInt;
    FieldName: TArrayOfChar; // Field Name
    StringsCount: Integer; // number of strings
    StringsResult: array of TStringResultSDK;
    // array of string recognition results
    buf_length: Integer;
    Buf_Text: PAnsiChar; // text buffer, '^' - lines separator
    FieldMask: PAnsiChar; // Field Mask
    Validity: Integer;
    InComparison: Integer;
    Reserved1: DWORD;     // field number
    Reserved2: DWORD;
  end;

  PPDocVisualExtendedInfo = ^PDocVisualExtendedInfo;
  PDocVisualExtendedInfo = ^TDocVisualExtendedInfo;

  TDocVisualExtendedInfo = record
    nFields: DWORD;
    pArrayFields: array of TDocVisualExtendedField;
  end;

  // ****************************************************************************
  // **  result RPRM_ResultType_Graphics
  // ****************************************************************************
  // 'TResultContainer.buffer' = TDocGraphicsInfo *

const
  // enum eGraphicFieldType{
  gf_Portrait = 201;
  gf_Fingerprint = 202;
  gf_Eye = 203;
  gf_Signature = 204;
  gf_BarCode = 205;
  gf_Proof_Of_Citizenship = 206;
  gf_Document_Front = 207;
  gf_Document_Rear = 208;
  gf_ColorDynamic = 209;
  gf_GhostPortrait = 210;
  gf_Stamp = 211;
  gf_Portrait_Of_Child = 212;
  gf_ContactChip = 213;
  gf_Sticker = 214;
  gf_Other = 250;

  gf_Finger_LeftThumb = 300;
  gf_Finger_LeftIndex = 301;
  gf_Finger_LeftMiddle = 302;
  gf_Finger_LeftRing = 303;
  gf_Finger_LeftLittle = 304;
  gf_Finger_RightThumb = 305;
  gf_Finger_RightIndex = 306;
  gf_Finger_RightMiddle = 307;
  gf_Finger_RightRing = 308;
  gf_Finger_RightLittle = 309;

  gf_Finger_Right4Fingers = 313;
  gf_Finger_Left4Fingers  = 314;
  gf_Finger_2Thumbs       = 315;

  ID1_MRZ_WIDTH = 77.7;
  ID2_MRZ_WIDTH = 93.3;
  ID3_MRZ_WIDTH = 114.0;



type

  // one field
  PDocGraphicField = ^TDocGraphicField;

  TDocGraphicField = record
    FieldType: Integer; // eGraphicFieldType
    FieldRect: TRect; // field area coordinates
    // RFID_OriginDG,                                                 //or additional RFID information
    // RFID_OriginDGTag,
    // RFID_OriginTagEntry,
    // RFID_OriginEntryView: LongInt;
    FieldName: TArrayOfChar; // Field Name
    image: TRawImageContainer;
  end;

  PDocGraphicsInfo = ^TDocGraphicsInfo;

  TDocGraphicsInfo = record
    nFields: DWORD;
    pArrayFields: array of TDocGraphicField;
  end;

  // ****************************************************************************
  // ****************************************************************************
  // 'TResultContainer.buffer' = TDocBinaryInfo *
  // actual meaning of Buffer depends on FieldType

type

  PBinaryData = ^TBinaryData;

  TBinaryData = record
    FieldType: Integer; // eGraphicFieldType, eVisualFieldType in context
    FieldName: TArrayOfChar; // Field Name
    buf_length: Integer;
    buffer: PByteArray;
  end;

  PDocBinaryInfo = ^TDocBinaryInfo;

  TDocBinaryInfo = record
    nFields: DWORD;
    pArrayFields: array of TBinaryData;
  end;

  // ****************************************************************************
  // **  result RPRM_ResultType_BarCodes
  // ****************************************************************************
  // 'TResultContainer.buffer' = TDocBarCodeInfo *

const
  // enum eBarCodeType {
  bct_Unknown = 0;
  bct_Code128 = 1;
  bct_Code39 = 2;
  bct_EAN8 = 3;
  bct_ITF = 4;
  bct_PDF417 = 5;
  bct_STF = 6;
  bct_MTF = 7;
  bct_IATA = 8;
  bct_CODABAR = 9;
  bct_UPCA = 10;
  bct_CODE93 = 11;
  bct_UPCE = 12;
  bct_EAN13 = 13;
  bct_QRCODE = 14;
  bct_AZTEC = 15;
  bct_DATAMATRIX = 16;
  bct_ALL_1D     = 17;
  bct_CODE11     = 18;
  bct_JABCODE = 19;

  // enum eBarCodeResultCodes {
  bcrc_NoErr = 0;
  bcrc_NullPtrErr = -6001;
  bcrc_BadArgErr = -6002;
  bcrc_SizeErr = -6003;
  bcrc_RangeErr = -6004;
  bcrc_InternalErr = -6005;
  bcrc_TryExceptErr = -6006;
  bcrc_BarCodeNotFound = -6008;
  bcrc_BarCodeDecodeErr = -6010;
  bcrc_NoUserDLLFound = -6019;
  bcrc_NoIPPDLLFound = -6020;
  bcrc_IppExecErr = -6024;
  bcrc_IppTryExceptErr = -6025;
  bcrc_BARCODE_ERROR_Inputparam = -11001;
  bcrc_BARCODE_ERROR_FInit = -11006;
  bcrc_BARCODE_ERROR_NotLoadIpDecodedll = -11012;
  bcrc_BARCODE_ERROR_InnerProblem = -11100;
  bcrc_BARCODE_ERROR_Decode_1D_BadDecode = -11200;
  bcrc_BARCODE_ERROR_FindRowOrColumn = -11201;
  bcrc_BARCODE_ERROR_Find3X8_2D_X = -11202;
  bcrc_BARCODE_ERROR_Find3X8_2D_Y = -11203;
  bcrc_BARCODE_ERROR_2D_UgolMax = -11204;
  bcrc_BARCODE_ERROR_INDEFINITELY_DECODED = -11210;
  bcrc_BARCODE_ERROR_Dllnotinit = -11300;
  bcrc_BARCODE_ERROR_IPDECODE_DLL_Try_Except = -11400;
  bcrc_IPDECODE_ERROR_LARGEERRORS = -4503;
  bcrc_IPDECODE_ERROR_FAULTCOLUMNS = -4504;
  bcrc_IPDECODE_ERROR_FAULTROWS = -4505;
  bcrc_IPDECODE_ERROR_INCORRECT_ERROR_LEVEL = -4511;
  bcrc_IPDECODE_ERROR_LOADING_DEV_TABLE = -4512;

  // enum eBarCodeModuleType{
  MODULETYPE_TEXT = 0;
  MODULETYPE_BYTE = 1;
  MODULETYPE_NUM = 2;
  MODULETYPE_SHIFT = 3;
  MODULETYPE_ALL = 4;

type

  PIP_DECODE_MODULE = ^TIP_DECODE_MODULE;

  TIP_DECODE_MODULE = record
    mType: Integer;
    mLength: Integer;
    mData: array of BYTE;
    mReserved1: Integer;
    mReserved2: Integer;
  end;

  PIP_PDF417_INFO = ^TIP_PDF417_INFO;

  TIP_PDF417_INFO = record
    bcColumn: Integer;
    bcRow: Integer;
    bcErrorLevel: Integer;
    minX: Single;
    minY: Single;
    Angle: Single;
  end;

  PPDocBarCodeField = ^PDocBarCodeField;
  PDocBarCodeField = ^TDocBarCodeField;

  TDocBarCodeField = record
    bcCodeResult: Integer;

    bcType_DETECT: Integer;
    bcROI_DETECT: TRect;
    bcAngle_DETECT: Single;

    bcType_DECODE: Integer;
    bcCountModule: Integer;
    bcDataModule: array of TIP_DECODE_MODULE;
    bcPDF417INFO: TIP_PDF417_INFO;
    bcTextFieldType: Integer;
    bcTextDecoderTypes: Integer;
    bcFieldMask: PAnsiChar;
  end;

  PDocBarCodeInfo = ^TDocBarCodeInfo;

  TDocBarCodeInfo = record
    nFields: DWORD;
    pArrayFields: array of TDocBarCodeField;
  end;

  // ****************************************************************************
  // **  result RPRM_ResultType_MRZ_TestQuality
  // ****************************************************************************
  // 'TResultContainer.buffer' = TDocMRZTestQuality *

  // Результат анализа параметров печати по символу
  PSymbolEstimation = ^TSymbolEstimation;

  TSymbolEstimation = record
    CharSymbol: AnsiChar;
    SymbolBounds: TRect;
    SYMBOL_PARAM: DWORD;
    EMPTINESS: DWORD;
    EDGE: DWORD;
    STAIN: DWORD;
    CONTRAST_PRINT: DWORD;
    CONTRAST_SYMBOL: DWORD;
    ALIGNMENT_NEAREST_SYMBOLS: DWORD;
    SizeErrorAlignWithPrev: Single;
    SizeErrorAlignWithNext: Single;
    SYMBOLS_INTERVAL: DWORD;
    SizeErrorIntervWithPrev: Single;
    SizeErrorIntervWithNext: Single;
    SYMBOL_SIZE: DWORD;
    SizeErrorSymbolHeight: Single;
    SizeErrorSymbolWidth: Single;
  end;

  PSingleRect = ^TSingleRect;

  TSingleRect = record
    Left, Top, Right, Bottom: Single;
  end;

const

  // enum eTestTextField
  tr_OK                          = $00000000;
  tr_Process_Error               = $00000001;
  tr_Invalid_Checksum            = $00000002;
  tr_Syntax_Error                = $00000004;
  tr_Logic_Error                 = $00000008;
  tr_SourcesComparison_Error     = $00000010;
  tr_FieldsComparison_LogicError = $00000020;
  tr_UnknownStatus               = $00000040;
  tr_GlaresOnField               = $00000080;
  tr_InvalidFont                 = $00000100;
  tr_InvalidFieldPosition        = $00000200;
  tr_InvalidBackground           = $00000400;

  // enum eCheckDiagnose
  // 0 - 9: common diagnoses
  chd_Unknown                             = 0; // check was not performed;
  chd_Pass                                = 1; // check was ok;
  chd_InvalidInputData                    = 2; // invalid input data;
  chd_InternalError                       = 3; // internal error in module;
  chd_ExceptionInModule                   = 4; // exception caught;
  chd_UncertainVerification               = 5; // can't make reliable decision
  chd_NecessaryImageNotFound              = 7; // image in necessary light not found
  chd_PhotoSidesNotFound                  = 8; // necessary side of photo not found

  // 10 - 19:	Lex.dll and RegDBOCR.dll (
  chd_InvalidChecksum                     = 10; // invalid checsum;
  chd_SyntaxError                         = 11; // syntactical error;
  chd_LogicError                          = 12; // logical error.
  chd_SourcesComparisonError              = 13; // comparasing was incorrect;
  chd_FieldsComparisonLogicError          = 14; // logical error. e.g. the current date is less than issue date
  chd_InvalidFieldFormat                  = 15; // wrong field format;

  // 20 - 29: Patterns.dll
  chd_TrueLuminiscenceError               = 20; // element of the luminescense in the UV does not meet the standard
  chd_FalseLuminiscenceError              = 21; // the presence of excess luminescence in UV
  chd_FixedPatternError                   = 22; // pattern does not match the standard
  chd_LowContrastInIRLight                = 23; // low contrast of object in transmitted IR light
  chd_IncorrectBackgroundLight            = 24; // background of page is too light or it have invalid color
  chd_BackgroundComparisonError           = 25; // background lightness of two pages have difference
  chd_IncorrectTextColor                  = 26;
  // text have incorrect color of luminescence in UV lightincorrect color of luminesced test
  chd_PhotoFalseLuminiscence              = 27; // invalid luminescence in photo area
  chd_TooMuchShift                        = 28; // object is too shifted from standard coordinates
  chd_ContactChipTypeMismatch             = 29;

  // 30 - 39: Fibers.dll
  chd_FibersNotFound                      = 30; // no protective fibers were found in UV
  chd_TooManyObjects                      = 31; // error finding fibers; too many objects
  chd_SpecksInUV                          = 33; // speck or exposure in UV image
  chd_TooLowResolution                    = 34; // resolution too low for fibers search

  // 40 - 49: IRVisibility.dll and ippImProc.dll(IRB900)
  chd_InvisibleElementPresent             = 40; // erroneous visibility of the element in IR
  chd_VisibleElementAbsent                = 41; // element is absent in IR
  chd_ElementShouldBeColored              = 42;
  chd_ElementShouldBeGrayscale            = 43;
  chd_PhotoWhiteIRDontMatch               = 44;

  // 50 - 59: UVDullPaper.dll
  chd_UVDullPaper_MRZ                     = 50; // glow paper in MRZ
  chd_FalseLuminiscenceInMRZ              = 51; // luminescence characters in MRZ
  chd_UVDullPaper_Photo                   = 52; // glow in the field of photo paper
  chd_UVDullPaper_Blank                   = 53; // glow paper form
  chd_UVDullPaperError                    = 54; // glow of the document in UV
  chd_FalseLuminiscenceInBlank            = 55;

  // 60 - 64: AxialProtection.dll
  chd_BadAreaInAxial                      = 60; // violation of the retro-reflective protection
  // 65 - 69: IPI.dll
  chd_FalseIPIParameters                  = 65; // invalid params for IPI check
  chd_EncryptedIPI_NotFound               = 66; // information not decoded
  chd_EncryptedIPI_DataDontMatch          = 67; // decoded data don't match to other data sources

  // 80 - 89: FieldPosCorrector.dll
  chd_FieldPosCorrector_Highlight_IR      = 80;
  chd_FieldPosCorrector_GlaresInPhotoArea = 81;
  chd_FieldPosCorrector_PhotoReplaced     = 82;
  chd_FieldPosCorrector_LandmarksCheckError = 83;
  chd_FieldPosCorrector_FacePresenceCheckError = 84;
  chd_FieldPosCorrector_FaceAbsenceCheckError = 85;
  chd_FieldPosCorrector_IncorrectHeadPosition = 86;
  // 90 - 99: OVIcheck.dll
  chd_OVI_IR_Invisible                    = 90; // OVI object is not visible in IR
  chd_OVI_InsufficientArea                = 91; // insufficient area of the object OVI
  chd_OVI_ColorInvariable                 = 92; // OVI color of an object does not change
  chd_OVI_BadColor_Front                  = 93; // impossible to determine the color of the AXIAL image
  chd_OVI_BadColor_Side                   = 94; // impossible to determine the color of the WHITE image
  chd_OVI_Wide_Color_Spread               = 95; // wide color spread // ?????????
  chd_OVI_BadColor_Percent                = 96; //

  // 100 - 109: Holograms Check (ippImProc.dll)
  chd_HologramElementAbsent               = 100; // hologram element absent
  chd_Hologram_Side_Top_Images_Absent     = 101; // There aren't Side or Top images! Check cancelled

  // 110 - 119: Diagnoses for RPRM_Authenticity_PassportRUS_Photo  (ippImProc.dll)
  chd_PhotoPattern_Interrupted            = 110; // Рattern is interrupted
  chd_PhotoPattern_Shifted                = 111; // Some of the patterns are shifted relative to each other
  chd_PhotoPattern_DifferentColors        = 112; // Some parts of the pattern have a different color
  chd_PhotoPattern_IR_Visible             = 113; // Pattern seen in the infrared
  chd_PhotoPattern_Not_Intersect          = 114; // Edge of the photo does not intersect with the pattern (Checking impossible)
  chd_PhotoSize_Is_Wrong                  = 115; // Size of the photo does not correspond to requirements
  chd_PhotoPattern_InvalidColor           = 116; // Some parts of the pattern have an invalid color (not Red)
  chd_PhotoPattern_Shifted_Vert           = 117; // Some of the patterns are shifted relative to each other (vertical)
  chd_PhotoPattern_PatternNotFound        = 118; // Not found Pattern. Refuse testing
  chd_PhotoPattern_DifferentLinesThickness = 119; // Different lines thickness

  // 120 - 129: Photo Properties Check (ippImProc.dll)
  chd_Photo_IsNot_Rectangle               = 120; // form of photography is not rectangular
  chd_Photo_Corners_Is_Wrong              = 121; // photo corners don't satisfy the requirements

  chd_TextColorShouldBeBlue               = 130;
  chd_TextColorShouldBeGreen              = 131;
  chd_TextColorShouldBeRed                = 132;
  chd_TextShouldBeBlack                   = 133;
  chd_BarcodeWasReadWithErrors            = 140;
  chd_BarcodeDataFormatError              = 141;
  chd_BarcodeSizeParamsError              = 142;
  chd_NotAllBarcodesRead                  = 143;
  chd_GlaresInBarcodeArea                 = 144;
  chd_NoCertificateForDigitalSignatureCheck = 145;

  chd_PortraitComparison_PortraitsDiffer  = 150;
  chd_PortraitComparison_NoServiceReply   = 151;
  chd_PortraitComparison_ServiceError     = 152;
  chd_PortraitComparison_NotEnoughImages  = 153;
  chd_PortraitComparison_NoLivePhoto      = 154;
  chd_PortraitComparison_NoServiceLicense = 155;
  chd_PortraitComparison_NoPortraitDetected = 156;

  // 160 - 169: Diagnoses for mobile images check
  chd_MobileImages_UnsuitableLightConditions = 160; // need improve light conditions
  chd_MobileImages_WhiteUVNoDifference    = 161; // possible torch don't work

  chd_FingerprintsComparison_Mismatch     = 170;

  chd_HoloPhoto_FaceNotDetected = 180;
  chd_HoloPhoto_FaceComparisonFailed = 181;
  chd_HoloPhoto_GlareInCenterAbsent = 182;
  chd_HoloPhoto_HoloElementShapeError = 183;
  chd_HoloPhoto_AlgorithmStepsError = 184;
  chd_HoloPhoto_HoloAreasNotLoaded = 185;
  chd_HoloPhoto_FinishedByTimeout = 186;
  chd_HoloPhoto_DocumentOutsideFrame = 187;

  chd_Liveness_DepthCheckFailed = 190;
  chd_Liveness_ScreenCaptureDetected = 191;
  chd_Liveness_ElectronicDeviceDetected = 192;

  chd_MrzQuality_WrongSymbolPosition = 200;
  chd_MrzQuality_WrongBackground = 201;
  chd_MrzQuality_WrongMrzWidth = 202;
  chd_MrzQuality_WrongMrzHeight = 203;
  chd_MrzQuality_WrongLinePosition = 204;
  chd_MrzQuality_WrongFontType = 205;

  chd_OCRQuality_TextPosition = 220;
  chd_OCRQuality_InvalidFont = 221;
  chd_OCRQuality_InvalidBackground = 222;

  chd_LasInk_InvalidLinesFrequency = 230;
  chd_DocLiveness_BlackAndWhiteCopyDetected = 239;
  chd_DocLiveness_ElectronicDeviceDetected = 240;
  chd_DocLiveness_InvalidBarcodeBackground = 241;
  chd_DocLiveness_VirtualCameraDetected = 242;

  // ICAO IDB diagnoses
  chd_ICAO_IDB_Base32Error = 243;
  chd_ICAO_IDB_ZippedError = 244;
  chd_ICAO_IDB_MessageZoneEmpty = 245;
  chd_ICAO_IDB_SignatureMustBePresent = 246;
  chd_ICAO_IDB_SignatureMustNotBePresent = 247;
  chd_ICAO_IDB_CertificateMustNotBePresent = 248;
  chd_IncorrectObjectColor = 250;
  chd_LastDiagnoseValue = 251;
  // enum eCompareStatus{
  CompareStatusUnknown = 0; // comparison result unknown
  CompareStatusPass = 3; // positive comparison result
  CompareStatusFailed = 4; // negative comparison result

type

  PTestTextField = ^TTestTextField;

  TTestTextField = record
    TEST_RESULT: DWORD;
    FieldType: DWORD;
    FieldPos: WORD;
    FieldLength: WORD;
    ValidCheckSum: WORD;
    reserved: WORD;
  end;

  PStrEstimation = ^TStrEstimation;

  TStrEstimation = record
    SymbolsCount: Integer;
    StringAngle: Single;
    StringBorders: TRect;
    STRING_POSITION: Integer;
    ErrorPOSITION: TSingleRect;
    STRINGS_DISTANCE: Integer;
    SizeError_DISTANCE: Single;
    STRINGS_INTERVAL: Integer;
    SizeError_INTERVAL: Single;
    ALIGNMENT_SYMBOLS_IN_STRING: Integer;
    SizeError_ALIGNMENT: Single;
    SYMBOLS_PARAM: Integer;
    STRING_FILLING: Integer;
    CHECK_SUMS: Integer;
    FieldCount: Integer;
    Fields: array [0 .. 11] of TTestTextField;
    SymbolsEstimations: array [0 .. 43] of TSymbolEstimation;
  end;

  PDocMRZTestQuality = ^TDocMRZTestQuality;

  TDocMRZTestQuality = record
    DOC_FORMAT: Integer;
    MRZ_FORMAT: Integer;
    TEXTUAL_FILLING: Integer;
    CHECK_SUMS: Integer;
    CONTRAST_PRINT: Integer;
    STAIN_MRZ: Integer;
    PRINT_POSITION: Integer;
    SYMBOLS_PARAM: Integer;
    StrCount: Integer;
    Strings: array [0 .. 2] of TStrEstimation;
  end;

  // ***********************************
  // for RPRM_Command_SetMRZTestQualityParams command:
  // ***********************************

const

  // параметры для проверки качества печати MRZ:
  // enum eMRZClassQuality{
  mrz_CLASS_QUALITY_X = 21;
  mrz_CLASS_QUALITY_Y = 22;
  mrz_CLASS_QUALITY_Z = 23;
  mrz_CLASS_QUALITY_CUSTOM = 24;

  // enum eMRZCheckResult{
  ch_Check_Error = 0;
  ch_Check_OK = 1;
  ch_Check_WasNotDone = 2;

  // enum ePhotoEmbedType{
  PhotoEmbedType_AnyType = 0;
  PhotoEmbedType_strPrinted = 1;
  PhotoEmbedType_strSticked = 2;

type

  PCommandsMRZTestQuality = ^TCommandsMRZTestQuality;

  TCommandsMRZTestQuality = record
    TEST_CLASS_QUALITY: DWORD;
    EXEC_SYMBOLS_PARAM: DWORD;
    EXEC_PRINT_POSITION: DWORD;
    EXEC_TEXTUAL_FILLING: DWORD;
    EXEC_CHECK_SUMS: DWORD;
    Reserved1: DWORD;
    Reserved2: DWORD;
  end;


  // ****************************************************************************
  // result RPRM_ResultType_DocumentTypesCandidates
  //
  // 'TResultContainer.buffer' = TCandidatesListContainer *
  // ****************************************************************************
  // result RPRM_ResultType_ChosenDocumentTypeCandidate
  //
  // 'TResultContainer.buffer' = TOneCandidate *
  // ****************************************************************************

// Document attribute filter (for RCTP_Data_SetDocumentAttributeFilter)
const
  daf_DigitalText = 1;

const

  // enum eRPRM_PostCalbackAction{
  RPRM_PostCalbackAction_Continue = 0;
  RPRM_PostCalbackAction_Cancel = 1;
  RPRM_PostCalbackAction_ProcessCandidate = 2;

  // enum eRPRM_RCTP_Result_RecType{
  RPRM_RCTP_Result_Ok = 0;
  RPRM_RCTP_Result_RecognClassConflict = 14;
  RPRM_RCTP_Result_RecognClassUnknown = 15;

  // enum eRFID_Presence{
  rfpNone = 0;
  rfpMainPage = 1;
  rfpBackPage = 2;

const
  // enum diDocType
  // types defined for IRS:
  dtNotDefined = 0; // Not Defined
  dtPassport = 11; // Passport
  dtIdentityCard = 12; // Identity Card
  dtDiplomaticPassport = 13; // Diplomatic Passport
  dtServicePassport = 14; // Service Passport
  dtSeamanIdentityDocument = 15; // Seaman's Identity Document
  dtIdentityCardForResidence = 16; // Identity Card for for.res.
  dtTravelDocument = 17; // Travel document
  // left for compatibility
  dtOther = 99; // Other
  dtVisaID2 = 29; // Visa, format 2x36
  dtVisaID3 = 30; // Visa, format 2x44
  // additional types supported by DocTeacher:
  dtNationalIdentityCard = 20; // NATIONAL IDENTITY CARD
  dtSocialIdentityCard = 21; // Social Identity Card
  dtAliensIdentityCard = 22; // Alien's Identity Card
  dtPrivilegedIdentityCard = 23; // Privileged Identity Card
  dtResidencePermitIdentityCard = 24; // Residence Permit Identity Card
  dtOriginCard = 25; // ORIGIN CARD
  dtEmergencyPassport = 26; // EMERGENCY PASSPORT
  dtAliensPassport = 27; // ALIEN'S PASSPORT
  dtAlternativeIdentityCard = 28;
  dtAuthorizationCard = 32;
  dtBeginnerPermit = 33;
  dtBorderCrossingCard = 34;
  dtChauffeurLicense = 35;
  dtChauffeurLicenseUnder18 = 36;
  dtChauffeurLicenseUnder21 = 37;
  dtCommercialDrivingLicense = 38;
  dtCommercialDrivingLicenseInstructionalPermit = 39;
  dtCommercialDrivingLicenseUnder18 = 40;
  dtCommercialDrivingLicenseUnder21 = 41;
  dtCommercialInstructionPermit = 42;
  dtCommercialNewPermit = 43;
  dtConcealedCarryLicense = 44;
  dtConcealedFirearmPermit = 45;
  dtConditionalDrivingLicense = 46;
  dtDepartmentOfVeteransAffairsIdentityCard = 47;
  dtDiplomaticDrivingLicense = 48;
  dtDrivingLicense = 49;
  dtDrivingLicenseInstructionalPermit = 50;
  dtDrivingLicenseInstructionalPermitUnder18 = 51;
  dtDrivingLicenseInstructionalPermitUnder21 = 52;
  dtDrivingLicenseLearnersPermit = 53;
  dtDrivingLicenseLearnersPermitUnder18 = 54;
  dtDrivingLicenseLearnersPermitUnder21 = 55;
  dtDrivingLicenseNovice = 56;
  dtDrivingLicenseNoviceUnder18 = 57;
  dtDrivingLicenseNoviceUnder21 = 58;
  dtDrivingLicenseRegisteredOffender = 59;
  dtDrivingLicenseRestrictedUnder18 = 60;
  dtDrivingLicenseRestrictedUnder21 = 61;
  dtDrivingLicenseTemporaryVisitor = 62;
  dtDrivingLicenseTemporaryVisitorUnder18 = 63;
  dtDrivingLicenseTemporaryVisitorUnder21 = 64;
  dtDrivingLicenseUnder18 = 65;
  dtDrivingLicenseUnder21 = 66;
  dtEmploymentDrivingPermit = 67;
  dtEnhancedChauffeurLicense = 68;
  dtEnhancedChauffeurLicenseUnder18 = 69;
  dtEnhancedChauffeurLicenseUnder21 = 70;
  dtEnhancedCommercialDrivingLicense = 71;
  dtEnhancedDrivingLicense = 72;
  dtEnhancedDrivingLicenseUnder18 = 73;
  dtEnhancedDrivingLicenseUnder21 = 74;
  dtEnhancedIdentityCard = 75;
  dtEnhancedIdentityCardUnder18 = 76;
  dtEnhancedIdentityCardUnder21 = 77;
  dtEnhancedOperatorsLicense = 78;
  dtFirearmsPermit = 79;
  dtFullProvisionalLicense = 80;
  dtFullProvisionalLicenseUnder18 = 81;
  dtFullProvisionalLicenseUnder21 = 82;
  dtGenevaConventionsIdentityCard = 83;
  dtGraduatedDrivingLicenseUnder18 = 84;
  dtGraduatedDrivingLicenseUnder21 = 85;
  dtGraduatedInstructionPermitUnder18 = 86;
  dtGraduatedInstructionPermitUnder21 = 87;
  dtGraduatedLicenseUnder18 = 88;
  dtGraduatedLicenseUnder21 = 89;
  dtHandgunCarryPermit = 90;
  dtIdentityAndPrivilegeCard = 91;
  dtIdentityCardMobilityImpaired = 92;
  dtIdentityCardRegisteredOffender = 93;
  dtIdentityCardTemporaryVisitor = 94;
  dtIdentityCardTemporaryVisitorUnder18 = 95;
  dtIdentityCardTemporaryVisitorUnder21 = 96;
  dtIdentityCardUnder18 = 97;
  dtIdentityCardUnder21 = 98;
  dtIgnitionInterlockPermit = 100;
  dtImmigrantVisa = 101;
  dtInstructionPermit = 102;
  dtInstructionPermitUnder18 = 103;
  dtInstructionPermitUnder21 = 104;
  dtInterimDrivingLicense = 105;
  dtInterimIdentityCard = 106;
  dtIntermediateDrivingLicense = 107;
  dtIntermediateDrivingLicenseUnder18 = 108;
  dtIntermediateDrivingLicenseUnder21 = 109;
  dtJuniorDrivingLicense = 110;
  dtLearnerInstructionalPermit = 111;
  dtLearnerLicense = 112;
  dtLearnerLicenseUnder18 = 113;
  dtLearnerLicenseUnder21 = 114;
  dtLearnerPermit = 115;
  dtLearnerPermitUnder18 = 116;
  dtLearnerPermitUnder21 = 117;
  dtLimitedLicense = 118;
  dtLimitedPermit = 119;
  dtLimitedTermDrivingLicense = 120;
  dtLimitedTermIdentityCard = 121;
  dtLiquorIdentityCard = 122;
  dtNewPermit = 123;
  dtNewPermitUnder18 = 124;
  dtNewPermitUnder21 = 125;
  dtNonUsCitizenDrivingLicense = 126;
  dtOccupationalDrivingLicense = 127;
  dtOneidaTribeOfIndiansIdentityCard = 128;
  dtOperatorLicense = 129;
  dtOperatorLicenseUnder18 = 130;
  dtOperatorLicenseUnder21 = 131;
  dtPermanentDrivingLicense = 132;
  dtPermitToReenter = 133;
  dtProbationaryAutoLicense = 134;
  dtProbationaryDrivingLicenseUnder18 = 135;
  dtProbationaryDrivingLicenseUnder21 = 136;
  dtProbationaryVehicleSalespersonLicense = 137;
  dtProvisionalDrivingLicense = 138;
  dtProvisionalDrivingLicenseUnder18 = 139;
  dtProvisionalDrivingLicenseUnder21 = 140;
  dtProvisionalLicense = 141;
  dtProvisionalLicenseUnder18 = 142;
  dtProvisionalLicenseUnder21 = 143;
  dtPublicPassengerChauffeurLicense = 144;
  dtRacingAndGamingComissionCard = 145;
  dtRefugeeTravelDocument = 146;
  dtRenewalPermit = 147;
  dtRestrictedCommercialDrivingLicense = 148;
  dtRestrictedDrivingLicense = 149;
  dtRestrictedPermit = 150;
  dtSeasonalPermit = 151;
  dtSeasonalResidentIdentityCard = 152;
  dtSeniorCitizenIdentityCard = 153;
  dtSexOffender = 154;
  dtSocialSecurityCard = 155;
  dtTemporaryDrivingLicense = 156;
  dtTemporaryDrivingLicenseUnder18 = 157;
  dtTemporaryDrivingLicenseUnder21 = 158;
  dtTemporaryIdentityCard = 159;
  dtTemporaryInstructionPermitIdentityCard = 160;
  dtTemporaryInstructionPermitIdentityCardUnder18 = 161;
  dtTemporaryInstructionPermitIdentityCardUnder21 = 162;
  dtTemporaryVisitorDrivingLicense = 163;
  dtTemporaryVisitorDrivingLicenseUnder18 = 164;
  dtTemporaryVisitorDrivingLicenseUnder21 = 165;
  dtUniformedServicesIdentityCard = 166;
  dtVehicleSalespersonLicense = 167;
  dtWorkerIdentificationCredential = 168;
  dtCommercialDrivingLicenseNovice = 169;
  dtCommercialDrivingLicenseNoviceUnder18 = 170;
  dtCommercialDrivingLicenseNoviceUnder21 = 171;
  dtPassportCard = 172;
  dtPermanentResidentCard = 173;
  dtPersonalIdentificationVerification = 174;
  dtTemporaryOperatorLicense = 175;
  dtDrivingLicenseUnder19 = 176;
  dtIdentityCardUnder19 = 177;
  dtVisa = 178;
  dtTemporaryPassport = 179;
  dtVotingCard = 180;
  dtHealthCard = 181;
  dtCertificateOfCitizenship = 182;
  dtAddressCard = 183;
  dtAirportImmigrationCard = 184;
  dtAlienRegistrationCard = 185;
  dtAPEHCard = 186;
  dtCouponToDrivingLicense = 187;
  dtCrewMemberCertificate = 188;
  dtDocumentForReturn = 189;
  dtECard = 190;
  dtEmploymentCard = 191;
  dtHKSARImmigrationForm = 192;
  dtImmigrantCard = 193;
  dtLabourCard = 194;
  dtLaissezPasser = 195;
  dtLawyerIdentityCertificate = 196;
  dtLicenseCard = 197;
  dtPassportStateless = 198;
  dtPassportChild = 199;
  dtPassportConsular = 200;
  dtPassportDiplomaticService = 201;
  dtPassportOfficial = 202;
  dtPassportProvisional = 203;
  dtPassportSpecial = 204;
  dtPermissionToTheLocalBorderTraffic = 205;
  dtRegistrationCertificate = 206; // Registration Certificate (Auto)
  dtSEDESOLCard = 207;
  dtSocialCard = 208;
  dtTBCard = 209;
  dtVehiclePassport = 210;
  dtWDocument = 211;
  dtDiplomaticIdentityCard = 212;
  dtConsularIdentityCard = 213;
  dtIncomeTaxCard = 214;
  dtResidencePermit = 215;
  dtDocumentOfIdentity = 216;
  dtBorderCrossingPermit = 217;
  dtPassportLimitedValidity = 218;
  dtSIMCard = 219;
  dtTaxCard = 220;
  dtCompanyCard = 221;
  dtDomesticPassport = 222;
  dtIdentityCertificate = 223;
  dtResidentIdentityCard = 224;
  dtArmedForcesIdentityCard = 225;
  dtProfessionalCard = 226;
  dtRegistrationStamp = 227;
  dtDriverCard = 228;
  dtDriverTrainingCertificate = 229;
  dtQualificationDrivingLicense = 230;
  dtMembershipCard = 231;
  dtPublicVehicleDriverAuthorityCard = 232;
  dtMarineLicense = 233;
  dtTemporaryLearnerDrivingLicense = 234;
  dtTemporaryCommercialDrivingLicense = 235;
  dtInterimInstructionalPermit = 236;
  dtCertificateOfCompetency = 237;
  dtCertificateOfProficiency = 238;
  dtTradeLicense = 239;
  dtPassportPage = 240;
  dtInvoice = 241;
  dtPassengerLocatorForm = 242;

type
  PFDSIDList = ^TFDSIDList;

  TFDSIDList = record
    ICAOCode: array [0 .. 3] of AnsiChar;
    Count: DWORD;
    List: array of DWORD;
    dType: DWORD;
    dFormat: DWORD;
    dMRZ: Boolean;
    dDescription: PAnsiChar;
    dYear: PAnsiChar;
    dCountryName: PAnsiChar;
    dStateCode: PAnsiChar;
    dStateName: PAnsiChar;
    isDeprecated: Boolean;
  end;

  POneCandidate = ^TOneCandidate;

  TOneCandidate = record
    DocumentName: PAnsiChar;
    ID: Integer;
    P: Double;
    Rotated180: WORD;
    RotationAngle: WORD;
    NecessaryLights: DWORD;
    preview: PRawImageContainer;
    RFID_Presence: DWORD;
    CheckAuthenticity: DWORD;
    UVExp: WORD;
    OVIExp: WORD;
    AuthenticityNecessaryLights: DWORD;
    FDSIDList: PFDSIDList;
  end;

  PCandidatesListContainer = ^TCandidatesListContainer;

  TCandidatesListContainer = record
    RecResult: DWORD;
    Count: DWORD;
    Candidates: array of TOneCandidate;
  end;

  // ****************************************************************************
  // **  result RPRM_ResultType_Authenticity
  // ****************************************************************************
  // 'TResultContainer.buffer' = TSecurityPaperChecks *

const

  // enum eRPRM_Authenticity
  RPRM_Authenticity_None                   = $00000000;
  RPRM_Authenticity_UV_Luminescence        = $00000001; // TSecurityFeatureCheck
  RPRM_Authenticity_IR_B900                = $00000002; // TSecurityFeatureCheck
  RPRM_Authenticity_Image_Pattern          = $00000004; // TIdentResult
  RPRM_Authenticity_Axial_Protection       = $00000008; // TSecurityFeatureCheck
  RPRM_Authenticity_UV_Fibers              = $00000010; // TFibersType
  RPRM_Authenticity_IR_Visibility          = $00000020; // TIdentResult
  RPRM_Authenticity_OCRSecurityText        = $00000040; // TOCRSecurityTextResult
  RPRM_Authenticity_IPI                    = $00000080; // TPhotoIdentResult
  RPRM_Authenticity_IR_Photo               = $00000100; // TPhotoIdentResult
  RPRM_Authenticity_Photo_Embed_Type       = $00000200; // TSecurityFeatureCheck
  RPRM_Authenticity_OVI                    = $00000400; // TIdentResult
  RPRM_Authenticity_IR_Luminescence        = $00000800; // TIdentResult
  RPRM_Authenticity_Holograms              = $00001000; // TSecurityFeatureCheck
  RPRM_Authenticity_Photo_Area             = $00002000; // TSecurityFeatureCheck
  RPRM_Authenticity_BackgroundComparison   = $00004000; // TFibersType
  RPRM_Authenticity_Portrait_Comparison    = $00008000; // TIdentResult
  RPRM_Authenticity_BarcodeFormatCheck     = $00010000; // TSecurityFeatureCheck
  RPRM_Authenticity_Kinegram               = $00020000; // TIdentResult
  RPRM_Authenticity_Letter_Screen          = $00040000; // TIdentResult
  RPRM_Authenticity_Holograms_Detection    = $00080000; // TIdentResult
  RPRM_Authenticity_Fingerprint_Comparison = $00100000; // TIdentResult
  RPRM_Authenticity_Liveness               = $00200000; // TIdentResult
  RPRM_Authenticity_OCR                    = $00400000; // TSecurityFeatureCheck
  RPRM_Authenticity_MRZ                    = $00800000; // TSecurityFeatureCheck
  RPRM_Authenticity_EncryptedIPI           = $01000000; // TOCRSecurityTextResult
  RPRM_Authenticity_UV                     = RPRM_Authenticity_UV_Luminescence or
                                             RPRM_Authenticity_Image_Pattern or
                                             RPRM_Authenticity_UV_Fibers;

type
  PFibersType = ^TFibersType;

  TFibersType = record
    ElementResult: WORD;
    ElementDiagnose: WORD;
    RectCount: DWORD;
    RectArray: array of TRect;
    Width: array of DWORD;
    Length: array of DWORD;
    Area: array of DWORD;
    ColorValues: array [0 .. 2] of BYTE;
    ExpectedCount: DWORD;
  end;

  // -------------------------------------------

  PPointList = ^TPointList;

  TPointList = record
    Count: DWORD;
    List: array of TPoint;
  end;

  PAreaList = ^TAreaList;

  TAreaList = record
    Count: DWORD;
    List: array of TRect;
    PointList: array of TPointList;
  end;

  PIdentResult = ^TIdentResult;

  TIdentResult = record
    ElementResult: WORD;
    ElementDiagnose: WORD;
    LightIndex: DWORD;
    Area: TRect;
    image: TRawImageContainer;
    EtalonImage: TRawImageContainer;
    PercentValue: DWORD;
    AreaList: PAreaList;
    ElementType: WORD;
    ElementID: WORD;
  end;

  POCRSecurityTextResult = ^TOCRSecurityTextResult;

  TOCRSecurityTextResult = record
    ElementResult: WORD;
    ElementDiagnose: WORD;
    CriticalFlag: DWORD;
    LightType: DWORD;
    FieldRect: TRect;
    EtalonResultType: DWORD;
    EtalonFieldType: DWORD;
    EtalonLightType: DWORD;
    EtalonFieldRect: TRect;
    SecurityTextResultOCR: array [0 .. 255] of AnsiChar;
    EtalonResultOCR: array [0 .. 255] of AnsiChar;
    Reserved1: DWORD;
    Reserved2: DWORD;
  end;

  PPhotoIdentResult = ^TPhotoIdentResult;

  TPhotoIdentResult = record
    ElementResult: WORD;
    ElementDiagnose: WORD;
    LightIndex: DWORD;
    Area: TRect;
    SourceImage: TRawImageContainer; // исходное изображение
    ResultImages: TRawImageContainerList; // массив выходных изображений
    FieldTypesCount: DWORD; // количество типов полей, текст которых закодирован в IPI
    FieldTypesList: array of DWORD; // список констант типов полей, текст которых закодирован в IPI
    Step: DWORD;
    Angle: DWORD;
    Reserved3: DWORD;
  end;

const
  // enum eRPRM_SecurityFeatureType // типы полей для проверки
  SecurityFeatureType_Blank = 0; // элемент бланка
  SecurityFeatureType_Fill = 1; // элемент заполнения
  SecurityFeatureType_Photo = 2; // фотография
  SecurityFeatureType_MRZ = 3; // машиночитаемая зона
  SecurityFeatureType_FalseLuminescence = 4; // машиночитаемая зона
  SecurityFeatureType_HoloSimple = 5;
  SecurityFeatureType_HoloVerifyStatic = 6;
  SecurityFeatureType_HoloVerifyMultiStatic = 7;
  SecurityFeatureType_HoloVerifyDinamic = 8;
  SecurityFeatureType_Pattern_NotInterrupted = 9; // Pattern can't interrupt on border of photo
  SecurityFeatureType_Pattern_NotShifted = 10;
  // Some of the patterns parts can't shift relative to each other (on border of photo)
  SecurityFeatureType_Pattern_SameColors = 11; // Parts of the pattern above photo and above blank have to be same color
  SecurityFeatureType_Pattern_IRInvisible = 12; // Pattern have to invisible under IR light
  SecurityFeatureType_PhotoSize_Check = 13;
  SecurityFeatureType_Portrait_Comparison_vsGhost = 14;
  SecurityFeatureType_Portrait_Comparison_vsRFID = 15;
  SecurityFeatureType_Portrait_Comparison_vsVisual = 16;
  SecurityFeatureType_Barcode = 17;
  SecurityFeatureType_Pattern_DifferentLinesThickness = 18;
  SecurityFeatureType_Portrait_Comparison_vsCamera = 19;
  SecurityFeatureType_Portrait_Comparison_RFIDvsCamera = 20;
  SecurityFeatureType_GhostPhoto = 21;
  SecurityFeatureType_ClearGhostPhoto = 22;
  SecurityFeatureType_InvisibleObject = 23;
  SecurityFeatureType_LowContrastObject = 24;
  // 25/07/2016 проверки фотографии (дополнительно к имеющейся SecurityFeatureType_PhotoSize_Check)
  SecurityFeatureType_Photo_Color = 25; // Цветность фотографии
  SecurityFeatureType_Photo_Shape = 26; // Форма (прямоугольность) фотографии
  SecurityFeatureType_Photo_Corners = 27; // Форма углов фотографии
  SecurityFeatureType_OCR = 28;
  SecurityFeatureType_Portrait_Comparison_ExtvsVisual = 29;
  SecurityFeatureType_Portrait_Comparison_ExtvsRFID = 30;
  SecurityFeatureType_Portrait_Comparison_ExtvsLive = 31;
  SecurityFeatureType_Liveness_Depth = 32;
  SecurityFeatureType_Microtext = 33;
  SecurityFeatureType_FluorescentObject = 34;
  SecurityFeatureType_LandmarksCheck = 35;
  SecurityFeatureType_FacePresence = 36;
  SecurityFeatureType_BlankCaption = 37;
  SecurityFeatureType_FaceAbsence = 38;
  SecurityFeatureType_LivenessScreenCapture = 39;
  SecurityFeatureType_LivenessElectronicDevice = 40;
  SecurityFeatureType_LivenessOVI = 41;
  SecurityFeatureType_BarcodeSizeCheck = 42;
  SecurityFeatureType_LasInk = 43;
  SecurityFeatureType_DocLiveness_ElectronicDevice = 44;
  SecurityFeatureType_Liveness_BarcodeBackground = 45;
  SecurityFeatureType_Portrait_Comparison_vsBarcode = 46;
  SecurityFeatureType_Portrait_Comparison_RFIDvsBarcode = 47;
  SecurityFeatureType_Portrait_Comparison_ExtvsBarcode = 48;
  SecurityFeatureType_Portrait_Comparison_BarcodevsCamera = 49;
  SecurityFeatureType_CheckDigitalSignature = 50;
  SecurityFeatureType_ContactChipClassification = 51;
  SecurityFeatureType_HeadPositionCheck = 52;
  SecurityFeatureType_Liveness_BlackAndWhiteCopyCheck = 53;

  // enum eIR_Visibility_Flag
  ElementInvisible = 0;
  ElementVisible = 1;
  ElementColored = 2;
  ElementGrayscale = 4;
  WhiteIRMatching = 8;

  // enum eSecurityCriticalFlag
  CheckFeatureNotCritical = 0;
  CheckFeatureIsCritical = 1;

type

  PSecurityFeatureCheck = ^TSecurityFeatureCheck;

  TSecurityFeatureCheck = record
    ElementResult: WORD;
    ElementDiagnose: WORD;
    ElementType: DWORD; // тип элемента (eRPRM_SecurityFeatureType)
    ElementRect: TRect; // область элемента
    Visibility: DWORD;
    // флаг видимости элемента для RPRM_Authenticity_IR_Visibility (eIR_Visibility_Flag)
    CriticalFlag: DWORD; // флаг критичности (eSecurityCriticalityFlag)
    AreaList: PAreaList;
    reserved: DWORD;
  end;

  PPAuthenticityCheckResult = ^PAuthenticityCheckResult;
  PAuthenticityCheckResult = ^TAuthenticityCheckResult;

  TAuthenticityCheckResult = record
    CheckType: DWORD; // тип проверки (eRPRM_Authenticity)
    Result: DWORD; // общий результат проверки (eRPRM_CheckResult)
    Count: DWORD; // количество элементов в List
    List: array of Pointer; // динамический массив элементов
  end;

  PAuthenticityCheckList = ^TAuthenticityCheckList;

  TAuthenticityCheckList = record
    Count: DWORD; // количество элементов в List, т.е. количество проверок
    List: array of PAuthenticityCheckResult; // список проверок
  end;

  // ****************************************************************************
  // **  result RPRM_ResultType_DocumentsInfoList
  // ****************************************************************************
  // 'TResultContainer.buffer' = TListDocsInfo *

type

  PPOCRDocInfo = ^TPOCRDocInfo;

  TPOCRDocInfo = record
    DocName: TArrayOfChar;
    DocID: DWORD;
    DocTxtID: TArrayOfChar;
    DocFormat: DWORD;
    NecessaryLights: DWORD;
    nFields: DWORD;
    RFID_Presence: DWORD;
    Reserved1: DWORD;
    Reserved2: DWORD;
    Reserved3: DWORD;
  end;

  PPListDocsInfo = ^TPListDocsInfo;

  TPListDocsInfo = record
    Count: DWORD;
    ArrayOfDocs: array of TPOCRDocInfo;
  end;

const
  // enum eRPRM_FieldVerificationResult
  RCF_Disabled = 0; // comparison result unknown
  RCF_Verified = 1; // verification passed
  RCF_Not_Verified = 2; // verification failed
  RCF_Compare_True = 3; // positive comparison result
  RCF_Compare_False = 4; // negative comparison result

  // ****************************************************************************
  // **  result RPRM_ResultType_OCRLexicalAnalyze
  // ****************************************************************************
  // 'TResultContainer.buffer' = TListVerifiedFields *
type
  PVerifiedFieldMap = ^TVerifiedFieldMap;

  TVerifiedFieldMap = record
    FieldType: WORD;
    LCID: WORD;
    Field_MRZ: PAnsiChar;
    Field_RFID: PAnsiChar;
    Field_Visual: PAnsiChar;
    Field_Barcode: PAnsiChar;
    Matrix: array [0 .. 9] of BYTE;
  end;

  PListVerifiedFields = ^TListVerifiedFields;

  TListVerifiedFields = record
    Count: DWORD;
    pFieldMaps: array of TVerifiedFieldMap;
  end;

const
  // enum eLexAnalysisDepth
  eLAD_Default = 0;
  eLAD_ShowAllData = $0001;
  eLAD_ShowDataAndResults = $0002;
  eLAD_CheckStopListOFF = $0004;
  eLAD_CheckDocNumZeroOFF = $0008;
  eLAD_ICAOConvertionOFF = $0010;

  // DEPRECATED
  // enum eLexDateFormat
  LDF_DefaultShort = 0;
  LDF_DefaultLong = 1;
  LDF_SystemShort = 2;
  LDF_SystemLong = 3;
  LDF_Universal = 4;
  LDF_Custom = 5;

type
  // DEPRECATED
  PLexDateFormat = ^TLexDateFormat;

  TLexDateFormat = record
    format: DWORD; // eLexDateFormat
    customFormatString: array [0 .. 31] of AnsiChar;
    // custom format string in yyyy-MM-dd format
  end;

  // ****************************************************************************
const
  // enum eLED_Color

  ledNone = 0;
  ledRed = 1;
  ledGreen = 2;
  ledOrange = 3;

type

  PIndicationLED = ^TIndicationLED;

  TIndicationLED = record
    wColorLed: WORD;
    wFreq: WORD;
  end;

  PDwordList = ^TDwordList;

  TDwordList = record
    Count: DWORD;
    List: array of DWORD;
  end;

const
  // enum eBoundsResultStatus
  BRS_None = 0;
  BRS_Confirmed = 1;
  BRS_HasMrz = 2;

type
  PPBoundsResult = ^PBoundsResult;
  PBoundsResult = ^TBoundsResult;

  TBoundsResult = record
    DocFormat: Integer;
    Width: Integer;
    Height: Integer;
    Center: TPoint;
    Angle: Single;
    LeftTop: TPoint;
    LeftBottom: TPoint;
    RightTop: TPoint;
    RightBottom: TPoint;
    Inverse: Integer;
    PerspectiveTr: Integer;
    ObjArea: BYTE; // 0-100 (doc area in % from image size)
    ObjIntAngleDev: BYTE; // 0-90  (deviation angle from 90)
    reserved: Integer;
  end;

  // ****************************************************************************
  // ****************************************************************************

const

  // enum eFDSLight {
  fdsWhite = 1;
  fdsUV365 = 2;
  fdsIR = 4;
  fdsMaterial = 6;

  // enum eFDS_Panel {
  FDS_Panel_Main = 0;
  FDS_Panel_Countries = 1;
  FDS_Panel_Documents = 2;
  FDS_Panel_Caption = 3;
  FDS_Panel_Description = 4;
  FDS_Panel_Illumination = 5;
  FDS_Panel_PageType = 6;

  // enum eFDS_Panel_Position
  FDS_Panel_Hide = 0;
  FDS_Panel_Show = 1;
  FDS_Panel_ShowTop = 2;
  FDS_Panel_ShowBottom = 3;

  // input image quality check
  // enum eImageQualityCheckType
  IQC_ImageGlares = 0;
  IQC_ImageFocus = 1;

type
  PImageQualityCheck = ^TImageQualityCheck;

  TImageQualityCheck = record
    CheckType: UInt32;
    Result: UInt32;
    Areas: PAreaList;
    Mean: Single;
    Std_dev: Single;
    Probability: Integer;
  end;

  PImageQualityCheckList = ^TImageQualityCheckList;

  TImageQualityCheckList = record
    Count: UInt32;
    Result: UInt32;
    List: array of PImageQualityCheck;
  end;

  PRfidOrigin = ^TRfidOrigin;

  TRfidOrigin = record
    dg: Integer;
    dgTag: Integer;
    tagEntry: Integer;
    entryView: Integer;
  end;

  PTextValidity = ^TTextValidity;

  TTextValidity = record
    source: PAnsiChar;
    status: UInt32; // eCheckResult
  end;

  PTextComparison = ^TTextComparison;

  TTextComparison = record
    sourceLeft: PAnsiChar;
    sourceRight: PAnsiChar;
    status: UInt32; // eCheckResult
  end;

  PTextSource = ^TTextSource;

  TTextSource = record
    source: PAnsiChar;
    containerType: UInt32; // eRPRM_ResultType
    validityStatus: UInt32; // eCheckResult
  end;

  PTextSymbol = ^TTextSymbol;

  TTextSymbol = record
    code: UInt32;
    rect: TRect;
    Probability: UInt32; // (0-100%)
  end;

  PTextFieldValue = ^TTextFieldValue;

  TTextFieldValue = record
    value: PAnsiChar;
    originalValue: PAnsiChar;
    originalValidity: UInt32; // eCheckResult
    source: PAnsiChar;
    containerType: UInt32; // eRPRM_ResultType
    pageIndex: UInt32;
    FieldRect: TRect;
    rfidOrigin: TRfidOrigin;
    Probability: UInt32; // (0-100%)
    originalSymbolsCount: UInt32; // number of symbols
    originalSymbols: array of TTextSymbol; // array of symbol recognition results
  end;

  PTextField = ^TTextField;

  TTextField = record
    FieldType: uint16; // eVisualFieldType
    FieldName: PAnsiChar;
    LCID: uint16;
    lcidName: PAnsiChar;
    status: UInt32; // eCheckResult
    value: PAnsiChar;
    valueCount: UInt32;
    valueList: array of TTextFieldValue;
    validityStatus: UInt32; // eCheckResult
    validityCount: UInt32;
    validityList: array of TTextValidity;
    comparisonStatus: UInt32; // eCheckResult
    comparisonCount: UInt32;
    comparisonList: array of TTextComparison;
  end;

  PTextResult = ^TTextResult;

  TTextResult = record
    status: UInt32; // eCheckResult
    validityStatus: UInt32; // eCheckResult
    comparisonStatus: UInt32; // eCheckResult
    dateFormat: PAnsiChar;
    FieldCount: UInt32;
    fieldList: array of TTextField;
    availableSourceCount: UInt32;
    availableSourceList: array of TTextSource;
  end;

  PImageFieldValue = ^TImageFieldValue;

  TImageFieldValue = record
    value: PAnsiChar;
    originalValue: PAnsiChar;
    source: PAnsiChar;
    containerType: UInt32;
    pageIndex: UInt32;
    LightIndex: UInt32;
    FieldRect: TRect;
    rfidOrigin: TRfidOrigin;
  end;

  PImageField = ^TImageField;

  TImageField = record
    FieldType: UInt32;
    FieldName: PAnsiChar;
    valueCount: UInt32;
    valueList: array of TImageFieldValue;
  end;

  PImageSource = ^TImageSource;

  TImageSource = record
    source: PAnsiChar;
    containerType: UInt32;
  end;

  PImagesResult = ^TImagesResult;

  TImagesResult = record
    FieldCount: UInt32;
    fieldList: array of TImageField;
    availableSourceCount: UInt32;
    availableSourceList: array of TImageSource;
  end;

  // ****************************************************************************

  PDatabaseCheck = ^TDatabaseCheck;

  TDatabaseCheck = record
    recordsCount: UInt32;
    recordsJson: PAnsiChar;
    sqlRequest: PAnsiChar;
  end;

  // ****************************************************************************
  // ** SDK DLL callback functions types
  // ****************************************************************************
type
  TResultReceivingFunc = procedure(Result: PResultContainer; PostAction: PLongWord;
    PostActionParameter: PLongWord); stdcall;
  TNotifyFunc = procedure(code, value: NativeInt); stdcall;

  // ****************************************************************************
  // ** SDK DLL exporting functions
  // ****************************************************************************
  _LibraryVersion = function: DWORD; cdecl;
  _SetCallbackFunc = procedure(F1: TResultReceivingFunc; F2: TNotifyFunc); cdecl;

  _Initialize = function(lpParams: Pointer; hParent: HWND): Integer; cdecl;
  _Free = function: Integer; cdecl;

  _ExecuteCommand = function(ACommand: Integer; AParams, AResult: Pointer): Integer; cdecl;

  _CheckResult = function(AType: Integer; AIdx: Integer; AOutput: Integer; AParam: Pointer): THandle; cdecl;
  _CheckResultFromList = function(AContainer: THandle; AOutput: Integer; AParam: Pointer): Integer; cdecl;
  _ResultTypeAvailable = function(AType: Integer): DWORD; cdecl;

  // memory allocation section ********************************
  _AllocRawImageContainer = function(ACont: PPRawImageContainer; w, h, bits_cnt, resolution: Integer): Integer; cdecl;
  _FreeRawImageContainer = function(ACont: PRawImageContainer): Integer; cdecl;

  // FDS section **********************************************
  _FDSUser_Connect = function(Handle: HWND): Integer; cdecl;
  _FDSUser_Disconnect = function: Integer; cdecl;
  _FDSUser_UpdateWindow = function(w, h, Show: Longint): Integer; cdecl;
  _FDSUser_UpdatePanel = function(Panel, Position, Height: Longint): Integer; cdecl;
  _FDSUser_SelectDocument = function(CountryCode, DocCode: PAnsiChar; light: Longint): Integer; cdecl;


  // **********************************************************************************************
  // ** SDK states, return and notification codes, etc.
  // **********************************************************************************************

const

  // enum eRPRM_OutputFormat{
  ofrDefault = 0;

  ofrTransport_Clipboard = $00000002;
  ofrTransport_File = $00000004;

  ofrFormat_XML = $00010000;
  ofrFormat_FileBuffer = $00020000; // for images only
  ofrFormat_ImagesXML = $00040000; // for images only
  ofrFormat_JSON = $00080000;
  ofrFormat_NoSystemInfo = $00100000; // do not write system info into file. to be used only with XML or JSON

  ofrFileBuffer_File = ofrTransport_File or ofrFormat_FileBuffer;

  ofrXML_Clipboard = ofrTransport_Clipboard or ofrFormat_XML;
  ofrXML_File = ofrTransport_File or ofrFormat_XML;

  ofrJSON_Clipboard = ofrTransport_Clipboard or ofrFormat_JSON;
  ofrJSON_File = ofrTransport_File or ofrFormat_JSON;

  ofrFileBuffer_XML_Clipboard = ofrXML_Clipboard or ofrFormat_FileBuffer;
  ofrFileBuffer_XML_File = ofrXML_File or ofrFormat_FileBuffer;

  ofrFileBuffer_JSON_Clipboard = ofrJSON_Clipboard or ofrFormat_FileBuffer;
  ofrFileBuffer_JSON_File = ofrJSON_File or ofrFormat_FileBuffer;

  // enum eRPRM_ResultStatus{
  RPRM_ResultStatus_NotAvailable = $FFFFFFFF;
  RPRM_ResultStatus_EndOfList = $FFFFFFFE;
  RPRM_ResultStatus_InvalidParameter = $FFFFFFFD;
  RPRM_ResultStatus_Error = $FFFFFFFC;
  RPRM_ResultStatus_IOError = $FFFFFFFB;
  RPRM_ResultStatus_InvalidFilename = $FFFFFFFA;
  RPRM_ResultStatus_ClipboardError = $FFFFFFF9;
  RPRM_ResultStatus_NotEnoughMemory = $FFFFFFF8;
  RPRM_ResultStatus_NotSupported = $FFFFFFF7;

type
  PVideodetectionNotification = ^TVideodetectionNotification;

  TVideodetectionNotification = record
    sensorState: UInt32;
    image: PRawImageContainer;
    mrzPosition: PBoundsResult;
  end;

const
  // enum eRPRM_NotificationCodes{  // - code parameter in NotifyFunc()
  RPRM_Notification_Error = $00000000; // value = one of eRPRM_ErrorCodes
  RPRM_Notification_DeviceDisconnected = $00000001;
  RPRM_Notification_DocumentReady = $00000002; // value = true or false
  RPRM_Notification_Scanning = $00000004; // value = true or false
  RPRM_Notification_DeviceTick = $00000007;
  RPRM_Notification_Calibration = $00000008; // value = true or false
  RPRM_Notification_CalibrationProgress = $00000009; // value = 0-100 - percentage
  RPRM_Notification_CalibrationStep = $0000000A;
  RPRM_Notification_EnumeratingDevices = $0000000C;
  RPRM_Notification_ConnectingDevice = $0000000D; // value = true or false
  RPRM_Notification_DocumentCanBeRemoved = $0000000E;
  RPRM_Notification_LidOpen = $0000000F;
  RPRM_Notification_Processing = $00000010;
  RPRM_Notification_DownloadingCalibrationInfo = $00000011;
  RPRM_Notification_LicenseExpired = $00000012;
  RPRM_Notification_OperationProgress = $00000013;
  RPRM_Notification_LatestAvailableSDK = $00000014;
  RPRM_Notification_LatestAvailableDatabase = $00000015;
  RPRM_Notification_VideoFrame = $00000016; // value = TVideodetectionNotification*
  RPRM_Notification_CompatibilityMode = $00000017;   ///< indication that device runs in compatibility mode. value = eDeviceLimitations*

  // enum eRPRM_ErrorCodes{
  RPRM_Error_NoError = $00000000; // everything is Ok
  RPRM_Error_AlreadyDone = $00000001; // requested operation is already done
  RPRM_Error_NoGraphManager = $00000002; // can't create or connect to the instance of GraphManager
  RPRM_Error_CantRegisterMessages = $00000003; // something wrong with Windows messages registration
  RPRM_Error_NoServiceManager = $00000004; // can't create or connect to the instance of ServiceManager
  RPRM_Error_CantConnectServiceManager = $00000006; // can't connect to ServiceManager COM server
  RPRM_Error_CantCreateDeviceLibraryEvent = $00000009; // can't create device control event
  RPRM_Error_InvalidParameter = $0000000C; // invalid parameter in ExecuteCommand() call
  RPRM_Error_NotInitialized = $0000000D; // Initialize() must be executed previously
  RPRM_Error_Busy = $0000000E; // device is busy and can't process command
  RPRM_Error_NotEnoughMemory = $00000011; // out of memory
  RPRM_Error_BadVideo = $00000014; // video stream didn't start properly - it's necessary to reconnect
  RPRM_Error_ScanAborted = $00000015; // scanning is cancelled
  RPRM_Error_CantRecognizeDocumentType = $00000016; // can't recognize document type during visual OCR
  RPRM_Error_CantSetupSensor = $00000018; // document inserted during initialization
  RPRM_Error_NotTrueColorDesktop = $00000019; //
  RPRM_Error_NotAvailable = $0000001A; // action is not available in the current working state
  RPRM_Error_DeviceError = $0000001B; // device is currently not available - it's necessary to retry
  // initialization or even re-plug-in the device itself
  RPRM_Error_DeviceDisconnected = $00000020; // device was disconnected prior to the requested action

  RPRM_Error_NotWrongThreadContext = $00000030;
  // вызов функции Free() требует контекста потока, в котором вызывалась Initialize()
  RPRM_Error_COMServers = $00000031; // ошибки регистрации СОМ-серверов в Global Interface Table
  RPRM_Error_NoDocumentReadersFound = $00000032; // не найдено ни одного подключенного ридера
  RPRM_Error_NoTranslationMngr = $00000033; // can't create or connect to the instance of ServiceManager
  RPRM_Error_NoActiveDevice = $00000034; // there's no currently connected reader
  RPRM_Error_ConnectingDevice = $00000035; // can't connect selected reader
  RPRM_Error_Failed = $00000036; // general error status
  RPRM_Error_LightIsNotAllowed = $00000037; // given light scheme is not available for image processing
  RPRM_Error_ImageIOError = $00000038; // ошибка чтения/записи изображения
  RPRM_Error_CantStoreCalibrationData = $00000039; // ошибка сохранения данных калибровки
  RPRM_Error_DeviceNotCalibrated = $0000003A; // ридер не был откалиброван
  RPRM_Error_CantCompensateDistortion = $0000003B; // ошибка компенсации искажений
  RPRM_Error_OperationCancelled = $0000003C; // операция прервана пользователем (калибровка, диалоги)
  RPRM_Error_CantLocateDocumentBounds = $0000003D; // границы документа не определены
  RPRM_Error_CantRefineImages = $0000003E; // ошибка компенсации цвета/неравномерности освещения
  RPRM_Error_CantCropRotateImages = $0000003F; // ошибка обработки
  RPRM_Error_IncompleteImagesList = $00000040;
  // при выполнении RPRM_Command_ProcessImagesList, когда представленный список
  // изображений требует обновления
  RPRM_Error_CantReadMRZ = $00000041; //
  RPRM_Error_CantFindBarcodes = $00000042; //
  RPRM_Error_DeviceIDNotSupported = $00000043;
  RPRM_Error_DeviceIDNotStored = $00000044;
  RPRM_Error_DeviceDriver = $00000045;

  RPRM_Error_CalibrationOpenLid = $00000046;
  RPRM_Error_Calibration_Brightness = $00000047; // плохая яркость
  RPRM_Error_Calibration_WhiteBalance = $00000048; // плохой баланс белого
  RPRM_Error_Calibration_TargetPosition = $00000049; // неправильное положение тест-объекта
  RPRM_Error_Calibration_LightBlank = $0000004A; // картинка забликована
  RPRM_Error_Calibration_LightDistortion = $0000004B; // неравномерность освещения
  RPRM_Error_Calibration_LightLevel = $0000004C; // недопустимый уровень яркости
  RPRM_Error_Calibration_LightLevelHigh = $0000004D; // - общий пересвет
  RPRM_Error_Calibration_LightLevelLow = $0000004E; // - общий недосвет

  RPRM_Error_8305CameraAbsent = $00000050;
  RPRM_Error_NotImplemented = $00000051;
  RPRM_Error_RemoveDocument = $00000052;
  RPRM_Error_BadDataFile = $00000053; // data file is absent or corrupted
  RPRM_Error_BadInputImage = $00000054; // input image has glares or out of focus
  RPRM_Error_BadOptical = $00000055;

  // enum eRPRM_Commands{
  RPRM_Command_Device_Count = $00000001; // retrieve a number of available document readers,
  // result = DWORD *
  RPRM_Command_Device_Features = $00000002; // retrieve reader's features,
  // params = device index, result = TRegulaDeviceProperties *
  RPRM_Command_Device_RefreshList = $00000003; // refresh list of available readers
  // result = DWORD * - returns new device count
  RPRM_Command_Device_ActiveIndex = $00000004;
  // retrieve an index of the active reader in the current list of available readers
  // result = DWORD *
  RPRM_Command_Device_Connect = $00000005; // connect selected document reader,
  // params = device index
  RPRM_Command_Device_Disconnect = $00000006; // disconnect active reader

  RPRM_Command_Device_Light_ScanList_Clear = $00000007; // clear current scanning light list for active reader
  RPRM_Command_Device_Light_ScanList_AddTo = $00000008; // add light to the scanning list for active reader
  // params = eRPRM_Lights combination
  RPRM_Command_Device_Light_ScanList_Default = $00000016; // restore default scan list
  RPRM_Command_Device_Light_ScanList_Count = $00000017; // retrieve a number of scan list elements
  // result = DWORD *
  RPRM_Command_Device_Light_ScanList_Item = $00000018; // retrieve an item from current scan list
  // params = item index
  // result = DWORD *

  RPRM_Command_Device_Light_TurnOn = $00000009; // manual light scheme activation, without image processing support
  // params = eRPRM_Lights combination
  RPRM_Command_Device_LED = $0000000B; // manual LED control
  // params = TIndicationLED *
  RPRM_Command_Device_PlaySound = $0000000F; // manual beep

  RPRM_Command_Device_Set_ParamLowLight = $0000000C; // params = 0-10, exposure for UV
  RPRM_Command_Device_Get_ParamLowLight = $0000000D; // result = long * for value

  RPRM_Command_Device_Calibration = $00000015; // calibrate the device
  // params = eCalibrationType

  RPRM_Command_Process = $00000019; // to capture and process images
  // params = eRPRM_GetImage_Modes combination

  RPRM_Command_Options_GraphicFormat_Count = $0000001A; // result = DWORD *
  RPRM_Command_Options_GraphicFormat_Name = $0000001B; // params = index
  // result = char **
  RPRM_Command_Options_GraphicFormat_Select = $0000001C; // params = format index
  RPRM_Command_Options_GraphicFormat_ActiveIndex = $00000020; // result = DWORD *

  RPRM_Command_Options_GetSDKCapabilities = $0000001E; // result = long * for eRPRM_Capabilities combination
  RPRM_Command_Options_GetSDKAuthCapabilities = $00000035; // result = long * for eRPRM_Authenticity combination

  RPRM_Command_Options_Set_MRZTestQualityParams = $00000022; // params = TCommandsMRZTestQuality *
  RPRM_Command_Options_Get_MRZTestQualityParams = $00000023; // result = TCommandsMRZTestQuality *

  RPRM_Command_ProcessImagesList = $00000024; // to process a list of images instead of executing live scanning
  // params = TResultContainerList *
  // result = eRPRM_GetImage_Modes combination (as 2nd input parameter)

  RPRM_Command_Options_Get_DBDirectory = $00000025; // result = char **
  RPRM_Command_Options_Set_DBDirectory = $00000026; // params = char *

  RPRM_Command_Options_Set_CurrentDocumentType = $00000027;
  // params = char *, for RPRM_Command_ProcessImagesList to follow
  RPRM_Command_Options_Get_CurrentDocumentType = $00000028; // result = char **

  RPRM_Command_Options_Set_CustomDocTypeMode = $00000029; // params = true or false
  RPRM_Command_Options_Get_CustomDocTypeMode = $0000002A; // result = long * for true or false

  RPRM_Command_Get_DocumentsInfoList = $0000002B; //

  RPRM_Command_OCRLexicalAnalyze = $0000002C; // params = TResultContainerList *
  RPRM_Command_Device_IsCalibrated = $0000002D; // check if the device has valid calibration data
  // result = long * for true or false
  RPRM_Command_Options_Set_CheckResultHeight = $0000002E; // params = desired height in pixels

  RPRM_Command_Device_Set_WorkingVideoMode = $00000030; // params = eRPRM_VideoModes
  RPRM_Command_Device_Get_WorkingVideoMode = $00000031; // result = long *

  RPRM_Command_Options_Set_AuthenticityCheckMode = $00000032; // params = eRPRM_Authenticity
  RPRM_Command_Options_Get_AuthenticityCheckMode = $00000033; // result = long *

  RPRM_Command_Options_Get_BatteryStatus = $00000034; // Get status of installed accumulator batteries
  // params = long - number of accumulator
  // result = long *  0-100%, 0xFF - no battery, 0xFE - charging, 0xF0 - battery level 100%

  RPRM_Command_Options_BuildExtLog = $00000040; // params = true or false
  RPRM_Command_Device_GetFrequencyDivider = $0000004E; // get Frequency Divider value;
  RPRM_Command_Device_SetFrequencyDivider = $00000041; // params = long (0-5)

  RPRM_Command_Device_Get_DriverVersion = $00000042; // result = long *
  RPRM_Command_Device_APM_Mode = $00000044;
  RPRM_Command_Device_UseVideoDetection = $00000045; // params = true or false
  RPRM_Command_ExpertAnalyze = $00000046; // params = TResultContainer *
  RPRM_Command_ClearResults = $00000047;
  RPRM_Command_Options_GraphicFormat_SetCompressionRatio = $00000048;
  // params - the level of compression (0 - min,  10 - max)
  RPRM_Command_Options_GraphicFormat_GetCompressionRatio = $00000049; // result = long *
  RPRM_Command_Process_Cancel = $0000004A; // no params
  RPRM_Command_ExcludeCapabilities = $0000004B; // params = eRPRM_Capabilities combination to exclude
  RPRM_Command_ExcludeAuthCapabilities = $0000004C; // params = eRPRM_Authenticity combination to exclude

  RPRM_Command_MakeSingleShot = $0000004D; // params = eRPRM_Lights combination, result = bool for LocateDocument

  RPRM_Command_ComplexAuthenticityCheck = $0000004F;
  RPRM_Command_Options_Set_GlareCompensation = $00000050;
  // glare compensation for Regula readers, params = true or false
  RPRM_Command_Options_Set_ExtendProcessingModes = $00000051;
  // Turn additional processing modes ON, params = true or false, default = true

  RPRM_Command_Options_Get_AppendVisa = $00000052; // get current "append visa" mode (false by default)
  RPRM_Command_Options_Set_AppendVisa = $00000053; // set "append visa" mode (false by default)
  RPRM_Command_Options_Set_MultiPageProcessingMode = $00000054; // set "multipage processing" mode (true by default)
  RPRM_Command_Device_Get_Calibration_FrequencyDivider = $00000055; // get Frequency Divider value;
  RPRM_Command_PortraitGraphicalAnalyze = $00000056; // compare portrait images
  // params = TResultContainerList * with additional containers with RFID data (if exists)
  RPRM_Command_Options_Set_SmartUV = $00000057; // SmartUV for Regula readers, params = true or false
  RPRM_Command_Options_Set_RotateResultImages = $00000058;
  // rotate document images by document type or portrait orientation
  RPRM_Command_BSIDocCheckXML = $00000059;
  RPRM_Command_Options_Get_QuickMrzProcessing = $0000005A;
  // Get QuickMrzProcessing parameter value (result = DWORD*, FALSE by default)
  RPRM_Command_Options_Set_QuickMrzProcessing = $0000005B;
  // Set QuickMrzProcessing parameter value (params = DWORD, TRUE/FALSE)
  RPRM_Command_Device_SetVideoDetectionDivider = $0000005C;
  // Set VideoDetectionFrameSize parameter value (params = DWORD)
  RPRM_Command_Device_GetVideoDetectionDivider = $0000005D;
  // Get VideoDetectionFrameSize parameter value (result = DWORD*)
  RPRM_Command_Device_SetRequiredOcrFields = $0000005E; // Set Required Ocr Fields (params = TDwordList *)
  RPRM_Command_Device_GetRequiredOcrFields = $0000005F; // Get Required Ocr Fields (result = TDwordList **)

  RPRM_Command_Options_Get_BatteryNumber = $00000060;
  // Get number of installed accumulator batteries in device, result - long *.
  RPRM_Command_Options_Get_QuickBoardingPassProcessing = $00000061;
  // Get QuickBoardingPassProcessing parameter value (result = DWORD*, FALSE by default)
  RPRM_Command_Options_Set_QuickBoardingPassProcessing = $00000062;
  // Set QuickBoardingPassProcessing parameter value (params = DWORD, TRUE/FALSE)
  RPRM_Command_Options_Set_WaitForReadingComplete = $00000063;
  RPRM_Command_ReadingComplete = $00000064;

  RPRM_Command_Options_Get_LexAnalysisDepth = $00000065;
  // [deprecated] Get LexAnalysisDepth parameter value (result = DWORD*, FALSE by default)
  RPRM_Command_Options_Set_LexAnalysisDepth = $00000066;
  // [deprecated]Set LexAnalysisDepth parameter value (params = DWORD, TRUE/FALSE)

  RPRM_Command_Options_Get_LexDateFormat = $00000067;
  // [deprecated] Get Lex Date Format parameter value (result = TLexDateFormat**)
  RPRM_Command_Options_Set_LexDateFormat = $00000068;
  // [deprecated] Set Lex Date Format parameter value (params = TLexDateFormat*)

  RPRM_Command_Device_Get_GetJpegImages = $00000069;
  // Get GetJpegImages parameter value (result = DWORD*, FALSE by default)
  RPRM_Command_Device_Set_GetJpegImages = $0000006A;
  // Set GetJpegImages parameter value (params = DWORD, TRUE/FALSE)
  RPRM_Command_BSIDocCheckXMLv2 = $0000006B;
  // generate BSI document check XML v2 (params = TResultContainerList *, result = char ** containing XML)
  RPRM_Command_Options_Get_TrustDPI = $0000006C; // Get TrustDPI parameter value (result = DWORD*, FALSE by default)
  RPRM_Command_Options_Set_TrustDPI = $0000006D; // Set TrustDPI parameter value (params = DWORD, TRUE/FALSE)
  RPRM_Command_Options_Get_LexParams = $0000006E; // Get Lex parameters JSON value (result = char **)
  RPRM_Command_Options_Set_LexParams = $0000006F; // Set Lex parameters JSON value (params = char *)
  RPRM_Command_Options_Get_StopOnBadInputImage = $00000070;
  // Get StopOnBadInputImage parameter value (result = DWORD*, FALSE by default)
  RPRM_Command_Options_Set_StopOnBadInputImage = $00000071;
  // Set StopOnBadInputImage parameter value (params = DWORD, TRUE/FALSE)
  RPRM_Command_Set_ProcessParametersJson = $00000072;
  // params = char* with process parameters JSON
  RPRM_Command_Options_Set_VideodetectionLowSensibility = $00000073;
  // Set VideodetectionLowSensibility parameter value (params = DWORD, TRUE/FALSE)
  RPRM_Command_Options_Set_TrustVideodetectionResult = $00000074;
  // Set TrustVideodetectionResult parameter value (params = DWORD, TRUE/FALSE)
  RPRM_Command_Device_Get_LED = $00000075; // get LED status. params = TIndicationLED*
  RPRM_Command_Get_DatabaseInfo = $00000076; // get database info. result = char** with database description JSON

  RPRM_Command_Device_Fingerprints_Scan = $00000077; // params - json with dllPath and scanParams
  RPRM_Command_Fingerprints_Compare = $00000078; // params - json with dllPath and comparisonParams
  RPRM_Command_Add_External_Containers = $00000079;
  RPRM_Command_Fingerprints_Search = $00000080; // params - json with dllPath and searchParams

 // enum eDeviceLimitations
    DL_NONE = $00000000;   ///< no limitations
    DL_USB2 = $00000001;   ///< device connected to USB 2.0 Port
    DL_32bit = $00000002;  ///< 32-bit platform


type
  PDetailsOptical = ^TDetailsOptical;

  TDetailsOptical = record
    overallStatus: UInt32;
    mrz: UInt32;
    text: UInt32;
    docType: UInt32;
    security: UInt32;
    imageQA: UInt32;
    expiry: UInt32;
    pagesCount: UInt32;
    vds: UInt32;
  end;

  PDetailsRFID = ^TDetailsRFID;

  TDetailsRFID = record
    overallStatus: UInt32;
    PA: UInt32;
    AA: UInt32;
    CA: UInt32;
    TA: UInt32;
    BAC: UInt32;
    PACE: UInt32;
  end;

  PStatus = ^TStatus;

  TStatus = record
    overallStatus: UInt32;
    detailsOptical: TDetailsOptical;
    optical: UInt32;
    detailsRFID: TDetailsRFID;
    rfid: UInt32;
    portrait: UInt32;
    stopList: UInt32;
  end;

implementation

end.
