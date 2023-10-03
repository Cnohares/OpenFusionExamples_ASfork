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
		IDMN_CONDITION_CP, M_CONDITION_CP, CND_CONDITION_CP, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 2, PARAM_EXPRESSION, PARAM_EXPRESSION, M_ACTION_CHANNEL, M_ACTION_EXCLUSIVE,
		IDMN_CONDITION_NCP, M_CONDITION_NCP, CND_CONDITION_NCP, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 0,
		IDMN_CONDITION_CFC, M_CONDITION_CFC, CND_CONDITION_CFC, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 1, PARAM_EXPRESSION, M_ACTION_CHANNEL,
		IDMN_CONDITION_CPAUSED, M_CONDITION_CPAUSED, CND_CONDITION_CPAUSED, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 2, PARAM_EXPRESSION, PARAM_EXPRESSION, M_ACTION_CHANNEL, M_ACTION_EXCLUSIVE,
		IDMN_CONDITION_ACPAUSED, M_CONDITION_ACPAUSED, CND_CONDITION_ACPAUSED, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 0,
		IDMN_CONDITION_CHNO, M_CONDITION_CHNO, CND_CONDITION_CHNO, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 2, PARAM_EXPRESSION, PARAM_EXPRESSION, M_ACTION_CHANNEL, M_ACTION_EXCLUSIVE,

		};

// Definitions of parameters for each action
short actionsInfos[]=
		{
		IDMN_ACTION_PE, M_ACTION_PE, ACT_ACTION_PE, 0, 5, PARAM_EXPSTRING, PARAM_EXPSTRING, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, M_ACTION_FILENAME, M_ACTION_KEY, M_ACTION_CHANNEL, M_ACTION_LOOP, M_ACTION_FADE,
		IDMN_ACTION_PM, M_ACTION_PM, ACT_ACTION_PM, 0, 5, PARAM_EXPSTRING, PARAM_EXPSTRING, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, M_ACTION_FILENAME, M_ACTION_KEY, M_ACTION_CHANNEL, M_ACTION_LOOP, M_ACTION_FADE,
		IDMN_ACTION_SV, M_ACTION_SV, ACT_ACTION_SV, 0, 3, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, M_ACTION_CHANNEL, M_ACTION_VOLUME, M_ACTION_EXCLUSIVE,

		IDMN_ACTION_SC, M_ACTION_SC, ACT_ACTION_SC, 0, 3, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, M_ACTION_CHANNEL, M_ACTION_FADE, M_ACTION_EXCLUSIVE,
		IDMN_ACTION_PC, M_ACTION_PC, ACT_ACTION_PC, 0, 2, PARAM_EXPRESSION, PARAM_EXPRESSION, M_ACTION_CHANNEL, M_ACTION_EXCLUSIVE,
		IDMN_ACTION_RC, M_ACTION_RC, ACT_ACTION_RC, 0, 2, PARAM_EXPRESSION, PARAM_EXPRESSION, M_ACTION_CHANNEL, M_ACTION_EXCLUSIVE,
		
		IDMN_ACTION_SP, M_ACTION_SP, ACT_ACTION_SP, 0, 2, PARAM_EXPRESSION, PARAM_EXPRESSION, M_ACTION_CHANNEL, M_ACTION_POSITION,
		IDMN_ACTION_SAC, M_ACTION_SAC, ACT_ACTION_SAC, 0, 1, PARAM_EXPRESSION, M_ACTION_FADE,

		IDMN_ACTION_SABL, M_ACTION_SABL, ACT_ACTION_SABL, 0, 3, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPRESSION, M_ACTION_CHANNEL, M_ACTION_START, M_ACTION_END,
		IDMN_ACTION_SMCS, M_ACTION_SMCS, ACT_ACTION_SMCS, 0, 4, PARAM_EXPRESSION, PARAM_EXPRESSION, PARAM_EXPSTRING, PARAM_EXPRESSION, M_ACTION_CHANNEL, M_ACTION_ENABLE, M_ACTION_SCORE, M_ACTION_BASE,

		IDMN_ACTION_LB, M_ACTION_LB, ACT_ACTION_LB, 0, 2, PARAM_EXPSTRING, PARAM_EXPSTRING, M_ACTION_FILENAME, M_ACTION_KEY,
		};

// Definitions of parameters for each expression
short expressionsInfos[]=
		{
		IDMN_EXPRESSION_GV, M_EXPRESSION_GV, EXP_EXPRESSION_GV, 0, 2, EXPPARAM_LONG, EXPPARAM_LONG, M_ACTION_CHANNEL, M_ACTION_EXCLUSIVE,
		IDMN_EXPRESSION_GCS, M_EXPRESSION_GCS, EXP_EXPRESSION_GCS, 0, 2, EXPPARAM_LONG, EXPPARAM_LONG, M_ACTION_CHANNEL, M_ACTION_EXCLUSIVE,
		IDMN_EXPRESSION_GCP, M_EXPRESSION_GCP, EXP_EXPRESSION_GCP, EXPFLAG_DOUBLE, 1, EXPPARAM_LONG, M_ACTION_CHANNEL,
		IDMN_EXPRESSION_GCD, M_EXPRESSION_GCD, EXP_EXPRESSION_GCD, EXPFLAG_DOUBLE, 1, EXPPARAM_LONG, M_ACTION_CHANNEL,
		IDMN_EXPRESSION_GCIDBN, M_EXPRESSION_GCIDBN, EXP_EXPRESSION_GCIDBN, 0, 2, EXPPARAM_STRING, EXPPARAM_LONG, M_ACTION_FILENAME, M_ACTION_EXCLUSIVE,
		IDMN_EXPRESSION_GCNBID, M_EXPRESSION_GCNBID, EXP_EXPRESSION_GCNBID, EXPFLAG_STRING, 1, EXPPARAM_LONG, M_ACTION_CHANNEL,
		IDMN_EXPRESSION_GPFMN, M_EXPRESSION_GPFMN, EXP_EXPRESSION_GPFMN, EXPFLAG_STRING, 3, EXPPARAM_STRING, EXPPARAM_LONG, EXPPARAM_LONG, M_ACTION_FILENAME, M_EXPRESSION_ADDRESS, M_EXPRESSION_SIZE,
		IDMN_EXPRESSION_GBA, M_EXPRESSION_GBA, EXP_EXPRESSION_GBA, 0, 2, EXPPARAM_STRING, EXPPARAM_LONG, M_ACTION_FILENAME, M_EXPRESSION_OFFSET,
		};



// ============================================================================
//
// CONDITION ROUTINES
// 
// ============================================================================

long WINAPI DLLExport Condition_ChannelPlaying(LPRDATA rdPtr, long param1, long param2) {
	const auto channel = (int)CNC_GetParameter(rdPtr);
	const auto bExclusive = (bool)CNC_GetParameter(rdPtr);

	return bExclusive
		? rdPtr->pData->ExclusiveChannelPlaying(channel)
		: rdPtr->pData->MixingChannelPlaying(channel);
}

long WINAPI DLLExport Condition_NoChannelPlaying(LPRDATA rdPtr, long param1, long param2) {
	return !(rdPtr->pData->ExclusiveChannelPlaying() || rdPtr->pData->MixingChannelPlaying());
}

long WINAPI DLLExport Condition_ChannelPaused(LPRDATA rdPtr, long param1, long param2) {
	const auto channel = (int)CNC_GetParameter(rdPtr);
	const auto bExclusive = (bool)CNC_GetParameter(rdPtr);

	return bExclusive
		? rdPtr->pData->ExclusiveChannelPaused(channel)
		: rdPtr->pData->MixingChannelPaused(channel);
}

long WINAPI DLLExport Condition_AllChannelPaused(LPRDATA rdPtr, long param1, long param2) {
	return !(rdPtr->pData->ExclusiveChannelPaused() || rdPtr->pData->MixingChannelPaused());
}

long WINAPI DLLExport Condition_ChannelFadingComplete(LPRDATA rdPtr, long param1, long param2) {
	const auto channel = (int)CNC_GetParameter(rdPtr);

	return rdPtr->pData->ExclusiveChannelFadingState(channel) == MIX_NO_FADING;	
}

long WINAPI DLLExport Condition_ChannelHasNoOutput(LPRDATA rdPtr, long param1, long param2) {
	const auto channel = (int)CNC_GetParameter(rdPtr);
	const auto bExclusive = (bool)CNC_GetParameter(rdPtr);

	// no output -> not playing or paused
	const auto bPlaying = bExclusive
		? rdPtr->pData->ExclusiveChannelPlaying(channel)
		: rdPtr->pData->MixingChannelPaused(channel);

	const auto bPaused = bExclusive
		? rdPtr->pData->ExclusiveChannelPaused(channel)
		: rdPtr->pData->MixingChannelPaused(channel);

	return !bPlaying || bPaused;
}

// ============================================================================
//
// ACTIONS ROUTINES
// 
// ============================================================================

short WINAPI DLLExport Action_PlayExclusive(LPRDATA rdPtr, long param1, long param2) {
	const auto pFilePath = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	const auto pKey = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	const auto channel = (int)CNC_GetIntParameter(rdPtr);
	const auto loops = (int)CNC_GetIntParameter(rdPtr);
	const auto fadeMs = (int)CNC_GetIntParameter(rdPtr);

	rdPtr->pData->PlayExclusive(pFilePath, pKey,
		channel, loops - 1, fadeMs);

	return 0;
}

short WINAPI DLLExport Action_PlayMixing(LPRDATA rdPtr, long param1, long param2) {
	const auto pFilePath = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	const auto pKey = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	const auto channel = (int)CNC_GetIntParameter(rdPtr);
	const auto loops = (int)CNC_GetIntParameter(rdPtr);
	const auto fadeMs = (int)CNC_GetIntParameter(rdPtr);

	rdPtr->pData->PlayMixing(pFilePath, pKey,
		channel, loops - 1, fadeMs);

	return 0;
}

short WINAPI DLLExport Action_SetVolume(LPRDATA rdPtr, long param1, long param2) {
	const auto channel = (int)CNC_GetIntParameter(rdPtr);
	const auto volume = (int)CNC_GetIntParameter(rdPtr);
	const auto bExclusive = (bool)CNC_GetIntParameter(rdPtr);

	bExclusive
		? rdPtr->pData->SetExclusiveVolume(channel, volume)
		: rdPtr->pData->SetMixingVolume(channel, volume);

	return 0;
}

short WINAPI DLLExport Action_StopChannel(LPRDATA rdPtr, long param1, long param2) {
	const auto channel = (int)CNC_GetIntParameter(rdPtr);
	const auto fadeMs = (int)CNC_GetIntParameter(rdPtr);
	const auto bExclusive = (bool)CNC_GetIntParameter(rdPtr);

	bExclusive
		? rdPtr->pData->StopExclusive(channel, fadeMs)
		: rdPtr->pData->StopMixing(channel, fadeMs);

	return 0;
}

short WINAPI DLLExport Action_PauseChannel(LPRDATA rdPtr, long param1, long param2) {
	const auto channel = (int)CNC_GetIntParameter(rdPtr);
	const auto bExclusive = (bool)CNC_GetIntParameter(rdPtr);

	bExclusive
		? rdPtr->pData->PauseExclusive(channel)
		: rdPtr->pData->PauseMixing(channel);

	return 0;
}

short WINAPI DLLExport Action_ResumeChannel(LPRDATA rdPtr, long param1, long param2) {
	const auto channel = (int)CNC_GetIntParameter(rdPtr);
	const auto bExclusive = (bool)CNC_GetIntParameter(rdPtr);

	bExclusive
		? rdPtr->pData->ResumeExclusive(channel)
		: rdPtr->pData->ResumeMixing(channel);

	return 0;
}

short WINAPI DLLExport Action_SetPosition(LPRDATA rdPtr, long param1, long param2) {
	const auto channel = (int)CNC_GetIntParameter(rdPtr);
	const auto position = (double)GetFloatParam(rdPtr);

	rdPtr->pData->SetExclusivePosition(channel, position);

	return 0;
}

short WINAPI DLLExport Action_StopAllChannel(LPRDATA rdPtr, long param1, long param2) {
	const auto fadeMs = (int)CNC_GetIntParameter(rdPtr);

	rdPtr->pData->StopAllExclusive(fadeMs);
	rdPtr->pData->StopAllMixing(fadeMs);

	return 0;
}

short WINAPI DLLExport Action_SetABLoop(LPRDATA rdPtr, long param1, long param2) {
	const auto channel = (int)CNC_GetIntParameter(rdPtr);
	const auto start = (double)GetFloatParam(rdPtr);
	const auto end = (double)GetFloatParam(rdPtr);

	rdPtr->pData->SetExclusiveABLoop(channel, start, end);

	return 0;
}

short WINAPI DLLExport Action_SetMixingChannelScore(LPRDATA rdPtr, long param1, long param2) {
	const auto channel = (int)CNC_GetIntParameter(rdPtr);
	const auto bEnable = (bool)CNC_GetIntParameter(rdPtr);
	const auto pScore = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	const auto base = (int)CNC_GetIntParameter(rdPtr);

	std::wstring score = pScore;
	rdPtr->pData->SetMixingChannelScore(channel, bEnable, MusicScore::GetNote(score), static_cast<float>(base));

	return 0;
}

short WINAPI DLLExport Action_LoadBinary(LPRDATA rdPtr, long param1, long param2) {
	const auto pFilePath = (LPCTSTR)CNC_GetStringParameter(rdPtr);
	const auto pKey = (LPCTSTR)CNC_GetStringParameter(rdPtr);

	rdPtr->pData->binaryData.AddData(pFilePath, pKey);

	return 0;
}

// ============================================================================
//
// EXPRESSIONS ROUTINES
// 
// ============================================================================

long WINAPI DLLExport Expression_GetVolume(LPRDATA rdPtr,long param1) {
	const auto channel = (int)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	const auto bExclusive = (bool)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);

	return bExclusive
		? rdPtr->pData->GetExclusiveVolume(channel)
		: rdPtr->pData->GetMixingVolume(channel);
}

long WINAPI DLLExport Expression_GetChannelState(LPRDATA rdPtr, long param1) {
	const auto channel = (int)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	const auto bExclusive = (bool)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);

	return bExclusive
		? rdPtr->pData->ExclusiveChannelPlaying(channel)
		: rdPtr->pData->MixingChannelPlaying(channel);
}

long WINAPI DLLExport Expression_GetChannelPosition(LPRDATA rdPtr, long param1) {
	const auto channel = (int)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);

	return ReturnFloat(rdPtr->pData->GetExclusivePosition(channel));
}

long WINAPI DLLExport Expression_GetChannelDuration(LPRDATA rdPtr, long param1) {
	const auto channel = (int)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);

	return ReturnFloat(rdPtr->pData->GetExclusiveDuration(channel));
}

long WINAPI DLLExport Expression_GetChannelIDByName(LPRDATA rdPtr, long param1) {
	const auto pFilePath = (LPCWSTR)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_STRING);
	const auto bExclusive = (bool)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);

	return bExclusive
		? rdPtr->pData->GetExclusiveChannelID(pFilePath)
		: rdPtr->pData->GetMixingChannelID(pFilePath);
}

long WINAPI DLLExport Expression_GetChannelNameByID(LPRDATA rdPtr, long param1) {
	const auto channel = (int)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);

	const auto pFileName = rdPtr->pData->GetExclusiveChannelName(channel);
	const auto pRet = pFileName == nullptr
		? Empty_Str
		: pFileName;

	//Setting the HOF_STRING flag lets MMF know that you are a string.
	rdPtr->rHo.hoFlags |= HOF_STRING;

	//This returns a pointer to the string for MMF.
	return (long)pRet;
}

long WINAPI DLLExport Expression_GetPlayFromMemoryName(LPRDATA rdPtr, long param1) {
	const auto pFilePath = (LPCWSTR)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_STRING);
	const auto address = (int)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);
	const auto size = (int)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);

	*rdPtr->pRet = std::format(L"FromMem_{}_{}_{}", pFilePath, address, size);

	//Setting the HOF_STRING flag lets MMF know that you are a string.
	rdPtr->rHo.hoFlags |= HOF_STRING;

	//This returns a pointer to the string for MMF.
	return (long)rdPtr->pRet->c_str();
}

long WINAPI DLLExport Expression_GetBinaryAddress(LPRDATA rdPtr, long param1) {
	const auto pFilePath = (LPCWSTR)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_STRING);
	const auto bOffset = (int)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);

	const auto pData = rdPtr->pData->binaryData.GetAddress(pFilePath);

	return pData != nullptr
		? reinterpret_cast<long>(pData) + bOffset
		: reinterpret_cast<long>(nullptr);
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
			Condition_ChannelPlaying,
			Condition_NoChannelPlaying,
			Condition_ChannelFadingComplete,
			Condition_ChannelPaused,
			Condition_AllChannelPaused,
			Condition_ChannelHasNoOutput,

			0
			};
	
short (WINAPI * ActionJumps[])(LPRDATA rdPtr, long param1, long param2) =
			{
			Action_PlayExclusive,
			Action_PlayMixing,
			Action_SetVolume,

			Action_StopChannel,
			Action_PauseChannel,
			Action_ResumeChannel,

			Action_SetPosition,
			Action_StopAllChannel,

			Action_SetABLoop,
			Action_SetMixingChannelScore,

			Action_LoadBinary,

			0
			};

long (WINAPI * ExpressionJumps[])(LPRDATA rdPtr, long param) = 
			{     
			Expression_GetVolume,
			Expression_GetChannelState,
			Expression_GetChannelPosition,
			Expression_GetChannelDuration,
			Expression_GetChannelIDByName,
			Expression_GetChannelNameByID,
			Expression_GetPlayFromMemoryName,
			Expression_GetBinaryAddress,

			0
			};