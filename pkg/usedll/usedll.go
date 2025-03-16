package usedll

/*
#cgo LDFLAGS: -L../source -lPasspR40
#cgo CFLAGS: -I../../source
#include "PasspR.h"
*/
import "C"

import (
	"fmt"
	"syscall"
	"unsafe"

	sl "github.com/Averianov/cisystemlog"
)

var (
	Passpr40        *syscall.DLL
	setCallbackFunc *syscall.Proc
	initialize      *syscall.Proc
	executeCommand  *syscall.Proc
	libVersion      *syscall.Proc
	free            *syscall.Proc
	// windowHandler syscall.Handle
)

func LoadDLL() {
	var err error
	Passpr40, err = syscall.LoadDLL("C:\\Program Files\\Regula\\Document Reader SDK\\PasspR40.dll")
	if err != nil {
		sl.L.Alert("LoadDLL: %v", err)
	}
	libVersion, err = Passpr40.FindProc("_LibraryVersion")
	if err != nil {
		sl.L.Alert("FindProc libVersion: %v", err)
	}
	free, err = Passpr40.FindProc("_Free")
	if err != nil {
		sl.L.Alert("FindProc free: %v", err)
	}
	initialize, err = Passpr40.FindProc("_Initialize")
	if err != nil {
		sl.L.Alert("FindProc initialize: %v", err)
	}
	executeCommand, err = Passpr40.FindProc("_ExecuteCommand")
	if err != nil {
		sl.L.Alert("FindProc executeCommand: %v", err)
	}
	setCallbackFunc, err = Passpr40.FindProc("_SetCallbackFunc")
	if err != nil {
		sl.L.Alert("FindProc setCallbackFunc: %v", err)
	}

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

	//var params int32
	var ret1, ret2 uintptr
	ret1, ret2, err = initialize.Call(
	//uintptr(0), // void *lpParams
	//uintptr(0), // HWND hParent
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
func ExecuteCommand(command RPRM_Command, param, result uintptr) (anyResult any, err error) {
	var ret1, ret2 uintptr
	ret1, ret2, err = executeCommand.Call(
		uintptr(unsafe.Pointer(&command)),
		param,
		result,
	)

	var rawerror RPRM_ErrorCode = RPRM_ErrorCode(int32(ret1))
	err = fmt.Errorf("%s (%s)", err.Error(), rawerror.String())

	anyResult = any(result)
	if ret1 == 0 || ret1 == 1 || err.Error() == "The operation completed successfully." {
		sl.L.Info("ExecuteCommand %s: %s (%v); result %v", command.String(), err.Error(), ret2, anyResult)
	} else {
		sl.L.Alert("ExecuteCommand %s: %s (%v); result %v", command.String(), err.Error(), ret2, anyResult)
	}
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
