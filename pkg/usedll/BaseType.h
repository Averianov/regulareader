#ifndef BASETYPE_H
#define BASETYPE_H

//***********************************************************************************************//

// Check windows platform
#if defined(_WIN32) || defined(_WIN64) || defined(__CYGWIN__)
    #define REGULA_PLATFORM_WIN
#endif

// Check linux platform
#if defined(__linux__) || defined(linux) || defined(__linux)
    #define REGULA_PLATFORM_LINUX
#endif


// Check Apple platforms
#if defined(__APPLE__)
    #include "TargetConditionals.h"
    #if TARGET_OS_OSX // Check OSX platform
        #define REGULA_PLATFORM_OSX
    #elif TARGET_OS_IPHONE || TARGET_OS_SIMULATOR // Check iOS platform
        #define REGULA_PLATFORM_IOS 
    #endif
#endif

// Check Android platform
#if defined(ANDROID) || defined(__ANDROID__)
    #define REGULA_PLATFORM_ANDROID
#endif

// Overall mobile platform (iOS or Android)
#if defined(REGULA_PLATFORM_IOS) || defined(REGULA_PLATFORM_ANDROID)
    #define REGULA_PLATFORM_MOBILE_OS
    #define MOBILE_OS
#endif

// Overall server platform
#if (defined(REGULA_PLATFORM_WIN) || defined(REGULA_PLATFORM_LINUX)) && !defined(REGULA_PLATFORM_MOBILE_OS)
    #define REGULA_PLATFORM_SERVER_OS
    #define SERVER_OS
#endif

// Check WebAssembly platform
#if defined(__EMSCRIPTEN__)
    #define REGULA_PLATFORM_WASM
#endif

#if defined(REGULA_PLATFORM_OSX)
    #define WINTYPES
#endif

#ifdef WINTYPES
    #include <PCSC/wintypes.h>
    // this will define __wintypes_h__
#endif

#include <stdint.h>
#include <time.h>

#ifdef _WIN32
#ifndef NOMINMAX
    #define NOMINMAX
#endif

#include <windows.h>

#if defined(__BORLANDC__) && !defined(__clang__)
    #define nullptr NULL; //-V1059
#endif

#else // !_WIN32

#if (TARGET_OS_IPHONE || TARGET_OS_SIMULATOR)
#include <opencv2/opencv.hpp>
#include <objc/objc.h>
#else
#ifndef __wintypes_h__
typedef int         BOOL;
#endif
#endif

#include <stddef.h>
#include <string.h>

#if !defined(_DEBUG) && !defined(NDEBUG)
    #define _DEBUG
#endif

#define IN
#define OUT

#define far
#define near

#ifndef FAR
#define FAR                 far
#endif

#define NEAR                near
#define CONST               const

#define INVALID_HANDLE_VALUE ((intptr_t)-1)
#define MAX_COMPUTERNAME_LENGTH 15

#define NO_ERROR 0L
#define ERROR_INVALID_FUNCTION 1L
typedef long HRESULT;       //-V126
#define S_OK ((HRESULT)0L)
#define S_FALSE ((HRESULT)1L)

typedef unsigned int uint;
typedef unsigned char byte;
#ifndef __wintypes_h__
typedef uint32_t DWORD;
typedef int32_t LONG;
#endif
typedef void VOID;
typedef char CHAR;
typedef short SHORT;
typedef int INT;
typedef CHAR* NPSTR, * LPSTR, * PSTR;
typedef LPSTR LPTSTR;
typedef unsigned char       BYTE;
typedef uint16_t            WORD;
typedef float               FLOAT;
typedef FLOAT* PFLOAT;
typedef BOOL near* PBOOL;
typedef BOOL far* LPBOOL;
typedef BYTE near* PBYTE;
typedef BYTE far* LPBYTE;
typedef int near* PINT;
typedef int far* LPINT;
typedef WORD near* PWORD;
typedef WORD far* LPWORD;
typedef long far* LPLONG;
typedef DWORD near* PDWORD;
typedef DWORD far* LPDWORD;
typedef void* PVOID;
typedef void far* LPVOID;
typedef CONST void far* LPCVOID;
typedef wchar_t WCHAR;
typedef WCHAR* PWCHAR;

typedef unsigned int        UINT;
typedef unsigned int* PUINT;

typedef uint16_t      UINT16, * PUINT16;

typedef unsigned char UCHAR;
typedef DWORD ULONG;


typedef double DOUBLE;

#if defined __linux__ || defined __APPLE__ || defined __EMSCRIPTEN__
// comes from WinCrypt.h
typedef struct _CRYPT_BIT_BLOB {
    DWORD   cbData;
    byte* pbData;
    DWORD   cUnusedBits;
} CRYPT_BIT_BLOB, * PCRYPT_BIT_BLOB;

typedef struct _CRYPTOAPI_BLOB {
    DWORD   cbData;
    byte* pbData;
} CRYPT_INTEGER_BLOB, * PCRYPT_INTEGER_BLOB,
CRYPT_UINT_BLOB, * PCRYPT_UINT_BLOB,
CRYPT_OBJID_BLOB, * PCRYPT_OBJID_BLOB,
CERT_NAME_BLOB, * PCERT_NAME_BLOB,
CERT_RDN_VALUE_BLOB, * PCERT_RDN_VALUE_BLOB,
CERT_BLOB, * PCERT_BLOB,
CRL_BLOB, * PCRL_BLOB,
DATA_BLOB, * PDATA_BLOB,
CRYPT_DATA_BLOB, * PCRYPT_DATA_BLOB,
CRYPT_HASH_BLOB, * PCRYPT_HASH_BLOB,
CRYPT_DIGEST_BLOB, * PCRYPT_DIGEST_BLOB,
CRYPT_DER_BLOB, * PCRYPT_DER_BLOB,
CRYPT_ATTR_BLOB, * PCRYPT_ATTR_BLOB;

typedef struct _CRYPT_ALGORITHM_IDENTIFIER {
    LPSTR               pszObjId;
    CRYPT_OBJID_BLOB    Parameters;
} CRYPT_ALGORITHM_IDENTIFIER, * PCRYPT_ALGORITHM_IDENTIFIER;

typedef struct _CERT_PUBLIC_KEY_INFO {
    CRYPT_ALGORITHM_IDENTIFIER    Algorithm;
    CRYPT_BIT_BLOB                PublicKey;
} CERT_PUBLIC_KEY_INFO, * PCERT_PUBLIC_KEY_INFO;
#define FILE_DEVICE_SMARTCARD           0x00000031
#define METHOD_BUFFERED                 0
#define FILE_ANY_ACCESS                 0
#define CTL_CODE( DeviceType, Function, Method, Access ) (                 \
    ((DeviceType) << 16) | ((Access) << 14) | ((Function) << 2) | (Method) \
)
#endif

#ifndef __APPLE__
typedef uint32_t errno_t;
#endif

#define ZeroMemory(Destination,Length) memset((Destination),0,(Length))

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

#define UINT        uint
#define CString     QString
#define CopyMemory    memcpy

#define MAX_PATH          260

//typedef    bool                BOOL;
//typedef unsigned long       uint32_t;
//typedef float               FLOAT;
//typedef unsigned int        UINT;
typedef uint64_t            UINT64, * PUINT64;
typedef int64_t             __int64;
typedef uint64_t ULONGLONG;
typedef ULONGLONG  DWORDLONG;
//typedef unsigned char       BYTE;
//typedef char                CHAR;
//typedef long                int32_t;
//typedef unsigned short      WORD;
//typedef void*                LPVOID;
//typedef void*                HINSTANCE;
typedef void* HMODULE;
typedef void* HANDLE;
#define SUCCEEDED(hr) (((HRESULT)(hr)) >= 0)
#define FAILED(hr) (((HRESULT)(hr)) < 0)
#define ERROR_BAD_COMMAND                22L

#define _HRESULT_TYPEDEF_(_sc) ((HRESULT)_sc)
#define E_FAIL          _HRESULT_TYPEDEF_(0x80004005L)
#define E_INVALIDARG    _HRESULT_TYPEDEF_(0x80070057L)

typedef struct _GUID {
    uint32_t Data1;
    uint16_t Data2;
    uint16_t Data3;
    uint8_t  Data4[8];
} GUID;

#ifndef DEFINE_GUID
#define DEFINE_GUID(guidName, Data1, Data2, Data3, Data4_0, Data4_1, Data4_2, Data4_3, Data4_4, Data4_5, Data4_6, Data4_7) \
    const GUID guidName = { Data1, Data2, Data3, Data4_0, Data4_1, Data4_2, Data4_3, Data4_4, Data4_5, Data4_6, Data4_7 }
#endif

typedef struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, * PSYSTEMTIME, * LPSYSTEMTIME;

typedef struct tagSIZE
{
    int32_t cx;
    int32_t cy;
} SIZE, * PSIZE, * LPSIZE;

typedef struct _POINTFLOAT {
    FLOAT   x;
    FLOAT   y;
} POINTFLOAT, * PPOINTFLOAT;

typedef HANDLE* PHANDLE;
#define DECLARE_HANDLE(name) struct name##__{int unused;}; typedef struct name##__ *name
DECLARE_HANDLE(HWND);

#ifdef MOBILE_OS
typedef uintptr_t SCARDCONTEXT;
typedef uintptr_t SCARDHANDLE;
#define SCARD_S_SUCCESS NO_ERROR
#endif



#define CALLBACK    REGULA_STDCALL
#define WINAPI      REGULA_STDCALL
#define WINAPIV     REGULA_CDECL
#define APIENTRY    WINAPI
#define APIPRIVATE  REGULA_STDCALL
#define PASCAL      REGULA_STDCALL

typedef CHAR* PCHAR, * LPCH, * PCH;
typedef CONST CHAR* LPCSTR, * PCSTR;
#if (!defined __APPLE__)
typedef CONST WCHAR* LPCWSTR, * PCWSTR;
#endif
typedef WCHAR TCHAR;

typedef struct tagRECT
{
    int32_t    left;
    int32_t    top;
    int32_t    right;
    int32_t    bottom;
} RECT;

typedef struct tagPOINT
{
    int32_t  x;
    int32_t  y;
} POINT, * PPOINT, NEAR* NPPOINT, FAR* LPPOINT;

typedef struct tagPOINTF
{
    FLOAT x;
    FLOAT y;
}     POINTF;

typedef int64_t LONGLONG;

typedef union _LARGE_INTEGER {
    struct {
        uint32_t LowPart;
        int32_t HighPart;
    } DUMMYSTRUCTNAME;
    struct {
        uint32_t LowPart;
        int32_t HighPart;
    } u;
    LONGLONG QuadPart;
} LARGE_INTEGER;

#define BI_RGB        0L
#define BI_RLE8       1L
#define BI_RLE4       2L
#define BI_BITFIELDS  3L
#define BI_JPEG       4L
#define BI_PNG        5L

#pragma pack(push, 2)

typedef struct tagBITMAPINFOHEADER {
    uint32_t      biSize;
    int32_t    biWidth;
    int32_t    biHeight;
    WORD       biPlanes;
    WORD       biBitCount;
    uint32_t      biCompression;
    uint32_t      biSizeImage;
    int32_t    biXPelsPerMeter;
    int32_t    biYPelsPerMeter;
    uint32_t      biClrUsed;
    uint32_t      biClrImportant;
} BITMAPINFOHEADER, FAR* LPBITMAPINFOHEADER, * PBITMAPINFOHEADER;

typedef struct tagRGBQUAD {
    BYTE    rgbBlue;
    BYTE    rgbGreen;
    BYTE    rgbRed;
    BYTE    rgbReserved;
} RGBQUAD;
typedef RGBQUAD FAR* LPRGBQUAD;

typedef struct tagRGBTRIPLE {
    BYTE    rgbtBlue;
    BYTE    rgbtGreen;
    BYTE    rgbtRed;
} RGBTRIPLE, * PRGBTRIPLE, NEAR* NPRGBTRIPLE, FAR* LPRGBTRIPLE;

typedef struct tagBITMAPINFO {
    BITMAPINFOHEADER    bmiHeader;
    RGBQUAD             bmiColors[1];
} BITMAPINFO, FAR* LPBITMAPINFO, * PBITMAPINFO;

typedef struct tagBITMAPFILEHEADER {
    WORD    bfType;
    uint32_t   bfSize;
    WORD    bfReserved1;
    WORD    bfReserved2;
    uint32_t   bfOffBits;
} BITMAPFILEHEADER, FAR* LPBITMAPFILEHEADER, * PBITMAPFILEHEADER;

#pragma pack(pop)

#define MAKEWORD(a, b) ((WORD)(((BYTE)(((uint32_t)(a)) & 0xff)) | ((WORD)((BYTE)(((uint32_t)(b)) & 0xff))) << 8))
#define MAKELONG(a, b) ((int32_t)(((WORD)(((uint64_t)(a)) & 0xffff)) | ((uint32_t)((WORD)(((uint64_t)(b)) & 0xffff))) << 16))
#define LOWORD(l) ((WORD)(((uint32_t)(l)) & 0xffff))
#define HIWORD(l) ((WORD)((((uint32_t)(l)) >> 16) & 0xffff))
#define LOBYTE(b) ((BYTE)(((uint16_t)(b)) & 0xff))
#define HIBYTE(b) ((BYTE)((((uint16_t)(b)) >> 8) & 0xff))

#define DLL_PROCESS_ATTACH   1    
#define DLL_THREAD_ATTACH    2    
#define DLL_THREAD_DETACH    3    
#define DLL_PROCESS_DETACH   0    
#define DLL_PROCESS_VERIFIER 4    

//-------------------------------------------------------------------------------------------------
typedef intptr_t LONG_PTR;
typedef LONG_PTR LRESULT;
typedef unsigned int UINT_PTR;

typedef UINT_PTR WPARAM;
typedef LONG_PTR LPARAM;

typedef HANDLE HINSTANCE;
typedef PVOID HDEVNOTIFY;

typedef WCHAR OLECHAR;
typedef OLECHAR* BSTR;
typedef BSTR* LPBSTR;
typedef long long INT64;
typedef DWORD COLORREF;
typedef WCHAR* LPWSTR;
typedef HANDLE HKEY;
typedef HANDLE HLOCAL;
typedef ULONG REGSAM;
typedef HKEY* PHKEY;
//-------------------------------------------------------------------------------------------------
typedef struct tagMSG {
    HWND   hwnd;
    UINT   message;
    WPARAM wParam;
    LPARAM lParam;
    DWORD  time;
    POINT  pt;
    DWORD  lPrivate;
} MSG, * PMSG, * NPMSG, * LPMSG;
//-------------------------------------------------------------------------------------------------
typedef struct _DEV_BROADCAST_HANDLE {
    DWORD      dbch_size;
    DWORD      dbch_devicetype;
    DWORD      dbch_reserved;
    HANDLE     dbch_handle;
    HDEVNOTIFY dbch_hdevnotify;
    GUID       dbch_eventguid;
    LONG       dbch_nameoffset;
    BYTE       dbch_data[1];
} DEV_BROADCAST_HANDLE, * PDEV_BROADCAST_HANDLE;
//-------------------------------------------------------------------------------------------------
typedef GUID IID;
const GUID GUID_NULL = { 0, 0, 0, { 0, 0, 0, 0, 0, 0, 0, 0 } };
//-------------------------------------------------------------------------------------------------
typedef struct _DCB {
    DWORD DCBlength;
    DWORD BaudRate;
    DWORD fBinary : 1;
    DWORD fParity : 1;
    DWORD fOutxCtsFlow : 1;
    DWORD fOutxDsrFlow : 1;
    DWORD fDtrControl : 2;
    DWORD fDsrSensitivity : 1;
    DWORD fTXContinueOnXoff : 1;
    DWORD fOutX : 1;
    DWORD fInX : 1;
    DWORD fErrorChar : 1;
    DWORD fNull : 1;
    DWORD fRtsControl : 2;
    DWORD fAbortOnError : 1;
    DWORD fDummy2 : 17;
    WORD  wReserved;
    WORD  XonLim;
    WORD  XoffLim;
    BYTE  ByteSize;
    BYTE  Parity;
    BYTE  StopBits;
    char  XonChar;
    char  XoffChar;
    char  ErrorChar;
    char  EofChar;
    char  EvtChar;
    WORD  wReserved1;
} DCB, * LPDCB;
//-------------------------------------------------------------------------------------------------
typedef uintptr_t ULONG_PTR;
typedef ULONG_PTR SIZE_T;
//-------------------------------------------------------------------------------------------------
#define CBR_9600 9600
#define NOPARITY 0
#define ONESTOPBIT 0
const uint GENERIC_READ = 0x80000000;
const uint GENERIC_WRITE = 0x40000000;
const uint OPEN_EXISTING = 3;
#define CREATE_ALWAYS 2
#define FILE_ATTRIBUTE_NORMAL 128
#define FILE_WRITE_DATA 2
#define CF_TEXT 1
#define CF_DIB 8
#define LMEM_FIXED 0x0000
#define LANG_NEUTRAL 0x0C00
#define SUBLANG_DEFAULT 0x01
#define VER_PLATFORM_WIN32_NT 2
#define WS_OVERLAPPED 0x00000000L
#define CW_USEDEFAULT 0x000000000
typedef HANDLE HGLOBAL;
typedef ULONG_PTR DWORD_PTR;
typedef HANDLE HICON;
typedef HICON HCURSOR;
typedef HANDLE HBRUSH;
typedef WORD ATOM;
typedef HANDLE HMENU;
typedef const IID* REFCLSID;
typedef wchar_t* LPOLESTR;
typedef unsigned short VARTYPE;
typedef short VARIANT_BOOL;
typedef ULONG SCODE;
typedef DWORD LCID;
typedef long long _Longlong;
//-------------------------------------------------------------------------------------------------
#define GMEM_MOVEABLE 0x0002
//-------------------------------------------------------------------------------------------------
typedef struct _SECURITY_ATTRIBUTES {
    DWORD  nLength;
    LPVOID lpSecurityDescriptor;
    BOOL   bInheritHandle;
} SECURITY_ATTRIBUTES, * PSECURITY_ATTRIBUTES, * LPSECURITY_ATTRIBUTES;
//-------------------------------------------------------------------------------------------------
typedef WCHAR* LPWCH;
typedef CONST WCHAR* LPCWCH;
typedef CONST CHAR* LPCCH, * PCCH;
typedef long* LPUNKNOWN;
//-------------------------------------------------------------------------------------------------
#ifdef UNICODE
typedef LPCWSTR LPCTSTR;
#else
typedef LPCSTR LPCTSTR;
#endif
//-------------------------------------------------------------------------------------------------
typedef struct _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME, * PFILETIME, * LPFILETIME;
//-------------------------------------------------------------------------------------------------
typedef struct _WIN32_FIND_DATAW {
    DWORD    dwFileAttributes;
    FILETIME ftCreationTime;
    FILETIME ftLastAccessTime;
    FILETIME ftLastWriteTime;
    DWORD    nFileSizeHigh;
    DWORD    nFileSizeLow;
    DWORD    dwReserved0;
    DWORD    dwReserved1;
    TCHAR    cFileName[MAX_PATH];
    TCHAR    cAlternateFileName[14];
} WIN32_FIND_DATAW, * PWIN32_FIND_DATAW, * LPWIN32_FIND_DATAW;
//-------------------------------------------------------------------------------------------------
#endif // _WIN32

#ifdef __cplusplus
#   define REGULA_EXTERNC extern "C"
#   define REGULA_EXTERNC_BEGIN extern "C" {
#   define REGULA_EXTERNC_END } // extern "C"
#else // !__cplusplus
#   define REGULA_EXTERNC
#   define REGULA_EXTERNC_BEGIN
#   define REGULA_EXTERNC_END
#endif // __cplusplus

#ifdef _WIN32
#   define REGULA_DEFAULT_VISIBILITY
#   define REGULA_CDECL      __cdecl
#   define REGULA_STDCALL    __stdcall
#   define REGULA_FASTCALL   __fastcall
#   define REGULA_DLLEXPORT  __declspec(dllexport)
#   define REGULA_DLLIMPORT  __declspec(dllimport)
#   ifdef REGULA_BUILD_DLL
#       define REGULA_EXPORT REGULA_EXTERNC REGULA_DLLEXPORT
#   else // NOT REGULA_BUILD_DLL
#       define REGULA_EXPORT REGULA_EXTERNC REGULA_DLLIMPORT
#   endif
#else // !_WIN32
#   define REGULA_DEFAULT_VISIBILITY __attribute__ ((visibility("default")))
#   define REGULA_CDECL
#   define REGULA_STDCALL
#   define REGULA_FASTCALL
#   define REGULA_DLLEXPORT REGULA_DEFAULT_VISIBILITY
#   define REGULA_DLLIMPORT
#   define REGULA_EXPORT REGULA_EXTERNC REGULA_DEFAULT_VISIBILITY
#endif // _WIN32

typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

//-------------------------------------------------------------------------------------------------
typedef struct _IppiBorder
{
    int        left;
    int        right;
    int        top;
    int        bottom;
} IppiBorder;
//-------------------------------------------------------------------------------------------------
typedef struct {
    float    width;
    float    height;
} fIppiSize;
//-------------------------------------------------------------------------------------------------
typedef struct {
    float    width;
    float    height;
} IppiSizeF;
//-------------------------------------------------------------------------------------------------
typedef struct tagRECTF
{
    float    left;
    float    top;
    float    right;
    float    bottom;
} RECTF;
//-------------------------------------------------------------------------------------------------
enum eRPRM_LightsSimple
{
    Light_OFF = 0,
    Light_White = 1,
    Light_IR = 2,
    Light_UV = 3,
    Light_AXIAL_White = 4
};
//-------------------------------------------------------------------------------------------------
enum eRPRM_DeviceTypesSimple
{
    DeviceType_Unknown = 0,    // Unknown device
    DTSType_1280x1024x14600 = 1,    //  1.3 small
    DTSType_1280x1024x9900 = 2,    //  1.3 
    DTSType_1280x1024x9900M = 3,    //  1.3 mobile
    DTSType_2048x1536x15750 = 4,    //  3.0
    DTSType_2048x1536x15750M = 5,    //  3.0 mobile
    DTSType_1600x1200x12300M = 6     //  3.0 mobile
};

// workaround for windows compilers
#define EXPAND( x ) x

// Define two genetic macros
#define SECOND_ARG(A,B,...) B
#define CONCAT2(A,B) A ## B

// If a macro is detected, add an arg, so the second one will be 1.
#define DETECT_EXIST_TRUE ~,true

// DETECT_EXIST merely concats a converted macro to the end of DETECT_EXIST_TRUE.
// If empty, DETECT_EXIST_TRUE converts fine.  If not 0 remains second argument.
#define EXISTS(X) DETECT_EXIST_IMPL(CONCAT2(DETECT_EXIST_TRUE,X), false, ~)
#define DETECT_EXIST_IMPL(...) EXPAND(SECOND_ARG(__VA_ARGS__))

#endif // BASETYPE_H
