package usedll

/*
//#cgo LDFLAGS: -L. -lPasspR40
//#cgo CFLAGS: -I.
#include <PasspR.h>
// extern void (__stdcall *ResultReceivingFunc)(TResultContainer *result, uint32_t *PostAction, uint32_t *PostActionParameter );
// extern void (__stdcall *NotifyFunc)(intptr_t code, intptr_t value);
// extern void (*_SetCallbackFuncFunc)(MyResultReceivingFunc f1, MyNotifyFunc f2);
*/
import "C"

import (
	"unsafe"

	sl "github.com/Averianov/cisystemlog"
)

// typedef void (*_SetCallbackFuncFunc)( ResultReceivingFunc f1, NotifyFunc f2 );
func SetCallbackFunc(resultFunc func(C.TResultContainer, *uint32, *uint32),
	notifyFunc func(uintptr, uintptr)) (err error) {
	resultf := resultFunc
	notifyf := notifyFunc
	var ret1, ret2 uintptr
	ret1, ret2, err = setCallbackFunc.Call(
		uintptr(unsafe.Pointer(&resultf)),
		uintptr(unsafe.Pointer(&notifyf)),
	)
	if ret1 == 0 || ret1 == 1 || err.Error() == "The operation completed successfully." {
		sl.L.Info("SetCallbackFunc: %v", err)
	} else {
		sl.L.Alert("SetCallbackFunc: %v", err)
	}

	sl.L.Debug("SetCallbackFunc: %v, %v", ret1, ret2)
	return
}

// // typedef void (__stdcall *ResultReceivingFunc) ( TResultContainer *result, uint32_t *PostAction, uint32_t *PostActionParameter );
// //
// // export MyResultReceivingFunc
// func MyResultReceivingFunc(result C.TResultContainer, postAction, postActionParam *uint32) {
// 	sl.L.Warning("ResultFunc: %v, %v, %v", result, postAction, postActionParam)
// }

// // typedef void (__stdcall *NotifyFunc)(intptr_t code, intptr_t value);
// //
// // export MyNotifyFunc
// func MyNotifyFunc(code, value uintptr) {
// 	sl.L.Warning("NotifyFunc: %v, %v", code, value)

// 	// switch notify {
// 	// case ALREADY_DONE:
// 	// 	sl.L.Info("%v", notify)
// 	// case NO_ERROR:
// 	// 	sl.L.Info("%v", notify)
// 	// default:
// 	// 	sl.L.Warning("%v", notify)
// 	// }
// }
