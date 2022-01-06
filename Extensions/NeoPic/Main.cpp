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
		IDMN_ACTION_LFF, M_ACTION_LFF,	ACT_ACTION_LFF,	0, 2,PARAM_EXPSTRING,PARAM_EXPSTRING,M_ACTION_FILENAME,M_ACTION_KEY,
		IDMN_ACTION_LFL, M_ACTION_LFL,	ACT_ACTION_LFL,	0, 3,PARAM_OBJECT,PARAM_EXPSTRING,PARAM_EXPSTRING,M_ACTION_OBJECT,M_ACTION_FILENAME,M_ACTION_KEY,
		
		IDMN_ACTION_RL, M_ACTION_RL,	ACT_ACTION_RL,	0, 0,
		IDMN_ACTION_EL, M_ACTION_EL,	ACT_ACTION_EL,	0, 1,PARAM_EXPSTRING,M_ACTION_FILENAME,
		IDMN_ACTION_UL, M_ACTION_UL,	ACT_ACTION_UL,	0, 2,PARAM_EXPSTRING,PARAM_EXPSTRING,M_ACTION_FILENAME,M_ACTION_KEY,
		
		IDMN_ACTION_SH, M_ACTION_SH,	ACT_ACTION_SH,	0, 3,PARAM_EXPRESSION,PARAM_EXPRESSION,PARAM_EXPRESSION,M_ACTION_HOTSPOT,M_ACTION_HOTSPOT_X,M_ACTION_HOTSPOT_Y,

		IDMN_ACTION_Z, M_ACTION_Z,	ACT_ACTION_Z,	0, 2,PARAM_EXPRESSION,PARAM_EXPRESSION,M_ACTION_Z_XSCALE,M_ACTION_Z_YSCALE,

		IDMN_ACTION_R, M_ACTION_R,	ACT_ACTION_R,	0, 1,PARAM_EXPRESSION,M_ACTION_A,

		IDMN_ACTION_US, M_ACTION_US,	ACT_ACTION_US,	0, 0,
		IDMN_ACTION_RC, M_ACTION_RC,	ACT_ACTION_RC,	0, 0,

		IDMN_ACTION_S, M_ACTION_S,	ACT_ACTION_S,	0, 2,PARAM_EXPRESSION,PARAM_EXPRESSION,M_ACTION_S_WIDTH,M_ACTION_S_HEIGHT,

		IDMN_ACTION_AB, M_ACTION_AB,	ACT_ACTION_AB,	0, 1,PARAM_PASTE,0,
		IDMN_ACTION_UC, M_ACTION_UC,	ACT_ACTION_UC,	0, 0,

		IDMN_ACTION_SC, M_ACTION_SC,	ACT_ACTION_SC,	0, 2,PARAM_EXPRESSION,PARAM_EXPRESSION,M_ACTION_HC,M_ACTION_AUC,
		IDMN_ACTION_SQ, M_ACTION_SQ,	ACT_ACTION_SQ,	0, 1,PARAM_EXPRESSION,M_ACTION_RS,

		IDMN_ACTION_AT, M_ACTION_AT,	ACT_ACTION_AT,	0, 0,
		IDMN_ACTION_O, M_ACTION_O,	ACT_ACTION_O,	0, 3,PARAM_EXPRESSION,PARAM_EXPRESSION,PARAM_EXPRESSION,M_ACTION_XO,M_ACTION_YO,
		M_ACTION_W,

		IDMN_ACTION_LFD, M_ACTION_LFD,	ACT_ACTION_LFD,	0, 2,PARAM_OBJECT,PARAM_EXPRESSION,M_ACTION_OBJECT,M_ACTION_COPYCOEF,

		};

// Definitions of parameters for each expression
short expressionsInfos[]=
		{
		IDMN_EXPRESSION_GHSX, M_EXPRESSION_GHSX, EXP_EXPRESSION_GHSX, 0, 0,
		IDMN_EXPRESSION_GHSY, M_EXPRESSION_GHSY, EXP_EXPRESSION_GHSY, 0, 0,

		IDMN_EXPRESSION_GOW, M_EXPRESSION_GOW, EXP_EXPRESSION_GOW, 0, 0,
		IDMN_EXPRESSION_GOH, M_EXPRESSION_GOH, EXP_EXPRESSION_GOH, 0, 0,

		IDMN_EXPRESSION_GCW, M_EXPRESSION_GCW, EXP_EXPRESSION_GCW, 0, 0,
		IDMN_EXPRESSION_GCH, M_EXPRESSION_GCH, EXP_EXPRESSION_GCH, 0, 0,
		
		IDMN_EXPRESSION_GXZS, M_EXPRESSION_GXZS, EXP_EXPRESSION_GXZS, EXPFLAG_DOUBLE, 0,
		IDMN_EXPRESSION_GYZS, M_EXPRESSION_GYZS, EXP_EXPRESSION_GYZS, EXPFLAG_DOUBLE, 0,

		IDMN_EXPRESSION_GA, M_EXPRESSION_GA, EXP_EXPRESSION_GA, 0, 0,
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

short WINAPI DLLExport LoadFromFile(LPRDATA rdPtr, long param1, long param2) {
	LPCTSTR FilePath = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	LPCTSTR Key = (LPCTSTR)CNC_GetStringParameter(rdPtr);

	LoadFromFile(rdPtr, FilePath, Key);

	return 0;
}

short WINAPI DLLExport LoadFromLib(LPRDATA rdPtr, long param1, long param2) {
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);

	LPCTSTR FilePath = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	LPCTSTR Key = (LPCTSTR)CNC_GetStringParameter(rdPtr);

	LoadFromLib(rdPtr, object, FilePath, Key);

	return 0;
}

short WINAPI DLLExport LoadFromDisplay(LPRDATA rdPtr, long param1, long param2) {
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);
	bool UpdateCoef = (bool)CNC_GetIntParameter(rdPtr);

	LoadFromDisplay(rdPtr, object, UpdateCoef);

	return 0;
}

short WINAPI DLLExport ResetLib(LPRDATA rdPtr, long param1, long param2) {
	if(rdPtr->IsLib){
		ResetLib(rdPtr->Lib);
	}

	return 0;
}

short WINAPI DLLExport EraseLib(LPRDATA rdPtr, long param1, long param2) {
	LPCTSTR FilePath = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	if (rdPtr->IsLib) {
		EraseLib(rdPtr->Lib, FilePath);		
	}

	return 0;
}

short WINAPI DLLExport UpdateLib(LPRDATA rdPtr, long param1, long param2) {
	LPCTSTR FilePath = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	LPCTSTR Key = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	
	if (rdPtr->IsLib) {
		EraseLib(rdPtr->Lib, FilePath);
		LoadFromFile(rdPtr, FilePath, Key);
	}

	return 0;
}

short WINAPI DLLExport UpdateSrc(LPRDATA rdPtr, long param1, long param2) {
	if (!rdPtr->IsLib && rdPtr->img->IsValid()) {
		//rdPtr->src->Delete();
		//rdPtr->src->Clone(*rdPtr->img);

		//rdPtr->HotSpot = rdPtr->ImgHotSpot;
		
	}

	return 0;
}
short WINAPI DLLExport RestoreCur(LPRDATA rdPtr, long param1, long param2) {
	if (!rdPtr->IsLib && rdPtr->src->IsValid()) {
		//rdPtr->ImgHotSpot = rdPtr->HotSpot;

		//rdPtr->img->Delete();
		//rdPtr->img->Clone(*rdPtr->src);
	}

	return 0;
}

short WINAPI DLLExport SetHotSpot(LPRDATA rdPtr, long param1, long param2) {
	HotSpotPos Pos = (HotSpotPos)CNC_GetIntParameter(rdPtr);

	int X = (int)CNC_GetIntParameter(rdPtr);
	int Y = (int)CNC_GetIntParameter(rdPtr);
	
	UpdateHotSpot(rdPtr, Pos, X, Y);
	rdPtr->ImgHotSpot = rdPtr->HotSpot;
	
	return 0;
}

short WINAPI DLLExport Zoom(LPRDATA rdPtr, long param1, long param2) {
	float XScale = GetFloatParam(rdPtr);
	float YScale = GetFloatParam(rdPtr);
	
	if (!rdPtr->IsLib && rdPtr->src->IsValid()) {
		Zoom(rdPtr, XScale, YScale);

		ReDisplay(rdPtr);
	}	

	return 0;
}

short WINAPI DLLExport Rotate(LPRDATA rdPtr, long param1, long param2) {
	int Angle = (int)CNC_GetIntParameter(rdPtr);
	Angle = Angle % 360;
	
	if (!rdPtr->IsLib && rdPtr->src->IsValid()) {
		Rotate(rdPtr, Angle);

		ReDisplay(rdPtr);
	}

	return 0;
}

short WINAPI DLLExport Stretch(LPRDATA rdPtr, long param1, long param2) {
	int Width = (int)CNC_GetIntParameter(rdPtr);
	int Height = (int)CNC_GetIntParameter(rdPtr);

	float XScale = (1.0f * Width/ rdPtr->src->GetWidth());
	float YScale = (1.0f * Height / rdPtr->src->GetHeight());

	if (!rdPtr->IsLib && rdPtr->src->IsValid()) {
		Zoom(rdPtr, XScale, YScale);

		ReDisplay(rdPtr);
	}

	return 0;
}

short WINAPI DLLExport AddBackdrop(LPRDATA rdPtr, long param1, long param2) {
	int nObstacleType = ((LPEVP)param1)->evp.evpW.evpW0;
	
	UpdateImg(rdPtr);

	if (!rdPtr->IsLib && rdPtr->img->IsValid()) {
		AddBackdrop(rdPtr, rdPtr->img,
			rdPtr->rHo.hoX - rdPtr->rHo.hoAdRunHeader->rhWindowX - rdPtr->ImgHotSpot.x,
			rdPtr->rHo.hoY - rdPtr->rHo.hoAdRunHeader->rhWindowY - rdPtr->ImgHotSpot.y,
			rdPtr->rs.rsEffect, rdPtr->rs.rsEffectParam, nObstacleType, rdPtr->rs.rsLayer);
	}

	return 0;
}
short WINAPI DLLExport UpdateCollision(LPRDATA rdPtr, long param1, long param2) {
	UpdateImg(rdPtr);

	return 0;
}

short WINAPI DLLExport SetCollision(LPRDATA rdPtr, long param1, long param2) {
	bool Collision = (bool)CNC_GetIntParameter(rdPtr);
	bool AutoUpdateCollision = (bool)CNC_GetIntParameter(rdPtr);

	rdPtr->Collision = Collision;
	rdPtr->AutoUpdateCollision = AutoUpdateCollision;

	FreeColMask(rdPtr->pColMask);	

	return 0;
}

short WINAPI DLLExport SetQuality(LPRDATA rdPtr, long param1, long param2) {
	bool Quality = (bool)CNC_GetIntParameter(rdPtr);

	rdPtr->StretchQuality = Quality;

	UpdateImg(rdPtr, true);

	return 0;
}

short WINAPI DLLExport AffineTrans(LPRDATA rdPtr, long param1, long param2) {
	bool Quality = (bool)CNC_GetIntParameter(rdPtr);

	ATArray A = { 1,2,3,4,5,6,7,8,9 };

	//Save Src
	LPSURFACE Trans = nullptr;

	if (!rdPtr->FromLib) {
		LPSURFACE Trans = rdPtr->src;
	}

	rdPtr->FromLib = false;

	//Affine Transformation
	//Recreate a surface and transform Src to it.
	AffineTransformation(rdPtr->src, A, -1);

	//Release Old Src
	delete Trans;

	//Update img
	NewImg(rdPtr);

	ReDisplay(rdPtr);

	return 0;
}

short WINAPI DLLExport Offset(LPRDATA rdPtr, long param1, long param2) {
	int XOffset = (int)CNC_GetIntParameter(rdPtr);
	int YOffset = (int)CNC_GetIntParameter(rdPtr);

	bool Wrap = (bool)CNC_GetIntParameter(rdPtr);

	rdPtr->Offset = { XOffset ,YOffset, Wrap };

	////Save Src
	//LPSURFACE Trans = nullptr;

	//if (!rdPtr->FromLib) {
	//	LPSURFACE Trans = rdPtr->src;
	//}

	//rdPtr->FromLib = false;

	//Offset(rdPtr->src, XOffset, YOffset, Wrap);

	////Release Old Src
	//delete Trans;

	//Update img
	//NewImg(rdPtr);

	ReDisplay(rdPtr);

	return 0;
}
// ============================================================================
//
// EXPRESSIONS ROUTINES
// 
// ============================================================================

long WINAPI DLLExport GetHotSpotX(LPRDATA rdPtr, long param1) {
	return rdPtr->HotSpot.x;
}
long WINAPI DLLExport GetHotSpotY(LPRDATA rdPtr, long param1) {
	return rdPtr->HotSpot.y;
}

long WINAPI DLLExport GetOriginalWidth(LPRDATA rdPtr, long param1) {
	return rdPtr->src->IsValid() ? rdPtr->src->GetWidth() : -1;
}
long WINAPI DLLExport GetOriginalHeight(LPRDATA rdPtr, long param1) {
	return rdPtr->src->IsValid() ? rdPtr->src->GetHeight() : -1;
}

long WINAPI DLLExport GetCurrentWidth(LPRDATA rdPtr, long param1) {
	return rdPtr->img->IsValid() ? rdPtr->img->GetWidth() : -1;
}
long WINAPI DLLExport GetCurrentHeight(LPRDATA rdPtr, long param1) {
	return rdPtr->img->IsValid() ? rdPtr->img->GetHeight() : -1;
}

long WINAPI DLLExport GetXZoomScale(LPRDATA rdPtr, long param1) {
	return ReturnFloat(rdPtr->img->IsValid() ? rdPtr->ZoomScale.XScale : -1);
}
long WINAPI DLLExport GetYZoomScale(LPRDATA rdPtr, long param1) {
	return ReturnFloat(rdPtr->img->IsValid() ? rdPtr->ZoomScale.YScale : -1);
}

long WINAPI DLLExport GetAngle(LPRDATA rdPtr, long param1) {
	return rdPtr->img->IsValid() ? rdPtr->Angle : -1;
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
			LoadFromFile,
			LoadFromLib,

			ResetLib,
			EraseLib,
			UpdateLib,

			SetHotSpot,
			
			Zoom,
			Rotate,

			UpdateSrc,
			RestoreCur,

			Stretch,

			AddBackdrop,
			UpdateCollision,

			SetCollision,
			SetQuality,

			AffineTrans,
			Offset,

			LoadFromDisplay,

			0
			};

long (WINAPI * ExpressionJumps[])(LPRDATA rdPtr, long param) = 
			{     
			GetHotSpotX,
			GetHotSpotY,

			GetOriginalWidth,
			GetOriginalHeight,

			GetCurrentWidth,
			GetCurrentHeight,

			GetXZoomScale,
			GetYZoomScale,

			GetAngle,

			0
			};