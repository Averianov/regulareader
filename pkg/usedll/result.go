package usedll

//****************************************************************************
//** result types
//****************************************************************************
// eRPRM_ResultType
var (
	RPRM_ResultType_Empty                       = 0
	RPRM_ResultType_RawImage                    = 1  // TRawImageContainer
	RPRM_ResultType_FileImage                   = 2  // byte array
	RPRM_ResultType_MRZ_OCR_Extended            = 3  // TDocVisualExtendedInfo
	RPRM_ResultType_BarCodes                    = 5  // TDocBarCodeInfo
	RPRM_ResultType_Graphics                    = 6  // TDocGraphicsInfo
	RPRM_ResultType_MRZ_TestQuality             = 7  // TDocMRZTestQuality
	RPRM_ResultType_DocumentTypesCandidates     = 8  // TCandidatesListContainer
	RPRM_ResultType_ChosenDocumentTypeCandidate = 9  // TOneCandidate
	RPRM_ResultType_DocumentsInfoList           = 10 // not used. TListDocsInfo
	RPRM_ResultType_OCRLexicalAnalyze           = 15 // TListVerifiedFields
	RPRM_ResultType_RawUncroppedImage           = 16 // TRawImageContainer
	RPRM_ResultType_Visual_OCR_Extended         = 17 // TDocVisualExtendedInfo
	RPRM_ResultType_BarCodes_TextData           = 18 // TDocVisualExtendedInfo
	RPRM_ResultType_BarCodes_ImageData          = 19 // TDocGraphicsInfo
	RPRM_ResultType_Authenticity                = 20 // TAuthenticityCheckList

	//-------------------- unused  ---------------
	RPRM_ResultType_ExpertAnalyze       = 21 // not used
	RPRM_ResultType_OCRLexicalAnalyzeEx = 22 // not used
	//-------------------- unused  ---------------

	RPRM_ResultType_EOSImage                = 23 // TRawImageContainer for EOS full-size images
	RPRM_ResultType_Bayer                   = 24 // TRawImageContainer
	RPRM_ResultType_MagneticStripe          = 25 // byte array
	RPRM_ResultType_MagneticStripe_TextData = 26 // TDocVisualExtendedInfo
	RPRM_ResultType_FieldFileImage          = 27 // byte array
	RPRM_ResultType_DatabaseCheck           = 28 // TDatabaseCheck
	RPRM_ResultType_FingerprintTemplateISO  = 29 // byte array

	RPRM_ResultType_InputImageQuality        = 30 // TImageQualityCheckList
	RPRM_ResultType_DeviceInfo               = 31 // TRegulaDeviceProperties
	RPRM_ResultType_LivePortrait             = 32 // TDocGraphicsInfo
	RPRM_ResultType_Status                   = 33 // TStatus
	RPRM_ResultType_Portrait_Comparison      = 34 // TAuthenticityCheckList
	RPRM_ResultType_ExtPortrait              = 35 // TDocGraphicsInfo
	RPRM_ResultType_Text                     = 36 // TTextResult
	RPRM_ResultType_Images                   = 37 // TImagesResult
	RPRM_ResultType_FingerPrints             = 38 // TDocGraphicsInfo
	RPRM_ResultType_FingerPrint_Comparison   = 39 // TAuthenticityCheckList
	RPRM_ResultType_FaceDatabaseCheck        = 40 // TDatabaseCheck
	RPRM_ResultType_FingerprintDatabaseCheck = 41 // TDatabaseCheck
	RPRM_ResultType_BarcodePosition          = 62 // TBoundsResult;
	RPRM_ResultType_BSI_XML_v2               = 73 // BSI XML v2 result. buffer = char* - pointer to BSI XML v2
	RPRM_ResultType_DocumentPosition         = 85 // TBoundsResult
	RPRM_ResultType_BSI_XML                  = 92 // BSI XML result. buffer = char* - pointer to BSI XML
	RPRM_ResultType_Custom                   = 100
)
