#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <ostream>

class Exception : public std::exception {};  //NEED TO INHERIT FROM STD
class InvalidCardName : public std::logic_error {
public:
	InvalidCardName(const std::string& what) : std::logic_error(what)
	{
	}
};

#endif //EXCEPTION_H