#ifndef _FUNC_
#define _FUNC_

// convert string to wstring
inline std::wstring to_wide_string(const std::string& input) {
	const auto size_needed = MultiByteToWideChar(CP_UTF8, 0, &input.at(0), (int)input.size(), nullptr, 0);

	std::wstring result(size_needed, 0);
	MultiByteToWideChar(CP_UTF8, 0, &input.at(0), (int)input.size(), &result.at(0), size_needed);

	return result;
}

// convert wstring to string 
inline std::string to_byte_string(const std::wstring& input) {
	const auto size_needed = WideCharToMultiByte(CP_UTF8, 0, &input.at(0), (int)input.size(), nullptr, 0, nullptr, nullptr);

	std::string result(size_needed, 0);
	WideCharToMultiByte(CP_UTF8, 0, &input.at(0), (int)input.size(), &result.at(0), size_needed, nullptr, nullptr);

	return result;
}

inline void NewStr(LPTSTR & Tar, LPCTSTR Str) {
	release_arr(Tar);
	rsize_t total_length = wcslen(Str) + 1;

	Tar = new WCHAR[total_length];
	wcscpy_s(Tar, total_length, Str);
}

inline void NewStr(LPTSTR& Tar, const std::wstring& Str) {
	NewStr(Tar, Str.c_str());
}

inline long ReturnFloat(LPRDATA rdPtr, float Val) {
	if (Val == (int)Val) {
		return (int)Val;
	}
	else {
		//Setting the HOF_FLOAT flag lets MMF know that you are returning a float.
		rdPtr->rHo.hoFlags |= HOF_FLOAT;

		//Return the float without conversion
		return *((long*)&Val);
	}
}

#define ReturnFloat(Val) ReturnFloat(rdPtr, Val)

inline bool Modified(SI_Error Input) {
	return Input == SI_UPDATED || Input == SI_INSERTED;
}

inline void SaveFile(LPINI Ini,const wchar_t* FilePath, const wchar_t* Key) {
	//Key has value, try to Encry
	if (!StrEmpty(Key)) {
		std::string Output;
		Ini->Save(Output);

		Encryption Encrypt;
		Encrypt.GenerateKey(Key);

		Encrypt.SetEncryptStr(Output);
		Encrypt.Encrypt();

		Encrypt.SaveFile(FilePath);
	}
	else {
		Ini->SaveFile(FilePath, false);
	}
}

inline void AutoSave(LPRDATA rdPtr) {
	if (rdPtr->Modified && rdPtr->AutoSave && valid(Fini) && valid(rdPtr->AutoSaveFilePath) && valid(rdPtr->AutoSaveKey)) {
		SaveFile(Fini, rdPtr->AutoSaveFilePath, rdPtr->AutoSaveKey);
	}
}

inline bool LPROValid(LPRO object, unsigned long identifier = 0) {
	if (object == nullptr) {
		return false;
	}

	if (identifier) {
		return object->roHo.hoIdentifier == identifier;
	}

	return true;		// need not to check indntifier
}

inline size_t GetRVOffset(LPRDATA rdPtr, LPRO object) {
	if (!LPROValid(object)) {
		return -1;
	}

	size_t offset = sizeof(headerObject);

	// Internal objects
	auto identifier = object->roHo.hoIdentifier;

	if (identifier == IDENTIFIER_LIVES || identifier == IDENTIFIER_SCORE) {		
		return -1;
	}

	if (identifier == IDENTIFIER_COUNTER || identifier == IDENTIFIER_STRING) {
		if (rdPtr->cf25p && rdPtr->allowRVforCS) {
			offset += sizeof(rCom) + sizeof(rMvt) + sizeof(rSpr);
			return offset;
		}
		else {
			return -1;
		}
	}

	if (identifier == IDENTIFIER_ACTIVE) {
		offset += sizeof(rCom) + sizeof(rMvt) + sizeof(rSpr);
		return offset;
	}

	// General extensions
	auto flags = object->roHo.hoAdRunHeader->rhApp->m_kpxDataTable->kpx[1].infos.editFlags;

	if (!(flags & OEFLAG_VALUES)) {
		return -1;
	}

	offset += (flags & OEFLAG_MOVEMENTS) || (flags & OEFLAG_ANIMATIONS) || (flags & OEFLAG_SPRITES)
		? sizeof(rCom) : 0;
	offset += (flags & OEFLAG_MOVEMENTS) ? sizeof(rMvt) : 0;
	offset += (flags & OEFLAG_ANIMATIONS) ? sizeof(rAni) : 0;
	offset += (flags & OEFLAG_SPRITES) ? sizeof(rSpr) : 0;

	return offset;
}

#endif // !_FUNC_

