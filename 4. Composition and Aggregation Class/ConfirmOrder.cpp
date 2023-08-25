/*Name: Moutikkumar Patel
Email:mgpatel2@myseneca.ca
Section: NBB
Student no : 147298202
*/
/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "ConfirmOrder.h"

using namespace std;

namespace sdds {
	ConfirmOrder::ConfirmOrder()
	{
		delete[] Z_ToYs;
		Z_ToYs = nullptr;
	}
	ConfirmOrder::ConfirmOrder(const ConfirmOrder& obj)
	{
		*this = obj;
	}
	ConfirmOrder& ConfirmOrder::operator=(const ConfirmOrder& obj)
	{
		if (this != &obj)
		{
			m_count = obj.m_count;
			delete Z_ToYs;
			Z_ToYs = new const Toy * [obj.m_count];
			for (size_t i = 0; i < m_count; i++)
			{
				Z_ToYs[i] = obj.Z_ToYs[i];
			}

		}
		return *this;
	}
	ConfirmOrder::ConfirmOrder(ConfirmOrder&& obj)
	{
		*this = std::move(obj);
	}
	ConfirmOrder& ConfirmOrder::operator=(ConfirmOrder&& obj)
	{
		if (this != &obj)
		{
			m_count = obj.m_count;
			delete[] Z_ToYs;
			Z_ToYs = obj.Z_ToYs;

			obj.Z_ToYs = nullptr;
			obj.m_count = 0;

		}

		return *this;
	}
	ConfirmOrder::~ConfirmOrder()
	{
		delete[] Z_ToYs;
	}
	ConfirmOrder& ConfirmOrder::operator+=(const Toy& toy)
	{
		
		bool found = false;
		for (size_t i = 0; i < m_count && !found; i++)
		{
			if (Z_ToYs[i] == &toy)  
			{
				found = true;
				
			}
		}
		
		if (!found)
		{
			const Toy** temp = nullptr;
			temp = new const Toy * [m_count + 1];
			for (size_t i = 0; i < m_count; i++)
			{
				temp[i] = Z_ToYs[i];

			}
			temp[m_count] = &toy;
			m_count++;
			delete[] Z_ToYs;
			Z_ToYs = temp;
			
			
		}

		return *this;
		
	}
	ConfirmOrder& ConfirmOrder::operator-=(const Toy& toy)
	{
		bool found = false;
		size_t i = 0;
		for (; i < m_count && !found; i++)
		{
			if (Z_ToYs[i] == &toy)
			{
				found = true;
				
			}
		}
		if (found) {
			for (; i < m_count; ++i)
				Z_ToYs[i - 1] = Z_ToYs[i];
			if (m_count > 0) {
				Z_ToYs[m_count - 1] = nullptr; 
				m_count--;
			}
		}
		return *this;
	}
	
	std::ostream& operator<<(std::ostream& os, const ConfirmOrder& obj)
	{
		
		os << "--------------------------" << endl;
		os << "Confirmations to Send"<< endl;
		os << "--------------------------" << endl;


		if (obj.Z_ToYs == nullptr) {
			
			os << "There are no confirmations to send!" << endl;
		}
		else {
			
			for (size_t i = 0; i < obj.m_count; i++)
			{
				os << *(obj.Z_ToYs[i]);
			}
		}
		
		os << "--------------------------" << endl;
		return os;
	}
}