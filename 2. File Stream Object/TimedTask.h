//Name: Moutikkumar Patel
//Subject: OOP345 NBB

//This submission is only done by me and work provided by professer.

#include <iostream>
#include<chrono>
#ifndef SDDS_TIMEDTASK_H_
#define SDDS_TIMEDTASK_H_

namespace sdds
{
	const int MAX = 10;
	class TimedTask
	{
	public:
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;
		struct Task
		{
			std::string taskName;
			std::string unit;
			std::chrono::steady_clock::duration duration;
		};
		Task m_task[MAX];
		int m_records = 0;
		friend std::ostream& operator<<(std::ostream& os, const TimedTask& tasks);
		void startClock();
		void stopClock();
		void addTask(std::string name);
	private:
	};
}



#endif //timedtask

