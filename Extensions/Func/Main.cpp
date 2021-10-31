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
		IDMN_CONDITION_OF, M_CONDITION_OF, CND_CONDITION_OF, 0, 1, PARAM_EXPSTRING, M_CND_FUNCNAME,
		
		IDMN_CONDITION_FHPA, M_CONDITION_FHPA, CND_CONDITION_FHPA, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 1, PARAM_EXPRESSION, M_EXP_GP,
		IDMN_CONDITION_FHRA, M_CONDITION_FHRA, CND_CONDITION_FHRA, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 1, PARAM_EXPRESSION, M_EXP_GP,
		
		IDMN_CONDITION_FHTP, M_CONDITION_FHTP, CND_CONDITION_FHTP, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 2, PARAM_EXPSTRING, PARAM_EXPSTRING, M_CND_FUNCNAME, M_ACT_PARAMNAME,
		IDMN_CONDITION_CFHTP, M_CONDITION_CFHTP, CND_CONDITION_CFHTP, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 1, PARAM_EXPSTRING, M_CND_FUNCNAME,
		};

// Definitions of parameters for each action
short actionsInfos[]=
		{
		IDMN_ACTION_SR, M_ACTION_SR, ACT_ACTION_SR,	0, 1,PARAM_EXPSTRING, M_ACT_RET,
		IDMN_ACTION_PR, M_ACTION_PR, ACT_ACTION_PR,	0, 1,PARAM_EXPSTRING, M_ACT_RET,

		IDMN_ACTION_CF, M_ACTION_CF, ACT_ACTION_CF,	0, 3,PARAM_EXPSTRING,PARAM_EXPSTRING, PARAM_EXPRESSION, M_CND_FUNCNAME, M_EXP_PARAM, M_ACT_LOOP,
		
		IDMN_ACTION_T, M_ACTION_T, ACT_ACTION_T,	0, 5,PARAM_EXPRESSION,PARAM_EXPSTRING,PARAM_EXPSTRING,PARAM_EXPSTRING,PARAM_EXPSTRING,M_EXP_BOOL, M_CND_FUNCNAME, M_EXP_PARAM, M_CND_FUNCNAME, M_EXP_PARAM,

		IDMN_ACTION_STV, M_ACTION_STV, ACT_ACTION_STV,	0, 3,PARAM_EXPSTRING, PARAM_EXPSTRING, PARAM_EXPSTRING, M_CND_FUNCNAME, M_ACT_PARAMNAME, M_ACT_PARAM,
		IDMN_ACTION_SCTV, M_ACTION_SCTV, ACT_ACTION_SCTV,	0, 2,PARAM_EXPSTRING, PARAM_EXPSTRING, M_ACT_PARAMNAME, M_ACT_PARAM,

		IDMN_ACTION_SAR, M_ACTION_SAR, ACT_ACTION_SAR,	0, 1,PARAM_EXPSTRING, M_ACT_RETA,

		IDMN_ACTION_SLI, M_ACTION_SLI, ACT_ACTION_SLI,	0, 2,PARAM_EXPSTRING, PARAM_EXPRESSION, M_CND_FUNCNAME, M_ACT_LOOPINDEX,
		IDMN_ACTION_SL, M_ACTION_SL, ACT_ACTION_SL,	0, 1, PARAM_EXPSTRING, M_CND_FUNCNAME,

		IDMN_ACTION_PASSRET, M_ACTION_PASSRET, ACT_ACTION_PASSRET,	0, 1,PARAM_EXPSTRING, M_ACT_RET,
		};

// Definitions of parameters for each expression
short expressionsInfos[]=
		{
		//CallFunc
		IDMN_EXPRESSION_RV, M_EXPRESSION_RV, EXP_EXPRESSION_RV, 0, 2, EXPPARAM_STRING, EXPPARAM_STRING,M_CND_FUNCNAME, M_EXP_PARAM,
		IDMN_EXPRESSION_RS, M_EXPRESSION_RS, EXP_EXPRESSION_RS, EXPFLAG_STRING,2,EXPPARAM_STRING, EXPPARAM_STRING,M_CND_FUNCNAME, M_EXP_PARAM,

		//Get Param
		IDMN_EXPRESSION_GVP, M_EXPRESSION_GVP, EXP_EXPRESSION_GVP, 0, 1, EXPPARAM_LONG,M_EXP_GP,
		IDMN_EXPRESSION_GSP, M_EXPRESSION_GSP, EXP_EXPRESSION_GSP, EXPFLAG_STRING, 1, EXPPARAM_LONG,M_EXP_GP,

		//Get Ret
		IDMN_EXPRESSION_GVR, M_EXPRESSION_GVR, EXP_EXPRESSION_GVR, 0, 1, EXPPARAM_LONG,M_EXP_GP,
		IDMN_EXPRESSION_GSR, M_EXPRESSION_GSR, EXP_EXPRESSION_GSR, EXPFLAG_STRING, 1, EXPPARAM_LONG,M_EXP_GP,

		//GetRecursiveIndex
		IDMN_EXPRESSION_GRI, M_EXPRESSION_GRI, EXP_EXPRESSION_GRI, 0, 1,EXPPARAM_STRING,M_CND_FUNCNAME,

		//GetSize
		IDMN_EXPRESSION_GPS, M_EXPRESSION_GPS, EXP_EXPRESSION_GPS, 0, 0,
		IDMN_EXPRESSION_GRS, M_EXPRESSION_GRS, EXP_EXPRESSION_GRS, 0, 0,
		
		//Ternary
		IDMN_EXPRESSION_TRV, M_EXPRESSION_TRV, EXP_EXPRESSION_TRV, 0, 3,EXPPARAM_LONG,EXPPARAM_LONG,EXPPARAM_LONG,M_EXP_BOOL,M_EXP_RETA,M_EXP_RETB,
		IDMN_EXPRESSION_TRS, M_EXPRESSION_TRS, EXP_EXPRESSION_TRS, EXPFLAG_STRING, 3,EXPPARAM_LONG,EXPPARAM_STRING,EXPPARAM_STRING,M_EXP_BOOL,M_EXP_RETA,M_EXP_RETB,

		//Get Temp Param
		IDMN_EXPRESSION_GVTP, M_EXPRESSION_GVTP, EXP_EXPRESSION_GVTP, 0, 2, EXPPARAM_STRING, EXPPARAM_STRING,M_CND_FUNCNAME, M_EXP_TEMPPARAM,
		IDMN_EXPRESSION_GSTP, M_EXPRESSION_GSTP, EXP_EXPRESSION_GSTP, EXPFLAG_STRING,2,EXPPARAM_STRING, EXPPARAM_STRING,M_CND_FUNCNAME, M_EXP_TEMPPARAM,
		
		//Get Current FuncName
		IDMN_EXPRESSION_GCFN, M_EXPRESSION_GCFN, EXP_EXPRESSION_GCFN, EXPFLAG_STRING, 0,

		//Get Current Temp Param
		IDMN_EXPRESSION_GVCTP, M_EXPRESSION_GVCTP, EXP_EXPRESSION_GVCTP, 0, 1, EXPPARAM_STRING,  M_EXP_TEMPPARAM,
		IDMN_EXPRESSION_GSCTP, M_EXPRESSION_GSCTP, EXP_EXPRESSION_GSCTP, EXPFLAG_STRING,1, EXPPARAM_STRING, M_EXP_TEMPPARAM,

		//GetLoopIndex
		IDMN_EXPRESSION_GLI, M_EXPRESSION_GLI, EXP_EXPRESSION_GLI, 0, 1,EXPPARAM_STRING,M_CND_FUNCNAME,

		};



// ============================================================================
//
// CONDITION ROUTINES
// 
// ============================================================================

long WINAPI DLLExport OnFunc(LPRDATA rdPtr, long param1, long param2) {
	LPCTSTR FuncName = (LPCTSTR)CNC_GetStringParameter(rdPtr);

	return StrEqu(FuncName, rdPtr->FuncNameStack->back().c_str()) ? TRUE : FALSE;
}

long WINAPI DLLExport FuncHasReturnAt(LPRDATA rdPtr, long param1, long param2) {
	size_t Pos = (size_t)CNC_GetStringParameter(rdPtr);

	return !rdPtr->FuncReturn->empty()
		&& (Pos == max(Pos, min(Pos, rdPtr->FuncReturn->size() - 1))) ? TRUE : FALSE;
}

long WINAPI DLLExport FuncHasParamAt(LPRDATA rdPtr, long param1, long param2) {
	size_t Pos = (size_t)CNC_GetStringParameter(rdPtr);

	return !rdPtr->FuncParamStack->back().empty()
		&& (Pos == max(Pos, min(Pos, rdPtr->FuncParamStack->back().size() - 1))) ? TRUE : FALSE;
}

long WINAPI DLLExport FuncHasTempParam(LPRDATA rdPtr, long param1, long param2) {
	std::wstring FuncName = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	std::wstring ParamName = (LPCTSTR)CNC_GetStringParameter(rdPtr);

	return HasTempParam(FuncName, ParamName) ? TRUE : FALSE;
}
long WINAPI DLLExport CurerntFuncHasTempParam(LPRDATA rdPtr, long param1, long param2) {
	LPCTSTR ParamName = (LPCTSTR)CNC_GetStringParameter(rdPtr);

	return !rdPtr->FuncNameStack->empty() && HasTempParam(rdPtr->FuncNameStack->back(), ParamName) ? TRUE : FALSE;
}

// ============================================================================
//
// ACTIONS ROUTINES
// 
// ============================================================================

short WINAPI DLLExport SetTempParam(LPRDATA rdPtr, long param1, long param2) {
	std::wstring FuncName = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	std::wstring ParamName = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	std::wstring Param = (LPCTSTR)CNC_GetStringParameter(rdPtr);

	TempParam(FuncName, ParamName) = Param;

	return 0;
}

short WINAPI DLLExport SetCurrentTempParam(LPRDATA rdPtr, long param1, long param2) {
	std::wstring ParamName = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	std::wstring Param = (LPCTSTR)CNC_GetStringParameter(rdPtr);

	TempParam(rdPtr->FuncNameStack->back(), ParamName) = Param;

	return 0;
}

short WINAPI DLLExport PassReturn(LPRDATA rdPtr, long param1, long param2) {
	std::wstring Return = (LPCTSTR)CNC_GetStringParameter(rdPtr);

	return 0;
}

short WINAPI DLLExport SetAllReturn(LPRDATA rdPtr, long param1, long param2) {
	std::wstring Return = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	rdPtr->FuncReturn->clear();
	UpdateReturn(rdPtr, Return);

	return 0;
}

short WINAPI DLLExport SetReturnValue(LPRDATA rdPtr, long param1, long param2) {	
	std::wstring Return = (LPCTSTR)CNC_GetStringParameter(rdPtr);

	rdPtr->FuncReturn->clear();
	rdPtr->FuncReturn->emplace_back(Return);

	return 0;
}

short WINAPI DLLExport PushReturnValue(LPRDATA rdPtr, long param1, long param2) {
	std::wstring Return = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	rdPtr->FuncReturn->emplace_back(Return);
	
	return 0;
}

short WINAPI DLLExport CallFunc(LPRDATA rdPtr, long param1, long param2) {
	std::wstring FuncName = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	std::wstring Param = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	size_t LoopIndex = (size_t)CNC_GetIntParameter(rdPtr);

	(*rdPtr->FuncLoopIndex)[FuncName] = LoopIndex;

	for ((*rdPtr->FuncCurLoopIndex)[FuncName] = 0; 
		(*rdPtr->FuncCurLoopIndex)[FuncName] < LoopIndex; 
		(*rdPtr->FuncCurLoopIndex)[FuncName]++) {
		CallFuncCore(FuncName, Param);
	}

	rdPtr->FuncLoopIndex->erase(FuncName);
	rdPtr->FuncCurLoopIndex->erase(FuncName);

	return 0;
}

short WINAPI DLLExport SetLoopIndex(LPRDATA rdPtr, long param1, long param2) {
	std::wstring FuncName = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	size_t LoopIndex = (size_t)CNC_GetIntParameter(rdPtr);

	if (rdPtr->FuncLoopIndex->count(FuncName) != 0) {
		(*rdPtr->FuncCurLoopIndex)[FuncName] = LoopIndex;
	}

	return 0;
}

short WINAPI DLLExport StopLoop(LPRDATA rdPtr, long param1, long param2) {
	std::wstring FuncName = (LPCTSTR)CNC_GetStringParameter(rdPtr);

	if (rdPtr->FuncLoopIndex->count(FuncName) != 0) {
		(*rdPtr->FuncCurLoopIndex)[FuncName] = (*rdPtr->FuncLoopIndex)[FuncName];
	}

	return 0;
}

short WINAPI DLLExport Ternary(LPRDATA rdPtr, long param1, long param2) {
	bool Result = (bool)CNC_GetIntParameter(rdPtr);
	
	std::wstring FuncNameA = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	std::wstring ParamA = (LPCTSTR)CNC_GetStringParameter(rdPtr);

	std::wstring FuncNameB = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	std::wstring ParamB = (LPCTSTR)CNC_GetStringParameter(rdPtr);

	CallFuncCore(Result ? FuncNameA : FuncNameB, Result ? ParamA : ParamB);	

	return 0;
}

// ============================================================================
//
// EXPRESSIONS ROUTINES
// 
// ============================================================================

long WINAPI DLLExport CallFuncRV(LPRDATA rdPtr,long param1) {
	std::wstring FuncName = (LPCTSTR)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_STRING);
	std::wstring Param = (LPCTSTR)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_STRING);	
	
	CallFuncCore(FuncName, Param);	
	
	if (StrIsNum(Return(0))) {
		return ReturnFloat(std::stof(Return(0)));
	}
	else {
		return 0;
	}
}

long WINAPI DLLExport CallFuncRS(LPRDATA rdPtr,long param1) {
	std::wstring FuncName = (LPCTSTR)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_STRING);
	std::wstring Param = (LPCTSTR)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_STRING);

	CallFuncCore(FuncName, Param);

	//Setting the HOF_STRING flag lets MMF know that you are a string.
	rdPtr->rHo.hoFlags |= HOF_STRING;
	
	//This returns a pointer to the string for MMF.
	return (long)Return(0).c_str();	
}

long WINAPI DLLExport GetParamRV(LPRDATA rdPtr, long param1) {
	size_t Pos = (size_t)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	
	if (!rdPtr->FuncParamStack->back().empty() && (Pos == max(Pos, min(Pos, rdPtr->FuncParamStack->back().size() - 1)))
		&& StrIsNum(GetParam(Pos))) {
		return ReturnFloat(std::stof(GetParam(Pos)));
	}
	else {
		return 0;
	}
}

long WINAPI DLLExport GetParamRS(LPRDATA rdPtr, long param1) {
	size_t Pos = (size_t)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);

	//Setting the HOF_STRING flag lets MMF know that you are a string.
	rdPtr->rHo.hoFlags |= HOF_STRING;

	//This returns a pointer to the string for MMF.
	if (!rdPtr->FuncParamStack->back().empty() && (Pos == max(Pos, min(Pos, rdPtr->FuncParamStack->back().size() - 1)))) {
		return (long)GetParam(Pos).c_str();
	}
	else {
		return (long)Default_Str;
	}
	
}

long WINAPI DLLExport GetTempParamRV(LPRDATA rdPtr, long param1) {
	std::wstring FuncName = (LPCTSTR)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_STRING);
	std::wstring ParamName = (LPCTSTR)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_STRING);
		
	if (HasTempParam(FuncName, ParamName) && StrIsNum(TempParam(FuncName, ParamName))) {
		return ReturnFloat(std::stof(TempParam(FuncName, ParamName)));
	}
	else {
		return 0;
	}
}

long WINAPI DLLExport GetTempParamRS(LPRDATA rdPtr, long param1) {
	std::wstring FuncName = (LPCTSTR)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_STRING);
	std::wstring ParamName = (LPCTSTR)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_STRING);

	//Setting the HOF_STRING flag lets MMF know that you are a string.
	rdPtr->rHo.hoFlags |= HOF_STRING;

	//This returns a pointer to the string for MMF.
	if (HasTempParam(FuncName, ParamName)) {
		return (long)TempParam(FuncName, ParamName).c_str();
	}
	else {
		return (long)Default_Str;
	}
}

long WINAPI DLLExport GetCurrentTempParamRV(LPRDATA rdPtr, long param1) {
	std::wstring ParamName = (LPCTSTR)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_STRING);

	if (HasTempParam(rdPtr->FuncNameStack->back(), ParamName) && StrIsNum(TempParam(rdPtr->FuncNameStack->back(), ParamName))) {
		return ReturnFloat(std::stof(TempParam(rdPtr->FuncNameStack->back(), ParamName)));
	}
	else {
		return 0;
	}
}

long WINAPI DLLExport GetCurrentTempParamRS(LPRDATA rdPtr, long param1) {
	std::wstring ParamName = (LPCTSTR)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_STRING);

	//Setting the HOF_STRING flag lets MMF know that you are a string.
	rdPtr->rHo.hoFlags |= HOF_STRING;

	//This returns a pointer to the string for MMF.
	if (HasTempParam(rdPtr->FuncNameStack->back(), ParamName)) {
		return (long)TempParam(rdPtr->FuncNameStack->back(), ParamName).c_str();
	}
	else {
		return (long)Default_Str;
	}
}

long WINAPI DLLExport GetRetRV(LPRDATA rdPtr, long param1) {
	size_t Pos = (size_t)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	
	if (!rdPtr->FuncReturn->empty() && (Pos == max(Pos, min(Pos, rdPtr->FuncReturn->size() - 1)))
		&& StrIsNum(Return(Pos))) {
		return ReturnFloat(std::stof(Return(Pos)));
	}
	else {
		return 0;
	}
}

long WINAPI DLLExport GetRetRS(LPRDATA rdPtr, long param1) {
	size_t Pos = (size_t)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);

	//Setting the HOF_STRING flag lets MMF know that you are a string.
	rdPtr->rHo.hoFlags |= HOF_STRING;

	//This returns a pointer to the string for MMF.
	if (!rdPtr->FuncReturn->empty() && (Pos == max(Pos, min(Pos, rdPtr->FuncReturn->size() - 1)))) {
		return (long)Return(Pos).c_str();
	}
	else {
		return (long)Default_Str;
	}
}

long WINAPI DLLExport GetRecursiveIndex(LPRDATA rdPtr, long param1) {
	std::wstring FuncName = (LPCTSTR)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_STRING);

	if(rdPtr->RecursiveIndex->count(FuncName)!=0){
		return (*rdPtr->RecursiveIndex)[FuncName];
	}
	else {
		return -1;
	}

	//size_t RecursiveIndex = 0;

	//for (auto& it : *(rdPtr->FuncNameStack)) {
	//	if (it == rdPtr->FuncNameStack->back()) {
	//		RecursiveIndex++;
	//	}
	//}
	//
	//return RecursiveIndex;
}

long WINAPI DLLExport GetParamSize(LPRDATA rdPtr, long param1) {	
	return rdPtr->FuncParamStack->back().size();
}

long WINAPI DLLExport GetRetSize(LPRDATA rdPtr, long param1) {
	return rdPtr->FuncReturn->size();
}

long WINAPI DLLExport TernaryRV(LPRDATA rdPtr,long param1) {
	bool Result = (bool)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);

	long p1 = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_FLOAT);
	float ReturnA = *(float*)&p1;

	long p2 = CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_FLOAT);
	float ReturnB = *(float*)&p2;
		
	return ReturnFloat(Result ? ReturnA : ReturnB);
}

long WINAPI DLLExport TernaryRS(LPRDATA rdPtr, long param1) {
	bool Result = (bool)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);

	std::wstring ReturnA = (LPCTSTR)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_STRING);
	std::wstring ReturnB = (LPCTSTR)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_STRING);

	NewStr(OStr, Result ? ReturnA : ReturnB);

	//Setting the HOF_STRING flag lets MMF know that you are a string.
	rdPtr->rHo.hoFlags |= HOF_STRING;

	//This returns a pointer to the string for MMF.
	return (long)OStr;
}

long WINAPI DLLExport GetCurrentFuncName(LPRDATA rdPtr, long param1) {
	//Setting the HOF_STRING flag lets MMF know that you are a string.
	rdPtr->rHo.hoFlags |= HOF_STRING;

	//This returns a pointer to the string for MMF.
	return (long)rdPtr->FuncNameStack->back().c_str();
}

long WINAPI DLLExport GetLoopIndex(LPRDATA rdPtr, long param1) {
	std::wstring FuncName = (LPCTSTR)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_STRING);

	if (rdPtr->FuncLoopIndex->count(FuncName) != 0) {
		return (*rdPtr->FuncCurLoopIndex)[FuncName];
	}
	else {
		return -1;
	}
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
			OnFunc,

			FuncHasParamAt,
			FuncHasReturnAt,
			
			FuncHasTempParam,
			CurerntFuncHasTempParam,

			0
			};
	
short (WINAPI * ActionJumps[])(LPRDATA rdPtr, long param1, long param2) =
			{
			SetReturnValue,
			PushReturnValue,

			CallFunc,

			Ternary,

			SetTempParam,
			SetCurrentTempParam,

			SetAllReturn,

			SetLoopIndex,
			StopLoop,

			PassReturn,

			0
			};

long (WINAPI * ExpressionJumps[])(LPRDATA rdPtr, long param) = 
			{     
			CallFuncRV,
			CallFuncRS,

			GetParamRV,
			GetParamRS,

			GetRetRV,
			GetRetRS,

			GetRecursiveIndex,

			GetParamSize,
			GetRetSize,

			TernaryRV,
			TernaryRS,

			GetTempParamRV,
			GetTempParamRS,

			GetCurrentFuncName,

			GetCurrentTempParamRV,
			GetCurrentTempParamRS,

			GetLoopIndex,

			0
			};