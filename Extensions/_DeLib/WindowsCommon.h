#pragma once

#include <tlhelp32.h>

#pragma comment(lib,"version.lib")

inline DWORD GetProcessIDByName(LPCTSTR ApplicationName) {
	//返回参数
	DWORD	ProcessID = 0;

	//获取快照
	HANDLE	snapshot;
	snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

	//循环遍历
	PROCESSENTRY32* info;
	info = new PROCESSENTRY32;
	info->dwSize = sizeof(PROCESSENTRY32);

	Process32First(snapshot, info);
	while (Process32Next(snapshot, info) != FALSE) {
		//进程名一致则结束进程		
		if (wcscmp(ApplicationName, info->szExeFile) == 0) {
			ProcessID = info->th32ProcessID;
			break;
		}
	}

	delete info;
	return ProcessID;
}

struct TRANSLATION {
	WORD wLanguage;		// language ID
	WORD wCodePage;		// character set (code page)
};

inline bool operator ==(const TRANSLATION& A, const TRANSLATION& B) {
	return (A.wLanguage == B.wLanguage) && (A.wCodePage == B.wCodePage);
}

inline bool operator !=(const TRANSLATION& A, const TRANSLATION& B) {
	return !(A==B);
}

static LPCWSTR DefaultBlock[] = { L"Comments",	L"InternalName",	L"ProductName",
						L"CompanyName",	L"LegalCopyright",	L"ProductVersion",
						L"FileDescription",	L"LegalTrademarks",	L"PrivateBuild",
						L"FileVersion",	L"OriginalFilename",	L"SpecialBuild" };

inline BYTE* GetFileVersion_GetFileVersionInfo(LPCWSTR FileName) {
	// Get FileVersionInfo
	auto size = GetFileVersionInfoSize(FileName, NULL);

	if (size == 0) {
		return nullptr;
	}

	BYTE* pData = new BYTE[size * sizeof(BYTE)];

	GetFileVersionInfo(FileName, NULL, size, pData);

	return pData;
}

inline TRANSLATION* GetFileVersion_GetTranslation(BYTE* pData) {
	// Query
	void* Buffer = nullptr;
	UINT Len = 0;

	// Get Translation
	TRANSLATION* pTranslation = nullptr;

	if (VerQueryValue(pData, L"\\VarFileInfo\\Translation", &Buffer, &Len)) {
		pTranslation = new TRANSLATION;
		memcpy(pTranslation, Buffer, sizeof(TRANSLATION));
	}

	return pTranslation;
}

inline LPWSTR GetFileVersion_GetSubBlock(BYTE* pData, TRANSLATION* pTranslation, LPCWSTR SubBlock) {
	// Query
	void* Buffer = nullptr;
	UINT Len = 0;
	
	// Get SubBlock based on translation
	LPCWSTR Format = L"\\StringFileInfo\\%04x%04x\\%s";
	auto sz = swprintf(nullptr, 0, Format, pTranslation->wLanguage, pTranslation->wCodePage, SubBlock);
	auto bufsz = sz + 1;

	LPWSTR block = new wchar_t[bufsz];
	swprintf(block, bufsz, Format, pTranslation->wLanguage, pTranslation->wCodePage, SubBlock);

	// Get the real STR
	LPWSTR info = nullptr;

	auto newStr = [](LPWSTR* des, LPCWSTR src)->void {
		auto isz = swprintf(nullptr, 0, L"%s", src);
		auto ibufsz = isz + 1;

		*des = new wchar_t[ibufsz];
		swprintf(*des, ibufsz, L"%s", src);
	};

	if (VerQueryValue(pData, block, &Buffer, &Len)) {
		newStr(&info, (wchar_t*)Buffer);
	}
	else {
		newStr(&info, L"NULL");
	}

	delete[] block;

	return info;
}

inline bool GetFileVersion_CMPDefault(BYTE* pDataA, BYTE* pDataB, int CMP) {
	bool ret = true;

	if (CMP == 0b000000000000) {
		return ret;
	}

	TRANSLATION* pTranslationA = GetFileVersion_GetTranslation(pDataA);
	TRANSLATION* pTranslationB = GetFileVersion_GetTranslation(pDataB);

	if (*pTranslationA != *pTranslationB) {
		ret = false;
		goto clear;
	}

	for (int i = 0b000000000001, count = 0; i != 0b100000000000; i = i << 1, count++) {
		if (i & CMP) {
			LPCWSTR infoA = GetFileVersion_GetSubBlock(pDataA, pTranslationA, DefaultBlock[count]);
			LPCWSTR infoB = GetFileVersion_GetSubBlock(pDataB, pTranslationB, DefaultBlock[count]);

			bool unequal = (wcscmp(infoA, infoB) != 0);

			delete[] infoA;
			delete[] infoB;

			if (unequal) {
				ret = false;
				break;
			}
		}
	}

clear:
	delete pTranslationA;
	delete pTranslationB;

	return ret;
}

inline bool GetFileVersion_CMPDefaultFile(LPCWSTR FileNameA, LPCWSTR FileNameB, int CMP) {
	BYTE* pDataA = GetFileVersion_GetFileVersionInfo(FileNameA);
	BYTE* pDataB = GetFileVersion_GetFileVersionInfo(FileNameB);

	bool ret = GetFileVersion_CMPDefault(pDataA, pDataB, CMP);

	delete[] pDataA;
	delete[] pDataB;

	return ret;
}

inline LPWSTR GetFileVersion(LPCWSTR FileName, LPCWSTR SubBlock) {
	// Get FileVersionInfo
	auto size = GetFileVersionInfoSize(FileName, NULL);	
	BYTE* pData = new BYTE[size * sizeof(BYTE)];
	//unique_ptr<BYTE> pData(new BYTE[size * sizeof(BYTE)]);

	GetFileVersionInfo(FileName, NULL, size, pData);

	// Query
	void* Buffer = nullptr;
	UINT Len = 0;

	// Get FixedFileInfo
	VerQueryValue(pData, L"\\", &Buffer, &Len);

	VS_FIXEDFILEINFO* pFixedFileInfo = new VS_FIXEDFILEINFO;
	memcpy(pFixedFileInfo, Buffer, sizeof(VS_FIXEDFILEINFO));

	// Get Translation
	VerQueryValue(pData, L"\\VarFileInfo\\Translation", &Buffer, &Len);

	TRANSLATION* pTranslation = new TRANSLATION;
	memcpy(pTranslation, Buffer, sizeof(TRANSLATION));

	// Get SubBlock based on translation
	LPCWSTR Format= L"\\StringFileInfo\\%04x%04x\\%s";
	auto sz = swprintf(nullptr, 0, Format, pTranslation->wLanguage, pTranslation->wCodePage, SubBlock);
	auto bufsz = sz + 1;
	
	LPWSTR block = new wchar_t[bufsz];
	swprintf(block, bufsz, Format, pTranslation->wLanguage, pTranslation->wCodePage, SubBlock);

	// Get the real STR
	LPWSTR info = nullptr;

	auto newStr = [](LPWSTR* des, LPCWSTR src)->void {
		auto isz = swprintf(nullptr, 0, L"%s", src);
		auto ibufsz = isz + 1;

		*des = new wchar_t[ibufsz];
		swprintf(*des, ibufsz, L"%s", src);
	};

	if (VerQueryValue(pData, block, &Buffer, &Len)) {
		newStr(&info, (wchar_t*)Buffer);
	}
	else {
		newStr(&info, L"NULL");
	}

	// Clear
	delete[] pData;
	delete pFixedFileInfo;
	delete pTranslation;

	delete[] block;

	return info;
}