#pragma once

#include "windows.h"

class myTime
{
	bool m_useQPF;
	float m_elapsedTime;
	LONGLONG m_ticksPerSec;
	LONGLONG m_lastElapsedTime;


public:
	myTime(void);
	virtual	~myTime(void);


	inline float GetElapsedTime() const
	{
		return m_elapsedTime;
	}


	void Init();
	void ProcessTime();

};

