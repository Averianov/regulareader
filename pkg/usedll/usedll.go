package usedll

import (
	"syscall"
	"unsafe"

	sl "github.com/Averianov/cisystemlog"
)

var (
	Passpr40        *syscall.LazyDLL
	libVersion      *syscall.LazyProc
	free            *syscall.LazyProc
	initialize      *syscall.LazyProc
	executeCommand  *syscall.LazyProc
	setCallbackFunc *syscall.LazyProc
)

const (
	CONNECT_DEVICE    string = "RPRM_Command_Device_Connect"
	DISCONNECT_DEVICE string = "RPRM_Command_Device_Disconnect"
	GET_DEVICE_COUNT  string = "RPRM_Command_Device_Count"
	NO_ERROR          string = "RPRM_Error_NoError"
	ALREADY_DONE      string = "RPRM_Error_AlreadyDone"
)

func init() {
	Passpr40 = syscall.NewLazyDLL("./lib/PasspR40.dll")
	libVersion = Passpr40.NewProc("_LibraryVersion")
	free = Passpr40.NewProc("_Free")
	initialize = Passpr40.NewProc("_Initialize")
	executeCommand = Passpr40.NewProc("_ExecuteCommand")
	setCallbackFunc = Passpr40.NewProc("_SetCallbackFunc")
}

// typedef long    (*_InitializeFunc)(void *lpParams, HWND hParent);
func InitializeDevice() (err error) {
	var ret1, ret2 uintptr
	ret1, ret2, err = initialize.Call()
	if err != nil {
		sl.L.Alert("%v", err)
	}
	sl.L.Info("%v, %v", ret1, ret2)
	return
}

// typedef long    (*_ExecuteCommandFunc)( long command, void *params, void *result );
func ExecuteCommand(command *int32) (err error) {
	var ret1, ret2 uintptr
	ret1, ret2, err = executeCommand.Call(
		uintptr(unsafe.Pointer(command)),
	)
	if err != nil && err.Error() != "The operation completed successfully." {
		sl.L.Alert("%v", err)
	}
	sl.L.Info("executeCommand:%v, %v", ret1, ret2)
	return
}

// typedef void    (*_SetCallbackFuncFunc)( ResultReceivingFunc f1, NotifyFunc f2 );
func SetCallbackFunc(resultFunc func(*uint32, *uint32, *uint32),
	notifyFunc func(uintptr, uintptr)) (err error) {

	var ret1, ret2 uintptr
	ret1, ret2, err = setCallbackFunc.Call(
	// uintptr(unsafe.Pointer(resultFunc)),
	// uintptr(unsafe.Pointer(notifyFunc)),
	)
	if err != nil && err.Error() != "The operation completed successfully." {
		sl.L.Alert("%v", err)
	}
	sl.L.Info("libVersion:%v, %v", ret1, ret2)
	return
}

func FreeDevice() (err error) {
	var ret1, ret2 uintptr
	ret1, ret2, err = free.Call()
	if err != nil && err.Error() != "The operation completed successfully." {
		sl.L.Alert("%v", err)
	}
	sl.L.Info("free:%v, %v", ret1, ret2)
	return
}

func GetVersion() (err error) {
	var ret1, ret2 uintptr
	ret1, ret2, err = libVersion.Call()
	if err != nil && err.Error() != "The operation completed successfully." {
		sl.L.Alert("%v", err)
	}
	sl.L.Info("libVersion:%v, %v", ret1, ret2)
	return
}

// typedef void (REGULA_STDCALL *ResultReceivingFunc)
// ( TResultContainer *result, uint32_t *PostAction, uint32_t *PostActionParameter );
func ResultFunc(result *uint32, postAction, postActionParam *uint32) {
	sl.L.Warning("ResultFunc: %v, %v, %v", result, postAction, postActionParam)
}

// typedef void (REGULA_STDCALL *NotifyFunc)(intptr_t code, intptr_t value);
func NotifyFunc(code, value uintptr) {
	sl.L.Info("NotifyFunc: %v, %v", code, value)

	// switch notify {
	// case ALREADY_DONE:
	// 	sl.L.Info("%v", notify)
	// case NO_ERROR:
	// 	sl.L.Info("%v", notify)
	// default:
	// 	sl.L.Warning("%v", notify)
	// }
}
