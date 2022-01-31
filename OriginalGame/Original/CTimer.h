#pragma once
#include <chrono>

class CTimer
{
private:
	std::chrono::steady_clock::time_point m_last;
	std::chrono::duration<float> m_elapsed;

public:
	CTimer();

	float GetElapsedTime()const;
	int GetFPS()const;
	void UpdateTimer();
};