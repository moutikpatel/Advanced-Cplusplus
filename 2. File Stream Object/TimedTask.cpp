//Name: Moutikkumar Patel
//Subject: OOP345 NBB

//This submission is only done by me and work provided by professer.

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;
#include "TimedTask.h"

namespace sdds
{

	void TimedTask::startClock()
	{
		startTime = std::chrono::steady_clock::now();
	}
	void TimedTask::stopClock()
	{
		endTime = std::chrono::steady_clock::now();
	}

	ostream& operator<<(std::ostream& os, const TimedTask& tasks)
	{
		os << "--------------------------\n" << "Execution Times:\n--------------------------\n";
		for (int i = 0; i < tasks.m_records; i++)
		{
			os << std::setw(21) << std::left << tasks.m_task[i].taskName << " ";
			os << std::setw(13) << std::right << tasks.m_task[i].duration.count() << " " << tasks.m_task[i].unit << "\n";
		}
		return os << "--------------------------\n";
	}

	void TimedTask::addTask(std::string name)
	{

		m_task[m_records].taskName = name;
		m_task[m_records].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
		m_task[m_records].unit = "nanoseconds";

		m_records += 1;
	}



}