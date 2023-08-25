/*Name: Moutikkumar Patel
Email:mgpatel2@myseneca.ca
Section: NBB
Student no : 147298202
*/
/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_TOY_H
#define SDDS_TOY_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <utility>
namespace sdds {
	class Toy {
		unsigned int orderID{ 0 };
		std::string name{};
		double M_Cost{ 0 };
		int hst{ 13 };
	public:
		size_t count{ 0 };
		Toy();
		void update(int numItems);
		Toy(const std::string& toy);
		Toy(const Toy& obj);
		Toy& operator=(const Toy& obj);
		~Toy();
		friend std::ostream& operator <<(std::ostream& os, const Toy& obj);
	};
}
#endif 

