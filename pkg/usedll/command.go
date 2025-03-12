package usedll

// eRPRM_Commands
var (
	RPRM_Command_Device_Count = int32(0x00000001) //retrieve a number of available document readers,
	//  result = uint32_t *
	RPRM_Command_Device_Features = int32(0x00000002) //retrieve reader's features,
	//  params = device index) result = TRegulaDeviceProperties **
	RPRM_Command_Device_RefreshList = int32(0x00000003) //refresh list of available readers
	//  result = uint32_t * - returns new device count
	RPRM_Command_Device_ActiveIndex = int32(0x00000004) //retrieve an index of the active reader in the current list of available readers
	//  result = uint32_t *
	RPRM_Command_Device_Connect = int32(0x00000005) //connect selected document reader,
	//  params = device index
	RPRM_Command_Device_Disconnect = int32(0x00000006) //disconnect active reader

	RPRM_Command_Device_Light_ScanList_Clear = int32(0x00000007) //clear current scanning light list for active reader
	RPRM_Command_Device_Light_ScanList_AddTo = int32(0x00000008) //add light to the scanning list for active reader
	//  params = eRPRM_Lights combination
	RPRM_Command_Device_Light_ScanList_Default = int32(0x00000016) //restore default scan list
	RPRM_Command_Device_Light_ScanList_Count   = int32(0x00000017) //retrieve a number of scan list elements
	//  result = uint32_t *
	RPRM_Command_Device_Light_ScanList_Item = int32(0x00000018) //retrieve an item from current scan list
	//  params = item index
	//  result = uint32_t *

	RPRM_Command_Device_Light_TurnOn = int32(0x00000009) //manual light scheme activation) without image processing support
	//  params = eRPRM_Lights combination
	RPRM_Command_Device_LED = int32(0x0000000B) //manual LED control
	//  params = TIndicationLED *
	RPRM_Command_Device_PlaySound = int32(0x0000000F) //beeper

	RPRM_Command_Device_Set_ParamLowLight = int32(0x0000000C) //params = 0-10) exposure for UV
	RPRM_Command_Device_Get_ParamLowLight = int32(0x0000000D) //result = long * for value

	RPRM_Command_Device_Calibration = int32(0x00000015) //calibrate the device

	RPRM_Command_Process = int32(0x00000019) //to capture and process images
	//  params = eRPRM_GetImage_Modes combination

	RPRM_Command_Options_GraphicFormat_Count = int32(0x0000001A) //result = uint32_t *
	RPRM_Command_Options_GraphicFormat_Name  = int32(0x0000001B) //params = index
	//result = char **
	RPRM_Command_Options_GraphicFormat_Select      = int32(0x0000001C) //params = format index
	RPRM_Command_Options_GraphicFormat_ActiveIndex = int32(0x00000020) //result = uint32_t *

	RPRM_Command_Options_GetSDKCapabilities     = int32(0x0000001E) //result = long * for eRPRM_Capabilities combination
	RPRM_Command_Options_GetSDKAuthCapabilities = int32(0x00000035) //result = long * for eRPRM_Authenticity combination

	RPRM_Command_Options_Set_MRZTestQualityParams = int32(0x00000022) //params = TCommandsMRZTestQuality *
	RPRM_Command_Options_Get_MRZTestQualityParams = int32(0x00000023) //result = TCommandsMRZTestQuality **

	RPRM_Command_ProcessImagesList = int32(0x00000024) //to process a list of images instead of executing live scanning
	//params = TResultContainerList *
	//result = eRPRM_GetImage_Modes combination (as 2nd input parameter)

	RPRM_Command_Options_Set_CurrentDocumentType = int32(0x00000027) //params = char *) for RPRM_Command_ProcessImagesList to follow
	RPRM_Command_Options_Get_CurrentDocumentType = int32(0x00000028) //result = char **

	RPRM_Command_Options_Set_CustomDocTypeMode = int32(0x00000029) //params = true or false
	RPRM_Command_Options_Get_CustomDocTypeMode = int32(0x0000002A) //result = long * for true or false

	RPRM_Command_Get_DocumentsInfoList = int32(0x0000002B) //

	RPRM_Command_OCRLexicalAnalyze = int32(0x0000002C) //params = TDocVisualExtendedInfo * with RFID data (if exists)

	RPRM_Command_Device_IsCalibrated = int32(0x0000002D) //check if the device has valid calibration data
	// result = long * for true or false

	RPRM_Command_Options_Set_CheckResultHeight = int32(0x0000002E) //params = desired image height

	RPRM_Command_Device_Set_WorkingVideoMode = int32(0x00000030) //params = eRPRM_VideoModes
	RPRM_Command_Device_Get_WorkingVideoMode = int32(0x00000031) //result = long *

	RPRM_Command_Options_Set_AuthenticityCheckMode = int32(0x00000032) //params = eRPRM_Authenticity
	RPRM_Command_Options_Get_AuthenticityCheckMode = int32(0x00000033) //result = long *

	RPRM_Command_Options_Get_BatteryStatus = int32(0x00000034) // Get status of installed accumulator batteries
	// params = long - number of accumulator
	// result = long *  0-100%) 0xFF - no battery) 0xFE - charging) 0xF0 - battery level 100%

	RPRM_Command_Options_BuildExtLog        = int32(0x00000040) //params = true or false
	RPRM_Command_Device_SetFrequencyDivider = int32(0x00000041) //params = long (0-5)

	RPRM_Command_Device_Get_DriverVersion = int32(0x00000042) //result = long *

	RPRM_Command_Device_APM_Mode = int32(0x00000044) //params = true or false for Advanced Power Management mode

	RPRM_Command_Device_UseVideoDetection = int32(0x00000045) //params = true or false

	RPRM_Command_ExpertAnalyze                             = int32(0x00000046) //params = TDocVisualExtendedInfo * with RFID data (if exists)
	RPRM_Command_ClearResults                              = int32(0x00000047) //no params
	RPRM_Command_Options_GraphicFormat_SetCompressionRatio = int32(0x00000048) //params - the level of compression (0 - min)  10 - max)
	RPRM_Command_Options_GraphicFormat_GetCompressionRatio = int32(0x00000049) //result = long *
	RPRM_Command_Process_Cancel                            = int32(0x0000004A) //no params

	RPRM_Command_ExcludeCapabilities     = int32(0x0000004B) // params = eRPRM_Capabilities combination to exclude
	RPRM_Command_ExcludeAuthCapabilities = int32(0x0000004C) // params = eRPRM_Authenticity combination to exclude

	RPRM_Command_MakeSingleShot = int32(0x0000004D) // make single shot. params = eRPRM_Lights (one value)) result = eRPRM_GetImage_Modes combination

	RPRM_Command_Device_GetFrequencyDivider = int32(0x0000004E) // get Frequency Divider value;

	RPRM_Command_ComplexAuthenticityCheck      = int32(0x0000004F) // complex security check for multi-page document
	RPRM_Command_Options_Set_GlareCompensation = int32(0x00000050) // glare compensation for Regula readers) params = true or false

	RPRM_Command_Options_Set_ExtendProcessingModes = int32(0x00000051) // Turn additional processing modes ON) params = true or false) default = true

	RPRM_Command_Options_Get_AppendVisa              = int32(0x00000052) // [deprecated] get current "append visa" mode (false by default)
	RPRM_Command_Options_Set_AppendVisa              = int32(0x00000053) // [deprecated] set "append visa" mode (false by default)
	RPRM_Command_Options_Set_MultiPageProcessingMode = int32(0x00000054) // set "multipage processing" mode (true by default)

	RPRM_Command_Device_Get_Calibration_FrequencyDivider = int32(0x00000055) // get device calibration Frequency Divider value;

	RPRM_Command_PortraitGraphicalAnalyze = int32(0x00000056) // compare portrait images
	// params = TResultContainerList * with additional containers with external data
	// (e.g. RFID) RPRM_ResultType_LivePortrait or RPRM_ResultType_ExtPortrait if applicable)
	RPRM_Command_Options_Set_SmartUV            = int32(0x00000057) // UV substitution for Regula readers) params = true or false
	RPRM_Command_Options_Set_RotateResultImages = int32(0x00000058) // rotate document images by document type or portrait orientation
	RPRM_Command_BSIDocCheckXML                 = int32(0x00000059) // generate BSI document check XML
	// params = TResultContainerList *
	// result = char ** containing XML

	RPRM_Command_Options_Get_QuickMrzProcessing = int32(0x0000005A) // Get QuickMrzProcessing parameter value (result = uint32_t*) FALSE by default)
	RPRM_Command_Options_Set_QuickMrzProcessing = int32(0x0000005B) // Set QuickMrzProcessing parameter value (params = uint32_t) TRUE/FALSE)

	RPRM_Command_Device_SetVideoDetectionDivider = int32(0x0000005C) // Set VideoDetectionFrameSize parameter value (params = uint32_t)
	RPRM_Command_Device_GetVideoDetectionDivider = int32(0x0000005D) // Get VideoDetectionFrameSize parameter value (result = uint32_t*)

	RPRM_Command_Device_SetRequiredOcrFields = int32(0x0000005E) // Set Required Ocr Fields (params = TDwordArray *)
	RPRM_Command_Device_GetRequiredOcrFields = int32(0x0000005F) // Get Required Ocr Fields (result = TDwordArray **)

	RPRM_Command_Options_Get_BatteryNumber = int32(0x00000060) // Get number of installed accumulator batteries in device) result - long *.

	RPRM_Command_Options_Get_QuickBoardingPassProcessing = int32(0x00000061) // Get QuickBoardingPassProcessing parameter value (result = uint32_t*) FALSE by default)
	RPRM_Command_Options_Set_QuickBoardingPassProcessing = int32(0x00000062) // Set QuickBoardingPassProcessing parameter value (params = uint32_t) TRUE/FALSE)

	RPRM_Command_Options_Set_WaitForReadingComplete = int32(0x00000063) // Set WaitForReadingComplete parameter value (params = uint32_t) TRUE/FALSE)
	RPRM_Command_ReadingComplete                    = int32(0x00000064) // RFID reading complete) eject card

	RPRM_Command_Options_Get_LexAnalysisDepth = int32(0x00000065) // [deprecated] Get LexAnalysisDepth parameter value (result = uint32_t*) (eLexAnalysisDepth)eLAD_Default by default)
	RPRM_Command_Options_Set_LexAnalysisDepth = int32(0x00000066) // [deprecated] Set LexAnalysisDepth parameter value (params = uint32_t) eLexAnalysisDepth)

	RPRM_Command_Options_Get_LexDateFormat = int32(0x00000067) // [deprecated] Get Lex Date Format parameter value (result = TLexDateFormat**)
	RPRM_Command_Options_Set_LexDateFormat = int32(0x00000068) // [deprecated] Set Lex Date Format parameter value (params = TLexDateFormat*)

	RPRM_Command_Device_Get_GetJpegImages = int32(0x00000069) // Get GetJpegImages parameter value (result = uint32_t*) FALSE by default)
	RPRM_Command_Device_Set_GetJpegImages = int32(0x0000006A) // Set GetJpegImages parameter value (params = uint32_t) TRUE/FALSE)

	RPRM_Command_BSIDocCheckXMLv2 = int32(0x0000006B) // generate BSI document check XML v2
	// params = TResultContainerList *
	// result = char ** containing XML

	RPRM_Command_Options_Get_TrustDPI = int32(0x0000006C) // Get TrustDPI parameter value (result = uint32_t*) FALSE by default)
	RPRM_Command_Options_Set_TrustDPI = int32(0x0000006D) // Set TrustDPI parameter value (params = uint32_t) TRUE/FALSE)

	RPRM_Command_Options_Get_LexParams           = int32(0x0000006E) // Get Lex parameters JSON value (result = char **)
	RPRM_Command_Options_Set_LexParams           = int32(0x0000006F) // Set Lex parameters JSON value (params = char *)
	RPRM_Command_Options_Get_StopOnBadInputImage = int32(0x00000070) // Get StopOnBadInputImage parameter value (result = uint32_t*) FALSE by default)
	RPRM_Command_Options_Set_StopOnBadInputImage = int32(0x00000071) // Set StopOnBadInputImage parameter value (params = uint32_t) TRUE/FALSE)

	RPRM_Command_Set_ProcessParametersJson = int32(0x00000072) // params = char* with process parameters JSON

	RPRM_Command_Options_Set_VideodetectionLowSensibility = int32(0x00000073) // Set VideodetectionLowSensibility parameter value (params = uint32_t) TRUE/FALSE)
	RPRM_Command_Options_Set_TrustVideodetectionResult    = int32(0x00000074) // Set TrustVideodetectionResult parameter value (params = uint32_t) TRUE/FALSE)

	RPRM_Command_Device_Get_LED   = int32(0x00000075) //get LED status. result = TIndicationLED*
	RPRM_Command_Get_DatabaseInfo = int32(0x00000076) //get database info. result = char** with database description JSON

	RPRM_Command_Device_Fingerprints_Scan = int32(0x00000077) // params - json with dllPath and scanParams
	RPRM_Command_Fingerprints_Compare     = int32(0x00000078) // params - json with dllPath and comparisonParams

	RPRM_Command_Add_External_Containers = int32(0x00000079) // params - TResultContainerList*
	RPRM_Command_Fingerprints_Search     = int32(0x0000007A) // params - json with dllPath and searchParams
)
