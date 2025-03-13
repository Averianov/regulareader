package main

import (
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

// "C:\Program Files\Regula\Document Reader SDK\READERDEMO" /unregserver
// "C:\Program Files\Regula\Document Reader SDK\READERDEMO" /regserver
func main() {

	// // var err error

	// // connection := &ole.Connection{}

	// // err = connection.Initialize()
	// // if err != nil {
	// // 	return
	// // }
	// // defer connection.Uninitialize()

	// // err = connection.Create("298595A7-A986-404B-9642-D0A37F2EE681")
	// // if err != nil {
	// // 	sl.L.Info("%v", err)
	// // 	if err.(*ole.OleError).Code() == ole.CO_E_CLASSSTRING {
	// // 		return
	// // 	}
	// // }
	// // defer connection.Release()

	// // dispatch, err := connection.Dispatch()
	// // if err != nil {
	// // 	sl.L.Info("%v", err)
	// // 	return
	// // }
	// // defer dispatch.Release()

	// // oleapi.InitializeDeviceOle()
	// // time.Sleep(time.Minute)

	usedll.CSetCallbackFunc()
	//usedll.SetCallbackFunc(usedll.MyResultReceivingFunc, usedll.MyNotifyFunc)
	usedll.InitializeDevice()
	usedll.GetVersion()

	var deviceCount int32
	usedll.ExecuteCommand(usedll.RPRM_Command_Device_Count, 0, uintptr(unsafe.Pointer(&deviceCount)))
	sl.L.Info("deviceCount: %v", deviceCount)

	// var deviceCount int32
	// usedll.ExecuteCommand(&usedll.RPRM_Command_Device_RefreshList, 0, uintptr(unsafe.Pointer(&deviceCount)))
	// sl.L.Info("deviceCount: %v", deviceCount)

	// var deviceCount int32 // TRegulaDeviceProperties
	// usedll.ExecuteCommand(&usedll.RPRM_Command_Device_Features, 0, uintptr(unsafe.Pointer(&deviceCount)))
	// sl.L.Info("deviceCount: %v", deviceCount)

	//var deviceCount int32 = -1
	usedll.ExecuteCommand(usedll.RPRM_Command_Device_Connect, uintptr(unsafe.Pointer(&deviceCount)), 0)
	usedll.ExecuteCommand(usedll.RPRM_Command_Device_Connect, 0, 0)

	defer usedll.FreeDevice()

	// form.InitForm()
}
