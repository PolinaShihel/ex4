#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <ostream>

class DeckFileNotFound : public std::exception
{
public:
    const char* what() const override
    {
        return "Deck File Error: File not found";
    }
};

class DeckFileFormatError : public std::exception
{
public:
    DeckFileFormatError(const int line):
    m_line(line),
    m_error("Deck File Error: File format error in line " + std::to_string(m_line))
    {}

    virtual const char* what() const override
    {
        return m_error.c_str();
    }

private:
    int m_line;
    std::string m_error;
};

class DeckFileInvalidSize : public std::exception
{
public:
    const char* what() const override
    {
        return "Deck File Error: Deck size is invalid";
    }

};

class InvalidCardName : public std::exception {
public:
    const char* what() const override
    {
        return "An invalid name has been entered for the current card";
    }
};

#endif //EXCEPTION_H