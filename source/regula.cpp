#include "PasspR.h"
#include "regula.h"
#include "HKEY_Helper.h"
#include <Windows.h>
#include <string>
#include <cstdio>
#include <cwchar>
#include <memory>
#include <cstring>

// Прототипы для колбэк-функций
static ResultReceivingFunc g_ResultReceivingFunc = NULL;
static NotifyFunc g_NotifyFunc = NULL;

// Определяем типы функций из внешней библиотеки
typedef void (REGULA_STDCALL *_SetCallbackFuncFunc)(ResultReceivingFunc f1, NotifyFunc f2);
typedef long (REGULA_STDCALL *_InitializeFunc)(void *lpParams, HWND hParent);
typedef long (REGULA_STDCALL *_ExecuteCommandFunc)(long command, void *params, void *result);
typedef uint32_t (REGULA_STDCALL *_LibraryVersionFunc)();

// Определяем указатели на функции из внешней библиотеки
static _SetCallbackFuncFunc pfnSetCallbackFuncFunc = NULL;
static _InitializeFunc pfnInitializeFunc = NULL;
static _ExecuteCommandFunc pfnExecuteCommandFunc = NULL;
static _LibraryVersionFunc pfnLibraryVersionFunc = NULL;

// Указатель на загруженную библиотеку
static HMODULE hDLL = NULL;

// Функция загрузки библиотеки и инициализации указателей на функции
bool LoadRegulaLibrary() {
    if (hDLL != NULL) {
        //printf("dll is loaded\n");
        return true; // Библиотека уже загружена
    }

    printf("load dll\n");

    // начало КОДа ИЗ unit1.cpp 
    // Get Registry sub-key holding library path depending on Windows bitness
    ::SYSTEM_INFO info {};
    ::GetSystemInfo( &info );
    //printf("SYSTEM_INFO: %d\n", info);
    //wprintf(L"SYSTEM_INFO: %d\n", info);

    const wchar_t* subKey {};
    switch( info.wProcessorArchitecture )
    {
    case PROCESSOR_ARCHITECTURE_AMD64:
        subKey = L"SOFTWARE\\Regula\\Document Reader SDK (x64)";
        break;
    case PROCESSOR_ARCHITECTURE_INTEL:
        subKey = L"SOFTWARE\\Regula\\Document Reader SDK";
        break;
    default:
        //throw Exception { "Unsupported architecture" };
        //throw printf("Unsupported architecture\n");
        printf("Unsupported architecture\n");
        return false;
    }
    
    //wprintf(L"subKey: %ls\n", subKey);

    // Get PasspR40.dll path
    const HKEY_Helper hKey { subKey };
    //wprintf(L"hKey: %ls\n", hKey.mKey);

    // Query size of the Path
    const wchar_t* Name = L"Path";
    DWORD bufSz {};
    auto ec = ::RegQueryValueExW( hKey,
                                  Name,
                                  nullptr,
                                  nullptr,
                                  nullptr,
                                  &bufSz );
    if( ec != ERROR_SUCCESS )
    {
        //throw Exception { "Cannot query Registry" };
        //throw printf("Cannot query Registry\n");
        printf("Cannot query Registry: %d\n", ec);
        return false;
    }

    if( 0 == bufSz )
    {
        
        //throw printf("Empty Path key!\n");
        printf("Empty Path key!\n");
        return false;
    }

    
    //wprintf(L"use registry: %d\n", bufSz);

    // Get the 'Path' key value and build a path to PasspR40.dll
    const wchar_t* libName = L"PasspR40.dll";
    const auto oldBufSz = bufSz;
    bufSz += std::wcslen( libName ) + sizeof( L'\0' );
    
    // Вместо std::make_unique используем обычный new
    wchar_t* result = new wchar_t[bufSz];
    std::memset(result, 0, bufSz * sizeof(wchar_t));

    ec = ::RegQueryValueExW( hKey,
                             Name,
                             nullptr,
                             nullptr,
                             reinterpret_cast< LPBYTE >(result),
                             &bufSz );

    if( ec != ERROR_SUCCESS )
    {
        //throw Exception { "Cannot read Registry" };
        delete[] result;
        //throw 
        printf("Cannot read Registry: %d\n", ec);
        return false;
    }

    const auto lastChar = oldBufSz / sizeof( wchar_t ) - 1;
    if( result[ lastChar ] == L'\0' )
    {
        std::wcscpy( &result[lastChar], libName );
    }
    else
    {
        // The value returned is NOT guaranteed to be null-terminated
        std::wcscpy( &result[ lastChar + 1 ], libName );
    }

    // Load the PasspR40.dll and load its functions
    const auto& libPath = result;
    wprintf(L"Library path: %ls\n", result);
    //m_hLib = ::LoadLibrary( libPath );
    hDLL = ::LoadLibraryW(libPath);
    //hDLL = ::LoadLibraryA("PasspR40.dll");
    
    // Освобождаем память после использования
    delete[] result;
    
    if( !hDLL )
    {
        //throw Exception { msg };
        printf("Cannot load library\n");
        return false;
    }
    printf("library was loaded\n");
    // конец кода из unit1.cpp 

    // Получаем указатели на функции
    pfnInitializeFunc = (_InitializeFunc)GetProcAddress(hDLL, "_Initialize");
    pfnSetCallbackFuncFunc = (_SetCallbackFuncFunc)GetProcAddress(hDLL, "_SetCallbackFunc");
    pfnExecuteCommandFunc = (_ExecuteCommandFunc)GetProcAddress(hDLL, "_ExecuteCommand");
    pfnLibraryVersionFunc = (_LibraryVersionFunc)GetProcAddress(hDLL, "_LibraryVersion");

    // Проверяем, что все функции найдены
    if (pfnInitializeFunc == NULL || pfnSetCallbackFuncFunc == NULL ||
        pfnExecuteCommandFunc == NULL || pfnLibraryVersionFunc == NULL) {
        FreeLibrary(hDLL);
        hDLL = NULL;
        return false;
    }

    return true;
}

// Экспортируемые функции-обертки для вызова функций из закрытой библиотеки

/*// Обертка для функции инициализации - не используется в Go
long REGULA_STDCALL Initialize(void *lpParams, HWND hParent)
{
    // Здесь происходит вызов соответствующей функции из закрытой библиотеки
    // Вся логика уже реализована в библиотеке
    return RPRM_Error_NoError;
}*/

// Функция-мост для инициализации
long Regula_Initialize(void *lpParams, void *hParent) {
    if (!LoadRegulaLibrary()) {
        return RPRM_Error_DeviceError;
    }
    
    // Вызываем функцию Initialize из библиотеки
    return pfnInitializeFunc(lpParams, (HWND)hParent);
}

// Функция-мост для установки колбэков
void Regula_SetCallbackFunc(void *f1, void *f2) {
    if (!LoadRegulaLibrary()) {
        return;
    }
    
    // Сохраняем указатели на колбэки
    g_ResultReceivingFunc = (ResultReceivingFunc)f1;
    g_NotifyFunc = (NotifyFunc)f2;
    
    // Вызываем функцию SetCallbackFunc из библиотеки
    pfnSetCallbackFuncFunc(g_ResultReceivingFunc, g_NotifyFunc);
}

// Функция-мост для выполнения команд
long Regula_ExecuteCommand(long command, void *params, void *result) {
    if (!LoadRegulaLibrary()) {
        return RPRM_Error_DeviceError;
    }
    
    // Вызываем функцию ExecuteCommand из библиотеки
    return pfnExecuteCommandFunc(command, params, result);
}

// Функция-мост для получения версии библиотеки
uint32_t Regula_LibraryVersion() {
    if (!LoadRegulaLibrary()) {
        return 0;
    }  

    // Вызываем функцию LibraryVersion из библиотеки
    return pfnLibraryVersionFunc();
}
