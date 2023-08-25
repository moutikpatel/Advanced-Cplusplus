/*Name: Moutikkumar Patel
Email:mgpatel2@myseneca.ca
Section: NBB
Student no : 147298202
*/
/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Toy.h"

using namespace std;

namespace sdds {
	sdds::Toy::Toy()
	{
	}
	void sdds::Toy::update(int numItems)
	{
		count = numItems;
	}
    sdds::Toy::Toy(const std::string& toy)
	{
		orderID =std::stoi(toy);
		int one = toy.find(':');
		std::string nam = toy.substr(one + 1);
		
		one = 0;
		while (one == 0)
		{
			one = nam.find(' ');
			if (one == 0)
			{
				nam.erase(0, 1);
			}
		}
		
		int two = 0;
		int flag = 1;
		while (flag)
		{
			
			two = nam.find(':');
			one = nam.find(' ', two - 1);
			if (one == two - 1)
			{
				nam.erase(two -1 , 1);
			}
			else
				flag = 0;
		}
		one = nam.find(':');
		name = nam.substr(0,one);
		nam = nam.substr(one + 1 );
		count = stoi(nam);
		one = nam.find(':');
		nam = nam.substr(one + 1);
		M_Cost = stod(nam);
		}
	Toy::Toy(const Toy& obj)
	{
		*this = obj; 
	}
	Toy& Toy::operator=(const Toy& obj)
	{
		orderID = obj.orderID;
		name = obj.name;
		count = obj.count;
		M_Cost = obj.M_Cost;
		hst = obj.hst;
		return *this;
	}
    Toy::~Toy()
	{
		
	}
	std::ostream& operator <<(std::ostream& os, const sdds::Toy & obj)
	{
		
		os << "Toy ";
		os.setf(std::ios::fixed, std::ios::floatfield);
		os.setf(ios::left);
		os.width(7);
		os.fill(' ');
		os << obj.orderID;
		os << ":";
		os.unsetf(ios::left);

		os.setf(ios::right);
		os.width(18);
		os << obj.name;
		os.width(3);
		os << obj.count;
		os << " items";
		os.width(8);
		os.precision(2);
		os << obj.M_Cost;

		os << "/item  subtotal:";
		os.width(7);
		os << setprecision(2) << (obj.count * obj.M_Cost);
		double sub = (obj.count * obj.M_Cost);
		os << " tax:";
		os.width(6);
		os << setprecision(2) << ((obj.count * obj.M_Cost) * 0.13);
		double tax = ((obj.count * obj.M_Cost) * 0.13);
		os << " total:";
		os.width(7);
		os <<setprecision(2) << (sub + tax);
		os.unsetf(ios::right);
		os << endl;

		return os;
	}
}