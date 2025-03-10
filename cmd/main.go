package main

import (
	"regulaclient/pkg"

	"fyne.io/fyne/v2"
	"fyne.io/fyne/v2/app"
	"fyne.io/fyne/v2/canvas"
	"fyne.io/fyne/v2/container"
	"fyne.io/fyne/v2/widget"

	sl "github.com/Averianov/cisystemlog"
)

type form struct {
	fyne.Window
}

type scan struct {
	ir    *canvas.Image
	wight *canvas.Image
	uv    *canvas.Image
}

const pathPhoto string = "Avatar.jpg"
const pathIcon string = "Icon.png"

var (
	L      *sl.Logs
	image1 *canvas.Image
	image2 *canvas.Image
	image3 *canvas.Image
	box    *fyne.Container
	table  *widget.Table

	scans = []scan{
		{&canvas.Image{File: pathPhoto, FillMode: canvas.ImageFillOriginal},
			&canvas.Image{File: pathPhoto, FillMode: canvas.ImageFillOriginal},
			&canvas.Image{File: pathPhoto, FillMode: canvas.ImageFillOriginal}},
	}
)

func main() {
	L = sl.CreateLogs(4, 5) // ##########################################
	L.RemoveLogFile(3)

	a := app.New()
	w := &form{
		a.NewWindow("Regual Client VFS"),
	}
	w.Resize(fyne.NewSize(900, 700))
	w.SetIcon(canvas.NewImageFromFile(pathIcon).Resource)

	bConnect := widget.NewButton("Connect", func() {
		w.ConnectDevice()
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

	tableH := widget.NewTable(
		func() (int, int) {
			rows := 1
			cols := 3
			return rows, cols
		},

		func() fyne.CanvasObject {
			l := canvas.NewImageFromFile(pathPhoto)
			l.FillMode = canvas.ImageFillOriginal
			return l
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

	tableV := widget.NewTable(
		func() (int, int) {
			rows := 2
			cols := 1
			return rows, cols
		},

		func() fyne.CanvasObject {
			i := canvas.NewImageFromFile(pathPhoto)
			i.FillMode = canvas.ImageFillOriginal
			i.SetMinSize(fyne.NewSize(100, 80))
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

	tableH.Resize(fyne.NewSize(600, 200))
	tableH.SetRowHeight(0, 200)
	tableH.SetColumnWidth(0, 200)
	tableH.SetColumnWidth(1, 200)
	tableH.SetColumnWidth(2, 200)

	w.SetContent(
		container.NewVBox(
			container.NewHBox(bConnect, bDisconnect, bScan),
			container.NewHBox(tableH, tableV),
		),
	)
	w.ShowAndRun()
}

func (w *form) UploadPhoto() (err error) {
	// pwd, _ := os.Getwd()
	// path := filepath.Join(filepath.Dir(pwd), "Avatar.jpg")
	sl.L.Info("%v", pathPhoto)
	//image1 = &canvas.Image{File: "Avatar.jpg", FillMode: canvas.ImageFillOriginal}
	//image1 = canvas.NewImageFromFile(path)
	image1.File = pathPhoto
	image1.SetMinSize(fyne.NewSize(300, 200))
	//image1.Position()
	image1.Move(fyne.Position{X: 0, Y: 0})
	sl.L.Info("%v", image1.Position())
	//image1.ScaleMode = canvas.ImageScalePixels
	image2.File = pathPhoto
	image2.SetMinSize(fyne.NewSize(300, 200))
	image2.Move(fyne.Position{X: 0, Y: 100})
	sl.L.Info("%v", image2.Position())
	image3.File = pathPhoto
	image3.SetMinSize(fyne.NewSize(300, 200))
	image3.Move(fyne.Position{X: 200, Y: 0})
	sl.L.Info("%v", image3.Position())
	return
}

func (w *form) ConnectDevice() (err error) {
	pkg.Initialize()
	return
}

func (w *form) DisconnectDevice() (err error) {
	pkg.Free()
	return
}
