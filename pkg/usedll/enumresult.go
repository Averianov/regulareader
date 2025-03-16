package usedll

import "fmt"

type RPRM_ResultType int32

// ****************************************************************************
// ** result types
// ****************************************************************************
// eRPRM_ResultType
const (
	RPRM_ResultType_Empty                       RPRM_ResultType = 0
	RPRM_ResultType_RawImage                    RPRM_ResultType = 1  // TRawImageContainer
	RPRM_ResultType_FileImage                   RPRM_ResultType = 2  // byte array
	RPRM_ResultType_MRZ_OCR_Extended            RPRM_ResultType = 3  // TDocVisualExtendedInfo
	RPRM_ResultType_BarCodes                    RPRM_ResultType = 5  // TDocBarCodeInfo
	RPRM_ResultType_Graphics                    RPRM_ResultType = 6  // TDocGraphicsInfo
	RPRM_ResultType_MRZ_TestQuality             RPRM_ResultType = 7  // TDocMRZTestQuality
	RPRM_ResultType_DocumentTypesCandidates     RPRM_ResultType = 8  // TCandidatesListContainer
	RPRM_ResultType_ChosenDocumentTypeCandidate RPRM_ResultType = 9  // TOneCandidate
	RPRM_ResultType_DocumentsInfoList           RPRM_ResultType = 10 // not used. TListDocsInfo
	RPRM_ResultType_OCRLexicalAnalyze           RPRM_ResultType = 15 // TListVerifiedFields
	RPRM_ResultType_RawUncroppedImage           RPRM_ResultType = 16 // TRawImageContainer
	RPRM_ResultType_Visual_OCR_Extended         RPRM_ResultType = 17 // TDocVisualExtendedInfo
	RPRM_ResultType_BarCodes_TextData           RPRM_ResultType = 18 // TDocVisualExtendedInfo
	RPRM_ResultType_BarCodes_ImageData          RPRM_ResultType = 19 // TDocGraphicsInfo
	RPRM_ResultType_Authenticity                RPRM_ResultType = 20 // TAuthenticityCheckList

	//-------------------- unused  ---------------
	RPRM_ResultType_ExpertAnalyze       RPRM_ResultType = 21 // not used
	RPRM_ResultType_OCRLexicalAnalyzeEx RPRM_ResultType = 22 // not used
	//-------------------- unused  ---------------

	RPRM_ResultType_EOSImage                RPRM_ResultType = 23 // TRawImageContainer for EOS full-size images
	RPRM_ResultType_Bayer                   RPRM_ResultType = 24 // TRawImageContainer
	RPRM_ResultType_MagneticStripe          RPRM_ResultType = 25 // byte array
	RPRM_ResultType_MagneticStripe_TextData RPRM_ResultType = 26 // TDocVisualExtendedInfo
	RPRM_ResultType_FieldFileImage          RPRM_ResultType = 27 // byte array
	RPRM_ResultType_DatabaseCheck           RPRM_ResultType = 28 // TDatabaseCheck
	RPRM_ResultType_FingerprintTemplateISO  RPRM_ResultType = 29 // byte array

	RPRM_ResultType_InputImageQuality        RPRM_ResultType = 30 // TImageQualityCheckList
	RPRM_ResultType_DeviceInfo               RPRM_ResultType = 31 // TRegulaDeviceProperties
	RPRM_ResultType_LivePortrait             RPRM_ResultType = 32 // TDocGraphicsInfo
	RPRM_ResultType_Status                   RPRM_ResultType = 33 // TStatus
	RPRM_ResultType_Portrait_Comparison      RPRM_ResultType = 34 // TAuthenticityCheckList
	RPRM_ResultType_ExtPortrait              RPRM_ResultType = 35 // TDocGraphicsInfo
	RPRM_ResultType_Text                     RPRM_ResultType = 36 // TTextResult
	RPRM_ResultType_Images                   RPRM_ResultType = 37 // TImagesResult
	RPRM_ResultType_FingerPrints             RPRM_ResultType = 38 // TDocGraphicsInfo
	RPRM_ResultType_FingerPrint_Comparison   RPRM_ResultType = 39 // TAuthenticityCheckList
	RPRM_ResultType_FaceDatabaseCheck        RPRM_ResultType = 40 // TDatabaseCheck
	RPRM_ResultType_FingerprintDatabaseCheck RPRM_ResultType = 41 // TDatabaseCheck
	RPRM_ResultType_BarcodePosition          RPRM_ResultType = 62 // TBoundsResult;
	RPRM_ResultType_BSI_XML_v2               RPRM_ResultType = 73 // BSI XML v2 result. buffer = char* - pointer to BSI XML v2
	RPRM_ResultType_DocumentPosition         RPRM_ResultType = 85 // TBoundsResult
	RPRM_ResultType_BSI_XML                  RPRM_ResultType = 92 // BSI XML result. buffer = char* - pointer to BSI XML
	RPRM_ResultType_Custom                   RPRM_ResultType = 100
)

func (e RPRM_ResultType) String() string {
	switch e {
	case RPRM_ResultType_Empty:
		return "Empty"
	case RPRM_ResultType_RawImage:
		return "RawImage"
	case RPRM_ResultType_FileImage:
		return "FileImage"
	case RPRM_ResultType_MRZ_OCR_Extended:
		return "MRZ_OCR_Extended"
	case RPRM_ResultType_BarCodes:
		return "BarCodes"
	case RPRM_ResultType_Graphics:
		return "Graphics"
	case RPRM_ResultType_MRZ_TestQuality:
		return "MRZ_TestQuality"
	case RPRM_ResultType_DocumentTypesCandidates:
		return "DocumentTypesCandidates"
	case RPRM_ResultType_ChosenDocumentTypeCandidate:
		return "ChosenDocumentTypeCandidate"
	case RPRM_ResultType_DocumentsInfoList:
		return "DocumentsInfoList"
	case RPRM_ResultType_OCRLexicalAnalyze:
		return "OCRLexicalAnalyze"
	case RPRM_ResultType_RawUncroppedImage:
		return "RawUncroppedImage"
	case RPRM_ResultType_Visual_OCR_Extended:
		return "Visual_OCR_Extended"
	case RPRM_ResultType_BarCodes_TextData:
		return "BarCodes_TextData"
	case RPRM_ResultType_BarCodes_ImageData:
		return "BarCodes_ImageData"
	case RPRM_ResultType_Authenticity:
		return "Authenticity"
	case RPRM_ResultType_ExpertAnalyze:
		return "ExpertAnalyze"
	case RPRM_ResultType_OCRLexicalAnalyzeEx:
		return "OCRLexicalAnalyzeEx"
	case RPRM_ResultType_EOSImage:
		return "EOSImage"
	case RPRM_ResultType_Bayer:
		return "Bayer"
	case RPRM_ResultType_MagneticStripe:
		return "MagneticStripe"
	case RPRM_ResultType_MagneticStripe_TextData:
		return "MagneticStripe_TextData"
	case RPRM_ResultType_FieldFileImage:
		return "FieldFileImage"
	case RPRM_ResultType_DatabaseCheck:
		return "DatabaseCheck"
	case RPRM_ResultType_FingerprintTemplateISO:
		return "FingerprintTemplateISO"
	case RPRM_ResultType_InputImageQuality:
		return "InputImageQuality"
	case RPRM_ResultType_DeviceInfo:
		return "DeviceInfo"
	case RPRM_ResultType_LivePortrait:
		return "LivePortrait"
	case RPRM_ResultType_Status:
		return "Status"
	case RPRM_ResultType_Portrait_Comparison:
		return "Portrait_Comparison"
	case RPRM_ResultType_ExtPortrait:
		return "ExtPortrait"
	case RPRM_ResultType_Text:
		return "Text"
	case RPRM_ResultType_Images:
		return "Images"
	case RPRM_ResultType_FingerPrints:
		return "FingerPrints"
	case RPRM_ResultType_FingerPrint_Comparison:
		return "FingerPrint_Comparison"
	case RPRM_ResultType_FaceDatabaseCheck:
		return "FaceDatabaseCheck"
	case RPRM_ResultType_FingerprintDatabaseCheck:
		return "FingerprintDatabaseCheck"
	case RPRM_ResultType_BarcodePosition:
		return "BarcodePosition"
	case RPRM_ResultType_BSI_XML_v2:
		return "BSI_XML_v2"
	case RPRM_ResultType_DocumentPosition:
		return "DocumentPosition"
	case RPRM_ResultType_BSI_XML:
		return "BSI_XML"
	case RPRM_ResultType_Custom:
		return "Custom"
	default:
		return fmt.Sprintf("Unknown result type(%d)", e)
	}
}
