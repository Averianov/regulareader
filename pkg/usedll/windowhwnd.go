package usedll

import (
	"fmt"
	"syscall"
)

func GetHWND() (hwnd uintptr, err error) {
	kernel32 := syscall.NewLazyDLL("kernel32.dll")
	getConsoleWindow := kernel32.NewProc("GetConsoleWindow")
	hwnd, _, err = getConsoleWindow.Call()
	if hwnd == 0 {
		err = fmt.Errorf("no associated console: %v", err)
	}
	return
}
