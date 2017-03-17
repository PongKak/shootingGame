#include "stdafx.h"
#include "time.h"



myTime::myTime(void)
	: m_useQPF(false)
	, m_elapsedTime(0.f)
	, m_ticksPerSec(0)
	,m_lastElapsedTime(0)
{

}


myTime::~myTime()
{
}

void myTime::Init()
{
	LARGE_INTEGER qwTicksPerSec, qwTime;

	m_useQPF = (bool)(QueryPerformanceFrequency(&qwTicksPerSec) != 0);

	if (m_useQPF != true)
	{
		return;
	}

	m_ticksPerSec = qwTicksPerSec.QuadPart;

	QueryPerformanceCounter(&qwTime);

	m_lastElapsedTime = qwTime.QuadPart;
}

void myTime::ProcessTime()
{

	if (m_useQPF != true)
	{



		return;
	}

	LARGE_INTEGER qwTime;
	QueryPerformanceCounter(&qwTime);

	m_elapsedTime = (float)((double)(qwTime.QuadPart - m_lastElapsedTime) / (double)m_ticksPerSec);

	m_lastElapsedTime = qwTime.QuadPart;

}
