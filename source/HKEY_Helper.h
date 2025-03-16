#pragma once

#include <windows.h>
#include <string>
#include <stdexcept>

#ifndef NULL
#define NULL 0
#endif

/// <summary>
/// RegKey RAII wrapper
/// </summary>
class HKEY_Helper
{
public:
    HKEY_Helper( const wchar_t* subKey, const REGSAM desiredAccess = KEY_READ ) :
        mKey { NULL }
    {
        auto ec = ::RegOpenKeyExW( HKEY_LOCAL_MACHINE,
                                   subKey,
                                   0,
                                   desiredAccess,
                                   &mKey );
        if( ERROR_SUCCESS != ec )
        {
            std::wstring msg = L"Cannot open ";
            msg += subKey;
            throw std::runtime_error("Cannot open registry key");
        }
    }
    
    ~HKEY_Helper() { if( mKey ) ::RegCloseKey( mKey ); }
    operator HKEY() const { return mKey; }
    
//private:
    HKEY mKey;
};