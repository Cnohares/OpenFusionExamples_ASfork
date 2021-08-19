// Object identifier "DIO0"

#define IDENTIFIER	MAKEID(D,I,O,0)		// REQUIRED: you MUST replace the letters in the MAKEID macro by others
										// and then remove the #pragma message above. If you do not do this, MMF2
										// could confuse your object with another in the event editor.

// ------------------------------
// DEFINITION OF CONDITIONS CODES
// ------------------------------
#define	CND_CONDITION_INAP			0
#define	CND_CONDITION_IML			1
#define	CND_CONDITION_RKS			2
#define	CND_CONDITION_IFS			3
#define	CND_LAST					4

// ---------------------------
// DEFINITION OF ACTIONS CODES
// ---------------------------
#define ACT_ACTION_RUN				0
#define ACT_ACTION_RUN_16			1
#define ACT_ACTION_STOPBYNAME		2
#define ACT_ACTION_STOPBYID			3

#define ACT_ACTION_LOCKMOUSE		4
#define ACT_ACTION_LOCKMOUSEBR		5
#define ACT_ACTION_UNLOCKMOUSE		6

#define ACT_ACTION_SETMOUSE			7

#define ACT_ACTION_LOCKMOUSESETTINGS_KEEPLOCK_ON			8
#define ACT_ACTION_LOCKMOUSESETTINGS_KEEPLOCK_OFF			9
#define ACT_ACTION_LOCKMOUSESETTINGS_UPDATELOCK_ON			10
#define ACT_ACTION_LOCKMOUSESETTINGS_UPDATELOCK_OFF			11
#define ACT_ACTION_LOCKMOUSESETTINGS_RECTOFFSET_ON			12
#define ACT_ACTION_LOCKMOUSESETTINGS_RECTOFFSET_OFF			13

#define ACT_ACTION_IME_DISABLE		14
#define ACT_ACTION_IME_ENABLE		15

#define ACT_ACTION_WINDOW_GF		16
#define ACT_ACTION_WINDOW_GW		17

#define ACT_ACTION_WINDOW_BFA		18

#define	ACT_LAST					19

// -------------------------------
// DEFINITION OF EXPRESSIONS CODES
// -------------------------------
#define	EXP_EXPRESSION_GPIDBN		0

#define	EXP_EXPRESSION_GCLR_L		1
#define	EXP_EXPRESSION_GCLR_R		2
#define	EXP_EXPRESSION_GCLR_T		3
#define	EXP_EXPRESSION_GCLR_B		4

#define	EXP_EXPRESSION_RXO			5
#define	EXP_EXPRESSION_RYO			6

#define	EXP_EXPRESSION_RXS			7
#define	EXP_EXPRESSION_RYS			8

#define	EXP_EXPRESSION_GCWR_L		9
#define	EXP_EXPRESSION_GCWR_R		10
#define	EXP_EXPRESSION_GCWR_T		11
#define	EXP_EXPRESSION_GCWR_B		12

#define	EXP_EXPRESSION_GCLT			13

#define	EXP_EXPRESSION_IME_STATE	14

#define	EXP_EXPRESSION_DPISCALING	15

#define	EXP_EXPRESSION_IFS			16

#define	EXP_LAST                    17

// ---------------------
// OBJECT DATA STRUCTURE 
// ---------------------
// Used at edit time and saved in the MFA/CCN/EXE files

typedef struct tagEDATA_V1
{
	// Header - required
	extHeader		eHeader;

	// Object's data
	//	short			swidth;
	//	short			sheight;
	
	//�л����ں󱣳�����
	bool KeepLock;
	//��ק���ں��������
	bool UpdateLock;
	//����������Դ�������
	bool RectOffset_State;

	//�����������뷨״̬
	bool KeepIMEState;

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
//	rCom			rc;				// Common structure for movements & animations
//	rMvt			rm;				// Movements
//	rSpr			rs;				// Sprite (displayable objects)
	rVal			rv;				// Alterable values

	// Object's runtime data

	//���ڱ����RunHeader
	fprh rhPtr = NULL;

	//�����ھ��
	HWND MainWindowHandle = NULL;
	//�������򴰿ھ��
	HWND FrameWindowHandle = NULL;

	//APP�ֱ���
	int AppW;
	int AppH;

	//������С
	int FrameW;
	int FrameH;
		
	//�����Ƿ�����
	bool Lock = false;
	//�����������
	int LockType;
	//�л����ں󱣳�����
	bool KeepLock;
	//��ק���ں��������
	bool UpdateLock;
	//����ڳ��������Ծ�����������ʱ�����ű���
	DPOINT FrameScale = { 1,1 };

	//������������
	int RectOffset_Type;
	//����������Դ�������
	bool RectOffset_State;
	//��ǰ��������ľ�����������ڴ��ڵ�ƫ��
	RECT RectOffset = { 0,0,0,0 };
	//ָ���ľ�������
	RECT UserSetRect = { 0,0,0,0 };

	//��ǰ��������ľ�������
	RECT CurrentLockRect;

	//�����������뷨״̬
	bool KeepIMEState;

	//�����Ƿ��Ѿ�����
	bool AppScaled;

} RUNDATA;
typedef	RUNDATA	*			LPRDATA;

// Size when editing the object under level editor
// -----------------------------------------------
#define	MAX_EDITSIZE			sizeof(EDITDATA)

// Default flags - see documentation for more info
// -------------
#define	OEFLAGS      			OEFLAG_VALUES|OEFLAG_SCROLLINGINDEPENDANT|OEFLAG_NEVERKILL|OEFLAG_RUNBEFOREFADEIN|OEFLAG_MANUALSLEEP 
#define	OEPREFS      			OEPREFS_SCROLLINGINDEPENDANT|OEPREFS_KILL|OEPREFS_SLEEP 


// If to handle message, specify the priority of the handling procedure
// 0= low, 255= very high. You should use 100 as normal.                                                
// --------------------------------------------------------------------
#define	WINDOWPROC_PRIORITY		100