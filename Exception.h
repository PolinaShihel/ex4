#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <ostream>

class DeckFileNotFound : public std::exception
{
public:
    std::string what()
    {
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError : public std::exception
{
public:
    DeckFileFormatError(const int line)
    {
        m_line = line;
    }
    std::string what()
    {
        return "Deck File Error: File format error in line " + std::to_string(m_line);
    }
private:
    int m_line;
};

class DeckFileInvalidSize : public std::exception
{
public:
    std::string what()
    {
        return "Deck File Error: Deck size is invalid";
    }

};

class InvalidCardName : public std::exception {
public:
	std::string what()
    {
        return "An invalid name has been entered for the current card";
    }
};

#endif //EXCEPTION_H