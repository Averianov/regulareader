package usedll

/*
#cgo LDFLAGS: -L../../source -lPasspR40
#cgo CFLAGS: -I../../source
#include "PasspR.h"
//typedef void (*_SetCallbackFuncFunc)(ResultReceivingFunc f1, NotifyFunc f2 );
//typedef long (*_ExecuteCommandFunc)(long, void*, void*);
long (_ExecuteCommand)(long command, void *params, void *result );
//extern _ExecuteCommand() ExecuteCommand;
*/
import "C"
import (
	sl "github.com/Averianov/cisystemlog"
)

func CSetCallbackFunc() {
	// //var command C.long = 42
	// var command int32 = 42
	// var params, result unsafe.Pointer

	// // ecf := C.ExecuteCommand
	// // sl.L.Warning("ExecuteCommand: %v", ecf)

	// //ecf2 := ecf(int32, unsafe.Pointer, unsafe.Pointer)
	// res := C._ExecuteCommandFunc(command, params, result)
	// // res := C.ExecuteCommand(command, params, result)
	// sl.L.Warning("ExecuteCommand: %v", res)

	//scbf *C._SetCallbackFuncFunc
	//sl.L.Warning("CSetCallbackFunc: %v", res)
	// resultf := MyResultReceivingFunc
	// notifyf := MyNotifyFunc

	// *scbf(resultf, notifyf)
}

// typedef void (__stdcall *ResultReceivingFunc) ( TResultContainer *result, uint32_t *PostAction, uint32_t *PostActionParameter );
//
// export MyResultReceivingFunc
func MyResultReceivingFunc(result C.TResultContainer, postAction, postActionParam *uint32) {
	sl.L.Warning("ResultFunc: %v, %v, %v", result, postAction, postActionParam)
}

// typedef void (__stdcall *NotifyFunc)(intptr_t code, intptr_t value);
//
// export MyNotifyFunc
func MyNotifyFunc(code, value uintptr) {
	sl.L.Warning("NotifyFunc: %v, %v", code, value)

	// switch notify {
	// case ALREADY_DONE:
	// 	sl.L.Info("%v", notify)
	// case NO_ERROR:
	// 	sl.L.Info("%v", notify)
	// default:
	// 	sl.L.Warning("%v", notify)
	// }
}
