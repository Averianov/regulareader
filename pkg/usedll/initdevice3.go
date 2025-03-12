package usedll

// import (
// 	"syscall"

// 	sl "github.com/Averianov/cisystemlog"
// )

// var (
// 	passpR40, _    = syscall.LoadLibrary("./lib/PasspR40.dll")
// 	version, _     = syscall.GetProcAddress(passpR40, " _LibraryVersion")
// 	initialize2, _ = syscall.GetProcAddress(passpR40, " _Initialize")
// 	free2, _       = syscall.GetProcAddress(passpR40, " _Free")
// )

// func Version() (handle uintptr) {
// 	if r1, r2, err := syscall.SyscallN(uintptr(version)); err != 0 {
// 		sl.L.Alert("%v", err)
// 		return
// 	} else {
// 		sl.L.Info("%v", r1)
// 		sl.L.Info("%v", r2)
// 		handle = r1
// 	}
// 	return
// }

// func Initialize() (handle uintptr) {
// 	var nargs uintptr = 0
// 	r1, r2, err := syscall.SyscallN(uintptr(initialize2), nargs, 0, 0, 0)
// 	if err != 0 {
// 		sl.L.Alert("%v", err)
// 		return
// 	} else {
// 		sl.L.Info("%v", r1)
// 		sl.L.Info("%v", r2)
// 		handle = r1
// 	}
// 	return
// }

// func Free() (handle uintptr) {
// 	if ret, _, err := syscall.SyscallN(uintptr(free2)); err != 0 {
// 		sl.L.Alert("%v", err)
// 	} else {
// 		handle = ret
// 	}
// 	return
// }
