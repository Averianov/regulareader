package oleapi

import (
	"context"
	"log"
	"os"
	"strings"

	sl "github.com/Averianov/cisystemlog"
	ole "github.com/go-ole/go-ole"
	"github.com/go-ole/go-ole/oleutil"
	"github.com/gonuts/commander"
)

func InitializeDeviceOle() (err error) {
	command := &commander.Command{
		UsageLine: os.Args[0],
		Short:     "READERDEMO",
		Long:      "Regula Document Reader SDK (x64)",
	}
	command.Subcommands = []*commander.Command{}
	for _, name := range []string{
		"_LibraryVersion",
		"_Free",
		"_Initialize",
		"_ExecuteCommand",
		"_SetCallbackFunc",
	} {
		command.Subcommands = append(command.Subcommands, &commander.Command{
			Run: func(cmd *commander.Command, args []string) error {
				_, err := oleutil.CallMethod(Regula(), name)
				return err
			},
			UsageLine: strings.ToLower(name),
		})
	}
	err = command.Dispatch(context.Background(), os.Args[1:])
	if err != nil {
		log.Fatal(err)
	}
	return
}

func Regula() *ole.IDispatch {
	ole.CoInitialize(0)
	unknown, err := oleutil.CreateObject("READERDEMO")
	if err != nil {
		log.Fatal(err)
	}
	sl.L.Info("Regula: %v", unknown)

	regula, err := unknown.QueryInterface(ole.IID_IDispatch)
	if err != nil {
		log.Fatal(err)
	}
	sl.L.Info("Regula: %v", unknown)
	return regula
}
