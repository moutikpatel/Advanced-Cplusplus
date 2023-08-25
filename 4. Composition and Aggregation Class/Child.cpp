/*Name: Moutikkumar Patel
Email:mgpatel2@myseneca.ca
Section: NBB
Student no : 147298202
*/
/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Child.h"
using namespace std;
namespace sdds{
	Child::Child()
	{
		delete[] Z_ToYs;
		Z_ToYs = nullptr;
	}
	Child::Child(std::string name, int age, const Toy* toys[], size_t count)
		:m_name(name),m_age(age)
	{
		for (auto i = 0u; i < m_count; ++i)
			delete Z_ToYs[i];

		delete[] Z_ToYs;
		m_count = count;
		Z_ToYs = new  const Toy*[count];

		for (size_t i = 0; i < count; i++)
		{
			
			Z_ToYs[i] = new Toy(*(toys[i]));
		}

	}
	Child::Child(const Child& obj)
	{
		*this = obj;
	}
	Child& Child::operator=(const Child& obj)
	{
		if (this != &obj)
		{
			for (auto i = 0u; i < m_count; ++i)
				delete Z_ToYs[i];

			delete[] Z_ToYs;
			m_count = obj.m_count;
		
			
			m_age = obj.m_age;
			m_name = obj.m_name;
			
			
			Z_ToYs = new  const Toy * [m_count];
			
			for (size_t i = 0; i < m_count; i++)
			{
				Z_ToYs[i] = new Toy(*(obj.Z_ToYs[i]));
				
			}
			
		}
		return *this;
	}
	Child::Child( Child&& obj)
	{
		*this = std::move(obj);
	}
	Child& Child::operator=( Child&& obj)
	{
		if (this != &obj)
		{
			
			delete[] Z_ToYs;
			m_count = obj.m_count;
			m_age = obj.m_age;
			m_name = obj.m_name;
			Z_ToYs = obj.Z_ToYs;

			
			obj.Z_ToYs = nullptr;
			obj.m_age = 0;
			obj.m_name = "";
			obj.m_count = 0;

			

		}
		return *this;
	}
	Child::~Child()
	{
		for (auto i = 0u; i < m_count; ++i)
			delete Z_ToYs[i];

		delete[] Z_ToYs;
		Z_ToYs = nullptr;	
	}
	size_t Child::size() const
	{
		return this->m_count;
	}
	std::ostream& operator<<(std::ostream& os, const Child& obj)
	{
		static size_t CALL_CNT = 1;
		os << "--------------------------" << endl;
		
	
		
		if (obj.Z_ToYs == nullptr){
			os << "Child " << CALL_CNT << ": " << " "  << "0 years old:" << endl;
		os << "--------------------------" << endl;
			os << "This child has no toys!" << endl;
		}
		else {
			os << "Child " << CALL_CNT << ": " << obj.m_name << " " << obj.m_age << " years old:" << endl;
			os << "--------------------------" << endl;
			for (size_t i = 0; i < obj.m_count; i++)
			{
				os << *(obj.Z_ToYs[i]);
			}
		}
		CALL_CNT++;
		os << "--------------------------" << endl;
		
		return os;
	}
}