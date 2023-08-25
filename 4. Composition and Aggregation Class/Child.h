/*Name: Moutikkumar Patel
Email:mgpatel2@myseneca.ca
Section: NBB
Student no : 147298202
*/
/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CHILD_H
#define SDDS_CHILD_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include "Toy.h"


namespace sdds {
	class Toy;

	class Child {
		const Toy** Z_ToYs{ nullptr };
		std::string m_name{};
		int m_age{ 0 };	
	public:
		size_t m_count{ 0 };
		Child();
		Child(std::string name, int age, const Toy* toys[], size_t count);
		Child(const Child& obj);
		Child& operator=(const Child&obj);
		Child( Child&& obj);
		Child& operator=( Child&& obj);
		~Child();
		size_t size() const;
		friend std::ostream& operator <<(std::ostream& os, const Child& obj);
	};
}
#endif
