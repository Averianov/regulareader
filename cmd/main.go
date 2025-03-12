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
	usedll.SetCallbackFunc(usedll.ResultFunc, usedll.NotifyFunc)
	// sl.L.Info("%v", usedll.RPRM_Command_Device_Count)

	var deviceCount int32
	usedll.ExecuteCommand(&usedll.RPRM_Command_Device_Count, 0, uintptr(unsafe.Pointer(&deviceCount)))
	sl.L.Info("deviceCount: %v", deviceCount)

	defer usedll.FreeDevice()

	form.InitForm()
}
