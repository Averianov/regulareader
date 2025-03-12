package main

import (
	"regulaclient/pkg/form"
	"regulaclient/pkg/usedll"

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
	//pkg.SetCallbackFunc(pkg.ResultFunc, pkg.NotifyFunc)
	usedll.ExecuteCommand(&usedll.RPRM_Command_Device_Count)
	defer usedll.FreeDevice()

	form.InitForm()
}
