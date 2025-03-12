package form

import (
	"regulaclient/pkg/usedll"
	"unsafe"

	"fyne.io/fyne"
	"fyne.io/fyne/app"
	"fyne.io/fyne/canvas"
	"fyne.io/fyne/container"
	"fyne.io/fyne/widget"
	sl "github.com/Averianov/cisystemlog"
)

const (
	PATH_PHOTO  string = "Avatar.jpg"
	PATH_ICON   string = "Icon.png"
	WINDOW_NAME string = "Regual Client VFS"
)

var (
	Image1 *canvas.Image
	Image2 *canvas.Image
	Image3 *canvas.Image
	// box    *fyne.Container
	// table  *widget.Table

	// scans = []scan{
	// 	{&canvas.Image{File: pathPhoto, FillMode: canvas.ImageFillOriginal},
	// 		&canvas.Image{File: pathPhoto, FillMode: canvas.ImageFillOriginal},
	// 		&canvas.Image{File: pathPhoto, FillMode: canvas.ImageFillOriginal}},
	// }
)

type Form struct {
	fyne.Window
}

func InitForm() (err error) {
	Image1 = &canvas.Image{}
	Image2 = &canvas.Image{}
	Image3 = &canvas.Image{}

	Image1.SetMinSize(fyne.NewSize(200, 150))
	Image1.Move(fyne.Position{X: 0, Y: 50})
	Image2.SetMinSize(fyne.NewSize(200, 150))
	Image2.Move(fyne.Position{X: 200, Y: 50})
	Image3.SetMinSize(fyne.NewSize(200, 150))
	Image3.Move(fyne.Position{X: 400, Y: 50})

	a := app.New()
	w := &Form{
		a.NewWindow(WINDOW_NAME),
	}
	icon, err := fyne.LoadResourceFromPath(PATH_ICON)
	if err != nil {
		sl.L.Alert("%v", err)
	}
	w.SetIcon(icon)
	w.Resize(fyne.NewSize(700, 400))

	bConnect := widget.NewButton("Connect", func() {
		//w.ConnectDevice()
		var deviceCount int32
		usedll.ExecuteCommand(&usedll.RPRM_Command_Device_Count, 0, uintptr(unsafe.Pointer(&deviceCount)))
		sl.L.Info("deviceCount: %v", deviceCount)
	})
	bConnect.Resize(fyne.Size{Width: 150, Height: 10})
	bDisconnect := widget.NewButton("Disconnect", func() {
		w.DisconnectDevice()
	})
	bDisconnect.Resize(fyne.Size{Width: 150, Height: 10})
	bDisconnect.Hide()

	bScan := widget.NewButton("Start Scan", func() {
		w.UploadPhoto()
	})
	bScan.Resize(fyne.Size{Width: 150, Height: 10})

	tableV := widget.NewTable(
		func() (int, int) {
			rows := 6
			cols := 1
			return rows, cols
		},

		func() fyne.CanvasObject {
			i := canvas.NewImageFromFile(PATH_PHOTO)
			i.FillMode = canvas.ImageFillContain
			i.SetMinSize(fyne.NewSize(200, 100))
			return i
		},

		func(id widget.TableCellID, c fyne.CanvasObject) {
			// img := c.(*canvas.Image)
			// col, row := id.Col, id.Row
			// // Data row
			// acc := scans[row-1]
			// var res image.Image
			// switch col {
			// case 0:
			// 	res = acc.ir.Image
			// case 1:
			// 	res = acc.wight.Image
			// case 2:
			// 	res = acc.uv.Image
			// }

			// img = canvas.NewImageFromImage(res)
		})

	//tableV.SetRowHeight(0, 600)
	tableV.SetColumnWidth(0, 200)
	tableV.Resize(fyne.NewSize(200, 600))

	w.SetContent(
		container.NewVBox(
			container.NewHBox(bConnect, bDisconnect, bScan),
			container.NewHBox(Image1, Image2, Image3, tableV),
		),
	)
	w.ShowAndRun()
	return
}

func (w *Form) UploadPhoto() (err error) {
	//sl.L.Info("%v", pathPhoto)
	Image1.File = PATH_PHOTO
	Image2.File = PATH_PHOTO
	Image3.File = PATH_PHOTO

	Image1.SetMinSize(fyne.NewSize(200, 150))
	Image1.Move(fyne.Position{X: 0, Y: 50})
	sl.L.Info("%v", Image1.Position())
	Image2.SetMinSize(fyne.NewSize(200, 150))
	Image2.Move(fyne.Position{X: 200, Y: 50})
	sl.L.Info("%v", Image2.Position())
	Image3.SetMinSize(fyne.NewSize(200, 150))
	Image3.Move(fyne.Position{X: 400, Y: 50})
	sl.L.Info("%v", Image3.Position())

	w.Canvas().Refresh(Image1)
	w.Canvas().Refresh(Image2)
	w.Canvas().Refresh(Image3)
	return
}

func (w *Form) ConnectDevice() (err error) {
	//pkg.Version()
	//pkg.Initialize()
	return
}

func (w *Form) DisconnectDevice() (err error) {
	//pkg.Free()
	return
}
