// Object identifier "NPIC"
#define IDENTIFIER	MAKEID(N,P,I,C)		// REQUIRED: you MUST replace the letters in the MAKEID macro by others
										// and then remove the #pragma message above. If you do not do this, MMF2
										// could confuse your object with another in the event editor.

// ------------------------------
// DEFINITION OF CONDITIONS CODES
// ------------------------------
#define	CND_CONDITION				0
#define	CND_LAST					1

// ---------------------------
// DEFINITION OF ACTIONS CODES
// ---------------------------
#define	ACT_ACTION_LFF				0
#define	ACT_ACTION_LFL				1

#define	ACT_ACTION_RL				2
#define	ACT_ACTION_EL				3
#define	ACT_ACTION_UL				4

#define	ACT_ACTION_SH				5
#define	ACT_ACTION_Z				6
#define	ACT_ACTION_R				7

#define	ACT_ACTION_US				8
#define	ACT_ACTION_RC				9

#define	ACT_ACTION_S				10

#define	ACT_ACTION_AB				11
#define	ACT_ACTION_UC				12

#define	ACT_ACTION_SC				13
#define	ACT_ACTION_SQ				14

#define	ACT_ACTION_AT				15
#define	ACT_ACTION_O				16

#define	ACT_ACTION_LFD				17

#define	ACT_LAST					18

// -------------------------------
// DEFINITION OF EXPRESSIONS CODES
// -------------------------------
#define	EXP_EXPRESSION_GHSX				0
#define EXP_EXPRESSION_GHSY				1

#define EXP_EXPRESSION_GOW				2
#define EXP_EXPRESSION_GOH				3

#define EXP_EXPRESSION_GCW				4
#define EXP_EXPRESSION_GCH				5

#define EXP_EXPRESSION_GXZS				6
#define EXP_EXPRESSION_GYZS				7

#define EXP_EXPRESSION_GA				8

#define EXP_EXPRESSION_GFN				9
#define EXP_EXPRESSION_GK				10

#define EXP_EXPRESSION_GSP				11

#define	EXP_LAST                    	12

// ---------------------
// OBJECT DATA STRUCTURE 
// ---------------------
// Used at edit time and saved in the MFA/CCN/EXE files

typedef struct tagEDATA_V1
{
	// Header - required
	extHeader		eHeader;

	// Object's data
	short			swidth;
	short			sheight;

	//Lib
	bool IsLib = false;

	//Collision
	bool Collision = false;
	bool AutoUpdateCollision = false;

	//Display

	//Settings
	bool HWA = false;
	bool StretchQuality = false;

} EDITDATA;
typedef EDITDATA *			LPEDATA;

// Object versions
#define	KCX_CURRENT_VERSION			1

// --------------------------------
// RUNNING OBJECT DATA STRUCTURE
// --------------------------------
// Used at runtime. Initialize it in the CreateRunObject function.
// Free any allocated memory or object in the DestroyRunObject function.
//
// Note: if you store C++ objects in this structure and do not store 
// them as pointers, you must call yourself their constructor in the
// CreateRunObject function and their destructor in the DestroyRunObject
// function. As the RUNDATA structure is a simple C structure and not a C++ object.

typedef struct tagRDATA
{
	// Main header - required
	headerObject	rHo;					// Header

	// Optional headers - depend on the OEFLAGS value, see documentation and examples for more info
	rCom			rc;				// Common structure for movements & animations
	rMvt			rm;				// Movements
	rSpr			rs;				// Sprite (displayable objects)
	rVal			rv;				// Alterable values

	// Object's runtime data
	short			swidth;
	short			sheight;

	//Lib
	bool IsLib = false;
	SurfaceLib* Lib = nullptr;

	//Collision
	bool Collision = false;
	bool AutoUpdateCollision = false;

	LPSMASK pColMask = nullptr;

	//Display

	//Settings
	bool HWA = false;
	bool StretchQuality = false;

	//Source
	bool FromLib = false;

	std::wstring* FileName = nullptr;
	std::wstring* Key = nullptr;

	//img->collision & add backdrop
	LPSURFACE img = nullptr;
	
	POINT ImgHotSpot = { 0,0 };
	ZoomScale ImgZoomScale = { 1.0,1.0 };

	OffsetCoef ImgOffset = { 0,0,false };
	
	int ImgAngle = 0;
	ATArray ImgAT = {};

	//src->display
	LPSURFACE src = nullptr;
	
	POINT HotSpot = { 0,0 };	
	ZoomScale ZoomScale = { 1.0,1.0 };

	OffsetCoef Offset = { 0,0,false };

	int Angle = 0;
	ATArray AT = {};

	//trans->transform
	LPSURFACE trans = nullptr;

	bool Changed = false;

} RUNDATA;
typedef	RUNDATA	*			LPRDATA;

// Size when editing the object under level editor
// -----------------------------------------------
#define	MAX_EDITSIZE			sizeof(EDITDATA)

// Default flags - see documentation for more info
// -------------
#define	OEFLAGS      			(OEFLAG_VALUES|OEFLAG_SCROLLINGINDEPENDANT|OEFLAG_NEVERKILL|OEFLAG_RUNBEFOREFADEIN|OEFLAG_MANUALSLEEP|OEFLAG_NEVERSLEEP|OEFLAG_SPRITES|OEFLAG_QUICKDISPLAY|OEFLAG_BACKSAVE|OEFLAG_MOVEMENTS)
#define	OEPREFS      			(OEPREFS_SCROLLINGINDEPENDANT|OEPREFS_INKEFFECTS|OEPREFS_BACKSAVE|OEPREFS_BACKEFFECTS|OEPREFS_FINECOLLISIONS)


// If to handle message, specify the priority of the handling procedure
// 0= low, 255= very high. You should use 100 as normal.                                                
// --------------------------------------------------------------------
#define	WINDOWPROC_PRIORITY		100
