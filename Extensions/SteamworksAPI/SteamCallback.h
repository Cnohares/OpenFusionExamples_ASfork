#pragma once

#include <functional>

// ------------
// Official Callback example
// ------------
// 
// https://partner.steamgames.com/doc/sdk/api#callbacks
// 
//class SteamCallbackHandler {
//public:
//	STEAM_CALLBACK(SteamCallbackHandler, CallbackManager, GameOverlayActivated_t);
//};
//
//inline void SteamCallbackHandler::CallbackManager(GameOverlayActivated_t* pCallback) {
//	return;
//}

// ------------
// Usage
// ------------
//SteamCallback* pCallback = GetCallBack<CallBackType>([&](CallBackType* pCallback) {
//	// Do somethings
//	});
//
//delete pCallback;
//pCallback = nullptr;

// ------------
// Base class
// ------------
class SteamCallback {
public:
	// callback result
	bool bCallbackSuccess = false;
	// reset callback result, for next callback
	void ResetCallbackResult() { bCallbackSuccess = false; }

	virtual ~SteamCallback() = default;
};

// ------------
// Callback helper class, to use lambda
// ------------
template<typename CallBackType>
class SteamCallbackHandler :public SteamCallback {
private:
	using Handler = std::function<bool(CallBackType*)>;
	Handler handler = nullptr;

	STEAM_CALLBACK(SteamCallbackHandler, CallbackManager, CallBackType);

public:
	explicit SteamCallbackHandler(Handler handler) {
		this->handler = handler;
	}

	~SteamCallbackHandler() override = default;
};

template<typename CallBackType>
inline void SteamCallbackHandler<CallBackType>::CallbackManager(CallBackType* pCallback) {
	bCallbackSuccess = handler(pCallback);
}

// ------------
// Function to get new instance
// ------------
// return true: callback success
template<typename CallBackType>
inline auto GetCallBack(std::function<bool(CallBackType*)> callback) {
	return new SteamCallbackHandler<CallBackType>(callback);
}

// ------------
// Call result helper class, to use lambda
// ------------
template<typename CallBackType>
class SteamCallResultHandler :public SteamCallback {
private:
	using Handler = std::function<bool(CallBackType*, bool)>;
	Handler handler = nullptr;

	SteamAPICall_t hSteamAPICall = 0;
	CCallResult<SteamCallResultHandler, CallBackType> callResult;

	inline void OnCallbackResult(CallBackType* pCallback, bool bIOFailure);

public:
	explicit SteamCallResultHandler(SteamAPICall_t hSteamAPICall, Handler handler) {
		this->handler = handler;
		this->hSteamAPICall = hSteamAPICall;
		callResult.Set(hSteamAPICall, this, &SteamCallResultHandler::OnCallbackResult);
	}

	~SteamCallResultHandler() override = default;
};

template<typename CallBackType>
inline void SteamCallResultHandler<CallBackType>::OnCallbackResult(CallBackType* pCallback, bool bIOFailure) {
	bCallbackSuccess = handler(pCallback, bIOFailure);
}

// ------------
// Function to get new instance
// ------------
// return true: callback success
template<typename CallBackType>
inline auto GetCallBack(SteamAPICall_t hSteamAPICall, std::function<bool(CallBackType*, bool)> callback) {
	return new SteamCallResultHandler<CallBackType>(hSteamAPICall, callback);
}

// ------------
// Usage
// ------------
//
//#pragma once
//
//#include "SteamInclude.h"
//
//class SteamFunction :public SteamCallbackClass {
//private:
//	inline void CallCallback(void* udata = nullptr) override {
//		bCallbackSuccess = false;
//		pCallback = GetCallBack<CallbackType>([&] (const CallbackType* pCallback) {
//			bCallbackSuccess = pCallback->m_eResult == k_EResultOK
//				&& pCallback->m_nGameID == appID;
//		});
//		bool bSuccess = SteamUserStats()->RequestCurrentStats();
//	}
//public:
//	SteamFunction(Refresh::RefreshTasks* pTasks)
//		:SteamCallbackClass(pTasks, Refresh::RefreshType::AchievementAndStat) {
//		SteamFunction::CallCallback();
//	}
//	~SteamFunction() override {
//
//	}
//};

// ------------
// Base class
// ------------
constexpr auto DefaultCallbackCount = 1;

template<class Derived>
class SteamCallbackClass {
protected:
	uint64 appID = 0;
	std::vector<SteamCallback*> SteamCallbacks;

	inline bool CallbackIndexValid(size_t index) const {
		return SteamCallbacks.size() > index;
	}

public:
	// child classes init pCallback with GetCallBack
	// then call the async operation
	explicit SteamCallbackClass(bool bAutoCallInit = true) {
		this->appID = SteamUtils()->GetAppID();
		SteamCallbacks.reserve(DefaultCallbackCount);
		// CRTP
		if (bAutoCallInit) {
			static_cast<Derived*>(this)->InitCallback();
		}
	}
	virtual ~SteamCallbackClass() {
		for (const auto& it : SteamCallbacks) {
			delete it;
		}
	}

	inline bool GetCallbackStat(size_t index = 0) const {
		if (!CallbackIndexValid(index)) { return false; }

		return SteamCallbacks[index]->bCallbackSuccess;
	}
	inline SteamCallback* GetCallback(size_t index = 0) const {
		if (!CallbackIndexValid(index)) { return nullptr; }

		return SteamCallbacks[index];
	}

	// add callbacks, must be implemented
	virtual inline void InitCallback() = 0;

	inline void AddCallback(SteamCallback* pCallback) {
		SteamCallbacks.emplace_back(pCallback);
	}
	// call the first callback by default
	inline void CallCallback(const std::function<void()>& worker = nullptr) const {
		CallCallback(0, worker);
	}
	// call the given callback
	inline void CallCallback(size_t index, const std::function<void()>& worker = nullptr) const {
		if (!CallbackIndexValid(index)) { return; }
		SteamCallbacks[index]->ResetCallbackResult();

		if (worker != nullptr) { worker(); }
	}
};