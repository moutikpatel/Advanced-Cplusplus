//Name: Moutikkumar Patel
//Subject: OOP345 NBB

//This submission is only done by me and work provided by professer.



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>

#include<string>
using namespace std;

#include "ProteinDatabase.h"

namespace sdds {

	ProteinDatabase::ProteinDatabase()
	{}

	ProteinDatabase::ProteinDatabase(char* f_name)
	{
		length = 0;
		records = nullptr;

		ifstream fname(f_name);

		if (!fname)
			return;

		string line, name;

		while (std::getline(fname,line).good()){
			if (line[0] == '>'){
				length++;
			}
		}


		fname.clear();
		fname.seekg(ios::beg);
		
		records = new string[length];
		line.clear();
		int i = -1;

		while (getline(fname,line).good()){
			if (line[0] == '>'){
				++i;
				name = line.substr(1);
			}
			else if (!name.empty()){
				records[i] += line;
			}
		}


	}


	ProteinDatabase::ProteinDatabase(ProteinDatabase&& old) {
		*this = std::move(old);
	}

	ProteinDatabase::ProteinDatabase(const ProteinDatabase& old){
        *this = old;
	}


	ProteinDatabase& ProteinDatabase::operator=(ProteinDatabase&& src){
		if (this != &src) {

			delete[] records;
			records = nullptr;

			records = src.records;
			src.records = nullptr;
			length = src.length;
			src.length = 0;
		}
		return *this;
	}

	
	size_t ProteinDatabase::size() {
		return length;
	}

    ProteinDatabase& ProteinDatabase::operator=(const ProteinDatabase& src){
        if (this != &src) {
            delete[] records;
            length = src.length;

            records = new string[length]{};

            for (long unsigned int i = 0; i < length; i++){
                records[i] = src.records[i];
            }
        }

        return *this;
    }


	std::string ProteinDatabase::operator[](size_t index) {

		if (index < length) {

			return records[index];
		}
		return "";
	}

	ProteinDatabase::~ProteinDatabase() {
		delete[] records;
	}
}