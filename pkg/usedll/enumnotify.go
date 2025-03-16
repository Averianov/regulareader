package usedll

import "fmt"

type RPRM_NotifyCode int32

const (
	RPRM_Notification_Error                      = RPRM_NotifyCode(int32(0x00000000))
	RPRM_Notification_DeviceDisconnected         = RPRM_NotifyCode(int32(0x00000001))
	RPRM_Notification_DocumentReady              = RPRM_NotifyCode(int32(0x00000002))
	RPRM_Notification_Scanning                   = RPRM_NotifyCode(int32(0x00000004))
	RPRM_Notification_Calibration                = RPRM_NotifyCode(int32(0x00000008))
	RPRM_Notification_CalibrationProgress        = RPRM_NotifyCode(int32(0x00000009))
	RPRM_Notification_CalibrationStep            = RPRM_NotifyCode(int32(0x0000000A))
	RPRM_Notification_EnumeratingDevices         = RPRM_NotifyCode(int32(0x0000000C))
	RPRM_Notification_ConnectingDevice           = RPRM_NotifyCode(int32(0x0000000D))
	RPRM_Notification_DocumentCanBeRemoved       = RPRM_NotifyCode(int32(0x0000000E))
	RPRM_Notification_LidOpen                    = RPRM_NotifyCode(int32(0x0000000F))
	RPRM_Notification_Processing                 = RPRM_NotifyCode(int32(0x00000010))
	RPRM_Notification_DownloadingCalibrationInfo = RPRM_NotifyCode(int32(0x00000011))
	RPRM_Notification_LicenseExpired             = RPRM_NotifyCode(int32(0x00000012))
	RPRM_Notification_OperationProgress          = RPRM_NotifyCode(int32(0x00000013))
	RPRM_Notification_LatestAvailableSDK         = RPRM_NotifyCode(int32(0x00000014))
	RPRM_Notification_LatestAvailableDatabase    = RPRM_NotifyCode(int32(0x00000015))
	RPRM_Notification_VideoFrame                 = RPRM_NotifyCode(int32(0x00000016)) //  value = TVideodetectionNotification*
	RPRM_Notification_CompatibilityMode          = RPRM_NotifyCode(int32(0x00000017))
)

func (e RPRM_NotifyCode) String() string {
	switch e {
	case RPRM_Notification_Error:
		return "Error"
	case RPRM_Notification_DeviceDisconnected:
		return "DeviceDisconnected"
	case RPRM_Notification_DocumentReady:
		return "DocumentReady"
	case RPRM_Notification_Scanning:
		return "Scanning"
	case RPRM_Notification_Calibration:
		return "Calibration"
	case RPRM_Notification_CalibrationProgress:
		return "CalibrationProgress"
	case RPRM_Notification_CalibrationStep:
		return "CalibrationStep"
	case RPRM_Notification_EnumeratingDevices:
		return "EnumeratingDevices"
	case RPRM_Notification_ConnectingDevice:
		return "ConnectingDevice"
	case RPRM_Notification_DocumentCanBeRemoved:
		return "DocumentCanBeRemoved"
	case RPRM_Notification_LidOpen:
		return "LidOpen"
	case RPRM_Notification_Processing:
		return "Processing"
	case RPRM_Notification_DownloadingCalibrationInfo:
		return "DownloadingCalibrationInfo"
	case RPRM_Notification_LicenseExpired:
		return "LicenseExpired"
	case RPRM_Notification_OperationProgress:
		return "OperationProgress"
	case RPRM_Notification_LatestAvailableSDK:
		return "LatestAvailableSDK"
	case RPRM_Notification_LatestAvailableDatabase:
		return "LatestAvailableDatabase"
	case RPRM_Notification_VideoFrame:
		return "VideoFrame"
	case RPRM_Notification_CompatibilityMode:
		return "CompatibilityMode"
	default:
		return fmt.Sprintf("Unknown(%d)", e)
	}
}
