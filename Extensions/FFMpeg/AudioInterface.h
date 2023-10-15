#pragma once

class AudioInterface {
public:
	AudioInterface() {} 
	virtual ~AudioInterface() {}
	virtual inline void AddInstance(FFMpeg** ppFFMpeg, void* pData) = 0;
	virtual inline void RemoveInstance(FFMpeg** ppFFMpeg, void* pData) = 0;
};