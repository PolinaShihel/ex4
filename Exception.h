#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <ostream>

using std::string;

class Exception : public std::exception {};  //NEED TO INHERIT FROM STD
class InvalidCardName : public std::logic_error {
public:
	InvalidCardName(const string& what) : std::logic_error(what)
	{
	}
};

#endif //EXCEPTION_H