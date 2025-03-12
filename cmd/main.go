package main

import (
	"regulaclient/pkg/form"
	"regulaclient/pkg/usedll"
	"unsafe"

	sl "github.com/Averianov/cisystemlog"
)

// type scan struct {
// 	ir    *canvas.Image
// 	wight *canvas.Image
// 	uv    *canvas.Image
// }

func init() {
	sl.CreateLogs(4, 5) // ##########################################
	sl.L.RemoveLogFile(3)
}

func main() {
	usedll.GetVersion()
	usedll.InitializeDevice()
	usedll.SetCallbackFunc(usedll.MyResultReceivingFunc, usedll.MyNotifyFunc)

	// var deviceCount int32
	// usedll.ExecuteCommand(&usedll.RPRM_Command_Device_Count, 0, uintptr(unsafe.Pointer(&deviceCount)))
	// sl.L.Info("deviceCount: %v", deviceCount)

	// var deviceCount int32
	// usedll.ExecuteCommand(&usedll.RPRM_Command_Device_RefreshList, 0, uintptr(unsafe.Pointer(&deviceCount)))
	// sl.L.Info("deviceCount: %v", deviceCount)

	// var deviceCount int32 // TRegulaDeviceProperties
	// usedll.ExecuteCommand(&usedll.RPRM_Command_Device_Features, 0, uintptr(unsafe.Pointer(&deviceCount)))
	// sl.L.Info("deviceCount: %v", deviceCount)

	var deviceCount int32 = -1
	usedll.ExecuteCommand(&usedll.RPRM_Command_Device_Connect, uintptr(unsafe.Pointer(&deviceCount)), 0)

	defer usedll.FreeDevice()

	form.InitForm()
}
