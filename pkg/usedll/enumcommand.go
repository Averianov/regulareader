package usedll

import "fmt"

type RPRM_Command int32

// eRPRM_Commands
var (
	RPRM_Command_Device_Count = RPRM_Command(int32(0x00000001)) //retrieve a number of available document readers,
	//  result = uRPRM_Command_t *
	RPRM_Command_Device_Features = RPRM_Command(int32(0x00000002)) //retrieve reader's features,
	//  params = device index) result = TRegulaDeviceProperties **
	RPRM_Command_Device_RefreshList = RPRM_Command(int32(0x00000003)) //refresh list of available readers
	//  result = uRPRM_Command_t * - returns new device count
	RPRM_Command_Device_ActiveIndex = RPRM_Command(int32(0x00000004)) //retrieve an index of the active reader in the current list of available readers
	//  result = uRPRM_Command_t *
	RPRM_Command_Device_Connect = RPRM_Command(int32(0x00000005)) //connect selected document reader,
	//  params = device index
	RPRM_Command_Device_Disconnect = RPRM_Command(int32(0x00000006)) //disconnect active reader

	RPRM_Command_Device_Light_ScanList_Clear = RPRM_Command(int32(0x00000007)) //clear current scanning light list for active reader
	RPRM_Command_Device_Light_ScanList_AddTo = RPRM_Command(int32(0x00000008)) //add light to the scanning list for active reader
	//  params = eRPRM_Lights combination
	RPRM_Command_Device_Light_ScanList_Default = RPRM_Command(int32(0x00000016)) //restore default scan list
	RPRM_Command_Device_Light_ScanList_Count   = RPRM_Command(int32(0x00000017)) //retrieve a number of scan list elements
	//  result = uRPRM_Command_t *
	RPRM_Command_Device_Light_ScanList_Item = RPRM_Command(int32(0x00000018)) //retrieve an item from current scan list
	//  params = item index
	//  result = uRPRM_Command_t *

	RPRM_Command_Device_Light_TurnOn = RPRM_Command(int32(0x00000009)) //manual light scheme activation) without image processing support
	//  params = eRPRM_Lights combination
	RPRM_Command_Device_LED = RPRM_Command(int32(0x0000000B)) //manual LED control
	//  params = TIndicationLED *
	RPRM_Command_Device_PlaySound = RPRM_Command(int32(0x0000000F)) //beeper

	RPRM_Command_Device_Set_ParamLowLight = RPRM_Command(int32(0x0000000C)) //params = 0-10) exposure for UV
	RPRM_Command_Device_Get_ParamLowLight = RPRM_Command(int32(0x0000000D)) //result = long * for value

	RPRM_Command_Device_Calibration = RPRM_Command(int32(0x00000015)) //calibrate the device

	RPRM_Command_Process = RPRM_Command(int32(0x00000019)) //to capture and process images
	//  params = eRPRM_GetImage_Modes combination

	RPRM_Command_Options_GraphicFormat_Count = RPRM_Command(int32(0x0000001A)) //result = uRPRM_Command_t *
	RPRM_Command_Options_GraphicFormat_Name  = RPRM_Command(int32(0x0000001B)) //params = index
	//result = char **
	RPRM_Command_Options_GraphicFormat_Select      = RPRM_Command(int32(0x0000001C)) //params = format index
	RPRM_Command_Options_GraphicFormat_ActiveIndex = RPRM_Command(int32(0x00000020)) //result = uRPRM_Command_t *

	RPRM_Command_Options_GetSDKCapabilities     = RPRM_Command(int32(0x0000001E)) //result = long * for eRPRM_Capabilities combination
	RPRM_Command_Options_GetSDKAuthCapabilities = RPRM_Command(int32(0x00000035)) //result = long * for eRPRM_Authenticity combination

	RPRM_Command_Options_Set_MRZTestQualityParams = RPRM_Command(int32(0x00000022)) //params = TCommandsMRZTestQuality *
	RPRM_Command_Options_Get_MRZTestQualityParams = RPRM_Command(int32(0x00000023)) //result = TCommandsMRZTestQuality **

	RPRM_Command_ProcessImagesList = RPRM_Command(int32(0x00000024)) //to process a list of images instead of executing live scanning
	//params = TResultContainerList *
	//result = eRPRM_GetImage_Modes combination (as 2nd input parameter)

	RPRM_Command_Options_Set_CurrentDocumentType = RPRM_Command(int32(0x00000027)) //params = char *) for RPRM_Command_ProcessImagesList to follow
	RPRM_Command_Options_Get_CurrentDocumentType = RPRM_Command(int32(0x00000028)) //result = char **

	RPRM_Command_Options_Set_CustomDocTypeMode = RPRM_Command(int32(0x00000029)) //params = true or false
	RPRM_Command_Options_Get_CustomDocTypeMode = RPRM_Command(int32(0x0000002A)) //result = long * for true or false

	RPRM_Command_Get_DocumentsInfoList = RPRM_Command(int32(0x0000002B)) //

	RPRM_Command_OCRLexicalAnalyze = RPRM_Command(int32(0x0000002C)) //params = TDocVisualExtendedInfo * with RFID data (if exists)

	RPRM_Command_Device_IsCalibrated = RPRM_Command(int32(0x0000002D)) //check if the device has valid calibration data
	// result = long * for true or false

	RPRM_Command_Options_Set_CheckResultHeight = RPRM_Command(int32(0x0000002E)) //params = desired image height

	RPRM_Command_Device_Set_WorkingVideoMode = RPRM_Command(int32(0x00000030)) //params = eRPRM_VideoModes
	RPRM_Command_Device_Get_WorkingVideoMode = RPRM_Command(int32(0x00000031)) //result = long *

	RPRM_Command_Options_Set_AuthenticityCheckMode = RPRM_Command(int32(0x00000032)) //params = eRPRM_Authenticity
	RPRM_Command_Options_Get_AuthenticityCheckMode = RPRM_Command(int32(0x00000033)) //result = long *

	RPRM_Command_Options_Get_BatteryStatus = RPRM_Command(int32(0x00000034)) // Get status of installed accumulator batteries
	// params = long - number of accumulator
	// result = long *  0-100%) 0xFF - no battery) 0xFE - charging) 0xF0 - battery level 100%

	RPRM_Command_Options_BuildExtLog        = RPRM_Command(int32(0x00000040)) //params = true or false
	RPRM_Command_Device_SetFrequencyDivider = RPRM_Command(int32(0x00000041)) //params = long (0-5)

	RPRM_Command_Device_Get_DriverVersion = RPRM_Command(int32(0x00000042)) //result = long *

	RPRM_Command_Device_APM_Mode = RPRM_Command(int32(0x00000044)) //params = true or false for Advanced Power Management mode

	RPRM_Command_Device_UseVideoDetection = RPRM_Command(int32(0x00000045)) //params = true or false

	RPRM_Command_ExpertAnalyze                             = RPRM_Command(int32(0x00000046)) //params = TDocVisualExtendedInfo * with RFID data (if exists)
	RPRM_Command_ClearResults                              = RPRM_Command(int32(0x00000047)) //no params
	RPRM_Command_Options_GraphicFormat_SetCompressionRatio = RPRM_Command(int32(0x00000048)) //params - the level of compression (0 - min)  10 - max)
	RPRM_Command_Options_GraphicFormat_GetCompressionRatio = RPRM_Command(int32(0x00000049)) //result = long *
	RPRM_Command_Process_Cancel                            = RPRM_Command(int32(0x0000004A)) //no params

	RPRM_Command_ExcludeCapabilities     = RPRM_Command(int32(0x0000004B)) // params = eRPRM_Capabilities combination to exclude
	RPRM_Command_ExcludeAuthCapabilities = RPRM_Command(int32(0x0000004C)) // params = eRPRM_Authenticity combination to exclude

	RPRM_Command_MakeSingleShot = RPRM_Command(int32(0x0000004D)) // make single shot. params = eRPRM_Lights (one value)) result = eRPRM_GetImage_Modes combination

	RPRM_Command_Device_GetFrequencyDivider = RPRM_Command(int32(0x0000004E)) // get Frequency Divider value;

	RPRM_Command_ComplexAuthenticityCheck      = RPRM_Command(int32(0x0000004F)) // complex security check for multi-page document
	RPRM_Command_Options_Set_GlareCompensation = RPRM_Command(int32(0x00000050)) // glare compensation for Regula readers) params = true or false

	RPRM_Command_Options_Set_ExtendProcessingModes = RPRM_Command(int32(0x00000051)) // Turn additional processing modes ON) params = true or false) default = true

	RPRM_Command_Options_Get_AppendVisa              = RPRM_Command(int32(0x00000052)) // [deprecated] get current "append visa" mode (false by default)
	RPRM_Command_Options_Set_AppendVisa              = RPRM_Command(int32(0x00000053)) // [deprecated] set "append visa" mode (false by default)
	RPRM_Command_Options_Set_MultiPageProcessingMode = RPRM_Command(int32(0x00000054)) // set "multipage processing" mode (true by default)

	RPRM_Command_Device_Get_Calibration_FrequencyDivider = RPRM_Command(int32(0x00000055)) // get device calibration Frequency Divider value;

	RPRM_Command_PortraitGraphicalAnalyze = RPRM_Command(int32(0x00000056)) // compare portrait images
	// params = TResultContainerList * with additional containers with external data
	// (e.g. RFID) RPRM_ResultType_LivePortrait or RPRM_ResultType_ExtPortrait if applicable)
	RPRM_Command_Options_Set_SmartUV            = RPRM_Command(int32(0x00000057)) // UV substitution for Regula readers) params = true or false
	RPRM_Command_Options_Set_RotateResultImages = RPRM_Command(int32(0x00000058)) // rotate document images by document type or portrait orientation
	RPRM_Command_BSIDocCheckXML                 = RPRM_Command(int32(0x00000059)) // generate BSI document check XML
	// params = TResultContainerList *
	// result = char ** containing XML

	RPRM_Command_Options_Get_QuickMrzProcessing = RPRM_Command(int32(0x0000005A)) // Get QuickMrzProcessing parameter value (result = uRPRM_Command_t*) FALSE by default)
	RPRM_Command_Options_Set_QuickMrzProcessing = RPRM_Command(int32(0x0000005B)) // Set QuickMrzProcessing parameter value (params = uRPRM_Command_t) TRUE/FALSE)

	RPRM_Command_Device_SetVideoDetectionDivider = RPRM_Command(int32(0x0000005C)) // Set VideoDetectionFrameSize parameter value (params = uRPRM_Command_t)
	RPRM_Command_Device_GetVideoDetectionDivider = RPRM_Command(int32(0x0000005D)) // Get VideoDetectionFrameSize parameter value (result = uRPRM_Command_t*)

	RPRM_Command_Device_SetRequiredOcrFields = RPRM_Command(int32(0x0000005E)) // Set Required Ocr Fields (params = TDwordArray *)
	RPRM_Command_Device_GetRequiredOcrFields = RPRM_Command(int32(0x0000005F)) // Get Required Ocr Fields (result = TDwordArray **)

	RPRM_Command_Options_Get_BatteryNumber = RPRM_Command(int32(0x00000060)) // Get number of installed accumulator batteries in device) result - long *.

	RPRM_Command_Options_Get_QuickBoardingPassProcessing = RPRM_Command(int32(0x00000061)) // Get QuickBoardingPassProcessing parameter value (result = uRPRM_Command_t*) FALSE by default)
	RPRM_Command_Options_Set_QuickBoardingPassProcessing = RPRM_Command(int32(0x00000062)) // Set QuickBoardingPassProcessing parameter value (params = uRPRM_Command_t) TRUE/FALSE)

	RPRM_Command_Options_Set_WaitForReadingComplete = RPRM_Command(int32(0x00000063)) // Set WaitForReadingComplete parameter value (params = uRPRM_Command_t) TRUE/FALSE)
	RPRM_Command_ReadingComplete                    = RPRM_Command(int32(0x00000064)) // RFID reading complete) eject card

	RPRM_Command_Options_Get_LexAnalysisDepth = RPRM_Command(int32(0x00000065)) // [deprecated] Get LexAnalysisDepth parameter value (result = uRPRM_Command_t*) (eLexAnalysisDepth)eLAD_Default by default)
	RPRM_Command_Options_Set_LexAnalysisDepth = RPRM_Command(int32(0x00000066)) // [deprecated] Set LexAnalysisDepth parameter value (params = uRPRM_Command_t) eLexAnalysisDepth)

	RPRM_Command_Options_Get_LexDateFormat = RPRM_Command(int32(0x00000067)) // [deprecated] Get Lex Date Format parameter value (result = TLexDateFormat**)
	RPRM_Command_Options_Set_LexDateFormat = RPRM_Command(int32(0x00000068)) // [deprecated] Set Lex Date Format parameter value (params = TLexDateFormat*)

	RPRM_Command_Device_Get_GetJpegImages = RPRM_Command(int32(0x00000069)) // Get GetJpegImages parameter value (result = uRPRM_Command_t*) FALSE by default)
	RPRM_Command_Device_Set_GetJpegImages = RPRM_Command(int32(0x0000006A)) // Set GetJpegImages parameter value (params = uRPRM_Command_t) TRUE/FALSE)

	RPRM_Command_BSIDocCheckXMLv2 = RPRM_Command(int32(0x0000006B)) // generate BSI document check XML v2
	// params = TResultContainerList *
	// result = char ** containing XML

	RPRM_Command_Options_Get_TrustDPI = RPRM_Command(int32(0x0000006C)) // Get TrustDPI parameter value (result = uRPRM_Command_t*) FALSE by default)
	RPRM_Command_Options_Set_TrustDPI = RPRM_Command(int32(0x0000006D)) // Set TrustDPI parameter value (params = uRPRM_Command_t) TRUE/FALSE)

	RPRM_Command_Options_Get_LexParams           = RPRM_Command(int32(0x0000006E)) // Get Lex parameters JSON value (result = char **)
	RPRM_Command_Options_Set_LexParams           = RPRM_Command(int32(0x0000006F)) // Set Lex parameters JSON value (params = char *)
	RPRM_Command_Options_Get_StopOnBadInputImage = RPRM_Command(int32(0x00000070)) // Get StopOnBadInputImage parameter value (result = uRPRM_Command_t*) FALSE by default)
	RPRM_Command_Options_Set_StopOnBadInputImage = RPRM_Command(int32(0x00000071)) // Set StopOnBadInputImage parameter value (params = uRPRM_Command_t) TRUE/FALSE)

	RPRM_Command_Set_ProcessParametersJson = RPRM_Command(int32(0x00000072)) // params = char* with process parameters JSON

	RPRM_Command_Options_Set_VideodetectionLowSensibility = RPRM_Command(int32(0x00000073)) // Set VideodetectionLowSensibility parameter value (params = uRPRM_Command_t) TRUE/FALSE)
	RPRM_Command_Options_Set_TrustVideodetectionResult    = RPRM_Command(int32(0x00000074)) // Set TrustVideodetectionResult parameter value (params = uRPRM_Command_t) TRUE/FALSE)

	RPRM_Command_Device_Get_LED   = RPRM_Command(int32(0x00000075)) //get LED status. result = TIndicationLED*
	RPRM_Command_Get_DatabaseInfo = RPRM_Command(int32(0x00000076)) //get database info. result = char** with database description JSON

	RPRM_Command_Device_Fingerprints_Scan = RPRM_Command(int32(0x00000077)) // params - json with dllPath and scanParams
	RPRM_Command_Fingerprints_Compare     = RPRM_Command(int32(0x00000078)) // params - json with dllPath and comparisonParams

	RPRM_Command_Add_External_Containers = RPRM_Command(int32(0x00000079)) // params - TResultContainerList*
	RPRM_Command_Fingerprints_Search     = RPRM_Command(int32(0x0000007A)) // params - json with dllPath and searchParams
)

func (e RPRM_Command) String() string {
	switch RPRM_Command(e) {
	case RPRM_Command_Device_Count:
		return "Device_Count"
	case RPRM_Command_Device_Features:
		return "Device_Features"
	case RPRM_Command_Device_RefreshList:
		return "Device_RefreshList"
	case RPRM_Command_Device_ActiveIndex:
		return "Device_ActiveIndex"
	case RPRM_Command_Device_Connect:
		return "Device_Connect"
	case RPRM_Command_Device_Disconnect:
		return "Device_Disconnect"
	case RPRM_Command_Device_Light_ScanList_Clear:
		return "Device_Light_ScanList_Clear"
	case RPRM_Command_Device_Light_ScanList_AddTo:
		return "Device_Light_ScanList_AddTo"
	case RPRM_Command_Device_Light_ScanList_Default:
		return "Device_Light_ScanList_Default"
	case RPRM_Command_Device_Light_ScanList_Count:
		return "Device_Light_ScanList_Count"
	case RPRM_Command_Device_Light_ScanList_Item:
		return "Device_Light_ScanList_Item"
	case RPRM_Command_Device_Light_TurnOn:
		return "Device_Light_TurnOn"
	case RPRM_Command_Device_LED:
		return "Device_LED"
	case RPRM_Command_Device_PlaySound:
		return "Device_PlaySound"
	case RPRM_Command_Device_Set_ParamLowLight:
		return "Device_Set_ParamLowLight"
	case RPRM_Command_Device_Get_ParamLowLight:
		return "Device_Get_ParamLowLight"
	case RPRM_Command_Device_Calibration:
		return "Device_Calibration"
	case RPRM_Command_Process:
		return "Process"
	case RPRM_Command_Options_GraphicFormat_Count:
		return "Options_GraphicFormat_Count"
	case RPRM_Command_Options_GraphicFormat_Name:
		return "Options_GraphicFormat_Name"
	case RPRM_Command_Options_GraphicFormat_Select:
		return "Options_GraphicFormat_Select"
	case RPRM_Command_Options_GraphicFormat_ActiveIndex:
		return "Options_GraphicFormat_ActiveIndex"
	case RPRM_Command_Options_GetSDKCapabilities:
		return "Options_GetSDKCapabilities"
	case RPRM_Command_Options_GetSDKAuthCapabilities:
		return "Options_GetSDKAuthCapabilities"
	case RPRM_Command_Options_Set_MRZTestQualityParams:
		return "Options_Set_MRZTestQualityParams"
	case RPRM_Command_Options_Get_MRZTestQualityParams:
		return "Options_Get_MRZTestQualityParams"
	case RPRM_Command_ProcessImagesList:
		return "ProcessImagesList"
	case RPRM_Command_Options_Set_CurrentDocumentType:
		return "Options_Set_CurrentDocumentType"
	case RPRM_Command_Options_Get_CurrentDocumentType:
		return "Options_Get_CurrentDocumentType"
	case RPRM_Command_Options_Set_CustomDocTypeMode:
		return "Options_Set_CustomDocTypeMode"
	case RPRM_Command_Options_Get_CustomDocTypeMode:
		return "Options_Get_CustomDocTypeMode"
	case RPRM_Command_Get_DocumentsInfoList:
		return "Get_DocumentsInfoList"
	case RPRM_Command_OCRLexicalAnalyze:
		return "OCRLexicalAnalyze"
	case RPRM_Command_Device_IsCalibrated:
		return "Device_IsCalibrated"
	case RPRM_Command_Options_Set_CheckResultHeight:
		return "Options_Set_CheckResultHeight"
	case RPRM_Command_Device_Set_WorkingVideoMode:
		return "Device_Set_WorkingVideoMode"
	case RPRM_Command_Device_Get_WorkingVideoMode:
		return "Device_Get_WorkingVideoMode"
	case RPRM_Command_Options_Set_AuthenticityCheckMode:
		return "Options_Set_AuthenticityCheckMode"
	case RPRM_Command_Options_Get_AuthenticityCheckMode:
		return "Options_Get_AuthenticityCheckMode"
	case RPRM_Command_Options_Get_BatteryStatus:
		return "Options_Get_BatteryStatus"
	case RPRM_Command_Options_BuildExtLog:
		return "Options_BuildExtLog"
	case RPRM_Command_Device_SetFrequencyDivider:
		return "Device_SetFrequencyDivider"
	case RPRM_Command_Device_Get_DriverVersion:
		return "Device_Get_DriverVersion"
	case RPRM_Command_Device_APM_Mode:
		return "Device_APM_Mode"
	case RPRM_Command_Device_UseVideoDetection:
		return "Device_UseVideoDetection"
	case RPRM_Command_ExpertAnalyze:
		return "ExpertAnalyze"
	case RPRM_Command_ClearResults:
		return "ClearResults"
	case RPRM_Command_Options_GraphicFormat_SetCompressionRatio:
		return "Options_GraphicFormat_SetCompressionRatio"
	case RPRM_Command_Options_GraphicFormat_GetCompressionRatio:
		return "Options_GraphicFormat_GetCompressionRatio"
	case RPRM_Command_Process_Cancel:
		return "Process_Cancel"
	case RPRM_Command_ExcludeCapabilities:
		return "ExcludeCapabilities"
	case RPRM_Command_ExcludeAuthCapabilities:
		return "ExcludeAuthCapabilities"
	case RPRM_Command_MakeSingleShot:
		return "MakeSingleShot"
	case RPRM_Command_Device_GetFrequencyDivider:
		return "Device_GetFrequencyDivider"
	case RPRM_Command_ComplexAuthenticityCheck:
		return "ComplexAuthenticityCheck"
	case RPRM_Command_Options_Set_GlareCompensation:
		return "Options_Set_GlareCompensation"
	case RPRM_Command_Options_Set_ExtendProcessingModes:
		return "Options_Set_ExtendProcessingModes"
	case RPRM_Command_Options_Get_AppendVisa:
		return "Options_Get_AppendVisa"
	case RPRM_Command_Options_Set_AppendVisa:
		return "Options_Set_AppendVisa"
	case RPRM_Command_Options_Set_MultiPageProcessingMode:
		return "Options_Set_MultiPageProcessingMode"
	case RPRM_Command_Device_Get_Calibration_FrequencyDivider:
		return "Device_Get_Calibration_FrequencyDivider"
	case RPRM_Command_PortraitGraphicalAnalyze:
		return "PortraitGraphicalAnalyze"
	case RPRM_Command_Options_Set_SmartUV:
		return "Options_Set_SmartUV"
	case RPRM_Command_Options_Set_RotateResultImages:
		return "Options_Set_RotateResultImages"
	case RPRM_Command_BSIDocCheckXML:
		return "BSIDocCheckXML"
	case RPRM_Command_Options_Get_QuickMrzProcessing:
		return "Options_Get_QuickMrzProcessing"
	case RPRM_Command_Options_Set_QuickMrzProcessing:
		return "Options_Set_QuickMrzProcessing"
	case RPRM_Command_Device_SetVideoDetectionDivider:
		return "Device_SetVideoDetectionDivider"
	case RPRM_Command_Device_GetVideoDetectionDivider:
		return "Device_GetVideoDetectionDivider"
	case RPRM_Command_Device_SetRequiredOcrFields:
		return "Device_SetRequiredOcrFields"
	case RPRM_Command_Device_GetRequiredOcrFields:
		return "Device_GetRequiredOcrFields"
	case RPRM_Command_Options_Get_BatteryNumber:
		return "Options_Get_BatteryNumber"
	case RPRM_Command_Options_Get_QuickBoardingPassProcessing:
		return "Options_Get_QuickBoardingPassProcessing"
	case RPRM_Command_Options_Set_QuickBoardingPassProcessing:
		return "Options_Set_QuickBoardingPassProcessing"
	case RPRM_Command_Options_Set_WaitForReadingComplete:
		return "Options_Set_WaitForReadingComplete"
	case RPRM_Command_ReadingComplete:
		return "ReadingComplete"
	case RPRM_Command_Options_Get_LexAnalysisDepth:
		return "Options_Get_LexAnalysisDepth"
	case RPRM_Command_Options_Set_LexAnalysisDepth:
		return "Options_Set_LexAnalysisDepth"
	case RPRM_Command_Options_Get_LexDateFormat:
		return "Options_Get_LexDateFormat"
	case RPRM_Command_Options_Set_LexDateFormat:
		return "Options_Set_LexDateFormat"
	case RPRM_Command_Device_Get_GetJpegImages:
		return "Device_Get_GetJpegImages"
	case RPRM_Command_Device_Set_GetJpegImages:
		return "Device_Set_GetJpegImages"
	case RPRM_Command_BSIDocCheckXMLv2:
		return "BSIDocCheckXMLv2"
	case RPRM_Command_Options_Get_TrustDPI:
		return "Options_Get_TrustDPI"
	case RPRM_Command_Options_Set_TrustDPI:
		return "Options_Set_TrustDPI"
	case RPRM_Command_Options_Get_LexParams:
		return "Options_Get_LexParams"
	case RPRM_Command_Options_Set_LexParams:
		return "Options_Set_LexParams"
	case RPRM_Command_Options_Get_StopOnBadInputImage:
		return "Options_Get_StopOnBadInputImage"
	case RPRM_Command_Options_Set_StopOnBadInputImage:
		return "Options_Set_StopOnBadInputImage"
	case RPRM_Command_Set_ProcessParametersJson:
		return "Set_ProcessParametersJson"
	case RPRM_Command_Options_Set_VideodetectionLowSensibility:
		return "Options_Set_VideodetectionLowSensibility"
	case RPRM_Command_Options_Set_TrustVideodetectionResult:
		return "Options_Set_TrustVideodetectionResult"
	case RPRM_Command_Device_Get_LED:
		return "Device_Get_LED"
	case RPRM_Command_Get_DatabaseInfo:
		return "Get_DatabaseInfo"
	case RPRM_Command_Device_Fingerprints_Scan:
		return "Device_Fingerprints_Scan"
	case RPRM_Command_Fingerprints_Compare:
		return "Fingerprints_Compare"
	case RPRM_Command_Add_External_Containers:
		return "Add_External_Containers"
	case RPRM_Command_Fingerprints_Search:
		return "Fingerprints_Search"
	default:
		return fmt.Sprintf("Unknown command(%d)", e)
	}
}
