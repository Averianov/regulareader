//------------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HKEY_Helper.h"
#include "Unit1.h"

#include <array>
#include <algorithm>
#include <System.StrUtils.hpp>

//------------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;

//------------------------------------------------------------------------------

// Get reader name by its id
inline UnicodeString __fastcall GetDeviceNameByID( const uint32_t id )
{
    static const std::array< UnicodeString, 93 > kDeviceTypes
    {
        "Unknown",                    //0
        "7004S",
        "7003.01",
        "7003.110",
        "7003.111",
        "7004.110",
        "70x4.111",
        "70x4.114",
        "70x4.115",
        "7004.100",
        "8303.100",                   //10
        "8303.110",
        "8303.111",
        "8303.114",
        "7104.115",
        "7304.115",
        "7504.115",
        "7384.115",
        "8303.115",
        "8313.115",
        "8333.115",                   //20
        "8353.115",
        "8383.115",
        "7103.115",
        "7303.115",
        "7503.115",
        "7383.115",
        "8314.115",
        "8334.115",
        "8354.115",
        "8384.115",                   //30
        "8305",
        "7107.115",
        "7307.115",
        "7507.115",
        "7387.115",
        "8307",
        "4820 (OV 1.3 Mp)",
        "4820 (OV 3.1 Mp)",
        "4820 (OV 5.1 Mp)",
        "4820 (Micron 3.1 Mp)",       //40
        "4820 (Micron 9.0 Mp)",

        "Virtual Reader",

        "7117.115",
        "7317.115",
        "7517.115",
        "7397.115",                   // 46

        "7024 (Micron 9.0 Mp)",
        "8303 (Micron 9.0 Mp)",
        "8304 (Micron 9.0 Mp)",
        "7007 (Micron 9.0 Mp)",       // 50
        "7003 (Micron 9.0 Mp)",

        "7074",                       // 52
        "7084",                       // 53

        // micron 5 MP
        "8853.115",                   // 54
        "8854.115",                   // 55
        "7857.115",                   //
        "7854.115",                   //
        "7853.115",                   //
        "4858",                       // 59

        "MMM",                         //60
        "7038.115 (Micron 3.1)",      // 61 - Micron 3.1
        "7058.115 (Micron 5.0)",      // 62 - Micron 5.0

        "7308.115 (Micron 3.1)",      // 63 - Micron 3.1
        "78E4 (Micron 14.0)",         // 64 - Micron 14.0
        "70x4.115M (Micron 3.1)",     // 65 - Micron 3.1
        "70x4.115M (Micron 5.0)",     // 66 - Micron 5.0

        "70x4.115M (Micron 10.0)",    // 67 - Micron 10.0
        "78A4 (Micron 10.0)",         // 68 - Micron 10.0
        "7303 (Blackfin)",            // 69
        "7303 (Cypress)",             // 70
        "E_SEEK M-500",               // 71
        "TWAIN scanner",              // 72
        "72x3 (OV 5.1 Mp)",           // 73 RPRM_DeviceType_FX_7253
        "7017 (Micron 5Mp)",          // 74 RPRM_DeviceType_FX_7517
        "7017 (OV 5Mp)",              // 75 RPRM_DeviceType_FX_7017
        "7027 (OV 5Mp)",              // 76 RPRM_DeviceType_FX_7027
        "8303M.115",                  // 77 RPRM_DeviceType_FX_8303_115
        "8803",                       // 78 RPRM_DeviceType_EOS_8803_100
        "8850",                       // 79 RPRM_DeviceType_EOS_8850_5
        "8824 80",                    // 80 RPRM_DeviceType_EOS_8824_80
        "70x8M (OV 5 Mp)",            // 81 RPRM_DeviceType_FX_7058M
        "70x8M (OV 5 Mp, VB)",        // 82 RPRM_DeviceType_FX_7058M_VB
        "7017D Master",               // 83 RPRM_DeviceType_FX_7017D_M
        "7017D Slave",                // 84 RPRM_DeviceType_FX_7017D_S
        "7038.115 (Micron 3.1, VB)",  // 85 RPRM_DeviceType_FX_7038_VB
        "70x4M.115-5A",               // 86 RPRM_DeviceType_FX_76x4M
        "8850M",                      // 87 RPRM_DeviceType_EOS_8850M_9
        "Panasonic-based",            // 88 RPRM_DeviceType_Panasonic
        "7310 Mobile complex",        // 89 RPRM_DeviceType_Mobile_7310
        "70x4.115M (Micron 18.0)",    // 90 - Micron 18.0
        "70x8M (AR 13 Mp)",           // 91 - RPRM_DeviceType_FX_7038M
        "DESKO Penta Scanner",        // 92 - RPRM_DeviceType_Desko
    }; // kDeviceTypes

    switch( id )
    {
    case RPRM_DeviceType_USB20_1:      return kDeviceTypes[ 0 ];
    case RPRM_DeviceType_7004s:        return kDeviceTypes[ 1 ];
    case RPRM_DeviceType_7003_01:      return kDeviceTypes[ 2 ];
    case RPRM_DeviceType_7003_110:     return kDeviceTypes[ 3 ];
    case RPRM_DeviceType_7003_111:     return kDeviceTypes[ 4 ];
    case RPRM_DeviceType_7004_110:     return kDeviceTypes[ 5 ];
    case RPRM_DeviceType_70x4_111:     return kDeviceTypes[ 6 ];
    case RPRM_DeviceType_70x4_114:     return kDeviceTypes[ 7 ];
    case RPRM_DeviceType_70x4_115:     return kDeviceTypes[ 8 ];
    case RPRM_DeviceType_7004_100:     return kDeviceTypes[ 9 ];
    case RPRM_DeviceType_8303_100:     return kDeviceTypes[ 10 ];
    case RPRM_DeviceType_8303_110:     return kDeviceTypes[ 11 ];
    case RPRM_DeviceType_8303_111:     return kDeviceTypes[ 12 ];
    case RPRM_DeviceType_8303_114:     return kDeviceTypes[ 13 ];
    case RPRM_DeviceType_FX_7104_Lite: return kDeviceTypes[ 14 ];
    case RPRM_DeviceType_FX_7104_115:  return kDeviceTypes[ 14 ];
    case RPRM_DeviceType_FX_7304_Lite: return kDeviceTypes[ 15 ];
    case RPRM_DeviceType_FX_7304_115:  return kDeviceTypes[ 15 ];
    case RPRM_DeviceType_FX_7504_Lite: return kDeviceTypes[ 16 ];
    case RPRM_DeviceType_FX_7504_115:  return kDeviceTypes[ 16 ];
    case RPRM_DeviceType_FX_7384_Lite: return kDeviceTypes[ 17 ];
    case RPRM_DeviceType_FX_7384_115:  return kDeviceTypes[ 17 ];
    case RPRM_DeviceType_8303_115:     return kDeviceTypes[ 18 ];
    case RPRM_DeviceType_FX_8313_115:  return kDeviceTypes[ 19 ];
    case RPRM_DeviceType_FX_8333_115:  return kDeviceTypes[ 20 ];
    case RPRM_DeviceType_FX_8353_115:  return kDeviceTypes[ 21 ];
    case RPRM_DeviceType_FX_8383_115:  return kDeviceTypes[ 22 ];
    case RPRM_DeviceType_FX_7103_115:  return kDeviceTypes[ 23 ];
    case RPRM_DeviceType_FX_7303_115:  return kDeviceTypes[ 24 ];
    case RPRM_DeviceType_FX_7503_115:  return kDeviceTypes[ 25 ];
    case RPRM_DeviceType_FX_7383_115:  return kDeviceTypes[ 26 ];
    case RPRM_DeviceType_FX_8314_115:  return kDeviceTypes[ 27 ];
    case RPRM_DeviceType_FX_8334_115:  return kDeviceTypes[ 28 ];
    case RPRM_DeviceType_FX_8354_115:  return kDeviceTypes[ 29 ];
    case RPRM_DeviceType_FX_8384_115:  return kDeviceTypes[ 30 ];
    case RPRM_DeviceType_8305:         return kDeviceTypes[ 31 ];
    case RPRM_DeviceType_FX_7107_115:  return kDeviceTypes[ 32 ];
    case RPRM_DeviceType_FX_7307_115:  return kDeviceTypes[ 33 ];
    case RPRM_DeviceType_FX_7507_115:  return kDeviceTypes[ 34 ];
    case RPRM_DeviceType_FX_7387_115:  return kDeviceTypes[ 35 ];
    case RPRM_DeviceType_FX_8307:      return kDeviceTypes[ 36 ];
    case RPRM_DeviceType_FX_4821:      return kDeviceTypes[ 37 ];
    case RPRM_DeviceType_FX_4823:      return kDeviceTypes[ 38 ];
    case RPRM_DeviceType_FX_4825:      return kDeviceTypes[ 39 ];
    case RPRM_DeviceType_FX_4822:      return kDeviceTypes[ 40 ];
    case RPRM_DeviceType_FX_4828:      return kDeviceTypes[ 41 ];
    case RPRM_DeviceType_Virtual:      return kDeviceTypes[ 42 ];
    case RPRM_DeviceType_FX_7117_115:  return kDeviceTypes[ 43 ];
    case RPRM_DeviceType_FX_7317_115:  return kDeviceTypes[ 44 ];
    case RPRM_DeviceType_FX_7517_115:  return kDeviceTypes[ 45 ];
    case RPRM_DeviceType_FX_7397_115:  return kDeviceTypes[ 46 ];
    case RPRM_DeviceType_FX_7884_Lite: return kDeviceTypes[ 47 ];
    case RPRM_DeviceType_FX_7884_115:  return kDeviceTypes[ 47 ];
    case RPRM_DeviceType_FX_8883_115:  return kDeviceTypes[ 48 ];
    case RPRM_DeviceType_FX_8884_115:  return kDeviceTypes[ 49 ];
    case RPRM_DeviceType_FX_7887_115:  return kDeviceTypes[ 50 ];
    case RPRM_DeviceType_FX_7883_115:  return kDeviceTypes[ 51 ];
    case RPRM_DeviceType_EOS_7074_550: return kDeviceTypes[ 52 ];
    case RPRM_DeviceType_EOS_7084_7:   return kDeviceTypes[ 53 ];
    case RPRM_DeviceType_FX_8853_115:  return kDeviceTypes[ 54 ];
    case RPRM_DeviceType_FX_8854_115:  return kDeviceTypes[ 55 ];
    case RPRM_DeviceType_FX_7857_115:  return kDeviceTypes[ 56 ];
    case RPRM_DeviceType_FX_7854_115:  return kDeviceTypes[ 57 ];
    case RPRM_DeviceType_FX_7854_Lite: return kDeviceTypes[ 57 ];
    case RPRM_DeviceType_FX_7853_115:  return kDeviceTypes[ 58 ];
    case RPRM_DeviceType_FX_4858:      return kDeviceTypes[ 59 ];
    case RPRM_DeviceType_3M:           return kDeviceTypes[ 60 ];
    case RPRM_DeviceType_FX_7038:      return kDeviceTypes[ 61 ];
    case RPRM_DeviceType_FX_7058:      return kDeviceTypes[ 62 ];
    case RPRM_DeviceType_FX_7338:      return kDeviceTypes[ 63 ];
    case RPRM_DeviceType_FX_78E4_115:  return kDeviceTypes[ 64 ];
    case RPRM_DeviceType_FX_78E4_Lite: return kDeviceTypes[ 64 ];
    case RPRM_DeviceType_FX_73x4M:     return kDeviceTypes[ 65 ];
    case RPRM_DeviceType_FX_75x4M:     return kDeviceTypes[ 66 ];
    case RPRM_DeviceType_FX_71x4M:     return kDeviceTypes[ 67 ];
    case RPRM_DeviceType_FX_78A4_115:  return kDeviceTypes[ 68 ];
    case RPRM_DeviceType_FX_78A4_Lite: return kDeviceTypes[ 68 ];
    case RPRM_DeviceType_73xx:         return kDeviceTypes[ 69 ];
    case RPRM_DeviceType_BK:           return kDeviceTypes[ 70 ];
    case RPRM_DeviceType_M500:         return kDeviceTypes[ 71 ];
    case RPRM_DeviceType_TWAIN:        return kDeviceTypes[ 72 ];
    case RPRM_DeviceType_FX_7253:      return kDeviceTypes[ 73 ];
    case RPRM_DeviceType_FX_7517:      return kDeviceTypes[ 74 ];
    case RPRM_DeviceType_FX_7017:      return kDeviceTypes[ 75 ];
    case RPRM_DeviceType_FX_7027:      return kDeviceTypes[ 76 ];
    case RPRM_DeviceType_FX_8303_115:  return kDeviceTypes[ 77 ];
    case RPRM_DeviceType_EOS_8803_100: return kDeviceTypes[ 78 ];
    case RPRM_DeviceType_EOS_8850_5:   return kDeviceTypes[ 79 ];
    case RPRM_DeviceType_EOS_8824_80:  return kDeviceTypes[ 80 ];
    case RPRM_DeviceType_FX_7058M:     return kDeviceTypes[ 81 ];
    case RPRM_DeviceType_FX_7058M_VB:  return kDeviceTypes[ 82 ];
    case RPRM_DeviceType_FX_7017D_M:   return kDeviceTypes[ 83 ];
    case RPRM_DeviceType_FX_7017D_S:   return kDeviceTypes[ 84 ];
    case RPRM_DeviceType_FX_7038_VB:   return kDeviceTypes[ 85 ];
    case RPRM_DeviceType_FX_76x4M:     return kDeviceTypes[ 86 ];
    case RPRM_DeviceType_EOS_8850M_9:  return kDeviceTypes[ 87 ];
    case RPRM_DeviceType_Panasonic:    return kDeviceTypes[ 88 ];
    case RPRM_DeviceType_Mobile_7310:  return kDeviceTypes[ 89 ];
    case RPRM_DeviceType_FX_78x4M:     return kDeviceTypes[ 90 ];
    case RPRM_DeviceType_FX_7038M:     return kDeviceTypes[ 91 ];
    case RPRM_DeviceType_Desko:        return kDeviceTypes[ 92 ];
    default:
        break;
    }
    return kDeviceTypes[ 0 ];
}

//------------------------------------------------------------------------------

inline
UnicodeString ErrorToStr( const eRPRM_ErrorCodes msg )
{
    UnicodeString str;
    switch( msg )
    {
    case RPRM_Error_NoError:
        str = L"Success";
        break;
    case RPRM_Error_AlreadyDone:
        str = L"RPRM_Error_AlreadyDone";
        break;
    case RPRM_Error_NoGraphManager:
        str = L"RPRM_Error_NoGraphManager";
        break;
    case RPRM_Error_CantRegisterMessages:
        str = L"RPRM_Error_CantRegisterMessages";
        break;
    case RPRM_Error_NoServiceManager:
        str = L"RPRM_Error_NoServiceManager";
        break;
    case RPRM_Error_CantConnectServiceManager:
        str = L"RPRM_Error_CantConnectServiceManager";
        break;
    case RPRM_Error_CantCreateDeviceLibraryEvent:
        str = L"RPRM_Error_CantCreateDeviceLibraryEvent";
        break;
    case RPRM_Error_InvalidParameter:
        str = L"RPRM_Error_InvalidParameter";
        break;
    case RPRM_Error_NotInitialized:
        str = L"RPRM_Error_NotInitialized";
        break;
    case RPRM_Error_Busy:
        str = L"RPRM_Error_Busy";
        break;
    case RPRM_Error_NotEnoughMemory:
        str = L"RPRM_Error_NotEnoughMemory";
        break;
    case RPRM_Error_BadVideo:
        str = L"RPRM_Error_BadVideo";
        break;
    case RPRM_Error_ScanAborted:
        str = L"RPRM_Error_ScanAborted";
        break;
    case RPRM_Error_CantRecognizeDocumentType:
        str = L"RPRM_Error_CantRecognizeDocumentType";
        break;
    case RPRM_Error_CantSetupSensor:
        str = L"RPRM_Error_CantSetupSensor";
        break;
    case RPRM_Error_NotTrueColorDesktop:
        str = L"RPRM_Error_NotTrueColorDesktop";
        break;
    case RPRM_Error_NotAvailable:
        str = L"RPRM_Error_NotAvailable";
        break;
    case RPRM_Error_DeviceError:
        str = L"RPRM_Error_DeviceError";
        break;
    case RPRM_Error_DeviceDisconnected:
        str = L"RPRM_Error_DeviceDisconnected";
        break;
    case RPRM_Error_WrongThreadContext:
        str = L"RPRM_Error_WrongThreadContext";
        break;
    case RPRM_Error_COMServers:
        str = L"RPRM_Error_COMServers";
        break;
    case RPRM_Error_NoDocumentReadersFound:
        str = L"RPRM_Error_NoDocumentReadersFound";
        break;
    case RPRM_Error_NoTranslationMngr:
        str = L"RPRM_Error_NoTranslationMngr";
        break;
    case RPRM_Error_NoActiveDevice:
        str = L"RPRM_Error_NoActiveDevice";
        break;
    case RPRM_Error_ConnectingDevice:
        str = L"RPRM_Error_ConnectingDevice";
        break;
    case RPRM_Error_Failed:
        str = L"RPRM_Error_Failed";
        break;
    case RPRM_Error_LightIsNotAllowed:
        str = L"RPRM_Error_LightIsNotAllowed";
        break;
    case RPRM_Error_ImageIOError:
        str = L"RPRM_Error_ImageIOError";
        break;
    case RPRM_Error_CantStoreCalibrationData:
        str = L"RPRM_Error_CantStoreCalibrationData";
        break;
    case RPRM_Error_DeviceNotCalibrated:
        str = L"RPRM_Error_DeviceNotCalibrated";
        break;
    case RPRM_Error_CantCompensateDistortion:
        str = L"RPRM_Error_CantCompensateDistortion";
        break;
    case RPRM_Error_OperationCancelled:
        str = L"RPRM_Error_OperationCancelled";
        break;
    case RPRM_Error_CantLocateDocumentBounds:
        str = L"RPRM_Error_CantLocateDocumentBounds";
        break;
    case RPRM_Error_CantRefineImages:
        str = L"RPRM_Error_CantRefineImages";
        break;
    case RPRM_Error_CantCropRotateImages:
        str = L"RPRM_Error_CantCropRotateImages";
        break;
    case RPRM_Error_IncompleteImagesList:
        str = L"RPRM_Error_IncompleteImagesList";
        break;
    case RPRM_Error_CantReadMRZ:
        str = L"RPRM_Error_CantReadMRZ";
        break;
    case RPRM_Error_CantFindBarcodes:
        str = L"RPRM_Error_CantFindBarcodes";
        break;
    case RPRM_Error_DeviceIDNotSupported:
        str = L"RPRM_Error_DeviceIDNotSupported";
        break;
    case RPRM_Error_DeviceIDNotStored:
        str = L"RPRM_Error_DeviceIDNotStored";
        break;
    case RPRM_Error_DeviceDriver:
        str = L"RPRM_Error_DeviceDriver";
        break;
    case RPRM_Error_Calibration_OpenLid:
        str = L"RPRM_Error_Calibration_OpenLid";
        break;
    case RPRM_Error_Calibration_Brightness:
        str = L"RPRM_Error_Calibration_Brightness";
        break;
    case RPRM_Error_Calibration_WhiteBalance:
        str = L"RPRM_Error_Calibration_WhiteBalance";
        break;
    case RPRM_Error_Calibration_TargetPosition:
        str = L"RPRM_Error_Calibration_TargetPosition";
        break;
    case RPRM_Error_Calibration_LightBlank:
        str = L"RPRM_Error_Calibration_LightBlank: blank spots detected";
        break;
    case RPRM_Error_Calibration_LightDistortion:
        str = L"RPRM_Error_Calibration_LightDistortion";
        break;
    case RPRM_Error_Calibration_LightLevel:
        str =
          L"RPRM_Error_Calibration_LightLevel: lighting level is unacceptable";
        break;
    case RPRM_Error_Calibration_LightLevelHigh:
        str = L"RPRM_Error_Calibration_LightLevelHigh";
        break;
    case RPRM_Error_Calibration_LightLevelLow:
        str = L"RPRM_Error_Calibration_LightLevelLow";
        break;
    case RPRM_Error_8305CameraAbsent:
        str = L"RPRM_Error_8305CameraAbsent: "
                    L"Check camera or accumulator connection";
        break;
    case RPRM_Error_NotImplemented:
        str = L"RPRM_Error_NotImplemented";
        break;
    case RPRM_Error_RemoveDocument:
        str = L"RPRM_Error_RemoveDocument";
        break;
    case RPRM_Error_BadDataFile:
        str = L"RPRM_Error_BadDataFile";
        break;
    case RPRM_Error_BadInputImage:
        str = L"RPRM_Error_BadInputImage";
        break;

    default:
        str = "Unknown";
        break;
    }
    return str;
}

//------------------------------------------------------------------------------
// Returns lighting scheme abbreviations depending on eRPRM_Lights flags
inline
UnicodeString GetLSName( const DWORD light )
{
    UnicodeString str;
    UnicodeString comma;

    auto append = [ &str, &comma ]( const UnicodeString& meaning )
    {
        str += comma + meaning;
        comma = ", ";
    };

    if( light & RPRM_Light_OVI )
    {
        append( "OVI" );
    }

    if( light & RPRM_Light_White_Top )
    {
        append( "Wt" );
    }

    if( light & RPRM_Light_White_Side )
    {
        append( "Ws" );
    }

    if( light & RPRM_Light_IR_Top )
    {
        append( "IRt" );
    }

    if( light & RPRM_Light_IR_Side )
    {
        append( "IRs" );
    }

    if( light & RPRM_Light_Transmitted )
    {
        append( "LT" );
    }

    if( light & RPRM_Light_Transmitted_IR )
    {
        append( "LT IR" );
    }

    if( light & RPRM_Light_UV )
    {
        append( "UV" );
    }

    if( light & RPRM_Light_IR_Luminescence )
    {
        append( "IRLum" );
    }

    if( light & RPRM_Light_AXIAL_White_Front )
    {
        append( "AxW+" );
    }

    if( light & RPRM_Light_AXIAL_White_Left )
    {
        append( "AxWl" );
    }

    if( light & RPRM_Light_AXIAL_White_Right )
    {
        append( "AxWr" );
    }

    if( light & RPRM_Light_IR_720 )
    {
        append( "IR720" );
    }

    if( light & RPRM_Light_IR_940 )
    {
        append( "IR940" );
    }

    if( light & RPRM_Light_Transmitted_IR940 )
    {
        append( "IR940t" );
    }

    if( light & RPRM_Light_IR_700 )
    {
        append( "IR700" );
    }

    if( light & RPRM_Light_AntiStokes )
    {
        append( "Anti" );
    }

    if( light & RPRM_Light_OVD_Left )
    {
        append( "OVDl" );
    }

    if( light & RPRM_Light_OVD_Right )
    {
        append( "OVDr" );
    }

    if( light & RPRM_Light_UVC )
    {
        append( "UVC" );
    }

    if( light & RPRM_Light_UVB )
    {
        append( "UVB" );
    }

    if( light & RPRM_Light_White_Obl )
    {
        append( "OblW" );
    }

    if( light & RPRM_Light_White_Special )
    {
        append( "Wspec" );
    }

    if( light & RPRM_Light_White_Front )
    {
        append( "W+" );
    }

    if( light & RPRM_Light_IR_Front )
    {
        append( "IR+" );
    }

    if( light & RPRM_Light_White_Gray )
    {
        append( "Wgrey" );
    }

    if( light & RPRM_Light_OVD )
    {
        append( "lOVD" );
    }

    if( light & RPRM_Light_Videodetection )
    {
        append( "Dtct" );
    }

    if( light & RPRM_Light_IR_870_Obl )
    {
        append( "IR940" );
    }

    if( light & RPRM_Light_HR_Light )
    {
        append( "HRl" );
    }

    if( light & RPRM_Light_RAW_Data )
    {
        append( "Raw" );
    }

    if( light & RPRM_Light_RAW_Data_GRBG )
    {
        append( "GRBG" );
    }

    if( light & RPRM_Light_RAW_Data_GBRG )
    {
        append( "GBRG" );
    }

    if( light & RPRM_Light_RAW_Data_RGGB )
    {
        append( "RGGB" );
    }

    if( light & RPRM_Light_RAW_Data_BGGR )
    {
        append( "BGGR" );
    }

    return str;
}

//******************************************************************************
//******************************************************************************

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner),
          m_hLib                  {},
          m_activeDevice          {},
          m_SDKCapabilities       {},
          m_deviceConnected       {},
          m_currentVideoMode      { RPRM_VM_UNDEFINED },
          m_liStartTime           {},
          m_availableLight        {},
          Initialize              {},
          Free                    {},
          SetCallbackFunc         {},
          ExecuteCommand          {},
          CheckResult             {},
          AllocRawImageContainer  {},
          FreeRawImageContainer   {},
          CheckResultFromList     {},
          ResultTypeAvailable     {}
{
}

//------------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
    ImagesTabControl->Tabs->Clear();
    UpdateControls();
}

//------------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject* Sender, TCloseAction& Action)
{
    FreeLibraryButtonClick( nullptr );
    Action = m_hLib ? caNone : caFree;
}

//------------------------------------------------------------------------------

void __fastcall TForm1::LoadLibraryButtonClick(TObject *Sender)
{
    Memo1->Clear();

    // Get Registry sub-key holding library path depending on Windows bitness
    ::SYSTEM_INFO info {};
    ::GetSystemInfo( &info );

    const wchar_t* subKey {};
    switch( info.wProcessorArchitecture )
    {
    case PROCESSOR_ARCHITECTURE_AMD64:
        subKey = L"SOFTWARE\\Regula\\Document Reader SDK (x64)";
        break;
    case PROCESSOR_ARCHITECTURE_INTEL:
        subKey = L"SOFTWARE\\Regula\\Document Reader SDK";
        break;
    default:
        throw Exception { "Unsupported architecture" };
    }

    // Get PasspR40.dll path
    const HKEY_Helper hKey { subKey };

    // Query size of the Path
    const wchar_t* Name = L"Path";
    DWORD bufSz {};
    auto ec = ::RegQueryValueExW( hKey,
                                  Name,
                                  nullptr,
                                  nullptr,
                                  nullptr,
                                  &bufSz );
    if( ec != ERROR_SUCCESS )
    {
        throw Exception { "Cannot query Registry" };
    }

    if( 0 == bufSz )
    {
        throw Exception { "Empty Path key!" };
    }

    // Get the 'Path' key value and build a path to PasspR40.dll
    const wchar_t* libName = L"\\PasspR40.dll";
    const auto oldBufSz = bufSz;
    bufSz += std::wcslen( libName ) + sizeof( L'\0' );
    auto result = std::make_unique< wchar_t[] >( bufSz );
    std::memset( &result[0], 0, bufSz );

    ec = ::RegQueryValueExW( hKey,
                             Name,
                             nullptr,
                             nullptr,
                             reinterpret_cast< LPBYTE >( &result[ 0 ] ),
                             &bufSz );

    if( ec != ERROR_SUCCESS )
    {
        throw Exception { "Cannot read Registry" };
    }

    const auto lastChar = oldBufSz / sizeof( wchar_t ) - 1;
    if( result[ lastChar ] == L'\0' )
    {
        std::wcscpy( &result[lastChar], libName );
    }
    else
    {
        // The value returned is NOT guaranteed to be null-terminated
        std::wcscpy( &result[ lastChar + 1 ], libName );
    }

    // Load the PasspR40.dll and load its functions
    const auto& libPath = &result[ 0 ];
    m_hLib = ::LoadLibrary( libPath );
    if( !m_hLib )
    {
        System::UnicodeString msg { "Cannot load " };
        msg += libPath;
        throw Exception { msg };
    }

    _LibraryVersionFunc LibraryVersion {};

    try
    {
        LoadFun( LibraryVersion, "_LibraryVersion" );
        LoadFun( Initialize, "_Initialize" );
        LoadFun( Free, "_Free" );
        LoadFun( SetCallbackFunc, "_SetCallbackFunc" );
        LoadFun( ExecuteCommand, "_ExecuteCommand" );
        LoadFun( CheckResult, "_CheckResult" );
        LoadFun( AllocRawImageContainer, "_AllocRawImageContainer" );
        LoadFun( FreeRawImageContainer, "_FreeRawImageContainer" );
        LoadFun( CheckResultFromList, "_CheckResultFromList" );
        LoadFun( ResultTypeAvailable, "_ResultTypeAvailable" );
    }
    catch( ... )
    {
        ::FreeLibrary( m_hLib );
        m_hLib = 0;
        throw;
    }

    // Set callbacks which must be called before calling the Initialize()
    SetCallbackFunc( MyResultReceivingFunc, MyNotifyFunc );

    const auto ver = LibraryVersion();
    LibraryVersionLabel->Caption = IntToStr( HIWORD( ver ) ) +
                                   "." +
                                   IntToStr( LOWORD( ver ) );

    ::QueryPerformanceCounter( &m_liStartTime );
    UpdateControls();
}

//------------------------------------------------------------------------------

void __fastcall TForm1::UpdateControls()
{
    IntializeButton->Enabled = m_hLib;
    FreeLibraryButton->Enabled = m_hLib;
    LoadLibraryButton->Enabled = ! m_hLib;

    // Video detection button
    SB_VideoDetection->Enabled = m_hLib;
    SB_VideoDetection->Visible = m_hLib;

    // Connect/Disconnect button
    ConnectDeviceButton->Enabled = m_hLib;
    ConnectDeviceButton->Down = m_deviceConnected;
    ConnectDeviceButton->Caption = m_deviceConnected ? "Disconnect" : "Connect";

    ProcessButton->Enabled = m_deviceConnected;

    SaveImagesCheckBox->Enabled = m_deviceConnected;
    XMLCheckBox->Enabled = m_deviceConnected;
    ClipboardCheckBox->Enabled = m_deviceConnected;
    FileCheckBox->Enabled = m_deviceConnected;
    LightCheckListBox->Enabled = m_deviceConnected;

    const bool location_is_available =
        m_SDKCapabilities & RPRM_Capabilities_LocateDocument;

    LocateCheckBox->Checked =
        LocateCheckBox->Checked ||
        MRZCheckBox->Checked ||
        MRZTestQualityCheckBox->Checked ||
        DocTypeCheckBox->Checked ||
        BarCodesCheckBox->Checked ||
        VisualOCRCheckBox->Checked ||
        AuthenticityCheckBox->Checked;

    LocateCheckBox->Enabled =
        m_deviceConnected &&
        location_is_available &&
        !MRZCheckBox->Checked &&
        !MRZTestQualityCheckBox->Checked &&
        !DocTypeCheckBox->Checked &&
        !BarCodesCheckBox->Checked &&
        !VisualOCRCheckBox->Checked &&
        !AuthenticityCheckBox->Checked;

    MRZCheckBox->Enabled =
        m_deviceConnected &&
        (m_SDKCapabilities & RPRM_Capabilities_MRZ_OCR) &&
        location_is_available;

    ScanImagesCheckBox->Enabled =
        m_deviceConnected &&
        (m_SDKCapabilities & RPRM_Capabilities_Scan);

    AllImagesCheckBox->Enabled =
        m_deviceConnected &&
        (m_SDKCapabilities & RPRM_Capabilities_Visual_OCR) &&
        location_is_available;

    MRZTestQualityCheckBox->Enabled =
        m_deviceConnected &&
        (m_SDKCapabilities & RPRM_Capabilities_MRZ_TestQuality) &&
        location_is_available;

    BarCodesCheckBox->Enabled =
        m_deviceConnected &&
        (m_SDKCapabilities & RPRM_Capabilities_BarCodes) &&
        location_is_available;

    DocTypeCheckBox->Enabled =
        m_deviceConnected &&
        (m_SDKCapabilities & RPRM_Capabilities_Visual_OCR) &&
        location_is_available;

    VisualOCRCheckBox->Enabled =
        m_deviceConnected &&
        (m_SDKCapabilities & RPRM_Capabilities_Visual_OCR) &&
        location_is_available;

    AuthenticityCheckBox->Enabled =
        m_deviceConnected &&
        (m_SDKCapabilities & RPRM_Capabilities_Authenticity) &&
        location_is_available;

    OCRLexAnalisysButton->Enabled =
        m_deviceConnected &&
        (m_SDKCapabilities & RPRM_Capabilities_OCR_Analyze) &&
        location_is_available;

    {
        const auto it = std::find( m_availableLight.begin(),
                                   m_availableLight.end(),
                                   RPRM_Light_UV );
        UVExpSpinEdit->Visible = ( it != m_availableLight.end() );
        UVExpLabel->Visible = UVExpSpinEdit->Visible;
        UVExpSpinEdit->Enabled = m_deviceConnected;
        UVExpLabel->Enabled = UVExpSpinEdit->Enabled;
    }

    int fl = m_activeDevice.AvailableVideoModes & RPRM_VM_1MP;
    SB_1mp->Visible = m_deviceConnected;
    SB_1mp->Enabled = fl;

    fl = m_activeDevice.AvailableVideoModes & RPRM_VM_3MP;
    SB_3mp->Visible = m_deviceConnected;
    SB_3mp->Enabled = fl;

    fl = m_activeDevice.AvailableVideoModes & RPRM_VM_5MP;
    SB_5mp->Visible = m_deviceConnected;
    SB_5mp->Enabled = fl;

    fl = m_activeDevice.AvailableVideoModes & RPRM_VM_9MP_2;
    SB_92mp->Visible = m_deviceConnected;
    SB_92mp->Enabled = fl;

    fl = m_activeDevice.AvailableVideoModes & RPRM_VM_9MP;
    SB_9mp->Visible = m_deviceConnected;
    SB_9mp->Enabled = fl;

    if( m_currentVideoMode == RPRM_VM_1MP )
    {
        SB_1mp->Down = true;
    }
    else if( m_currentVideoMode == RPRM_VM_3MP )
    {
        SB_3mp->Down = true;
    }
    else if( m_currentVideoMode == RPRM_VM_5MP )
    {
        SB_5mp->Down = true;
    }
    else if( m_currentVideoMode == RPRM_VM_9MP_2 )
    {
        SB_92mp->Down = true;
    }
    else if( m_currentVideoMode == RPRM_VM_9MP )
    {
        SB_9mp->Down = true;
    }
}

//------------------------------------------------------------------------------

void __fastcall TForm1::IntializeButtonClick(TObject *Sender)
{
    const auto res = Initialize( nullptr, Handle );

    if( ( res != RPRM_Error_NoError ) &&
        ( res != RPRM_Error_AlreadyDone ) )
    {
        LogMessage( L"Initialize() return code = 0x%08X", res );
        FreeLibraryButtonClick( nullptr );
    }
    else
    {
        LogMessage( L"Initialized" );
    }

    UpdateControls();
}

//------------------------------------------------------------------------------

void __fastcall TForm1::FreeLibraryButtonClick(TObject *Sender)
{
    if( ! m_hLib )
    {
        LogMessage( L"Not initialized" );
        return;
    }

    Disconnect();

    const auto res = Free();
    if( ( res == RPRM_Error_NoError ) || ( res == RPRM_Error_NotInitialized ) )
    {
        ::FreeLibrary( m_hLib );
        m_hLib = 0;

        Initialize = nullptr;
        Free = nullptr;
        SetCallbackFunc = nullptr;
        ExecuteCommand = nullptr;
        CheckResult = nullptr;
        CheckResultFromList = nullptr;
        ResultTypeAvailable = nullptr;

        LibraryVersionLabel->Caption = "";
    }

    UpdateControls();
}

//------------------------------------------------------------------------------

void __fastcall TForm1::ConnectDeviceButtonClick(TObject *Sender)
{
    if( ConnectDeviceButton->Down )
    {
        const auto enabled = SB_VideoDetection->Down;
        Call< RPRM_Command_Device_UseVideoDetection >( enabled );
        Connect();
    }
    else
    {
        Disconnect();
    }
}

//------------------------------------------------------------------------------

void __fastcall TForm1::ProcessButtonClick(TObject *Sender)
{
    CleanupImageContainer( m_imagesTabs );
    ImagesTabControl->Tabs->Clear();

    // Check MRZ
    if( MRZTestQualityCheckBox->Checked )
    {
        TCommandsMRZTestQuality quality;
        quality.EXEC_SYMBOLS_PARAM = TRUE;
        quality.EXEC_PRINT_POSITION = TRUE;
        quality.EXEC_TEXTUAL_FILLING = TRUE;
        quality.EXEC_CHECK_SUMS = TRUE;
        quality.TEST_CLASS_QUALITY = mrz_CLASS_QUALITY_Z;

        Call< RPRM_Command_Options_Set_MRZTestQualityParams >( &quality );
    }

    // Populate the lighting schemes list before scanning
    Call< RPRM_Command_Device_Light_ScanList_Clear >();
    for( int i {}; i < LightCheckListBox->Items->Count; i++ )
    {
        if( LightCheckListBox->Checked[ i ] )
        {
            const auto lsId = m_availableLight.at( i );
            Call< RPRM_Command_Device_Light_ScanList_AddTo >( lsId );
        }
    }

    // Obtain document authenticity check results
    if( AuthenticityCheckBox->Checked )
    {
        const uint32_t mode = RPRM_Authenticity_IPI |  /*
                              RPRM_Authenticity_BarcodeFormatCheck |*/
                              RPRM_Authenticity_UV;

        Call< RPRM_Command_Options_Set_AuthenticityCheckMode >( mode );
    }

    // Process and get results
    const auto processingMode = GetProcessingMode();
    const auto res = Call< RPRM_Command_Process >( processingMode );
    LogMessage( L"RPRM_Command_Process return code = 0x%08X", res );
    if( res == RPRM_Error_NoError )
    {
        const auto mode = GetDirectQueryMode();
        if( mode )
        {
            DoDirectQuery( mode );
        }
    }
}

//------------------------------------------------------------------------------

void __fastcall TForm1::OCRLexAnalisysButtonClick(TObject *Sender)
{
    const auto res = Call< RPRM_Command_OCRLexicalAnalyze >( nullptr );
    if( res == RPRM_Error_NoError )
    {
        const auto mode = GetDirectQueryMode();
        if( mode )
        {
            GetResult< RPRM_ResultType_OCRLexicalAnalyze >(
                mode,
                [ this ]( auto ) -> UnicodeString
                {
                    const auto path = GetTestDataPath();
                    return path + "ocr_lex_an.xml";
                }
            );
        }
    }
}

//------------------------------------------------------------------------------

void __fastcall TForm1::PaintBoxPaint(TObject *Sender)
{
    if( m_imagesTabs.empty() ||
        ( ImagesTabControl->TabIndex < 0 ) ||
        ( ImagesTabControl->TabIndex >= m_imagesTabs.size() ) )
    {
        return;
    }

    auto im = m_imagesTabs.at( ImagesTabControl->TabIndex );
    if( !im )
    {
        return;
    }

    const float rrr
    {
        static_cast< float >( PaintBox->Width ) /
        static_cast< float >( PaintBox->Height )
    };

    const float rdd
    {
        static_cast< float >( im->bmi->bmiHeader.biWidth ) /
        static_cast< float >( im->bmi->bmiHeader.biHeight )
    };

    float ratio;
    if( rrr<rdd )
    {
        ratio = im->bmi->bmiHeader.biWidth /
                static_cast< float >( PaintBox->Width );
    }
    else
    {
        ratio = im->bmi->bmiHeader.biHeight /
                static_cast< float >( PaintBox->Height );
    }

    ::SetStretchBltMode( PaintBox->Canvas->Handle, STRETCH_DELETESCANS );

    const auto& hdr = im->bmi->bmiHeader;
    ::StretchDIBits( PaintBox->Canvas->Handle,
                     0,
                     0,
                     static_cast< float >( hdr.biWidth / ratio ),
                     static_cast< float >( hdr.biHeight / ratio ),
                     0,
                     0,
                     hdr.biWidth,
                     hdr.biHeight,
                     im->bits,
                     im->bmi,
                     DIB_RGB_COLORS,
                     SRCCOPY );
}

//------------------------------------------------------------------------------

void __fastcall TForm1::ImagesTabControlChange(TObject *Sender)
{
    PaintBox->Invalidate();
}

//------------------------------------------------------------------------------

void __fastcall TForm1::CheckBoxClick(TObject *Sender)
{
    UpdateControls();
}

//------------------------------------------------------------------------------

void __fastcall TForm1::SB_1mpClick(TObject *Sender)
{
    SetWorkingVideoMode( RPRM_VM_1MP );
}

//------------------------------------------------------------------------------

void __fastcall TForm1::SB_3mpClick(TObject *Sender)
{
    SetWorkingVideoMode( RPRM_VM_3MP );
}

//------------------------------------------------------------------------------

void __fastcall TForm1::SB_5mpClick(TObject *Sender)
{
    SetWorkingVideoMode( RPRM_VM_5MP );
}

//------------------------------------------------------------------------------

void __fastcall TForm1::SB_92mpClick(TObject *Sender)
{
    SetWorkingVideoMode( RPRM_VM_9MP_2 );
}

//------------------------------------------------------------------------------

void __fastcall TForm1::SB_9mpClick(TObject *Sender)
{
    SetWorkingVideoMode( RPRM_VM_9MP );
}

//------------------------------------------------------------------------------

void __fastcall TForm1::UVExpSpinEditChange(TObject *Sender)
{
    SetUVExposure( UVExpSpinEdit->Value );
}
//------------------------------------------------------------------------------

void __fastcall TForm1::PaintDocPresenceBox( const TColor color )
{
    Shape1->Brush->Color = color;
}

//------------------------------------------------------------------------------

void TForm1::LogMessage( const wchar_t *fmt, ... ) const
{
    va_list args;
    va_start( args, fmt );

    UnicodeString str;
    str.vprintf( fmt, args );

    LogMessage( str );

    va_end( args );
}

//------------------------------------------------------------------------------

void TForm1::LogMessage( const UnicodeString& msg ) const
{
    LARGE_INTEGER liFinish;
    ::QueryPerformanceCounter( &liFinish );

    LARGE_INTEGER liFreq;
    ::QueryPerformanceFrequency( &liFreq );

    const double dd
    {
        static_cast< double >( liFinish.QuadPart - m_liStartTime.QuadPart )
        /
        static_cast< double >( liFreq.LowPart )
    };

    UnicodeString timestr;
    timestr.printf( TEXT("%0.4f sec"), dd );

    Memo1->Lines->Add( timestr + ":   " + msg );
}

//------------------------------------------------------------------------------

long __fastcall TForm1::GetDirectQueryMode() const
{
    long mode {};
    if( SaveImagesCheckBox->Checked )
    {
        mode |= ofrFormat_FileBuffer;
    }

    if( FileCheckBox->Checked )
    {
        mode |= ofrTransport_File;
    }

    if( XMLCheckBox->Checked )
    {
        mode |= ofrFormat_XML;
    }

    if( ClipboardCheckBox->Checked )
    {
        mode |= ofrTransport_Clipboard;
    }
    return mode;
}

//------------------------------------------------------------------------------

void __fastcall TForm1::DoDirectQuery( const long mode )
{
    DWORD imgFormat {};
    Get< RPRM_Command_Options_GraphicFormat_ActiveIndex >( &imgFormat );

    char *format {};
    Call< RPRM_Command_Options_GraphicFormat_Name >( imgFormat, &format );

    const auto path = GetTestDataPath();

    auto CopyVisualInfoToClipboard = [ this ]( const HANDLE hRes )
    {
        auto res = reinterpret_cast< const TResultContainer* >( hRes );
        auto info = static_cast< const TDocVisualExtendedInfo* >( res->buffer );
        auto fieldNum = info->nFields;
        while( fieldNum-- )
        {
            // The clipboard is being overwritten by the last iteration
            const auto rtc =
                CheckResultFromList( hRes, ofrTransport_Clipboard, 0 );
            if( rtc < 0 )
            {
                break;
            }
        }
    };

    //**************************************************************************
    // RPRM_ResultType_RawImage
    //**************************************************************************

    // Get images for all selected lightning scheme checkboxes
    if( ScanImagesCheckBox->Checked )
    {
        constexpr auto RawImage = RPRM_ResultType_RawImage;
        GetResult< RawImage >(
            mode,
            [ this, &format, &path ]( auto idx ) -> UnicodeString
            {
                // Get the lightning scheme for this id and insert
                // it into the file name
                auto hRes = CheckResult( RawImage,
                                         idx,
                                         ofrDefault,
                                         0 );

                const auto ret = reinterpret_cast< intptr_t >( hRes );
                if( ret < 0 )
                {
                    UnicodeString msg;
                    msg.printf(
                        L"CheckResult( RPRM_ResultType_RawImage, %d, "
                        L"ofrDefault, 0 ) "
                        L"failed with eRPRM_ResultStatus == %d", idx, ret );
                    throw Exception { msg };
                }

                auto res = reinterpret_cast< const TResultContainer* >( hRes );
                if( ! res )
                {
                    throw Exception
                    {
                        "RPRM_ResultType_Graphics: null TResultContainer"
                    };
                }

                UnicodeString slight;
                slight.printf( L"0x%08X", res->light );

                auto ext = XMLCheckBox->Checked ? UnicodeString( ".xml" ) :
                                                  ExtractFileExt( format );

                return path + slight + ext;
            }
        );
    }

    //**************************************************************************
    // RPRM_ResultType_MRZ_OCR_Extended
    //**************************************************************************
    if( MRZCheckBox->Checked )
    {
        GetResult< RPRM_ResultType_MRZ_OCR_Extended >(
            mode,
            [ &path ]( auto ) -> UnicodeString
            {
                return path + "mrz_parsed.xml";
            },
            CopyVisualInfoToClipboard
        );
    }

    //**************************************************************************
    // RPRM_ResultType_MRZ_TestQuality
    //**************************************************************************
    if( MRZTestQualityCheckBox->Checked )
    {
        GetResult< RPRM_ResultType_MRZ_TestQuality >(
            mode,
            [ &path ]( auto ) -> UnicodeString
            {
                return path + "mrz_test_quality.xml";
            }
        );
    }

    //**************************************************************************
    // RPRM_ResultType_BarCodes
    // RPRM_ResultType_BarCodes_TextData
    // RPRM_ResultType_BarCodes_ImageData
    //**************************************************************************
    if( BarCodesCheckBox->Checked )
    {
        GetResult< RPRM_ResultType_BarCodes >(
            mode,
            [ &path ]( auto ) -> UnicodeString
            {
                return path + "barcodes_binary.xml";
            }
        );

        GetResult< RPRM_ResultType_BarCodes_TextData >(
            mode,
            [ &path ]( auto ) -> UnicodeString
            {
                return path + "barcodes_text.xml";
            },
            CopyVisualInfoToClipboard
        );

        GetResult< RPRM_ResultType_BarCodes_ImageData >(
            mode,
            [ &path ]( auto ) -> UnicodeString
            {
                return path + "barcodes_graphics.xml";
            }
        );
    }

    //**************************************************************************
    // RPRM_ResultType_DocumentTypesCandidates
    //**************************************************************************
    if( DocTypeCheckBox->Checked )
    {
        GetResult< RPRM_ResultType_DocumentTypesCandidates >(
            mode,
            [ &path ]( auto ) -> UnicodeString
            {
                return path + "doc_type_candidates.xml";
            }
        );
    }

    //**************************************************************************
    // RPRM_ResultType_Visual_OCR_Extended
    // RPRM_ResultType_Graphics
    //**************************************************************************
    if( VisualOCRCheckBox->Checked )
    {
        GetResult< RPRM_ResultType_Visual_OCR_Extended >(
            mode,
            [ &path ]( auto ) -> UnicodeString
            {
                return path + "visual_OCR_txt.xml";
            },
            CopyVisualInfoToClipboard
        );

        GetResult< RPRM_ResultType_Graphics >(
            mode,
            [ &path ]( auto ) -> UnicodeString
            {
                return path + "visual_OCR_txt.xml";
            },
            [ this, &path, &format ]( auto hRes )
            {
                auto info =
                    reinterpret_cast< const TResultContainer* >( hRes );

                auto data =
                    static_cast< const TDocGraphicsInfo* >( info->buffer );

                auto fieldNum = data->nFields;
                while( fieldNum-- )
                {
                    UnicodeString filename =
                        path +
                       "visual_OCR_txt_graph" +
                       IntToStr( static_cast< int >( fieldNum ) ) +
                       ExtractFileExt( format );

                    const auto rtc = CheckResultFromList( hRes,
                                                          ofrTransport_File,
                                                          filename.c_str() );
                    if( rtc < 0 )
                    {
                        break;
                    }
                }
            }
        );
    }

    //**************************************************************************
    // RPRM_ResultType_Authenticity
    //**************************************************************************
    if( AuthenticityCheckBox->Checked )
    {
        GetResult< RPRM_ResultType_Authenticity >(
            mode,
            [ &path ]( auto ) -> UnicodeString
            {
                return path + "authenticity.xml";
            }
        );
    }
}

//------------------------------------------------------------------------------

void __fastcall TForm1::Connect()
{
    auto res = Call< RPRM_Command_Device_Connect >( -1 );
    m_deviceConnected =
        ( res == RPRM_Error_NoError ) || ( res == RPRM_Error_AlreadyDone );

    if( m_deviceConnected )
    {
        // Set up image containers
        CleanupImageContainer( m_imagesTabs );
        m_availableLight.clear();

        ImagesTabControl->Tabs->Clear();
        LightCheckListBox->Items->Clear();

        // Get available device features
        long idx {};
        Get< RPRM_Command_Device_ActiveIndex >( &idx );
        LogMessage( L"Reader Index %d", idx );

        TRegulaDeviceProperties* p_activeDevice {};
        res = Call< RPRM_Command_Device_Features >( idx, &p_activeDevice);
        const bool gotFeatures
        {
            ( res == RPRM_Error_NoError ) || ( res == RPRM_Error_AlreadyDone )
        };

        if( gotFeatures && p_activeDevice )
        {
            m_activeDevice = *p_activeDevice;
        }
        else
        {
            UnicodeString msg;
            msg.printf( L"RPRM_Command_Device_Features returned: 0x%08X", res );
            LogMessage( msg );
            throw Exception { msg };
        }

        RefreshSDKCapabilities();

        Get< RPRM_Command_Device_Get_WorkingVideoMode >( &m_currentVideoMode );

        // Get available light schemes
        long lightCnt {};
        Get< RPRM_Command_Device_Light_ScanList_Count >( &lightCnt );

        for( decltype( lightCnt ) i {}; i < lightCnt; ++i )
        {
            long light {};
            Call< RPRM_Command_Device_Light_ScanList_Item >( i, &light );
            const auto& abbreviation = GetLSName( light );
            LightCheckListBox->Items->Add( abbreviation );
            m_availableLight.push_back( light );
        }

        constexpr long Recommended_UV_Value { 6 };
        SetUVExposure( Recommended_UV_Value );
    }
    else
    {
        LogMessage( L"Device_Connect return code = 0x%08X", res );
    }

    UpdateControls();
}

//------------------------------------------------------------------------------

void __fastcall TForm1::Disconnect()
{
    const auto res = Call< RPRM_Command_Device_Disconnect >();
    const bool disconnected
    {
        res == RPRM_Error_NoError ||
        res == RPRM_Error_AlreadyDone
    };

    if( disconnected )
    {
        CleanupImageContainer( m_imagesTabs );
        ImagesTabControl->Tabs->Clear();
        m_availableLight.clear();

        if( m_deviceConnected )
        {
            m_deviceConnected = false;
            LogMessage( L"Device disconnected" );
        }

        PaintDocPresenceBox( clGray );
    }
    else
    {
        LogMessage( L"Device_Disconnect return code = 0x%08X", res );
    }

    UpdateControls();
}

//------------------------------------------------------------------------------

void __fastcall TForm1::SetWorkingVideoMode( const eRPRM_VideoModes mode )
{
    const auto ec = Call< RPRM_Command_Device_Set_WorkingVideoMode >( mode );
    if( ( ec == RPRM_Error_NoError ) ||
        ( ec == RPRM_Error_AlreadyDone ) )
    {
        m_currentVideoMode = mode;
    }
    else
    {
        m_currentVideoMode = RPRM_VM_UNDEFINED;
        LogMessage( L"RPRM_Command_Device_Set_WorkingVideoMode returned 0x%08X",
                    ec );
    }
}

//------------------------------------------------------------------------------

UnicodeString __fastcall TForm1::GetTestDataPath() const
{
    DWORD deviceIdx {};
    Get< RPRM_Command_Device_ActiveIndex >( &deviceIdx );

    TRegulaDeviceProperties *device {};
    Call< RPRM_Command_Device_Features >( deviceIdx, &device );

    const UnicodeString exePath = ExtractFilePath( Application->ExeName );
    return exePath +
           "TestData\\" +
           GetDeviceNameByID(device->DeviceID) +
           "\\";
}

//------------------------------------------------------------------------------

uint32_t __fastcall TForm1::GetProcessingMode() const
{
    uint32_t res = RPRM_GetImage_Modes_Empty;

    // Get images for all selected lightning scheme checkboxes
    if( ScanImagesCheckBox->Checked )
    {
        res |= RPRM_GetImage_Modes_GetImages;
    }

    // Crop images along document borders
    if( LocateCheckBox->Checked )
    {
        res |= RPRM_GetImage_Modes_LocateDocument;
    }

    // Read MRZ
    if( MRZCheckBox->Checked )
    {
        res |= RPRM_GetImage_Modes_OCR_MRZ;
    }

    // Return all images being taken automatically by the library
    // e.g. when reading bar codes, MRZ etc.
    if( AllImagesCheckBox->Checked )
    {
        res |= RPRM_GetImage_Modes_ReceiveAllScannedImages;
    }

    // Check MRZ
    if( MRZTestQualityCheckBox->Checked )
    {
        res |= RPRM_GetImage_Modes_OCR_TestMRZQuality;
    }

    // Read barcodes
    if( BarCodesCheckBox->Checked )
    {
        res |= RPRM_GetImage_Modes_OCR_BarCodes;
    }

    // Determine document type
    if( DocTypeCheckBox->Checked )
    {
        res |= RPRM_GetImage_Modes_DocumentType;
    }

    // OCR document filling
    if( VisualOCRCheckBox->Checked )
    {
        res |= RPRM_GetImage_Modes_OCR_Visual;
    }

    // Obtain document authenticity check results
    if( AuthenticityCheckBox->Checked )
    {
        res |= RPRM_GetImage_Modes_Authenticity;
    }

    return res;
}

//------------------------------------------------------------------------------

void __fastcall TForm1::RefreshSDKCapabilities()
{
    Get< RPRM_Command_Options_GetSDKCapabilities >( &m_SDKCapabilities );

    if( m_activeDevice.DeviceCtrl != RPRM_DeviceControlType_Virtual )
    {
        const bool dist =
            m_SDKCapabilities &
            RPRM_Capabilities_ImageDistortionCompensation;

        const bool refine =
            m_SDKCapabilities & RPRM_Capabilities_LocateDocument;

        LogMessage(L"Calibration status: Distortion Compensation - %s",
                   dist ? L"Ok" : L"Failed");

        LogMessage(L"Calibration status: Color/Brightness Compensation - %s",
                   refine ? L"Ok" : L"Failed");

    }
}

//------------------------------------------------------------------------------

void __stdcall TForm1::MyResultReceivingFunc( TResultContainer *result,
                                              uint32_t *PostAction,
                                              uint32_t *PostActionParameter )
{
    if( !result )
    {
        return;
    }

    switch( result->result_type )
    {

    case RPRM_ResultType_RawImage :
    case RPRM_ResultType_RawUncroppedImage:
    {
        Form1->ReceiveRawImage( result );
        break;
    }

    case RPRM_ResultType_FileImage:
    {
        Form1->ReceiveFileImage( result );
        break;
    }

    case RPRM_ResultType_MRZ_OCR_Extended :
    case RPRM_ResultType_Visual_OCR_Extended :
    case RPRM_ResultType_BarCodes_TextData :
    {
        Form1->ReceiveVisualExtOCR( result );
        break;
    }

    case RPRM_ResultType_MRZ_TestQuality :
    {
        Form1->ReceiveMRZTestQuality( result );
        break;
    }

    case RPRM_ResultType_Graphics :
    case RPRM_ResultType_BarCodes_ImageData:
    {
        Form1->Receive_OCR_Graphics( result );
        break;
    }

    case RPRM_ResultType_BarCodes:
    {
        Form1->ReceiveBarcode( result );
        break;
    }

    case RPRM_ResultType_DocumentTypesCandidates:
    {
        Form1->ReceiveDocTypes( result, PostAction, PostActionParameter );
        break;
    }

    case RPRM_ResultType_ChosenDocumentTypeCandidate:
    {
        Form1->ReceiveDocTypeCandidate( result );
        break;
    }

    case RPRM_ResultType_DocumentsInfoList:
    {
        // Not used
        break;
    }

    case RPRM_ResultType_OCRLexicalAnalyze:
    {
        Form1->ReceiveOCRLexAnalisys( result );
        break;
    }

    case RPRM_ResultType_Authenticity:
    {
        Form1->ReceiveAuthenticity( result );
        break;
    }
    default:
        break;
    }
}

//------------------------------------------------------------------------------

void __stdcall TForm1::MyNotifyFunc( intptr_t rawCode, intptr_t value )
{
    const auto code = static_cast< eRPRM_NotificationCodes >( rawCode );
    switch( code )
    {
    case RPRM_Notification_Error:
    {
        if( value > 0 )
        {
            const auto& str =
                ErrorToStr( static_cast< eRPRM_ErrorCodes >( value ) );
            Form1->LogMessage( L"MyNotifyFunc() error: " + str );
        }
        break;
    }

    case RPRM_Notification_DeviceDisconnected:
    {
        Form1->Disconnect();
        break;
    }

    case RPRM_Notification_DocumentReady:
    {
        Form1->NotifyDocumentReady( value );
        break;
    }

    case RPRM_Notification_Scanning:
    {
        Form1->NotifyScanning( value );
        break;
    }

    case RPRM_Notification_Calibration:
    {
        // Not implemented
        break;
    }

    case RPRM_Notification_CalibrationProgress:
    {
        // Not implemented
        break;
    }

    case RPRM_Notification_CalibrationStep:
    {
        // Not implemented
        break;
    }

    case RPRM_Notification_EnumeratingDevices:
    {
        Form1->NotifyDevEnumeration( value );
        break;
    }

    case RPRM_Notification_ConnectingDevice:
    {
        Form1->NotifyDevConnected( value );
        break;
    }

    case RPRM_Notification_DocumentCanBeRemoved:
    {
        Form1->NotifyDocCanBeRemoved();
        break;
    }

    case RPRM_Notification_LidOpen:
    {
        Form1->NotifyLidOpen( value );
        break;
    }

    case RPRM_Notification_Processing:
    {
        Form1->NotifyProcessingDone( value );
        break;
    }

    case RPRM_Notification_DownloadingCalibrationInfo:
    {
        Form1->NotifyCalibInfoDownload( value );
        break;
    }

    case RPRM_Notification_LicenseExpired:
    {
        Form1->NotifyLicenseExpired( value );
        break;
    }

    case RPRM_Notification_OperationProgress:
    {
        Form1->NotifyProgress( value );
        break;
    }

    case RPRM_Notification_LatestAvailableSDK:
    {
        Form1->NotifySDKAvailable( value );
        break;
    }

    case RPRM_Notification_LatestAvailableDatabase:
    {
        Form1->NotifyDBAvailable( value );
        break;
    }

    case RPRM_Notification_VideoFrame:
    {
        Form1->NotifyVideoFrame(
            reinterpret_cast< TVideodetectionNotification* >( value ) );
        break;
    }

    case RPRM_Notification_CompatibilityMode:
    {
        Form1->NotifyCompatibilityMode(
            *reinterpret_cast< eDeviceLimitations* >( value ) );
        break;
    }

    default:
        Form1->LogMessage( L"MyNotifyFunc(): unexpected notification code %d",
                           code );
        break;
    }
    Form1->UpdateControls();
}

//------------------------------------------------------------------------------

void __fastcall  TForm1::ReceiveVisualExtOCR( const TResultContainer *result )
{
    auto res = static_cast< const TDocVisualExtendedInfo* >( result->buffer );
    if( !res )
    {
        return;
    }

    UnicodeString title;
    const auto type = result->result_type;
    if( type == RPRM_ResultType_MRZ_OCR_Extended )
    {
        title = "Receiving MRZ OCR results...";
    }
    else if( type == RPRM_ResultType_Visual_OCR_Extended )
    {
        title = "Receiving Visual OCR TEXT results...";
    }
    else if( type == RPRM_ResultType_BarCodes_TextData )
    {
        title = "Receiving Barcodes TEXT results...";
    }

    LogMessage( title );

    for( uint32_t i {}; i < res->nFields; ++i )
    {
        const TDocVisualExtendedField* field = &res->pArrayFields[ i ];

        UnicodeString str;
        str += field->FieldName;
        str += ":  ";
        str += field->Buf_Text;

        const auto& result = SplitString( str, "^" );
        for( const auto& sub : result )
        {
            if( ! sub.IsEmpty() )
            {
                LogMessage( sub );
            }
        }
    }

    Memo1->Lines->Add( "" );
}

//------------------------------------------------------------------------------

void __fastcall TForm1::ReceiveRawImage( const TResultContainer* result )
{
    auto im_res = static_cast< const TRawImageContainer* >( result->buffer );
    if( ! im_res )
    {
        return;
    }

    m_imagesTabs.reserve( m_imagesTabs.size() + 1 );

    const auto im = GetImage( im_res );
    if( ! im )
    {
        return;
    }

    auto label = GetLSName( result->light );
    if( RPRM_ResultType_RawUncroppedImage == result->result_type )
    {
        label += "(uc)";
    }

    m_imagesTabs.push_back( im );
    ImagesTabControl->Tabs->Add( label );
    PaintBox->Invalidate();
}

//------------------------------------------------------------------------------

void __fastcall TForm1::ReceiveFileImage( const TResultContainer *result )
{
    DWORD imgFormat {};
    Get< RPRM_Command_Options_GraphicFormat_ActiveIndex >( &imgFormat );

    char* format {};
    Call< RPRM_Command_Options_GraphicFormat_Name >( imgFormat, &format );

    const UnicodeString& ext = ExtractFileExt( format );
    LogMessage( L"Receiving file image for 0x%08X (%d byte(s) - %s)",
                result->light,
                result->buf_length,
                ext.UpperCase().c_str() + 1 );
}

//------------------------------------------------------------------------------

void __fastcall TForm1::Receive_OCR_Graphics( const TResultContainer *result )
{
    auto res = static_cast< const TDocGraphicsInfo* >( result->buffer );
    if( ! res )
    {
        return;
    }

    UnicodeString title;
    if( result->result_type == RPRM_ResultType_Graphics )
    {
        LogMessage( L"Receiving Visual OCR GRAPHIC results..." );
    }
    else if( result->result_type == RPRM_ResultType_BarCodes_TextData )
    {
        LogMessage( L"Receiving Barcodes GRAPHIC results..." );
    }

    m_imagesTabs.reserve( m_imagesTabs.size() + res->nFields );

    for( size_t i {}; i < res->nFields; i++ )
    {
        TRawImageContainer* im_res = &res->pArrayFields[ i ].image;
        if( ! im_res )
        {
            return;
        }

        const auto im = GetImage( im_res );
        if( ! im )
        {
            return;
        }

        m_imagesTabs.push_back( im );

        if( result->result_type == RPRM_ResultType_Graphics )
        {
            ImagesTabControl->Tabs->Add(
                "V Field #" +
                UIntToStr( i ) );
        }
        else if( result->result_type == RPRM_ResultType_BarCodes_ImageData )
        {
            ImagesTabControl->Tabs->Add(
                "BC Field #" +
                UIntToStr( i ) );
        }
    }

    Memo1->Lines->Add( "" );
    PaintBox->Invalidate();
}

//------------------------------------------------------------------------------

void __fastcall TForm1::ReceiveMRZTestQuality( const TResultContainer *result )
{
    auto res = static_cast< const TDocMRZTestQuality* >( result->buffer );
    if( !res )
    {
        return;
    }

    LogMessage( "MRZ Test Quality results received." );
    Memo1->Lines->Add( "" );
}

//------------------------------------------------------------------------------

void __fastcall TForm1::ReceiveBarcode( const TResultContainer *result )
{
    auto res = static_cast< const TDocBarCodeInfo* >( result->buffer );
    if( !res )
    {
        return;
    }

    LogMessage( "Receiving Barcode binary results..." );
    Memo1->Lines->Add( "" );
}

//------------------------------------------------------------------------------

void __fastcall TForm1::ReceiveDocTypes( const TResultContainer *result,
                                         uint32_t *PostAction,
                                         uint32_t *PostActionParameter )
{
    auto res = static_cast< const TCandidatesListContainer* >( result->buffer );
    if( !res )
    {
        return;
    }

    LogMessage( "Receiving Document Type Candidates..." );

    *PostAction = RPRM_PostCalbackAction_Continue;

    LogMessage( L"Choosing 1st candidate: " +
                UnicodeString { res->Candidates[ 0 ].DocumentName } );

    Memo1->Lines->Add( "" );
}

//------------------------------------------------------------------------------

void
__fastcall TForm1::ReceiveDocTypeCandidate( const TResultContainer *result )
{
    auto res = static_cast< const TOneCandidate* >( result->buffer );
    if( !res )
    {
        return;
    }

    LogMessage( "Receiving Current Document Type Candidate info..." );
    Memo1->Lines->Add( "" );
}

//------------------------------------------------------------------------------

void __fastcall TForm1::ReceiveOCRLexAnalisys( const TResultContainer *result )
{
    auto res = static_cast< const TListVerifiedFields* >( result->buffer );
    if( !res )
    {
        return;
    }

    LogMessage( "Receiving OCR Lexical Analisys results..." );
    Memo1->Lines->Add( "" );
}

//------------------------------------------------------------------------------

void __fastcall TForm1::ReceiveAuthenticity( const TResultContainer *result )
{
    auto res = static_cast< const TAuthenticityCheckList* >( result->buffer );
    if( !res )
    {
        return;
    }

    LogMessage("Receiving Authenticity Check results...");
    Memo1->Lines->Add( "" );
}

//------------------------------------------------------------------------------

void __fastcall TForm1::NotifyDocumentReady( const bool isPlaced )
{
    if( isPlaced )
    {
        PaintDocPresenceBox( clRed );
        LogMessage( L"Document placed" );
    }
    else
    {
        PaintDocPresenceBox( clLime );
        LogMessage( L"Document removed" );
    }
}

//------------------------------------------------------------------------------

void __fastcall TForm1::NotifyScanning( const bool isScanningCompleted )
{
    if( isScanningCompleted )
    {
        LogMessage( L"Scanning completed" );
    }
    else
    {
        LogMessage( L"Scanning started" );
        ::SetForegroundWindow( Handle );
    }
}

//------------------------------------------------------------------------------

void __fastcall TForm1::NotifyDevEnumeration( const bool isEnumCompleted )
{
    if( isEnumCompleted )
    {
        long total_devices {};
        Get< RPRM_Command_Device_Count >( &total_devices );
        LogMessage( L"Document readers found: %d", total_devices );
    }
    else
    {
        LogMessage( L"Detecting available document readers" );
    }
}

//------------------------------------------------------------------------------

void __fastcall TForm1::NotifyDevConnected( const bool isConnected )
{
    ConnectDeviceButton->Enabled = isConnected;
    LogMessage( isConnected ? L"Connected" : L"Connecting. Please wait..." );
}

//------------------------------------------------------------------------------

void __fastcall TForm1::NotifyDocCanBeRemoved()
{
    Form1->LogMessage( L"The document can be removed" );
    TIndicationLED led {};
    led.wColorLed = ledGreen;
    led.wFreq = MAKEWORD( 0, 0 );
    Call< RPRM_Command_Device_LED >( &led );
}

//------------------------------------------------------------------------------

void __fastcall TForm1::NotifyLidOpen( const bool isOpen )
{
    if( isOpen )
    {
        LogMessage( L"Lid open" );
    }
    else
    {
        LogMessage( L"Lid closed" );
    }
}

//------------------------------------------------------------------------------

void __fastcall TForm1::NotifyProcessingDone( const bool isDone )
{
    if( isDone )
    {
        LogMessage( L"Processing done" );
    }
    else
    {
        LogMessage( L"Processing started" );
    }
}

//------------------------------------------------------------------------------

void __fastcall TForm1::NotifyCalibInfoDownload( const int percent )
{
    LogMessage( L"Downloading calibration info %d%%", percent );
    ProgressBar->Position = percent;
}

//------------------------------------------------------------------------------

void __fastcall TForm1::NotifyLicenseExpired( const int daysSince1900 )
{
    LogMessage( L"Number of days since January, 1, 1900 "
                L"until license was active %d",
                daysSince1900 );
}

//------------------------------------------------------------------------------

void __fastcall TForm1::NotifyProgress( const int percent )
{
    LogMessage( L"Progress: %d%%", percent );
    ProgressBar->Position = percent;
}

//------------------------------------------------------------------------------

void __fastcall TForm1::NotifySDKAvailable( const uint32_t version )
{
    LogMessage( L"The latest available SDK version: %d.%d",
                HIWORD( version ),
                LOWORD( version ) );
}

//------------------------------------------------------------------------------

void __fastcall TForm1::NotifyDBAvailable( const uint32_t version )
{
    LogMessage( L"The latest available DB version: %d.%d",
                HIWORD( version ),
                LOWORD( version ) );
}

//------------------------------------------------------------------------------

void __fastcall
TForm1::NotifyVideoFrame( const TVideodetectionNotification* frame )
{
    const auto& hdr = frame->image->bmi->bmiHeader;
    LogMessage( L"New %d bit %dx%d video frame; Sensor state 0x%08X; ",
                hdr.biBitCount,
                hdr.biWidth,
                hdr.biHeight,
                frame->sensorState );
}

//------------------------------------------------------------------------------

void __fastcall TForm1::NotifyCompatibilityMode( const eDeviceLimitations mode )
{
    if( mode == DL_NONE )
    {
        LogMessage( L"The device has no limitations" );
    }
    else
    {
        if( mode & DL_USB2 )
        {
             LogMessage( L"The device is limited by USB 2.0 port" );
        }

        if( mode & DL_32bit )
        {
             LogMessage( L"The device uses a 32-bit platform" );
        }
    }
}

//------------------------------------------------------------------------------

TRawImageContainer*
__fastcall TForm1::GetImage( const  TRawImageContainer* im_res )
{
    TRawImageContainer* im {};
    const auto& hdr = im_res->bmi->bmiHeader;
    const auto res = AllocRawImageContainer( &im,
                                             hdr.biWidth,
                                             hdr.biHeight,
                                             hdr.biBitCount,
                                             hdr.biXPelsPerMeter );

    if( ( res != RPRM_Error_NoError ) || !im )
    {
        LogMessage( L"AllocRawImageContainer returned 0x%08X; ",
                    L"The container is %s available",
                    ! im ? "not" : "",
                    res );
        return nullptr;
    }

    memcpy( im->bits, im_res->bits, hdr.biSizeImage );
    return im;
}

//------------------------------------------------------------------------------

void __fastcall TForm1::SetUVExposure( long value )
{
    const auto ec = Call< RPRM_Command_Device_Set_ParamLowLight >( value );
    if( ( ec == RPRM_Error_NoError ) || ( ec == RPRM_Error_AlreadyDone ) )
    {
        LogMessage( L"UV exposure is set to %d", value );
    }
    else
    {
        LogMessage( L"RPRM_Command_Device_Set_ParamLowLight returned: "
                    L"0x%08X",
                    ec );
    }

    Get< RPRM_Command_Device_Get_ParamLowLight >( &value );
    UVExpSpinEdit->Value = value;
}

//------------------------------------------------------------------------------