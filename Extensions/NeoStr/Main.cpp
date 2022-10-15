// ============================================================================
//
// This file are where the Conditions/Actions/Expressions are defined.
// You can manually enter these, or use CICK (recommended)
// See the Extension FAQ in this SDK for more info and where to download it
//
// ============================================================================

// Common Include
#include	"common.h"

// Quick memo: content of the eventInformations arrays
// ---------------------------------------------------
// Menu ID
// String ID
// Code
// Flags
// Number_of_parameters
// Parameter_type [Number_of_parameters]
// Parameter_TitleString [Number_of_parameters]

// Definitions of parameters for each condition
short conditionsInfos[]=
		{
		IDMN_CONDITION, M_CONDITION, CND_CONDITION, EVFLAGS_ALWAYS, 3, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, M_CND_P1, M_CND_P2, M_CND_P3,
		};

// Definitions of parameters for each action
short actionsInfos[]=
		{
		IDMN_ACTION_CS, M_ACTION_CS, ACT_ACTION_CS,	0, 2, PARAM_EXPRESSION, PARAM_EXPRESSION, M_WIDTH, M_HEIGHT,
		IDMN_ACTION_CSTR, M_ACTION_CSTR, ACT_ACTION_CSTR,	0, 1, PARAM_EXPSTRING, M_STR,
		IDMN_ACTION_CRS, M_ACTION_CRS, ACT_ACTION_CRS,	0, 1, PARAM_EXPRESSION, M_ROWSPACE,
		IDMN_ACTION_CCS, M_ACTION_CCS, ACT_ACTION_CCS,	0, 1, PARAM_EXPRESSION, M_COLSPACE,

		IDMN_ACTION_CHA, M_ACTION_CHA, ACT_ACTION_CHA,	0, 1, PARAM_EXPRESSION, M_HA,
		IDMN_ACTION_CVA, M_ACTION_CVA, ACT_ACTION_CVA,	0, 1, PARAM_EXPRESSION, M_VA,

		IDMN_ACTION_ASTR, M_ACTION_ASTR, ACT_ACTION_ASTR,	0, 1, PARAM_EXPSTRING, M_STR,
		IDMN_ACTION_ASTRNL, M_ACTION_ASTRNL, ACT_ACTION_ASTRNL,	0, 1, PARAM_EXPSTRING, M_STR,
		
		IDMN_ACTION_SH, M_ACTION_SH, ACT_ACTION_SH,	0, 3, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, IDS_PROP_HOTSPOT_DEFAULT_INFO, IDS_PROP_HOTSPOT_X, IDS_PROP_HOTSPOT_Y,
		IDMN_ACTION_Z, M_ACTION_Z, ACT_ACTION_Z,	0, 2, PARAM_EXPRESSION, PARAM_EXPRESSION, M_XSCALE, M_YSCALE,
		IDMN_ACTION_S, M_ACTION_S, ACT_ACTION_S,	0, 2, PARAM_EXPRESSION, PARAM_EXPRESSION, M_WIDTH, M_HEIGHT,
		IDMN_ACTION_R, M_ACTION_R, ACT_ACTION_R,	0, 1, PARAM_EXPRESSION, M_ANGLE,

		IDMN_ACTION_EF, M_ACTION_EF, ACT_ACTION_EF,	0, 2, PARAM_EXPSTRING, PARAM_EXPSTRING, M_FONTNAME, M_KEY,

		};

// Definitions of parameters for each expression
short expressionsInfos[]=
		{
		IDMN_EXPRESSION_GSTR, M_EXPRESSION_GSTR, EXP_EXPRESSION_GSTR, EXPFLAG_STRING, 0,
		IDMN_EXPRESSION_GRS, M_EXPRESSION_GRS, EXP_EXPRESSION_GRS, 0, 0,
		IDMN_EXPRESSION_GCS, M_EXPRESSION_GCS, EXP_EXPRESSION_GCS, 0, 0,
		
		IDMN_EXPRESSION_GLCX, M_EXPRESSION_GLCX, EXP_EXPRESSION_GLCX, 0, 0,
		IDMN_EXPRESSION_GLCY, M_EXPRESSION_GLCY, EXP_EXPRESSION_GLCY, 0, 0,
		IDMN_EXPRESSION_GMW, M_EXPRESSION_GMW, EXP_EXPRESSION_GMW, 0, 0,

		IDMN_EXPRESSION_GHA, M_EXPRESSION_GHA, EXP_EXPRESSION_GHA, 0, 0,
		IDMN_EXPRESSION_GVA, M_EXPRESSION_GVA, EXP_EXPRESSION_GVA, 0, 0,

		IDMN_EXPRESSION_GTH, M_EXPRESSION_GTH, EXP_EXPRESSION_GTH, 0, 0,
		
		IDMN_EXPRESSION_GRW, M_EXPRESSION_GRW, EXP_EXPRESSION_GRW, 0, 0,
		IDMN_EXPRESSION_GRH, M_EXPRESSION_GRH, EXP_EXPRESSION_GRH, 0, 0,
		IDMN_EXPRESSION_GHX, M_EXPRESSION_GHX, EXP_EXPRESSION_GHX, 0, 0,
		IDMN_EXPRESSION_GHY, M_EXPRESSION_GHY, EXP_EXPRESSION_GHY, 0, 0,
		IDMN_EXPRESSION_GXS, M_EXPRESSION_GXS, EXP_EXPRESSION_GXS, 0, 0,
		IDMN_EXPRESSION_GYS, M_EXPRESSION_GYS, EXP_EXPRESSION_GYS, 0, 0,
		IDMN_EXPRESSION_GA, M_EXPRESSION_GA, EXP_EXPRESSION_GA, 0, 0,

		IDMN_EXPRESSION_GFN, M_EXPRESSION_GFN, EXP_EXPRESSION_GFN, EXPFLAG_STRING, 3, EXPPARAM_STRING, EXPPARAM_STRING, EXPPARAM_LONG, M_FONTNAME, M_KEY, M_POS,

		IDMN_EXPRESSION_GCX, M_EXPRESSION_GCX, EXP_EXPRESSION_GCX, 0, 1, EXPPARAM_LONG, M_POS,
		IDMN_EXPRESSION_GCY, M_EXPRESSION_GCY, EXP_EXPRESSION_GCY, 0, 1, EXPPARAM_LONG, M_POS,

		};



// ============================================================================
//
// CONDITION ROUTINES
// 
// ============================================================================

// -----------------
// Sample Condition
// -----------------
// Returns TRUE when the two values are equal!
// 

long WINAPI DLLExport Condition(LPRDATA rdPtr, long param1, long param2)
{

//  **** Still use this method for 1 or 2 parameters ****	
//	if (param1==param2)	
//		return TRUE;

	long p1 = CNC_GetParameter(rdPtr);
	long p2 = CNC_GetParameter(rdPtr);
	long p3 = CNC_GetParameter(rdPtr);

	if ((p1 + p2)==p3)
		return TRUE;
		 
	return FALSE;
}


// ============================================================================
//
// ACTIONS ROUTINES
// 
// ============================================================================

short WINAPI DLLExport Action_ChangeRenderSize(LPRDATA rdPtr, long param1, long param2) {
	short width = TURNCATE_SHORT(CNC_GetIntParameter(rdPtr));
	short height = TURNCATE_SHORT(CNC_GetIntParameter(rdPtr));

	rdPtr->swidth = width;
	rdPtr->sheight = height;

	ReDisplay(rdPtr);

	return 0;
}

short WINAPI DLLExport Action_ChangeString(LPRDATA rdPtr, long param1, long param2) {
	LPCWSTR pStr = (LPCWSTR)CNC_GetStringParameter(rdPtr);

	*rdPtr->pStr = pStr;

	ReDisplay(rdPtr);

	return 0;
}

short WINAPI DLLExport Action_AppendString(LPRDATA rdPtr, long param1, long param2) {
	LPCWSTR pStr = (LPCWSTR)CNC_GetStringParameter(rdPtr);

	rdPtr->pStr->append(pStr);

	ReDisplay(rdPtr);

	return 0;
}

short WINAPI DLLExport Action_AppendStringNewLine(LPRDATA rdPtr, long param1, long param2) {
	LPCWSTR pStr = (LPCWSTR)CNC_GetStringParameter(rdPtr);

	rdPtr->pStr->append(L"\r\n");
	rdPtr->pStr->append(pStr);

	ReDisplay(rdPtr);

	return 0;
}

short WINAPI DLLExport Action_ChangeRowSpace(LPRDATA rdPtr, long param1, long param2) {
	short nRowSpace = (short)CNC_GetIntParameter(rdPtr);

	rdPtr->nRowSpace = nRowSpace;

	ReDisplay(rdPtr);

	return 0;
}

short WINAPI DLLExport Action_ChangeColSpace(LPRDATA rdPtr, long param1, long param2) {
	short nColSpace = (short)CNC_GetIntParameter(rdPtr);

	rdPtr->nColSpace = nColSpace;

	ReDisplay(rdPtr);

	return 0;
}

short WINAPI DLLExport Action_ChangeHorizontalAlign(LPRDATA rdPtr, long param1, long param2) {
	short horizontalFlag = (short)CNC_GetIntParameter(rdPtr);
	
	rdPtr->dwAlignFlags = (rdPtr->dwAlignFlags & ~(DT_LEFT | DT_CENTER | DT_RIGHT)) | (horizontalFlag);

	ReDisplay(rdPtr);

	return 0;
}

short WINAPI DLLExport Action_ChangeVerticalAlign(LPRDATA rdPtr, long param1, long param2) {
	short verticalFlag = (short)CNC_GetIntParameter(rdPtr);

	rdPtr->dwAlignFlags = (rdPtr->dwAlignFlags & ~(DT_TOP | DT_VCENTER | DT_BOTTOM)) | (verticalFlag);

	ReDisplay(rdPtr);

	return 0;
}

short WINAPI DLLExport Action_SetHotSpot(LPRDATA rdPtr, long param1, long param2) {
	HotSpotPos pos = (HotSpotPos)CNC_GetIntParameter(rdPtr);

	int x = (int)CNC_GetIntParameter(rdPtr);
	int y = (int)CNC_GetIntParameter(rdPtr);

	rdPtr->hotSpotPos = pos;

	UpdateHotSpot(rdPtr->hotSpotPos, rdPtr->swidth, rdPtr->sheight, x, y);

	rdPtr->hotSpotX = x;
	rdPtr->hotSpotY = y;

	ChangeScale(rdPtr);

	return 0;
}

short WINAPI DLLExport Action_Zoom(LPRDATA rdPtr, long param1, long param2) {
	float xScale = GetFloatParam(rdPtr);
	float yScale = GetFloatParam(rdPtr);

	rdPtr->xScale = xScale;
	rdPtr->yScale = yScale;

	ChangeScale(rdPtr);

	return 0;
}

short WINAPI DLLExport Action_Stretch(LPRDATA rdPtr, long param1, long param2) {
	int width = (int)CNC_GetIntParameter(rdPtr);
	int height = (int)CNC_GetIntParameter(rdPtr);

	float xScale = (1.0f * width / rdPtr->swidth);
	float yScale = (1.0f * height / rdPtr->sheight);

	rdPtr->xScale = xScale;
	rdPtr->yScale = yScale;

	ChangeScale(rdPtr);

	return 0;
}

short WINAPI DLLExport Action_Rotate(LPRDATA rdPtr, long param1, long param2) {
	int angle = (int)CNC_GetIntParameter(rdPtr);
	angle = angle % 360;

	rdPtr->angle = angle;

	ChangeScale(rdPtr);

	return 0;
}

// https://docs.microsoft.com/zh-cn/windows/win32/gdi/font-installation-and-deletion
// https://docs.microsoft.com/en-us/windows/win32/api/wingdi/nf-wingdi-addfontresourceexa
short WINAPI DLLExport Action_EmbedFont(LPRDATA rdPtr, long param1, long param2) {
	std::wstring FilePath = GetFullPathNameStr((LPCTSTR)CNC_GetStringParameter(rdPtr));
	LPCTSTR Key = (LPCTSTR)CNC_GetStringParameter(rdPtr);

	bool bFromMem = !StrEmpty(Key);
	Encryption* E = nullptr;

	if (bFromMem) {
		E = new Encryption;
		E->GenerateKey(Key);

		E->OpenFile(FilePath.c_str());
		E->Decrypt();
	}

	int ret = 0;
	DWORD fontNum = 0;

	auto flags = FR_PRIVATE;

	//ret = RemoveFontResourceEx(FilePath.c_str(), flags, 0);
	ret = bFromMem
		? (int)AddFontMemResourceEx(E->GetOutputData(), E->GetOutputDataLength(), 0, &fontNum)
		: AddFontResourceEx(FilePath.c_str(), flags, 0);

	if (ret == 0) {
		return 0;
	}

	auto gdipRet = bFromMem
		? rdPtr->pData->pFontCollection->AddMemoryFont(E->GetOutputData(), E->GetOutputDataLength())
		: rdPtr->pData->pFontCollection->AddFontFile(FilePath.c_str());

	if (gdipRet != Gdiplus::Status::Ok) {
		return 0;
	}

	auto fontNames = bFromMem
		? GetFontNameFromFile((LPCWSTR)E->GetOutputData(), E->GetOutputDataLength())
		: GetFontNameFromFile(FilePath.c_str());

	delete E;

#ifdef _FONTEMBEDDEBUG
	MSGBOX((std::wstring)L"Embed " + FilePath +
		(std::wstring)(gdipRet != Gdiplus::Status::Ok
			? L" Not OK"
			: L" OK"));
 
	auto font = rdPtr->pData->pFontCollection->GetFamilyCount();
 
	for (auto& i : fontNames) {
		wprintf(L"%s\n", i.c_str());
		//std::wcout << i << std::endl;
	}
#endif // _FONTEMBEDDEBUG

	//refresh objects
	ObjectSelection Oc(rdPtr->rHo.hoAdRunHeader);
	Oc.IterateObjectWithIdentifier(rdPtr, rdPtr->rHo.hoIdentifier, [fontNames](LPRO pObject) {
		LPRDATA pObj = (LPRDATA)pObject;

		std::wstring withRegular = (std::wstring)pObj->logFont.lfFaceName + (std::wstring)L" Regular";
		//std::wstring withNormal = (std::wstring)pObj->logFont.lfFaceName + (std::wstring)L" Normal";

		for (auto& name : fontNames) {
			if (StrIEqu(pObj->logFont.lfFaceName, name.c_str())
				|| StrIEqu(withRegular.c_str(), name.c_str())
				/*|| StrIEqu(withNormal.c_str(), name.c_str())*/) {
				SetRunObjectFont(pObj, &pObj->logFont, nullptr);
				
				return;
			}
		}

		});

	return 0;
}

// ============================================================================
//
// EXPRESSIONS ROUTINES
// 
// ============================================================================

long WINAPI DLLExport Expression_GetString(LPRDATA rdPtr, long param1) {
	//Setting the HOF_STRING flag lets MMF know that you are a string.
	rdPtr->rHo.hoFlags |= HOF_STRING;

	//This returns a pointer to the string for MMF.
	return (long)(rdPtr->pStr->c_str());
}

long WINAPI DLLExport Expression_GetRowSpace(LPRDATA rdPtr,long param1) {
	return rdPtr->nRowSpace;
}

long WINAPI DLLExport Expression_GetColSpace(LPRDATA rdPtr, long param1) {
	return rdPtr->nColSpace;
}

long WINAPI DLLExport Expression_GetLastCharX(LPRDATA rdPtr, long param1) {
	return UpdateLastCharPos(rdPtr).x;
}

long WINAPI DLLExport Expression_GetLastCharY(LPRDATA rdPtr, long param1) {
	return UpdateLastCharPos(rdPtr).y;
}

long WINAPI DLLExport Expression_GetMaxWidth(LPRDATA rdPtr, long param1) {
	return UpdateLastCharPos(rdPtr).maxWidth;
}

long WINAPI DLLExport Expression_GetTotalHeight(LPRDATA rdPtr, long param1) {
	return UpdateLastCharPos(rdPtr).totalHeight;
}

long WINAPI DLLExport Expression_GetHorizontalAlign(LPRDATA rdPtr, long param1) {
	if (rdPtr->dwAlignFlags & DT_CENTER) {
		return DT_CENTER;
	}
	if (rdPtr->dwAlignFlags & DT_RIGHT) {
		return DT_RIGHT;
	}

	return DT_LEFT;
}

long WINAPI DLLExport Expression_GetVerticalAlign(LPRDATA rdPtr, long param1) {
	if (rdPtr->dwAlignFlags & DT_VCENTER) {
		return DT_VCENTER;
	}
	if (rdPtr->dwAlignFlags & DT_BOTTOM) {
		return DT_BOTTOM;
	}

	return DT_TOP;
}

long WINAPI DLLExport Expression_GetRenderWidth(LPRDATA rdPtr, long param1) {
	return rdPtr->swidth;
}
long WINAPI DLLExport Expression_GetRenderHeight(LPRDATA rdPtr, long param1) {
	return rdPtr->sheight;
}

long WINAPI DLLExport Expression_GetHotSpotX(LPRDATA rdPtr, long param1) {
	int hotSpotX = rdPtr->hotSpotX;
	int hotSpotY = rdPtr->hotSpotY;

	UpdateHotSpot(rdPtr->hotSpotPos
		, rdPtr->rHo.hoImgWidth, rdPtr->rHo.hoImgHeight
		, hotSpotX, hotSpotY);

	return hotSpotX;
}
long WINAPI DLLExport Expression_GetHotSpotY(LPRDATA rdPtr, long param1) {
	int hotSpotX = rdPtr->hotSpotX;
	int hotSpotY = rdPtr->hotSpotY;

	UpdateHotSpot(rdPtr->hotSpotPos
		, rdPtr->rHo.hoImgWidth, rdPtr->rHo.hoImgHeight
		, hotSpotX, hotSpotY);

	return hotSpotY;
}

long WINAPI DLLExport Expression_GetXScale(LPRDATA rdPtr, long param1) {
	return ReturnFloat(rdPtr->xScale);
}
long WINAPI DLLExport Expression_GetYScale(LPRDATA rdPtr, long param1) {
	return ReturnFloat(rdPtr->yScale);
}

long WINAPI DLLExport Expression_GetAngle(LPRDATA rdPtr, long param1) {
	return rdPtr->angle;
}

long WINAPI DLLExport Expression_GetFontFamilyName(LPRDATA rdPtr, long param1) {
	std::wstring filePath = (LPCTSTR)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_STRING);
	LPCTSTR Key = (LPCTSTR)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_STRING);

	size_t pos = (size_t)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);

	bool bFromMem = !StrEmpty(Key);
	Encryption* E = nullptr;

	if (bFromMem) {
		E = new Encryption;
		E->GenerateKey(Key);

		E->OpenFile(filePath.c_str());
		E->Decrypt();
	}

	auto fontNames = bFromMem
		? GetFontNameFromFile((LPCWSTR)E->GetOutputData(), E->GetOutputDataLength())
		: GetFontNameFromFile(filePath.c_str());

	delete E;

	rdPtr->rHo.hoFlags |= HOF_STRING;

	try{
		auto& name = fontNames.at(pos);
		NewStr(*rdPtr->pExpRet, name);

		return (long)rdPtr->pExpRet->c_str();

	}catch(...) {
		return (long)Empty_Str;
	}
}

long WINAPI DLLExport Expression_GetCharX(LPRDATA rdPtr, long param1) {
	size_t pos = (size_t)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);

	UpdateLastCharPos(rdPtr);
	
	return rdPtr->pNeoStr->GetCharPos(pos).x;
}

long WINAPI DLLExport Expression_GetCharY(LPRDATA rdPtr, long param1) {
	size_t pos = (size_t)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);

	UpdateLastCharPos(rdPtr);

	return rdPtr->pNeoStr->GetCharPos(pos).y;
}

// ----------------------------------------------------------
// Condition / Action / Expression jump table
// ----------------------------------------------------------
// Contains the address inside the extension of the different
// routines that handle the action, conditions and expressions.
// Located at the end of the source for convinience
// Must finish with a 0
//
long (WINAPI * ConditionJumps[])(LPRDATA rdPtr, long param1, long param2) = 
			{ 
			Condition,
			
			0
			};
	
short (WINAPI * ActionJumps[])(LPRDATA rdPtr, long param1, long param2) =
			{
			Action_ChangeRenderSize,
			Action_ChangeString,
			Action_ChangeRowSpace,
			Action_ChangeColSpace,
			
			Action_ChangeHorizontalAlign,
			Action_ChangeVerticalAlign,
			
			Action_AppendString,
			Action_AppendStringNewLine,

			Action_SetHotSpot,
			Action_Zoom,
			Action_Stretch,
			Action_Rotate,

			Action_EmbedFont,

			0
			};

long (WINAPI * ExpressionJumps[])(LPRDATA rdPtr, long param) = 
			{     
			Expression_GetString,
			Expression_GetRowSpace,
			Expression_GetColSpace,
			
			Expression_GetLastCharX,
			Expression_GetLastCharY,
			Expression_GetMaxWidth,

			Expression_GetHorizontalAlign,
			Expression_GetVerticalAlign,

			Expression_GetTotalHeight,
			
			Expression_GetRenderWidth,
			Expression_GetRenderHeight,
			Expression_GetHotSpotX,
			Expression_GetHotSpotY,
			Expression_GetXScale,
			Expression_GetYScale,
			Expression_GetAngle,

			Expression_GetFontFamilyName,

			Expression_GetCharX,
			Expression_GetCharY,
			
			0
			};