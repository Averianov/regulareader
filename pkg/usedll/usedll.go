package usedll

/*
//#cgo LDFLAGS: -L. -lPasspR40
//#cgo CFLAGS: -I.
#include <PasspR.h>
*/
import "C"

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

	// windowHandler syscall.Handle
)

const (
	CONNECT_DEVICE    string = "RPRM_Command_Device_Connect"
	DISCONNECT_DEVICE string = "RPRM_Command_Device_Disconnect"
	GET_DEVICE_COUNT  string = "RPRM_Command_Device_Count"
	NO_ERROR          string = "RPRM_Error_NoError"
	ALREADY_DONE      string = "RPRM_Error_AlreadyDone"
)

func init() {

	Passpr40 = syscall.NewLazyDLL("C:\\Projects\\regulareader\\lib\\PasspR40.dll")
	//Passpr40 = syscall.NewLazyDLL("./lib/PasspR40.dll")
	libVersion = Passpr40.NewProc("_LibraryVersion")
	free = Passpr40.NewProc("_Free")
	initialize = Passpr40.NewProc("_Initialize")
	executeCommand = Passpr40.NewProc("_ExecuteCommand")
	setCallbackFunc = Passpr40.NewProc("_SetCallbackFunc")

	// var err error
	// windowHandler, err = FindWindow(form.WINDOW_NAME)
	// if err != nil {
	// 	sl.L.Alert("%v", err)
	// }
}

// typedef long    (*_InitializeFunc)(void *lpParams, HWND hParent);
func InitializeDevice() (err error) {
	var hwnd uintptr
	hwnd, err = GetHWND()
	if err != nil {
		if err.Error() != "The operation completed successfully." {
			sl.L.Alert("GetHWND: %v", err)
		} else {
			sl.L.Debug("GetHWND: %v", err)
		}
	}
	sl.L.Info("GetHWND: %v", hwnd)

	var ret1, ret2 uintptr
	ret1, ret2, err = initialize.Call(
		0, // void *lpParams
		0, //hwnd, // HWND hParent
	)
	if ret1 == 0 || ret1 == 1 || err.Error() == "The operation completed successfully." {
		sl.L.Info("InitializeDevice: %v", err)
	} else {
		sl.L.Alert("InitializeDevice: %v", err)
	}

	sl.L.Debug("InitializeDevice: %v, %v", ret1, ret2)
	return
}

// typedef long    (*_ExecuteCommandFunc)( long command, void *params, void *result );
func ExecuteCommand(command int32, param, result uintptr) (err error) {
	var ret1, ret2 uintptr
	ret1, ret2, err = executeCommand.Call(
		uintptr(unsafe.Pointer(&command)),
		param,
		result,
	)
	if ret1 == 0 || ret1 == 1 || err.Error() == "The operation completed successfully." {
		sl.L.Info("ExecuteCommand %v: %v", command, err)
	} else {
		sl.L.Alert("ExecuteCommand %v: %v", command, err)
	}

	sl.L.Debug("executeCommand %v: %v, %v", command, ret1, ret2)
	return
}

func FreeDevice() (err error) {
	var ret1, ret2 uintptr
	ret1, ret2, err = free.Call()
	if ret1 == 0 || ret1 == 1 || err.Error() == "The operation completed successfully." {
		sl.L.Info("FreeDevice: %v", err)
	} else {
		sl.L.Alert("FreeDevice: %v", err)
	}

	sl.L.Debug("FreeDevice: %v, %v", ret1, ret2)
	return
}

func GetVersion() (err error) {
	var ret1, ret2 uintptr
	ret1, ret2, err = libVersion.Call()
	if ret1 == 0 || ret1 == 1 || err.Error() == "The operation completed successfully." {
		sl.L.Info("GetVersion: %v", err)
	} else {
		sl.L.Alert("GetVersion: %v", err)
	}

	sl.L.Debug("GetVersion: %v, %v", ret1, ret2)
	return
}
