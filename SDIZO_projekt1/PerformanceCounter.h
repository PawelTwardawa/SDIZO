#pragma once
#include <Windows.h>
class PerformanceCounter
{
public:
	PerformanceCounter();
	~PerformanceCounter();
	double PCFreq = 0.0;
	__int64 CounterStart = 0;
	void startTimer();
	double endTimer();
	
};

