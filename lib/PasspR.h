#ifndef PASSPR_H
#define PASSPR_H

#include "BaseType.h"

#ifdef __BORLANDC__ // if using a Borland compiler
    #pragma option -a4  //switch to double word alignment
#else   // !__BORLANDC__ if we're using some other compiler
    #pragma pack (push, before_passpr)
    #pragma pack (4)
#endif  // __BORLANDC__

#ifndef __cplusplus

#ifndef bool
#if __STDC_VERSION__ < 202311L
// c23 stdbool.h and bool macro replaced by keyword bool
#include <stdbool.h>
#endif // __STDC_VERSION__ < 202311L
#endif // !bool

#endif // !__cplusplus

typedef struct TRegulaDeviceProperties
{
    uint32_t DeviceID;              ///< eRPRM_DeviceTypes
    uint32_t Lights;                ///< eRPRM_Lights combination
    uint32_t SerialNumber;          ///< if available
    uint32_t Features;              ///< eRPRM_DeviceAdditionalFeatures
    uint32_t DeviceCtrl;            ///< eRPRM_DeviceControlTypes
    LPSTR DirectShowName;           ///< DirectShow device name
    LPSTR SystemUID;                ///< system unique device name
    LPSTR Name;                     ///< non-DirectShow device name
    uint32_t AvailableVideoModes;   ///< eRPRM_VideoModes combination
    uint64_t LabelSerialNumber;     ///< serial number on label
    LPSTR LabelSerialNumberStr;     ///< serial number on label (string)
    uint64_t CameraSerialNumber;    ///< camera HW serial number
    GUID CameraGuid;                ///< camera GUID
    uint32_t Capabilities;
    uint32_t Authenticity;
    uint32_t Database;
    time_t ValidUntil;
    bool WillConnect;
    uint32_t Limitations;           ///< eDeviceLimitations
} TRegulaDeviceProperties;

typedef enum eRPRM_DeviceAdditionalFeatures 
{
    RPRM_DeviceAdditionalFeature_None                 = 0x00000000,
    RPRM_DeviceAdditionalFeature_Accumulator          = 0x00000001,
    RPRM_DeviceAdditionalFeature_Indicators_Triple    = 0x00000002,
    RPRM_DeviceAdditionalFeature_VideoDetection       = 0x00000004,
    RPRM_DeviceAdditionalFeature_IRFilter             = 0x00000008,
    RPRM_DeviceAdditionalFeature_Indicators_Single    = 0x00000010,
    RPRM_DeviceAdditionalFeature_Indicators_Double    = 0x00000020,
    RPRM_DeviceAdditionalFeature_Indicators_Button    = 0x00000040,
    RPRM_DeviceAdditionalFeature_Indicators_Four      = 0x00000080,

    RPRM_DeviceAdditionalFeature_2SidedWhite          = 0x00000100,
    RPRM_DeviceAdditionalFeature_2SidedIR             = 0x00000200,
    RPRM_DeviceAdditionalFeature_2SidedUV             = 0x00000400,

    RPRM_DeviceAdditionalFeature_MagneticStripe       = 0x00001000,
    RPRM_DeviceAdditionalFeature_JPEGCompression      = 0x00002000,
    RPRM_DeviceAdditionalFeature_IntegratedDisplay    = 0x00004000,
    RPRM_DeviceAdditionalFeature_KeyboardLight        = 0x00008000,
    RPRM_DeviceAdditionalFeature_ExternalLight        = 0x00010000,
    RPRM_DeviceAdditionalFeature_FactoryCalibrated    = 0x00020000,
    RPRM_DeviceAdditionalFeature_DocumentSensor       = 0x00040000,
    RPRM_DeviceAdditionalFeature_DocSizeMode          = 0x00080000,
    RPRM_DeviceAdditionalFeature_LiveView             = 0x00100000,
    RPRM_DeviceAdditionalFeature_ExternalPower        = 0x00200000,
    RPRM_DeviceAdditionalFeature_LensR7628            = 0x00400000,
} eRPRM_DeviceAdditionalFeatures;

typedef enum eRPRM_DeviceControlTypes 
{
    RPRM_DeviceControlType_DirectShow = 1,
    RPRM_DeviceControlType_DirectIO   = 2,
    RPRM_DeviceControlType_Virtual    = 3,
} eRPRM_DeviceControlTypes;

typedef enum eRPRM_DeviceTypes 
{
    RPRM_DeviceType_Unknown       = 0x00000000,   // Unknown device
    RPRM_DeviceType_Virtual       = 0xFFFFFFFF,   // Virtual Device (Security Key)
        
    // 83x3
    RPRM_DeviceType_FX_8313_115 = 0x08313115,   // OV 1.3
    RPRM_DeviceType_FX_8333_115 = 0x08333115,   // OV 3.0
    RPRM_DeviceType_FX_8353_115 = 0x08353115,   // OV 5.1
    RPRM_DeviceType_FX_8383_115 = 0x08383115,   // Micron 3.1
    RPRM_DeviceType_FX_8883_115 = 0x08883115,   // Micron 9.0
    RPRM_DeviceType_FX_8853_115 = 0x08853115,   // Micron 5.0

    // 83x3M
    RPRM_DeviceType_FX_8303_115 = 0x08323115,   // Micron 3.1
    
    // 83x4 (83x3 + Bottom light table)
    RPRM_DeviceType_FX_8314_115 = 0x08314115,   // OV 1.3
    RPRM_DeviceType_FX_8334_115 = 0x08334115,   // OV 3.0
    RPRM_DeviceType_FX_8354_115 = 0x08354115,   // OV 3.0
    RPRM_DeviceType_FX_8384_115 = 0x08384115,   // Micron 3.1
    RPRM_DeviceType_FX_8884_115 = 0x08884115,   // Micron 9.0
    RPRM_DeviceType_FX_8854_115 = 0x08854115,   // Micron 5.0

    // 7007
    RPRM_DeviceType_FX_7107_115 = 0x07107115,   // OV 1.3 
    RPRM_DeviceType_FX_7117_115 = 0x07117115,   // OV 1.3 Modification 2   
    RPRM_DeviceType_FX_7307_115 = 0x07307115,   // OV 3.0 
    RPRM_DeviceType_FX_7317_115 = 0x07317115,   // OV 3.1 Modification 2   
    RPRM_DeviceType_FX_7507_115 = 0x07507115,   // OV 5.1
    RPRM_DeviceType_FX_7517_115 = 0x07517115,   // OV 5.1 Modification 2   
    RPRM_DeviceType_FX_7387_115 = 0x07387115,   // Micron 3.1
    RPRM_DeviceType_FX_7397_115 = 0x07397115,   // Micron 3.1 Modification 2   
    RPRM_DeviceType_FX_7887_115 = 0x07887115,   // Micron 9.0 
    RPRM_DeviceType_FX_7857_115 = 0x07857115,   // Micron 5.0

    // 8307
    RPRM_DeviceType_FX_8307     = 0x08307000,   // Micron 3.1 Mp (MRZ-only reader)

    // 7024
    RPRM_DeviceType_FX_7104_115 = 0x07104115,   // OV 1.3 
    RPRM_DeviceType_FX_7304_115 = 0x07304115,   // OV 3.0 
    RPRM_DeviceType_FX_7504_115 = 0x07504115,   // OV 5.0  
    RPRM_DeviceType_FX_7384_115 = 0x07384115,   // Micron 3.1 
    RPRM_DeviceType_FX_7884_115 = 0x07884115,   // Micron 9.0 
    RPRM_DeviceType_FX_7854_115 = 0x07854115,   // Micron 5.0 
    RPRM_DeviceType_FX_78A4_115 = 0x078A4115,   // Micron 10.0
    RPRM_DeviceType_FX_78E4_115 = 0x078E4115,   // Micron 14.0 

    // 7024 Lite functionality
    RPRM_DeviceType_FX_7104_Lite = 0x07104333,  // OV 1.3 
    RPRM_DeviceType_FX_7304_Lite = 0x07304333,  // OV 3.0 
    RPRM_DeviceType_FX_7504_Lite = 0x07504333,  // OV 5.1 
    RPRM_DeviceType_FX_7384_Lite = 0x07384333,  // Micron 3.1 
    RPRM_DeviceType_FX_7884_Lite = 0x07884333,  // Micron 9.0  
    RPRM_DeviceType_FX_7854_Lite = 0x07854333,  // Micron 5.0
    RPRM_DeviceType_FX_78A4_Lite = 0x078A4333,  // Micron 10.0
    RPRM_DeviceType_FX_78E4_Lite = 0x078E4333,  // Micron 14.0 

    // 70x3
    RPRM_DeviceType_FX_7103_115 = 0x07103115,   // OV 1.3
    RPRM_DeviceType_FX_7303_115 = 0x07303115,   // OV 3.0
    RPRM_DeviceType_FX_7503_115 = 0x07503115,   // OV 5.1
    RPRM_DeviceType_FX_7383_115 = 0x07383115,   // Micron 3.1
    RPRM_DeviceType_FX_7883_115  = 0x07883115,   // Micron 9.0 
    RPRM_DeviceType_FX_7853_115  = 0x07853115,   // Micron 5.0 
            
    // 4820
    RPRM_DeviceType_FX_4821      = 0x04821115,  // OV 1.3 
    RPRM_DeviceType_FX_4823      = 0x04823115,  // OV 3.0 
    RPRM_DeviceType_FX_4825      = 0x04825115,  // OV 5.1 
    RPRM_DeviceType_FX_4822      = 0x04822115,  // Micron 3.1 
    RPRM_DeviceType_FX_4828      = 0x04828115,  // Micron 9.0   
    RPRM_DeviceType_FX_4858      = 0x04858115,  // Micron 5.0 

    // 7008 
    RPRM_DeviceType_FX_7038        = 0x07038115,  //Micron 3.1
    RPRM_DeviceType_FX_7038_VB     = 0x17038115,  //Micron 3.1
    RPRM_DeviceType_FX_7058        = 0x07058115,  //Micron 5.0

    // 70x8M
    RPRM_DeviceType_FX_7058M        = 0x07058110,  //OV 5 Mp
    RPRM_DeviceType_FX_7058M_VB    = 0x17058110,  //OV 5 Mp
    RPRM_DeviceType_FX_7038M       = 0x07038110,  //AR 13 Mp

    // 70x4M small reader
    RPRM_DeviceType_FX_73x4M        = 0x07364115,  //Micron 3.1
    RPRM_DeviceType_FX_75x4M        = 0x07564115,  //Micron 5.0
    RPRM_DeviceType_FX_71x4M        = 0x07A64115,  //Micron 10.0
    RPRM_DeviceType_FX_76x4M        = 0x07664115,  //OV 5Mp
    RPRM_DeviceType_FX_78x4M        = 0x07864115,  //Micron 18Mp
    RPRM_DeviceType_FX_75A4M        = 0x075A4115,  //AR 5 Mp
    
    // 7308 
    RPRM_DeviceType_FX_7338        = 0x07338115,  //Micron 3.1

    // 72x3  ID1 reader with 2 cameras
    RPRM_DeviceType_FX_7253        = 0x07253115,  //OV 5.0 Mp with 2 cameras

    // 7017 simple reader with W
    RPRM_DeviceType_FX_7517		  = 0x07517000,    //Micron 5Mp
    RPRM_DeviceType_FX_7017        = 0x07017000,    //OV 5Mp

    // 71x7 MRZ reader
    RPRM_DeviceType_FX_7107 = 0x07107000,    //OV 5Mp
    RPRM_DeviceType_FX_7127 = 0x07127000,    //OV 5Mp

    // 7017D double reader master device
    RPRM_DeviceType_FX_7017D_M = 0x07017100,    //OV 5Mp

    // 7017D double reader slave device
    RPRM_DeviceType_FX_7017D_S = 0x07017200,    //OV 5Mp

    // 7027 simple reader with W rebel
    RPRM_DeviceType_FX_7027        = 0x07027000,    //OV 5Mp

    // 7074
    RPRM_DeviceType_EOS_7074_550 = 0x07074550,   // Cannon EOS 550D

    // 7084
    RPRM_DeviceType_EOS_7084_7   = 0x07084007,   // Cannon EOS 7D

    // 8803 - Banknote Reader
    RPRM_DeviceType_EOS_8803_100 = 0x08803100,   // Cannon EOS 100D

    // 8850 - Passport Reader 1/2 pages
    RPRM_DeviceType_EOS_8850_5	= 0x08850005,   // Cannon EOS 5DS (5DSR)

    // 8824 - Banknote Reader 
    RPRM_DeviceType_EOS_8824_80 = 0x08824080,   // Cannon EOS 80D

    // 8850M - Passport Reader 1/2 pages
    RPRM_DeviceType_EOS_8850M_9  = 0x08880009,   // Panasonic G9

    // 8850F - Passport Reader 2 pages
    RPRM_DeviceType_EOS_8850F_9 = 0x0888000A,   // Panasonic G9

    // 8880 - Passport Reader 1/2 pages
    RPRM_DeviceType_EOS_8880_1 = 0x08850001,   // Panasonic S1R

    // 8880F - Passport Reader 2 pages
    RPRM_DeviceType_EOS_8880F_1 = 0x08850002,   // Panasonic S1R

    // 88100 - Passport Reader 2 pages
    RPRM_DeviceType_EOS_88100 = 0x08850003,   // Fujifilm GFX100S

    // 88100F - Passport Reader 2 pages
    RPRM_DeviceType_EOS_88100F = 0x08850004,   // Fujifilm GFX100S

    // Camera Canon EOS
    RPRM_DeviceType_CanonEOS     = 0x20000001,    // Canon EOS series

    // Camera Panasonic
    RPRM_DeviceType_Panasonic	= 0x30000009,    // Panasonic series

    // Camera Fujifilm
    RPRM_DeviceType_Fujifilm     = 0x3000000A,    // Fujifilm GFX100S

    // 4107
    RPRM_DeviceType_FX_4137 = 0x04137115,  //Micron 3.1
    RPRM_DeviceType_FX_4157 = 0x04157115,  //Micron 5.0

    // 7310
    RPRM_DeviceType_Mobile_7310 = 0x07310000,  // 1110 Torch + Mobile device = mobile complex 7310

    // ARH
    RPRM_DeviceType_ARH = 0x10000001, 
    
    // 3M
    RPRM_DeviceType_3M = 0x10000002, 

    // Access-IS
    RPRM_DeviceType_AccessIs = 0x10000003,

    // TWAIN
    RPRM_DeviceType_TWAIN = 0x10000004, 

    // Bisys Korea
    RPRM_DeviceType_BK = 0x10000005, 

    // Bisys Korea New - 7303
    RPRM_DeviceType_73xx = 0x10000006,

    // e-seek M500
    RPRM_DeviceType_M500 = 0x10000007,

    // DESKO Penta
    RPRM_DeviceType_Desko = 0x10000008,

    // e-seek M600
    RPRM_DeviceType_M600 = 0x10000009,

    // DESKO Icon
    RPRM_DeviceType_DeskoIcon = 0x1000000A,

    // Xperix RealPass
    RPRM_DeviceType_XperixRealPass = 0x1000000B,

    // Wise Cube wsdef API
    RPRM_DeviceType_WiseCube_wsdef = 0x1000000C,

    //unused ----------------------------------------------------------------------------------------------
    RPRM_DeviceType_USB20_1     = 0x00200001,   // RdrPassport with USB2.0 camera
    RPRM_DeviceType_7004s       = 0x00200002,   // PR7004S    (W+, IR+)
    RPRM_DeviceType_7003_01     = 0x00200003,   // PR7003_01  (Wt, Ws, W+, IR+)
    RPRM_DeviceType_7003_110    = 0x07003110,   // PR7003_111 (Wt, Ws, W+, IRt, IRs, IR+, UV365)
    RPRM_DeviceType_7003_111    = 0x07003111,   // PR7003_111 (Wt, Ws, W+, IRt, IRs, IR+, UV365, 3MW1, 3MW2, 3MW+)
    RPRM_DeviceType_7004_100    = 0x07004100,   // PR7004_100 / PR7005_100 (W+, IR+)
    RPRM_DeviceType_7004_110    = 0x07004110,   // PR7004_110 / PR7005_110 (W+, IR+, UV)
    RPRM_DeviceType_70x4_111    = 0x07004111,   // PR70x4_111 / PR70x5_111 (W+, IR+, UV, 3MW+)
    RPRM_DeviceType_70x4_114    = 0x07004114,   // PR70x4_114 / PR70x5_114 (Wt, Ws, W+, IRt, IRs, IR+, UV365, 3MW1, 3MW2, 3MW+, 3MIR1, 3MIR2, 3MIR+)
    RPRM_DeviceType_70x4_115    = 0x07004115,   // PR70x4_115 / PR70x5_115 (W(m), IR(m), UV365, 3MW1, 3MW2, 3MW+)
    RPRM_DeviceType_8303_100    = 0x08303100,   // PR8303_100 (W+, IR+)
    RPRM_DeviceType_8303_110    = 0x08303110,   // PR8303_110 (W+, IR+, UV)
    RPRM_DeviceType_8303_111    = 0x08303111,   // PR8303_111 (W+, IR+, UV, 3M1, 3M2)
    RPRM_DeviceType_8303_114    = 0x08303114,   // PR8303_114 (W_down, W_up, W+, IR_down, IR_up, IR+, UV365, 3MW1, 3MW2, 3MW+)
    RPRM_DeviceType_8303_115    = 0x08303115,
    RPRM_DeviceType_8305        = 0x08305000,    // Mobile complex 8305 (Logitech QuickCam Pro web-camera)
    //unused ----------------------------------------------------------------------------------------------
} eRPRM_DeviceTypes;

typedef enum eRPRM_Lights 
{
    RPRM_Light_OFF               = 0x00000000, // Light Off
    RPRM_Light_OVI               = 0x00000001, // Light for OVI
    RPRM_Light_White_Top         = 0x00000002, // Light White Top
    RPRM_Light_White_Side        = 0x00000004, // Light White Side
    RPRM_Light_IR_Top            = 0x00000008, // Light IR Top
    RPRM_Light_IR_Side           = 0x00000010, // Light IR Side
    RPRM_Light_Transmitted       = 0x00000020, // transmitted light
    RPRM_Light_Transmitted_IR    = 0x00000040, // transmitted IR light
    RPRM_Light_UV                = 0x00000080, // Light UV
    RPRM_Light_IR_Luminescence   = 0x00000100, // Light Green Front
    RPRM_Light_AXIAL_White_Front = 0x00000200, // Light Axial White
    RPRM_Light_AXIAL_White_Left  = 0x00000400, // Light Axial White Left
    RPRM_Light_AXIAL_White_Right = 0x00000800, // Light Axial White Right
    RPRM_Light_IR_720            = 0x00001000, // Light IR 720 (mod. 8850)
    RPRM_Light_IR_940            = 0x00002000, // Light IR 940 (mod. 8803, 8850)
    RPRM_Light_Transmitted_IR940 = 0x00004000, // Light IR transmitted 940 (mod. 8803, 8850)
    RPRM_Light_IR_700            = 0x00008000, // Light IR 700 (mod. 8803)
    RPRM_Light_AntiStokes        = 0x00010000, // Anti Stokes light
    RPRM_Light_OVD_Left 		 = 0x00020000, // Light OVD Left
    RPRM_Light_OVD_Right		 = 0x00040000, // Light OVD Right
    RPRM_Light_UVC               = 0x00080000, // Light UVС 254 (88X0 devices)
    RPRM_Light_UVB               = 0x00100000, // Light UVB 313 (88X0 devices)
    RPRM_Light_White_Obl         = 0x00200000, // Light oblique white 
    RPRM_Light_White_Special     = 0x00400000, // Light White (special light source)
    RPRM_Light_White_Front       = 0x00800000, // Light White (single light source)
    RPRM_Light_IR_Front          = 0x01000000, // Light IR (single light source)
    RPRM_Light_White_Gray        = 0x02000000, // Light GRAY (grayscale made from WHITE)
    RPRM_Light_OVD               = 0x04000000, // Light OVD (hologram visualization)
    RPRM_Light_Videodetection    = 0x08000000, // Light Videodetection (for internal use only)
    RPRM_Light_IR_870_Obl        = 0x10000000, // Light IR 870 oblique

    //common aliases
    RPRM_Light_White_Full = (RPRM_Light_White_Top | RPRM_Light_White_Side),
    RPRM_Light_IR_Full = (RPRM_Light_IR_Top | RPRM_Light_IR_Side),
    RPRM_Light_AXIAL_White_Full = (RPRM_Light_AXIAL_White_Left | RPRM_Light_AXIAL_White_Right),
    RPRM_Light_White_UV = (RPRM_Light_White_Full | RPRM_Light_UV),

    //aliases for devices
    RPRM_Light_IR_870            = RPRM_Light_IR_Front, // Light IR 870 (mod. 8803)
    RPRM_Light_Holo              = RPRM_Light_OVD, // Light OVD (hologram visualization) - 8850
    RPRM_Light_White_Full_Holo   = RPRM_Light_White_Full | RPRM_Light_Holo,
    RPRM_Light_IR_Bottom         = RPRM_Light_Transmitted_IR,    // Light IR Bottom (mod. 8304)
    RPRM_Light_White_Bottom      = RPRM_Light_Transmitted,    // Light White Bottom (mod. 8304)  

    RPRM_Light_HR_Light = 0x40000000,
    RPRM_Light_HR_White = (RPRM_Light_HR_Light | RPRM_Light_White_Full),
    RPRM_Light_HR_UV = (RPRM_Light_HR_Light | RPRM_Light_UV),
    RPRM_Light_HR_IR = (RPRM_Light_HR_Light | RPRM_Light_IR_Full),

    //raw image format data
    RPRM_Light_RAW_Data          = 0x80000000, // RAW data from camera sensor (byte/pixel)
    RPRM_Light_RAW_Data_GRBG     = 0x90000000, // RAW data from camera sensor (byte/pixel)
    RPRM_Light_RAW_Data_GBRG     = 0xA0000000, // RAW data from camera sensor (byte/pixel)
    RPRM_Light_RAW_Data_RGGB     = 0xB0000000, // RAW data from camera sensor (byte/pixel)
    RPRM_Light_RAW_Data_BGGR     = 0xC0000000, // RAW data from camera sensor (byte/pixel)
    
} eRPRM_Lights;

typedef enum eRPRM_VideoModes 
{
    RPRM_VM_UNDEFINED = 0,

    RPRM_VM_1MP       = 0x00000001, // 1280 x 1024  - OV 1.3
                                    // 1024 x 768   - OV 3.0 & Micron 3.1
    RPRM_VM_3MP       = 0x00000002, // 2048 x 1536  - OV 3.0 & Micron 3.1
    RPRM_VM_5MP       = 0x00000004, // 2592 x 1944  - Micron 5MP - VM_QSXGA
    RPRM_VM_3MP_MRZ   = 0x00000010, // 1536 х 500   - RPRM_DeviceType_FX_8307
    RPRM_VM_9MP_2     = 0x00000020, // 1744 x 1308  - Micron 9.0
    RPRM_VM_9MP       = 0x00000040, // 3488 x 2616  - Micron 9.0
    RPRM_VM_5MP_1_3   = 0x00000080, // 1296 x 972   - skip 2*2 from VM_QSXGA
    RPRM_VM_14MP      = 0x00000100, // 4384 x 3288  - Micron 14 Mpx video mode
    RPRM_VM_FULL_HD   = 0x00000200, // 1920 x 1080  - FullHD video mode
    RPRM_VM_10MP      = 0x00000400, // 3664 x 2744  - Micron 10MP - VM_MP10
    RPRM_VM_10MP_2_5  = 0x00000800, // 1832 x 1372  - skip 2*2 from VM_MP10 = VM_MP2_5
    RPRM_VM_18MP      = 0x00001000, // 4896 x 3680 pixels 18 Mp video mode
    RPRM_VM_18MP_SB   = 0x00002000, // 2448 x 1840 pixels 18 Mp (SB 2X) video mode
    RPRM_VM_18MP_4X   = 0x00004000, // 1224 x 920 pixels 18 Mp (SB 4X) video mode
    RPRM_VM_13MP      = 0x00008000, // 4200 x 3120 pixels 13 Mp
    RPRM_VM_13MP_Q    = 0x00010000, // 2100 x 1560 pixels (1/4 (quarter) of 13 Mp)
    RPRM_VM_13MP_H    = 0x00020000, // 3360 x 2496 pixels (2/3 (half) of 13 Mp)
    RPRM_VM_50MP      = 0x01000000, // 8688 x 5792  - Canon EOS 5Ds/5Dsr 50 MP
    RPRM_VM_50MP_3    = 0x02000000, // 2172 x 1448  - Canon EOS 5Ds/5Dsr 3 MP
    RPRM_VM_24MP      = 0x04000000, // 6000 x 4000  - Canon 80D 24Mpx 
    RPRM_VM_24MP_1_5  = 0x08000000, // 1500 x 1000  - Canon 80D 24Mpx 1.5 MP
    RPRM_VM_20MP      = 0x00100000, // 5184 x 3888  - Panasonic G9 20Mp default 20MP + RPRM_VM_5MP_1_3
    RPRM_VM_80MP      = 0x00200000, // 10368x 7776  - Panasonic G9 max 80Mpx 80MP + RPRM_VM_5MP
    
    RPRM_VM_ID1xx_600 = 0x10000000, // 2300 x 1350  - ID1xx card reader 600 DPI mode
    RPRM_VM_300DPI    = 0x20000000, // 1150 x 675
    RPRM_VM_5MP_EOS   = 0x40000000, // 2592 x 1728  - Canon EOS 550D
    
    RPRM_VM_MAX
} eRPRM_VideoModes;

typedef enum CDocFormat 
{
    dfID1       = 0,    //  Document of ID-1 format
    dfID2       = 1,    //  Document of ID-2 format
    dfID3       = 2,    //  Document of ID-3 format - passport
    dfNON       = 3,    //  Document of unknown format
    dfA4        = 4,    //  A4
    dfID3_x2    = 5,    //  Open document of ID-3 format - open passport
    dfID2_Turkey = 6,
    dfID1_90    = 10,
    dfID1_180   = 11,
    dfID1_270   = 12,
    dfID2_180   = 13,
    dfID3_180   = 14,
    dfCustom    = 1000,
    dfPhoto     = 1001, // photo for document
    dfFlexible  = 1002,
    dfUnknown   = -1
} CDocFormat;

typedef enum eRPRM_Orientation
{
    Orientation_0 = 1,
    Orientation_90 = 8,
    Orientation_180 = 2,
    Orientation_270 = 4,
    Orientation_0_180 = Orientation_0 | Orientation_180,
    Orientation_90_270 = Orientation_90 | Orientation_270,
    Orientation_90_180_270 = Orientation_90 | Orientation_180 | Orientation_270,
    Orientation_0_90_180_270 = Orientation_0 | Orientation_90 | Orientation_180 | Orientation_270,
} eRPRM_Orientation;

typedef enum eRPRM_Capabilities
{
    RPRM_Capabilities_Empty                       = 0x00000000,
    RPRM_Capabilities_Scan                        = 0x00000001,
    RPRM_Capabilities_SaveFiles                   = 0x00000002,
    RPRM_Capabilities_LocateDocument              = 0x00000004,
    RPRM_Capabilities_MRZ_OCR                     = 0x00000008,
    RPRM_Capabilities_Visual_OCR                  = 0x00000010,
    RPRM_Capabilities_BarCodes                    = 0x00000020,
    RPRM_Capabilities_MRZ_TestQuality             = 0x00000040,
    RPRM_Capabilities_FDS                         = 0x00000080,
    RPRM_Capabilities_ImageDistortionCompensation = 0x00000100,
    RPRM_Capabilities_OCR_Analyze                 = 0x00000200,
    RPRM_Capabilities_Authenticity                = 0x00000400,

    RPRM_Capabilities_RAW_ImageData               = 0x00000800,
    RPRM_Capabilities_RAW_CustomDemosaic          = 0x00001000,

    RPRM_Capabilities_DocumentType                = 0x00002000,
    RPRM_Capabilities_Visual_Graphics             = 0x00004000,

    RPRM_Capabilities_Expert_Analyze              = 0x00008000,
    RPRM_Capabilities_ColorCompensation           = 0x00010000,

    RPRM_Capabilities_BarcodesExtended            = 0x00020000,

    RPRM_Capabilities_GlareCompensation           = 0x00040000,

    RPRM_Capabilities_RFID                        = 0x00080000,
    RPRM_Capabilities_BankCard                    = 0x00100000,
    RPRM_Capabilities_LiveFaceComparison          = 0x00200000,
    RPRM_Capabilities_FaceSearch                  = 0x00400000,
    RPRM_Capabilities_ServerSideRFID              = 0x02000000,

    RPRM_Capabilities_FingerprintComparison       = 0x04000000,
    RPRM_Capabilities_FingerprintSearch           = 0x08000000,
    
    RPRM_Capabilities_ProcessImages               = 0x10000000,

    RPRM_Capabilities_Custom2                     = 0x20000000,
    RPRM_Capabilities_Custom3                     = 0x40000000,
    RPRM_Capabilities_Custom4                     = 0x80000000,
    RPRM_Capabilities_Max                         = 0xFFFFFFFF,
} eRPRM_Capabilities;

typedef enum eRPRM_GetImage_Modes
{
    RPRM_GetImage_Modes_Empty                   = 0x00000000,
    RPRM_GetImage_Modes_GetUncroppedImages      = 0x00000001, ///< to receive unprocessed images
    RPRM_GetImage_Modes_ReceiveAllScannedImages = 0x00000002,
    RPRM_GetImage_Modes_OCR_Visual_Graphics     = 0x00000004, ///< read document visual zone - graph fields only
    RPRM_GetImage_Modes_GetImages               = 0x00000008, ///< no additional actions, to receive preset images
    RPRM_GetImage_Modes_LocateDocument          = 0x00000010, ///< locate document page bounds, crop images
    RPRM_GetImage_Modes_DocumentType            = 0x00000020, ///< try to determine document type
    RPRM_GetImage_Modes_OCR_MRZ                 = 0x00000040, //locate MRZ and read it       
    RPRM_GetImage_Modes_OCR_Visual_Text         = 0x00000080, ///< read document visual zone - text fields only
    RPRM_GetImage_Modes_OCR_Visual              = RPRM_GetImage_Modes_OCR_Visual_Graphics | RPRM_GetImage_Modes_OCR_Visual_Text,
    RPRM_GetImage_Modes_OCR_BarCodes            = 0x00000100, ///< locate and read barcodes
    RPRM_GetImage_Modes_Authenticity            = 0x00000200,
    RPRM_GetImage_Modes_OCR_TestMRZQuality      = 0x00000400, ///< test MRZ printing quality
    RPRM_GetImage_Modes_RAW_Data                = 0x00000800, ///< Bayer matrix + unprocessed images
    RPRM_GetImage_Modes_RAW_Data_Only           = 0x00001000, ///< only Bayer matrix
    RPRM_GetImage_Modes_NoColorCompensation     = 0x00002000, ///< don't correct brightness and color balance
    RPRM_GetImage_Modes_NoDistortionCompensation= 0x00004000, ///< don't correct distortion
    RPRM_GetImage_Modes_DetectDocument          = 0x00008000, ///< get document detection position 
    RPRM_GetImage_Modes_ImageQA                 = 0x00010000, ///< make image QA results (glare, focus) 
    
    RPRM_GetImage_Modes_Holo                    = 0x00020000,
    RPRM_GetImage_Modes_FaceDetect              = 0x00040000,
    RPRM_GetImage_Modes_CheckVDS                = 0x00080000, ///< check VDS, if available
    RPRM_GetImage_Modes_Reserved12              = 0x00100000,
    RPRM_GetImage_Modes_Reserved13              = 0x00200000,
    RPRM_GetImage_Modes_Reserved14              = 0x00400000,
    RPRM_GetImage_Modes_Reserved15              = 0x00800000,
    RPRM_GetImage_Modes_Reserved16              = 0x01000000,
    RPRM_GetImage_Modes_Reserved17              = 0x02000000,
    RPRM_GetImage_Modes_Reserved18              = 0x04000000,
    RPRM_GetImage_Modes_Reserved19              = 0x08000000,

    RPRM_GetImage_Modes_Custom1                 = 0x10000000,
    RPRM_GetImage_Modes_Custom2                 = 0x20000000,
    RPRM_GetImage_Modes_Custom3                 = 0x40000000,
    RPRM_GetImage_Modes_Custom4                 = 0x80000000,
} eRPRM_GetImage_Modes;

/**
 * @brief Enumeration of device limitations
 */
typedef enum eDeviceLimitations
{
    DL_NONE = 0x00000000,   ///< no limitations
    DL_USB2 = 0x00000001,   ///< device connected to USB 2.0 Port
    DL_32bit = 0x00000002,  ///< 32-bit platform
} eDeviceLimitations;

//****************************************************************************
//** result types
//****************************************************************************
typedef enum eRPRM_ResultType
{
    RPRM_ResultType_Empty                       = 0,
    RPRM_ResultType_RawImage                    = 1,            // TRawImageContainer
    RPRM_ResultType_FileImage                   = 2,            // byte array
    RPRM_ResultType_MRZ_OCR_Extended            = 3,            // TDocVisualExtendedInfo
    RPRM_ResultType_BarCodes                    = 5,            // TDocBarCodeInfo
    RPRM_ResultType_Graphics                    = 6,            // TDocGraphicsInfo
    RPRM_ResultType_MRZ_TestQuality             = 7,            // TDocMRZTestQuality
    RPRM_ResultType_DocumentTypesCandidates     = 8,            // TCandidatesListContainer
    RPRM_ResultType_ChosenDocumentTypeCandidate = 9,            // TOneCandidate
    RPRM_ResultType_DocumentsInfoList           = 10,           // not used. TListDocsInfo
    RPRM_ResultType_OCRLexicalAnalyze           = 15,           // TListVerifiedFields
    RPRM_ResultType_RawUncroppedImage           = 16,           // TRawImageContainer
    RPRM_ResultType_Visual_OCR_Extended         = 17,           // TDocVisualExtendedInfo
    RPRM_ResultType_BarCodes_TextData           = 18,           // TDocVisualExtendedInfo
    RPRM_ResultType_BarCodes_ImageData          = 19,           // TDocGraphicsInfo
    RPRM_ResultType_Authenticity                = 20,           // TAuthenticityCheckList


    //-------------------- unused  ---------------
    RPRM_ResultType_ExpertAnalyze               = 21,           // not used
    RPRM_ResultType_OCRLexicalAnalyzeEx         = 22,           // not used
    //-------------------- unused  ---------------

    RPRM_ResultType_EOSImage                    = 23,           // TRawImageContainer for EOS full-size images
    RPRM_ResultType_Bayer                       = 24,           // TRawImageContainer
    RPRM_ResultType_MagneticStripe              = 25,           // byte array
    RPRM_ResultType_MagneticStripe_TextData     = 26,           // TDocVisualExtendedInfo
    RPRM_ResultType_FieldFileImage              = 27,           // byte array
    RPRM_ResultType_DatabaseCheck               = 28,           // TDatabaseCheck
    RPRM_ResultType_FingerprintTemplateISO      = 29,           // byte array

    RPRM_ResultType_InputImageQuality           = 30,           // TImageQualityCheckList
    RPRM_ResultType_DeviceInfo                  = 31,           // TRegulaDeviceProperties
    RPRM_ResultType_LivePortrait                = 32,           // TDocGraphicsInfo
    RPRM_ResultType_Status                      = 33,           // TStatus
    RPRM_ResultType_Portrait_Comparison         = 34,           // TAuthenticityCheckList
    RPRM_ResultType_ExtPortrait                 = 35,           // TDocGraphicsInfo
    RPRM_ResultType_Text                        = 36,           // TTextResult
    RPRM_ResultType_Images                      = 37,           // TImagesResult
    RPRM_ResultType_FingerPrints                = 38,           // TDocGraphicsInfo 
    RPRM_ResultType_FingerPrint_Comparison      = 39,           // TAuthenticityCheckList 
    RPRM_ResultType_FaceDatabaseCheck           = 40,           // TDatabaseCheck
    RPRM_ResultType_FingerprintDatabaseCheck    = 41,           // TDatabaseCheck
    RPRM_ResultType_BarcodePosition             = 62,           // TBoundsResult;
    RPRM_ResultType_BSI_XML_v2                  = 73,           // BSI XML v2 result. buffer = char* - pointer to BSI XML v2
    RPRM_ResultType_DocumentPosition            = 85,           // TBoundsResult
    RPRM_ResultType_BSI_XML                     = 92,           // BSI XML result. buffer = char* - pointer to BSI XML
    RPRM_ResultType_Custom                      = 100,
} eRPRM_ResultType;

//****************************************************************************
//**  result container structure
//****************************************************************************
typedef struct TResultContainer
{
    uint32_t  result_type;     // eRPRM_ResultType
    uint32_t  light;          // eRPRM_Lights
    uint32_t  buf_length;
    void  *buffer;
    uint32_t  XML_length;
    BYTE  *XML_buffer;
    uint32_t  list_idx;
    uint32_t  page_idx;
} TResultContainer;

typedef struct TResultContainerList
{
    uint32_t Count;
    TResultContainer *List;
} TResultContainerList;

typedef struct TResultContainerPointersList
{
    uint32_t Count;
    TResultContainer **List;
} TResultContainerPointersList;

//****************************************************************************
//**  result RPRM_ResultType_RawImage
//****************************************************************************
// 'TResultContainer.buffer' = TRawImageContainer *

typedef struct TRawImageContainer
{
    BITMAPINFO *bmi;    //with valid bmiColors[256]
    BYTE *bits;         //image bits array, uint32_t aligned
} TRawImageContainer;

typedef struct TRawImageContainerList
{
    int    Count;
    TRawImageContainer* Images;
} TRawImageContainerList;

//****************************************************************************
//**  result RPRM_ResultType_FileImage
//****************************************************************************
// TResultContainer.buffer points to the whole file image buffer (BYTE *) of length TResultContainer.buf_length

//********************************************************************************************************
//**  result RPRM_ResultType_Visual_OCR and RPRM_ResultType_MRZ_OCR_Parsed
//********************************************************************************************************
// 'TResultContainer.buffer' = TDocVisualInfo *

typedef enum eVisualFieldType
{
    ft_Document_Class_Code                = 0,
    ft_Issuing_State_Code                = 1,
    ft_Document_Number                    = 2,
    ft_Date_of_Expiry                    = 3,
    ft_Date_of_Issue                    = 4,
    ft_Date_of_Birth                    = 5,
    ft_Place_of_Birth                    = 6,
    ft_Personal_Number                    = 7,
    ft_Surname                            = 8,
    ft_Given_Names                        = 9,
    ft_Mothers_Name                        = 10,
    ft_Nationality                        = 11,
    ft_Sex                                = 12,  
    ft_Height                            = 13,  
    ft_Weight                            = 14,  
    ft_Eyes_Color                        = 15,  
    ft_Hair_Color                        = 16,  
    ft_Address                            = 17,
    ft_Donor                            = 18,  
    ft_Social_Security_Number            = 19,
    ft_DL_Class                            = 20,
    ft_DL_Endorsed                        = 21,
    ft_DL_Restriction_Code                = 22,  
    ft_DL_Under_21_Date                    = 23,  
    ft_Authority                        = 24,
    ft_Surname_And_Given_Names            = 25,
    ft_Nationality_Code                    = 26,
    ft_Passport_Number                    = 27,
    ft_Invitation_Number                = 28,
    ft_Visa_ID                            = 29,
    ft_Visa_Class                        = 30,
    ft_Visa_SubClass                    = 31,
    ft_MRZ_String1                        = 32,
    ft_MRZ_String2                        = 33,
    ft_MRZ_String3                        = 34,
    ft_MRZ_Type                            = 35,
    ft_Optional_Data                    = 36,
    ft_Document_Class_Name                = 37,
    ft_Issuing_State_Name                = 38,
    ft_Place_of_Issue                    = 39,
    ft_Document_Number_Checksum            = 40,
    ft_Date_of_Birth_Checksum            = 41,
    ft_Date_of_Expiry_Checksum            = 42,
    ft_Personal_Number_Checksum            = 43,
    ft_FinalChecksum                    = 44,
    ft_Passport_Number_Checksum         = 45,
    ft_Invitation_Number_Checksum       = 46,
    ft_Visa_ID_Checksum                 = 47,
    ft_Surname_And_Given_Names_Checksum = 48,
    ft_Visa_Valid_Until_Checksum        = 49,
    ft_Other                            = 50,
    ft_MRZ_Strings                        = 51,
    ft_Name_Suffix                        = 52,
    ft_Name_Prefix                        = 53,
    ft_Date_of_Issue_Checksum            = 54,  
    ft_Date_of_Issue_CheckDigit            = 55,  
    ft_Document_Series                    = 56,
    ft_RegCert_RegNumber                = 57,
    ft_RegCert_CarModel                    = 58,
    ft_RegCert_CarColor                    = 59,
    ft_RegCert_BodyNumber                = 60,
    ft_RegCert_CarType                    = 61,
    ft_RegCert_MaxWeight                = 62,
    ft_Reg_Cert_Weight                    = 63,
    ft_Address_Area                        = 64,
    ft_Address_State                    = 65,
    ft_Address_Building                    = 66,
    ft_Address_House                    = 67,
    ft_Address_Flat                        = 68,
    ft_Place_of_Registration            = 69,
    ft_Date_of_Registration                = 70,    
    ft_Resident_From                    = 71,    
    ft_Resident_Until                    = 72,    
    ft_Authority_Code                    = 73,
    ft_Place_of_Birth_Area                = 74,    
    ft_Place_of_Birth_StateCode            = 75,
    ft_Address_Street                    = 76,    // Street portion of the card holder address.
    ft_Address_City                        = 77,    // City portion of the card holder address.
    ft_Address_Jurisdiction_Code        = 78,    // Jurisdiction Code - State portion of the card holder address.
    ft_Address_Postal_Code                = 79,    // Postal code portion of the card holder address in the U.S. and Canada.
    // MRZ recognized check digits
    ft_Document_Number_CheckDigit           = 80,
    ft_Date_of_Birth_CheckDigit             = 81,
    ft_Date_of_Expiry_CheckDigit            = 82,
    ft_Personal_Number_CheckDigit           = 83,
    ft_FinalCheckDigit                      = 84,
    ft_Passport_Number_CheckDigit           = 85,
    ft_Invitation_Number_CheckDigit         = 86,
    ft_Visa_ID_CheckDigit                   = 87,
    ft_Surname_And_Given_Names_CheckDigit   = 88,
    ft_Visa_Valid_Until_CheckDigit          = 89,
    ft_Permit_DL_Class                    = 90,   // Driver Permit Classification Code
    ft_Permit_Date_of_Expiry            = 91,   // Driver Permit Expiration Date
    ft_Permit_Identifier                = 92,   // Permit Identifier
    ft_Permit_Date_of_Issue                = 93,   // Driver Permit Issue Date
    ft_Permit_Restriction_Code            = 94,   // Driver Permit Restriction Code
    ft_Permit_Endorsed                    = 95,   // Driver Permit Endorsement Code
    ft_Issue_Timestamp                    = 96,    //A string used by some jurisdictions to validate the
    ft_Number_of_Duplicates                = 97,
    ft_Medical_Indicator_Codes            = 98,
    ft_Non_Resident_Indicator            = 99,    //Used by some jurisdictions to indicate holder of the
    ft_Visa_Type                        = 100,
    ft_Visa_Valid_From                    = 101,
    ft_Visa_Valid_Until                    = 102,
    ft_Duration_of_Stay                    = 103,
    ft_Number_of_Entries                = 104,
    ft_Day                                = 105,
    ft_Month                            = 106,
    ft_Year                                = 107,
    ft_Unique_Customer_Identifier        = 108,  //A number or alphanumeric string used by some
                                                //jurisdictions to identify a
                                                //"customer" across multiple data bases.
    ft_Commercial_Vehicle_Codes            = 109,     // Federal Commercial Vehicle Codes
                                                // Federally established codes for vehicle
                                                // categories, endorsements, and restrictions that
                                                // are generally applicable to commercial motor
                                                // vehicles. If the vehicle is not a commercial
                                                // vehicle, "NONE" is to be entered.
    // AKA (also known as)
    ft_AKA_Date_of_Birth                = 110,
    ft_AKA_Social_Security_Number        = 111,
    ft_AKA_Surname                        = 112,
    ft_AKA_Given_Names                    = 113,
    ft_AKA_Name_Suffix                    = 114,
    ft_AKA_Name_Prefix                    = 115,
    ft_Mailing_Address_Street             = 116, // (Mailing Street Address)
    ft_Mailing_Address_City               = 117, // (Mailing City Address)
    ft_Mailing_Address_Jurisdiction_Code  = 118, // (Mailing Jurisdiction Code - State portion of the cardholder address)
    ft_Mailing_Address_Postal_Code        = 119, // (Mailing Postal code portion of the cardholder address)
    ft_Audit_Information                  = 120, // (Audit information)
    ft_Inventory_Number                   = 121, // (Inventory control number)
    ft_Race_Ethnicity                     = 122, // (Race/ethnicity)
    ft_Jurisdiction_Vehicle_Class         = 123, // (Jurisdiction Vehicle Class)
    ft_Jurisdiction_Endorsement_Code      = 124, // (Jurisdiction Endorsement Code)
    ft_Jurisdiction_Restriction_Code      = 125, // (Jurisdiction Restriction Code)
    ft_Family_Name                   = 126,
    ft_Given_Names_RUS               = 127,
    ft_Visa_ID_RUS                   = 128,
    ft_Fathers_Name                  = 129,    
    ft_Fathers_Name_RUS              = 130,
    ft_Surname_And_Given_Names_RUS   = 131,
    ft_Place_Of_Birth_RUS            = 132,
    ft_Authority_RUS                 = 133,
    ft_Issuing_State_Code_Numeric    = 134,
    ft_Nationality_Code_Numeric      = 135, 
    ft_Engine_Power                  = 136,
    ft_Engine_Volume                 = 137,
    ft_Chassis_Number                = 138,
    ft_Engine_Number                 = 139,
    ft_Engine_Model                  = 140,
    ft_Vehicle_Category              = 141,
    ft_Identity_Card_Number          = 142, // add 05/06/2008 for China Passport #1
    ft_Control_No                    = 143, // add 24/09/2008 for Malaysia Passport #2
    ft_Parrent_s_Given_Names         = 144, // add 17/10/2008 for Spanish documents
    ft_Second_Surname                = 145, // add 17/10/2008 for Spanish documents
    ft_Middle_Name                   = 146, // add 16/11/2009 for Philippine passport #3

    // add 25/08/2010 for Poland Registration Certificate (Vehicle)
    ft_RegCert_VIN                   = 147, // Vehicle Identification Number
    ft_RegCert_VIN_CheckDigit        = 148, // VIN Check Digit
    ft_RegCert_VIN_Checksum          = 149, // VIN CheckSum Check Result
    ft_Line1_CheckDigit              = 150, // Line 1 Check Digit
    ft_Line2_CheckDigit              = 151, // Line 2 Check Digit
    ft_Line3_CheckDigit              = 152, // Line 3 Check Digit
    ft_Line1_Checksum                = 153, // Line 1 CheckSum Check Result
    ft_Line2_Checksum                = 154, // Line 2 CheckSum Check Result
    ft_Line3_Checksum                = 155, // Line 3 CheckSum Check Result
    ft_RegCert_RegNumber_CheckDigit  = 156, // Registration number (License plates) Check Digit
    ft_RegCert_RegNumber_Checksum    = 157, // Registration number (License plates) CheckSum Check Result
    ft_RegCert_Vehicle_ITS_Code      = 158, // Vehicle ITS code (from the catalog of the Motor Transport Institute).
    ft_Card_Access_Number             = 159, // Card Access Number.
    ft_Marital_Status                 = 160,
    ft_Company_Name                     = 161,

    ft_Special_Notes                 = 162,
    ft_Surname_of_Spose                 = 163,
    ft_Tracking_Number                 = 164,
    ft_Booklet_Number                 = 165,
    ft_Children                         = 166,
    ft_Copy                             = 167,
    ft_Serial_Number                 = 168,
    ft_Dossier_Number                 = 169,
    ft_AKA_Surname_And_Given_Names     = 170,
    ft_Territorial_Validity             = 171,
    ft_MRZ_Strings_With_Correct_CheckSums = 172, // [deprecated] (for Reader Provider)
    ft_DL_CDL_Restriction_Code         = 173,
    ft_DL_Under_18_Date                 = 174,
    ft_DL_Record_Created             = 175,
    ft_DL_Duplicate_Date             = 176,
    ft_DL_Iss_Type                     = 177,
    ft_Military_Book_Number             = 178,
    ft_Destination                     = 179,
    ft_Blood_Group                     = 180,
    ft_Sequence_Number                 = 181,
    ft_RegCert_BodyType                 = 182,
    ft_RegCert_CarMark                 = 183,
    ft_Transaction_Number             = 184,
    ft_Age                             = 185,
    ft_Folio_Number                     = 186,
    ft_Voter_Key                     = 187,
    ft_Address_Municipality             = 188,
    ft_Address_Location                 = 189,
    ft_Section                         = 190,
    ft_OCR_Number                     = 191,
    ft_Federal_Elections             = 192,
    ft_Reference_Number                 = 193,
    ft_Optional_Data_Checksum        = 194,  // for Russian National Passport
    ft_Optional_Data_CheckDigit      = 195,  // for Russian National Passport
    ft_Visa_Number                   = 196,  // for Visas
    ft_Visa_Number_Checksum          = 197,  // for Visas
    ft_Visa_Number_CheckDigit        = 198,  // for Visas
    ft_Voter                         = 199,
    ft_Previous_Type                 = 200,

    ft_FieldFromMRZ                  = 220,
    ft_CurrentDate                   = 221,
    
    ft_Status_Date_of_Expiry         = 251,
    ft_Banknote_Number                 = 252,
    ft_CSC_Code                         = 253,

    ft_Artistic_Name                 = 254,
    ft_Academic_Title                 = 255,
    ft_Address_Country                 = 256,
    ft_Address_Zipcode                 = 257,

    ft_eID_Residence_Permit1         = 258,
    ft_eID_Residence_Permit2         = 259,
    ft_eID_PlaceOfBirth_Street         = 260,
    ft_eID_PlaceOfBirth_City         = 261,
    ft_eID_PlaceOfBirth_State         = 262,
    ft_eID_PlaceOfBirth_Country         = 263,
    ft_eID_PlaceOfBirth_Zipcode         = 264,
    ft_CDL_Class                     = 265,
    ft_DL_Under_19_Date                 = 266,
    ft_Weight_pounds                 = 267,
    ft_Limited_Duration_Document_Indicator = 268,
    ft_Endorsement_Expiration_Date     = 269,
    ft_Revision_Date                 = 270,
    ft_Compliance_Type                 = 271,
    ft_Family_name_truncation         = 272,
    ft_First_name_truncation         = 273,
    ft_Middle_name_truncation         = 274,
    ft_Exam_Date                     = 275,
    ft_Organization                     = 276,
    ft_Department                     = 277,
    ft_Pay_Grade                     = 278,
    ft_Rank                             = 279,
    ft_Benefits_Number                 = 280,
    ft_Sponsor_Service                 = 281,
    ft_Sponsor_Status                 = 282,
    ft_Sponsor                         = 283,
    ft_Relationship                     = 284,
    ft_USCIS                         = 285,
    ft_Category                         = 286,
    ft_Conditions                     = 287,
    ft_Identifier                     = 288,     // IDL MRZ: ISO/IEC 18013-3:2009/Amd.1:2012(E)
    ft_Configuration                 = 289,     // IDL MRZ: ISO/IEC 18013-3:2009/Amd.1:2012(E)
    ft_Discretionary_data             = 290,     // IDL MRZ: ISO/IEC 18013-3:2009/Amd.1:2012(E)
    // add 12/09/2012 for Macau IDCard
    ft_Line1_Optional_Data             = 291,
    ft_Line2_Optional_Data             = 292,
    ft_Line3_Optional_Data             = 293,
    ft_EQV_Code                         = 294,
    ft_ALT_Code                         = 295,
    ft_Binary_Code                     = 296,
    ft_Pseudo_Code                     = 297,
    ft_Fee                             = 298,
    ft_Stamp_Number                     = 299,

    // from RFID.h enum eRFID_VisualFieldType
    ft_SBH_SecurityOptions              = 300,
    ft_SBH_IntegrityOptions             = 301,
    ft_Date_of_Creation                 = 302,
    ft_Validity_Period                  = 303,
    ft_Patron_Header_Version            = 304,
    ft_BDB_Type                         = 305,
    ft_Biometric_Type                   = 306,
    ft_Biometric_Subtype                = 307,
    ft_Biometric_ProductID              = 308,
    ft_Biometric_Format_Owner           = 309,
    ft_Biometric_Format_Type            = 310,
    //DG11
    ft_Phone                            = 311,
    ft_Profession                       = 312,
    ft_Title                            = 313,
    ft_Personal_Summary                 = 314,
    ft_Other_Valid_ID                   = 315,
    ft_Custody_Info                     = 316,
    ft_Other_Name                       = 317,
    //DG12
    ft_Observations                     = 318,
    ft_Tax                              = 319,
    ft_Date_of_Personalization          = 320,
    ft_Personalization_SN               = 321,
    ft_OtherPerson_Name                 = 322,
    //DG16
    ft_PersonToNotify_Date_of_Record    = 323,
    ft_PersonToNotify_Name              = 324,
    ft_PersonToNotify_Phone             = 325,
    ft_PersonToNotify_Address           = 326,
    //DS certificate
    ft_DS_Certificate_Issuer            = 327,
    ft_DS_Certificate_Subject           = 328,
    ft_DS_Certificate_ValidFrom         = 329,
    ft_DS_Certificate_ValidTo           = 330,
    //eDL, DG1
    ft_VRC_DataObject_Entry             = 331,   //category of vehicle/restriction/condition Data Object entry
    ft_TypeApprovalNumber               = 332,   //0x5F01 tag contents
    //eDL, DG3
    ft_AdministrativeNumber             = 333,
    ft_DocumentDiscriminator            = 334,
    ft_DataDiscriminator                = 335,
    ft_ISO_Issuer_ID_Number             = 336,
    // DTC
    ft_DTC_Version                      = 337,
    ft_DTC_ID                           = 338,
    ft_DTC_DateOfExpiry                 = 339,
    //end eRFID_VisualFieldType

    ft_GNIB_Number                     = 340,
    ft_Dept_Number                     = 341,
    ft_Telex_Code                     = 342,
    ft_Allergies                     = 343,
    ft_Sp_Code                         = 344,
    ft_Court_Code                     = 345,
    ft_Cty                             = 346,
    ft_Sponsor_SSN                     = 347,
    ft_DoD_Number                     = 348,
    ft_MC_Novice_Date                 = 349,
    ft_DUF_Number                     = 350,
    ft_AGY                             = 351,
    ft_PNR_Code                         = 352,
    ft_From_Airport_Code             = 353,
    ft_To_Airport_Code                 = 354,
    ft_Flight_Number                 = 355,
    ft_Date_of_Flight                 = 356,
    ft_Seat_Number                     = 357,
    ft_Date_of_Issue_Boarding_Pass   = 358,
    ft_CCW_Until                     = 359,
    ft_Reference_Number_Checksum        = 360,      // for USA DL
    ft_Reference_Number_CheckDigit      = 361,      // for USA DL
    ft_Room_Number                     = 362,
    ft_Religion                         = 363,
    ft_RemainderTerm                 = 364,
    ft_Electronic_Ticket_Indicator     = 365,
    ft_Compartment_Code                 = 366,
    ft_CheckIn_Sequence_Number         = 367,
    ft_Airline_Designator_of_boarding_pass_issuer = 368,
    ft_Airline_Numeric_Code             = 369,
    ft_Ticket_Number                 = 370,
    ft_Frequent_Flyer_Airline_Designator = 371,
    ft_Frequent_Flyer_Number         = 372,
    ft_Free_Baggage_Allowance         = 373,
    ft_PDF417Codec                 = 374,
    ft_Identity_Card_Number_Checksum    = 375,      // for Spain Residence permit (1997-2010) Side B
    ft_Identity_Card_Number_CheckDigit  = 376,      // for Spain Residence permit (1997-2010) Side B
    ft_Veteran                            = 377,        // Veteran indicator - for USA DL
    ft_DLClassCode_A1_From                =378,
    ft_DLClassCode_A1_To                =379,
    ft_DLClassCode_A1_Notes                =380,
    ft_DLClassCode_A_From                =381,
    ft_DLClassCode_A_To                    =382,
    ft_DLClassCode_A_Notes                =383,
    ft_DLClassCode_B_From                =384,
    ft_DLClassCode_B_To                    =385,
    ft_DLClassCode_B_Notes                =386,
    ft_DLClassCode_C1_From                =387,
    ft_DLClassCode_C1_To                =388,
    ft_DLClassCode_C1_Notes                =389,
    ft_DLClassCode_C_From                =390,
    ft_DLClassCode_C_To                    =391,
    ft_DLClassCode_C_Notes                =392,
    ft_DLClassCode_D1_From                =393,
    ft_DLClassCode_D1_To                =394,
    ft_DLClassCode_D1_Notes                =395,
    ft_DLClassCode_D_From                =396,
    ft_DLClassCode_D_To                    =397,
    ft_DLClassCode_D_Notes                =398,
    ft_DLClassCode_BE_From                =399,
    ft_DLClassCode_BE_To                =400,
    ft_DLClassCode_BE_Notes                =401,
    ft_DLClassCode_C1E_From                =402,
    ft_DLClassCode_C1E_To                =403,
    ft_DLClassCode_C1E_Notes            =404,
    ft_DLClassCode_CE_From                =405,
    ft_DLClassCode_CE_To                =406,
    ft_DLClassCode_CE_Notes                =407,
    ft_DLClassCode_D1E_From                =408,
    ft_DLClassCode_D1E_To                =409,
    ft_DLClassCode_D1E_Notes            =410,
    ft_DLClassCode_DE_From                =411,
    ft_DLClassCode_DE_To                =412,
    ft_DLClassCode_DE_Notes                =413,
    ft_DLClassCode_M_From                =414,
    ft_DLClassCode_M_To                    =415,
    ft_DLClassCode_M_Notes                =416,
    ft_DLClassCode_L_From                =417,
    ft_DLClassCode_L_To                    =418,
    ft_DLClassCode_L_Notes                =419,
    ft_DLClassCode_T_From                =420,
    ft_DLClassCode_T_To                    =421,
    ft_DLClassCode_T_Notes                =422,
    ft_DLClassCode_AM_From                =423,
    ft_DLClassCode_AM_To                =424,
    ft_DLClassCode_AM_Notes                =425,
    ft_DLClassCode_A2_From                =426,
    ft_DLClassCode_A2_To                =427,
    ft_DLClassCode_A2_Notes                =428,
    ft_DLClassCode_B1_From                =429,
    ft_DLClassCode_B1_To                =430,
    ft_DLClassCode_B1_Notes                =431,
    ft_Surname_at_Birth                    =432,
    ft_Civil_Status                        =433,
    ft_Number_of_Seats                    =434,
    ft_Number_of_Standing_Places        =435,
    ft_Max_Speed                        =436,
    ft_Fuel_Type                        =437,
    ft_EC_Environmental_Type            =438,
    ft_Power_Weight_Ratio                =439,
    ft_Max_Mass_of_Trailer_Braked        =440,
    ft_Max_Mass_of_Trailer_Unbraked        =441,
    ft_Transmission_Type                =442,
    ft_Trailer_Hitch                    =443,
    ft_Accompanied_by                    =444,
    ft_Police_District                    =445,
    ft_First_Issue_Date                    =446,
    ft_Payload_Capacity                    =447,
    ft_Number_of_Axels                    =448,
    ft_Permissible_Axle_Load            =449,
    ft_Precinct                            =450,
    ft_Invited_by                        =451,
    ft_Purpose_of_Entry                    =452,
    ft_Skin_Color                        =453,
    ft_Complexion                        =454,
    ft_Airport_From                        =455,
    ft_Airport_To                        =456,
    ft_Airline_Name                        =457,
    ft_Airline_Name_Frequent_Flyer        =458,
    ft_License_Number                    =459,
    ft_In_Tanks                            =460,
    ft_Exept_In_Tanks                    =461,
    ft_Fast_Track                        =462,
    ft_Owner                            =463,
    ft_MRZ_Strings_ICAO_RFID            =464,
    ft_Number_of_Card_Issuance             =465, // the number of times a card with this number has been issued
    ft_Number_of_Card_Issuance_Checksum =466,
    ft_Number_of_Card_Issuance_CheckDigit =467,
    ft_Century_Date_of_Birth             =468,
    ft_DLClassCode_A3_From = 469,
    ft_DLClassCode_A3_To = 470,
    ft_DLClassCode_A3_Notes = 471,
    ft_DLClassCode_C2_From = 472,
    ft_DLClassCode_C2_To = 473,
    ft_DLClassCode_C2_Notes = 474,
    ft_DLClassCode_B2_From = 475,
    ft_DLClassCode_B2_To = 476,
    ft_DLClassCode_B2_Notes = 477,
    ft_DLClassCode_D2_From = 478,
    ft_DLClassCode_D2_To = 479,
    ft_DLClassCode_D2_Notes = 480,
    ft_DLClassCode_B2E_From = 481,
    ft_DLClassCode_B2E_To = 482,
    ft_DLClassCode_B2E_Notes = 483,
    ft_DLClassCode_G_From = 484,
    ft_DLClassCode_G_To = 485,
    ft_DLClassCode_G_Notes = 486,
    ft_DLClassCode_J_From = 487,
    ft_DLClassCode_J_To = 488,
    ft_DLClassCode_J_Notes = 489,
    ft_DLClassCode_LC_From = 490,
    ft_DLClassCode_LC_To = 491,
    ft_DLClassCode_LC_Notes = 492,
    ft_BankCardNumber = 493,
    ft_BankCardValidThru = 494,
    ft_TaxNumber = 495,
    ft_HealthNumber =496,
    ft_GrandfatherName = 497,
    ft_Selectee_Indicator = 498,
    ft_Mother_Surname = 499,
    ft_Mother_GivenName = 500,
    ft_Father_Surname = 501,
    ft_Father_GivenName = 502,
    ft_Mother_DateOfBirth = 503,
    ft_Father_DateOfBirth = 504,
    ft_Mother_PersonalNumber = 505,
    ft_Father_PersonalNumber = 506,
    ft_Mother_PlaceOfBirth = 507,
    ft_Father_PlaceOfBirth = 508,
    ft_Mother_CountryOfBirth = 509,
    ft_Father_CountryOfBirth = 510,
    ft_Date_First_Renewal = 511,
    ft_Date_Second_Renewal = 512,
    ft_PlaceOfExamination = 513,
    ft_ApplicationNumber = 514,
    ft_VoucherNumber = 515,
    ft_AuthorizationNumber = 516,
    ft_Faculty = 517,
    ft_FormOfEducation = 518,
    ft_DNINumber = 519,
    ft_RetirementNumber = 520,
    ft_ProfessionalIdNumber = 521,
    ft_Age_at_Issue = 522,
    ft_Years_Since_Issue = 523,
    ft_DLClassCode_BTP_From = 524,
    ft_DLClassCode_BTP_Notes = 525,
    ft_DLClassCode_BTP_To = 526,
    ft_DLClassCode_C3_From = 527,
    ft_DLClassCode_C3_Notes = 528,
    ft_DLClassCode_C3_To = 529,
    ft_DLClassCode_E_From = 530,
    ft_DLClassCode_E_Notes = 531,
    ft_DLClassCode_E_To = 532,
    ft_DLClassCode_F_From = 533,
    ft_DLClassCode_F_Notes = 534,
    ft_DLClassCode_F_To = 535,
    ft_DLClassCode_FA_From = 536,
    ft_DLClassCode_FA_Notes = 537,
    ft_DLClassCode_FA_To = 538,
    ft_DLClassCode_FA1_From = 539,
    ft_DLClassCode_FA1_Notes = 540,
    ft_DLClassCode_FA1_To = 541,
    ft_DLClassCode_FB_From = 542,
    ft_DLClassCode_FB_Notes = 543,
    ft_DLClassCode_FB_To = 544,
    ft_DLClassCode_G1_From = 545,
    ft_DLClassCode_G1_Notes = 546,
    ft_DLClassCode_G1_To = 547,
    ft_DLClassCode_H_From = 548,
    ft_DLClassCode_H_Notes = 549,
    ft_DLClassCode_H_To = 550,
    ft_DLClassCode_I_From = 551,
    ft_DLClassCode_I_Notes = 552,
    ft_DLClassCode_I_To = 553,
    ft_DLClassCode_K_From = 554,
    ft_DLClassCode_K_Notes = 555,
    ft_DLClassCode_K_To = 556,
    ft_DLClassCode_LK_From = 557,
    ft_DLClassCode_LK_Notes = 558,
    ft_DLClassCode_LK_To = 559,
    ft_DLClassCode_N_From = 560,
    ft_DLClassCode_N_Notes = 561,
    ft_DLClassCode_N_To = 562,
    ft_DLClassCode_S_From = 563,
    ft_DLClassCode_S_Notes = 564,
    ft_DLClassCode_S_To = 565,
    ft_DLClassCode_TB_From = 566,
    ft_DLClassCode_TB_Notes = 567,
    ft_DLClassCode_TB_To = 568,
    ft_DLClassCode_TM_From = 569,
    ft_DLClassCode_TM_Notes = 570,
    ft_DLClassCode_TM_To = 571,
    ft_DLClassCode_TR_From = 572,
    ft_DLClassCode_TR_Notes = 573,
    ft_DLClassCode_TR_To = 574,
    ft_DLClassCode_TV_From = 575,
    ft_DLClassCode_TV_Notes = 576,
    ft_DLClassCode_TV_To = 577,
    ft_DLClassCode_V_From = 578,
    ft_DLClassCode_V_Notes = 579,
    ft_DLClassCode_V_To = 580,
    ft_DLClassCode_W_From = 581,
    ft_DLClassCode_W_Notes = 582,
    ft_DLClassCode_W_To = 583,
    ft_URL = 584,
    ft_Caliber = 585,
    ft_Model = 586,
    ft_Make = 587,
    ft_NumberOfCylinders = 588,
    ft_SurnameOfHusbandAfterRegistration = 589,
    ft_SurnameOfWifeAfterRegistration = 590,
    ft_DateOfBirthOfWife = 591,
    ft_DateOfBirthOfHusband = 592,
    ft_CitizenshipOfFirstPerson = 593,
    ft_CitizenshipOfSecondPerson = 594,
    ft_CVV = 595,
    ft_Date_of_Insurance_Expiry = 596,
    ft_Mortgage_by = 597,
    ft_Old_Document_Number = 598,
    ft_Old_Date_of_Issue = 599,
    ft_Old_Place_of_Issue = 600,
    ft_DLClassCode_LR_From = 601,
    ft_DLClassCode_LR_To = 602,
    ft_DLClassCode_LR_Notes = 603,
    ft_DLClassCode_MR_From = 604,
    ft_DLClassCode_MR_To = 605,
    ft_DLClassCode_MR_Notes = 606,
    ft_DLClassCode_HR_From = 607,
    ft_DLClassCode_HR_To = 608,
    ft_DLClassCode_HR_Notes = 609,
    ft_DLClassCode_HC_From = 610,
    ft_DLClassCode_HC_To = 611,
    ft_DLClassCode_HC_Notes = 612,
    ft_DLClassCode_MC_From = 613,
    ft_DLClassCode_MC_To = 614,
    ft_DLClassCode_MC_Notes = 615,
    ft_DLClassCode_RE_From = 616,
    ft_DLClassCode_RE_To = 617,
    ft_DLClassCode_RE_Notes = 618,
    ft_DLClassCode_R_From = 619,
    ft_DLClassCode_R_To = 620,
    ft_DLClassCode_R_Notes = 621,
    ft_DLClassCode_CA_From = 622,
    ft_DLClassCode_CA_To = 623,
    ft_DLClassCode_CA_Notes = 624,
    ft_Citizenship_Status = 625,
    ft_Military_Service_From = 626,
    ft_Military_Service_To = 627,
    ft_DLClassCode_NT_From = 628,
    ft_DLClassCode_NT_To = 629,
    ft_DLClassCode_NT_Notes = 630,
    ft_DLClassCode_TN_From = 631,
    ft_DLClassCode_TN_To = 632,
    ft_DLClassCode_TN_Notes = 633,
    ft_DLClassCode_D3_From = 634,
    ft_DLClassCode_D3_To = 635,
    ft_DLClassCode_D3_Notes = 636,
    ft_Alt_Date_Of_Expiry = 637,
    ft_DLClassCode_CD_From = 638,
    ft_DLClassCode_CD_To = 639,
    ft_DLClassCode_CD_Notes = 640,
    ft_Issuer_Identification_Number = 641,
    ft_Payment_Period_From = 642,
    ft_Payment_Period_To = 643,
    ft_VaccinationCertificateIdentifier = 644,
    ft_First_Name = 645,
    ft_Date_of_Arrival = 646,
    ft_Second_Name = 647,
    ft_Third_Name = 648,
    ft_Fourth_Name = 649,
    ft_Last_Name = 650,
    ft_DLClassCode_RM_From = 651,
    ft_DLClassCode_RM_Notes = 652,
    ft_DLClassCode_RM_To = 653,
    ft_DLClassCode_PW_From = 654,
    ft_DLClassCode_PW_Notes = 655,
    ft_DLClassCode_PW_To = 656,
    ft_DLClassCode_EB_From = 657,
    ft_DLClassCode_EB_Notes = 658,
    ft_DLClassCode_EB_To = 659,
    ft_DLClassCode_EC_From = 660,
    ft_DLClassCode_EC_Notes = 661,
    ft_DLClassCode_EC_To = 662,
    ft_DLClassCode_EC1_From = 663,
    ft_DLClassCode_EC1_Notes = 664,
    ft_DLClassCode_EC1_To = 665,
    ft_Place_of_Birth_City = 666,
    ft_Year_of_Birth = 667,
    ft_Year_of_Expiry = 668,
    ft_GrandfatherName_Maternal = 669,
    ft_First_Surname = 670,
    ft_Month_of_Birth = 671,
    ft_Address_Floor_Number = 672,
    ft_Address_Entrance = 673,
    ft_Address_Block_Number = 674,
    ft_Address_Street_Number = 675,
    ft_Address_Street_Type = 676,
    ft_Address_City_Sector = 677,
    ft_Address_County_Type = 678,
    ft_Address_City_Type = 679,
    ft_Address_Building_Type = 680,
    ft_Date_of_Retirement = 681,
    ft_Document_Status = 682,
    ft_Signature = 683,
    ft_UniqueCertificateIdentifier = 684,
    ft_Email = 685,
    ft_Date_of_SpecimenCollection = 686,
    ft_TypeOfTesting = 687,
    ft_ResultOfTesting = 688,
    ft_MethodOfTesting = 689,
    ft_Digital_Travel_Authorization_Number = 690,
    ft_Date_of_First_Positive_Test_Result = 691,
    ft_EF_CardAccess = 692

} eVisualFieldType;

#ifdef _WIN32
    #pragma deprecated (ft_MRZ_Strings_With_Correct_CheckSums)
#endif // _WIN32

typedef struct TSymbolCandidate
{
    uint32_t   SymbolCode;         // ASCII code
    uint32_t   SymbolProbability;  // confidence level (0-100%)
    WORD    SubClass;
    WORD    Class;
} TSymbolCandidate;

#ifdef  _WIN32
    #pragma warning (push)
    #pragma warning (disable : 4201)
#endif
// single character recognition result
typedef struct TSymbolResult
{
    RECT  SymbolRect;        // symbol's bounds
    uint32_t CandidatesCount;   // number of valid candidates in ListOfCandidates
    TSymbolCandidate ListOfCandidates[4]; // list of candidates
    union
    {
        struct
        {
            WORD BaseLineBottom;
            WORD BaseLineTop;
        };
        uint32_t Reserved;
    };
} TSymbolResult;

#ifdef  _WIN32
    #pragma warning (pop)
#endif

// single string recognition result
typedef struct TStringResultSDK
{
    uint32_t SymbolsCount;          // number of characters
    uint32_t Reserved;
    TSymbolResult *StringResult; // array of character recognition results
} TStringResultSDK;

#ifdef  _WIN32
    #pragma warning (push)
    #pragma warning (disable : 4201)
#endif

typedef struct TDocVisualExtendedField
{
    union
    {
        int FieldType; // eVisualFieldType
        struct
        {
            WORD wFieldType;
            WORD wLCID;
        };
    };
    union
    {
        RECT FieldRect; // field area coordinates
        struct
        { // or additional RFID information
            int32_t RFID_OriginDG;
            int32_t RFID_OriginDGTag;
            int32_t RFID_OriginTagEntry;
            int32_t RFID_OriginEntryView;
        };
    };
    char FieldName[256];             // Field Name
    int StringsCount;                // number of strings
    TStringResultSDK *StringsResult; // array of string recognition results
    int Buf_Length;
    char *Buf_Text;  // text buffer, '^' - lines separator
    char *FieldMask; // Field Mask
    int Validity;
    int InComparison;
    uint32_t Reserved2;
    uint32_t Reserved3;
} TDocVisualExtendedField;

#ifdef  _WIN32
    #pragma warning (pop)
#endif

typedef struct TDocVisualExtendedInfo
{
    uint32_t nFields;
    TDocVisualExtendedField *pArrayFields;
} TDocVisualExtendedInfo;

//****************************************************************************
//**  result RPRM_ResultType_Graphics
//****************************************************************************
// 'TResultContainer.buffer' = TDocGraphicsInfo *

typedef enum eGraphicFieldType
{
    gf_Portrait             = 201,
    gf_Fingerprint          = 202,
    gf_Eye                  = 203,
    gf_Signature            = 204,
    gf_BarCode              = 205,
    gf_Proof_Of_Citizenship = 206,
    gf_Document_Front       = 207,
    gf_Document_Rear        = 208,
    gf_ColorDynamic         = 209,
    gf_GhostPortrait        = 210,
    gf_Stamp                = 211,
    gf_Portrait_Of_Child    = 212,
    gf_ContactChip          = 213,

    gf_Other                = 250,

    gf_Finger_LeftThumb     = 300,
    gf_Finger_LeftIndex     = 301,
    gf_Finger_LeftMiddle    = 302,
    gf_Finger_LeftRing      = 303,
    gf_Finger_LeftLittle    = 304,
    gf_Finger_RightThumb    = 305,
    gf_Finger_RightIndex    = 306,
    gf_Finger_RightMiddle   = 307,
    gf_Finger_RightRing     = 308,
    gf_Finger_RightLittle   = 309,
    gf_Finger_Right4Fingers = 313,
    gf_Finger_Left4Fingers  = 314,
    gf_Finger_2Thumbs       = 315
} eGraphicFieldType;

#ifdef  _WIN32
    #pragma warning (push)
    #pragma warning (disable : 4201)
#endif

//one field
typedef struct TDocGraphicField
{
    int FieldType; // eGraphicFieldType
    union
    {
        RECT FieldRect; // field area coordinates
        struct
        { // or additional RFID information
            int32_t RFID_OriginDG;
            int32_t RFID_OriginDGTag;
            int32_t RFID_OriginTagEntry;
            int32_t RFID_OriginEntryView;
        };
    };
    char FieldName[256]; // Field Name
    TRawImageContainer image;
} TDocGraphicField;

#ifdef  _WIN32
    #pragma warning (pop)
#endif

typedef struct TDocGraphicsInfo
{
    uint32_t nFields;
    TDocGraphicField *pArrayFields;
} TDocGraphicsInfo;

//****************************************************************************
//****************************************************************************
// 'TResultContainer.buffer' = TDocBinaryInfo *
// actual meaning of Buffer depends on FieldType

typedef struct TBinaryData
{
    int  FieldType;           // eGraphicFieldType, eVisualFieldType in context
    char FieldName[256];      // Field Name
    int  Buf_Length;
    BYTE *Buffer;
} TBinaryData;

typedef struct TDocBinaryInfo
{
    uint32_t nFields;
    TBinaryData *pArrayFields;
} TDocBinaryInfo;

//****************************************************************************
//**  result RPRM_ResultType_BarCodes
//****************************************************************************
// 'TResultContainer.buffer' = TDocBarCodeInfo *

typedef enum eBarCodeType
{
    bct_Unknown    = 0,
    bct_Code128    = 1,
    bct_Code39     = 2,
    bct_EAN8       = 3,
    bct_ITF        = 4,
    bct_PDF417     = 5,
    bct_STF        = 6,
    bct_MTF        = 7,
    bct_IATA       = 8,
    bct_CODABAR    = 9,
    bct_UPCA       = 10,
    bct_CODE93     = 11,
    bct_UPCE       = 12,
    bct_EAN13      = 13,
    bct_QRCODE     = 14,
    bct_AZTEC      = 15,
    bct_DATAMATRIX = 16,
    bct_ALL_1D     = 17,
    bct_CODE11     = 18,
    bct_JABCODE    = 19,
    eBarCodeType_END // Insert all enum values BEFORE this
} eBarCodeType;

typedef enum eBarCodeResultCodes 
{
    bcrc_NoErr                                 = 0,
    bcrc_NullPtrErr                            = -6001,
    bcrc_BadArgErr                             = -6002,
    bcrc_SizeErr                               = -6003,
    bcrc_RangeErr                              = -6004,
    bcrc_InternalErr                           = -6005,
    bcrc_TryExceptErr                          = -6006,
    bcrc_BarCodeNotFound                       = -6008,
    bcrc_BarCodeDecodeErr                      = -6010,
    bcrc_NoUserDLLFound                        = -6019,
    bcrc_NoIPPDLLFound                         = -6020,
    bcrc_IppExecErr                            = -6024,
    bcrc_IppTryExceptErr                       = -6025,
    bcrc_BARCODE_ERROR_Inputparam              = -11001,
    bcrc_BARCODE_ERROR_FInit                   = -11006,
    bcrc_BARCODE_ERROR_NotLoadIpDecodedll      = -11012,
    bcrc_BARCODE_ERROR_InnerProblem            = -11100,
    bcrc_BARCODE_ERROR_Decode_1D_BadDecode     = -11200,
    bcrc_BARCODE_ERROR_FindRowOrColumn         = -11201,
    bcrc_BARCODE_ERROR_Find3X8_2D_X            = -11202,
    bcrc_BARCODE_ERROR_Find3X8_2D_Y            = -11203,
    bcrc_BARCODE_ERROR_2D_UgolMax              = -11204,
    bcrc_BARCODE_ERROR_INDEFINITELY_DECODED    = -11210,
    bcrc_BARCODE_ERROR_Dllnotinit              = -11300,
    bcrc_BARCODE_ERROR_IPDECODE_DLL_Try_Except = -11400,
    bcrc_IPDECODE_ERROR_LARGEERRORS            = -4503,
    bcrc_IPDECODE_ERROR_FAULTCOLUMNS           = -4504,
    bcrc_IPDECODE_ERROR_FAULTROWS              = -4505,
    bcrc_IPDECODE_ERROR_INCORRECT_ERROR_LEVEL  = -4511,
    bcrc_IPDECODE_ERROR_LOADING_DEV_TABLE      = -4512
} eBarCodeResultCodes;

typedef enum eBarCodeModuleType
{
    MODULETYPE_TEXT     = 0,    //text module
    MODULETYPE_BYTE     = 1,    //byte module
    MODULETYPE_NUM      = 2,    //numeric module
    MODULETYPE_SHIFT    = 3,    //shift module
    MODULETYPE_ALL      = 4,    //common module
} eBarCodeModuleType;

typedef struct TIP_DECODE_MODULE
{
    int32_t mType;         //type of module eBarCodeModuleType
    int32_t mLength;       //length of char data
    BYTE *mData;     //char data of module
    int32_t mReserved1;
    int32_t mReserved2;
} TIP_DECODE_MODULE;

typedef struct TIP_PDF417_INFO
{
    int32_t  bcColumn;
    int32_t  bcRow;
    int32_t  bcErrorLevel;
    float minX;
    float minY;
    float Angle;
} TIP_PDF417_INFO;

typedef struct TDocBarCodeField
{
    int32_t  bcCodeResult;

    int32_t  bcType_DETECT;
    RECT  bcROI_DETECT;
    float bcAngle_DETECT;

    int32_t  bcType_DECODE;
    int32_t  bcCountModule;
    TIP_DECODE_MODULE *bcDataModule;
    TIP_PDF417_INFO   bcPDF417INFO;
    int32_t  bcTextFieldType;
    int32_t  bcTextDecoderTypes;
    int8_t*  bcFieldMask;
} TDocBarCodeField;

typedef struct TDocBarCodeInfo
{
    uint32_t nFields;
    TDocBarCodeField *pArrayFields;
} TDocBarCodeInfo;

//****************************************************************************
//**  result RPRM_ResultType_MRZ_TestQuality
//****************************************************************************
// 'TResultContainer.buffer' = TDocMRZTestQuality *

typedef struct TSymbolEstimation
{
    char CharSymbol;                
    RECT SymbolBounds;              
    uint32_t SYMBOL_PARAM;             
    uint32_t EMPTINESS;                
    uint32_t EDGE;                     
    uint32_t STAIN;                    
    uint32_t CONTRAST_PRINT;           
    uint32_t CONTRAST_SYMBOL;          
    uint32_t ALIGNMENT_NEAREST_SYMBOLS;
    float SizeErrorAlignWithPrev;   
    float SizeErrorAlignWithNext;   
    uint32_t SYMBOLS_INTERVAL;         
    float SizeErrorIntervWithPrev;  
    float SizeErrorIntervWithNext;  
    uint32_t SYMBOL_SIZE;
    float SizeErrorSymbolHeight;
    float SizeErrorSymbolWidth;
} TSymbolEstimation;

typedef struct TSingleRect
{
    float Left, Top, Right, Bottom;
} TSingleRect;

typedef enum eTestTextField
{
    tr_OK                           = 0x00000000,
    tr_Process_Error                = 0x00000001,
    tr_Invalid_Checksum             = 0x00000002,
    tr_Syntax_Error                 = 0x00000004,
    tr_Logic_Error                  = 0x00000008,
    tr_SourcesComparison_Error      = 0x00000010,
    tr_FieldsComparison_LogicError  = 0x00000020,
    tr_UnknownStatus                = 0x00000040,
    tr_GlaresOnField                = 0x00000080
} eTestTextField;

typedef enum eCheckDiagnose
{
//    0 - 9: common diagnoses
    chd_Unknown                        = 0,    // check was not performed;
    chd_Pass                        = 1,    // check was ok;
    chd_InvalidInputData            = 2,    // invalid input data;
    chd_InternalError                = 3,    // internal error in module;
    chd_ExceptionInModule            = 4,    // exception caught;
    chd_UncertainVerification        = 5,    // can't make reliable decision
    chd_NecessaryImageNotFound        = 7,    // image in necessary light not found
    chd_PhotoSidesNotFound            = 8,    // necessary side of photo not found

//    10 - 19:    Lex.dll and RegDBOCR.dll (
    chd_InvalidChecksum                = 10,    // invalid checsum;
    chd_SyntaxError                    = 11,    // syntactical error;
    chd_LogicError                    = 12,    // logical error.
    chd_SourcesComparisonError        = 13,    // comparasing was incorrect;
    chd_FieldsComparisonLogicError    = 14,    // logical error. e.g. the current date is less than issue date
    chd_InvalidFieldFormat            = 15,    // wrong field format; 

//    20 - 29: Patterns.dll part 1, part 2 is 250-259
    chd_TrueLuminiscenceError        = 20,    // element of the luminescense in the UV does not meet the standard
    chd_FalseLuminiscenceError        = 21,    // the presence of excess luminescence in UV
    chd_FixedPatternError            = 22,    // pattern does not match the standard
    chd_LowContrastInIRLight        = 23,    // low contrast of object in transmitted IR light
    chd_IncorrectBackgroundLight    = 24,    // background of page is too light or it have invalid color
    chd_BackgroundComparisonError    = 25,    // background lightness of two pages have difference
    chd_IncorrectTextColor            = 26,    // text have incorrect color of luminescence in UV lightincorrect color of luminesced test
    chd_PhotoFalseLuminiscence        = 27,    // invalid luminescence in photo area
    chd_TooMuchShift                = 28,    // object is too shifted from standard coordinates
    chd_ContactChipTypeMismatch     = 29,

//    30 - 39: Fibers.dll
    chd_FibersNotFound                = 30,    // no protective fibers were found in UV
    chd_TooManyObjects                = 31,    // error finding fibers, too many objects
    chd_SpecksInUV                    = 33,    // speck or exposure in UV image
    chd_TooLowResolution            = 34,    // resolution too low for fibers search

//    40 - 49: IRVisibility.dll and ippImProc.dll(IRB900)
    chd_InvisibleElementPresent        = 40,    // erroneous visibility of the element in IR
    chd_VisibleElementAbsent        = 41,    // element is absent in IR
    chd_ElementShouldBeColored        = 42,
    chd_ElementShouldBeGrayscale    = 43,
    chd_PhotoWhiteIRDontMatch       = 44,

//    50 - 59: UVDullPaper.dll
    chd_UVDullPaper_MRZ                = 50,    // glow paper in MRZ
    chd_FalseLuminiscenceInMRZ        = 51,    // luminescence characters in MRZ
    chd_UVDullPaper_Photo            = 52,    // glow in the field of photo paper
    chd_UVDullPaper_Blank            = 53,    // glow paper form
    chd_UVDullPaperError            = 54,    // glow of the document in UV
    chd_FalseLuminiscenceInBlank    = 55,

//    60 - 64: AxialProtection.dll
    chd_BadAreaInAxial                = 60,    // violation of the retro-reflective protection

//    65 - 69: IPI.dll and LetterScreen.dll
    chd_FalseIPIParameters            = 65,    //    invalid params for IPI check
    chd_EncryptedIPI_NotFound         = 66,  // information not decoded
    chd_EncryptedIPI_DataDontMatch    = 67,  // decoded data don't match to other data sources

//    80 - 89: FieldPosCorrector.dll
    chd_FieldPosCorrector_Highlight_IR    = 80,
    chd_FieldPosCorrector_GlaresInPhotoArea = 81,
    chd_FieldPosCorrector_PhotoReplaced = 82,
    chd_FieldPosCorrector_LandmarksCheckError = 83,
    chd_FieldPosCorrector_FacePresenceCheckError = 84,
    chd_FieldPosCorrector_FaceAbsenceCheckError = 85,
    chd_FieldPosCorrector_IncorrectHeadPosition = 86,

//    90 - 99: OVIcheck.dll
    chd_OVI_IR_Invisible            = 90,    // OVI object is not visible in IR
    chd_OVI_InsufficientArea        = 91,    // insufficient area of the object OVI
    chd_OVI_ColorInvariable         = 92,    // OVI color of an object does not change
    chd_OVI_BadColor_Front          = 93,    // impossible to determine the color of the AXIAL image
    chd_OVI_BadColor_Side           = 94,    // impossible to determine the color of the WHITE image
    chd_OVI_Wide_Color_Spread       = 95,    // wide color spread // ?????????
    chd_OVI_BadColor_Percent        = 96,    //
//    100 - 109: Holograms Check (ippImProc.dll)
    chd_HologramElementAbsent            = 100,    // hologram element absent
    chd_Hologram_Side_Top_Images_Absent = 101,  // There aren't Side or Top images! Check cancelled
    chd_HologramElementPresent			= 102,  // hologram element detected
    chd_Hologram_Frames_IsAbsent        = 103,  // Frame with hologram not found
    chd_Hologram_HoloField_IsAbsent     = 104,  // Field with hologram not found in description

//    110 - 119: Diagnoses for RPRM_Authenticity_PassportRUS_Photo  (ippImProc.dll)
    chd_PhotoPattern_Interrupted        = 110,  //  Pattern is interrupted
    chd_PhotoPattern_Shifted            = 111,  // Some of the patterns are shifted relative to each other
    chd_PhotoPattern_DifferentColors    = 112,  // Some parts of the pattern have a different color
    chd_PhotoPattern_IR_Visible         = 113,  // Pattern seen in the infrared
    chd_PhotoPattern_Not_Intersect      = 114,  // Edge of the photo does not intersect with the pattern (Checking impossible)
    chd_PhotoSize_Is_Wrong              = 115,  // Size of the photo does not correspond to requirements
    chd_PhotoPattern_InvalidColor       = 116,  // Some parts of the pattern have an invalid color (not Red)
    chd_PhotoPattern_Shifted_Vert        = 117,  // Some of the patterns are shifted relative to each other (vertical)
    chd_PhotoPattern_PatternNotFound    = 118,  // Not found Pattern. Refuse testing
    chd_PhotoPattern_DifferentLinesThickness = 119, // Different lines thickness
    chd_Photo_IsNot_Rectangle            = 120, // photo shape is not rectangular
    chd_Photo_Corners_Is_Wrong            = 121, // photo corners don't satisfy the requirements
    chd_DocumentIsCancelling			= 122,  

    //  130 - 140 diagnoses for OcrSecurityText
    chd_TextColorShouldBeBlue = 130,
    chd_TextColorShouldBeGreen = 131,
    chd_TextColorShouldBeRed = 132,
    chd_TextShouldBeBlack = 133,

    chd_BarcodeWasReadWithErrors        = 140,
    chd_BarcodeDataFormatError          = 141,
    chd_BarcodeSizeParamsError          = 142,
    chd_NotAllBarcodesRead              = 143,
    chd_GlaresInBarcodeArea             = 144,
    chd_NoCertificateForDigitalSignatureCheck = 145,
    
    chd_PortraitComparison_PortraitsDiffer = 150,
    chd_PortraitComparison_NoServiceReply = 151,
    chd_PortraitComparison_ServiceError = 152,
    chd_PortraitComparison_NotEnoughImages = 153,
    chd_PortraitComparison_NoLivePhoto = 154,
    chd_PortraitComparison_NoServiceLicense = 155,
    chd_PortraitComparison_NoPortraitDetected = 156,

    // 160 - 169: Diagnoses for mobile images check
    chd_MobileImages_UnsuitableLightConditions = 160, // need improve light conditions
    chd_MobileImages_WhiteUVNoDifference = 161, // possible torch don't work
    
    chd_FingerprintsComparison_Mismatch = 170,

    chd_HoloPhoto_FaceNotDetected = 180,
    chd_HoloPhoto_FaceComparisonFailed = 181,
    chd_HoloPhoto_GlareInCenterAbsent = 182,
    chd_HoloPhoto_HoloElementShapeError = 183,
    chd_HoloPhoto_AlgorithmStepsError = 184,
    chd_HoloPhoto_HoloAreasNotLoaded = 185,
    chd_HoloPhoto_FinishedByTimeout = 186,
    chd_HoloPhoto_DocumentOutsideFrame = 187,
    
    chd_Liveness_DepthCheckFailed = 190,

    chd_MrzQuality_WrongSymbolPosition = 200,
    chd_MrzQuality_WrongBackground = 201,
    chd_MrzQuality_WrongMrzWidth = 202,
    chd_MrzQuality_WrongMrzHeight = 203,
    chd_MrzQuality_WrongLinePosition = 204,
    chd_MrzQuality_WrongFontType = 205,

    chd_OCRQuality_TextPosition = 220,
    chd_OCRQuality_InvalidFont = 221,
    chd_OCRQuality_InvalidBackground = 222,

    chd_LasInk_InvalidLinesFrequency = 230,

    chd_DocLiveness_BlackAndWhiteCopyDetected = 239,
    chd_DocLiveness_ElectronicDeviceDetected = 240,
    chd_DocLiveness_InvalidBarcodeBackground = 241,
    chd_DocLiveness_VirtualCameraDetected = 242,

    // ICAO IDB diagnoses
    chd_ICAO_IDB_Base32Error = 243,
    chd_ICAO_IDB_ZippedError = 244,
    chd_ICAO_IDB_MessageZoneEmpty = 245,
    chd_ICAO_IDB_SignatureMustBePresent = 246,
    chd_ICAO_IDB_SignatureMustNotBePresent = 247,
    chd_ICAO_IDB_CertificateMustNotBePresent = 248,

    // Patterns.dll part 2 (250-259), part 1 is 20-29
    chd_IncorrectObjectColor = 250
} eCheckDiagnose;

typedef enum eCompareStatus
{
    CompareStatusUnknown    = 0, // comparison result unknown
    CompareStatusPass        = 3, // positive comparison result
    CompareStatusFailed        = 4  // negative comparison result
} eCompareStatus;

typedef struct TTestTextField
{
    uint32_t TEST_RESULT;    // eTestTextField
    uint32_t FieldType;      // eRPRMFieldType
    WORD  FieldPos;
    WORD  FieldLength;
    WORD  ValidCheckSum;
    WORD  reserved;
} TTestTextField;

typedef struct TStrEstimation
{
    int32_t SymbolsCount;
    float StringAngle;
    RECT StringBorders;
    int32_t STRING_POSITION;
    TSingleRect ErrorPOSITION;
    int32_t STRINGS_DISTANCE;
    float SizeError_DISTANCE;
    int32_t STRINGS_INTERVAL;
    float SizeError_INTERVAL;
    int32_t ALIGNMENT_SYMBOLS_IN_STRING;
    float SizeError_ALIGNMENT;
    int32_t SYMBOLS_PARAM;
    int32_t STRING_FILLING;
    int32_t CHECK_SUMS;
    int32_t FieldCount;
    TTestTextField Fields[12];
    TSymbolEstimation SymbolsEstimations[44];
} TStrEstimation;

typedef struct TDocMRZTestQuality
{
    int32_t DOC_FORMAT;
    int32_t MRZ_FORMAT;
    int32_t TEXTUAL_FILLING;
    int32_t CHECK_SUMS;
    int32_t CONTRAST_PRINT;
    int32_t STAIN_MRZ;
    int32_t PRINT_POSITION;
    int32_t SYMBOLS_PARAM;
    int32_t StrCount;
    TStrEstimation Strings[3];
} TDocMRZTestQuality;

typedef enum eCheckResult
{
    ch_Check_Error      = 0,
    ch_Check_OK         = 1,
    ch_Check_WasNotDone = 2
} eCheckResult;

typedef enum ePhotoEmbedType
{
    PhotoEmbedType_AnyType        = 0,
    PhotoEmbedType_strPrinted    = 1,
    PhotoEmbedType_strSticked    = 2
} ePhotoEmbedType;

//***********************************
// for RPRM_Command_SetMRZTestQualityParams command:
//***********************************
typedef enum eMRZClassQuality
{
    mrz_CLASS_QUALITY_X = 21,
    mrz_CLASS_QUALITY_Y = 22,
    mrz_CLASS_QUALITY_Z = 23,
    mrz_CLASS_QUALITY_CUSTOM = 24,
} eMRZClassQuality;

typedef struct TCommandsMRZTestQuality
{
    uint32_t TEST_CLASS_QUALITY; // eMRZClassQuality
    uint32_t EXEC_SYMBOLS_PARAM;
    uint32_t EXEC_PRINT_POSITION;
    uint32_t EXEC_TEXTUAL_FILLING;
    uint32_t EXEC_CHECK_SUMS;
    uint32_t RESERVED1;
    uint32_t RESERVED2;
} TCommandsMRZTestQuality;

//****************************************************************************
//  result RPRM_ResultType_DocumentTypesCandidates
//
// 'TResultContainer.buffer' = TCandidatesListContainer *
//****************************************************************************
//  result RPRM_ResultType_ChosenDocumentTypeCandidate
//
// 'TResultContainer.buffer' = TOneCandidate *
//****************************************************************************
typedef enum eRPRM_PostCalbackAction
{
    RPRM_PostCalbackAction_Continue = 0,
    RPRM_PostCalbackAction_Cancel = 1,
    RPRM_PostCalbackAction_ProcessCandidate = 2
} eRPRM_PostCalbackAction;

typedef enum eRPRM_RCTP_Result_RecType
{
    RPRM_RCTP_Result_Ok = 0,
    RPRM_RCTP_Result_RecognClassConflict = 14,
    RPRM_RCTP_Result_RecognClassUnknown = 15,
    RPRM_RCTP_Result_Need_Other_Image = 29, // additional images required to complete documnt type recognition
} eRPRM_RCTP_Result_RecType;

typedef enum eRFID_Presence
{
    rfpNone = 0,
    rfpMainPage = 1,
    rfpBackPage = 2,
} eRFID_Presence;

typedef enum diDocType
{
    // types defined for IRS:
    dtNotDefined = 0,   // Not Defined
    dtPassport = 11,   // Passport
    dtIdentityCard = 12,   // Identity Card
    dtDiplomaticPassport = 13,   // Diplomatic Passport
    dtServicePassport = 14,   // Service Passport
    dtSeamanIdentityDocument = 15,   // Seaman's Identity Document
    dtIdentityCardForResidence = 16,   // Identity Card for for.res.
    dtTravelDocument = 17,   // Travel document
    // left for compatibility
    dtOther = 99,    // Other
    dtVisaID2 = 29,   // Visa, format 2x36
    dtVisaID3 = 30,   // Visa, format 2x44
    // additional types supported by DocTeacher:
    dtNationalIdentityCard = 20,   // NATIONAL IDENTITY CARD
    dtSocialIdentityCard = 21,   //  Social Identity Card
    dtAliensIdentityCard = 22,   //  Alien's Identity Card
    dtPrivilegedIdentityCard = 23,   //  Privileged Identity Card
    dtResidencePermitIdentityCard = 24,   // Residence Permit Identity Card
    dtOriginCard = 25,   // ORIGIN CARD
    dtEmergencyPassport = 26,   // EMERGENCY PASSPORT
    dtAliensPassport = 27,   // ALIEN'S PASSPORT
    dtAlternativeIdentityCard = 28,
    dtAuthorizationCard = 32,
    dtBeginnerPermit = 33,
    dtBorderCrossingCard = 34,
    dtChauffeurLicense = 35,
    dtChauffeurLicenseUnder18 = 36,
    dtChauffeurLicenseUnder21 = 37,
    dtCommercialDrivingLicense = 38,
    dtCommercialDrivingLicenseInstructionalPermit = 39,
    dtCommercialDrivingLicenseUnder18 = 40,
    dtCommercialDrivingLicenseUnder21 = 41,
    dtCommercialInstructionPermit = 42,
    dtCommercialNewPermit = 43,
    dtConcealedCarryLicense = 44,
    dtConcealedFirearmPermit = 45,
    dtConditionalDrivingLicense = 46,
    dtDepartmentOfVeteransAffairsIdentityCard = 47,
    dtDiplomaticDrivingLicense = 48,
    dtDrivingLicense = 49,
    dtDrivingLicenseInstructionalPermit = 50,
    dtDrivingLicenseInstructionalPermitUnder18 = 51,
    dtDrivingLicenseInstructionalPermitUnder21 = 52,
    dtDrivingLicenseLearnersPermit = 53,
    dtDrivingLicenseLearnersPermitUnder18 = 54,
    dtDrivingLicenseLearnersPermitUnder21 = 55,
    dtDrivingLicenseNovice = 56,
    dtDrivingLicenseNoviceUnder18 = 57,
    dtDrivingLicenseNoviceUnder21 = 58,
    dtDrivingLicenseRegisteredOffender = 59,
    dtDrivingLicenseRestrictedUnder18 = 60,
    dtDrivingLicenseRestrictedUnder21 = 61,
    dtDrivingLicenseTemporaryVisitor = 62,
    dtDrivingLicenseTemporaryVisitorUnder18 = 63,
    dtDrivingLicenseTemporaryVisitorUnder21 = 64,
    dtDrivingLicenseUnder18 = 65,
    dtDrivingLicenseUnder21 = 66,
    dtEmploymentDrivingPermit = 67,
    dtEnhancedChauffeurLicense = 68,
    dtEnhancedChauffeurLicenseUnder18 = 69,
    dtEnhancedChauffeurLicenseUnder21 = 70,
    dtEnhancedCommercialDrivingLicense = 71,
    dtEnhancedDrivingLicense = 72,
    dtEnhancedDrivingLicenseUnder18 = 73,
    dtEnhancedDrivingLicenseUnder21 = 74,
    dtEnhancedIdentityCard = 75,
    dtEnhancedIdentityCardUnder18 = 76,
    dtEnhancedIdentityCardUnder21 = 77,
    dtEnhancedOperatorsLicense = 78,
    dtFirearmsPermit = 79,
    dtFullProvisionalLicense = 80,
    dtFullProvisionalLicenseUnder18 = 81,
    dtFullProvisionalLicenseUnder21 = 82,
    dtGenevaConventionsIdentityCard = 83,
    dtGraduatedDrivingLicenseUnder18 = 84,
    dtGraduatedDrivingLicenseUnder21 = 85,
    dtGraduatedInstructionPermitUnder18 = 86,
    dtGraduatedInstructionPermitUnder21 = 87,
    dtGraduatedLicenseUnder18 = 88,
    dtGraduatedLicenseUnder21 = 89,
    dtHandgunCarryPermit = 90,
    dtIdentityAndPrivilegeCard = 91,
    dtIdentityCardMobilityImpaired = 92,
    dtIdentityCardRegisteredOffender = 93,
    dtIdentityCardTemporaryVisitor = 94,
    dtIdentityCardTemporaryVisitorUnder18 = 95,
    dtIdentityCardTemporaryVisitorUnder21 = 96,
    dtIdentityCardUnder18 = 97,
    dtIdentityCardUnder21 = 98,
    dtIgnitionInterlockPermit = 100,
    dtImmigrantVisa = 101,
    dtInstructionPermit = 102,
    dtInstructionPermitUnder18 = 103,
    dtInstructionPermitUnder21 = 104,
    dtInterimDrivingLicense = 105,
    dtInterimIdentityCard = 106,
    dtIntermediateDrivingLicense = 107,
    dtIntermediateDrivingLicenseUnder18 = 108,
    dtIntermediateDrivingLicenseUnder21 = 109,
    dtJuniorDrivingLicense = 110,
    dtLearnerInstructionalPermit = 111,
    dtLearnerLicense = 112,
    dtLearnerLicenseUnder18 = 113,
    dtLearnerLicenseUnder21 = 114,
    dtLearnerPermit = 115,
    dtLearnerPermitUnder18 = 116,
    dtLearnerPermitUnder21 = 117,
    dtLimitedLicense = 118,
    dtLimitedPermit = 119,
    dtLimitedTermDrivingLicense = 120,
    dtLimitedTermIdentityCard = 121,
    dtLiquorIdentityCard = 122,
    dtNewPermit = 123,
    dtNewPermitUnder18 = 124,
    dtNewPermitUnder21 = 125,
    dtNonUsCitizenDrivingLicense = 126,
    dtOccupationalDrivingLicense = 127,
    dtOneidaTribeOfIndiansIdentityCard = 128,
    dtOperatorLicense = 129,
    dtOperatorLicenseUnder18 = 130,
    dtOperatorLicenseUnder21 = 131,
    dtPermanentDrivingLicense = 132,
    dtPermitToReenter = 133,
    dtProbationaryAutoLicense = 134,
    dtProbationaryDrivingLicenseUnder18 = 135,
    dtProbationaryDrivingLicenseUnder21 = 136,
    dtProbationaryVehicleSalespersonLicense = 137,
    dtProvisionalDrivingLicense = 138,
    dtProvisionalDrivingLicenseUnder18 = 139,
    dtProvisionalDrivingLicenseUnder21 = 140,
    dtProvisionalLicense = 141,
    dtProvisionalLicenseUnder18 = 142,
    dtProvisionalLicenseUnder21 = 143,
    dtPublicPassengerChauffeurLicense = 144,
    dtRacingAndGamingComissionCard = 145,
    dtRefugeeTravelDocument = 146,
    dtRenewalPermit = 147,
    dtRestrictedCommercialDrivingLicense = 148,
    dtRestrictedDrivingLicense = 149,
    dtRestrictedPermit = 150,
    dtSeasonalPermit = 151,
    dtSeasonalResidentIdentityCard = 152,
    dtSeniorCitizenIdentityCard = 153,
    dtSexOffender = 154,
    dtSocialSecurityCard = 155,
    dtTemporaryDrivingLicense = 156,
    dtTemporaryDrivingLicenseUnder18 = 157,
    dtTemporaryDrivingLicenseUnder21 = 158,
    dtTemporaryIdentityCard = 159,
    dtTemporaryInstructionPermitIdentityCard = 160,
    dtTemporaryInstructionPermitIdentityCardUnder18 = 161,
    dtTemporaryInstructionPermitIdentityCardUnder21 = 162,
    dtTemporaryVisitorDrivingLicense = 163,
    dtTemporaryVisitorDrivingLicenseUnder18 = 164,
    dtTemporaryVisitorDrivingLicenseUnder21 = 165,
    dtUniformedServicesIdentityCard = 166,
    dtVehicleSalespersonLicense = 167,
    dtWorkerIdentificationCredential = 168,
    dtCommercialDrivingLicenseNovice = 169,
    dtCommercialDrivingLicenseNoviceUnder18 = 170,
    dtCommercialDrivingLicenseNoviceUnder21 = 171,
    dtPassportCard = 172,
    dtPermanentResidentCard = 173,
    dtPersonalIdentificationVerification = 174,
    dtTemporaryOperatorLicense = 175,
    dtDrivingLicenseUnder19 = 176,
    dtIdentityCardUnder19 = 177,
    dtVisa = 178,
    dtTemporaryPassport = 179,
    dtVotingCard = 180,
    dtHealthCard = 181,
    dtCertificateOfCitizenship = 182,
    dtAddressCard = 183,
    dtAirportImmigrationCard = 184,
    dtAlienRegistrationCard = 185,
    dtAPEHCard = 186,
    dtCouponToDrivingLicense = 187,
    dtCrewMemberCertificate = 188,
    dtDocumentForReturn = 189,
    dtECard = 190,
    dtEmploymentCard = 191,
    dtHKSARImmigrationForm = 192,
    dtImmigrantCard = 193,
    dtLabourCard = 194,
    dtLaissezPasser = 195,
    dtLawyerIdentityCertificate = 196,
    dtLicenseCard = 197,
    dtPassportStateless = 198,
    dtPassportChild = 199,
    dtPassportConsular = 200,
    dtPassportDiplomaticService = 201,
    dtPassportOfficial = 202,
    dtPassportProvisional = 203,
    dtPassportSpecial = 204,
    dtPermissionToTheLocalBorderTraffic = 205,
    dtRegistrationCertificate = 206,   // Registration Certificate (Auto)
    dtSEDESOLCard = 207,
    dtSocialCard = 208,
    dtTBCard = 209,
    dtVehiclePassport = 210,
    dtWDocument = 211,
    dtDiplomaticIdentityCard = 212,
    dtConsularIdentityCard = 213,
    dtIncomeTaxCard = 214,
    dtResidencePermit = 215,
    dtDocumentOfIdentity = 216,
    dtBorderCrossingPermit = 217,
    dtPassportLimitedValidity = 218,
    dtSIMCard = 219,
    dtTaxCard = 220,
    dtCompanyCard = 221,
    dtDomesticPassport = 222,
    dtIdentityCertificate = 223,
    dtResidentIdCard = 224,
    dtArmedForcesIdentityCard = 225,
    dtProfessionalCard = 226,
    dtRegistrationStamp = 227,
    dtDriverCard = 228,
    dtDriverTrainingCertificate = 229,
    dtQualificationDrivingLicense = 230,
    dtMembershipCard = 231,
    dtPublicVehicleDriverAuthorityCard = 232,
    dtMarineLicense = 233,
    dtTemporaryLearnerDrivingLicense = 234,
    dtTemporaryCommercialDrivingLicense = 235,
    dtInterimInstructionalPermit = 236,
    dtCertificateOfCompetency = 237,
    dtCertificateOfProficiency = 238,
    dtTradeLicense = 239,
    dtPassportPage = 240,
    dtInvoice = 241,
    dtPassengerLocatorForm = 242,
} diDocType;

typedef struct TFDSIDList
{
    char ICAOCode[4];
    uint32_t Count;
    uint32_t *List;
    uint32_t dType;                // diDocType
    uint32_t dFormat;
    bool dMRZ;
    char *dDescription;
    char *dYear;
    char *dCountryName;
    char *dStateCode;
    char *dStateName;
    bool deprecated;
} TFDSIDList;

typedef struct TOneCandidate
{
    char *DocumentName;
    int ID;
    double P;
    WORD Rotated180;
    WORD RotationAngle;
    uint32_t NecessaryLights;
    TRawImageContainer *preview;
    uint32_t RFID_Presence; // eRFID_Presence
    uint32_t CheckAuthenticity;
    WORD UVExp;
    WORD OVIExp;
    uint32_t AuthenticityNecessaryLights;
    TFDSIDList *extendedInfo;
} TOneCandidate;

typedef struct TCandidatesListContainer
{
    uint32_t RecResult; // eRPRM_RCTP_Result_RecType
    uint32_t Count;
    TOneCandidate *Candidates; // array of maximum 16 pcs
} TCandidatesListContainer;

//****************************************************************************
//**  result RPRM_ResultType_Authenticity, RPRM_ResultType_Portrait_Comparison & RPRM_ResultType_FingerPrint_Comparison
//****************************************************************************
// 'TResultContainer.buffer' = TSecurityPaperChecks *

typedef enum eRPRM_Authenticity
{
    RPRM_Authenticity_None                        = 0x00000000,
    RPRM_Authenticity_UV_Luminescence             = 0x00000001, // TSecurityFeatureCheck
    RPRM_Authenticity_IR_B900                     = 0x00000002, // TSecurityFeatureCheck
    RPRM_Authenticity_Image_Pattern               = 0x00000004, // TIdentResult
    RPRM_Authenticity_Axial_Protection            = 0x00000008, // TSecurityFeatureCheck
    RPRM_Authenticity_UV_Fibers                   = 0x00000010, // TFibersType
    RPRM_Authenticity_IR_Visibility               = 0x00000020, // TIdentResult
    RPRM_Authenticity_OCRSecurityText             = 0x00000040, // TOCRSecurityTextResult
    RPRM_Authenticity_IPI                         = 0x00000080, // TPhotoIdentResult
    RPRM_Authenticity_IR_Photo                    = 0x00000100, // TPhotoIdentResult
    RPRM_Authenticity_Photo_Embed_Type            = 0x00000200, // TSecurityFeatureCheck
    RPRM_Authenticity_OVI                         = 0x00000400, // TIdentResult
    RPRM_Authenticity_IR_Luminescence             = 0x00000800, // TIdentResult
    RPRM_Authenticity_Holograms                   = 0x00001000, // TSecurityFeatureCheck
    RPRM_Authenticity_Photo_Area                  = 0x00002000, // TSecurityFeatureCheck
    RPRM_Authenticity_UV_Background               = 0x00004000, // TFibersType
    RPRM_Authenticity_Portrait_Comparison         = 0x00008000, // TIdentResult
    RPRM_Authenticity_BarcodeFormatCheck          = 0x00010000, // TSecurityFeatureCheck
    RPRM_Authenticity_Kinegram                    = 0x00020000, // TIdentResult
    RPRM_Authenticity_Letter_Screen               = 0x00040000, // TIdentResult
    RPRM_Authenticity_Holograms_Detection         = 0x00080000, // TIdentResult
    RPRM_Authenticity_Fingerprint_Comparison      = 0x00100000, // TIdentResult
    RPRM_Authenticity_Liveness                    = 0x00200000, // TIdentResult
    RPRM_Authenticity_Ocr                         = 0x00400000, // TSecurityFeatureCheck
    RPRM_Authenticity_Mrz                         = 0x00800000, // TSecurityFeatureCheck
    RPRM_Authenticity_EncryptedIPI                = 0x01000000, // TOCRSecurityTextResult
    RPRM_Authenticity_StatusOnly                  = 0x80000000, // TSecurityFeatureCheck, flag for status-only authenticity
    RPRM_Authenticity_UV  = RPRM_Authenticity_UV_Luminescence | RPRM_Authenticity_Image_Pattern | RPRM_Authenticity_UV_Fibers,
} eRPRM_Authenticity;

#ifdef  _WIN32
    #pragma warning (push)
    #pragma warning (disable : 4201)
#endif

typedef struct TFibersType
{
    union
    {
        uint32_t ErrorCode; // eCheckResult
        struct
        {
            WORD ElementResult;   // eCheckResult
            WORD ElementDiagnose; // eCheckDiagnose
        };
    };
    union
    {
        uint32_t RectCount;  //    for RPRM_Authenticity_UV_Fibers
        uint32_t LightValue; //    for RPRM_Authenticity_UV_Background
    };
    RECT *RectArray;
    uint32_t *Width;
    uint32_t *Length;
    uint32_t *Area;
    BYTE ColorValues[3];
    union
    {
        uint32_t ExpectedCount; //    for RPRM_Authenticity_UV_Fibers
        uint32_t LightDisp;     //    for RPRM_Authenticity_UV_Background
    };
} TFibersType;

#ifdef  _WIN32
    #pragma warning (pop)
#endif

typedef struct TIRVisibilityElement
{
    RECT Field;
    int32_t Visibility;
    int32_t CheckResult;
    int32_t ElementType;
    int32_t Reserved;
} TIRVisibilityElement;

typedef struct TPointArraySDK
{
    int PointCount;
    POINT *PointsList;
} TPointArraySDK;

typedef struct TAreaArray
{
    int Count;
    RECT *List;
    TPointArraySDK *Points;
} TAreaArray;

typedef TAreaArray* PAreaArray;

#ifdef  _WIN32
    #pragma warning (push)
    #pragma warning (disable : 4201)
#endif

typedef struct TIdentResult
{
    union
    {
        uint32_t Result;
        struct
        {
            WORD ElementResult;   //    eCheckResult
            WORD ElementDiagnose; //  eCheckDiagnose
        };
    };
    uint32_t LightIndex;
    RECT Area;
    TRawImageContainer Image;
    TRawImageContainer EtalonImage;
    uint32_t PercentValue;
    TAreaArray *AreaList;
    union
    {
        uint32_t ElementType;
        struct
        {
            uint16_t elemType;
            uint16_t elemID;
        };
    };
} TIdentResult;

typedef struct TOCRSecurityTextResult
{
    union
    {
        uint32_t ResultCode;
        struct
        {
            WORD ElementResult;   //    eCheckResult
            WORD ElementDiagnose; //  eCheckDiagnose
        };
    };
    uint32_t CriticalFlag;
    uint32_t LightType;
    RECT FieldRect;
    uint32_t EtalonResultType;
    uint32_t EtalonFieldType;
    uint32_t EtalonLightType;
    RECT EtalonFieldRect;
    char SecurityTextResultOCR[256];
    char EtalonResultOCR[256];
    uint32_t Reserved1;
    uint32_t Reserved2;
} TOCRSecurityTextResult;

#ifdef  _WIN32
    #pragma warning (pop)
#endif

typedef enum eIR_Visibility_Flag
{
    ElementInvisible = 0,
    ElementVisible = 1,
    ElementColored = 2,
    ElementGrayscale = 4,
    WhiteIRMatching = 8,
} eIR_Visibility_Flag;

typedef enum eSecurityCriticalFlag
{
    CheckFeatureNotCritical = 0,
    CheckFeatureIsCritical = 1
} eSecurityCriticalFlag;

typedef enum eRPRM_SecurityFeatureType
{
    SecurityFeatureType_Blank = 0,
    SecurityFeatureType_Fill = 1,
    SecurityFeatureType_Photo = 2,
    SecurityFeatureType_MRZ = 3,
    SecurityFeatureType_FalseLuminescence = 4,
    SecurityFeatureType_HoloSimple = 5,
    SecurityFeatureType_HoloVerifyStatic = 6,
    SecurityFeatureType_HoloVerifyMultiStatic = 7,
    SecurityFeatureType_HoloVerifyDinamic = 8,
    SecurityFeatureType_Pattern_NotInterrupted = 9, // Pattern can't interrupt on border of photo
    SecurityFeatureType_Pattern_NotShifted = 10,    // Some of the patterns parts can't shift relative to each other (on border of photo)
    SecurityFeatureType_Pattern_SameColors = 11,    // Parts of the pattern above photo and above blank have to be same color
    SecurityFeatureType_Pattern_IRInvisible = 12,   // Pattern have to invisible under IR light
    SecurityFeatureType_PhotoSize_Check = 13,
    SecurityFeatureType_Portrait_Comparison_vsGhost = 14,
    SecurityFeatureType_Portrait_Comparison_vsRFID = 15,
    SecurityFeatureType_Portrait_Comparison_vsVisual = 16,
    SecurityFeatureType_Barcode = 17,
    SecurityFeatureType_Pattern_DifferentLinesThickness = 18, // Different lines thickness

    SecurityFeatureType_Portrait_Comparison_vsCamera = 19,
    SecurityFeatureType_Portrait_Comparison_RFIDvsCamera = 20,
    SecurityFeatureType_GhostPhoto = 21,
    SecurityFeatureType_ClearGhostPhoto = 22,
    SecurityFeatureType_InvisibleObject = 23,
    SecurityFeatureType_LowContrastObject = 24,
    SecurityFeatureType_Photo_Color = 25,   // photograph color type
    SecurityFeatureType_Photo_Shape = 26,   // photo shape (squareness)
    SecurityFeatureType_Photo_Corners = 27, // photo corners shape
    SecurityFeatureType_OCR = 28,
    SecurityFeatureType_Portrait_Comparison_ExtvsVisual = 29,
    SecurityFeatureType_Portrait_Comparison_ExtvsRFID = 30,
    SecurityFeatureType_Portrait_Comparison_ExtvsLive = 31,

    SecurityFeatureType_Liveness_Depth = 32,
    SecurityFeatureType_Microtext = 33,
    SecurityFeatureType_FluorescentObject = 34,
    SecurityFeatureType_LandmarksCheck = 35,
    SecurityFeatureType_FacePresence = 36,
    SecurityFeatureType_FaceAbsence = 38,
    SecurityFeatureType_Liveness_ScreenCapture = 39,
    SecurityFeatureType_Liveness_ElectronicDevice = 40,
    SecurityFeatureType_Liveness_OVI = 41,
    SecurityFeatureType_BarcodeSizeCheck = 42,
    SecurityFeatureType_LasInk = 43,
    SecurityFeatureType_Liveness_MLI = 44,
    SecurityFeatureType_Liveness_BarcodeBackground = 45,
    SecurityFeatureType_Portrait_Comparison_vsBarcode = 46,
    SecurityFeatureType_Portrait_Comparison_RFIDvsBarcode = 47,
    SecurityFeatureType_Portrait_Comparison_ExtvsBarcode = 48,
    SecurityFeatureType_Portrait_Comparison_BarcodevsCamera = 49,
    SecurityFeatureType_CheckDigitalSignature = 50,
    SecurityFeatureType_ContactChipClassification = 51,
    SecurityFeatureType_HeadPositionCheck = 52,
    SecurityFeatureType_Liveness_BlackAndWhiteCopyCheck = 53,
} eRPRM_SecurityFeatureType;

#ifdef  _WIN32
    #pragma warning (push)
    #pragma warning (disable : 4201)
#endif

typedef struct TSecurityFeatureCheck
{
    union
    {
        int Result;
        struct
        {
            WORD ElementResult;   //    eCheckResult
            WORD ElementDiagnose; //  eCheckDiagnose
        };
    };
    int ElementType; // eRPRM_SecurityFeatureType
    RECT ElementRect;
    uint32_t Visibility;   // RPRM_Authenticity_IR_Visibility (eIR_Visibility_Flag)
    uint32_t CriticalFlag; // eSecurityCriticalFlag
    TAreaArray *AreaList;
    uint32_t Reserved2;
} TSecurityFeatureCheck;

typedef struct TPhotoIdentResult
{
    union
    {
        int Result;
        struct
        {
            WORD ElementResult;   //    eCheckResult
            WORD ElementDiagnose; //  eCheckDiagnose
        };
    };
    int LightIndex;
    RECT Area;
    TRawImageContainer SourceImage;
    TRawImageContainerList ResultImages;
    uint32_t FieldTypesCount;
    uint32_t *FieldTypesList;
    int Step;
    int Angle;
    int Reserved3;
} TPhotoIdentResult;

#ifdef  _WIN32
    #pragma warning (pop)
#endif

typedef struct TAuthenticityCheckResult
{
    int Type;    // eRPRM_Authenticity
    int Result;  // eCheckResult
    int Count;   //
    void **List; // see eRPRM_Authenticity for List contents
} TAuthenticityCheckResult;

typedef struct TAuthenticityCheckList
{
    int Count;
    TAuthenticityCheckResult **List;
} TAuthenticityCheckList;

//****************************************************************************
//**  result RPRM_ResultType_DocumentsInfoList
//****************************************************************************
// 'TResultContainer.buffer' = TListDocsInfo *

typedef struct TOCRDocInfo
{
    char DocName[256];
    uint32_t DocID;
    char DocTxtID[256];
    uint32_t DocFormat;
    uint32_t NecessaryLights;
    uint32_t nFields;
    uint32_t RFID_Presence;
    uint32_t reserved1;
    uint32_t reserved2;
    uint32_t reserved3;
} TOCRDocInfo;

typedef struct TListDocsInfo
{
    uint32_t Count;
    TOCRDocInfo *ArrayOfDocs;
} TListDocsInfo;

//****************************************************************************
typedef enum eRPRM_FieldVerificationResult
{
    RCF_Disabled = 0,        // comparison result unknown
    RCF_Verified = 1,        // verification passed
    RCF_Not_Verified = 2,    // verification failed
    RCF_Compare_True = 3,    // positive comparison result
    RCF_Compare_False = 4    // negative comparison result
} eRPRM_FieldVerificationResult;

//****************************************************************************
//**  result RPRM_ResultType_OCRLexicalAnalyze
//****************************************************************************
// 'TResultContainer.buffer' = TListVerifiedFields *

#ifdef  _WIN32
    #pragma warning (push)
    #pragma warning (disable : 4201)
#endif

typedef struct TVerifiedFieldMap
{
    union
    {
        uint32_t FieldType; // eVisualFieldType
        struct
        {
            WORD wFieldType;
            WORD wLCID;
        };
    };
    char *Field_MRZ;
    char *Field_RFID;
    char *Field_Visual;
    char *Field_Barcode;
    union
    {
        BYTE Matrix[10];
        struct
        {
            BYTE verMRZ;
            BYTE verRFid;
            BYTE verVisual;
            BYTE verBarcode;
            BYTE compMRZ_RFid;
            BYTE compMRZ_Visual;
            BYTE compMRZ_Barcode;
            BYTE compVisual_RFid;
            BYTE compVisual_Barcode;
            BYTE compRFid_Barcode;
        };
    };
} TVerifiedFieldMap;

#ifdef  _WIN32
    #pragma warning (pop)
#endif

typedef struct TListVerifiedFields
{
    uint32_t Count;
    TVerifiedFieldMap *pFieldMaps;
    char *pDateFormat;
} TListVerifiedFields;

//-------------------------------------------------------------------------------------------------
typedef enum eLexAnalysisDepth
{
    //    default mode, fields and results with low probability are not exposed, 
    //    fields are checked for presence in "stop-list", document number should not be zero
    eLAD_Default = 0x0000,
    //    show all read data, but disable comparison/verification results
    eLAD_ShowAllData = 0x0001,
    //    show all read data and results regardless of probability
    eLAD_ShowDataAndResults = 0x0002,
    //    disable "stop-list" fields check
    eLAD_CheckStopListOFF = 0x0004,
    //    disable zero document number check
    eLAD_CheckDocNumZeroOFF = 0x0008,
    //    disable ICAO convention check
    eLAD_ICAOConvertionOFF = 0x0010,
    //    enable convertion latin fields to Cyrillic
    eLAD_ConvertToCyrillicON = 0x0020,
    //    generate MRZ for russian national passports
    eLAD_GenerateRussiaMRZStrings = 0x0040,
    //	 compare generated fields ft_Authority_RUS with ft_Authority
    //	in Russia's national passport
    eLAD_CompareRussiaAuthority = 0x0080,

    eLAD_CheckLowProbabilityEnable = 0x0100,

    eLAD_CheckExtendedStopListOFF = 0x0200
} eLexAnalysisDepth;

//-------------------------------------------------------------------------------------------------
// DEPRECATED
typedef enum eLexDateFormat
{
    LDF_DefaultShort = 0,
    LDF_DefaultLong = 1,
    LDF_SystemShort = 2,
    LDF_SystemLong = 3, 
    LDF_Universal = 4,
    LDF_Custom = 5,
} eLexDateFormat;

//-------------------------------------------------------------------------------------------------
// DEPRECATED
typedef struct TLexDateFormat
{
    uint32_t format;    // eLexDateFormat
    char customFormatString[32]; // custom format string in yyyy-MM-dd format
} TLexDateFormat;

#ifdef _WIN32
#pragma deprecated (eLexDateFormat, TLexDateFormat)
#endif // _WIN32

//****************************************************************************
// input image quality check
typedef enum eImageQualityCheckType
{
    IQC_ImageGlares = 0,
    IQC_ImageFocus = 1,
    IQC_ImageResolution = 2,
    IQC_ImageColorness = 3,
    IQC_Perspective = 4,
    IQC_Bounds = 5,
    IQC_ScreenCapture = 6,
    IQC_Portrait = 7,
    IQC_Handwritten = 8,
    IQC_Brightness = 9
} eImageQualityCheckType;

typedef struct TImageQualityCheck
{
    eImageQualityCheckType type;
    eCheckResult result;
    eRPRM_SecurityFeatureType  featureType; // SecurityFeatureType_Blank = 0, SecurityFeatureType_Photo = 2, SecurityFeatureType_MRZ = 3
    TAreaArray *areas;
    float mean;
    float std_dev;
    int probability;
} TImageQualityCheck;

//type RPRM_ResultType_InputImageQuality
typedef struct TImageQualityCheckList
{
    uint32_t Count;
    eCheckResult result;
    TImageQualityCheck **List;
} TImageQualityCheckList;
//****************************************************************************

typedef struct TRfidOrigin
{
    int32_t dg;
    int32_t dgTag;
    int32_t tagEntry;
    int32_t entryView;
} TRfidOrigin;

typedef struct TTextValidity
{
    char* source;
    uint32_t status; // eCheckResult
} TTextValidity;

typedef struct TTextComparison
{
    char* sourceLeft;
    char* sourceRight;
    uint32_t status; // eCheckResult
} TTextComparison;

typedef struct TTextSource
{
    char* source;
    uint32_t containerType; // eRPRM_ResultType
    uint32_t validityStatus; // eCheckResult
} TTextSource;

typedef struct TTextSymbol
{
    uint32_t code;
    RECT rect;
    uint32_t probability; // (0-100%)
} TTextSymbol;

typedef struct TTextFieldValue
{
    char* value;
    char* originalValue;
    uint32_t originalValidity; // eCheckResult
    char* source;
    uint32_t containerType; // eRPRM_ResultType
    uint32_t pageIndex;
    RECT fieldRect;
    TRfidOrigin rfidOrigin;
    uint32_t probability;  // (0-100%)
    uint32_t originalSymbolsCount; // number of symbols
    TTextSymbol* originalSymbols; // array of symbol recognition results
} TTextFieldValue;

typedef struct TTextField
{
    uint16_t fieldType; // eVisualFieldType
    char* fieldName;
    uint16_t lcid;
    char* lcidName;
    uint32_t status; // eCheckResult
    char* value;
    uint32_t valueCount;
    TTextFieldValue* valueList;
    uint32_t validityStatus; // eCheckResult
    uint32_t validityCount;
    TTextValidity* validityList;
    uint32_t comparisonStatus; // eCheckResult
    uint32_t comparisonCount;
    TTextComparison* comparisonList;
} TTextField;

typedef struct TTextResult
{
    uint32_t status; // eCheckResult
    uint32_t validityStatus; // eCheckResult
    uint32_t comparisonStatus; // eCheckResult
    char* dateFormat;
    uint32_t fieldCount;
    TTextField* fieldList;
    uint32_t availableSourceCount;
    TTextSource* availableSourceList;
} TTextResult;

typedef struct TImageFieldValue
{
    char* value;
    char* originalValue;
    char* source;
    uint32_t containerType;
    uint32_t pageIndex;
    uint32_t lightIndex;
    RECT fieldRect;
    TRfidOrigin rfidOrigin;
    uint32_t originalPageIndex;
} TImageFieldValue;

typedef struct TImageField
{
    uint32_t fieldType;
    char* fieldName;
    uint32_t valueCount;
    TImageFieldValue* valueList;
} TImageField;

typedef struct TImageSource
{
    char* source;
    uint32_t containerType;
} TImageSource;

typedef struct TImagesResult
{
    uint32_t fieldCount;
    TImageField* fieldList;
    uint32_t availableSourceCount;
    TImageSource* availableSourceList;
} TImagesResult;

typedef struct TDatabaseCheck
{
    uint32_t recordsCount;
    char * recordsJson;
    char * sqlRequest;
    char * recordsXml;
} TDatabaseCheck;

typedef enum eLED_Color
{
  ledNone     = 0,
  ledRed      = 1,
  ledGreen    = 2,
  ledOrange   = 3,
} eLED_Color;

typedef struct TIndicationLED
{
   WORD wColorLed;
   WORD wFreq;
} TIndicationLED;

typedef struct TDwordArray
{
    uint32_t Count;
    uint32_t *List;
} TDwordArray;

typedef enum eBoundsResultStatus
{
    BRS_None = 0x0,
    BRS_Confirmed = 0x1,
    BRS_HasMrz = 0x2,
    BRS_DetectByMrz = 0x4,
    BRS_FullImage = 0x8
} eBoundsResultStatus;

typedef struct TBoundsResult
{
    int docFormat;
    int Width;
    int Height;
    POINT Center;
    float Angle;
    POINT LeftTop;
    POINT LeftBottom;
    POINT RightTop;
    POINT RightBottom;
    int Inverse;
    BYTE PerspectiveTr; // cut as a quadrangle or as a rectangle
    BYTE ResultStatus; // eBoundsResultStatus combination
    BYTE Reserve1;
    BYTE Reserve2;
    BYTE ObjArea;            // 0-100 (doc area in % from image size)
    BYTE ObjIntAngleDev;    // 0-90  (deviation angle from 90)
    int Dpi;
    int DpiIn;
} TBoundsResult;

//****************************************************************************
// FDS
//****************************************************************************
typedef enum eFDS_Light
{
  fdsWhite      = 1,
  fdsUV365      = 2,
  fdsIR         = 4,
  fdsMaterial   = 6
} eFDS_Light;

typedef enum eFDS_Panel 
{
   FDS_Panel_Main            = 0,
   FDS_Panel_Countries       = 1,
   FDS_Panel_Documents       = 2,
   FDS_Panel_Caption         = 3,
   FDS_Panel_Description     = 4,
   FDS_Panel_Illumination    = 5,
   FDS_Panel_PageType        = 6,
} eFDS_Panel;

typedef enum eFDS_Panel_Position
{
   FDS_Panel_Hide            = 0,
   FDS_Panel_Show            = 1,
   FDS_Panel_ShowTop         = 2,
   FDS_Panel_ShowBottom      = 3,
} eFDS_Panel_Position;

//****************************************************************************
//** SDK DLL callback functions types
//****************************************************************************
typedef void (REGULA_STDCALL *ResultReceivingFunc)( TResultContainer *result, uint32_t *PostAction, uint32_t *PostActionParameter );
typedef void (REGULA_STDCALL *NotifyFunc)(intptr_t code, intptr_t value);

//****************************************************************************
//** SDK DLL exporting functions
//****************************************************************************
#ifdef __cplusplus
REGULA_EXTERNC {
#endif // __cplusplus
  typedef uint32_t   (*_LibraryVersionFunc)();
  typedef void    (*_SetCallbackFuncFunc)( ResultReceivingFunc f1, NotifyFunc f2 );

  typedef long    (*_InitializeFunc)(void *lpParams, HWND hParent);
  typedef long    (*_FreeFunc)();

  typedef long    (*_ExecuteCommandFunc)( long command, void *params, void *result );
  typedef HANDLE  (*_CheckResultFunc)(long type, long idx, long output, void *param);
  typedef long    (*_CheckResultFromListFunc)(HANDLE container, long output, void *param);
  typedef uint32_t   (*_ResultTypeAvailableFunc)(long type);

//memory allocation section ********************************
  typedef long    (*_AllocRawImageContainerFunc)(TRawImageContainer **, long w, long h, long bits_cnt, long resolution);
  typedef long    (*_FreeRawImageContainerFunc)(TRawImageContainer *);

//FDS section **********************************************
  typedef long    (*_FDSUser_ConnectFunc)( HWND hWnd );
  typedef long    (*_FDSUser_DisconnectFunc)();
  typedef long    (*_FDSUser_UpdateWindowFunc)( long w, long h, long show );
  typedef long    (*_FDSUser_UpdatePanelFunc)( long panel, long position, long height );

  typedef long    (*_FDSUser_SelectDocumentFunc)( char *CountryCode, char *DocCode, long Light ); //-V126

#ifdef __cplusplus
};
#endif // __cplusplus

//**********************************************************************************************
//** SDK states, return and notification codes, etc.
//**********************************************************************************************
typedef enum eRPRM_OutputFormat
{
    ofrDefault                      = 0,
    ofrTransport_Clipboard          = 0x00000002,
    ofrTransport_File               = 0x00000004,
    ofrFormat_XML                   = 0x00010000,
    ofrFormat_FileBuffer            = 0x00020000,     //for images only
    ofrFormat_ImagesXML             = 0x00040000,
    ofrFormat_JSON                  = 0x00080000,
    ofrFormat_NoSystemInfo          = 0x00100000,     // do not write system info into file. to be used only with XML or JSON
    
    ofrFileBuffer_File              = ofrTransport_File | ofrFormat_FileBuffer,
    ofrXML_Clipboard                = ofrTransport_Clipboard | ofrFormat_XML,
    ofrXML_File                     = ofrTransport_File | ofrFormat_XML,
    ofrFileBuffer_XML_Clipboard     = ofrXML_Clipboard | ofrFormat_FileBuffer,
    ofrFileBuffer_XML_File          = ofrXML_File | ofrFormat_FileBuffer,
    ofrJSON_Clipboard               = ofrTransport_Clipboard | ofrFormat_JSON,
    ofrJSON_File                    = ofrTransport_File | ofrFormat_JSON,
    ofrFileBuffer_JSON_Clipboard    = ofrJSON_Clipboard | ofrFormat_FileBuffer,
    ofrFileBuffer_JSON_File         = ofrJSON_File | ofrFormat_FileBuffer,
} eRPRM_OutputFormat;

typedef enum eRPRM_ResultStatus
{
    RPRM_ResultStatus_NotAvailable          = (uint32_t)-1, // 0xffffffff,
    RPRM_ResultStatus_EndOfList             = (uint32_t)-2, // 0xfffffffe,
    RPRM_ResultStatus_InvalidParameter      = (uint32_t)-3, // 0xfffffffd,
    RPRM_ResultStatus_IOError               = (uint32_t)-5, // 0xfffffffb,
    RPRM_ResultStatus_InvalidFilename       = (uint32_t)-6, // 0xfffffffa,
    RPRM_ResultStatus_ClipboardError        = (uint32_t)-7, // 0xfffffff9,
    RPRM_ResultStatus_NotEnoughMemory       = (uint32_t)-8, // 0xfffffff8,
    RPRM_ResultStatus_NotSupported          = (uint32_t)-9, // 0xfffffff7,
} eRPRM_ResultStatus;

typedef struct TVideodetectionNotification
{
    uint32_t sensorState;
    TRawImageContainer* image;
    TBoundsResult* mrzPosition;
} TVideodetectionNotification;

typedef enum eRPRM_NotificationCodes
{
    RPRM_Notification_Error                      = 0x00000000,
    RPRM_Notification_DeviceDisconnected         = 0x00000001,
    RPRM_Notification_DocumentReady              = 0x00000002,  
    RPRM_Notification_Scanning                   = 0x00000004,  
    RPRM_Notification_Calibration                = 0x00000008,  
    RPRM_Notification_CalibrationProgress        = 0x00000009,
    RPRM_Notification_CalibrationStep            = 0x0000000A,
    RPRM_Notification_EnumeratingDevices         = 0x0000000C,
    RPRM_Notification_ConnectingDevice           = 0x0000000D,
    RPRM_Notification_DocumentCanBeRemoved       = 0x0000000E,       
    RPRM_Notification_LidOpen                    = 0x0000000F,      
    RPRM_Notification_Processing                 = 0x00000010,  
    RPRM_Notification_DownloadingCalibrationInfo = 0x00000011,
    RPRM_Notification_LicenseExpired             = 0x00000012,
    RPRM_Notification_OperationProgress          = 0x00000013,
    RPRM_Notification_LatestAvailableSDK         = 0x00000014,
    RPRM_Notification_LatestAvailableDatabase    = 0x00000015,
    RPRM_Notification_VideoFrame                 = 0x00000016,    //  value = TVideodetectionNotification*
    RPRM_Notification_CompatibilityMode          = 0x00000017,    ///< indication that device runs in compatibility mode. value = eDeviceLimitations*
} eRPRM_NotificationCodes;

typedef enum eRPRM_ErrorCodes
{
    RPRM_Error_NoError                          = 0x00000000, 
    RPRM_Error_AlreadyDone                      = 0x00000001, 
    RPRM_Error_NoGraphManager                   = 0x00000002, 
    RPRM_Error_CantRegisterMessages             = 0x00000003, 
    RPRM_Error_NoServiceManager                 = 0x00000004,
    RPRM_Error_CantConnectServiceManager        = 0x00000006, 
    RPRM_Error_CantCreateDeviceLibraryEvent     = 0x00000009, 
    RPRM_Error_InvalidParameter                 = 0x0000000C, 
    RPRM_Error_NotInitialized                   = 0x0000000D, 
    RPRM_Error_Busy                             = 0x0000000E, 
    RPRM_Error_NotEnoughMemory                  = 0x00000011, 
    RPRM_Error_BadVideo                         = 0x00000014, 
    RPRM_Error_ScanAborted                      = 0x00000015, 
    RPRM_Error_CantRecognizeDocumentType        = 0x00000016, 
    RPRM_Error_CantSetupSensor                  = 0x00000018, 
    RPRM_Error_NotTrueColorDesktop              = 0x00000019, 
    RPRM_Error_NotAvailable                     = 0x0000001A,
    RPRM_Error_DeviceError                      = 0x0000001B, 
    RPRM_Error_DeviceDisconnected               = 0x00000020,
    RPRM_Error_WrongThreadContext               = 0x00000030,
    RPRM_Error_COMServers                       = 0x00000031,
    RPRM_Error_NoDocumentReadersFound           = 0x00000032,
    RPRM_Error_NoTranslationMngr                = 0x00000033,
    RPRM_Error_NoActiveDevice                   = 0x00000034,
    RPRM_Error_ConnectingDevice                 = 0x00000035,
    RPRM_Error_Failed                           = 0x00000036,
    RPRM_Error_LightIsNotAllowed                = 0x00000037,
    RPRM_Error_ImageIOError                     = 0x00000038,
    RPRM_Error_CantStoreCalibrationData         = 0x00000039,
    RPRM_Error_DeviceNotCalibrated              = 0x0000003A,
    RPRM_Error_CantCompensateDistortion         = 0x0000003B,
    RPRM_Error_OperationCancelled               = 0x0000003C,
    RPRM_Error_CantLocateDocumentBounds         = 0x0000003D,
    RPRM_Error_CantRefineImages                 = 0x0000003E,
    RPRM_Error_CantCropRotateImages             = 0x0000003F,
    RPRM_Error_IncompleteImagesList             = 0x00000040,
    RPRM_Error_CantReadMRZ                      = 0x00000041,
    RPRM_Error_CantFindBarcodes                 = 0x00000042,
    RPRM_Error_DeviceIDNotSupported             = 0x00000043,
    RPRM_Error_DeviceIDNotStored                = 0x00000044,
    RPRM_Error_DeviceDriver                     = 0x00000045,
    RPRM_Error_Calibration_OpenLid              = 0x00000046,
    RPRM_Error_Calibration_Brightness           = 0x00000047, // - bad brightness
    RPRM_Error_Calibration_WhiteBalance         = 0x00000048, // - bad white balance
    RPRM_Error_Calibration_TargetPosition       = 0x00000049, // - bad document position
    RPRM_Error_Calibration_LightBlank           = 0x0000004A, // - a lot of blinks
    RPRM_Error_Calibration_LightDistortion      = 0x0000004B, // - irregular brightness
    RPRM_Error_Calibration_LightLevel           = 0x0000004C, // - very high brightness
    RPRM_Error_Calibration_LightLevelHigh       = 0x0000004D, // - common brightness more than threshold
    RPRM_Error_Calibration_LightLevelLow        = 0x0000004E, // - common brightness less than threshold
    RPRM_Error_8305CameraAbsent                 = 0x00000050,
    RPRM_Error_NotImplemented                   = 0x00000051, // - not implemented
    RPRM_Error_RemoveDocument                   = 0x00000052, // it is necessary to remove document during initialization 
    RPRM_Error_BadDataFile                      = 0x00000053, // data file is absent or corrupted
    RPRM_Error_BadInputImage                    = 0x00000054, // input image has glares or out of focus
} eRPRM_ErrorCodes;

typedef enum eRPRM_Commands
{
    RPRM_Command_Device_Count                   = 0x00000001,  //retrieve a number of available document readers,
                                                                //  result = uint32_t *
    RPRM_Command_Device_Features                = 0x00000002,  //retrieve reader's features,
                                                                //  params = device index, result = TRegulaDeviceProperties **
    RPRM_Command_Device_RefreshList             = 0x00000003,  //refresh list of available readers
                                                                //  result = uint32_t * - returns new device count
    RPRM_Command_Device_ActiveIndex             = 0x00000004,  //retrieve an index of the active reader in the current list of available readers
                                                                //  result = uint32_t *
    RPRM_Command_Device_Connect                 = 0x00000005,  //connect selected document reader,
                                                                //  params = device index
    RPRM_Command_Device_Disconnect              = 0x00000006,  //disconnect active reader

    RPRM_Command_Device_Light_ScanList_Clear    = 0x00000007,  //clear current scanning light list for active reader
    RPRM_Command_Device_Light_ScanList_AddTo    = 0x00000008,  //add light to the scanning list for active reader
                                                                //  params = eRPRM_Lights combination
    RPRM_Command_Device_Light_ScanList_Default  = 0x00000016,  //restore default scan list
    RPRM_Command_Device_Light_ScanList_Count    = 0x00000017,  //retrieve a number of scan list elements
                                                                //  result = uint32_t *
    RPRM_Command_Device_Light_ScanList_Item     = 0x00000018,  //retrieve an item from current scan list
                                                                //  params = item index
                                                                //  result = uint32_t *

    RPRM_Command_Device_Light_TurnOn            = 0x00000009,  //manual light scheme activation, without image processing support
                                                                //  params = eRPRM_Lights combination
    RPRM_Command_Device_LED                     = 0x0000000B,  //manual LED control
                                                                //  params = TIndicationLED *
    RPRM_Command_Device_PlaySound               = 0x0000000F,  //beeper

    RPRM_Command_Device_Set_ParamLowLight       = 0x0000000C,  //params = 0-10, exposure for UV
    RPRM_Command_Device_Get_ParamLowLight       = 0x0000000D,  //result = long * for value

    RPRM_Command_Device_Calibration             = 0x00000015,  //calibrate the device

    RPRM_Command_Process                        = 0x00000019,  //to capture and process images
                                                                //  params = eRPRM_GetImage_Modes combination

    RPRM_Command_Options_GraphicFormat_Count    = 0x0000001A,  //result = uint32_t *
    RPRM_Command_Options_GraphicFormat_Name     = 0x0000001B,  //params = index
                                                                //result = char **
    RPRM_Command_Options_GraphicFormat_Select   = 0x0000001C,  //params = format index
    RPRM_Command_Options_GraphicFormat_ActiveIndex = 0x00000020, //result = uint32_t *

    RPRM_Command_Options_GetSDKCapabilities     = 0x0000001E,  //result = long * for eRPRM_Capabilities combination
    RPRM_Command_Options_GetSDKAuthCapabilities = 0x00000035,  //result = long * for eRPRM_Authenticity combination

    RPRM_Command_Options_Set_MRZTestQualityParams = 0x00000022, //params = TCommandsMRZTestQuality *
    RPRM_Command_Options_Get_MRZTestQualityParams = 0x00000023, //result = TCommandsMRZTestQuality **

    RPRM_Command_ProcessImagesList              = 0x00000024,  //to process a list of images instead of executing live scanning
                                                                //params = TResultContainerList *
                                                                //result = eRPRM_GetImage_Modes combination (as 2nd input parameter)

    RPRM_Command_Options_Set_CurrentDocumentType = 0x00000027, //params = char *, for RPRM_Command_ProcessImagesList to follow
    RPRM_Command_Options_Get_CurrentDocumentType = 0x00000028, //result = char **

    RPRM_Command_Options_Set_CustomDocTypeMode  = 0x00000029,  //params = true or false
    RPRM_Command_Options_Get_CustomDocTypeMode  = 0x0000002A,  //result = long * for true or false

    RPRM_Command_Get_DocumentsInfoList          = 0x0000002B,  //

    RPRM_Command_OCRLexicalAnalyze              = 0x0000002C,  //params = TDocVisualExtendedInfo * with RFID data (if exists)

    RPRM_Command_Device_IsCalibrated            = 0x0000002D,  //check if the device has valid calibration data
                                                                // result = long * for true or false

    RPRM_Command_Options_Set_CheckResultHeight  = 0x0000002E,  //params = desired image height

    RPRM_Command_Device_Set_WorkingVideoMode    = 0x00000030,  //params = eRPRM_VideoModes
    RPRM_Command_Device_Get_WorkingVideoMode    = 0x00000031,  //result = long *

    RPRM_Command_Options_Set_AuthenticityCheckMode = 0x00000032,  //params = eRPRM_Authenticity
    RPRM_Command_Options_Get_AuthenticityCheckMode = 0x00000033,  //result = long *

    RPRM_Command_Options_Get_BatteryStatus      = 0x00000034,    // Get status of installed accumulator batteries
                                                                // params = long - number of accumulator
                                                                // result = long *  0-100%, 0xFF - no battery, 0xFE - charging, 0xF0 - battery level 100%

    RPRM_Command_Options_BuildExtLog            = 0x00000040,     //params = true or false
    RPRM_Command_Device_SetFrequencyDivider     = 0x00000041,     //params = long (0-5)

    RPRM_Command_Device_Get_DriverVersion       = 0x00000042,     //result = long *

    RPRM_Command_Device_APM_Mode                = 0x00000044,     //params = true or false for Advanced Power Management mode

    RPRM_Command_Device_UseVideoDetection       = 0x00000045,     //params = true or false

    RPRM_Command_ExpertAnalyze                  = 0x00000046,     //params = TDocVisualExtendedInfo * with RFID data (if exists)
    RPRM_Command_ClearResults                   = 0x00000047,     //no params
    RPRM_Command_Options_GraphicFormat_SetCompressionRatio  = 0x00000048,     //params - the level of compression (0 - min,  10 - max)
    RPRM_Command_Options_GraphicFormat_GetCompressionRatio  = 0x00000049,     //result = long *
    RPRM_Command_Process_Cancel                   = 0x0000004A,     //no params

    RPRM_Command_ExcludeCapabilities               = 0x0000004B, // params = eRPRM_Capabilities combination to exclude
    RPRM_Command_ExcludeAuthCapabilities           = 0x0000004C, // params = eRPRM_Authenticity combination to exclude

    RPRM_Command_MakeSingleShot                   = 0x0000004D, // make single shot. params = eRPRM_Lights (one value), result = eRPRM_GetImage_Modes combination

    RPRM_Command_Device_GetFrequencyDivider       = 0x0000004E, // get Frequency Divider value;
    
    RPRM_Command_ComplexAuthenticityCheck       = 0x0000004F,    // complex security check for multi-page document
    RPRM_Command_Options_Set_GlareCompensation  = 0x00000050, // glare compensation for Regula readers, params = true or false

    RPRM_Command_Options_Set_ExtendProcessingModes       = 0x00000051, // Turn additional processing modes ON, params = true or false, default = true

    RPRM_Command_Options_Get_AppendVisa                = 0x00000052,        // [deprecated] get current "append visa" mode (false by default)
    RPRM_Command_Options_Set_AppendVisa                = 0x00000053,        // [deprecated] set "append visa" mode (false by default)
    RPRM_Command_Options_Set_MultiPageProcessingMode = 0x00000054,        // set "multipage processing" mode (true by default)

    RPRM_Command_Device_Get_Calibration_FrequencyDivider = 0x00000055,    // get device calibration Frequency Divider value;

    RPRM_Command_PortraitGraphicalAnalyze       = 0x00000056,    // compare portrait images
                                                                // params = TResultContainerList * with additional containers with external data 
                                                                // (e.g. RFID, RPRM_ResultType_LivePortrait or RPRM_ResultType_ExtPortrait if applicable)
    RPRM_Command_Options_Set_SmartUV                = 0x00000057, // UV substitution for Regula readers, params = true or false
    RPRM_Command_Options_Set_RotateResultImages    = 0x00000058, // rotate document images by document type or portrait orientation
    RPRM_Command_BSIDocCheckXML                    = 0x00000059,    // generate BSI document check XML
                                                                // params = TResultContainerList *
                                                                // result = char ** containing XML

    RPRM_Command_Options_Get_QuickMrzProcessing = 0x0000005A,    // Get QuickMrzProcessing parameter value (result = uint32_t*, FALSE by default)
    RPRM_Command_Options_Set_QuickMrzProcessing = 0x0000005B,    // Set QuickMrzProcessing parameter value (params = uint32_t, TRUE/FALSE)

    RPRM_Command_Device_SetVideoDetectionDivider = 0x0000005C,    // Set VideoDetectionFrameSize parameter value (params = uint32_t)
    RPRM_Command_Device_GetVideoDetectionDivider = 0x0000005D,    // Get VideoDetectionFrameSize parameter value (result = uint32_t*)

    RPRM_Command_Device_SetRequiredOcrFields = 0x0000005E,    // Set Required Ocr Fields (params = TDwordArray *)
    RPRM_Command_Device_GetRequiredOcrFields = 0x0000005F,    // Get Required Ocr Fields (result = TDwordArray **)

    RPRM_Command_Options_Get_BatteryNumber = 0x00000060,    // Get number of installed accumulator batteries in device, result - long *.    

    RPRM_Command_Options_Get_QuickBoardingPassProcessing = 0x00000061,    // Get QuickBoardingPassProcessing parameter value (result = uint32_t*, FALSE by default)
    RPRM_Command_Options_Set_QuickBoardingPassProcessing = 0x00000062,    // Set QuickBoardingPassProcessing parameter value (params = uint32_t, TRUE/FALSE)

    RPRM_Command_Options_Set_WaitForReadingComplete        = 0x00000063,    // Set WaitForReadingComplete parameter value (params = uint32_t, TRUE/FALSE)
    RPRM_Command_ReadingComplete                            = 0x00000064,    // RFID reading complete, eject card
    
    RPRM_Command_Options_Get_LexAnalysisDepth = 0x00000065,    // [deprecated] Get LexAnalysisDepth parameter value (result = uint32_t*, (eLexAnalysisDepth)eLAD_Default by default)
    RPRM_Command_Options_Set_LexAnalysisDepth = 0x00000066,    // [deprecated] Set LexAnalysisDepth parameter value (params = uint32_t, eLexAnalysisDepth)

    RPRM_Command_Options_Get_LexDateFormat = 0x00000067,    // [deprecated] Get Lex Date Format parameter value (result = TLexDateFormat**)
    RPRM_Command_Options_Set_LexDateFormat = 0x00000068,    // [deprecated] Set Lex Date Format parameter value (params = TLexDateFormat*)

    RPRM_Command_Device_Get_GetJpegImages = 0x00000069,    // Get GetJpegImages parameter value (result = uint32_t*, FALSE by default)
    RPRM_Command_Device_Set_GetJpegImages = 0x0000006A,    // Set GetJpegImages parameter value (params = uint32_t, TRUE/FALSE)

    RPRM_Command_BSIDocCheckXMLv2 = 0x0000006B,    // generate BSI document check XML v2
                                                // params = TResultContainerList *
                                                // result = char ** containing XML

    RPRM_Command_Options_Get_TrustDPI = 0x0000006C,         // Get TrustDPI parameter value (result = uint32_t*, FALSE by default)
    RPRM_Command_Options_Set_TrustDPI = 0x0000006D,         // Set TrustDPI parameter value (params = uint32_t, TRUE/FALSE)

    RPRM_Command_Options_Get_LexParams = 0x0000006E,        // Get Lex parameters JSON value (result = char **)
    RPRM_Command_Options_Set_LexParams = 0x0000006F,        // Set Lex parameters JSON value (params = char *)
    RPRM_Command_Options_Get_StopOnBadInputImage = 0x00000070,    // Get StopOnBadInputImage parameter value (result = uint32_t*, FALSE by default)
    RPRM_Command_Options_Set_StopOnBadInputImage = 0x00000071,    // Set StopOnBadInputImage parameter value (params = uint32_t, TRUE/FALSE)

    RPRM_Command_Set_ProcessParametersJson = 0x00000072,        // params = char* with process parameters JSON

    RPRM_Command_Options_Set_VideodetectionLowSensibility = 0x00000073, // Set VideodetectionLowSensibility parameter value (params = uint32_t, TRUE/FALSE)
    RPRM_Command_Options_Set_TrustVideodetectionResult = 0x00000074, // Set TrustVideodetectionResult parameter value (params = uint32_t, TRUE/FALSE)
    
    RPRM_Command_Device_Get_LED = 0x00000075, //get LED status. result = TIndicationLED* 
    RPRM_Command_Get_DatabaseInfo = 0x00000076, //get database info. result = char** with database description JSON  

    RPRM_Command_Device_Fingerprints_Scan = 0x00000077, // params - json with dllPath and scanParams
    RPRM_Command_Fingerprints_Compare = 0x00000078, // params - json with dllPath and comparisonParams

    RPRM_Command_Add_External_Containers = 0x00000079, // params - TResultContainerList*
    RPRM_Command_Fingerprints_Search = 0x0000007A, // params - json with dllPath and searchParams
} eRPRM_Commands;

typedef enum eDocumentStatus
{
    eDS_BadImage,
    eDS_DocumentAbsent,
    eDS_DocumentMoving,
    eDS_DocumentFix,
    eDS_DocumentFixWait,
    eDS_DocumentPresent
} eDocumentStatus;

typedef struct TDetailsOptical
{
    eCheckResult overallStatus;
    eCheckResult mrz;
    eCheckResult text;
    eCheckResult docType;
    eCheckResult security;
    eCheckResult imageQA;
    eCheckResult expiry;
    uint32_t pagesCount;
    eCheckResult vds;
} TDetailsOptical;

typedef struct TDetailsRFID
{
    eCheckResult overallStatus;
    eCheckResult PA;
    eCheckResult AA;
    eCheckResult CA;
    eCheckResult TA;
    eCheckResult BAC;
    eCheckResult PACE;
} TDetailsRFID;

typedef struct TStatus
{
    eCheckResult overallStatus;

    TDetailsOptical detailsOptical;
    eCheckResult optical;

    TDetailsRFID detailsRFID;
    eCheckResult rfid;

    eCheckResult portrait;
    eCheckResult stopList;
} TStatus;

#ifdef _WIN32
    #pragma deprecated(RPRM_Command_Options_Get_LexAnalysisDepth, RPRM_Command_Options_Set_LexAnalysisDepth)
    #pragma deprecated(RPRM_Command_Options_Get_LexDateFormat, RPRM_Command_Options_Set_LexDateFormat)
#endif // _WIN32

#ifdef __BORLANDC__ // if we're using a Borland compiler
    #pragma option -a.  // switch back to original alignment
#else   //if NOT using a Borland compiler
    #pragma pack (pop, before_passpr)
#endif  //

#endif
