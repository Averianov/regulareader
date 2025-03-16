package main

import "C"
import (
	"regulaclient/pkg/form"
	"regulaclient/pkg/usedll"
	"time"
	"unsafe"

	sl "github.com/Averianov/cisystemlog"
)

func init() {
	sl.CreateLogs(4, 5) // ##########################################
	sl.L.RemoveLogFile(3)
}

// "C:\Program Files\Regula\Document Reader SDK\READERDEMO" /unregserver
// "C:\Program Files\Regula\Document Reader SDK\READERDEMO" /regserver
func main() {
	// WORK OLE EXPIRIENCE
	// conn, err := oleapi.InitializeOleConnection()
	// if err != nil {
	// 	sl.L.Alert("InitializeOleConnection: %v", err)
	// }
	// defer conn.Uninitialize()
	// oleapi.DispatchOle(conn)

	var err error
	var param any

	usedll.AISetCallbackFunc()
	usedll.AIInitialize()
	usedll.AILibraryVersion()

	var anyResult any
	param = 0
	anyResult, err = usedll.AIExecuteCommand(int32(usedll.RPRM_Command_Device_RefreshList), unsafe.Pointer(&param))
	if err != nil {
		return
	}
	if anyResult == nil {
		sl.L.Info("RefreshList is nil")
	} else {
		sl.L.Info("RefreshList: %v", anyResult)
	}

	var deviceCount any //usedll.RPRM_ResultType
	deviceCount, err = usedll.AIExecuteCommand(int32(usedll.RPRM_Command_Device_Count), unsafe.Pointer(&param))
	if err != nil {
		return
	}
	if deviceCount == nil {
		sl.L.Alert("deviceCount is nil")
	} else {
		sl.L.Info("deviceCount: %v", deviceCount)
	}

	time.Sleep(time.Second * 5)

	param = -1
	anyResult, err = usedll.AIExecuteCommand(int32(usedll.RPRM_Command_Device_Connect), unsafe.Pointer(&param))
	if err != nil {
		return
	}
	if anyResult == nil {
		sl.L.Info("Device_Connect is nil")
	} else {
		sl.L.Info("Device_Connect: %v", anyResult)
	}

	for idx := range usedll.Devices {
		var param any = idx
		var properties any
		properties, err = usedll.AIExecuteCommand(int32(usedll.RPRM_Command_Device_Features), unsafe.Pointer(&param))
		if err != nil {
			continue
		}
		if properties == nil {
			sl.L.Alert("properties is nil")
			continue
		}
		sl.L.Info("properties: %v", properties)

		//var deviceProperties usedll.TRegulaDeviceProperties
		if deviceProperties, ok := (properties).(usedll.TRegulaDeviceProperties); ok {
			usedll.Devices[idx] = deviceProperties
		} else {
			sl.L.Alert("failed to cast properties to TRegulaDeviceProperties")
			continue
		}

	} /**/

	/*usedll.LoadDLL()
	usedll.SetCallbackFunc(usedll.MyResultReceivingFunc, usedll.MyNotifyFunc)
	usedll.InitializeDevice()
	usedll.GetVersion()

	var deviceCount int32
	usedll.ExecuteCommand(usedll.RPRM_Command_Device_Count, 0, uintptr(unsafe.Pointer(&deviceCount)))
	sl.L.Info("deviceCount: %v", deviceCount)

	deviceCount = -1
	usedll.ExecuteCommand(usedll.RPRM_Command_Device_Connect, uintptr(unsafe.Pointer(&deviceCount)), 0)

	defer usedll.FreeDevice()/**/

	form.InitForm()
}
