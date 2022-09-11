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
		IDMN_CONDITION_VO, M_CONDITION_VO, CND_CONDITION_VO, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 0,
		IDMN_CONDITION_VP, M_CONDITION_VP, CND_CONDITION_VP, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 0,
		IDMN_CONDITION_VL, M_CONDITION_VL, CND_CONDITION_VL, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 0,
		IDMN_CONDITION_VF, M_CONDITION_VF, CND_CONDITION_VF, EVFLAGS_ALWAYS | EVFLAGS_NOTABLE, 0,
		
		IDMN_CONDITION_OVF, M_CONDITION_OVF, CND_CONDITION_OVF, 0, 1, PARAM_EXPSTRING, M_FILEPATH,
		};

// Definitions of parameters for each action
short actionsInfos[]=
		{
		IDMN_ACTION_OV, M_ACTION_OV, ACT_ACTION_OV,	0, 2, PARAM_EXPSTRING, PARAM_EXPSTRING, M_FILEPATH, M_KEY,
		IDMN_ACTION_CV, M_ACTION_CV, ACT_ACTION_CV,	0, 0,
		IDMN_ACTION_PLAYV, M_ACTION_PLAYV, ACT_ACTION_PLAYV,	0, 0,
		IDMN_ACTION_PAUSEV, M_ACTION_PAUSEV, ACT_ACTION_PAUSEV,	0, 0,

		IDMN_ACTION_SV, M_ACTION_SV, ACT_ACTION_SV,	0, 1, PARAM_EXPRESSION, M_VOLUME,
		IDMN_ACTION_SL, M_ACTION_SL, ACT_ACTION_SL,	0, 1, PARAM_EXPRESSION, M_LOOP,

		IDMN_ACTION_SP, M_ACTION_SP, ACT_ACTION_SP,	0, 1, PARAM_EXPRESSION, M_POSITION,
		};

// Definitions of parameters for each expression
short expressionsInfos[]=
		{
		IDMN_EXPRESSION_GVN, M_EXPRESSION_GVN, EXP_EXPRESSION_GVN, EXPFLAG_STRING, 0,
		IDMN_EXPRESSION_GVP, M_EXPRESSION_GVP, EXP_EXPRESSION_GVP, 0, 0,
		IDMN_EXPRESSION_GVD, M_EXPRESSION_GVD, EXP_EXPRESSION_GVD, 0, 0,

		IDMN_EXPRESSION_GV, M_EXPRESSION_GV, EXP_EXPRESSION_GV, 0, 0,

		IDMN_EXPRESSION_GCVFP, M_EXPRESSION_GCVFP, EXP_EXPRESSION_GCVFP, 0, 1, EXPPARAM_LONG, M_HWA,
		IDMN_EXPRESSION_GGVFP, M_EXPRESSION_GGVFP, EXP_EXPRESSION_GGVFP, 0, 2, EXPPARAM_LONG, EXPPARAM_LONG, M_POSITION, M_HWA,
		};



// ============================================================================
//
// CONDITION ROUTINES
// 
// ============================================================================

long WINAPI DLLExport Condition_VideoOpen(LPRDATA rdPtr, long param1, long param2) {
	return rdPtr->bOpen;
}

long WINAPI DLLExport Condition_VideoPlay(LPRDATA rdPtr, long param1, long param2) {
	return rdPtr->bPlay && rdPtr->pFFMpeg != nullptr && !rdPtr->pFFMpeg->get_finishState();
}

long WINAPI DLLExport Condition_VideoLoop(LPRDATA rdPtr, long param1, long param2) {
	return rdPtr->bLoop;
}

long WINAPI DLLExport Condition_VideoFinish(LPRDATA rdPtr, long param1, long param2) {
	return  rdPtr->pFFMpeg != nullptr && rdPtr->pFFMpeg->get_finishState();
}

long WINAPI DLLExport Condition_OnVideoFinish(LPRDATA rdPtr, long param1, long param2) {
	std::wstring filePath = GetFullPathNameStr((LPCWSTR)CNC_GetStringParameter(rdPtr));

	return *rdPtr->pFilePath == filePath;
}

// ============================================================================
//
// ACTIONS ROUTINES
// 
// ============================================================================

short WINAPI DLLExport Action_OpenVideo(LPRDATA rdPtr, long param1, long param2) {
	std::wstring filePath = GetFullPathNameStr((LPCWSTR)CNC_GetStringParameter(rdPtr));
	std::wstring key = (LPCWSTR)CNC_GetStringParameter(rdPtr);

	CloseGeneral(rdPtr);

	try {
		if (StrEmpty(key.c_str())) {
			rdPtr->pFFMpeg = new FFMpeg(filePath);
		}
		else {
			rdPtr->pEncrytpt = new Encryption;
			rdPtr->pEncrytpt->GenerateKey(key.c_str());

			rdPtr->pEncrytpt->OpenFile(filePath.c_str());
			rdPtr->pEncrytpt->Decrypt();

			rdPtr->pFFMpeg = new FFMpeg(rdPtr->pEncrytpt->GetOutputData(), rdPtr->pEncrytpt->GetOutputDataLength());
		}
				
		rdPtr->bOpen = true;
		// TODO auto play
		rdPtr->bPlay = true;

		// TODO在开始播放时刷新
		*rdPtr->pPreviousTimer = std::chrono::steady_clock::now();

		rdPtr->pFFMpeg->set_volume(rdPtr->volume);
		rdPtr->pFFMpeg->set_loop(rdPtr->bLoop);

		BlitVideoFrame(rdPtr, 0, [&](LPSURFACE& pMemSf) {
			rdPtr->rc.rcScaleX = ((float)rdPtr->swidth) / pMemSf->GetWidth();
			rdPtr->rc.rcScaleY = ((float)rdPtr->sheight) / pMemSf->GetHeight();
			});

		ReDisplay(rdPtr);
	}
	catch (...) {

	}

	return 0;
}

short WINAPI DLLExport Action_CloseVideo(LPRDATA rdPtr, long param1, long param2) {
	CloseGeneral(rdPtr);

	return 0;
}

short WINAPI DLLExport Action_PlayVideo(LPRDATA rdPtr, long param1, long param2) {
	rdPtr->bPlay = true;

	if (rdPtr->pFFMpeg != nullptr) {
		rdPtr->pFFMpeg->set_pause(false);
	}

	return 0;
}

short WINAPI DLLExport Action_PauseVideo(LPRDATA rdPtr, long param1, long param2) {
	rdPtr->bPlay = false;

	if (rdPtr->pFFMpeg != nullptr) {
		rdPtr->pFFMpeg->set_pause(true);
	}

	return 0;
}

short WINAPI DLLExport Action_SetVolume(LPRDATA rdPtr, long param1, long param2) {
	rdPtr->volume = min(100, max(0, CNC_GetIntParameter(rdPtr)));

	return 0;
}

short WINAPI DLLExport Action_SetLoop(LPRDATA rdPtr, long param1, long param2) {
	rdPtr->bLoop = (bool)CNC_GetIntParameter(rdPtr);

	return 0;
}

short WINAPI DLLExport Action_SetPosition(LPRDATA rdPtr, long param1, long param2) {
	size_t ms = (size_t)CNC_GetIntParameter(rdPtr);

	if (!rdPtr->bOpen) {
		return 0;
	}

	rdPtr->pFFMpeg->set_videoPosition(ms);

	if (!rdPtr->bPlay) {
		BlitVideoFrame(rdPtr, ms, [&](LPSURFACE& pMemSf) {
			rdPtr->rc.rcScaleX = ((float)rdPtr->swidth) / pMemSf->GetWidth();
			rdPtr->rc.rcScaleY = ((float)rdPtr->sheight) / pMemSf->GetHeight();
			});
	}

	ReDisplay(rdPtr);

	return 0;
}

// ============================================================================
//
// EXPRESSIONS ROUTINES
// 
// ============================================================================

long WINAPI DLLExport Expression_GetVideoName(LPRDATA rdPtr, long param1) {
	//Setting the HOF_STRING flag lets MMF know that you are a string.
	rdPtr->rHo.hoFlags |= HOF_STRING;

	//This returns a pointer to the string for MMF.
	return (long)rdPtr->pFilePath->c_str();
}

long WINAPI DLLExport Expression_GetVideoPosition(LPRDATA rdPtr, long param1) {
	return rdPtr->pFFMpeg != nullptr ? (long)rdPtr->pFFMpeg->get_videoPosition() : -1;
}

long WINAPI DLLExport Expression_GetVideoDuration(LPRDATA rdPtr, long param1) {
	return rdPtr->pFFMpeg != nullptr ? (long)rdPtr->pFFMpeg->get_videoDuration() : -1;
}

long WINAPI DLLExport Expression_GetVolume(LPRDATA rdPtr, long param1) {
	return rdPtr->volume;
}

long WINAPI DLLExport Expression_GetCurrentVideoFramePointer(LPRDATA rdPtr, long param1) {
	bool bHwa = (bool)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);

	if (rdPtr->pMemSf == nullptr) {
		return 0;
	}

	if (!bHwa) {
		return ConvertToLong(rdPtr->pMemSf);
	}
	else {
		delete rdPtr->pHwaSf;
		rdPtr->pHwaSf = nullptr;

		rdPtr->pHwaSf = ConvertHWATexture(rdPtr, rdPtr->pMemSf);

		return ConvertToLong(rdPtr->pHwaSf);
	}
}

long WINAPI DLLExport Expression_GetGrabbedVideoFramePointer(LPRDATA rdPtr,long param1) {
	size_t ms = (size_t)CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	bool bHwa = (bool)CNC_GetNextExpressionParameter(rdPtr, param1, TYPE_INT);

	if (!rdPtr->bOpen) {
		return 0;
	}

	BlitVideoFrame(rdPtr, ms, [&](LPSURFACE& pMemSf) {
		delete rdPtr->pGrabbedFrame;
		rdPtr->pGrabbedFrame = nullptr;

		if (bHwa) {
			if (rdPtr->pGrabbedFrame == nullptr) {
				rdPtr->pGrabbedFrame = CreateHWASurface(rdPtr, 32, pMemSf->GetWidth(), pMemSf->GetHeight(), ST_HWA_ROMTEXTURE);
				rdPtr->pGrabbedFrame->CreateAlpha();
			}

			pMemSf->Blit(*rdPtr->pGrabbedFrame);
		}
		else {
			if (rdPtr->pGrabbedFrame == nullptr) {
				rdPtr->pGrabbedFrame = CreateSurface(32, pMemSf->GetWidth(), pMemSf->GetHeight());
			}
		
			pMemSf->Blit(*rdPtr->pGrabbedFrame);
		}
		});
	
	return ConvertToLong(rdPtr->pGrabbedFrame);
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
			Condition_VideoOpen,
			Condition_VideoPlay,
			Condition_VideoLoop,
			Condition_VideoFinish,

			Condition_OnVideoFinish,

			0
			};
	
short (WINAPI * ActionJumps[])(LPRDATA rdPtr, long param1, long param2) =
			{
			Action_OpenVideo,
			Action_CloseVideo,
			Action_PlayVideo,
			Action_PauseVideo,

			Action_SetVolume,			
			Action_SetLoop,
			
			Action_SetPosition,

			0
			};

long (WINAPI * ExpressionJumps[])(LPRDATA rdPtr, long param) = 
			{     
			Expression_GetVideoName,
			Expression_GetVideoPosition,
			Expression_GetVideoDuration,
			
			Expression_GetVolume,

			Expression_GetCurrentVideoFramePointer,
			Expression_GetGrabbedVideoFramePointer,

			0
			};