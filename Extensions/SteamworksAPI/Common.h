#ifndef COMMON_H
#define COMMON_H

#if defined(_DEBUG) && defined(WIN32)
	#define	_CRTDBG_MAP_ALLOC	1
#endif

#define	IN_EXT_VERSION2
#define	COXSDK

// ----------------------------------------------
// VERSION AND BUILD YOUR EXTENSION CAN WORK WITH
// ----------------------------------------------
//#define TGFEXT		// TGF, MMF Standard and MMF Pro
#define	MMFEXT			// MMF Standard and MMF Pro
//#define PROEXT		// MMF Pro only

// Build number of the minimum required version of MMF
#ifdef _UNICODE
#define	MINBUILD	292
#else
#define	MINBUILD	292
#endif


#ifdef _DEBUG
#include	<assert.h>
#endif

//#define _CONSOLE

#ifdef _CONSOLE
#include <iostream>
#endif

//#define _USE_CRTDBG

#ifdef _USE_CRTDBG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

#define NOIMPL_MICROTXN

#ifndef NOIMPL_MICROTXN
// Http lib
// must be here to be compatible with other parts
#define	    CPPHTTPLIB_OPENSSL_SUPPORT
#include	"httplib.h"
#endif

// General includes
#include	"ccxhdr.h"
#include	"Surface.h"

#include	"WindowsCommon.h"
#include	"GeneralDefinition.h"
#include	"SteamUtilities.h"

#include	"Definition.h"

// Specific to this cox
#include	"resource.h"
#include	"main.h"
#include	"TigsExt.hpp"

// My header
#include	"Fusion.h"
#include	"FusionUtilities.h"

#include	"Func.h"

// Globals and Prototypes
extern HINSTANCE hInstLib;
extern short conditionsInfos[];
extern short actionsInfos[];
extern short expressionsInfos[];

long (WINAPI * ConditionJumps[])(LPRDATA rdPtr, long param1, long param2);
short (WINAPI * ActionJumps[])(LPRDATA rdPtr, long param1, long param2);
long (WINAPI * ExpressionJumps[])(LPRDATA rdPtr, long param);

// Used to ensure the MMF version is 1.5, you can safely ignore this
#if defined(MMFEXT)
#define	IS_COMPATIBLE(v) (v->mvGetVersion != NULL && (v->mvGetVersion() & MMFBUILD_MASK) >= MINBUILD && (v->mvGetVersion() & MMFVERSION_MASK) >= MMFVERSION_20 && ((v->mvGetVersion() & MMFVERFLAG_MASK) & MMFVERFLAG_HOME) == 0)
#elif defined(PROEXT)
#define IS_COMPATIBLE(v) (v->mvGetVersion != NULL && (v->mvGetVersion() & MMFBUILD_MASK) >= MINBUILD && (v->mvGetVersion() & MMFVERSION_MASK) >= MMFVERSION_20 && ((v->mvGetVersion() & MMFVERFLAG_MASK) & MMFVERFLAG_PRO) != 0)
#else
#define	IS_COMPATIBLE(v) (v->mvGetVersion != NULL && (v->mvGetVersion() & MMFBUILD_MASK) >= MINBUILD && (v->mvGetVersion() & MMFVERSION_MASK) >= MMFVERSION_20)
#endif

#endif
