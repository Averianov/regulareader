package oleapi

import (
	sl "github.com/Averianov/cisystemlog"
	ole "github.com/go-ole/go-ole"
)

const PORG_ID string = "READERDEMO.RegulaReader"

func InitializeOleConnection() (conn *ole.Connection, err error) {
	conn = &ole.Connection{}
	err = conn.Initialize()
	if err != nil {
		return
	}

	err = conn.Create(PORG_ID)
	if err != nil {
		sl.L.Info("%v", err)
		if err.(*ole.OleError).Code() == ole.CO_E_CLASSSTRING {
			return
		}
	}
	return
}

func DispatchOle(conn *ole.Connection) {
	dispatch, err := conn.Dispatch()
	if err != nil {
		sl.L.Info("%v", err)
		return
	}
	defer dispatch.Release()
}

// NOT WORK???
// func InitializeDeviceOle() (err error) {
// 	command := &commander.Command{
// 		UsageLine: os.Args[0],
// 		Short:     "READERDEMO",
// 		Long:      "Regula Document Reader SDK (x64)",
// 	}
// 	command.Subcommands = []*commander.Command{}
// 	for _, name := range []string{
// 		"_LibraryVersion",
// 		"_Free",
// 		"_Initialize",
// 		"_ExecuteCommand",
// 		"_SetCallbackFunc",
// 	} {
// 		command.Subcommands = append(command.Subcommands, &commander.Command{
// 			Run: func(cmd *commander.Command, args []string) error {
// 				_, err := oleutil.CallMethod(Regula(), name)
// 				return err
// 			},
// 			UsageLine: strings.ToLower(name),
// 		})
// 	}
// 	err = command.Dispatch(context.Background(), os.Args[1:])
// 	if err != nil {
// 		log.Fatal(err)
// 	}
// 	return
// }

// func Regula() *ole.IDispatch {
// 	ole.CoInitialize(0)
// 	unknown, err := oleutil.CreateObject(PORG_ID)
// 	if err != nil {
// 		log.Fatal(err)
// 	}
// 	sl.L.Info("Regula: %v", unknown)

// 	regula, err := unknown.QueryInterface(ole.IID_IDispatch)
// 	if err != nil {
// 		log.Fatal(err)
// 	}
// 	sl.L.Info("Regula: %v", unknown)
// 	return regula
// }
