//Name: Moutikkumar Patel
//Subject: OOP345 NBB

//This submission is only done by me and work provided by professer.

#include <iostream>
#ifndef SDDS_PROTEINDATABASE_H_
#define SDDS_PROTEINDATABASE_H_

namespace sdds
{
	class ProteinDatabase
	{
	public:
		std::string* records = nullptr;
		long unsigned int length = 0;
long unsigned int index = 0;
		ProteinDatabase();
		~ProteinDatabase();

		ProteinDatabase(char* fname);
	
		size_t size();
		std::string operator[](size_t);

		ProteinDatabase(const ProteinDatabase& src);

		ProteinDatabase(ProteinDatabase&& src);

		ProteinDatabase& operator=(const ProteinDatabase&);
		ProteinDatabase& operator=(ProteinDatabase&&);



	private:

	};

}
#endif