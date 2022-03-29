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
		IDMN_CONDITION_SMBS, M_CONDITION_SMBS, CND_CONDITION_SMBS, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 2, PARAM_EXPRESSION, PARAM_EXPRESSION, M_WIDTH, M_HEIGHT,
		IDMN_CONDITION_SMBB, M_CONDITION_SMBB, CND_CONDITION_SMBB, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 1, PARAM_EXPSTRING, M_BASE64,
		IDMN_CONDITION_SMBC, M_CONDITION_SMBC, CND_CONDITION_SMBC, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 7, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPSTRING, M_GIRDSIZE, M_GIRDOFFSETX, M_GIRDOFFSETY, M_EVEIT, M_BASEALYER, M_TYPE, M_ITNAME,
		IDMN_CONDITION_OSMBC, M_CONDITION_OSMBC, CND_CONDITION_OSMBC, 0, 1, PARAM_EXPSTRING, M_ITNAME,

		IDMN_CONDITION_OPF, M_CONDITION_OPF, CND_CONDITION_OPF, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 9, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPSTRING, M_STARTX, M_STARTY, M_DESTINATIONX, M_DESTINATIONY, M_DIAGONAL, M_CHECKDIAGONALCORNER, M_FORCEFIND, M_USEREALCOORD, M_SAVENAME,

		IDMN_CONDITION_PA, M_CONDITION_PA, CND_CONDITION_PA, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 1, PARAM_EXPSTRING, M_PATHNAME,
		
		IDMN_CONDITION_OITP, M_CONDITION_OITP, CND_CONDITION_OITP, 0, 1, PARAM_EXPSTRING, M_ITNAME,
		
		IDMN_CONDITION_MA, M_CONDITION_MA, CND_CONDITION_MA, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 0,
		IDMN_CONDITION_CMCAC, M_CONDITION_CMCAC, CND_CONDITION_CMCAC, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 5, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION,M_X, M_Y, M_COST_CHECK, M_TYPE, M_USEREALCOORD,

		IDMN_CONDITION_OAG, M_CONDITION_OAG, CND_CONDITION_OAG, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 3, PARAM_OBJECT, PARAM_EXPRESSION, PARAM_EXPRESSION, M_OBJECT, M_X, M_Y,
		IDMN_CONDITION_OAO, M_CONDITION_OAO, CND_CONDITION_OAO, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 2, PARAM_OBJECT, PARAM_EXPRESSION, M_OBJECT, M_TYPE,
		IDMN_CONDITION_OAC, M_CONDITION_OAC, CND_CONDITION_OAC, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 3, PARAM_OBJECT, PARAM_EXPRESSION, PARAM_EXPRESSION, M_OBJECT, M_X, M_Y,

		IDMN_CONDITION_SMBP, M_CONDITION_SMBP, CND_CONDITION_SMBP, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 4, PARAM_EXPSTRING, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, M_FILEPATH, M_GIRDSIZE, M_GIRDOFFSETX, M_GIRDOFFSETY,
		};

// Definitions of parameters for each action
short actionsInfos[]=
		{
		IDMN_ACTION_SM, M_ACTION_SM, ACT_ACTION_SM,	0, 6, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, M_X, M_Y, M_COST, M_TYPE, M_USEREALCOORD, M_USEITERATECOORD,
		
		IDMN_ACTION_C, M_ACTION_C, ACT_ACTION_C,	0, 0,
		
		IDMN_ACTION_ITP, M_ACTION_ITP, ACT_ACTION_ITP,	0, 3, PARAM_EXPSTRING, PARAM_EXPRESSION, PARAM_EXPSTRING, M_PATHNAME, M_USEREALCOORD, M_ITNAME,

		IDMN_ACTION_SMBO, M_ACTION_SMBO, ACT_ACTION_SMBO,	0, 3, PARAM_OBJECT, PARAM_EXPRESSION, PARAM_EXPRESSION, M_OBJECT, M_COST, M_TYPE,
		IDMN_ACTION_CM, M_ACTION_CM, ACT_ACTION_CM,	0, 2, PARAM_EXPRESSION, PARAM_EXPRESSION, M_COST, M_TYPE,
		};

// Definitions of parameters for each expression
short expressionsInfos[]=
		{
		IDMN_EXPRESSION_GITX, M_EXPRESSION_GITX, EXP_EXPRESSION_GITX, 0, 0,
		IDMN_EXPRESSION_GITY, M_EXPRESSION_GITY, EXP_EXPRESSION_GITY, 0, 0,

		IDMN_EXPRESSION_GS, M_EXPRESSION_GS, EXP_EXPRESSION_GS, 0, 9, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_STRING, M_STARTX_EXP, M_STARTY_EXP, M_DESTINATIONX_EXP, M_DESTINATIONY_EXP, M_DIAGONAL_EXP, M_CHECKDIAGONALCORNER_EXP, M_FORCEFIND_EXP, M_USEREALCOORD_EXP, M_SAVENAME_EXP,
		IDMN_EXPRESSION_GSOP, M_EXPRESSION_GSOP, EXP_EXPRESSION_GSOP, 0, 1, EXPPARAM_STRING, M_PATHNAME,
		IDMN_EXPRESSION_GSCOP, M_EXPRESSION_GSCOP, EXP_EXPRESSION_GSCOP, 0, 3, EXPPARAM_STRING, EXPPARAM_LONG, EXPPARAM_LONG, M_PATHNAME, M_STEP, M_COORDTYPE,

		IDMN_EXPRESSION_GGC, M_EXPRESSION_GGC, EXP_EXPRESSION_GGC, 0, 1, EXPPARAM_LONG, M_COORD,
		IDMN_EXPRESSION_GRC, M_EXPRESSION_GRC, EXP_EXPRESSION_GRC, 0, 1, EXPPARAM_LONG, M_COORD,

		IDMN_EXPRESSION_GITI, M_EXPRESSION_GITI, EXP_EXPRESSION_GITI, 0, 0,

		IDMN_EXPRESSION_GMC, M_EXPRESSION_GMC, EXP_EXPRESSION_GMC, 0, 4, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_LONG, M_X, M_Y, M_USEREALCOORD, M_TYPE,
		IDMN_EXPRESSION_GMB64, M_EXPRESSION_GMB64, EXP_EXPRESSION_GMB64, EXPFLAG_STRING, 0,
		IDMN_EXPRESSION_GMS, M_EXPRESSION_GMS, EXP_EXPRESSION_GMS, EXPFLAG_STRING, 3, EXPPARAM_LONG, EXPPARAM_LONG, EXPPARAM_STRING, M_TYPE, M_SHOWPATH, M_PATHNAME,
		};



// ============================================================================
//
// CONDITION ROUTINES
// 
// ============================================================================

long WINAPI DLLExport SetMapBySize(LPRDATA rdPtr, long param1, long param2) {
	delete rdPtr->pFTW;
	rdPtr->pFTW = nullptr;

	size_t width = (size_t)CNC_GetParameter(rdPtr);
	size_t height = (size_t)CNC_GetParameter(rdPtr);

	try {
		rdPtr->pFTW = new FindTheWayClass(width, height);
	}
	catch (Exception) {
		return FALSE;
	}

#ifdef _DEBUG
	auto map = rdPtr->pFTW->OutPutMapStr();
#endif // _DEBUG

	return TRUE;
}

long WINAPI DLLExport SetMapByBase64(LPRDATA rdPtr, long param1, long param2) {
	delete rdPtr->pFTW;
	rdPtr->pFTW = nullptr;

	wstring base64 = (LPCTSTR)CNC_GetStringParameter(rdPtr);

	try {
		rdPtr->pFTW = new FindTheWayClass(base64);
	}
	catch (Exception) {
		return FALSE;
	}

#ifdef _DEBUG
	auto map = rdPtr->pFTW->OutPutMapStr();
#endif // _DEBUG

	return TRUE;
}

long WINAPI DLLExport SetMapByPicture(LPRDATA rdPtr, long param1, long param2) {
	delete rdPtr->pFTW;
	rdPtr->pFTW = nullptr;

	wstring filePath = (LPCTSTR)CNC_GetStringParameter(rdPtr);

	size_t girdSize = (size_t)CNC_GetParameter(rdPtr);
	size_t girdOffsetX = (size_t)CNC_GetParameter(rdPtr);
	size_t girdOffsetY = (size_t)CNC_GetParameter(rdPtr);

	auto pSf = new cSurface();

	CImageFilterMgr* pImgMgr = rdPtr->rHo.hoAdRunHeader->rh4.rh4Mv->mvImgFilterMgr;
	CImageFilter    pFilter(pImgMgr);

	ImportImage(pImgMgr, filePath.c_str(), pSf, 0, 0);

	if (!pSf->IsValid()) {
		return FALSE;
	}

	size_t width = pSf->GetWidth();
	size_t height = pSf->GetHeight();

	try {
		rdPtr->pFTW = new FindTheWayClass(width, height);
	}
	catch (Exception) {
		return FALSE;
	}

	rdPtr->pFTW->SetGirdSize(girdSize, girdOffsetX, girdOffsetY);

	auto [girdWidth, girdHeight] = rdPtr->pFTW->GetGirdCoord(Coord{ width ,height });

	BYTE* buff = pSf->LockBuffer();
	if (!buff) {
		return 0;
	}

	int pitch = pSf->GetPitch();
	if (pitch < 0) {
		pitch *= -1;
		buff -= pitch * (height - 1);
	}

	size_t size = pitch * height;
	size_t byte = pSf->GetDepth() >> 3;

	for (size_t y = 0; y < girdHeight; y++) {
		for (size_t x = 0; x < girdWidth; x++) {
			auto [realX, realY] = rdPtr->pFTW->GetRealCoord(Coord{ x ,y });
			auto offset = realY * pitch + realX * byte;

			if (offset >= size) {
				continue;
			}

			auto cost = buff[offset + 2];		// R value
			rdPtr->pFTW->SetMap(x,y,cost,MapType::TERRAIN);
		}
	}

	pSf->UnlockBuffer(buff);

#ifdef _DEBUG
	auto map = rdPtr->pFTW->OutPutMapStr(MapType::TERRAIN);
#endif // _DEBUG

	return TRUE;
}

long WINAPI DLLExport SetMapByCollision(LPRDATA rdPtr, long param1, long param2) {
	delete rdPtr->pFTW;
	rdPtr->pFTW = nullptr;

	size_t girdSize = (size_t)CNC_GetParameter(rdPtr);
	size_t girdOffsetX = (size_t)CNC_GetParameter(rdPtr);
	size_t girdOffsetY = (size_t)CNC_GetParameter(rdPtr);

	bool eventIterate = (bool)CNC_GetParameter(rdPtr);
	size_t baseLayer = (size_t)CNC_GetParameter(rdPtr) - 1;		// Index start from 0, LAYER_ALL = -1 for All layer
	MapType type = (MapType)CNC_GetParameter(rdPtr);

	*rdPtr->pOnItCollisionName = (LPCTSTR)CNC_GetStringParameter(rdPtr);

	const auto& frameRect = rdPtr->rHo.hoAdRunHeader->rhFrame->m_leVirtualRect;

	auto frameWidth = frameRect.right - frameRect.left;
	auto frameHeight = frameRect.bottom - frameRect.top;

	size_t width = frameWidth / girdSize;
	size_t height = frameHeight / girdSize;

	try {
		rdPtr->pFTW = new FindTheWayClass(width, height);
	}
	catch (Exception) {
		return FALSE;
	}
	
	rdPtr->pFTW->SetGirdSize(girdSize, girdOffsetX, girdOffsetY);

	auto hoPtr = &(rdPtr->rHo);
	npWin win = hoPtr->hoAdRunHeader->rh4.rh4Mv->mvIdEditWin;

	int layerOffsetX = hoPtr->hoAdRunHeader->rh3.rh3DisplayX;
	int layerOffsetY = hoPtr->hoAdRunHeader->rh3.rh3DisplayY;

	for (size_t y = 0; y < height; y++) {
		for (size_t x = 0; x < width; x++) {
			rdPtr->itCoord = rdPtr->pFTW->GetRealCoord(Coord{ x,y });

			if (eventIterate) {
				CallEvent(ONSETMAPBYCOLLISION);
			}
			// Ref: https://community.clickteam.com/threads/59029-Accessing-backdrops-from-extensions
			else if (!callColMaskTestPoint(hoPtr					// colMaskTestPoint in Java/OC/JS
				, rdPtr->itCoord.x - layerOffsetX
				, rdPtr->itCoord.y - layerOffsetY
				, baseLayer, 0)) {
				rdPtr->pFTW->SetMap(x, y, MAP_OBSTACLE, MapType::TERRAIN);
			}
		}
	}

#ifdef _DEBUG
	auto map = rdPtr->pFTW->OutPutMapStr(MapType::TERRAIN);
#endif // _DEBUG

	return TRUE;
}

long WINAPI DLLExport OnSetMapByCollision(LPRDATA rdPtr, long param1, long param2) {
	wstring iterateName = (LPCTSTR)CNC_GetStringParameter(rdPtr);

	return (*rdPtr->pOnItCollisionName) == iterateName;
}

long WINAPI DLLExport OnPathFound(LPRDATA rdPtr, long param1, long param2) {
	size_t startX = (size_t)CNC_GetParameter(rdPtr);
	size_t startY = (size_t)CNC_GetParameter(rdPtr);

	size_t destinationX = (size_t)CNC_GetParameter(rdPtr);
	size_t destinationY = (size_t)CNC_GetParameter(rdPtr);

	bool diagonal = (bool)CNC_GetParameter(rdPtr);
	bool checkDiagonalCorner = (bool)CNC_GetParameter(rdPtr);

	bool forceFind=(bool)CNC_GetParameter(rdPtr);
	bool useRealCoord = (bool)CNC_GetParameter(rdPtr);

	wstring saveName = (LPCWSTR)CNC_GetStringParameter(rdPtr);

	RetIfMapInvalid(FALSE);

	FindPath(rdPtr, Coord{ startX ,startY }, Coord{ destinationX ,destinationY }, diagonal, checkDiagonalCorner, forceFind, useRealCoord, saveName);

#ifdef _DEBUG
	auto map = rdPtr->pFTW->OutPutMapStr();
#endif // _DEBUG

	return rdPtr->pFTW->GetPathValidity();
}

long WINAPI DLLExport PathAvailable(LPRDATA rdPtr, long param1, long param2) {
	wstring pathName = (LPCWSTR)CNC_GetStringParameter(rdPtr);
	RetIfMapInvalid(FALSE);

	return rdPtr->pFTW->GetPathValidity(&pathName);
}

long WINAPI DLLExport OnIteratePath(LPRDATA rdPtr, long param1, long param2) {
	wstring iterateName = (LPCTSTR)CNC_GetStringParameter(rdPtr);

	return (*rdPtr->pOnItPathName) == iterateName;
}

long WINAPI DLLExport MapAvailable(LPRDATA rdPtr, long param1, long param2) {
	RetIfMapInvalid(FALSE);

	return TRUE;
}

long WINAPI DLLExport CheckMapCostAtPoint(LPRDATA rdPtr, long param1, long param2) {
	size_t x = (size_t)CNC_GetParameter(rdPtr);
	size_t y = (size_t)CNC_GetParameter(rdPtr);

	int cost = (int)CNC_GetParameter(rdPtr);
	MapType type = (MapType)CNC_GetParameter(rdPtr);

	bool useRealCoord = (bool)CNC_GetParameter(rdPtr);

	RetIfMapInvalid(FALSE);

	Coord girdCoord = Coord{ x, y };

	if (useRealCoord) {
		girdCoord = rdPtr->pFTW->GetGirdCoord(girdCoord);
	}

	auto& [girdX, girdY] = girdCoord;

	auto mapCost = rdPtr->pFTW->GetMap(girdX, girdY, type);

	if (cost ==-1 && mapCost != MAP_OBSTACLE) {					// Check for path
		return TRUE;
	}
	else if (cost == 65536 && mapCost == MAP_OBSTACLE) {		// Check for obstacle
		return TRUE;
	}
	else if (cost == mapCost) {									// Check accurate cost
		return TRUE;
	}
	else {
		return FALSE;
	}
}

long WINAPI DLLExport ObjectAtGird(LPRDATA rdPtr, long param1, long param2) {
	bool negated = IsNegated(rdPtr);

	short oil = (short)OIL_GetParameter(rdPtr);
	size_t x = (size_t)CNC_GetParameter(rdPtr);
	size_t y = (size_t)CNC_GetParameter(rdPtr);

	RetIfMapInvalid(FALSE);

	return rdPtr->pSelect->FilterObjects(rdPtr, oil, negated, [&](LPRDATA rdPtr, LPRO object)->bool {
		if (object->roHo.hoX < 0 || object->roHo.hoY < 0) {
			return false;
		}
		else {
			return Coord{ x,y } == rdPtr->pFTW->GetGirdCoord(Coord{ (size_t)object->roHo.hoX, (size_t)object->roHo.hoY });
		}
		});
}

long WINAPI DLLExport ObjectAtObstacle(LPRDATA rdPtr, long param1, long param2) {
	bool negated = IsNegated(rdPtr);

	short oil = (short)OIL_GetParameter(rdPtr);
	MapType type = (MapType)CNC_GetParameter(rdPtr);

	RetIfMapInvalid(FALSE);

	return rdPtr->pSelect->FilterObjects(rdPtr, oil, negated, [&](LPRDATA rdPtr, LPRO object)->bool {
		if (object->roHo.hoX < 0 || object->roHo.hoY < 0) {
			return false;
		}
		else {
			auto [girdX, girdY] = rdPtr->pFTW->GetGirdCoord(Coord{ (size_t)object->roHo.hoX, (size_t)object->roHo.hoY });

			return rdPtr->pFTW->GetMap(girdX, girdY, type) == MAP_OBSTACLE;
		}
		});
}

long WINAPI DLLExport ObjectAtCoord(LPRDATA rdPtr, long param1, long param2) {
	bool negated = IsNegated(rdPtr);

	short oil = (short)OIL_GetParameter(rdPtr);
	int x = (int)CNC_GetParameter(rdPtr);
	int y = (int)CNC_GetParameter(rdPtr);

	RetIfMapInvalid(FALSE);

	return rdPtr->pSelect->FilterObjects(rdPtr, oil, negated, [&](LPRDATA rdPtr, LPRO object)->bool {
		return object->roHo.hoX == x && object->roHo.hoY == y;
		});
}

// ============================================================================
//
// ACTIONS ROUTINES
// 
// ============================================================================

short WINAPI DLLExport SetMap(LPRDATA rdPtr, long param1, long param2) {
	size_t x = (size_t)CNC_GetParameter(rdPtr);
	size_t y = (size_t)CNC_GetParameter(rdPtr);

	BYTE cost = (BYTE)CNC_GetParameter(rdPtr);
	MapType type = (MapType)CNC_GetParameter(rdPtr);

	bool useRealCoord = (bool)CNC_GetParameter(rdPtr);
	bool useIterateCoord = (bool)CNC_GetParameter(rdPtr);

	RetIfMapInvalid(0);

	Coord girdCoord = Coord{ x, y };

	if (useIterateCoord) {
		girdCoord = rdPtr->pFTW->GetGirdCoord(rdPtr->itCoord);
	}
	else if (useRealCoord) {
		girdCoord = rdPtr->pFTW->GetGirdCoord(girdCoord);
	}

	auto& [girdX, girdY] = girdCoord;

	rdPtr->pFTW->SetMap(girdX, girdY, cost, type);

	return 0;
}

short WINAPI DLLExport SetMapByObject(LPRDATA rdPtr, long param1, long param2) {
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);
	BYTE cost = (BYTE)CNC_GetParameter(rdPtr);
	MapType type = (MapType)CNC_GetParameter(rdPtr);

	RetIfMapInvalid(0);

	auto [girdX, girdY] = rdPtr->pFTW->GetGirdCoord(Coord{ (size_t)object->roHo.hoX, (size_t)object->roHo.hoY });
	rdPtr->pFTW->SetMap(girdX, girdY, cost, type);

	return 0;
}

short WINAPI DLLExport ClearMap(LPRDATA rdPtr, long param1, long param2) {
	BYTE cost = (BYTE)CNC_GetParameter(rdPtr);
	MapType type = (MapType)CNC_GetParameter(rdPtr);

	RetIfMapInvalid(0);

	rdPtr->pFTW->ClearMap(type, cost);

	return 0;
}

short WINAPI DLLExport Continue(LPRDATA rdPtr, long param1, long param2) {
	return 0;		// Force fusion to evaluate conditions, as empty events will be skipped
}

short WINAPI DLLExport IteratePath(LPRDATA rdPtr, long param1, long param2) {
	wstring pathName = (LPCWSTR)CNC_GetStringParameter(rdPtr);
	bool realCoord = (bool)CNC_GetIntParameter(rdPtr);

	*rdPtr->pOnItPathName = (LPCTSTR)CNC_GetStringParameter(rdPtr);

	RetIfMapInvalid(0);

	wstring* pPathName = pathName == L"" ? nullptr : &pathName;

	if (!rdPtr->pFTW->GetPathValidity(pPathName)) {
		return 0;
	}
	rdPtr->itIndex = 0;
	size_t totapStep = rdPtr->pFTW->GetDistance(pPathName);
	for (size_t step = 0; step < totapStep; step++) {
		auto coord = Coord{ rdPtr->pFTW->GetCoordAtPath(step, CoordType::X, pPathName)
						,rdPtr->pFTW->GetCoordAtPath(step, CoordType::Y, pPathName) };
		rdPtr->itCoord = realCoord ? rdPtr->pFTW->GetRealCoord(coord) : coord;
		rdPtr->itIndex = step;

		CallEvent(ONITERATESTEP);
	}
	return 0;
}

// ============================================================================
//
// EXPRESSIONS ROUTINES
// 
// ============================================================================

long WINAPI DLLExport GetIterateX(LPRDATA rdPtr, long param1) {
	return rdPtr->itCoord.x;
}
 
long WINAPI DLLExport GetIterateY(LPRDATA rdPtr, long param1) {
	return rdPtr->itCoord.y;
}

long WINAPI DLLExport GetIterateIndex(LPRDATA rdPtr, long param1) {
	return rdPtr->itIndex;
}

long WINAPI DLLExport GetStep(LPRDATA rdPtr, long param1) {
	size_t startX = (size_t)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	size_t startY = (size_t)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);

	size_t destinationX = (size_t)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	size_t destinationY = (size_t)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);

	bool diagonal = (bool)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	bool checkDiagonalCorner = (bool)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);

	bool forceFind = (bool)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	bool useRealCoord = (bool)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);

	wstring saveName = (LPCWSTR)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_STRING);

	RetIfMapInvalid(STEP_UNREACHABLE);

	FindPath(rdPtr, Coord{ startX ,startY }, Coord{ destinationX ,destinationY }, diagonal, checkDiagonalCorner, forceFind, useRealCoord, saveName);

#ifdef _DEBUG
	auto map = rdPtr->pFTW->OutPutMapStr();
#endif // _DEBUG

	return rdPtr->pFTW->GetDistance();
}

long WINAPI DLLExport GetStepOfPath(LPRDATA rdPtr, long param1) {
	wstring pathName = (LPCWSTR)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_STRING);

	RetIfMapInvalid(STEP_UNREACHABLE);

	wstring* pPathName = pathName == L"" ? nullptr : &pathName;

	return rdPtr->pFTW->GetDistance(pPathName);
}

long WINAPI DLLExport GetStepCoordOfPath(LPRDATA rdPtr, long param1) {
	wstring pathName = (LPCWSTR)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_STRING);
	size_t step = (size_t)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	CoordType type = (CoordType)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);

	RetIfMapInvalid(COORD_INVALID);

	wstring* pPathName = pathName == L"" ? nullptr : &pathName;

	return rdPtr->pFTW->GetCoordAtPath(step, type, pPathName);
}

long WINAPI DLLExport GetGirdCoord(LPRDATA rdPtr, long param1) {
	size_t coord = (size_t)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);

	RetIfMapInvalid(COORD_INVALID);

	return rdPtr->pFTW->GetGirdCoord(Coord{ coord ,0 }).x;
}

long WINAPI DLLExport GetRealCoord(LPRDATA rdPtr, long param1) {
	size_t coord = (size_t)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);

	RetIfMapInvalid(REAL_INVALID);

	return rdPtr->pFTW->GetRealCoord(Coord{ coord ,0 }).x;
}

long WINAPI DLLExport GetMapCost(LPRDATA rdPtr, long param1) {
	size_t x = (size_t)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	size_t y = (size_t)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);

	bool useRealCoord = (bool)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	MapType type = (MapType)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);

	RetIfMapInvalid(MAP_OBSTACLE);

	Coord girdCoord = Coord{ x, y };

	if (useRealCoord) {
		girdCoord = rdPtr->pFTW->GetGirdCoord(girdCoord);
	}

	auto& [girdX, girdY] = girdCoord;

	return rdPtr->pFTW->GetMap(girdX, girdY, type);
}

long WINAPI DLLExport GetMapBase64(LPRDATA rdPtr, long param1) {
	*rdPtr->pMapBase64Str = (rdPtr->pFTW == nullptr) ? L"InvalidMap" : rdPtr->pFTW->GetMap();

	//Setting the HOF_STRING flag lets MMF know that you are a string.
	rdPtr->rHo.hoFlags |= HOF_STRING;

	//This returns a pointer to the string for MMF.
	return (long)(*rdPtr->pMapBase64Str).c_str();
}

long WINAPI DLLExport GetMapStr(LPRDATA rdPtr, long param1) {
	MapType type = (MapType)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	bool showPath = (bool)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);

	wstring pathName = (LPCWSTR)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_STRING);

	wstring* pPathName = pathName == L"" ? nullptr : &pathName;

	*rdPtr->pMapStr = (rdPtr->pFTW == nullptr) ? L"InvalidMap" : rdPtr->pFTW->OutPutMapStr(type, showPath, pPathName);

	//Setting the HOF_STRING flag lets MMF know that you are a string.
	rdPtr->rHo.hoFlags |= HOF_STRING;

	//This returns a pointer to the string for MMF.
	return (long)(*rdPtr->pMapStr).c_str();
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
			SetMapBySize,
			SetMapByBase64,
			SetMapByCollision,
			OnSetMapByCollision,
			
			OnPathFound,
			PathAvailable,
			OnIteratePath,

			MapAvailable,
			CheckMapCostAtPoint,

			ObjectAtGird,
			ObjectAtObstacle,
			ObjectAtCoord,

			SetMapByPicture,

			0
			};
	
short (WINAPI * ActionJumps[])(LPRDATA rdPtr, long param1, long param2) =
			{
			SetMap,
			Continue,

			IteratePath,

			SetMapByObject,
			ClearMap,

			0
			};

long (WINAPI * ExpressionJumps[])(LPRDATA rdPtr, long param) = 
			{     
			GetIterateX,
			GetIterateY,

			GetStep,
			GetStepOfPath,
			GetStepCoordOfPath,

			GetGirdCoord,
			GetRealCoord,

			GetIterateIndex,
			
			GetMapCost,
			GetMapBase64,
			GetMapStr,

			0
			};