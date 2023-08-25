//Name: Moutikkumar Patel
//Student id:147298202
//email:mgpatel12
//Section OOP345 NBB

//This set of code is written by me and provided by professor.

#include "Pair.h"
using namespace std;
namespace sdds {
    
    bool Pair::haveSameKey(const Pair& P, const Pair& N){
        bool res = false;
        if (P.m_key == N.m_key) {
        res = true;
        }
        return res;
    }

    std::ostream& Pair::display(std::ostream& ostr) const {
        ostr.width(20);
        ostr.setf(ios::right);
        ostr << getKey();
        ostr.setf(ios::left);
        ostr << ": " << getValue();
        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const Pair& P) {
        return P.display(ostr);
    }
}