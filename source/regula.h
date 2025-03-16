#pragma once

#include "PasspR.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Мост-функции для интеграции с Go
long Regula_Initialize(void *lpParams, void *hParent);
void Regula_SetCallbackFunc(void *f1, void *f2);
long Regula_ExecuteCommand(long command, void *params, void *result);
uint32_t Regula_LibraryVersion();

// Константы для команд из PasspR.h, которые будут использоваться в Go
enum {
    GO_COMMAND_DEVICE_COUNT = RPRM_Command_Device_Count,
    GO_COMMAND_DEVICE_REFRESH_LIST = RPRM_Command_Device_RefreshList,
    GO_COMMAND_DEVICE_FEATURES = RPRM_Command_Device_Features,
    GO_COMMAND_DEVICE_CONNECT = RPRM_Command_Device_Connect,
    GO_COMMAND_DEVICE_DISCONNECT = RPRM_Command_Device_Disconnect,
    GO_COMMAND_DEVICE_ACTIVE_INDEX = RPRM_Command_Device_ActiveIndex,
};

#ifdef __cplusplus
}
#endif
