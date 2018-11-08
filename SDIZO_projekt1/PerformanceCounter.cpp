#include "PerformanceCounter.h"
#include <iostream>

using namespace std;


PerformanceCounter::PerformanceCounter()
{
}


PerformanceCounter::~PerformanceCounter()
{
}

void PerformanceCounter::startTimer()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li))
		cout << "QueryPerformanceFrequency failed!\n";

	PCFreq = double(li.QuadPart) / 1000.0;

	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}

double PerformanceCounter::endTimer()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}
