package usedll

import (
	"time"
	"unsafe"

	"github.com/google/uuid"
)

var Devices map[int32]TRegulaDeviceProperties = make(map[int32]TRegulaDeviceProperties)

type TResultContainer struct {
	result_type uint32 // eRPRM_ResultType
	light       uint32 // eRPRM_Lights
	buf_length  uint32
	buffer      unsafe.Pointer
	XML_length  uint32
	XML_buffer  unsafe.Pointer
	list_idx    uint32
	page_idx    uint32
}

type TRegulaDeviceProperties struct {
	DeviceID             uint32    ///< eRPRM_DeviceTypes
	Lights               uint32    ///< eRPRM_Lights combination
	SerialNumber         uint32    ///< if available
	Features             uint32    ///< eRPRM_DeviceAdditionalFeatures
	DeviceCtrl           uint32    ///< eRPRM_DeviceControlTypes
	DirectShowName       string    ///< DirectShow device name
	SystemUID            string    ///< system unique device name
	Name                 string    ///< non-DirectShow device name
	AvailableVideoModes  uint32    ///< eRPRM_VideoModes combination
	LabelSerialNumber    uint64    ///< serial number on label
	LabelSerialNumberStr string    ///< serial number on label (string)
	CameraSerialNumber   uint64    ///< camera HW serial number
	CameraGuid           uuid.UUID ///< camera GUID
	Capabilities         uint32
	Authenticity         uint32
	Database             uint32
	ValidUntil           time.Time
	WillConnect          bool
	Limitations          uint32
}
