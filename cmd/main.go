package main

import (
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
	w.Resize(fyne.NewSize(800, 600))

	start := widget.NewButton("Start Scan", func() {
		w.UploadPhoto()
	})
	start.Resize(fyne.Size{Width: 150, Height: 10})

	// w.SetContent(container.NewVBox(
	// 	start,
	// 	//box,
	// 	//photoList,
	// ))

	table := widget.NewTable(
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

	table.SetColumnWidth(0, 200)
	table.SetColumnWidth(1, 200)
	table.SetColumnWidth(2, 200)

	w.SetContent(container.NewStack(start, table))
	w.ShowAndRun()
}

func (w *form) UploadPhoto() (err error) {
	// pwd, _ := os.Getwd()
	// path := filepath.Join(filepath.Dir(pwd), "Avatar.jpg")
	path := "./Avatar.jpg"
	sl.L.Info("%v", path)
	//image1 = &canvas.Image{File: "Avatar.jpg", FillMode: canvas.ImageFillOriginal}
	//image1 = canvas.NewImageFromFile(path)
	image1.File = path
	image1.SetMinSize(fyne.NewSize(300, 200))
	//image1.Position()
	image1.Move(fyne.Position{X: 0, Y: 0})
	sl.L.Info("%v", image1.Position())
	//image1.ScaleMode = canvas.ImageScalePixels
	image2.File = path
	image2.SetMinSize(fyne.NewSize(300, 200))
	image2.Move(fyne.Position{X: 0, Y: 100})
	sl.L.Info("%v", image2.Position())
	image3.File = path
	image3.SetMinSize(fyne.NewSize(300, 200))
	image3.Move(fyne.Position{X: 200, Y: 0})
	sl.L.Info("%v", image3.Position())
	return
}
