#include "CTimer.h"

CTimer::CTimer()
{
	m_last = std::chrono::steady_clock::now();
}

float CTimer::GetElapsedTime()const
{
	return m_elapsed.count();
}

void CTimer::UpdateTimer()
{
	const auto old = m_last;
	m_last = std::chrono::steady_clock::now();
	m_elapsed = m_last - old;
}

int CTimer::GetFPS() const
{
	return 1 / (int)GetElapsedTime();
}
