/*Name: Moutikkumar Patel
Email:mgpatel2@myseneca.ca
Section: NBB
Student no : 147298202
*/
/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CONFIRM_H
#define SDDS_CONFIRM_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include "Toy.h"


namespace sdds {
	class Toy;
	class ConfirmOrder {
		const Toy** Z_ToYs{ nullptr };
		size_t m_count{ 0 };	
	public:
		ConfirmOrder();
		ConfirmOrder(const ConfirmOrder& obj);
		ConfirmOrder& operator=(const ConfirmOrder& obj);
		ConfirmOrder(ConfirmOrder&& obj);
		ConfirmOrder& operator=(ConfirmOrder&& obj);
		~ConfirmOrder();
		ConfirmOrder& operator+=(const Toy& toy);
		ConfirmOrder& operator-=(const Toy& toy);	
		friend std::ostream& operator <<(std::ostream& os, const ConfirmOrder& obj);
	};
}
#endif
