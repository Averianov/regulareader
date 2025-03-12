package usedll

// /*
// #cgo LDFLAGS: -L. -lPasspR40
// #cgo CFLAGS: -I./lib

// #include "PasspR.h"
// */
// import "C"

// func InitDevice() {
// 	C.Initialize()
// }

type Regula struct {
	// _LibraryVersionFunc  *windows.Proc `func:"_LibraryVersionFunc"`
	// _SetCallbackFuncFunc *windows.Proc `func:"_SetCallbackFuncFunc"`
	// _InitializeFunc      *windows.Proc `func:"_InitializeFunc"`
	// _FreeFunc            *windows.Proc `func:"_FreeFunc"`

	// _ExecuteCommandFunc      *windows.Proc `func:"_ExecuteCommandFunc"`
	// _CheckResultFunc         *windows.Proc `func:"_CheckResultFunc"`
	// _CheckResultFromListFunc *windows.Proc `func:"_CheckResultFromListFunc"`
	// _ResultTypeAvailableFunc *windows.Proc `func:"_ResultTypeAvailableFunc"`

	// _AllocRawImageContainerFunc *windows.Proc `func:"_AllocRawImageContainerFunc"`
	// _FreeRawImageContainerFunc  *windows.Proc `func:"_FreeRawImageContainerFunc"`

	// _FDSUser_ConnectFunc      *windows.Proc `func:"_FDSUser_ConnectFunc"`
	// _FDSUser_DisconnectFunc   *windows.Proc `func:"_FDSUser_DisconnectFunc"`
	// _FDSUser_UpdateWindowFunc *windows.Proc `func:"_FDSUser_UpdateWindowFunc"`
	// _FDSUser_UpdatePanelFunc  *windows.Proc `func:"_FDSUser_UpdatePanelFunc"`

	// _FDSUser_SelectDocumentFunc *windows.Proc `func:"_FDSUser_SelectDocumentFunc"`
}

// func InitializeDevice() {
// 	// r := Regula{}
// 	// err := goinvoke.Unmarshal("./lib/PasspR40.dll", &r)
// 	// if err != nil {
// 	// 	panic(err)
// 	// }

// 	var dll *goinvoke.DLL
// 	dll, err := goinvoke.LoadDLL("./lib/PasspR40.dll")
// 	if err != nil {
// 		sl.L.Alert(err)
// 	}

// 	var initialize *goinvoke.Proc
// 	initialize, err = dll.FindProc("_Initialize")
// 	if err != nil {
// 		sl.L.Alert(err)
// 	}

// 	r1, r2, err := initialize.Call(initialize.Addr())
// 	if err != nil {
// 		sl.L.Alert(err)
// 	}

// 	sl.L.Info("%v - %v", r1, r2)

// 	// startupInfo := windows.StartupInfo{}
// 	// _, _, err = r.Initialize.Call(uintptr(unsafe.Pointer(&startupInfo)))
// 	// if !errors.Is(err, windows.ERROR_SUCCESS) {
// 	// 	panic(err)
// 	// }
// 	// lpTitle := windows.UTF16PtrToString(startupInfo.Title)
// 	// fmt.Printf("lpTitle = %s\n", lpTitle)
// }
