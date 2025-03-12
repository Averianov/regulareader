//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

#include "PasspR.h"
#include "cspin.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>

#include <vector>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:    // IDE-managed Components
    TButton *LoadLibraryButton;
    TButton *IntializeButton;
    TLabel *Label1;
    TLabel *LibraryVersionLabel;
    TButton *FreeLibraryButton;
    TBevel *Bevel5;
    TPanel *FDSPanel;
    TBevel *Bevel1;
    TMemo *Memo1;
    TSpeedButton *ConnectDeviceButton;
    TShape *Shape1;
    TButton *ProcessButton;
    TBevel *Bevel2;
    TBevel *Bevel3;
    TTabControl *ImagesTabControl;
    TPaintBox *PaintBox;
    TCheckBox *SaveImagesCheckBox;
    TCheckBox *LocateCheckBox;
    TCheckBox *XMLCheckBox;
    TCheckBox *ClipboardCheckBox;
    TCheckBox *FileCheckBox;
    TCheckBox *MRZCheckBox;
    TCheckBox *MRZTestQualityCheckBox;
    TCheckBox *ScanImagesCheckBox;
    TCheckBox *BarCodesCheckBox;
    TCheckBox *DocTypeCheckBox;
    TCheckBox *VisualOCRCheckBox;
    TCheckBox *AuthenticityCheckBox;
    TButton *OCRLexAnalisysButton;
    TProgressBar *ProgressBar;
    TCheckBox *AllImagesCheckBox;
    TSpeedButton *SB_1mp;
    TSpeedButton *SB_3mp;
    TCheckListBox *LightCheckListBox;
    TCSpinEdit *UVExpSpinEdit;
    TSpeedButton *SB_VideoDetection;
    TSpeedButton *SB_5mp;
    TSpeedButton *SB_92mp;
    TSpeedButton *SB_9mp;
    TLabel *UVExpLabel;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall LoadLibraryButtonClick(TObject *Sender);
    void __fastcall IntializeButtonClick(TObject *Sender);
    void __fastcall FreeLibraryButtonClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall ConnectDeviceButtonClick(TObject *Sender);
    void __fastcall ProcessButtonClick(TObject *Sender);
    void __fastcall PaintBoxPaint(TObject *Sender);
    void __fastcall ImagesTabControlChange(TObject *Sender);
    void __fastcall CheckBoxClick(TObject *Sender);
    void __fastcall OCRLexAnalisysButtonClick(TObject *Sender);
    void __fastcall SB_1mpClick(TObject *Sender);
    void __fastcall SB_3mpClick(TObject *Sender);
    void __fastcall SB_5mpClick(TObject *Sender);
    void __fastcall SB_92mpClick(TObject *Sender);
    void __fastcall SB_9mpClick(TObject *Sender);
    void __fastcall UVExpSpinEditChange(TObject *Sender);

private:
    // Library handle
    HMODULE m_hLib;

    // Document reader properties
    TRegulaDeviceProperties m_activeDevice;

    // Functional capabilities
    DWORD m_SDKCapabilities;

    // Indicates whether the device is connected
    bool m_deviceConnected;

    // Current video mode
    eRPRM_VideoModes m_currentVideoMode;

    // The last timestamp for measuring time between two
    // consecutive log messages
    LARGE_INTEGER m_liStartTime;

    // Received scanned images
    std::vector< TRawImageContainer* > m_imagesTabs;

    // Available light schemes
    std::vector< DWORD > m_availableLight;

    // Imported library functions
    _InitializeFunc Initialize;
    _FreeFunc Free;
    _SetCallbackFuncFunc SetCallbackFunc;
    _ExecuteCommandFunc ExecuteCommand;
    _CheckResultFunc CheckResult;
    _CheckResultFromListFunc CheckResultFromList;
    _ResultTypeAvailableFunc ResultTypeAvailable;
    _AllocRawImageContainerFunc AllocRawImageContainer;
    _FreeRawImageContainerFunc FreeRawImageContainer;

public:    // User declarations
    __fastcall TForm1( TComponent* Owner );

protected:
    // Updates buttons, checkboxes etc. depending on the form state
    // e.g. connected/disconnected
    void __fastcall UpdateControls();

    // Sets the document presence color. The box color indicates whether a
    // document is in the tray or not
    void __fastcall PaintDocPresenceBox( const TColor color );

    // Log messages on the form
    void LogMessage( const wchar_t *fmt, ... ) const;
    void LogMessage( const UnicodeString& msg ) const;
    void __fastcall LogErrorCode( const eDeviceLimitations msg );

    // Result receiving callback set before the initialization
    static
    void __stdcall MyResultReceivingFunc( TResultContainer *result,
                                          uint32_t *PostAction,
                                          uint32_t *PostActionParameter );

    // Notification callback set before the initialization
    static
    void __stdcall MyNotifyFunc( intptr_t rawCode, intptr_t value );

    // Result receiving callback helpers
    void __fastcall ReceiveVisualExtOCR( const TResultContainer *result );
    void __fastcall ReceiveRawImage( const TResultContainer *result );
    void __fastcall ReceiveFileImage( const TResultContainer *result );
    void __fastcall Receive_OCR_Graphics( const TResultContainer *result );
    void __fastcall ReceiveMRZTestQuality( const TResultContainer *result );
    void __fastcall ReceiveBarcode( const TResultContainer *result );
    void __fastcall ReceiveDocTypes( const TResultContainer *result,
                                     uint32_t *PostAction,
                                     uint32_t *PostActionParameter );
    void __fastcall
    ReceiveDocTypeCandidate( const TResultContainer *result );

    void __fastcall ReceiveOCRLexAnalisys( const TResultContainer *result );
    void __fastcall ReceiveAuthenticity( const TResultContainer *result );

    // Notification receiving callback helpers
    void __fastcall NotifyDocumentReady( const bool isPlaced );
    void __fastcall NotifyScanning( const bool isScanningCompleted );
    void __fastcall NotifyDevEnumeration( const bool isEnumCompleted );
    void __fastcall NotifyDevConnected( const bool isConnected );
    void __fastcall NotifyDocCanBeRemoved();
    void __fastcall NotifyLidOpen( const bool isOpen );
    void __fastcall NotifyProcessingDone( const bool isDone );
    void __fastcall NotifyCalibInfoDownload( const int percent );
    void __fastcall NotifyLicenseExpired( const int daysSince1900 );
    void __fastcall NotifyProgress( const int percent );
    void __fastcall NotifySDKAvailable( const uint32_t version );
    void __fastcall NotifyDBAvailable( const uint32_t version );

    void __fastcall
    NotifyVideoFrame( const TVideodetectionNotification* frame );

    void __fastcall
    NotifyCompatibilityMode( const eDeviceLimitations mode );

    // Executes the command
    template< eRPRM_Commands command >
    eRPRM_ErrorCodes Call( void *params = nullptr,
                           void *result = nullptr ) const
    {
        return
            static_cast< eRPRM_ErrorCodes >(
                ExecuteCommand( command,
                                params,
                                result ) );

    }

    // Executes the command
    template< eRPRM_Commands command >
    eRPRM_ErrorCodes Call( long params, void* result = nullptr ) const
    {
        return
            static_cast< eRPRM_ErrorCodes >(
                ExecuteCommand( command,
                                reinterpret_cast< void* >( params ),
                                result ) );
    }

    // Executes the command
    template< eRPRM_Commands command >
    eRPRM_ErrorCodes Get( void* result = nullptr ) const
    {
        return
            static_cast< eRPRM_ErrorCodes >(
                ExecuteCommand( command,
                                nullptr,
                                result ) );
    }

    // A wrapper function for the _CheckResult
    template< int type, class PathFunc >
    void GetResult( const long mode, PathFunc&& getPathFor )
    {
        GetResult< type >( mode, getPathFor, []( auto ){} );
    }

    // A wrapper function for the _CheckResult
    template< const int type, class PathFunc, class ResultFunc >
    void GetResult( const long mode,
                    PathFunc&& getPathFor,
                    ResultFunc&& passResult )
    {
        const auto total = ResultTypeAvailable( type );
        LogMessage( L"%d results available of type %d "
                    L"to be read by CheckResult",
                    total,
                    type );

        for( int idx {}; idx < total; ++idx )
        {
            const UTF8String file = getPathFor( idx );

            ::DeleteFileA( file.c_str() );

            const auto hRes = CheckResult( type,
                                           idx,
                                           mode,
                                           file.c_str() );

            const auto ret = reinterpret_cast< intptr_t >( hRes );
            if( ret <= 0 )
            {
                LogMessage( L"CheckResult for idx %d returned: 0x%08X",
                            idx,
                            ret );
                continue;
            }

            // Check the file was actually saved
            const auto attr = ::GetFileAttributesA( file.c_str() );
            if( ( attr != INVALID_FILE_ATTRIBUTES ) &&
                !( attr & FILE_ATTRIBUTE_DIRECTORY ) )
            {
                LogMessage( file + " - saved." );
            }

            // Call the postprocessing if any
            passResult( hRes );
        }
    }

    // Loads PasspR function by procName
    template< typename T >
    void LoadFun( T& f, LPCSTR procName )
    {
        auto proc = ::GetProcAddress( m_hLib, procName );
        if( ! proc )
        {
            System::UnicodeString msg
            {
                "Cannot import "
            };
            msg += procName;
            throw Exception { msg };

        }
        f = reinterpret_cast< T >( proc );
    }

    // Frees previously allocated TRawImageContainer* memory
    // and clears the images container
    template< class T >
    void CleanupImageContainer( T& images )
    {
        for( auto i : images )
        {
            FreeRawImageContainer( i );
        }
        images.clear();
    }

    // Connect reader
    void __fastcall Connect();

    // Disconnect reader
    void __fastcall Disconnect();

    //Switch between different digital camera sensor modes
    void __fastcall SetWorkingVideoMode( const eRPRM_VideoModes mode );

    // Returns a path for scanning result files
    UnicodeString __fastcall GetTestDataPath() const;

    uint32_t __fastcall GetProcessingMode() const;
    void __fastcall RefreshSDKCapabilities();
    long __fastcall GetDirectQueryMode() const;
    void __fastcall DoDirectQuery( const long mode );

    TRawImageContainer*
    __fastcall GetImage( const TRawImageContainer* im_res );

    void __fastcall SetUVExposure( long value );
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
