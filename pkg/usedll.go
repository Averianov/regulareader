package pkg

// import ("C")
// ...
// C.SomeDllFunc(...)

import (
	"syscall"
)

var (
	passpR40, _   = syscall.LoadLibrary("PasspR40.dll")
	initialize, _ = syscall.GetProcAddress(passpR40, " _Initialize")
	free, _       = syscall.GetProcAddress(passpR40, " _Free")
)

func Initialize() (handle uintptr) {
	var nargs uintptr = 0
	if ret, _, callErr := syscall.SyscallN(uintptr(initialize), nargs, 0, 0, 0); callErr != 0 {
		//abort("Call GetModuleHandle", callErr)
	} else {
		handle = ret
	}
	return
}

func Free() (handle uintptr) {
	var nargs uintptr = 0
	if ret, _, callErr := syscall.SyscallN(uintptr(free), nargs, 0, 0, 0); callErr != 0 {
		//abort("Call GetModuleHandle", callErr)
	} else {
		handle = ret
	}
	return
}
