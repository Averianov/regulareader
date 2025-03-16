package usedll

import "fmt"

type eLED_Color int32

// enum eLED_Color
const (
	ledNone   eLED_Color = 0
	ledRed    eLED_Color = 1
	ledGreen  eLED_Color = 2
	ledOrange eLED_Color = 3
)

func (e eLED_Color) String() string {
	switch e {
	case ledNone:
		return "ledNone"
	case ledRed:
		return "ledRed"
	case ledGreen:
		return "ledGreen"
	case ledOrange:
		return "ledOrange"
	}
	return fmt.Sprintf("Unknown color(%d)", e)
}
