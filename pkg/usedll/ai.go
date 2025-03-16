package usedll

/*
#cgo CXXFLAGS: -std=c++11
#cgo CFLAGS: -I../../source
#cgo LDFLAGS: -L../../source -lregula -lPasspR40 -lstdc++ -lole32 -loleaut32 -luser32

#include <stdlib.h>
#include <stdint.h>
#include "PasspR.h"
#include "regula.h"

// Обратные вызовы из Go в C
extern void goResultReceivingCallback(void* result, uint32_t* postAction, uint32_t* postActionParam);
extern void goNotifyCallback(int code, int value);
*/
import "C"
import (
	"fmt"
	"unsafe"

	sl "github.com/Averianov/cisystemlog"
)

// Колбэк для получения результатов
//
//export goResultReceivingCallback
func goResultReceivingCallback(result unsafe.Pointer, postAction *C.uint32_t, postActionParam *C.uint32_t) {
	rprmResult := (*RPRM_ResultType)(result)
	sl.L.Warning("Получен результат: %v, postAction=%d, postActionParam=%d",
		rprmResult.String(), *postAction, *postActionParam)
}

// Колбэк для получения уведомлений
//
//export goNotifyCallback
func goNotifyCallback(code C.int, value C.int) {
	switch RPRM_NotifyCode(code) {
	case RPRM_Notification_Error:
		sl.L.Alert("Ошибка: %s", RPRM_ErrorCode(value).String())
	case RPRM_Notification_DeviceDisconnected:
		sl.L.Warning("Устройство отключено")
	case RPRM_Notification_DocumentReady:
		sl.L.Debug("Документ готов")
	case RPRM_Notification_Scanning:
		sl.L.Debug("Сканирование")
	case RPRM_Notification_Calibration:
		sl.L.Debug("Калибровка")
	case RPRM_Notification_CalibrationProgress:
		sl.L.Debug("Калибровка в процессе")
	case RPRM_Notification_CalibrationStep:
		sl.L.Debug("Этап Калибровки")
	case RPRM_Notification_EnumeratingDevices:
		switch value {
		case 0:
			sl.L.Warning("Начата инициализации устройств")
		case 1:
			sl.L.Warning("Инициализация устройств завершена")
		}
	case RPRM_Notification_ConnectingDevice:
		sl.L.Debug("Подключение устройства")
	case RPRM_Notification_DocumentCanBeRemoved:
		sl.L.Debug("Документ можно удалить")
	case RPRM_Notification_LidOpen:
		sl.L.Debug("Крышка открыта")
	case RPRM_Notification_Processing:
		sl.L.Debug("Обработка")
	case RPRM_Notification_DownloadingCalibrationInfo:
		sl.L.Debug("Скачивание информации о калибровке")
	case RPRM_Notification_LicenseExpired:
		sl.L.Debug("Лицензия истекла")
	case RPRM_Notification_OperationProgress:
		sl.L.Debug("Операция в процессе")
	case RPRM_Notification_LatestAvailableSDK:
		sl.L.Debug("Доступная версия SDK")
	case RPRM_Notification_LatestAvailableDatabase:
		sl.L.Debug("Доступная база данных")
	case RPRM_Notification_VideoFrame:
		sl.L.Debug("Кадр видео")
	case RPRM_Notification_CompatibilityMode:
		sl.L.Debug("Режим совместимости")
	default:
		sl.L.Warning("Получено неизвестное уведомление: %d: %v", code, value)
	}
}

func AISetCallbackFunc() (err error) {
	sl.L.Debug("Устанавливаем колбэки...")
	C.Regula_SetCallbackFunc(
		unsafe.Pointer(C.goResultReceivingCallback),
		unsafe.Pointer(C.goNotifyCallback),
	)
	return
}

func AIInitialize() (err error) {
	// 2. Инициализируем библиотеку
	sl.L.Debug("Инициализация библиотеки...")
	response := C.Regula_Initialize(nil, nil)

	if response != 0 && response != 1 {
		sl.L.Alert("AIInitialize: %s\n", RPRM_ErrorCode(response).String())
		return
	}

	sl.L.Info("AIInitialize: %s", RPRM_ErrorCode(response).String())

	//

	/*var result, param any
	param = -1
	result, err = AIExecuteCommand(C.GO_COMMAND_DEVICE_CONNECT, unsafe.Pointer(&param))
	if err != nil {
		sl.L.Alert(err.Error())
		return
	}
	sl.L.Info("result: %v", result)/**/
	return
}

// func AIExecuteCommand(command C.long, params unsafe.Pointer) (result any, err error) {
func AIExecuteCommand(command int32, params unsafe.Pointer) (result any, err error) {
	stringCommand := RPRM_Command(command).String()
	sl.L.Debug("Выполняем команду %s", stringCommand)

	var cResult C.void // Инициализация переменной для результата
	response := C.Regula_ExecuteCommand(
		C.long(command),
		params,
		unsafe.Pointer(&cResult),
	)

	if response != 0 && response != 1 {
		err = fmt.Errorf("AIExecuteCommand %s: %s", stringCommand, RPRM_ErrorCode(response).String())
		sl.L.Alert(err.Error())
		return
	}

	// Преобразование результата в Go
	result = cResult // Присваиваем результат
	stringResult := fmt.Sprintf("%v", result)
	sl.L.Info("AIExecuteCommand %s: %s %v", stringCommand, RPRM_ErrorCode(response).String(), stringResult)
	return
}

func AILibraryVersion() (err error) {
	sl.L.Debug("Получаем версию библиотеки...")

	version := C.Regula_LibraryVersion()
	sl.L.Info("Версия библиотеки: %v", version)
	return
}
