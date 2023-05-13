#pragma once

//immediate conditon ID
constexpr auto OnMixroTxnError = 1;
constexpr auto OnMixroTxnFinish = 2;

class SteamUtilities;

struct tagRDATA;
typedef tagRDATA RUNDATA;
typedef RUNDATA* LPRDATA;

struct GlobalData {
	LPRDATA rdPtr = nullptr;

	bool bInit = false;
	SteamUtilities* pSteamUtil = nullptr;
		
	GlobalData() {
		bInit = SteamAPI_Init();

		if (bInit) {
			pSteamUtil = new SteamUtilities();
		}
	}
	~GlobalData() {
		delete pSteamUtil;
		pSteamUtil = nullptr;

		if (bInit) {
			SteamAPI_Shutdown();
		}
	}

	inline bool SteamUtilitiesValid() const {
		return pSteamUtil != nullptr;
	}

	//rdPtr->pData->GetSteamUtilities([] (SteamUtilities* pSteamUtil) {});
	inline void GetSteamUtilities(const std::function<void(SteamUtilities* pSteamUtil)>& callback,
		const std::function<bool(SteamUtilities* pSteamUtil)>& extraCond = nullptr) const {
		const bool bExtra = extraCond != nullptr
			? extraCond(pSteamUtil)
			: true;

		if (!SteamUtilitiesValid() || !bExtra) {
			return;
		}

		callback(pSteamUtil);
	}

	template<typename T>
	inline T GetSteamUtilities(const T defaultValue,
		const std::function<T(SteamUtilities* pSteamUtil)>& callback,
		const std::function<bool(SteamUtilities* pSteamUtil)>& extraCond = nullptr) const {
		const bool bExtra = extraCond != nullptr
			? extraCond(pSteamUtil)
			: true;

		if (!SteamUtilitiesValid() || !bExtra) {
			return defaultValue;
		}

		return callback(pSteamUtil);
	}

	inline void UpdateRdPtr(LPRDATA rdPtr) {
		this->rdPtr = rdPtr;
	}

	inline void UpdateMicroTxnCallback() const;
};