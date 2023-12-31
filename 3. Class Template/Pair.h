//Name: Moutikkumar Patel
//Student id:147298202
//email:mgpatel12
//Section OOP345 NBB

//This set of code is written by me and provided by professor.

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>
#include <string>
namespace sdds {
class Pair {
 std::string m_key{};
 std::string m_value{};
public:
 const std::string& getKey() const{
  return m_key;
 }
 const std::string& getValue() const{
  return m_value;
 }
 Pair(const std::string& key, const std::string& value) : m_key{ key }, m_value{ value }{};
 static bool haveSameKey(const Pair& P, const Pair& N);
 Pair() : m_key{ "" }, m_value{ "" }{};
 virtual std::ostream& display(std::ostream& ostr = std::cout) const;
 bool operator==(const Pair& pair)const {
  return m_key == pair.getKey();
 }
};
std::ostream& operator<<(std::ostream& ostr, const Pair& P);
}
#endif  // !SDDS_PAIR_H