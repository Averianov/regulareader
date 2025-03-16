package usedll

import "fmt"

type RPRM_ErrorCode int32

// typedef enum eRPRM_ErrorCodes
const (
	RPRM_Error_NoError                      = RPRM_ErrorCode(int32(0x00000000))
	RPRM_Error_AlreadyDone                  = RPRM_ErrorCode(int32(0x00000001))
	RPRM_Error_NoGraphManager               = RPRM_ErrorCode(int32(0x00000002))
	RPRM_Error_CantRegisterMessages         = RPRM_ErrorCode(int32(0x00000003))
	RPRM_Error_NoServiceManager             = RPRM_ErrorCode(int32(0x00000004))
	RPRM_Error_CantConnectServiceManager    = RPRM_ErrorCode(int32(0x00000006))
	RPRM_Error_CantCreateDeviceLibraryEvent = RPRM_ErrorCode(int32(0x00000009))
	RPRM_Error_InvalidParameter             = RPRM_ErrorCode(int32(0x0000000C))
	RPRM_Error_NotInitialized               = RPRM_ErrorCode(int32(0x0000000D))
	RPRM_Error_Busy                         = RPRM_ErrorCode(int32(0x0000000E))
	RPRM_Error_NotEnoughMemory              = RPRM_ErrorCode(int32(0x00000011))
	RPRM_Error_BadVideo                     = RPRM_ErrorCode(int32(0x00000014))
	RPRM_Error_ScanAborted                  = RPRM_ErrorCode(int32(0x00000015))
	RPRM_Error_CantRecognizeDocumentType    = RPRM_ErrorCode(int32(0x00000016))
	RPRM_Error_CantSetupSensor              = RPRM_ErrorCode(int32(0x00000018))
	RPRM_Error_NotTrueColorDesktop          = RPRM_ErrorCode(int32(0x00000019))
	RPRM_Error_NotAvailable                 = RPRM_ErrorCode(int32(0x0000001A))
	RPRM_Error_DeviceError                  = RPRM_ErrorCode(int32(0x0000001B))
	RPRM_Error_DeviceDisconnected           = RPRM_ErrorCode(int32(0x00000020))
	RPRM_Error_WrongThreadContext           = RPRM_ErrorCode(int32(0x00000030))
	RPRM_Error_COMServers                   = RPRM_ErrorCode(int32(0x00000031))
	RPRM_Error_NoDocumentReadersFound       = RPRM_ErrorCode(int32(0x00000032))
	RPRM_Error_NoTranslationMngr            = RPRM_ErrorCode(int32(0x00000033))
	RPRM_Error_NoActiveDevice               = RPRM_ErrorCode(int32(0x00000034))
	RPRM_Error_ConnectingDevice             = RPRM_ErrorCode(int32(0x00000035))
	RPRM_Error_Failed                       = RPRM_ErrorCode(int32(0x00000036))
	RPRM_Error_LightIsNotAllowed            = RPRM_ErrorCode(int32(0x00000037))
	RPRM_Error_ImageIOError                 = RPRM_ErrorCode(int32(0x00000038))
	RPRM_Error_CantStoreCalibrationData     = RPRM_ErrorCode(int32(0x00000039))
	RPRM_Error_DeviceNotCalibrated          = RPRM_ErrorCode(int32(0x0000003A))
	RPRM_Error_CantCompensateDistortion     = RPRM_ErrorCode(int32(0x0000003B))
	RPRM_Error_OperationCancelled           = RPRM_ErrorCode(int32(0x0000003C))
	RPRM_Error_CantLocateDocumentBounds     = RPRM_ErrorCode(int32(0x0000003D))
	RPRM_Error_CantRefineImages             = RPRM_ErrorCode(int32(0x0000003E))
	RPRM_Error_CantCropRotateImages         = RPRM_ErrorCode(int32(0x0000003F))
	RPRM_Error_IncompleteImagesList         = RPRM_ErrorCode(int32(0x00000040))
	RPRM_Error_CantReadMRZ                  = RPRM_ErrorCode(int32(0x00000041))
	RPRM_Error_CantFindBarcodes             = RPRM_ErrorCode(int32(0x00000042))
	RPRM_Error_DeviceIDNotSupported         = RPRM_ErrorCode(int32(0x00000043))
	RPRM_Error_DeviceIDNotStored            = RPRM_ErrorCode(int32(0x00000044))
	RPRM_Error_DeviceDriver                 = RPRM_ErrorCode(int32(0x00000045))
	RPRM_Error_Calibration_OpenLid          = RPRM_ErrorCode(int32(0x00000046))
	RPRM_Error_Calibration_Brightness       = RPRM_ErrorCode(int32(0x00000047)) // - bad brightness
	RPRM_Error_Calibration_WhiteBalance     = RPRM_ErrorCode(int32(0x00000048)) // - bad white balance
	RPRM_Error_Calibration_TargetPosition   = RPRM_ErrorCode(int32(0x00000049)) // - bad document position
	RPRM_Error_Calibration_LightBlank       = RPRM_ErrorCode(int32(0x0000004A)) // - a lot of blinks
	RPRM_Error_Calibration_LightDistortion  = RPRM_ErrorCode(int32(0x0000004B)) // - irregular brightness
	RPRM_Error_Calibration_LightLevel       = RPRM_ErrorCode(int32(0x0000004C)) // - very high brightness
	RPRM_Error_Calibration_LightLevelHigh   = RPRM_ErrorCode(int32(0x0000004D)) // - common brightness more than threshold
	RPRM_Error_Calibration_LightLevelLow    = RPRM_ErrorCode(int32(0x0000004E)) // - common brightness less than threshold
	RPRM_Error_8305CameraAbsent             = RPRM_ErrorCode(int32(0x00000050))
	RPRM_Error_NotImplemented               = RPRM_ErrorCode(int32(0x00000051)) // - not implemented
	RPRM_Error_RemoveDocument               = RPRM_ErrorCode(int32(0x00000052)) // it is necessary to remove document during initialization
	RPRM_Error_BadDataFile                  = RPRM_ErrorCode(int32(0x00000053)) // data file is absent or corrupted
	RPRM_Error_BadInputImage                = RPRM_ErrorCode(int32(0x00000054)) // input image has glares or out of focus
)

func (e RPRM_ErrorCode) String() string {
	switch e {
	case RPRM_Error_NoError:
		return "NoError"
	case RPRM_Error_AlreadyDone:
		return "AlreadyDone"
	case RPRM_Error_NoGraphManager:
		return "NoGraphManager"
	case RPRM_Error_CantRegisterMessages:
		return "CantRegisterMessages"
	case RPRM_Error_NoServiceManager:
		return "NoServiceManager"
	case RPRM_Error_CantConnectServiceManager:
		return "CantConnectServiceManager"
	case RPRM_Error_CantCreateDeviceLibraryEvent:
		return "CantCreateDeviceLibraryEvent"
	case RPRM_Error_InvalidParameter:
		return "InvalidParameter"
	case RPRM_Error_NotInitialized:
		return "NotInitialized"
	case RPRM_Error_Busy:
		return "Busy"
	case RPRM_Error_NotEnoughMemory:
		return "NotEnoughMemory"
	case RPRM_Error_BadVideo:
		return "BadVideo"
	case RPRM_Error_ScanAborted:
		return "ScanAborted"
	case RPRM_Error_CantRecognizeDocumentType:
		return "CantRecognizeDocumentType"
	case RPRM_Error_CantSetupSensor:
		return "CantSetupSensor"
	case RPRM_Error_NotTrueColorDesktop:
		return "NotTrueColorDesktop"
	case RPRM_Error_NotAvailable:
		return "NotAvailable"
	case RPRM_Error_DeviceError:
		return "DeviceError"
	case RPRM_Error_DeviceDisconnected:
		return "DeviceDisconnected"
	case RPRM_Error_WrongThreadContext:
		return "WrongThreadContext"
	case RPRM_Error_COMServers:
		return "COMServers"
	case RPRM_Error_NoDocumentReadersFound:
		return "NoDocumentReadersFound"
	case RPRM_Error_NoTranslationMngr:
		return "NoTranslationMngr"
	case RPRM_Error_NoActiveDevice:
		return "NoActiveDevice"
	case RPRM_Error_ConnectingDevice:
		return "ConnectingDevice"
	case RPRM_Error_Failed:
		return "Failed"
	case RPRM_Error_LightIsNotAllowed:
		return "LightIsNotAllowed"
	case RPRM_Error_ImageIOError:
		return "ImageIOError"
	case RPRM_Error_CantStoreCalibrationData:
		return "CantStoreCalibrationData"
	case RPRM_Error_DeviceNotCalibrated:
		return "DeviceNotCalibrated"
	case RPRM_Error_CantCompensateDistortion:
		return "CantCompensateDistortion"
	case RPRM_Error_OperationCancelled:
		return "OperationCancelled"
	case RPRM_Error_CantLocateDocumentBounds:
		return "CantLocateDocumentBounds"
	case RPRM_Error_CantRefineImages:
		return "CantRefineImages"
	case RPRM_Error_CantCropRotateImages:
		return "CantCropRotateImages"
	case RPRM_Error_IncompleteImagesList:
		return "IncompleteImagesList"
	case RPRM_Error_CantReadMRZ:
		return "CantReadMRZ"
	case RPRM_Error_CantFindBarcodes:
		return "CantFindBarcodes"
	case RPRM_Error_DeviceIDNotSupported:
		return "DeviceIDNotSupported"
	case RPRM_Error_DeviceIDNotStored:
		return "DeviceIDNotStored"
	case RPRM_Error_DeviceDriver:
		return "DeviceDriver"
	case RPRM_Error_Calibration_OpenLid:
		return "Calibration_OpenLid"
	case RPRM_Error_Calibration_Brightness:
		return "Calibration_Brightness" // - bad brightness
	case RPRM_Error_Calibration_WhiteBalance:
		return "Calibration_WhiteBalance" // - bad white balance
	case RPRM_Error_Calibration_TargetPosition:
		return "Calibration_TargetPosition" // - bad document position
	case RPRM_Error_Calibration_LightBlank:
		return "Calibration_LightBlank" // - a lot of blinks
	case RPRM_Error_Calibration_LightDistortion:
		return "Calibration_LightDistortion" // - irregular brightness
	case RPRM_Error_Calibration_LightLevel:
		return "Calibration_LightLevel" // - very high brightness
	case RPRM_Error_Calibration_LightLevelHigh:
		return "Calibration_LightLevelHigh" // - common brightness more than threshold
	case RPRM_Error_Calibration_LightLevelLow:
		return "Calibration_LightLevelLow" // - common brightness less than threshold
	case RPRM_Error_8305CameraAbsent:
		return "8305CameraAbsent"
	case RPRM_Error_NotImplemented:
		return "NotImplemented" // - not implemented
	case RPRM_Error_RemoveDocument:
		return "RemoveDocument" // it is necessary to remove document during initialization
	case RPRM_Error_BadDataFile:
		return "BadDataFile" // data file is absent or corrupted
	case RPRM_Error_BadInputImage:
		return "BadInputImage" // input image has glares or out of focus
	}
	return fmt.Sprintf("Unknown error(%d)", e)
}
